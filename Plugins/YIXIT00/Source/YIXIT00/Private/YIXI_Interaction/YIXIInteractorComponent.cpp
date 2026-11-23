#include "YIXI_Interaction/YIXIInteractorComponent.h"

#include "Blueprint/SlateBlueprintLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "CoreGlobals.h"
#include "Engine/GameViewportClient.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "SceneView.h"
#include "YIXI_Interaction/YIXIInteractable.h"

namespace
{
	bool CanReachAnchor(UWorld& World, const FVector& Start, const FVector& Anchor,
		const APawn& Pawn, const AActor& Interactable)
	{
		FCollisionQueryParams Params(SCENE_QUERY_STAT(YIXIInteractionVisibility), true, &Pawn);
		FHitResult Hit;
		return !World.LineTraceSingleByChannel(Hit, Start, Anchor, ECC_Visibility, Params)
			|| Hit.GetActor() == &Interactable;
	}
}

struct UYIXIInteractorComponent::FView
{
	APlayerController* Controller = nullptr;
	FVector CameraLocation = FVector::ZeroVector;
	FVector CameraForward = FVector::ForwardVector;
	FGeometry PlayerGeometry;
	FIntRect ViewRect;
	FMatrix ViewProjection = FMatrix::Identity;
};

struct UYIXIInteractorComponent::FTarget
{
	AActor* Actor = nullptr;
	FVector2D PlayerPosition = FVector2D::ZeroVector;
	FText ActionText;
	bool bCanUse = false;
	bool bShowPrompt = false;
	float Score = -MAX_flt;
};

UYIXIInteractorComponent::UYIXIInteractorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_PostUpdateWork;
}

void UYIXIInteractorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	ResetLocalPlayer();
	Super::EndPlay(EndPlayReason);
}

APlayerController* UYIXIInteractorComponent::ResolveLocalController() const
{
	const AActor* Owner = GetOwner();
	if (!Owner || Owner->FindComponentByClass<UYIXIInteractorComponent>() != this)
	{
		return nullptr;
	}

	APlayerController* Controller = Cast<APlayerController>(GetOwner());
	if (!Controller)
	{
		const APawn* Pawn = Cast<APawn>(Owner);
		Controller = Pawn ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
		if (Controller && Controller->FindComponentByClass<UYIXIInteractorComponent>())
		{
			return nullptr;
		}
	}

	return Controller && Controller->GetPawn() && Controller->GetLocalPlayer() ? Controller : nullptr;
}

UYIXIInteractionHUDWidget* UYIXIInteractorComponent::FindDialogueHUD(APlayerController& Controller)
{
	UYIXIInteractorComponent* Interactor = Controller.FindComponentByClass<UYIXIInteractorComponent>();
	if (!Interactor)
	{
		if (APawn* Pawn = Controller.GetPawn())
		{
			Interactor = Pawn->FindComponentByClass<UYIXIInteractorComponent>();
		}
	}
	if (Interactor && Interactor->ResolveLocalController() == &Controller)
	{
		Interactor->EnsureHUD(Controller);
		return Interactor->HUDWidget;
	}
	return nullptr;
}

void UYIXIInteractorComponent::EnsureHUD(APlayerController& Controller)
{
	if (HUDWidget)
	{
		return;
	}

	UClass* Class = HUDWidgetClass ? HUDWidgetClass.Get() : UYIXIInteractionHUDWidget::StaticClass();
	if (UYIXIInteractionHUDWidget* Widget = CreateWidget<UYIXIInteractionHUDWidget>(&Controller, Class))
	{
		Widget->SetIsFocusable(false);
		Widget->SetVisibility(ESlateVisibility::HitTestInvisible);
		if (Widget->AddToPlayerScreen(20))
		{
			HUDWidget = Widget;
		}
	}
}

void UYIXIInteractorComponent::EnsureInput(APlayerController& Controller)
{
	if (!bBindInteractionKey || InteractionInputComponent || !InteractionKey.IsValid() || !Controller.PlayerInput)
	{
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Controller.GetLocalPlayer());
	if (!Subsystem)
	{
		return;
	}

	InteractionAction = NewObject<UInputAction>(this, NAME_None, RF_Transient);
	InteractionAction->ValueType = EInputActionValueType::Boolean;
	InteractionAction->bConsumeInput = bConsumeInteractionInput;
	InteractionAction->bConsumesActionAndAxisMappings = bConsumeInteractionInput;
	InteractionAction->TriggerEventsThatConsumeLegacyKeys = static_cast<int32>(ETriggerEvent::Started | ETriggerEvent::Triggered);
	InteractionMapping = NewObject<UInputMappingContext>(this, NAME_None, RF_Transient);
	InteractionMapping->MapKey(InteractionAction, InteractionKey);

	InteractionInputComponent = NewObject<UEnhancedInputComponent>(&Controller, NAME_None, RF_Transient);
	InteractionInputComponent->RegisterComponent();
	InteractionInputComponent->BindAction(InteractionAction, ETriggerEvent::Started, this, &ThisClass::OnInteractionPressed);
	Controller.PushInputComponent(InteractionInputComponent);
	Subsystem->AddMappingContext(InteractionMapping, InteractionMappingPriority);
	InputSubsystem = Subsystem;
}

void UYIXIInteractorComponent::RemoveInput()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = InputSubsystem.Get(); Subsystem && InteractionMapping)
	{
		Subsystem->RemoveMappingContext(InteractionMapping);
	}
	if (InteractionInputComponent)
	{
		if (APlayerController* Controller = ActiveController.Get())
		{
			Controller->PopInputComponent(InteractionInputComponent);
		}
		InteractionInputComponent->DestroyComponent();
	}

	InteractionInputComponent = nullptr;
	InteractionMapping = nullptr;
	InteractionAction = nullptr;
	InputSubsystem.Reset();
}

void UYIXIInteractorComponent::ResetLocalPlayer()
{
	RemoveInput();
	if (HUDWidget)
	{
		HUDWidget->RemoveFromParent();
		HUDWidget = nullptr;
	}
	ActiveController.Reset();
	Candidates.Reset();
	CurrentTarget = nullptr;
	CurrentActionText = FText::GetEmpty();
	PromptState = EYIXIInteractionPromptState::Hidden;
	TimeUntilCandidateRefresh = 0.0f;
	TimeUntilScan = 0.0f;
}

void UYIXIInteractorComponent::SetInteractionKeyBindingEnabled(bool bEnabled)
{
	bBindInteractionKey = bEnabled;
	if (!bEnabled)
	{
		RemoveInput();
	}
}

void UYIXIInteractorComponent::OnInteractionPressed()
{
	RequestInteract();
}

void UYIXIInteractorComponent::SetCinematicSuppressed(bool bSuppressed)
{
	if (bCinematicSuppressed == bSuppressed)
	{
		return;
	}
	bCinematicSuppressed = bSuppressed;
	ApplyTarget(FTarget(), 0.0f);
	TimeUntilCandidateRefresh = 0.0f;
	TimeUntilScan = 0.0f;
}

void UYIXIInteractorComponent::RefreshCandidates()
{
	Candidates.Reset();
	for (TActorIterator<AActor> It(GetWorld()); It; ++It)
	{
		AActor* Actor = *It;
		if (Actor->GetClass()->ImplementsInterface(UYIXIInteractable::StaticClass()))
		{
			Candidates.Add(Actor);
		}
	}
}

bool UYIXIInteractorComponent::BuildView(APlayerController& Controller, FView& OutView) const
{
	const ULocalPlayer* LocalPlayer = Controller.GetLocalPlayer();
	FSceneViewProjectionData Projection;
	if (!LocalPlayer || !LocalPlayer->ViewportClient || !LocalPlayer->ViewportClient->Viewport
		|| !LocalPlayer->GetProjectionData(LocalPlayer->ViewportClient->Viewport, Projection))
	{
		return false;
	}

	OutView.PlayerGeometry = UWidgetLayoutLibrary::GetPlayerScreenWidgetGeometry(&Controller);
	const FVector2D Size = OutView.PlayerGeometry.GetLocalSize();
	if (Size.X <= 0.0 || Size.Y <= 0.0)
	{
		return false;
	}

	FVector ViewLocation;
	FRotator ViewRotation;
	Controller.GetPlayerViewPoint(ViewLocation, ViewRotation);
	OutView.Controller = &Controller;
	OutView.CameraForward = ViewRotation.Vector();
	OutView.CameraLocation = Projection.ViewOrigin;
	OutView.ViewRect = Projection.GetConstrainedViewRect();
	OutView.ViewProjection = Projection.ComputeViewProjectionMatrix();
	return true;
}

bool UYIXIInteractorComponent::EvaluateTarget(AActor* Actor, APawn& Pawn, const FView& View, FTarget& OutTarget) const
{
	if (!IsValid(Actor) || Actor == &Pawn || Actor->IsActorBeingDestroyed() || Actor->IsHidden()
		|| !Actor->HasActorBegunPlay())
	{
		return false;
	}

	const FYIXIInteractionPrompt Prompt = IYIXIInteractable::Execute_GetInteractionPrompt(Actor, &Pawn);
	const FVector Anchor = Prompt.WorldLocation;
	const float DetectRange = FMath::Max(0.0f, Prompt.DetectionRange);
	const float InteractRange = FMath::Clamp(Prompt.InteractRange, 0.0f, DetectRange);
	const bool bWasCurrent = Actor == CurrentTarget;
	const float Hysteresis = bWasCurrent ? FMath::Max(0.0f, DistanceHysteresisCm) : 0.0f;
	const double Distance = FVector::Dist(Pawn.GetActorLocation(), Anchor);
	const double Facing = FVector::DotProduct(View.CameraForward, (Anchor - View.CameraLocation).GetSafeNormal());
	const float ConeAngle = FMath::Clamp(ViewConeHalfAngle, 1.0f, 89.0f);
	if (Anchor.ContainsNaN() || DetectRange <= 0.0f || Distance > DetectRange + Hysteresis
		|| Facing < FMath::Cos(FMath::DegreesToRadians(ConeAngle)))
	{
		return false;
	}

	FVector2D Pixels;
	if (!FSceneView::ProjectWorldToScreen(Anchor, View.ViewRect, View.ViewProjection, Pixels)
		|| Pixels.X < View.ViewRect.Min.X || Pixels.Y < View.ViewRect.Min.Y
		|| Pixels.X >= View.ViewRect.Max.X || Pixels.Y >= View.ViewRect.Max.Y
		|| !CanReachAnchor(*GetWorld(), View.CameraLocation, Anchor, Pawn, *Actor)
		|| !CanReachAnchor(*GetWorld(), Pawn.GetActorLocation(), Anchor, Pawn, *Actor))
	{
		return false;
	}

	USlateBlueprintLibrary::ScreenToWidgetLocal(View.Controller, View.PlayerGeometry, Pixels, OutTarget.PlayerPosition);
	const float ReadyPadding = bWasCurrent && PromptState == EYIXIInteractionPromptState::Ready ? Hysteresis : 0.0f;
	OutTarget.bCanUse = InteractRange > 0.0f && Distance <= InteractRange + ReadyPadding
		&& IYIXIInteractable::Execute_CanInteract(Actor, &Pawn);
	OutTarget.Actor = Actor;
	OutTarget.bShowPrompt = Prompt.bShowPrompt;
	OutTarget.ActionText = Prompt.ActionText;
	OutTarget.Score = static_cast<float>(2.0 * Facing - 0.35 * (Distance / DetectRange))
		+ (OutTarget.bCanUse ? 0.30f : 0.0f) + (bWasCurrent ? 0.07f : 0.0f);
	return true;
}

void UYIXIInteractorComponent::ApplyTarget(const FTarget& Target, float DeltaTime)
{
	const bool bTargetChanged = CurrentTarget != Target.Actor;
	CurrentTarget = Target.Actor;
	CurrentActionText = Target.ActionText;
	PromptState = EYIXIInteractionPromptState::Hidden;
	if (Target.Actor && Target.bShowPrompt)
	{
		PromptState = Target.bCanUse ? EYIXIInteractionPromptState::Ready : EYIXIInteractionPromptState::Dot;
	}
	if (HUDWidget)
	{
		HUDWidget->UpdatePrompt(PromptState, Target.PlayerPosition, InteractionKey.GetDisplayName(false), DeltaTime, bTargetChanged);
	}
}

bool UYIXIInteractorComponent::RequestInteract()
{
	APlayerController* Controller = ResolveLocalController();
	if (bCinematicSuppressed || !Controller || Controller != ActiveController.Get()
		|| !IsValid(CurrentTarget) || LastRequestFrame == GFrameCounter)
	{
		return false;
	}

	FView View;
	FTarget Target;
	if (!BuildView(*Controller, View) || !EvaluateTarget(CurrentTarget, *Controller->GetPawn(), View, Target) || !Target.bCanUse)
	{
		return false;
	}

	LastRequestFrame = GFrameCounter;
	IYIXIInteractable::Execute_Interact(Target.Actor, Controller->GetPawn());
	return true;
}

void UYIXIInteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	APlayerController* Controller = ResolveLocalController();
	if (Controller != ActiveController.Get() || (!Controller && HUDWidget))
	{
		ResetLocalPlayer();
		ActiveController = Controller;
	}
	if (!Controller || bCinematicSuppressed)
	{
		return;
	}

	EnsureHUD(*Controller);
	EnsureInput(*Controller);
	FView View;
	FTarget Best;
	if (BuildView(*Controller, View))
	{
		APawn& Pawn = *Controller->GetPawn();
		TimeUntilCandidateRefresh -= DeltaTime;
		TimeUntilScan -= DeltaTime;
		if (TimeUntilCandidateRefresh <= 0.0f)
		{
			RefreshCandidates();
			TimeUntilCandidateRefresh = 0.5f;
			TimeUntilScan = 0.0f;
		}

		if (TimeUntilScan <= 0.0f)
		{
			TimeUntilScan = FMath::Max(0.02f, TargetScanInterval);
			for (const TWeakObjectPtr<AActor>& Candidate : Candidates)
			{
				FTarget Target;
				if (EvaluateTarget(Candidate.Get(), Pawn, View, Target) && Target.Score > Best.Score)
				{
					Best = MoveTemp(Target);
				}
			}
		}
		else if (!EvaluateTarget(CurrentTarget, Pawn, View, Best) && CurrentTarget)
		{
			TimeUntilScan = 0.0f;
		}
	}
	ApplyTarget(Best, DeltaTime);
}
