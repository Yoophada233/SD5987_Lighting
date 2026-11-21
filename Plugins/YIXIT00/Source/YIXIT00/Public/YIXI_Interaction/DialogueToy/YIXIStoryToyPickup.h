#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXI_Interaction/YIXIInteractable.h"
#include "YIXIStoryToyPickup.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UYIXIToyCarryComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FYIXIToyPickedUp, APawn*, PickingPawn);

UCLASS(Blueprintable)
class YIXIT00_API AYIXIStoryToyPickup : public AActor, public IYIXIInteractable
{
	GENERATED_BODY()

public:
	AYIXIStoryToyPickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Story|Components")
	TObjectPtr<UStaticMeshComponent> ToyMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Story|Components")
	TObjectPtr<USceneComponent> InteractionAnchor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Interaction", meta = (ClampMin = "0", Units = "cm"))
	float DetectionRange = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Interaction", meta = (ClampMin = "0", Units = "cm"))
	float InteractRange = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Interaction")
	bool bStartPickupAvailable = false;

	UPROPERTY(BlueprintAssignable, Category = "Story|Interaction")
	FYIXIToyPickedUp OnToyPickedUp;

	UFUNCTION(BlueprintCallable, Category = "Story|Interaction")
	void SetPickupAvailable(bool bAvailable);

	virtual bool CanInteract_Implementation(APawn* Interactor) const override;
	virtual void Interact_Implementation(APawn* Interactor) override;
	virtual FYIXIInteractionPrompt GetInteractionPrompt_Implementation(APawn* Interactor) const override;

protected:
	virtual void BeginPlay() override;

private:
	friend class UYIXIToyCarryComponent;

	bool IsPickupAvailable() const;
	void CommitPickup();

	UPROPERTY(VisibleInstanceOnly, Category = "Story|Interaction")
	bool bPickupAvailable = false;

	UPROPERTY(VisibleInstanceOnly, Category = "Story|Interaction")
	bool bClaimed = false;
	bool bPickupGateSet = false;
};
