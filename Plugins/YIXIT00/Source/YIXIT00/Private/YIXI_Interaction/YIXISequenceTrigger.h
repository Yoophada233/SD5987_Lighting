#pragma once

#include "YIXI_Interaction/ScriptedProjectile/YIXIStoryTriggerBox.h"
#include "MovieSceneSequencePlaybackSettings.h"
#include "YIXISequenceTrigger.generated.h"

class ALevelSequenceActor;
class ULevelSequence;
class ULevelSequencePlayer;

/** Plays a Level Sequence when the local player's possessed pawn enters TriggerBox. */
UCLASS(Blueprintable)
class AYIXISequenceTrigger : public AYIXIStoryTriggerBox
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sequence Trigger",
		meta = (ToolTip = "Allow this box and Play Sequence to start playback."))
	bool bEnabled = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sequence Trigger",
		meta = (EditCondition = "UsesSequenceAsset()", HideEditConditionToggle,
			ToolTip = "Sequence played using its authored bindings. Ignored when Existing Sequence Actor is assigned."))
	TObjectPtr<ULevelSequence> SequenceAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sequence Trigger",
		meta = (ToolTip = "Loop indefinitely until Stop Sequence is called or this trigger leaves play."))
	bool bLoopPlayback = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sequence Trigger",
		meta = (ToolTip = "Allow one successful play per instance lifetime, unless Reset Trigger is called."))
	bool bTriggerOnce = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sequence Trigger",
		meta = (ClampMin = "0.01", UIMin = "0.01", ToolTip = "Positive playback speed multiplier. 1 is normal speed."))
	float PlayRate = 1.0f;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "YIXI|Sequence Trigger|Advanced",
		meta = (ToolTip = "Optional. Takes precedence over Sequence Asset and uses this actor's existing bindings and cinematic settings. Turn off Auto Play on that actor."))
	TSoftObjectPtr<ALevelSequenceActor> ExistingSequenceActor;

	/** Try to start the selected sequence under the same rules as entering the box. */
	UFUNCTION(BlueprintCallable, Category = "YIXI|Sequence Trigger")
	bool PlaySequence();

	/** Stop only playback started by this trigger. */
	UFUNCTION(BlueprintCallable, Category = "YIXI|Sequence Trigger")
	void StopSequence();

	/** Allow another activation. Does not stop playback or simulate an overlap. */
	UFUNCTION(BlueprintCallable, Category = "YIXI|Sequence Trigger")
	void ResetTrigger();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

private:
	UFUNCTION()
	bool UsesSequenceAsset() const { return ExistingSequenceActor.IsNull(); }

	UFUNCTION()
	void HandlePlayerEntered(APawn* Pawn);

	UFUNCTION()
	void HandlePlaybackStarted();

	UFUNCTION()
	void ClearPlayback();

	ALevelSequenceActor* GetOrCreatePlaybackActor();
	void WarnAutoPlay(const ALevelSequenceActor& Actor) const;

	UPROPERTY(Transient)
	TObjectPtr<ALevelSequenceActor> OwnedSequenceActor;

	TWeakObjectPtr<ULevelSequencePlayer> ActivePlayer;
	FMovieSceneSequencePlaybackSettings PreviousSettings;
	bool bHasTriggered = false;
	bool bEndingPlay = false;
};
