#include "YIXI_Interaction/DialogueToy/YIXIToyCarryComponent.h"

#include "CollisionQueryParams.h"
#include "CollisionShape.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"
#include "YIXI_Interaction/DialogueToy/YIXIStoryToyPickup.h"

namespace
{
	FCollisionQueryParams MakeDropQuery(const APawn& Pawn, const AStaticMeshActor& Toy)
	{
		FCollisionQueryParams Params(SCENE_QUERY_STAT(YIXIToyDrop), false, &Pawn);
		Params.AddIgnoredActor(&Toy);
		return Params;
	}

	FCollisionShape MakeDropShape(const FBoxSphereBounds& Bounds, const FVector& Scale)
	{
		return FCollisionShape::MakeBox((Bounds.BoxExtent * Scale.GetAbs()).ComponentMax(FVector(0.5)));
	}

	bool PlaceDetachedToy(AStaticMeshActor& Toy, const FTransform& Pose)
	{
		// MoveComponent reports whether it changed a transform. A sub-tolerance curve step can be a valid no-op.
		Toy.SetActorLocationAndRotation(Pose.GetLocation(), Pose.GetRotation(), false, nullptr, ETeleportType::TeleportPhysics);
		return Toy.GetActorLocation().Equals(Pose.GetLocation(), UE_KINDA_SMALL_NUMBER)
			&& Toy.GetActorQuat().Equals(Pose.GetRotation(), UE_KINDA_SMALL_NUMBER);
	}
}

UYIXIToyCarryComponent::UYIXIToyCarryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	FallbackHandRelativeTransform = FTransform(FVector(38.0, 28.0, 5.0));
	FallbackWaistRelativeTransform = FTransform(FVector(-24.0, 0.0, -24.0));
}

UYIXIToyCarryComponent* UYIXIToyCarryComponent::FindForPawn(APawn* Pawn)
{
	if (!IsValid(Pawn) || !Pawn->IsPlayerControlled())
	{
		return nullptr;
	}

	if (AController* Controller = Pawn->GetController())
	{
		if (UYIXIToyCarryComponent* Carry = Controller->FindComponentByClass<UYIXIToyCarryComponent>())
		{
			return Carry;
		}
	}

	return Pawn->FindComponentByClass<UYIXIToyCarryComponent>();
}

void UYIXIToyCarryComponent::BeginPlay()
{
	Super::BeginPlay();
	if (AController* Controller = Cast<AController>(GetOwner()))
	{
		Controller->OnPossessedPawnChanged.AddUniqueDynamic(this, &ThisClass::HandlePawnChanged);
	}
}

void UYIXIToyCarryComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	bEndingPlay = true;
	if (AController* Controller = Cast<AController>(GetOwner()))
	{
		Controller->OnPossessedPawnChanged.RemoveDynamic(this, &ThisClass::HandlePawnChanged);
	}
	if (IsValid(ToyActor.Get()))
	{
		ToyActor->OnDestroyed.RemoveDynamic(this, &ThisClass::HandleToyDestroyed);
		ToyActor->Destroy();
	}
	ToyActor = nullptr;
	CarrierPawn.Reset();
	CarryState = EYIXIToyCarryState::Grounded;

	Super::EndPlay(EndPlayReason);
}

AActor* UYIXIToyCarryComponent::GetToyActor() const
{
	return IsValid(ToyActor.Get()) ? ToyActor.Get() : nullptr;
}

APawn* UYIXIToyCarryComponent::GetControlledPawn() const
{
	if (const AController* Controller = Cast<AController>(GetOwner()))
	{
		return Controller->GetPawn();
	}
	return Cast<APawn>(GetOwner());
}

bool UYIXIToyCarryComponent::CanTakeToy(APawn* Pawn) const
{
	return !bEndingPlay && IsValid(Pawn) && Pawn == GetControlledPawn()
		&& Pawn->GetWorld() == GetWorld() && Pawn->IsPlayerControlled()
		&& CarryState == EYIXIToyCarryState::Grounded && !GetToyActor();
}

bool UYIXIToyCarryComponent::FindAttachment(APawn& Pawn, bool bWaist, FAttachment& OutAttachment) const
{
	const FName Socket = bWaist ? WaistSocketName : HandSocketName;
	const FTransform& SocketPose = bWaist ? WaistRelativeTransform : HandRelativeTransform;
	if (!Socket.IsNone() && SocketPose.IsValid())
	{
		TInlineComponentArray<USkeletalMeshComponent*> Meshes;
		Pawn.GetComponents(Meshes);
		for (USkeletalMeshComponent* Mesh : Meshes)
		{
			if (IsValid(Mesh) && Mesh->IsRegistered() && Mesh->GetSkeletalMeshAsset()
				&& (PawnMeshComponentName.IsNone() || Mesh->GetFName() == PawnMeshComponentName)
				&& Mesh->DoesSocketExist(Socket))
			{
				OutAttachment = {Mesh, Socket, SocketPose};
				return true;
			}
		}
	}

	const FTransform& FallbackPose = bWaist ? FallbackWaistRelativeTransform : FallbackHandRelativeTransform;
	USceneComponent* Root = Pawn.GetRootComponent();
	if (bAllowRootAttachmentFallback && IsValid(Root) && Root->IsRegistered() && FallbackPose.IsValid())
	{
		OutAttachment = {Root, NAME_None, FallbackPose};
		return true;
	}
	return false;
}

bool UYIXIToyCarryComponent::AttachToy(AStaticMeshActor& Actor, const FAttachment& Attachment, const FVector& BaseScale) const
{
	if (!Actor.AttachToComponent(Attachment.Parent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, Attachment.Socket))
	{
		return false;
	}

	Actor.SetActorRelativeLocation(Attachment.RelativePose.GetLocation());
	Actor.SetActorRelativeRotation(Attachment.RelativePose.GetRotation());
	Actor.SetActorScale3D(BaseScale * Attachment.RelativePose.GetScale3D());
	return true;
}

bool UYIXIToyCarryComponent::TryPickup(APawn* Pawn, AYIXIStoryToyPickup& Pickup)
{
	UWorld* World = GetWorld();
	if (!CanTakeToy(Pawn) || !World || !World->PersistentLevel || Pickup.GetWorld() != World || !Pickup.IsPickupAvailable())
	{
		return false;
	}

	FAttachment Attachment;
	if (!FindAttachment(*Pawn, false, Attachment))
	{
		return false;
	}

	UStaticMeshComponent* Source = Pickup.ToyMesh.Get();
	const FTransform SourcePose = Source->GetComponentTransform();
	FActorSpawnParameters Spawn;
	Spawn.Owner = GetOwner();
	Spawn.OverrideLevel = World->PersistentLevel;
	Spawn.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AStaticMeshActor* Prop = World->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), SourcePose, Spawn);
	if (!IsValid(Prop))
	{
		return false;
	}

	Prop->SetActorEnableCollision(false);
	UStaticMeshComponent* VisibleMesh = Prop->GetStaticMeshComponent();
	VisibleMesh->SetMobility(EComponentMobility::Movable);
	VisibleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	VisibleMesh->SetStaticMesh(Source->GetStaticMesh());
	for (int32 MaterialIndex = 0; MaterialIndex < Source->GetNumMaterials(); ++MaterialIndex)
	{
		VisibleMesh->SetMaterial(MaterialIndex, Source->GetMaterial(MaterialIndex));
	}

	const FVector BaseScale = SourcePose.GetScale3D();
	if (!AttachToy(*Prop, Attachment, BaseScale))
	{
		Prop->Destroy();
		return false;
	}

	ToyBaseScale = BaseScale;
	ToyActor = Prop;
	CarrierPawn = Pawn;
	Prop->OnDestroyed.AddUniqueDynamic(this, &ThisClass::HandleToyDestroyed);
	Pickup.CommitPickup();
	SetCarryState(Pawn, EYIXIToyCarryState::HeldHand);
	if (IsValid(&Pickup) && IsValid(Pawn))
	{
		Pickup.OnToyPickedUp.Broadcast(Pawn);
	}
	return true;
}

bool UYIXIToyCarryComponent::TryDrop()
{
	APawn* Pawn = GetControlledPawn();
	if (!IsValid(Pawn))
	{
		return false;
	}
	const FQuat Rotation = FRotator(0.0, Pawn->GetActorRotation().Yaw, 0.0).Quaternion();
	const FTransform GroundAnchor(Rotation, Pawn->GetActorLocation() + Rotation.RotateVector(DropOffset));
	FTransform LandingPose;
	return FindCinematicDropPose(GroundAnchor, LandingPose) && TryDropAt(LandingPose);
}

bool UYIXIToyCarryComponent::FindCinematicDropPose(const FTransform& GroundAnchor, FTransform& OutPose) const
{
	APawn* Pawn = GetControlledPawn();
	UWorld* World = GetWorld();
	if (bEndingPlay || (CarryState != EYIXIToyCarryState::HeldHand && CarryState != EYIXIToyCarryState::Falling)
		|| !World || !IsValid(Pawn)
		|| CarrierPawn.Get() != Pawn || !GetToyActor() || !GroundAnchor.IsValid())
	{
		return false;
	}

	const UStaticMesh* Mesh = ToyActor->GetStaticMeshComponent()->GetStaticMesh();
	if (!Mesh)
	{
		return false;
	}

	const FBoxSphereBounds Bounds = Mesh->GetBounds();
	const FQuat DropRotation = GroundAnchor.GetRotation();
	const FVector BoundsOffset = DropRotation.RotateVector(Bounds.Origin * ToyActor->GetActorScale3D());
	const FVector DropCenter = GroundAnchor.GetLocation() + BoundsOffset;
	const FVector Start = DropCenter + FVector(0.0, 0.0, 70.0);
	const FVector End = DropCenter - FVector(0.0, 0.0, FMath::Max(1.0f, DropGroundSearchDistance));

	FHitResult Floor;
	if (!World->SweepSingleByChannel(Floor, Start, End, DropRotation, DropTraceChannel,
			MakeDropShape(Bounds, ToyActor->GetActorScale3D()), MakeDropQuery(*Pawn, *ToyActor))
		|| Floor.bStartPenetrating || Floor.ImpactNormal.Z < 0.5)
	{
		return false;
	}

	const FVector DropLocation = Floor.Location - BoundsOffset + FVector(0.0, 0.0, 1.0);
	OutPose = FTransform(DropRotation, DropLocation, ToyActor->GetActorScale3D());
	return IsDropPathClear(*Pawn, OutPose);
}

bool UYIXIToyCarryComponent::IsDropPathClear(const APawn& Pawn, const FTransform& WorldPose, bool bCheckPawnCollision) const
{
	UWorld* World = GetWorld();
	if (!World || !GetToyActor() || !WorldPose.IsValid())
	{
		return false;
	}

	const UStaticMesh* Mesh = ToyActor->GetStaticMeshComponent()->GetStaticMesh();
	if (!Mesh)
	{
		return false;
	}

	const FBoxSphereBounds Bounds = Mesh->GetBounds();
	const FVector ToyScale = ToyActor->GetActorScale3D();
	const FQuat Rotation = WorldPose.GetRotation();
	const FVector CurrentCenter = ToyActor->GetActorTransform().TransformPosition(Bounds.Origin);
	const FVector DropCenter = WorldPose.GetLocation() + Rotation.RotateVector(Bounds.Origin * ToyScale);
	const FCollisionShape Shape = MakeDropShape(Bounds, ToyScale);
	const FCollisionQueryParams Query = MakeDropQuery(Pawn, *ToyActor);
	const auto IsChannelClear = [&](ECollisionChannel Channel)
	{
		if (World->OverlapBlockingTestByChannel(DropCenter, Rotation, Channel, Shape, Query))
		{
			UE_LOG(LogTemp, Warning, TEXT("YIXI toy destination occupied at %s"), *DropCenter.ToString());
			return false;
		}
		FHitResult Hit;
		if (!CurrentCenter.Equals(DropCenter, UE_KINDA_SMALL_NUMBER)
			&& World->SweepSingleByChannel(Hit, CurrentCenter, DropCenter, Rotation, Channel, Shape, Query))
		{
			UE_LOG(LogTemp, Warning, TEXT("YIXI toy remaining path blocked by %s / %s, distance %.4fcm"),
				*GetNameSafe(Hit.GetActor()), *GetNameSafe(Hit.GetComponent()), Hit.Distance);
			return false;
		}
		return true;
	};
	return IsChannelClear(DropTraceChannel)
		&& (!bCheckPawnCollision || DropTraceChannel.GetValue() == ECC_Pawn || IsChannelClear(ECC_Pawn));
}

bool UYIXIToyCarryComponent::TryDropAt(const FTransform& WorldPose)
{
	APawn* Pawn = GetControlledPawn();
	if (bEndingPlay || CarryState != EYIXIToyCarryState::HeldHand || !IsValid(Pawn)
		|| CarrierPawn.Get() != Pawn || !IsDropPathClear(*Pawn, WorldPose))
	{
		return false;
	}

	// Check placement and move before detaching so rejects leave the hand attachment intact.
	if (!ToyActor->SetActorLocationAndRotation(WorldPose.GetLocation(), WorldPose.GetRotation(), false, nullptr, ETeleportType::TeleportPhysics))
	{
		return false;
	}

	ToyActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	CarrierPawn.Reset();
	SetCarryState(Pawn, EYIXIToyCarryState::Dropped);
	return true;
}

bool UYIXIToyCarryComponent::BeginCinematicDrop(const FTransform& LandingPose, float Duration)
{
	return StartVerticalDrop(LandingPose, Duration, false);
}

bool UYIXIToyCarryComponent::BeginSequencedVerticalDrop(const FTransform& LandingPose, float Duration, AActor* RequiredFloor)
{
	return StartVerticalDrop(LandingPose, Duration, true, RequiredFloor);
}

bool UYIXIToyCarryComponent::FindVerticalCinematicLanding(FTransform& OutPose, AActor* RequiredFloor,
	double* OutSupportZ) const
{
	const APawn* Pawn = GetControlledPawn();
	return !bEndingPlay && CarryState == EYIXIToyCarryState::HeldHand && IsValid(Pawn)
		&& CarrierPawn.Get() == Pawn && GetToyActor()
		&& ProjectBelowToy(*Pawn, ToyActor->GetActorTransform(), OutPose, RequiredFloor, OutSupportZ)
		&& IsDropPathClear(*Pawn, OutPose, RequiredFloor != nullptr);
}

bool UYIXIToyCarryComponent::ProjectBelowToy(const APawn& Pawn, const FTransform& ReleasePose, FTransform& OutPose,
	const AActor* RequiredFloor, double* OutSupportZ) const
{
	const UStaticMesh* Mesh = ToyActor->GetStaticMeshComponent()->GetStaticMesh();
	if (!Mesh || !ReleasePose.IsValid() || DropGroundSearchDistance <= 0.0f
		|| (RequiredFloor && (!IsValid(RequiredFloor) || RequiredFloor->GetWorld() != GetWorld())))
	{
		return false;
	}
	const FBoxSphereBounds Bounds = Mesh->GetBounds();
	const FVector Center = ReleasePose.TransformPosition(Bounds.Origin);
	const FVector Below = Center - FVector(0, 0, DropGroundSearchDistance);
	const ECollisionChannel GroundChannel = RequiredFloor ? ECC_Pawn : DropTraceChannel.GetValue();
	FHitResult Hit;
	if (!GetWorld()->SweepSingleByChannel(Hit, Center, Below, ReleasePose.GetRotation(), GroundChannel,
		MakeDropShape(Bounds, ReleasePose.GetScale3D()), MakeDropQuery(Pawn, *ToyActor))
		|| Hit.bStartPenetrating || Hit.Distance <= 0.4
		|| Hit.ImpactNormal.Z < (RequiredFloor ? 0.7 : 0.5)
		|| (RequiredFloor && Hit.GetActor() != RequiredFloor))
	{
		return false;
	}
	// Hit.Distance is the downward travel of the oriented mesh bounds, including signed pivot offset.
	OutPose = ReleasePose;
	OutPose.AddToTranslation(FVector(0, 0, -(Hit.Distance - 0.4)));
	if (OutSupportZ) *OutSupportZ = Hit.ImpactPoint.Z;
	return true;
}

bool UYIXIToyCarryComponent::StartVerticalDrop(const FTransform& LandingPose, float Duration, bool bFromSequence,
	AActor* RequiredFloor)
{
	FTransform GroundPose;
	if (!FMath::IsFinite(Duration) || Duration <= 0.0f || !FindVerticalCinematicLanding(GroundPose, RequiredFloor)
		|| !GroundPose.GetLocation().Equals(LandingPose.GetLocation(), 2.0)
		|| !GroundPose.GetRotation().Equals(LandingPose.GetRotation(), 1.e-4)
		|| ToyActor->GetStaticMeshComponent()->IsSimulatingPhysics())
	{
		return false;
	}

	APawn* Pawn = GetControlledPawn();
	USceneComponent* Root = ToyActor->GetRootComponent();
	if (!Root->GetAttachParent() || Root->GetAttachParent()->GetOwner() != Pawn)
	{
		return false;
	}
	ReleaseParent = Root->GetAttachParent();
	ReleaseSocket = Root->GetAttachSocketName();
	ReleaseRelativePose = Root->GetRelativeTransform();
	DropStartPose = ToyActor->GetActorTransform();
	DropEndPose = GroundPose;
	DropDuration = Duration;
	DropElapsed = 0.0f;
	DropProgress = 0.0f;
	bSequenceControlsDrop = bFromSequence;
	CinematicDropPawn = Pawn;
	CinematicDropFloor = RequiredFloor;
	ToyActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetComponentTickEnabled(!bFromSequence);
	SetCarryState(Pawn, EYIXIToyCarryState::Falling);
	return CarryState == EYIXIToyCarryState::Falling || CarryState == EYIXIToyCarryState::Dropped;
}

void UYIXIToyCarryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	APawn* Pawn = GetControlledPawn();
	if (bSequenceControlsDrop || CarryState != EYIXIToyCarryState::Falling || !IsValid(Pawn) || CinematicDropPawn.Get() != Pawn || !GetToyActor())
	{
		SetComponentTickEnabled(false);
		return;
	}

	DropElapsed += DeltaTime;
	const float Alpha = FMath::Clamp(DropElapsed / DropDuration, 0.0f, 1.0f);
	if (!MoveVerticalDrop(Alpha >= 1.0f ? 1.0f : Alpha * Alpha))
	{
		SetComponentTickEnabled(false);
		RestoreToyToHand();
	}
}

bool UYIXIToyCarryComponent::ApplySequencedDropProgress(float Alpha)
{
	return bSequenceControlsDrop && MoveVerticalDrop(Alpha);
}

bool UYIXIToyCarryComponent::MoveVerticalDrop(float Alpha)
{
	const APawn* Pawn = GetControlledPawn();
	if (bEndingPlay || CarryState != EYIXIToyCarryState::Falling || !IsValid(Pawn) || CinematicDropPawn.Get() != Pawn
		|| !GetToyActor() || ToyActor->GetAttachParentActor() || !FMath::IsFinite(Alpha)
		|| (!CinematicDropFloor.IsExplicitlyNull() && !CinematicDropFloor.IsValid()))
	{
		return false;
	}
	DropProgress = FMath::Clamp(Alpha, DropProgress, 1.0f);
	if (DropProgress >= 1.0f) return FinishCinematicDrop();
	FTransform Pose = DropStartPose;
	FVector Position = Pose.GetLocation();
	Position.Z = FMath::Lerp(Position.Z, DropEndPose.GetLocation().Z, DropProgress);
	Pose.SetLocation(Position);
	return IsDropPathClear(*Pawn, Pose, !CinematicDropFloor.IsExplicitlyNull()) && PlaceDetachedToy(*ToyActor, Pose);
}

bool UYIXIToyCarryComponent::FinishCinematicDrop()
{
	APawn* Pawn = GetControlledPawn();
	if (bEndingPlay || CarryState != EYIXIToyCarryState::Falling || !IsValid(Pawn)
		|| CinematicDropPawn.Get() != Pawn || !GetToyActor() || ToyActor->GetAttachParentActor())
	{
		return false;
	}
	// Validate the remaining segment (also covers a skip), then recheck the surface just below the endpoint.
	// A new object behind the descending toy no longer obstructs it.
	FTransform FloorProbe = DropEndPose;
	FloorProbe.AddToTranslation(FVector(0, 0, 3.0));
	FTransform FloorPose;
	AActor* RequiredFloor = CinematicDropFloor.Get();
	if (!IsDropPathClear(*Pawn, DropEndPose, !CinematicDropFloor.IsExplicitlyNull())) return false;
	if ((!RequiredFloor && !CinematicDropFloor.IsExplicitlyNull())
		|| !ProjectBelowToy(*Pawn, FloorProbe, FloorPose, RequiredFloor)
		|| !FloorPose.GetLocation().Equals(DropEndPose.GetLocation(), 0.25))
	{
		UE_LOG(LogTemp, Warning, TEXT("YIXI toy lost support at %s"), *DropEndPose.GetLocation().ToString());
		return false;
	}
	if (!PlaceDetachedToy(*ToyActor, DropEndPose))
	{
		UE_LOG(LogTemp, Warning, TEXT("YIXI toy endpoint transform not reached at %s"), *DropEndPose.GetLocation().ToString());
		return false;
	}

	SetComponentTickEnabled(false);
	CarrierPawn.Reset();
	CinematicDropFloor.Reset();
	SetCarryState(Pawn, EYIXIToyCarryState::Dropped);
	return CarryState == EYIXIToyCarryState::Dropped && GetToyActor();
}

bool UYIXIToyCarryComponent::RestoreReleaseAttachment(APawn& Pawn)
{
	USceneComponent* Parent = ReleaseParent.Get();
	if (!IsValid(Parent) || !Parent->IsRegistered() || Parent->GetOwner() != &Pawn
		|| (!ReleaseSocket.IsNone() && !Parent->DoesSocketExist(ReleaseSocket))
		|| !ToyActor->AttachToComponent(Parent, FAttachmentTransformRules::KeepWorldTransform, ReleaseSocket))
	{
		return false;
	}
	ToyActor->GetRootComponent()->SetRelativeTransform(ReleaseRelativePose);
	return true;
}

bool UYIXIToyCarryComponent::RestoreToyToHand()
{
	APawn* Pawn = GetControlledPawn();
	if (bEndingPlay || !IsValid(Pawn) || !Pawn->IsPlayerControlled() || CinematicDropPawn.Get() != Pawn || !GetToyActor()
		|| (CarryState != EYIXIToyCarryState::Falling && CarryState != EYIXIToyCarryState::Dropped))
	{
		return false;
	}
	FAttachment Hand;
	if (!RestoreReleaseAttachment(*Pawn) && (!FindAttachment(*Pawn, false, Hand) || !AttachToy(*ToyActor, Hand, ToyBaseScale)))
	{
		return false;
	}
	SetComponentTickEnabled(false);
	CarrierPawn = Pawn;
	CinematicDropPawn.Reset();
	CinematicDropFloor.Reset();
	SetCarryState(Pawn, EYIXIToyCarryState::HeldHand);
	return CarryState == EYIXIToyCarryState::HeldHand && GetToyActor();
}

bool UYIXIToyCarryComponent::CanAttachToWaist() const
{
	APawn* Pawn = GetControlledPawn();
	FAttachment Attachment;
	return !bEndingPlay && IsValid(Pawn) && Pawn->IsPlayerControlled() && Pawn->GetWorld() == GetWorld()
		&& (CinematicDropPawn.IsExplicitlyNull() || CinematicDropPawn.Get() == Pawn)
		&& GetToyActor() && FindAttachment(*Pawn, true, Attachment);
}

bool UYIXIToyCarryComponent::GetWaistPreviewTransform(FTransform& OutPose) const
{
	APawn* Pawn = GetControlledPawn();
	FAttachment Attachment;
	if (!Pawn || !CanAttachToWaist() || !FindAttachment(*Pawn, true, Attachment))
		return false;
	const FTransform Parent = Attachment.Parent->GetSocketTransform(Attachment.Socket);
	OutPose = Attachment.RelativePose * Parent;
	OutPose.SetScale3D(ToyBaseScale * Attachment.RelativePose.GetScale3D());
	return OutPose.IsValid();
}

bool UYIXIToyCarryComponent::TryAttachToWaist()
{
	APawn* Pawn = GetControlledPawn();
	if (bEndingPlay || CarryState != EYIXIToyCarryState::Dropped
		|| !IsValid(Pawn) || !Pawn->IsPlayerControlled() || Pawn->GetWorld() != GetWorld() || !GetToyActor()
		|| (!CinematicDropPawn.IsExplicitlyNull() && CinematicDropPawn.Get() != Pawn))
	{
		return false;
	}

	FAttachment Attachment;
	if (!FindAttachment(*Pawn, true, Attachment) || !AttachToy(*ToyActor, Attachment, ToyBaseScale))
	{
		return false;
	}

	CarrierPawn = Pawn;
	CinematicDropPawn.Reset();
	SetCarryState(Pawn, EYIXIToyCarryState::AttachedAtWaist);
	return true;
}

void UYIXIToyCarryComponent::SetCarryState(APawn* Pawn, EYIXIToyCarryState NewState)
{
	const EYIXIToyCarryState Previous = CarryState;
	CarryState = NewState;
	if (Previous != NewState)
	{
		OnToyStateChanged.Broadcast(Pawn, Previous, NewState);
	}
}

void UYIXIToyCarryComponent::HandlePawnChanged(APawn* PreviousPawn, APawn* NewPawn)
{
	if (!bEndingPlay && CarryState == EYIXIToyCarryState::Falling && GetToyActor())
	{
		SetComponentTickEnabled(!bSequenceControlsDrop && IsValid(NewPawn) && CinematicDropPawn.Get() == NewPawn);
		if (IsValid(PreviousPawn) && PreviousPawn != NewPawn && CinematicDropPawn.Get() == PreviousPawn)
		{
			// Restore the prop to the original carrier before their cinematic is interrupted.
			FAttachment Hand;
			if (RestoreReleaseAttachment(*PreviousPawn)
				|| (FindAttachment(*PreviousPawn, false, Hand) && AttachToy(*ToyActor, Hand, ToyBaseScale)))
			{
				CinematicDropPawn.Reset();
				SetCarryState(PreviousPawn, EYIXIToyCarryState::HeldHand);
			}
		}
		return;
	}
	const bool bAttached = CarryState == EYIXIToyCarryState::HeldHand || CarryState == EYIXIToyCarryState::AttachedAtWaist;
	if (!bEndingPlay && bAttached && GetToyActor() && (!CarrierPawn.IsValid() || CarrierPawn.Get() != NewPawn))
	{
		ToyActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		CarrierPawn.Reset();
		SetCarryState(NewPawn, EYIXIToyCarryState::Dropped);
	}
}

void UYIXIToyCarryComponent::HandleToyDestroyed(AActor* DestroyedActor)
{
	if (!bEndingPlay && ToyActor.Get() == DestroyedActor)
	{
		SetComponentTickEnabled(false);
		CinematicDropPawn.Reset();
		ToyActor = nullptr;
		CarrierPawn.Reset();
		SetCarryState(GetControlledPawn(), EYIXIToyCarryState::Grounded);
	}
}
