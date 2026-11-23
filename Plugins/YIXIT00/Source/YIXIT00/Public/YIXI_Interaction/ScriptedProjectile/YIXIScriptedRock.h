#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXIScriptedRock.generated.h"

class ADecalActor;
class ATargetPoint;
class UAudioComponent;
class UBoxComponent;
class UCurveFloat;
class UDecalComponent;
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

	/** Cancels flight or clears a previous impact when the owning story is reset. */
	UFUNCTION(BlueprintCallable, Category = "YIXI|Scripted Rock")
	void ResetRock();

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

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Scripted Rock|Markers")
	TObjectPtr<ATargetPoint> FlightStartMarker;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Scripted Rock|Markers")
	TObjectPtr<ATargetPoint> FlightImpactMarker;

	/** World-space offset from the assigned start marker to the trajectory pivot. */
	UPROPERTY(EditInstanceOnly, Category = "YIXI|Scripted Rock|Markers", meta = (Units = "cm"))
	FVector StartMarkerOffset = FVector::ZeroVector;

	/** World-space offset from the assigned impact marker to the trajectory pivot. */
	UPROPERTY(EditInstanceOnly, Category = "YIXI|Scripted Rock|Markers", meta = (Units = "cm"))
	FVector ImpactMarkerOffset = FVector::ZeroVector;

	/** Edit this component's mesh, materials and transform. Its local alignment follows the trajectory. */
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

	/** Pick the existing crack decal at this rock's landing site. It stays visible in the editor. */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Scripted Rock|Impact")
	TObjectPtr<ADecalActor> ImpactDecal;

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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	float EvaluateVerticalShape(float Alpha) const;
	FTransform MakeRockMeshPose(const FVector& PathLocation, const FQuat& PathRotation) const;
	UDecalComponent* GetImpactDecalComponent() const;
	void SetImpactDecalHidden(bool bInHidden);
	void FinishTravel();
	void TryEnableBlockage();

	FTransform LaunchPose;
	FTransform LandingPose;
	FTransform LandingBlockerPose;
	FTransform MeshAlignment;
	FTransform RestMeshTransform;
	FTransform RestBlockerTransform;
	float ElapsedTime = 0.0f;
	float ActiveDuration = 0.0f;
	float ActiveLift = 0.0f;
	int32 ActiveRequestId = 0;
	bool bImpactOccurred = false;
	bool bPendingBlockage = false;
};
