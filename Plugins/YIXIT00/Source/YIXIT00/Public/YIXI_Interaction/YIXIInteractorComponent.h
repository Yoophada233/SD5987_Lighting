#pragma once

#include "Components/ActorComponent.h"
#include "InputCoreTypes.h"
#include "YIXI_Interaction/YIXIInteractionHUDWidget.h"
#include "YIXIInteractorComponent.generated.h"

class APlayerController;
class APawn;
class UEnhancedInputComponent;
class UEnhancedInputLocalPlayerSubsystem;
class UInputAction;
class UInputMappingContext;

/** Add to a player controller or its possessed pawn. The controller component takes precedence. */
UCLASS(ClassGroup = (YIXI), meta = (BlueprintSpawnableComponent))
class YIXIT00_API UYIXIInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UYIXIInteractorComponent();

	/** Finds the same non-interactive HUD already used by the local controller's interaction component. */
	static UYIXIInteractionHUDWidget* FindDialogueHUD(APlayerController& Controller);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction|Input")
	FKey InteractionKey = EKeys::E;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction|Input")
	bool bBindInteractionKey = true;

	/** Reserve this key against lower-priority mappings only in contexts where that is intended. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction|Input", meta = (EditCondition = "bBindInteractionKey"))
	bool bConsumeInteractionInput = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction|Input", meta = (EditCondition = "bBindInteractionKey"))
	int32 InteractionMappingPriority = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction|HUD")
	TSubclassOf<UYIXIInteractionHUDWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Targeting", meta = (ClampMin = "1.0", ClampMax = "89.0", Units = "deg"))
	float ViewConeHalfAngle = 60.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Targeting", meta = (ClampMin = "0.0", Units = "cm"))
	float DistanceHysteresisCm = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Targeting", meta = (ClampMin = "0.02", Units = "s"))
	float TargetScanInterval = 0.08f;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "Interaction|State")
	TObjectPtr<AActor> CurrentTarget;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "Interaction|State")
	EYIXIInteractionPromptState PromptState = EYIXIInteractionPromptState::Hidden;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "Interaction|State")
	FText CurrentActionText;

	/** Call from an existing Enhanced Input Started event with automatic binding disabled. */
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	bool RequestInteract();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void SetInteractionKeyBindingEnabled(bool bEnabled);

	/** Temporarily suspend both targeting and dispatch while a presentation owns the local view. */
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void SetCinematicSuppressed(bool bSuppressed);

	UFUNCTION(BlueprintPure, Category = "Interaction")
	bool IsCinematicSuppressed() const { return bCinematicSuppressed; }

protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	struct FView;
	struct FTarget;

	APlayerController* ResolveLocalController() const;
	void EnsureHUD(APlayerController& Controller);
	void EnsureInput(APlayerController& Controller);
	void RemoveInput();
	void ResetLocalPlayer();
	void OnInteractionPressed();
	void RefreshCandidates();
	bool BuildView(APlayerController& Controller, FView& OutView) const;
	bool EvaluateTarget(AActor* Actor, APawn& Pawn, const FView& View, FTarget& OutTarget) const;
	void ApplyTarget(const FTarget& Target, float DeltaTime);

	UPROPERTY(Transient)
	TObjectPtr<UYIXIInteractionHUDWidget> HUDWidget;

	UPROPERTY(Transient)
	TObjectPtr<UEnhancedInputComponent> InteractionInputComponent;

	UPROPERTY(Transient)
	TObjectPtr<UInputAction> InteractionAction;

	UPROPERTY(Transient)
	TObjectPtr<UInputMappingContext> InteractionMapping;

	TWeakObjectPtr<APlayerController> ActiveController;
	TWeakObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputSubsystem;
	TArray<TWeakObjectPtr<AActor>> Candidates;
	float TimeUntilCandidateRefresh = 0.0f;
	float TimeUntilScan = 0.0f;
	uint64 LastRequestFrame = MAX_uint64;
	bool bCinematicSuppressed = false;
};
