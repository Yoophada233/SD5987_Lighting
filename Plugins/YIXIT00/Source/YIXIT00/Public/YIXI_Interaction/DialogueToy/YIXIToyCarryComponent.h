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
	AttachedAtWaist,
	Falling
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

	/** Project an authored position onto clear ground using the held toy's bounds and rotation. */
	UFUNCTION(BlueprintCallable, Category = "Toy|Cinematic")
	bool FindCinematicDropPose(const FTransform& GroundAnchor, FTransform& OutPose) const;

	bool FindVerticalCinematicLanding(FTransform& OutPose) const;

	/** Sequencer supplies the monotonic progress. The component does not tick this drop. */
	bool BeginSequencedVerticalDrop(const FTransform& LandingPose, float Duration);
	bool ApplySequencedDropProgress(float Alpha);

	/** Release the real hand prop and move it over game time to a validated landing pose. */
	UFUNCTION(BlueprintCallable, Category = "Toy|Cinematic")
	bool BeginCinematicDrop(const FTransform& LandingPose, float Duration);

	/** Commit the remaining descent immediately, for an explicit cinematic skip. */
	UFUNCTION(BlueprintCallable, Category = "Toy|Cinematic")
	bool FinishCinematicDrop();

	/** Recover an interrupted cinematic drop for its original, still-possessed carrier. */
	UFUNCTION(BlueprintCallable, Category = "Toy|Cinematic")
	bool RestoreToyToHand();

	UFUNCTION(BlueprintPure, Category = "Toy")
	bool CanAttachToWaist() const;

	UFUNCTION(BlueprintCallable, Category = "Toy")
	bool TryAttachToWaist();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

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
	bool IsDropPathClear(const APawn& Pawn, const FTransform& WorldPose) const;
	bool ProjectBelowToy(const APawn& Pawn, const FTransform& ReleasePose, FTransform& OutPose) const;
	bool StartVerticalDrop(const FTransform& LandingPose, float Duration, bool bFromSequence);
	bool MoveVerticalDrop(float Alpha);
	bool RestoreReleaseAttachment(APawn& Pawn);
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
	TWeakObjectPtr<APawn> CinematicDropPawn;
	TWeakObjectPtr<USceneComponent> ReleaseParent;
	FName ReleaseSocket;
	FTransform ReleaseRelativePose;
	bool bSequenceControlsDrop = false;
	float DropProgress = 0.0f;
	FTransform DropStartPose;
	FTransform DropEndPose;
	float DropDuration = 0.0f;
	float DropElapsed = 0.0f;
	FVector ToyBaseScale = FVector::OneVector;
	bool bEndingPlay = false;
};
