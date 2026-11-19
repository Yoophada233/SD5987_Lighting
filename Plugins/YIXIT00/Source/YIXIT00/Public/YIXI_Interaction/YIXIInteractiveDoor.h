#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXI_Interaction/YIXIInteractable.h"
#include "YIXIInteractiveDoor.generated.h"

class UCurveFloat;
class USceneComponent;
class USoundAttenuation;
class USoundBase;
class USphereComponent;
class UStaticMesh;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EYIXIDoorState : uint8
{
	Closed,
	Opening,
	Open,
	Closing
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FYIXIDoorEvent);

UCLASS(Blueprintable)
class YIXIT00_API AYIXIInteractiveDoor : public AActor, public IYIXIInteractable
{
	GENERATED_BODY()

public:
	AYIXIInteractiveDoor();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaSeconds) override;

	virtual bool CanInteract_Implementation(APawn* Interactor) const override;
	virtual void Interact_Implementation(APawn* Interactor) override;
	virtual FYIXIInteractionPrompt GetInteractionPrompt_Implementation(APawn* Interactor) const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<USceneComponent> DoorRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<UStaticMeshComponent> DoorFrame;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<USceneComponent> HingePivot;

	/** Unscaled mounting point for both the leaf mesh and the handle. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<USceneComponent> LeafMount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<UStaticMeshComponent> DoorLeaf;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<USceneComponent> HandleMarker;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<USceneComponent> SoundOrigin;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Components")
	TObjectPtr<USphereComponent> DetectionPreview;

	/** The basic Cube uses a whitebox lintel and jambs. Any other mesh replaces that assembly. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Structure")
	TObjectPtr<UStaticMesh> DoorFrameMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Structure")
	TObjectPtr<UStaticMesh> DoorLeafMesh;

	/** Placement of an authored frame mesh relative to the root. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Structure", meta = (MakeEditWidget))
	FVector FrameMeshOffset = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Structure")
	FVector FrameMeshScale = FVector::OneVector;

	/** Hinge position in door actor space, in centimeters. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Structure", meta = (MakeEditWidget))
	FVector HingePivotOffset = FVector(-50.0, 0.0, 0.0);

	/** Leaf mesh mounting point relative to the hinge. Flip X when moving the hinge to the right. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Structure")
	FVector LeafCenterOffset = FVector(50.0, 0.0, 105.0);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Structure")
	FVector LeafMeshScale = FVector(1.0, 0.06, 2.1);

	/** Handle location relative to the unscaled leaf mounting point. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Structure")
	FVector HandleMarkerOffset = FVector(42.0, -10.0, -5.0);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Structure")
	FRotator ClosedRotation = FRotator::ZeroRotator;

	/** Signed rotation from ClosedRotation about the actor's local Z axis. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Structure", meta = (ClampMin = "-180", ClampMax = "180", Units = "deg"))
	float OpenAngleDegrees = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion")
	bool bStartOpened = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion")
	bool bCanClose = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion", meta = (ClampMin = "0.05", Units = "s"))
	float OpenDuration = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion", meta = (ClampMin = "0.05", Units = "s"))
	float CloseDuration = 2.0f;

	/** Optional ease curve sampled over 0–1. An empty or flat curve uses smoothstep. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion")
	TObjectPtr<UCurveFloat> OpenEaseCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion")
	TObjectPtr<UCurveFloat> CloseEaseCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Motion")
	bool bAllowMidMotionReverse = false;

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Interaction", meta = (ClampMin = "0", Units = "cm"))
	float DetectionRange = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Interaction", meta = (ClampMin = "0", Units = "cm"))
	float InteractRange = 150.0f;

	/** Additional UI anchor offset in handle marker space, in centimeters. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Interaction")
	FVector PromptAnchorOffset = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Interaction")
	bool bShowHUDPrompt = true;

	/** When disabled, one open/close cycle is allowed. A door that starts open can close once. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door|Interaction")
	bool bAllowRepeat = true;

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
	void ApplyComponentConfiguration();
	void SetDoorOpenFraction(float Fraction);
	FQuat PivotRotationAt(float Fraction) const;
	void BeginMotion(bool bOpening);
	float EvaluateEase(float Progress, const UCurveFloat* Curve) const;
	bool WouldCloseThroughPawn(float NewFraction) const;

	UPROPERTY()
	TObjectPtr<UStaticMesh> WhiteboxCube;

	UPROPERTY()
	TObjectPtr<UStaticMeshComponent> WhiteboxLeftJamb;

	UPROPERTY()
	TObjectPtr<UStaticMeshComponent> WhiteboxRightJamb;

	float MotionStartFraction = 0.0f;
	float MotionElapsed = 0.0f;
	float MotionDuration = 0.0f;
	bool bCompletedCycle = false;
};
