#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXIStoryTriggerBox.generated.h"

class APawn;
class AController;
class UBoxComponent;
class UPrimitiveComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FYIXIStoryTriggerPlayerEvent, APawn*, Pawn);

/** A reusable story cue volume that reports one entry and exit per possessed player pawn. */
UCLASS(Blueprintable)
class YIXIT00_API AYIXIStoryTriggerBox : public AActor
{
	GENERATED_BODY()

public:
	AYIXIStoryTriggerBox();

	/** Recheck physical occupancy when a story stage arms after the player arrived. */
	UFUNCTION(BlueprintPure, Category = "YIXI|Story Trigger")
	bool ContainsPawn(const APawn* Pawn) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Story Trigger")
	TObjectPtr<UBoxComponent> TriggerBox;

	UPROPERTY(BlueprintAssignable, Category = "YIXI|Story Trigger")
	FYIXIStoryTriggerPlayerEvent OnPlayerEntered;

	UPROPERTY(BlueprintAssignable, Category = "YIXI|Story Trigger")
	FYIXIStoryTriggerPlayerEvent OnPlayerExited;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Sweep);

	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);

	UFUNCTION()
	void HandleControllerChanged(APawn* Pawn, AController* OldController, AController* NewController);

	UFUNCTION()
	void HandlePawnDestroyed(AActor* Actor);

	void TrackPawn(APawn* Pawn);
	void UpdatePresence(APawn* Pawn);
	void UnbindPawn(APawn& Pawn);
	void ScheduleOverlapRefresh();
	void RefreshOverlaps();

	// Track physical overlap independently from whether a player currently possesses the pawn.
	TMap<TWeakObjectPtr<APawn>, bool> TrackedPawns;
	bool bOverlapRefreshScheduled = false;
	bool bEndingPlay = false;
};
