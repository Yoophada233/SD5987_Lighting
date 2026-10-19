#include "YIXIT01FocusRig.h"
#include "Components/SphereComponent.h"
#include "Curves/CurveFloat.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

AYIXIT01ViewCamera::AYIXIT01ViewCamera(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer.SetDefaultSubobjectClass<UYIXIT01ViewComponent>(TEXT("CameraComponent")))
{
}

void UYIXIT01ViewComponent::GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView)
{
    // PlayerCameraManager bypasses ACameraActor::CalcCamera and reads its
    // component directly. Both entry points must return the identical view.
    if (const auto* Proxy=Cast<AYIXIT01ViewCamera>(GetOwner())) DesiredView=Proxy->View;
    else Super::GetCameraView(DeltaTime,DesiredView);
}

AYIXIT01FocusRig::AYIXIT01FocusRig()
{
    PrimaryActorTick.bCanEverTick = false;
    InteractionArea = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionArea"));
    SetRootComponent(InteractionArea);
    InteractionArea->InitSphereRadius(300.f);
    InteractionArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    InteractionArea->SetGenerateOverlapEvents(false);
    InteractionArea->SetHiddenInGame(true);
}

bool AYIXIT01FocusRig::ContainsPawn(const APawn* Pawn) const
{
    return IsValid(Pawn) && InteractionArea
        && FVector::DistSquared(Pawn->GetActorLocation(), InteractionArea->GetComponentLocation())
            <= FMath::Square(InteractionArea->GetScaledSphereRadius());
}

bool AYIXIT01FocusRig::Validate(FString& Reason) const
{
    if (!InteractionArea || InteractionArea->GetScaledSphereRadius() <= 0
        || !FMath::IsFinite(EnterSeconds) || EnterSeconds < .1f
        || !FMath::IsFinite(ReturnSeconds) || ReturnSeconds < .1f
        || !FMath::IsFinite(HandoffSeconds) || HandoffSeconds < .05f
        || !FMath::IsFinite(CameraProbeRadius) || CameraProbeRadius < 1
        || !FMath::IsFinite(HeadAvoidanceRadius) || HeadAvoidanceRadius < 1
        || PathSamples < 16 || PathSamples > 128)
    { Reason = TEXT("Invalid interaction radius, duration or path safety settings"); return false; }
    if (EaseCurve)
    {
        float Previous = EaseCurve->GetFloatValue(0);
        if (!FMath::IsNearlyZero(Previous, .001f) || !FMath::IsNearlyEqual(EaseCurve->GetFloatValue(1), 1.f, .001f))
        { Reason = TEXT("EaseCurve must start at (0,0) and end at (1,1)"); return false; }
        for (int32 Index=1; Index<=64; ++Index)
        {
            const float Value = EaseCurve->GetFloatValue(Index/64.f);
            if (!FMath::IsFinite(Value) || Value < Previous-.0001f || Value < 0 || Value > 1)
            { Reason = TEXT("EaseCurve must be finite, monotonic and within 0..1"); return false; }
            Previous = Value;
        }
    }
    return true;
}

float AYIXIT01FocusRig::Ease(float Time) const
{
    const float A = FMath::Clamp(Time, 0.f, 1.f);
    if (A == 0 || A == 1) return A;
    return EaseCurve ? FMath::Clamp(EaseCurve->GetFloatValue(A), 0.f, 1.f) : A*A*(3.f-2.f*A);
}

FVector AYIXIT01FocusRig::ControlPoint(const FMinimalViewInfo& Start) const
{
    return bShoulderRelativeToInitialView
        ? Start.Location + Start.Rotation.RotateVector(ShoulderViewOffset)
        : GetActorTransform().TransformPosition(ShoulderControlLocal);
}

AActor* AYIXIT01FocusRig::ResolveTarget(FString& Reason) const
{
    if (!ObservationTarget.IsNull())
    {
        AActor* Target = ObservationTarget.Get(); // Never synchronously load at interaction/cut.
        if (IsValid(Target) && Target->GetWorld() == GetWorld()) return Target;
        Reason = TEXT("ObservationTarget is not already loaded in this play World");
        return nullptr;
    }
    TArray<AActor*> Found;
    UGameplayStatics::GetAllActorsWithTag(this, ObservationTargetTag, Found);
    if (Found.Num() == 1) return Found[0];
    Reason = FString::Printf(TEXT("Observation target tag %s has %d matches"), *ObservationTargetTag.ToString(), Found.Num());
    return nullptr;
}
