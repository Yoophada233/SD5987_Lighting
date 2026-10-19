#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraTypes.h"
#include "YIXIT01FocusRig.generated.h"

class USphereComponent;
class UCurveFloat;
class APawn;

// One reusable, non-blocking configuration Actor; no GASP asset dependencies.
UCLASS(Blueprintable)
class YIXIT00_API AYIXIT01FocusRig : public AActor
{
    GENERATED_BODY()
public:
    AYIXIT01FocusRig();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="T01|Interaction")
    TObjectPtr<USphereComponent> InteractionArea;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="T01|Interaction")
    FText InteractionPrompt = FText::FromString(TEXT("F · 观察"));
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="T01|Interaction")
    FText ObservationPrompt = FText::FromString(TEXT("F · 继续    Esc · 返回"));

    // Soft references permit references across traditional streaming levels.
    // Empty camera references reuse the T00 tagged Camera_A / Camera_B.
    UPROPERTY(EditInstanceOnly, Category="T01|References") TSoftObjectPtr<ACameraActor> DayCloseupCamera;
    UPROPERTY(EditInstanceOnly, Category="T01|References") TSoftObjectPtr<ACameraActor> NightCloseupCamera;
    UPROPERTY(EditInstanceOnly, Category="T01|References") TSoftObjectPtr<AActor> ObservationTarget;
    UPROPERTY(EditAnywhere, Category="T01|References") FName ObservationTargetTag = TEXT("T00_BodyA");
    UPROPERTY(EditAnywhere, Category="T01|References", meta=(MakeEditWidget=true))
    FVector TargetLocalOffset = FVector(0, 0, 12);

    UPROPERTY(EditAnywhere, Category="T01|Motion", meta=(ClampMin="0.1", Units="s")) float EnterSeconds = 2.f;
    UPROPERTY(EditAnywhere, Category="T01|Motion", meta=(ClampMin="0.1", Units="s")) float ReturnSeconds = 1.5f;
    UPROPERTY(EditAnywhere, Category="T01|Motion", meta=(ClampMin="0.05", Units="s")) float HandoffSeconds = .18f;
    UPROPERTY(EditAnywhere, Category="T01|Motion") bool bShoulderRelativeToInitialView = true;
    // View-relative mode: X forward, Y right, Z up from the captured camera.
    UPROPERTY(EditAnywhere, Category="T01|Motion", meta=(EditCondition="bShoulderRelativeToInitialView"))
    FVector ShoulderViewOffset = FVector(220, 100, 40);
    // World-control mode: an editable gizmo relative to this Rig Actor.
    UPROPERTY(EditAnywhere, Category="T01|Motion", meta=(MakeEditWidget=true, EditCondition="!bShoulderRelativeToInitialView"))
    FVector ShoulderControlLocal = FVector(-450, 80, 80);
    UPROPERTY(EditAnywhere, Category="T01|Motion") FVector NightReturnArcOffset = FVector(0, 90, 70);
    // Optional monotonic 0..1 easing curve; null uses cubic Ease In/Out.
    UPROPERTY(EditAnywhere, Category="T01|Motion") TObjectPtr<UCurveFloat> EaseCurve;

    UPROPERTY(EditAnywhere, Category="T01|Path Safety", meta=(ClampMin="1.0", Units="cm")) float CameraProbeRadius = 8.f;
    UPROPERTY(EditAnywhere, Category="T01|Path Safety", meta=(ClampMin="1.0", Units="cm")) float HeadAvoidanceRadius = 18.f;
    UPROPERTY(EditAnywhere, Category="T01|Path Safety", meta=(ClampMin="16", ClampMax="128")) int32 PathSamples = 48;

    bool ContainsPawn(const APawn* Pawn) const;
    bool Validate(FString& Reason) const;
    float Ease(float Time) const;
    FVector ControlPoint(const FMinimalViewInfo& Start) const;
    AActor* ResolveTarget(FString& Reason) const;
};

// Runtime-owned view proxy: preserve the captured FMinimalViewInfo, including
// FOV/aspect/projection/post-process, rather than constructing a default camera.
UCLASS(Transient)
class YIXIT00_API UYIXIT01ViewComponent : public UCameraComponent
{
    GENERATED_BODY()
public:
    virtual void GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView) override;
};

UCLASS(NotPlaceable, Transient)
class YIXIT00_API AYIXIT01ViewCamera : public ACameraActor
{
    GENERATED_BODY()
public:
    AYIXIT01ViewCamera(const FObjectInitializer& ObjectInitializer);
    FMinimalViewInfo View;
    virtual void CalcCamera(float DeltaTime, FMinimalViewInfo& OutResult) override { OutResult = View; }
};
