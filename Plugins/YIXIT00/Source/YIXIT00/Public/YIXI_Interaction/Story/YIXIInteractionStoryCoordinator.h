#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "YIXIInteractionStoryCoordinator.generated.h"

class APawn;
class AYIXIAudioTriggerBox;
class AYIXIDoubleDoor;
class AYIXIScriptedRock;
class AYIXIStoryGirl;
class AYIXIStoryToyPickup;
class AYIXIStoryTriggerBox;

UENUM(BlueprintType)
enum class EYIXIInteractionStoryStage : uint8
{
	WaitingForDoor,
	Corridor,
	RoadCuePending,
	RoadCueInFlight,
	Bypass,
	GirlRequest,
	ToyPickup,
	Return,
	AttackCueInFlight,
	Discovery,
	MatchCut,
	Completed,
	Stopped
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FYIXIInteractionStoryStageChanged, EYIXIInteractionStoryStage, Stage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FYIXIInteractionStoryDialogue, APawn*, Pawn, FText, Line);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FYIXIInteractionMatchCutRequested, int32, RequestId, APawn*, Pawn, AActor*, DroppedToy);

/** Wires one local player's authored interaction sequence. Assign actors in an isolated level. */
UCLASS(Blueprintable)
class YIXIT00_API AYIXIInteractionStoryCoordinator : public AActor
{
	GENERATED_BODY()

public:
	AYIXIInteractionStoryCoordinator();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Actors")
	TObjectPtr<AYIXIDoubleDoor> ClassroomDoor;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Actors")
	TObjectPtr<AYIXIAudioTriggerBox> CorridorAudio;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Actors")
	TObjectPtr<AYIXIScriptedRock> RoadRock;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Actors")
	TObjectPtr<AYIXIStoryTriggerBox> BypassTrigger;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Actors")
	TObjectPtr<AYIXIStoryGirl> Girl;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Actors")
	TObjectPtr<AYIXIStoryToyPickup> ToyPickup;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Actors")
	TObjectPtr<AYIXIStoryTriggerBox> ReturnTrigger;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Actors")
	TObjectPtr<AYIXIScriptedRock> AttackCue;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Actors")
	TObjectPtr<AYIXIStoryTriggerBox> DiscoveryTrigger;

	/** Optional whitebox aftermath prop. It is revealed on entry to DiscoveryTrigger. */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Actors")
	TObjectPtr<AActor> GirlAftermath;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Story", meta = (ClampMin = "0", Units = "s"))
	float RoadLaunchDelay = 0.65f;

	/** Explicit whitebox acknowledgment of the transition contract. No level streaming or camera change. */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story|Match Cut")
	bool bUseIsolatedMatchCutStandIn = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Story|Match Cut",
		meta = (ClampMin = "0.01", Units = "s", EditCondition = "bUseIsolatedMatchCutStandIn"))
	float StandInDelay = 0.8f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Story|Match Cut", meta = (ClampMin = "0.1", Units = "s"))
	float MatchCutTimeout = 8.0f;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Story")
	bool bShowWhiteboxDialogue = false;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "YIXI|Story")
	EYIXIInteractionStoryStage Stage = EYIXIInteractionStoryStage::WaitingForDoor;

	UPROPERTY(BlueprintAssignable, Category = "YIXI|Story")
	FYIXIInteractionStoryStageChanged OnStageChanged;

	UPROPERTY(BlueprintAssignable, Category = "YIXI|Story")
	FYIXIInteractionStoryDialogue OnDialogue;

	UPROPERTY(BlueprintAssignable, Category = "YIXI|Story|Match Cut")
	FYIXIInteractionMatchCutRequested OnMatchCutRequested;

	/** The same still-possessed pawn and request must be present before the toy is put on the waist. */
	UFUNCTION(BlueprintCallable, Category = "YIXI|Story|Match Cut")
	bool CompleteMatchCut(int32 RequestId, bool bSucceeded);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UFUNCTION()
	void HandleClassroomOpened();
	UFUNCTION()
	void HandleCorridorTriggered(APawn* Pawn);
	UFUNCTION()
	void HandleRoadBlockageReady(int32 RequestId);
	UFUNCTION()
	void HandleBypassEntered(APawn* Pawn);
	UFUNCTION()
	void HandleToyRequested(APawn* Pawn);
	UFUNCTION()
	void HandleToyPickedUp(APawn* Pawn);
	UFUNCTION()
	void HandleReturnEntered(APawn* Pawn);
	UFUNCTION()
	void HandleAttackImpact(int32 RequestId);
	UFUNCTION()
	void HandleDiscoveryEntered(APawn* Pawn);

	void CheckInitialDoorState();
	void LaunchRoadCue();
	void SetStage(EYIXIInteractionStoryStage NewStage);
	void StopStory(const TCHAR* Reason);
	bool IsLocalPlayer(const APawn* Pawn) const;
	bool IsParticipant(const APawn* Pawn) const;
	void ShowDialogue(APawn* Pawn, const FText& Line);
	void StartMatchCut(APawn* Pawn, AActor* DroppedToy);

	TWeakObjectPtr<APawn> StoryPawn;
	FTimerHandle RoadCueTimer;
	FTimerHandle MatchCutTimeoutTimer;
	FTimerHandle StandInTimer;
	int32 NextRequestId = 0;
	int32 PendingMatchCut = 0;
	bool bEndingPlay = false;
};
