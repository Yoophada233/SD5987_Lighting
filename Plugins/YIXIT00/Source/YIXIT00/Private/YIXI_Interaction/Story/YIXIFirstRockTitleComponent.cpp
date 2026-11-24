#include "YIXI_Interaction/Story/YIXIFirstRockTitleComponent.h"

#include "YIXI_Interaction/ScriptedProjectile/YIXIScriptedRock.h"
#include "YIXI_Interaction/Story/YIXIFirstRockTitleInputFilter.h"
#include "YIXI_Interaction/YIXIInteractorComponent.h"
#include "EnhancedInputComponent.h"
#include "Engine/GameViewportClient.h"
#include "Engine/Texture2D.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "MoverComponent.h"
#include "MoverDataModelTypes.h"
#include "Rendering/DrawElements.h"
#include "Styling/CoreStyle.h"
#include "UObject/StructOnScope.h"
#include "UObject/UnrealType.h"
#include "Widgets/SLeafWidget.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIFirstRockTitle, Log, All);

namespace
{
const FName RagdollMode(TEXT("Ragdoll"));

bool RequestTemplateRagdoll(APawn& Pawn, const UMoverComponent& Mover)
{
	if (Mover.GetMovementModeName() == RagdollMode || Mover.GetNextMovementModeName() == RagdollMode)
	{
		UE_LOG(LogYIXIFirstRockTitle, Display, TEXT("Template ragdoll already active or queued."));
		return true;
	}

	UFunction* TriggerRagdoll = Pawn.FindFunction(TEXT("TriggerRagdoll"));
	if (!TriggerRagdoll || TriggerRagdoll->NumParms != 3)
	{
		return false;
	}

	const FBoolProperty* StopMontages = FindFProperty<FBoolProperty>(TriggerRagdoll, TEXT("StopActiveMontages"));
	const FStructProperty* BlendOut = FindFProperty<FStructProperty>(TriggerRagdoll, TEXT("MontageBlendOut"));
	const FStructProperty* DefaultBlendOut = FindFProperty<FStructProperty>(
		Pawn.GetClass(), TEXT("DefaultRagdollMontageBlendOut"));
	const FProperty* InjuryState = FindFProperty<FProperty>(TriggerRagdoll, TEXT("Ragdoll_InjuryState"));
	if (!StopMontages || !BlendOut || !DefaultBlendOut || BlendOut->Struct != DefaultBlendOut->Struct || !InjuryState)
	{
		return false;
	}

	// Match IA_TriggerRagdoll: stop montages with the pawn's authored blend and use the default injury entry.
	FStructOnScope Params(TriggerRagdoll);
	uint8* ParamData = Params.GetStructMemory();
	StopMontages->SetPropertyValue_InContainer(ParamData, true);
	BlendOut->CopyCompleteValue(BlendOut->ContainerPtrToValuePtr<void>(ParamData),
		DefaultBlendOut->ContainerPtrToValuePtr<void>(&Pawn));

	void* InjuryValue = InjuryState->ContainerPtrToValuePtr<void>(ParamData);
	const FEnumProperty* Enum = CastField<FEnumProperty>(InjuryState);
	const FByteProperty* Byte = CastField<FByteProperty>(InjuryState);
	const UEnum* EnumType = Enum ? Enum->GetEnum() : Byte ? Byte->Enum.Get() : nullptr;
	const int64 DefaultInjury = EnumType ? EnumType->GetValueByNameString(TEXT("NewEnumerator0")) : INDEX_NONE;
	if (DefaultInjury == INDEX_NONE)
	{
		return false;
	}
	if (Enum)
	{
		Enum->GetUnderlyingProperty()->SetIntPropertyValue(InjuryValue, DefaultInjury);
	}
	else
	{
		Byte->SetPropertyValue(InjuryValue, static_cast<uint8>(DefaultInjury));
	}

	Pawn.ProcessEvent(TriggerRagdoll, ParamData);
	UE_LOG(LogYIXIFirstRockTitle, Display, TEXT("Called TriggerRagdoll for %s. Current mode=%s, next mode=%s."),
		*Pawn.GetName(), *Mover.GetMovementModeName().ToString(), *Mover.GetNextMovementModeName().ToString());
	return true;
}

float SmoothProgress(double Time, double Duration)
{
	const float Alpha = static_cast<float>(FMath::Clamp(Time / Duration, 0.0, 1.0));
	return Alpha * Alpha * (3.0f - 2.0f * Alpha);
}
}

class SYIXIFirstRockTitleLayer final : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SYIXIFirstRockTitleLayer) {}
	SLATE_END_ARGS()

	void Construct(const FArguments&, UTexture2D* Texture, float Scale, FVector2D Offset)
	{
		if (Texture)
		{
			ImageSize = FVector2D(Texture->GetSizeX(), Texture->GetSizeY());
			ImageBrush.DrawAs = ESlateBrushDrawType::Image;
			ImageBrush.SetResourceObject(Texture);
		}
		ImageScale = FMath::Clamp(Scale, 0.05f, 1.0f);
		ImageOffset = Offset;
		SetVisibility(EVisibility::HitTestInvisible);
	}

	void SetFrame(float ImageProgress, float FrameOpacity)
	{
		TitleProgress = ImageProgress;
		Opacity = FrameOpacity;
		Invalidate(EInvalidateWidgetReason::Paint);
	}

private:
	virtual FVector2D ComputeDesiredSize(float) const override { return FVector2D::ZeroVector; }

	virtual int32 OnPaint(const FPaintArgs&, const FGeometry& Geometry, const FSlateRect&,
		FSlateWindowElementList& Elements, int32 LayerId, const FWidgetStyle&, bool) const override
	{
		const FVector2D Canvas = Geometry.GetLocalSize();
		const FSlateBrush* White = FCoreStyle::Get().GetBrush(TEXT("WhiteBrush"));
		const FLinearColor Black(0.0f, 0.0f, 0.0f, Opacity);
		const auto Box = [&](FVector2D Min, FVector2D Max, const FSlateBrush* Brush, const FLinearColor& Tint)
		{
			const FVector2D Size = Max - Min;
			if (Size.X > 0.0 && Size.Y > 0.0)
			{
				FSlateDrawElement::MakeBox(Elements, LayerId,
					Geometry.ToPaintGeometry(Size, FSlateLayoutTransform(Min)), Brush,
					ESlateDrawEffect::IgnoreTextureAlpha | ESlateDrawEffect::NoPixelSnapping, Tint);
			}
		};
		if (Opacity <= 0.0f || Canvas.X <= 0.0 || Canvas.Y <= 0.0)
		{
			return LayerId;
		}
		if (TitleProgress <= 0.0f || ImageSize.X <= 0.0 || ImageSize.Y <= 0.0)
		{
			Box(FVector2D::ZeroVector, Canvas, White, Black);
			return LayerId;
		}

		const double Fit = FMath::Min(Canvas.X / ImageSize.X, Canvas.Y / ImageSize.Y) * ImageScale;
		const FVector2D Size = ImageSize * Fit;
		const FVector2D Spare = Canvas - Size;
		const FVector2D Offset = Spare * 0.5 + Canvas * ImageOffset;
		const FVector2D Min(FMath::Clamp(Offset.X, 0.0, FMath::Max(Spare.X, 0.0)),
			FMath::Clamp(Offset.Y, 0.0, FMath::Max(Spare.Y, 0.0)));
		const FVector2D Max = Min + Size;

		// The gutters and the opaque source image share edges and never overlap.
		// Each pixel is blended into the world exactly once during the combined fade.
		Box(FVector2D::ZeroVector, FVector2D(Canvas.X, Min.Y), White, Black);
		Box(FVector2D(0.0, Max.Y), Canvas, White, Black);
		Box(FVector2D(0.0, Min.Y), FVector2D(Min.X, Max.Y), White, Black);
		Box(FVector2D(Max.X, Min.Y), FVector2D(Canvas.X, Max.Y), White, Black);
		Box(Min, Max, &ImageBrush, FLinearColor(TitleProgress, TitleProgress, TitleProgress, Opacity));
		return LayerId;
	}

	FSlateBrush ImageBrush;
	FVector2D ImageSize = FVector2D::ZeroVector;
	FVector2D ImageOffset = FVector2D::ZeroVector;
	float ImageScale = 1.0f;
	float TitleProgress = 0.0f;
	float Opacity = 1.0f;
};

void UYIXIFirstRockTitleInputFilter::ProduceInput_Implementation(int32 SimTimeMs, FMoverInputCmdContext& Command)
{
	auto& Inputs = Command.InputCollection.FindOrAddMutableDataByType<FCharacterDefaultInputs>();
	Inputs.SetMoveInput(EMoveInputType::DirectionalIntent, FVector::ZeroVector);
	Inputs.bIsJumpJustPressed = false;
	Inputs.bIsJumpPressed = false;
}

UYIXIFirstRockTitleComponent::UYIXIFirstRockTitleComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	PrimaryComponentTick.TickGroup = TG_PostUpdateWork;
}

void UYIXIFirstRockTitleComponent::BeginPlay()
{
	Super::BeginPlay();
	if (!bEnabled)
	{
		return;
	}

	BoundRock = FirstRockReference ? FirstRockReference.Get() : Cast<AYIXIScriptedRock>(GetOwner());
	if (!BoundRock.IsValid())
	{
		UE_LOG(LogYIXIFirstRockTitle, Warning, TEXT("%s needs a First Rock Reference."), *GetPathName());
		return;
	}

	Layer = SNew(SYIXIFirstRockTitleLayer, TitleTexture.Get(), TitleScale, TitleOffset);
	BoundRock->OnImpact.AddUniqueDynamic(this, &ThisClass::OnFirstRockImpact);
}

void UYIXIFirstRockTitleComponent::OnFirstRockImpact(int32 RequestId)
{
	const AYIXIScriptedRock* Rock = BoundRock.Get();
	UWorld* World = GetWorld();
	if (bPlayed || !bEnabled || !Rock || !World || !Layer || RequestId <= 0 ||
		!Rock->HasImpacted() || RequestId != Rock->GetActiveRequestId())
	{
		return;
	}

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	APawn* ControlledPawn = PC ? PC->GetPawn() : nullptr;
	UGameViewportClient* GameViewport = World->GetGameViewport();
	if (!PC || !PC->IsLocalController() || !ControlledPawn || !GameViewport)
	{
		return;
	}

	bPlayed = true;
	StartedAt = World->GetRealTimeSeconds();
	StartFrame = GFrameCounter;
	Controller = PC;
	Pawn = ControlledPawn;
	Mover = ControlledPawn->FindComponentByClass<UMoverComponent>();
	Viewport = GameViewport;
	bKnockdownPending = bKnockdownOnBlackout;

	SetFrame(EPhase::Black, 0.0f, 1.0f, 0.0);
	GameViewport->AddViewportWidgetContent(Layer.ToSharedRef(), 1000);

	InputBlocker = NewObject<UEnhancedInputComponent>(this);
	InputBlocker->bBlockInput = true;
	InputBlocker->Priority = MAX_int32;
	PC->PushInputComponent(InputBlocker);
	PC->SetIgnoreMoveInput(true);
	PC->SetIgnoreLookInput(true);
	PC->FlushPressedKeys();
	ControlledPawn->ConsumeMovementInputVector();
	if (Mover.IsValid())
	{
		MovementInputFilter = NewObject<UYIXIFirstRockTitleInputFilter>(this);
		Mover->InputProducers.Add(MovementInputFilter);
	}

	UYIXIInteractorComponent* Interactor = PC->FindComponentByClass<UYIXIInteractorComponent>();
	if (!Interactor)
	{
		Interactor = ControlledPawn->FindComponentByClass<UYIXIInteractorComponent>();
	}
	if (Interactor && !Interactor->IsCinematicSuppressed())
	{
		Interactor->SetCinematicSuppressed(true);
		SuppressedInteractor = Interactor;
	}
	if (auto* HUD = UYIXIInteractorComponent::FindDialogueHUD(*PC))
	{
		PreviousHUDVisibility = HUD->GetVisibility();
		if (PreviousHUDVisibility != ESlateVisibility::Hidden && PreviousHUDVisibility != ESlateVisibility::Collapsed)
		{
			HiddenHUD = HUD;
			HUD->SetVisibility(ESlateVisibility::Collapsed);
		}
	}

	UE_LOG(LogYIXIFirstRockTitle, Display, TEXT("Bound rock %s impact request %d."), *Rock->GetName(), RequestId);
	SetComponentTickEnabled(true);
}

void UYIXIFirstRockTitleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	const UWorld* World = GetWorld();
	if (!World || !Controller.IsValid() || !Pawn.IsValid() || Controller->GetPawn() != Pawn.Get()
		|| !Viewport.IsValid() || !BoundRock.IsValid())
	{
		CancelTitle();
		return;
	}

	// Let the viewport present the blackout before invoking the same entry point as the R action.
	if (GFrameCounter == StartFrame)
	{
		return;
	}
	if (bKnockdownPending)
	{
		bKnockdownPending = false;
		if (!Mover.IsValid() || !RequestTemplateRagdoll(*Pawn.Get(), *Mover.Get()))
		{
			UE_LOG(LogYIXIFirstRockTitle, Warning, TEXT("The current pawn did not expose the expected TriggerRagdoll entry."));
		}
	}

	const double Elapsed = World->GetRealTimeSeconds() - StartedAt;
	const double BlackEnd = FMath::Max(BlackHoldBeforeTitle, 0.0f);
	const double RevealEnd = BlackEnd + FMath::Max(TitleFadeInDuration, 0.0f);
	const double HoldEnd = RevealEnd + FMath::Max(TitleHoldDuration, 0.0f);
	const double End = HoldEnd + FMath::Max(CombinedFadeOutDuration, 0.0f);
	if (Elapsed < BlackEnd)
	{
		return;
	}
	if (Elapsed < RevealEnd)
	{
		SetFrame(EPhase::Reveal, SmoothProgress(Elapsed - BlackEnd, RevealEnd - BlackEnd), 1.0f, Elapsed);
	}
	else if (Elapsed < HoldEnd)
	{
		SetFrame(EPhase::Hold, 1.0f, 1.0f, Elapsed);
	}
	else if (Elapsed < End)
	{
		SetFrame(EPhase::FadeOut, 1.0f, 1.0f - SmoothProgress(Elapsed - HoldEnd, End - HoldEnd), Elapsed);
	}
	else
	{
		UE_LOG(LogYIXIFirstRockTitle, Display, TEXT("Finished at %.3fs. Current pawn movement mode: %s."),
			Elapsed, Mover.IsValid() ? *Mover->GetMovementModeName().ToString() : TEXT("none"));
		CancelTitle();
	}
}

void UYIXIFirstRockTitleComponent::SetFrame(EPhase NewPhase, float TitleProgress, float Opacity, double Elapsed)
{
	if (Phase != NewPhase)
	{
		const TCHAR* Name = NewPhase == EPhase::Black ? TEXT("Black") : NewPhase == EPhase::Reveal
			? TEXT("Reveal") : NewPhase == EPhase::Hold ? TEXT("Hold") : TEXT("FadeOut");
		UE_LOG(LogYIXIFirstRockTitle, Display, TEXT("%s at %.3fs."), Name, Elapsed);
		Phase = NewPhase;
	}
	Layer->SetFrame(TitleProgress, Opacity);
}

void UYIXIFirstRockTitleComponent::CancelTitle()
{
	if (Phase == EPhase::Inactive)
	{
		return;
	}

	Phase = EPhase::Inactive;
	bKnockdownPending = false;
	SetComponentTickEnabled(false);
	if (Viewport.IsValid() && Layer)
	{
		Viewport->RemoveViewportWidgetContent(Layer.ToSharedRef());
	}
	if (Mover.IsValid() && MovementInputFilter)
	{
		Mover->InputProducers.RemoveSingle(MovementInputFilter);
	}
	if (Controller.IsValid())
	{
		// Enhanced Input ignores held digital actions until a fresh press after the flush.
		Controller->FlushPressedKeys();
		Controller->PopInputComponent(InputBlocker);
		Controller->SetIgnoreMoveInput(false);
		Controller->SetIgnoreLookInput(false);
	}
	if (SuppressedInteractor.IsValid())
	{
		SuppressedInteractor->SetCinematicSuppressed(false);
	}
	if (HiddenHUD.IsValid() && HiddenHUD->GetVisibility() == ESlateVisibility::Collapsed)
	{
		HiddenHUD->SetVisibility(PreviousHUDVisibility);
	}
	InputBlocker = nullptr;
	MovementInputFilter = nullptr;
	Controller.Reset();
	Pawn.Reset();
	Mover.Reset();
	Viewport.Reset();
	SuppressedInteractor.Reset();
	HiddenHUD.Reset();
}

void UYIXIFirstRockTitleComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (BoundRock.IsValid())
	{
		BoundRock->OnImpact.RemoveDynamic(this, &ThisClass::OnFirstRockImpact);
	}
	CancelTitle();
	Layer.Reset();
	Super::EndPlay(EndPlayReason);
}
