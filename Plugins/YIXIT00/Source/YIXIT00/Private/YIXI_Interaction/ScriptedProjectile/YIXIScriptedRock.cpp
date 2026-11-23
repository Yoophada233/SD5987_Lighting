#include "YIXI_Interaction/ScriptedProjectile/YIXIScriptedRock.h"

#include "CollisionQueryParams.h"
#include "CollisionShape.h"
#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Curves/CurveFloat.h"
#include "Engine/DecalActor.h"
#include "Engine/StaticMesh.h"
#include "Engine/TargetPoint.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundBase.h"
#include "UObject/ConstructorHelpers.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIScriptedRock, Log, All);

namespace
{
	void PrepareSpatialCue(UAudioComponent& Audio, USceneComponent* Parent)
	{
		Audio.SetupAttachment(Parent);
		Audio.SetAutoActivate(false);
		Audio.bAllowSpatialization = true;
		Audio.bOverrideAttenuation = true;
		Audio.AttenuationOverrides.bAttenuate = true;
		Audio.AttenuationOverrides.bSpatialize = true;
	}

	void PlaySpatialCue(UAudioComponent& Audio, USoundBase* Sound, float Volume, USoundAttenuation* Attenuation)
	{
		if (IsValid(Sound) && Volume > 0.0f)
		{
			Audio.AttenuationSettings = Attenuation;
			Audio.bOverrideAttenuation = !IsValid(Attenuation);
			Audio.SetVolumeMultiplier(Volume);
			Audio.SetSound(Sound);
			Audio.Play();
		}
	}
}

AYIXIScriptedRock::AYIXIScriptedRock()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	USceneComponent* SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StartAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("StartAnchor"));
	StartAnchor->SetupAttachment(SceneRoot);
	StartAnchor->SetRelativeLocation(FVector(0.0, 0.0, 350.0));

	ImpactAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("ImpactAnchor"));
	ImpactAnchor->SetupAttachment(SceneRoot);
	ImpactAnchor->SetRelativeLocation(FVector(450.0, 0.0, 100.0));

	RockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RockMesh"));
	RockMesh->SetupAttachment(SceneRoot);
	RockMesh->SetMobility(EComponentMobility::Movable);
	RockMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RockMesh->SetCanEverAffectNavigation(false);
	RockMesh->SetHiddenInGame(true);

	static const ConstructorHelpers::FObjectFinder<UStaticMesh> DefaultRock(
		TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	RockMesh->SetStaticMesh(DefaultRock.Object);
	RockMesh->SetRelativeScale3D(FVector(2.4, 1.3, 2.0));

	FlightAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("FlightAudio"));
	PrepareSpatialCue(*FlightAudio, RockMesh);
	ImpactAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("ImpactAudio"));
	PrepareSpatialCue(*ImpactAudio, SceneRoot);

	Blocker = CreateDefaultSubobject<UBoxComponent>(TEXT("Blocker"));
	Blocker->SetupAttachment(ImpactAnchor);
	Blocker->InitBoxExtent(FVector(110.0, 60.0, 85.0));
	Blocker->SetMobility(EComponentMobility::Movable);
	Blocker->SetCollisionObjectType(ECC_WorldDynamic);
	Blocker->SetCollisionResponseToAllChannels(ECR_Ignore);
	Blocker->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	Blocker->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Blocker->SetGenerateOverlapEvents(false);
	Blocker->SetCanEverAffectNavigation(false);
	Blocker->SetHiddenInGame(true);
}

void AYIXIScriptedRock::BeginPlay()
{
	if (UDecalComponent* Decal = GetImpactDecalComponent())
	{
		SetImpactDecalHidden(true);
		// The story owns the lifetime of the crack. Clear an authored fade-out timer in play.
		Decal->SetFadeOut(0.0f, 0.0f, false);
	}
	else
	{
		UE_LOG(LogYIXIScriptedRock, Display, TEXT("%s: assign an Impact Decal at this rock's landing site to show an impact crack."),
			*GetPathName());
	}
	Super::BeginPlay();
}

bool AYIXIScriptedRock::Launch(int32 RequestId)
{
	if (RequestId <= 0 || RockState != EYIXIScriptedRockState::Idle || !HasActorBegunPlay()
		|| IsActorBeingDestroyed() || !FMath::IsFinite(TravelDuration) || TravelDuration <= 0.0f
		|| !FMath::IsFinite(VerticalLift))
	{
		return false;
	}

	if ((FlightStartMarker && (!IsValid(FlightStartMarker) || FlightStartMarker->GetWorld() != GetWorld()))
		|| (FlightImpactMarker && (!IsValid(FlightImpactMarker) || FlightImpactMarker->GetWorld() != GetWorld())))
	{
		return false;
	}

	// Resolve authored markers at launch. Unbound rock instances still use their component anchors.
	FTransform Start = StartAnchor->GetComponentTransform();
	const FTransform AuthoredImpact = ImpactAnchor->GetComponentTransform();
	FTransform End = AuthoredImpact;
	FTransform BlockageTransform = Blocker->GetComponentTransform();
	if (FlightStartMarker)
	{
		Start.SetLocation(FlightStartMarker->GetActorLocation() + StartMarkerOffset);
	}
	if (FlightImpactMarker)
	{
		End.SetLocation(FlightImpactMarker->GetActorLocation() + ImpactMarkerOffset);
		BlockageTransform = BlockageTransform.GetRelativeTransform(AuthoredImpact) * End;
	}
	const FVector BlockageExtent = Blocker->GetScaledBoxExtent();
	if (Start.ContainsNaN() || End.ContainsNaN()
		|| (bEnableBlockageAfterImpact && (!GetActorEnableCollision()
			|| BlockageTransform.ContainsNaN() || BlockageExtent.ContainsNaN()
			|| BlockageExtent.GetMin() <= UE_KINDA_SMALL_NUMBER)))
	{
		return false;
	}

	// Keep the visual alignment separate from the anchor path and the blockage volume.
	FTransform Alignment = RockMesh->GetRelativeTransform();
	Alignment.SetTranslation(Alignment.GetTranslation() * GetRootComponent()->GetComponentScale());
	Alignment.SetScale3D(RockMesh->GetComponentScale());
	if (!Alignment.IsValid())
	{
		return false;
	}
	RestMeshTransform = RockMesh->GetRelativeTransform();
	RestBlockerTransform = Blocker->GetRelativeTransform();
	MeshAlignment = Alignment;
	LaunchPose = Start;
	LandingPose = End;
	LandingBlockerPose = BlockageTransform;
	ActiveRequestId = RequestId;
	ActiveDuration = TravelDuration;
	ActiveLift = FMath::Max(0.0f, VerticalLift);
	bPendingBlockage = bEnableBlockageAfterImpact;
	RockState = EYIXIScriptedRockState::InFlight;

	Blocker->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RockMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RockMesh->SetWorldTransform(MakeRockMeshPose(LaunchPose.GetLocation(), LaunchPose.GetRotation()));
	RockMesh->SetHiddenInGame(false);
	SetActorTickEnabled(true);

	if (LaunchSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, LaunchSound, RockMesh->GetComponentLocation());
	}
	PlaySpatialCue(*FlightAudio, FlightSound, FlightVolume, FlightAttenuation);
	OnLaunched.Broadcast(ActiveRequestId);
	return true;
}

void AYIXIScriptedRock::ResetRock()
{
	if (!HasActorBegunPlay() || IsActorBeingDestroyed())
	{
		return;
	}

	const bool bNeedsRestPose = RockState != EYIXIScriptedRockState::Idle;
	RockState = EYIXIScriptedRockState::Idle;
	ActiveRequestId = 0;
	ElapsedTime = 0.0f;
	bImpactOccurred = false;
	bPendingBlockage = false;
	SetActorTickEnabled(false);
	FlightAudio->Stop();
	ImpactAudio->Stop();
	Blocker->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RockMesh->SetHiddenInGame(true);
	if (bNeedsRestPose)
	{
		RockMesh->SetRelativeTransform(RestMeshTransform);
		Blocker->SetRelativeTransform(RestBlockerTransform);
	}
	SetImpactDecalHidden(true);
}

bool AYIXIScriptedRock::IsBlockageReady() const
{
	return RockState == EYIXIScriptedRockState::Blocking && GetActorEnableCollision() && Blocker->IsPhysicsStateCreated()
		&& Blocker->GetCollisionEnabled() == ECollisionEnabled::QueryAndPhysics
		&& Blocker->GetCollisionResponseToChannel(ECC_Pawn) == ECR_Block;
}

void AYIXIScriptedRock::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (IsActorBeingDestroyed())
	{
		return;
	}
	if (RockState == EYIXIScriptedRockState::WaitingForClearance)
	{
		TryEnableBlockage();
		return;
	}
	if (RockState != EYIXIScriptedRockState::InFlight)
	{
		return;
	}

	ElapsedTime = FMath::Min(ElapsedTime + DeltaSeconds, ActiveDuration);
	const float Alpha = ElapsedTime / ActiveDuration;
	if (Alpha >= 1.0f)
	{
		FinishTravel();
		return;
	}

	const FVector BasePosition = FMath::Lerp(LaunchPose.GetLocation(), LandingPose.GetLocation(), Alpha);
	const FVector Position = BasePosition + FVector::UpVector * (ActiveLift * EvaluateVerticalShape(Alpha));
	const FQuat Rotation = FQuat::Slerp(LaunchPose.GetRotation(), LandingPose.GetRotation(), Alpha);
	const FTransform MeshPose = MakeRockMeshPose(Position, Rotation);
	RockMesh->SetWorldLocationAndRotation(MeshPose.GetLocation(), MeshPose.GetRotation());
}

FTransform AYIXIScriptedRock::MakeRockMeshPose(const FVector& PathLocation, const FQuat& PathRotation) const
{
	return FTransform(PathRotation * MeshAlignment.GetRotation(),
		PathLocation + PathRotation.RotateVector(MeshAlignment.GetTranslation()), MeshAlignment.GetScale3D());
}

float AYIXIScriptedRock::EvaluateVerticalShape(float Alpha) const
{
	if (VerticalShape)
	{
		const float Start = VerticalShape->GetFloatValue(0.0f);
		const float End = VerticalShape->GetFloatValue(1.0f);
		const float Shape = VerticalShape->GetFloatValue(Alpha) - FMath::Lerp(Start, End, Alpha);
		if (FMath::IsFinite(Shape))
		{
			return Shape;
		}
	}

	return 4.0f * Alpha * (1.0f - Alpha);
}

UDecalComponent* AYIXIScriptedRock::GetImpactDecalComponent() const
{
	return IsValid(ImpactDecal) && !ImpactDecal->IsActorBeingDestroyed() && ImpactDecal->GetWorld() == GetWorld()
		? ImpactDecal->GetDecal() : nullptr;
}

void AYIXIScriptedRock::SetImpactDecalHidden(bool bHideDecal)
{
	if (GetImpactDecalComponent())
	{
	ImpactDecal->SetActorHiddenInGame(bHideDecal);
	}
}

void AYIXIScriptedRock::FinishTravel()
{
	RockMesh->SetWorldTransform(MakeRockMeshPose(LandingPose.GetLocation(), LandingPose.GetRotation()));
	bImpactOccurred = true;
	RockState = bPendingBlockage ? EYIXIScriptedRockState::WaitingForClearance
		: EYIXIScriptedRockState::Impacted;
	SetActorTickEnabled(bPendingBlockage);
	if (bPendingBlockage)
	{
		Blocker->SetWorldTransform(LandingBlockerPose);
	}

	FlightAudio->Stop();
	ImpactAudio->SetWorldLocation(RockMesh->GetComponentLocation());
	PlaySpatialCue(*ImpactAudio, ImpactSound, ImpactVolume, ImpactAttenuation);
	SetImpactDecalHidden(false);

	// Consumers see the landed pose before clearance can fire its separate event.
	OnImpact.Broadcast(ActiveRequestId);
	if (!IsActorBeingDestroyed() && RockState == EYIXIScriptedRockState::WaitingForClearance)
	{
		TryEnableBlockage();
	}
}

void AYIXIScriptedRock::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	FlightAudio->Stop();
	ImpactAudio->Stop();
	Super::EndPlay(EndPlayReason);
}

void AYIXIScriptedRock::TryEnableBlockage()
{
	if (!GetActorEnableCollision() || !Blocker->IsRegistered())
	{
		return;
	}
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	const FTransform BlockerPose = Blocker->GetComponentTransform();
	const FVector Extent = Blocker->GetScaledBoxExtent();
	if (BlockerPose.ContainsNaN() || Extent.ContainsNaN() || Extent.GetMin() <= UE_KINDA_SMALL_NUMBER)
	{
		return;
	}
	const FCollisionShape ClearanceShape = FCollisionShape::MakeBox(Extent + FVector(2.0));
	const FCollisionObjectQueryParams PawnObjects(ECC_Pawn);
	const FCollisionQueryParams Params(SCENE_QUERY_STAT(YIXIRockClearance), false, this);
	if (World->OverlapAnyTestByObjectType(BlockerPose.GetLocation(), BlockerPose.GetRotation(),
		PawnObjects, ClearanceShape, Params))
	{
		return;
	}

	Blocker->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	Blocker->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	if (!Blocker->IsPhysicsStateCreated())
	{
		Blocker->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		return;
	}
	RockState = EYIXIScriptedRockState::Blocking;
	SetActorTickEnabled(false);
	OnBlockageReady.Broadcast(ActiveRequestId);
}
