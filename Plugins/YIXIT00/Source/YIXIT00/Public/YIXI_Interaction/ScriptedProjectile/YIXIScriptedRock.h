#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXIScriptedRock.generated.h"

class UAudioComponent;
class UBoxComponent;
class UCurveFloat;
class USceneComponent;
class USoundAttenuation;
class USoundBase;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EYIXIScriptedRockState : uint8
{
	Idle,
	InFlight,
	Impacted,
	WaitingForClearance,
	Blocking
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FYIXIScriptedRockEvent, int32, RequestId);

/** An authored, one-shot environment cue with optional pawn-blocking scenery. */
UCLASS(Blueprintable)
class YIXIT00_API AYIXIScriptedRock : public AActor
{
	GENERATED_BODY()

public:
	AYIXIScriptedRock();

	/** Starts this instance once. A positive request ID is echoed by its events. */
	UFUNCTION(BlueprintCallable, Category = "YIXI|Scripted Rock")
	bool Launch(int32 RequestId);

	UFUNCTION(BlueprintPure, Category = "YIXI|Scripted Rock")
	int32 GetActiveRequestId() const { return ActiveRequestId; }

	UFUNCTION(BlueprintPure, Category = "YIXI|Scripted Rock")
	bool HasImpacted() const { return bImpactOccurred; }

	UFUNCTION(BlueprintPure, Category = "YIXI|Scripted Rock")
	bool IsBlockageReady() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Scripted Rock")
	TObjectPtr<USceneComponent> StartAnchor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Scripted Rock")
	TObjectPtr<USceneComponent> ImpactAnchor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Scripted Rock")
	TObjectPtr<UStaticMeshComponent> RockMesh;

	/** Author the blockage relative to ImpactAnchor. The box stays inactive until clear. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Scripted Rock")
	TObjectPtr<UBoxComponent> Blocker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Scripted Rock",
		meta = (ClampMin = "0.05", Units = "s"))
	float TravelDuration = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Scripted Rock",
		meta = (ClampMin = "0", Units = "cm"))
	float VerticalLift = 200.0f;

	/** Optional normalized vertical shape. Use a 0–1 time axis. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Scripted Rock")
	TObjectPtr<UCurveFloat> VerticalShape;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Scripted Rock")
	bool bEnableBlockageAfterImpact = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Audio")
	TObjectPtr<USoundBase> LaunchSound;

	/** Optional moving source on the visible rock, active only during flight. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Audio")
	TObjectPtr<UAudioComponent> FlightAudio;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Audio")
	TObjectPtr<USoundBase> FlightSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Audio", meta = (ClampMin = "0"))
	float FlightVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Audio")
	TObjectPtr<USoundAttenuation> FlightAttenuation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Audio")
	TObjectPtr<UAudioComponent> ImpactAudio;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Audio")
	TObjectPtr<USoundBase> ImpactSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Audio", meta = (ClampMin = "0"))
	float ImpactVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Audio")
	TObjectPtr<USoundAttenuation> ImpactAttenuation;

	UPROPERTY(BlueprintAssignable, Category = "YIXI|Events")
	FYIXIScriptedRockEvent OnLaunched;

	UPROPERTY(BlueprintAssignable, Category = "YIXI|Events")
	FYIXIScriptedRockEvent OnImpact;

	UPROPERTY(BlueprintAssignable, Category = "YIXI|Events")
	FYIXIScriptedRockEvent OnBlockageReady;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "YIXI|Scripted Rock")
	EYIXIScriptedRockState RockState = EYIXIScriptedRockState::Idle;

protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	float EvaluateVerticalShape(float Alpha) const;
	void FinishTravel();
	void TryEnableBlockage();

	FTransform LaunchPose;
	FTransform LandingPose;
	FTransform LandingBlockerPose;
	float ElapsedTime = 0.0f;
	float ActiveDuration = 0.0f;
	float ActiveLift = 0.0f;
	int32 ActiveRequestId = 0;
	bool bImpactOccurred = false;
	bool bPendingBlockage = false;
};
