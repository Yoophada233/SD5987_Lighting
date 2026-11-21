#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXI_Interaction/YIXIInteractable.h"
#include "YIXIStoryGirl.generated.h"

class USceneComponent;
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Story|Components")
	TObjectPtr<USceneComponent> InteractionAnchor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Dialogue")
	FText RequestDialogue;

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

	virtual bool CanInteract_Implementation(APawn* Interactor) const override;
	virtual void Interact_Implementation(APawn* Interactor) override;
	virtual FYIXIInteractionPrompt GetInteractionPrompt_Implementation(APawn* Interactor) const override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleInstanceOnly, Category = "Story|Dialogue")
	EYIXIStoryGirlState RequestState = EYIXIStoryGirlState::Waiting;
	bool bRequestGateSet = false;
};
