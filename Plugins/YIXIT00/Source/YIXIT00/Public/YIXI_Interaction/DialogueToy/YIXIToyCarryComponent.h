#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "YIXIToyCarryComponent.generated.h"

class APawn;
class AStaticMeshActor;
class AYIXIStoryToyPickup;
class USceneComponent;

UENUM(BlueprintType)
enum class EYIXIToyCarryState : uint8
{
	Grounded,
	HeldHand,
	Dropped,
	AttachedAtWaist
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FYIXIToyStateChanged, APawn*, Pawn,
	EYIXIToyCarryState, PreviousState, EYIXIToyCarryState, NewState);

/** Use one carry component on the player controller to keep the toy across streamed levels. */
UCLASS(ClassGroup = (YIXI), meta = (BlueprintSpawnableComponent))
class YIXIT00_API UYIXIToyCarryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UYIXIToyCarryComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Attachment")
	FName PawnMeshComponentName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Attachment")
	FName HandSocketName = TEXT("hand_r");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Attachment")
	FName WaistSocketName = TEXT("YIXI_Toy_BackWaist");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Attachment")
	FTransform HandRelativeTransform = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Attachment")
	FTransform WaistRelativeTransform = FTransform::Identity;

	/** Opt in for a whitebox pawn before authored sockets exist. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Attachment")
	bool bAllowRootAttachmentFallback = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Attachment",
		meta = (EditCondition = "bAllowRootAttachmentFallback"))
	FTransform FallbackHandRelativeTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Attachment",
		meta = (EditCondition = "bAllowRootAttachmentFallback"))
	FTransform FallbackWaistRelativeTransform;

	/** Centimeters in the controlled pawn's yaw frame. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Drop")
	FVector DropOffset = FVector(85.0, 0.0, -20.0);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Drop",
		meta = (ClampMin = "1", Units = "cm"))
	float DropGroundSearchDistance = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Toy|Drop")
	TEnumAsByte<ECollisionChannel> DropTraceChannel = ECC_Visibility;

	UPROPERTY(BlueprintAssignable, Category = "Toy")
	FYIXIToyStateChanged OnToyStateChanged;

	UFUNCTION(BlueprintPure, Category = "Toy")
	static UYIXIToyCarryComponent* FindForPawn(APawn* Pawn);

	UFUNCTION(BlueprintPure, Category = "Toy")
	EYIXIToyCarryState GetCarryState() const { return CarryState; }

	UFUNCTION(BlueprintPure, Category = "Toy")
	AActor* GetToyActor() const;

	/** Snap the toy to clear ground near its current carrier. */
	UFUNCTION(BlueprintCallable, Category = "Toy")
	bool TryDrop();

	/** Use an authored world location and rotation if the pose and path are clear. */
	UFUNCTION(BlueprintCallable, Category = "Toy")
	bool TryDropAt(const FTransform& WorldPose);

	UFUNCTION(BlueprintCallable, Category = "Toy")
	bool TryAttachToWaist();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	friend class AYIXIStoryToyPickup;

	struct FAttachment
	{
		USceneComponent* Parent = nullptr;
		FName Socket;
		FTransform RelativePose;
	};

	APawn* GetControlledPawn() const;
	bool CanTakeToy(APawn* Pawn) const;
	bool TryPickup(APawn* Pawn, AYIXIStoryToyPickup& Pickup);
	bool FindAttachment(APawn& Pawn, bool bWaist, FAttachment& OutAttachment) const;
	bool AttachToy(AStaticMeshActor& Actor, const FAttachment& Attachment, const FVector& BaseScale) const;
	void SetCarryState(APawn* Pawn, EYIXIToyCarryState NewState);

	UFUNCTION()
	void HandlePawnChanged(APawn* PreviousPawn, APawn* NewPawn);

	UFUNCTION()
	void HandleToyDestroyed(AActor* DestroyedActor);

	UPROPERTY(VisibleInstanceOnly, Category = "Toy")
	EYIXIToyCarryState CarryState = EYIXIToyCarryState::Grounded;

	UPROPERTY(Transient)
	TObjectPtr<AStaticMeshActor> ToyActor;

	TWeakObjectPtr<APawn> CarrierPawn;
	FVector ToyBaseScale = FVector::OneVector;
	bool bEndingPlay = false;
};
