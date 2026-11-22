#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXI_Interaction/YIXIInteractable.h"
#include "YIXIStoryGirl.generated.h"

class UAudioComponent;
class USceneComponent;
class USkeletalMeshComponent;
class USoundAttenuation;
class USoundBase;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EYIXIStoryGirlState : uint8
{
	Waiting,
	RequestReady,
	Requested,
	Unavailable
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice")
	TObjectPtr<USoundBase> RequestVoice;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice")
	TObjectPtr<USoundBase> ReminderVoice;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice", meta = (ClampMin = "0"))
	float VoiceVolume = 1.0f;

	/** When empty, the voice uses the component's default spatial attenuation. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Voice")
	TObjectPtr<USoundAttenuation> VoiceAttenuation;

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

	/** Stops speech and its reminder subtitle without changing the story state. */
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
	void PlayVoice(USoundBase* Sound);

	UPROPERTY(VisibleInstanceOnly, Category = "Story|Dialogue")
	EYIXIStoryGirlState RequestState = EYIXIStoryGirlState::Waiting;
	bool bRequestGateSet = false;
};
