#include "YIXI_Interaction/YIXIDoubleDoor.h"

#include "CollisionQueryParams.h"
#include "CollisionShape.h"
#include "Components/SceneComponent.h"
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

#define LOCTEXT_NAMESPACE "YIXIDoubleDoor"

namespace
{
	void ConfigureMesh(UStaticMeshComponent& Component, UStaticMesh* Mesh, const FTransform& RelativeTransform)
	{
		Component.SetStaticMesh(Mesh);
		Component.SetRelativeTransform(RelativeTransform);
	}

	FQuat HingeRotationAt(const FRotator& ClosedRotation, float SwingDegrees, float Fraction)
	{
		const FQuat Swing(FVector::UpVector, FMath::DegreesToRadians(SwingDegrees * Fraction));
		return Swing * ClosedRotation.Quaternion();
	}

	float EvaluateDoorEase(float Progress, const UCurveFloat* Curve)
	{
		if (Progress <= 0.0f || Progress >= 1.0f)
		{
			return FMath::Clamp(Progress, 0.0f, 1.0f);
		}

		if (Curve)
		{
			const float Start = Curve->GetFloatValue(0.0f);
			const float Span = Curve->GetFloatValue(1.0f) - Start;
			const float Value = Curve->GetFloatValue(Progress);
			if (FMath::IsFinite(Value) && FMath::IsFinite(Span) && !FMath::IsNearlyZero(Span))
			{
				return FMath::Clamp((Value - Start) / Span, 0.0f, 1.0f);
			}
		}

		return FMath::SmoothStep(0.0f, 1.0f, Progress);
	}
}

AYIXIDoubleDoor::AYIXIDoubleDoor()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.TickGroup = TG_PostPhysics;

	DoorFrameRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorFrameRoot"));
	SetRootComponent(DoorFrameRoot);

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(DoorFrameRoot);
	DoorFrame->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);

	LeftHinge = CreateDefaultSubobject<USceneComponent>(TEXT("LeftHinge"));
	LeftHinge->SetupAttachment(DoorFrameRoot);
	LeftLeaf = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftLeaf"));
	LeftLeaf->SetupAttachment(LeftHinge);
	LeftLeaf->SetMobility(EComponentMobility::Movable);
	LeftLeaf->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);

	RightHinge = CreateDefaultSubobject<USceneComponent>(TEXT("RightHinge"));
	RightHinge->SetupAttachment(DoorFrameRoot);
	RightLeaf = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightLeaf"));
	RightLeaf->SetupAttachment(RightHinge);
	RightLeaf->SetMobility(EComponentMobility::Movable);
	RightLeaf->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);

	CenterInteractionAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("CenterInteractionAnchor"));
	CenterInteractionAnchor->SetupAttachment(DoorFrameRoot);
	InteractionAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("InteractionAnchor"));
	InteractionAnchor->SetupAttachment(CenterInteractionAnchor);
	SoundOrigin = CreateDefaultSubobject<USceneComponent>(TEXT("SoundOrigin"));
	SoundOrigin->SetupAttachment(DoorFrameRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Engine/BasicShapes/Cube.Cube"));
	DoorFrameMesh = Cube.Object;
	LeftDoorMesh = Cube.Object;
	RightDoorMesh = Cube.Object;
	ApplyConfiguration();
	SetOpenFraction(0.0f);
}

void AYIXIDoubleDoor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	ApplyConfiguration();
	ResetMotion();
}

void AYIXIDoubleDoor::BeginPlay()
{
	ApplyConfiguration();
	ResetMotion();
	Super::BeginPlay();
}

void AYIXIDoubleDoor::ApplyConfiguration()
{
	ConfigureMesh(*DoorFrame, DoorFrameMesh.Get(), DoorFrameTransform);
	ConfigureMesh(*LeftLeaf, LeftDoorMesh.Get(), LeftLeafTransform);
	ConfigureMesh(*RightLeaf, RightDoorMesh.Get(), RightLeafTransform);
	LeftHinge->SetRelativeLocation(LeftHingeOffset);
	RightHinge->SetRelativeLocation(RightHingeOffset);
	CenterInteractionAnchor->SetRelativeLocation(CenterInteractionAnchorOffset);
	SoundOrigin->SetRelativeLocation(SoundOriginOffset);
}

void AYIXIDoubleDoor::ResetMotion()
{
	SetActorTickEnabled(false);
	MotionElapsed = 0.0f;
	MotionDuration = 0.0f;
	MotionStartFraction = bStartOpened ? 1.0f : 0.0f;
	DoorState = bStartOpened ? EYIXIDoorState::Open : EYIXIDoorState::Closed;
	SetOpenFraction(MotionStartFraction);
}

FYIXIInteractionPrompt AYIXIDoubleDoor::GetInteractionPrompt_Implementation(APawn* Interactor) const
{
	FYIXIInteractionPrompt Prompt;
	Prompt.WorldLocation = InteractionAnchor->GetComponentLocation();
	if (DoorState == EYIXIDoorState::Open && !bCanClose)
	{
		// Remove a permanently open door from target selection as well as the HUD.
		Prompt.DetectionRange = 0.0f;
		Prompt.InteractRange = 0.0f;
		Prompt.bShowPrompt = false;
		return Prompt;
	}
	Prompt.DetectionRange = FMath::Max(0.0f, DetectionRange);
	Prompt.InteractRange = FMath::Clamp(InteractRange, 0.0f, Prompt.DetectionRange);
	const bool bWouldClose = DoorState == EYIXIDoorState::Open || DoorState == EYIXIDoorState::Opening;
	Prompt.ActionText = bWouldClose ? LOCTEXT("CloseDoor", "Close door") : LOCTEXT("OpenDoor", "Open door");
	Prompt.bShowPrompt = bShowHUDPrompt;
	return Prompt;
}

bool AYIXIDoubleDoor::CanInteract_Implementation(APawn* Interactor) const
{
	if (!IsValid(Interactor) || Interactor->GetWorld() != GetWorld())
	{
		return false;
	}

	switch (DoorState)
	{
	case EYIXIDoorState::Closed:
		return true;
	case EYIXIDoorState::Opening:
		return bCanClose && bAllowReverseDuringAnimation;
	case EYIXIDoorState::Open:
		return bCanClose;
	case EYIXIDoorState::Closing:
		return bAllowReverseDuringAnimation;
	}
	return false;
}

void AYIXIDoubleDoor::Interact_Implementation(APawn* Interactor)
{
	if (IYIXIInteractable::Execute_CanInteract(this, Interactor))
	{
		BeginMotion(DoorState == EYIXIDoorState::Closed || DoorState == EYIXIDoorState::Closing);
	}
}

void AYIXIDoubleDoor::BeginMotion(bool bOpening)
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
			Volume, 1.0f, 0.0f, SoundAttenuation.Get());
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

void AYIXIDoubleDoor::Tick(float DeltaSeconds)
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
	const float Eased = EvaluateDoorEase(Progress, bOpening ? OpeningCurve.Get() : ClosingCurve.Get());
	const float Candidate = FMath::Lerp(MotionStartFraction, Goal, Eased);
	const float NewFraction = bOpening ? FMath::Max(OpenFraction, Candidate) : FMath::Min(OpenFraction, Candidate);

	if (!bOpening && (WouldCloseLeafThroughPawn(*LeftHinge, *LeftLeaf, LeftClosedRotation, LeftOpenAngle, NewFraction)
		|| WouldCloseLeafThroughPawn(*RightHinge, *RightLeaf, RightClosedRotation, RightOpenAngle, NewFraction)))
	{
		return;
	}

	MotionElapsed = NewElapsed;
	SetOpenFraction(NewFraction);
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
		OnDoorClosed.Broadcast();
	}
}

void AYIXIDoubleDoor::SetOpenFraction(float Fraction)
{
	OpenFraction = Fraction;
	LeftHinge->SetRelativeRotation(HingeRotationAt(LeftClosedRotation, LeftOpenAngle, Fraction));
	RightHinge->SetRelativeRotation(HingeRotationAt(RightClosedRotation, RightOpenAngle, Fraction));
}

bool AYIXIDoubleDoor::WouldCloseLeafThroughPawn(const USceneComponent& Hinge, const UStaticMeshComponent& Leaf,
	const FRotator& ClosedRotation, float OpenAngle, float NewFraction) const
{
	UWorld* World = GetWorld();
	const UStaticMesh* Mesh = Leaf.GetStaticMesh();
	const float SwingDegrees = FMath::Abs(OpenAngle * (NewFraction - OpenFraction));
	if (!World || !Mesh || !CollisionEnabledHasQuery(Leaf.GetCollisionEnabled())
		|| Leaf.GetCollisionResponseToChannel(ECC_Pawn) != ECR_Block || SwingDegrees <= 0.0f)
	{
		return false;
	}

	const FTransform LeafInHinge = Leaf.GetRelativeTransform();
	const FTransform FrameInWorld = DoorFrameRoot->GetComponentTransform();
	const FBoxSphereBounds Bounds = Mesh->GetBounds();
	const double RadiusInHinge = LeafInHinge.TransformPosition(Bounds.Origin).Size()
		+ Bounds.SphereRadius * LeafInHinge.GetScale3D().GetAbsMax();
	const double MaxWorldScale = FrameInWorld.GetScale3D().GetAbsMax() * Hinge.GetRelativeScale3D().GetAbsMax();
	const double Arc = RadiusInHinge * MaxWorldScale * FMath::DegreesToRadians(SwingDegrees);

	// Expand each midpoint sample by the maximum distance any edge can travel to the interval endpoint.
	constexpr double SampleSpacingCm = 8.0;
	constexpr double MaxSamples = 64.0;
	const int32 Steps = FMath::CeilToInt(FMath::Clamp(Arc / SampleSpacingCm, 1.0, MaxSamples));
	const double Padding = 1.5 + Arc / (2.0 * Steps);
	const FCollisionObjectQueryParams PawnObjects(ECC_Pawn);
	const FCollisionQueryParams Query(SCENE_QUERY_STAT(YIXIDoubleDoorClosing), false, this);
	FTransform HingeInFrame = Hinge.GetRelativeTransform();

	for (int32 Step = 0; Step < Steps; ++Step)
	{
		const float Fraction = FMath::Lerp(OpenFraction, NewFraction, (Step + 0.5f) / Steps);
		HingeInFrame.SetRotation(HingeRotationAt(ClosedRotation, OpenAngle, Fraction));
		const FTransform LeafInWorld = LeafInHinge * HingeInFrame * FrameInWorld;
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
