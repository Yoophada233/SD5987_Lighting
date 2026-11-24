#pragma once

#include "Components/ActorComponent.h"
#include "Components/SlateWrapperTypes.h"
#include "YIXIFirstRockTitleComponent.generated.h"

class APlayerController;
class AYIXIScriptedRock;
class APawn;
class SYIXIFirstRockTitleLayer;
class UGameViewportClient;
class UInputComponent;
class UMoverComponent;
class UTexture2D;
class UYIXIInteractionHUDWidget;
class UYIXIInteractorComponent;

/** Plays the opening title once, on the actual impact of the configured rock. */
UCLASS(ClassGroup = (YIXI), meta = (BlueprintSpawnableComponent, DisplayName = "YIXI First Rock Title"))
class YIXIT00_API UYIXIFirstRockTitleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UYIXIFirstRockTitleComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI | Title Card")
	bool bEnabled = true;

	/** Defaults to the owning rock when this component is installed on it. */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI | Title Card")
	TObjectPtr<AYIXIScriptedRock> FirstRockReference;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI | Title Card")
	TObjectPtr<UTexture2D> TitleTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI | Title Card | Timing", meta = (ClampMin = "0.0", Units = "s"))
	float BlackHoldBeforeTitle = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI | Title Card | Timing", meta = (ClampMin = "0.0", Units = "s"))
	float TitleFadeInDuration = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI | Title Card | Timing", meta = (ClampMin = "0.0", Units = "s"))
	float TitleHoldDuration = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI | Title Card | Timing", meta = (ClampMin = "0.0", Units = "s"))
	float CombinedFadeOutDuration = 2.0f;

	/** 1 fits the full original image inside the viewport at its original aspect ratio. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI | Title Card | Layout", meta = (ClampMin = "0.05", ClampMax = "1.0"))
	float TitleScale = 1.0f;

	/** Fraction of viewport width and height, with positive Y pointing down. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI | Title Card | Layout")
	FVector2D TitleOffset = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI | Title Card")
	bool bKnockdownOnBlackout = true;

	UFUNCTION(BlueprintCallable, Category = "YIXI | Title Card")
	void CancelTitle();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	enum class EPhase : uint8 { Inactive, Black, Reveal, Hold, FadeOut };

	UFUNCTION()
	void OnFirstRockImpact(int32 RequestId);

	void SetFrame(EPhase NewPhase, float TitleProgress, float Opacity, double Elapsed);

	TWeakObjectPtr<AYIXIScriptedRock> BoundRock;
	TWeakObjectPtr<APlayerController> Controller;
	TWeakObjectPtr<APawn> Pawn;
	TWeakObjectPtr<UMoverComponent> Mover;
	TWeakObjectPtr<UGameViewportClient> Viewport;
	TWeakObjectPtr<UYIXIInteractorComponent> SuppressedInteractor;
	TWeakObjectPtr<UYIXIInteractionHUDWidget> HiddenHUD;
	TSharedPtr<SYIXIFirstRockTitleLayer> Layer;

	UPROPERTY(Transient)
	TObjectPtr<UInputComponent> InputBlocker;

	UPROPERTY(Transient)
	TObjectPtr<UObject> MovementInputFilter;

	ESlateVisibility PreviousHUDVisibility = ESlateVisibility::Visible;
	EPhase Phase = EPhase::Inactive;
	double StartedAt = 0.0;
	uint64 StartFrame = 0;
	bool bPlayed = false;
	bool bKnockdownPending = false;
};
