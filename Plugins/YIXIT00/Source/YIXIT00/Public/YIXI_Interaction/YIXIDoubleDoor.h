#pragma once

#include "CoreMinimal.h"
#include "YIXI_Interaction/YIXIInteractiveDoor.h"
#include "YIXIDoubleDoor.generated.h"

class UCurveFloat;
class USceneComponent;
class USoundAttenuation;
class USoundBase;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class YIXIT00_API AYIXIDoubleDoor : public AActor, public IYIXIInteractable
{
	GENERATED_BODY()

public:
	AYIXIDoubleDoor();

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaSeconds) override;
	virtual bool CanInteract_Implementation(APawn* Interactor) const override;
	virtual void Interact_Implementation(APawn* Interactor) override;
	virtual FYIXIInteractionPrompt GetInteractionPrompt_Implementation(APawn* Interactor) const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<USceneComponent> DoorFrameRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<UStaticMeshComponent> DoorFrame;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<USceneComponent> LeftHinge;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<USceneComponent> RightHinge;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<UStaticMeshComponent> LeftLeaf;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<UStaticMeshComponent> RightLeaf;

	/** The prompt stays in the frame's coordinate space while either leaf rotates. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Interaction")
	TObjectPtr<USceneComponent> CenterInteractionAnchor;

	/** Editable adjustment to the fixed center of the frame. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Interaction")
	TObjectPtr<USceneComponent> InteractionAnchor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<USceneComponent> SoundOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Frame")
	TObjectPtr<UStaticMesh> DoorFrameMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Frame")
	FTransform DoorFrameTransform = FTransform(FQuat::Identity, FVector(0.0, 0.0, 255.0), FVector(3.2, 0.20, 0.10));

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Left")
	TObjectPtr<UStaticMesh> LeftDoorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Left", meta = (MakeEditWidget))
	FVector LeftHingeOffset = FVector(-150.0, 0.0, 0.0);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Left")
	FTransform LeftLeafTransform = FTransform(FQuat::Identity, FVector(75.0, 0.0, 125.0), FVector(1.5, 0.08, 2.5));

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Left")
	FRotator LeftClosedRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Left", meta = (ClampMin = "-180", ClampMax = "180", Units = "deg"))
	float LeftOpenAngle = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Right")
	TObjectPtr<UStaticMesh> RightDoorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Right", meta = (MakeEditWidget))
	FVector RightHingeOffset = FVector(150.0, 0.0, 0.0);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Right")
	FTransform RightLeafTransform = FTransform(FQuat::Identity, FVector(-75.0, 0.0, 125.0), FVector(1.5, 0.08, 2.5));

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Right")
	FRotator RightClosedRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Right", meta = (ClampMin = "-180", ClampMax = "180", Units = "deg"))
	float RightOpenAngle = -90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion")
	bool bStartOpened = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion")
	bool bCanClose = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion")
	bool bAllowReverseDuringAnimation = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion", meta = (ClampMin = "0.05", Units = "s"))
	float OpenDuration = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion", meta = (ClampMin = "0.05", Units = "s"))
	float CloseDuration = 2.0f;

	/** Optional curve normalized between its values at 0 and 1. Defaults to smoothstep. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion")
	TObjectPtr<UCurveFloat> OpeningCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion")
	TObjectPtr<UCurveFloat> ClosingCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Interaction", meta = (MakeEditWidget))
	FVector CenterInteractionAnchorOffset = FVector(0.0, 0.0, 110.0);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Interaction", meta = (ClampMin = "0", Units = "cm"))
	float DetectionRange = 350.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Interaction", meta = (ClampMin = "0", Units = "cm"))
	float InteractRange = 175.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Interaction")
	bool bShowHUDPrompt = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Audio")
	TObjectPtr<USoundBase> OpenSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Audio")
	TObjectPtr<USoundBase> CloseSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Audio")
	bool bEnableOpenSound = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Audio")
	bool bEnableCloseSound = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Audio", meta = (ClampMin = "0"))
	float OpenSoundVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Audio", meta = (ClampMin = "0"))
	float CloseSoundVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Audio")
	TObjectPtr<USoundAttenuation> SoundAttenuation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Audio", meta = (MakeEditWidget))
	FVector SoundOriginOffset = FVector(0.0, 0.0, 110.0);

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Door|Runtime")
	EYIXIDoorState DoorState = EYIXIDoorState::Closed;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Door|Runtime")
	float OpenFraction = 0.0f;

	UPROPERTY(BlueprintAssignable, Category = "Door|Events")
	FYIXIDoorEvent OnDoorOpenStarted;

	UPROPERTY(BlueprintAssignable, Category = "Door|Events")
	FYIXIDoorEvent OnDoorOpened;

	UPROPERTY(BlueprintAssignable, Category = "Door|Events")
	FYIXIDoorEvent OnDoorCloseStarted;

	UPROPERTY(BlueprintAssignable, Category = "Door|Events")
	FYIXIDoorEvent OnDoorClosed;

protected:
	virtual void BeginPlay() override;

private:
	void ApplyConfiguration();
	void ResetMotion();
	void SetOpenFraction(float Fraction);
	void BeginMotion(bool bOpening);
	bool WouldCloseLeafThroughPawn(const USceneComponent& Hinge, const UStaticMeshComponent& Leaf,
		const FRotator& ClosedRotation, float OpenAngle, float NewFraction) const;

	float MotionStartFraction = 0.0f;
	float MotionElapsed = 0.0f;
	float MotionDuration = 0.0f;
};
