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
}

UYIXIToyCarryComponent::UYIXIToyCarryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
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
	UWorld* World = GetWorld();
	if (bEndingPlay || CarryState != EYIXIToyCarryState::HeldHand || !World || !IsValid(Pawn)
		|| CarrierPawn.Get() != Pawn || !GetToyActor())
	{
		return false;
	}

	const UStaticMesh* Mesh = ToyActor->GetStaticMeshComponent()->GetStaticMesh();
	if (!Mesh)
	{
		return false;
	}

	const FBoxSphereBounds Bounds = Mesh->GetBounds();
	const FQuat DropRotation = FRotator(0.0, Pawn->GetActorRotation().Yaw, 0.0).Quaternion();
	const FVector BoundsOffset = DropRotation.RotateVector(Bounds.Origin * ToyActor->GetActorScale3D());
	const FVector DropCenter = Pawn->GetActorLocation() + DropRotation.RotateVector(DropOffset) + BoundsOffset;
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
	return TryDropAt(FTransform(DropRotation, DropLocation));
}

bool UYIXIToyCarryComponent::TryDropAt(const FTransform& WorldPose)
{
	APawn* Pawn = GetControlledPawn();
	UWorld* World = GetWorld();
	if (bEndingPlay || CarryState != EYIXIToyCarryState::HeldHand || !World || !IsValid(Pawn)
		|| CarrierPawn.Get() != Pawn || !GetToyActor() || !WorldPose.IsValid())
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
	const FCollisionQueryParams Query = MakeDropQuery(*Pawn, *ToyActor);
	if (World->OverlapBlockingTestByChannel(DropCenter, Rotation, DropTraceChannel, Shape, Query)
		|| World->SweepTestByChannel(CurrentCenter, DropCenter, Rotation, DropTraceChannel, Shape, Query))
	{
		return false;
	}

	// Check placement and move before detaching so rejects leave the hand attachment intact.
	if (!ToyActor->SetActorLocationAndRotation(WorldPose.GetLocation(), Rotation, false, nullptr, ETeleportType::TeleportPhysics))
	{
		return false;
	}

	ToyActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	CarrierPawn.Reset();
	SetCarryState(Pawn, EYIXIToyCarryState::Dropped);
	return true;
}

bool UYIXIToyCarryComponent::TryAttachToWaist()
{
	APawn* Pawn = GetControlledPawn();
	if (bEndingPlay || CarryState != EYIXIToyCarryState::Dropped
		|| !IsValid(Pawn) || !Pawn->IsPlayerControlled() || Pawn->GetWorld() != GetWorld() || !GetToyActor())
	{
		return false;
	}

	FAttachment Attachment;
	if (!FindAttachment(*Pawn, true, Attachment) || !AttachToy(*ToyActor, Attachment, ToyBaseScale))
	{
		return false;
	}

	CarrierPawn = Pawn;
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
		ToyActor = nullptr;
		CarrierPawn.Reset();
		SetCarryState(GetControlledPawn(), EYIXIToyCarryState::Grounded);
	}
}
