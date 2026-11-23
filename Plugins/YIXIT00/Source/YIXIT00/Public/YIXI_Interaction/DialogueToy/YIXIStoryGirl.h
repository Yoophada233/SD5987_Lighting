#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/Actor.h"
#include "YIXI_Interaction/YIXIInteractable.h"
#include "YIXIStoryGirl.generated.h"

class UAudioComponent;
class APlayerController;
class USceneComponent;
class USkeletalMeshComponent;
class USoundAttenuation;
class USoundBase;
class UStaticMeshComponent;
class UYIXIInteractionHUDWidget;
enum class EAudioComponentPlayState : uint8;

UENUM(BlueprintType)
enum class EYIXIStoryGirlState : uint8
{
	Waiting,
	RequestReady,
	Requested,
	Unavailable
};

UENUM(BlueprintType)
enum class EYIXIStoryGirlDialoguePhase : uint8
{
	Idle,
	Girl,
	Gap,
	Player
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FYIXIToyRequested, APawn*, RequestingPawn);

UCLASS(Blueprintable)
class YIXIT00_API AYIXIStoryGirl : public AActor, public IYIXIInteractable
{
	GENERATED_BODY()

public:
	AYIXIStoryGirl();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Story|Components")
	TObjectPtr<UStaticMeshComponent> GirlMesh;

	/** Optional visible character. Set the mesh, local transform and animation on this component. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Story|Components")
	TObjectPtr<USkeletalMeshComponent> GirlSkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Story|Components")
	TObjectPtr<USceneComponent> InteractionAnchor;

	/** Move this audio component to place the girl's voice independently of the prompt. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Story|Voice")
	TObjectPtr<UAudioComponent> VoiceAnchor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Dialogue")
	FText RequestDialogue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Dialogue")
	FText RequestFollowUpSubtitle;

	/** Time from the start of the request voice to its optional second subtitle. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Dialogue", meta = (ClampMin = "0.0", Units = "s"))
	float RequestFollowUpSubtitleTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Dialogue")
	FText PlayerReplySubtitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Dialogue", meta = (ClampMin = "0.0", Units = "s"))
	float DialogueGap = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Dialogue")
	bool bDialogueSubtitlesEnabled = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice")
	TObjectPtr<USoundBase> RequestVoice;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice")
	TObjectPtr<USoundBase> PlayerReplyVoice;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice")
	TObjectPtr<USoundBase> ReminderVoice;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice", meta = (ClampMin = "0"))
	float VoiceVolume = 1.0f;

	/** When empty, the voice uses the component's default spatial attenuation. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice")
	TObjectPtr<USoundAttenuation> VoiceAttenuation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice", meta = (ClampMin = "0.0"))
	float PlayerVoiceVolume = 1.0f;

	/** When empty, the player uses a spatial source at the pawn's eye height. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice")
	TObjectPtr<USoundAttenuation> PlayerVoiceAttenuation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Interaction", meta = (ClampMin = "0", Units = "cm"))
	float DetectionRange = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Interaction", meta = (ClampMin = "0", Units = "cm"))
	float InteractRange = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Interaction")
	bool bStartRequestAvailable = false;

	UPROPERTY(BlueprintAssignable, Category = "Story|Dialogue")
	FYIXIToyRequested OnToyRequested;

	/** Opens or closes the request gate before its first successful use. */
	UFUNCTION(BlueprintCallable, Category = "Story|Dialogue")
	void SetRequestAvailable(bool bAvailable);

	UFUNCTION(BlueprintCallable, Category = "Story|Dialogue")
	void SetUnavailable();

	UFUNCTION(BlueprintPure, Category = "Story|Dialogue")
	FText GetRequestDialogue() const { return RequestDialogue; }

	UFUNCTION(BlueprintPure, Category = "Story|Dialogue")
	EYIXIStoryGirlState GetRequestState() const { return RequestState; }

	/** Uses the audio component's live state, including its handling of a refused playback. */
	UFUNCTION(BlueprintPure, Category = "Story|Voice")
	bool IsVoicePlaying() const;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "Story|Dialogue")
	EYIXIStoryGirlDialoguePhase DialoguePhase = EYIXIStoryGirlDialoguePhase::Idle;

	/** Stops speech without changing the story state. */
	UFUNCTION(BlueprintCallable, Category = "Story|Voice")
	void StopVoice();

	virtual bool CanInteract_Implementation(APawn* Interactor) const override;
	virtual void Interact_Implementation(APawn* Interactor) override;
	virtual FYIXIInteractionPrompt GetInteractionPrompt_Implementation(APawn* Interactor) const override;

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	bool HasAvailableDialogue() const;
	void PlayVoice(USoundBase* Sound, bool bUseHUDSubtitle = false);
	void HideReminderSubtitle(bool bImmediate);
	void StartRequestDialogue(APawn& Pawn, APlayerController& Controller);
	void StartPlayerReply(uint32 Session);
	void StartDialogueClip(UAudioComponent& Component, USoundBase& Sound, const FText& Line,
		float Volume, USoundAttenuation* Attenuation);
	bool IsDialogueValid(uint32 Session) const;
	void OnDialogueClipFinished(UAudioComponent* Component, uint32 Session, EYIXIStoryGirlDialoguePhase Phase);
	void OnDialogueClipStateChanged(const UAudioComponent* Component, EAudioComponentPlayState State, uint32 Session);
	void CheckDialoguePlayback(uint32 Session);
	void ShowRequestFollowUp(uint32 Session);
	void UnbindDialogueClip();
	void FinishDialogue(bool bCancelled, const TCHAR* Reason);

	UFUNCTION()
	void OnDialoguePawnChanged(APawn* OldPawn, APawn* NewPawn);

	UFUNCTION()
	void OnDialoguePawnEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UPROPERTY(VisibleInstanceOnly, Transient, Category = "Story|Voice")
	TObjectPtr<UAudioComponent> PlayerDialogueVoiceComponent;

	TWeakObjectPtr<APawn> DialoguePawn;
	TWeakObjectPtr<APlayerController> DialogueController;
	TWeakObjectPtr<UYIXIInteractionHUDWidget> DialogueHUD;
	TWeakObjectPtr<UYIXIInteractionHUDWidget> ReminderHUD;
	TWeakObjectPtr<UAudioComponent> DialogueClip;
	FDelegateHandle ClipFinishedHandle;
	FDelegateHandle ClipStateHandle;
	FTimerHandle DialogueGapTimer;
	FTimerHandle DialogueWatchTimer;
	FTimerHandle SubtitleCueTimer;
	FTimerHandle ReminderSubtitleTimer;
	uint32 DialogueSession = 0;
	double ClipStartedAt = 0.0;
	float ClipDuration = 0.0f;
	bool bClipPreviouslySuppressedSubtitles = false;

	UPROPERTY(VisibleInstanceOnly, Category = "Story|Dialogue")
	EYIXIStoryGirlState RequestState = EYIXIStoryGirlState::Waiting;
	bool bRequestGateSet = false;
};
