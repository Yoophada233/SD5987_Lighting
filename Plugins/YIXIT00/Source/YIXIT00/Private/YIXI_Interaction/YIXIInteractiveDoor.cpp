#include "YIXI_Interaction/YIXIInteractiveDoor.h"

#include "CollisionQueryParams.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Curves/CurveFloat.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundBase.h"
#include "UObject/ConstructorHelpers.h"

#define LOCTEXT_NAMESPACE "YIXIInteractiveDoor"

AYIXIInteractiveDoor::AYIXIInteractiveDoor()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.TickGroup = TG_PostPhysics;

	DoorRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorRoot"));
	SetRootComponent(DoorRoot);
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(DoorRoot);
	DoorFrame->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);
	WhiteboxLeftJamb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WhiteboxLeftJamb"));
	WhiteboxLeftJamb->SetupAttachment(DoorRoot);
	WhiteboxRightJamb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WhiteboxRightJamb"));
	WhiteboxRightJamb->SetupAttachment(DoorRoot);

	HingePivot = CreateDefaultSubobject<USceneComponent>(TEXT("HingePivot"));
	HingePivot->SetupAttachment(DoorRoot);
	LeafMount = CreateDefaultSubobject<USceneComponent>(TEXT("LeafMount"));
	LeafMount->SetupAttachment(HingePivot);
	DoorLeaf = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorLeaf"));
	DoorLeaf->SetupAttachment(LeafMount);
	DoorLeaf->SetMobility(EComponentMobility::Movable);
	DoorLeaf->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);
	HandleMarker = CreateDefaultSubobject<USceneComponent>(TEXT("HandleMarker"));
	HandleMarker->SetupAttachment(LeafMount);
	InteractionAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("InteractionAnchor"));
	InteractionAnchor->SetupAttachment(HandleMarker);
	SoundOrigin = CreateDefaultSubobject<USceneComponent>(TEXT("SoundOrigin"));
	SoundOrigin->SetupAttachment(HingePivot);
	SoundOrigin->SetRelativeLocation(FVector(0.0, 0.0, 100.0));

	DetectionPreview = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionPreview"));
	DetectionPreview->SetupAttachment(InteractionAnchor);
	DetectionPreview->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DetectionPreview->SetGenerateOverlapEvents(false);
	DetectionPreview->SetHiddenInGame(true);
	DetectionPreview->InitSphereRadius(DetectionRange);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Engine/BasicShapes/Cube.Cube"));
	WhiteboxCube = Cube.Object;
	DoorFrameMesh = WhiteboxCube;
	DoorLeafMesh = WhiteboxCube;
	ApplyComponentConfiguration();
	SetDoorOpenFraction(0.0f);
}

void AYIXIInteractiveDoor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	ApplyComponentConfiguration();
	DoorState = bStartOpened ? EYIXIDoorState::Open : EYIXIDoorState::Closed;
	SetDoorOpenFraction(bStartOpened ? 1.0f : 0.0f);
}

void AYIXIInteractiveDoor::BeginPlay()
{
	Super::BeginPlay();
	ApplyComponentConfiguration();
	bCompletedCycle = false;
	DoorState = bStartOpened ? EYIXIDoorState::Open : EYIXIDoorState::Closed;
	SetDoorOpenFraction(bStartOpened ? 1.0f : 0.0f);
}

void AYIXIInteractiveDoor::ApplyComponentConfiguration()
{
	const bool bWhiteboxFrame = WhiteboxCube && DoorFrameMesh == WhiteboxCube;
	DoorFrame->SetStaticMesh(DoorFrameMesh);
	DoorFrame->SetRelativeLocation(bWhiteboxFrame ? FVector(0.0, 0.0, 215.0) : FrameMeshOffset);
	DoorFrame->SetRelativeScale3D(bWhiteboxFrame ? FVector(1.2, 0.2, 0.1) : FrameMeshScale);
	for (UStaticMeshComponent* Jamb : { WhiteboxLeftJamb.Get(), WhiteboxRightJamb.Get() })
	{
		Jamb->SetStaticMesh(bWhiteboxFrame ? WhiteboxCube.Get() : nullptr);
		Jamb->SetRelativeLocation(FVector(Jamb == WhiteboxLeftJamb.Get() ? -55.0 : 55.0, 0.0, 105.0));
		Jamb->SetRelativeScale3D(FVector(0.1, 0.2, 2.1));
		Jamb->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);
		Jamb->SetCollisionEnabled(bWhiteboxFrame ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
	}

	HingePivot->SetRelativeLocation(HingePivotOffset);
	LeafMount->SetRelativeLocation(LeafCenterOffset);
	DoorLeaf->SetStaticMesh(DoorLeafMesh);
	DoorLeaf->SetRelativeScale3D(LeafMeshScale);
	HandleMarker->SetRelativeLocation(HandleMarkerOffset);
	DetectionPreview->SetRelativeLocation(PromptAnchorOffset);
	DetectionPreview->SetSphereRadius(FMath::Max(0.0f, DetectionRange), false);
}

FYIXIInteractionPrompt AYIXIInteractiveDoor::GetInteractionPrompt_Implementation(APawn* Interactor) const
{
	FYIXIInteractionPrompt Prompt;
	Prompt.WorldLocation = InteractionAnchor->GetComponentTransform().TransformPosition(PromptAnchorOffset);
	Prompt.DetectionRange = FMath::Max(0.0f, DetectionRange);
	Prompt.InteractRange = FMath::Clamp(InteractRange, 0.0f, Prompt.DetectionRange);
	const bool bWouldClose = DoorState == EYIXIDoorState::Open || DoorState == EYIXIDoorState::Opening;
	Prompt.ActionText = bWouldClose ? LOCTEXT("CloseDoor", "Close door") : LOCTEXT("OpenDoor", "Open door");
	Prompt.bShowPrompt = bShowHUDPrompt && (bAllowRepeat || !bCompletedCycle)
		&& (bCanClose || DoorState != EYIXIDoorState::Open);
	return Prompt;
}

bool AYIXIInteractiveDoor::CanInteract_Implementation(APawn* Interactor) const
{
	if (!IsValid(Interactor) || Interactor->GetWorld() != GetWorld() || (!bAllowRepeat && bCompletedCycle))
	{
		return false;
	}

	switch (DoorState)
	{
	case EYIXIDoorState::Closed:
		return true;
	case EYIXIDoorState::Opening:
		return bCanClose && bAllowMidMotionReverse;
	case EYIXIDoorState::Open:
		return bCanClose;
	case EYIXIDoorState::Closing:
		return bAllowMidMotionReverse;
	}
	return false;
}

void AYIXIInteractiveDoor::Interact_Implementation(APawn* Interactor)
{
	if (IYIXIInteractable::Execute_CanInteract(this, Interactor))
	{
		BeginMotion(DoorState == EYIXIDoorState::Closed || DoorState == EYIXIDoorState::Closing);
	}
}

void AYIXIInteractiveDoor::BeginMotion(bool bOpening)
{
	MotionStartFraction = OpenFraction;
	MotionElapsed = 0.0f;
	const float RemainingFraction = bOpening ? 1.0f - OpenFraction : OpenFraction;
	const float FullDuration = FMath::Max(0.05f, bOpening ? OpenDuration : CloseDuration);
	MotionDuration = FMath::Max(UE_KINDA_SMALL_NUMBER, FullDuration * RemainingFraction);
	DoorState = bOpening ? EYIXIDoorState::Opening : EYIXIDoorState::Closing;
	SetActorTickEnabled(true);

	USoundBase* Sound = bOpening ? OpenSound.Get() : CloseSound.Get();
	const bool bSoundEnabled = bOpening ? bEnableOpenSound : bEnableCloseSound;
	const float Volume = bOpening ? OpenSoundVolume : CloseSoundVolume;
	if (Sound && bSoundEnabled && Volume > 0.0f)
	{
		UGameplayStatics::PlaySoundAtLocation(this, Sound, SoundOrigin->GetComponentLocation(),
			Volume, 1.0f, 0.0f, SoundAttenuation);
	}

	if (bOpening)
	{
		OnDoorOpenStarted.Broadcast();
	}
	else
	{
		OnDoorCloseStarted.Broadcast();
	}
}

void AYIXIInteractiveDoor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	const bool bOpening = DoorState == EYIXIDoorState::Opening;
	if (!bOpening && DoorState != EYIXIDoorState::Closing)
	{
		return;
	}

	const float NewElapsed = FMath::Min(MotionElapsed + DeltaSeconds, MotionDuration);
	const float Progress = NewElapsed / MotionDuration;
	const float Goal = bOpening ? 1.0f : 0.0f;
	const float Eased = EvaluateEase(Progress, bOpening ? OpenEaseCurve.Get() : CloseEaseCurve.Get());
	const float Candidate = FMath::Lerp(MotionStartFraction, Goal, Eased);
	const float NewFraction = bOpening ? FMath::Max(OpenFraction, Candidate) : FMath::Min(OpenFraction, Candidate);
	if (!bOpening && WouldCloseThroughPawn(NewFraction))
	{
		return;
	}

	MotionElapsed = NewElapsed;
	SetDoorOpenFraction(NewFraction);
	if (Progress < 1.0f)
	{
		return;
	}

	SetActorTickEnabled(false);
	if (bOpening)
	{
		DoorState = EYIXIDoorState::Open;
		OnDoorOpened.Broadcast();
	}
	else
	{
		DoorState = EYIXIDoorState::Closed;
		bCompletedCycle = true;
		OnDoorClosed.Broadcast();
	}
}

float AYIXIInteractiveDoor::EvaluateEase(float Progress, const UCurveFloat* Curve) const
{
	if (Progress <= 0.0f || Progress >= 1.0f)
	{
		return FMath::Clamp(Progress, 0.0f, 1.0f);
	}
	if (Curve)
	{
		const float Start = Curve->GetFloatValue(0.0f);
		const float End = Curve->GetFloatValue(1.0f);
		const float Value = Curve->GetFloatValue(Progress);
		const float Span = End - Start;
		if (FMath::IsFinite(Value) && FMath::IsFinite(Span) && !FMath::IsNearlyZero(Span))
		{
			return FMath::Clamp((Value - Start) / Span, 0.0f, 1.0f);
		}
	}
	return FMath::SmoothStep(0.0f, 1.0f, Progress);
}

FQuat AYIXIInteractiveDoor::PivotRotationAt(float Fraction) const
{
	const FQuat LocalSwing(FVector::UpVector, FMath::DegreesToRadians(OpenAngleDegrees * Fraction));
	return LocalSwing * ClosedRotation.Quaternion();
}

void AYIXIInteractiveDoor::SetDoorOpenFraction(float Fraction)
{
	OpenFraction = Fraction;
	HingePivot->SetRelativeRotation(PivotRotationAt(Fraction));
}

bool AYIXIInteractiveDoor::WouldCloseThroughPawn(float NewFraction) const
{
	UWorld* World = GetWorld();
	const UStaticMesh* Mesh = DoorLeaf->GetStaticMesh();
	if (!World || !Mesh || !CollisionEnabledHasQuery(DoorLeaf->GetCollisionEnabled())
		|| DoorLeaf->GetCollisionResponseToChannel(ECC_Pawn) != ECR_Block
		|| FMath::IsNearlyEqual(OpenFraction, NewFraction, UE_SMALL_NUMBER))
	{
		return false;
	}

	const FTransform LeafInPivot = DoorLeaf->GetRelativeTransform() * LeafMount->GetRelativeTransform();
	const FTransform RootInWorld = DoorRoot->GetComponentTransform();
	const FBoxSphereBounds Bounds = Mesh->GetBounds();
	const double HingeRadius = RootInWorld.GetScale3D().GetAbsMax() * HingePivot->GetRelativeScale3D().GetAbsMax()
		* (LeafInPivot.TransformPosition(Bounds.Origin).Size() + Bounds.SphereRadius * LeafInPivot.GetScale3D().GetAbsMax());
	const double Arc = HingeRadius * FMath::DegreesToRadians(FMath::Abs(OpenAngleDegrees * (NewFraction - OpenFraction)));
	const int32 Steps = FMath::CeilToInt(FMath::Clamp(Arc / 8.0, 1.0, 64.0));
	const double Padding = 1.5 + Arc / (2.0 * Steps);
	const FCollisionObjectQueryParams PawnObjects(ECC_Pawn);
	const FCollisionQueryParams Query(SCENE_QUERY_STAT(YIXIDoorClosing), false, this);

	// A rotational movement sweep checks only the root. Sample padded leaf bounds along the actual arc.
	// The half-step arc padding covers motion between samples, including low frame-rate steps.
	for (int32 Index = 0; Index < Steps; ++Index)
	{
		const float Fraction = FMath::Lerp(OpenFraction, NewFraction, (Index + 0.5f) / Steps);
		FTransform PivotInRoot = HingePivot->GetRelativeTransform();
		PivotInRoot.SetRotation(PivotRotationAt(Fraction));
		const FTransform LeafInWorld = LeafInPivot * PivotInRoot * RootInWorld;
		const FVector Center = LeafInWorld.TransformPosition(Bounds.Origin);
		const FVector Extent = Bounds.BoxExtent * LeafInWorld.GetScale3D().GetAbs() + FVector(Padding);
		if (World->OverlapAnyTestByObjectType(Center, LeafInWorld.GetRotation(), PawnObjects,
			FCollisionShape::MakeBox(Extent), Query))
		{
			return true;
		}
	}
	return false;
}

#undef LOCTEXT_NAMESPACE
