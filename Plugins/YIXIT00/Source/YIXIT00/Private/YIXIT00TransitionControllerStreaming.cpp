#include "YIXIT00TransitionController.h"
#include "Camera/CameraActor.h"
#include "Camera/PlayerCameraManager.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/StaticMeshComponent.h"
#include "Dom/JsonObject.h"
#include "Engine/Level.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/GameplayCameraComponentBase.h"
#include "HAL/PlatformMemory.h"
#include "Kismet/GameplayStatics.h"

ULevelStreaming* AYIXIT00TransitionController::P04Level(FName Name) const
{
    return UGameplayStatics::GetStreamingLevel(this,Name); // Handles PIE package prefixes.
}
bool AYIXIT00TransitionController::P04ScenesReady(FString* Reason) const
{
    auto* Day=P04Level(DayStreamingLevel);
    auto* Night=P04Level(NightStreamingLevel);
    if (GetWorld()->IsPartitionedWorld() || GetWorld()->GetStreamingLevels().Num()!=2 || !Day || !Night ||
        !Day->IsA<ULevelStreamingDynamic>() || !Night->IsA<ULevelStreamingDynamic>())
    { if (Reason) *Reason=TEXT("P04 requires two configured Blueprint streaming levels in a non-WP World"); return false; }
    const bool bDay=Day->IsLevelLoaded() && Day->IsLevelVisible();
    const bool bNight=Night->IsLevelLoaded() && Night->IsLevelVisible();
    if (bP04DayUnloadRequested) return bNight;
    if (Phase==EPhase::Warming)
    {
        if (Reason && !(bDay && !Night->IsLevelLoaded())) *Reason=TEXT("P04 startup waiting for Day visible and Night genuinely unloaded");
        return bDay && !Night->IsLevelLoaded();
    }
    const bool bDayStage=Phase==EPhase::Ready || FocusState==EYIXIT01FocusState::FocusEnter ||
        FocusState==EYIXIT01FocusState::FocusHold || FocusState==EYIXIT01FocusState::FocusReturn;
    if (Reason && !(bDay && (bDayStage || bNight))) *Reason=TEXT("P04 required scene is no longer loaded/visible");
    return bDay && (bDayStage || bNight);
}
bool AYIXIT00TransitionController::P04CutReady() const
{
    auto* Night=P04Level(NightStreamingLevel);
    return bP04NightReady && Night && Night->IsLevelLoaded() && Night->IsLevelVisible();
}
void AYIXIT00TransitionController::RequestP04Night()
{
    if (!bUsePhaseStreaming || bP04Preloading || P04CutReady()) return;
    auto* Night=P04Level(NightStreamingLevel);
    if (!Night) { bP04NightFailed=true; Event(TEXT("P04_NIGHT_REQUEST_FAILED_MISSING_LEVEL")); return; }
    bP04NightFailed=false; bP04NightReady=false; bP04Preloading=true;
    bP04NightFenceStarted=false; P04NightReadyFrames=0; P04LoadAt=FPlatformTime::Seconds();
    Night->bShouldBlockOnLoad=false;
    Night->SetShouldBeLoaded(true); Night->SetShouldBeVisible(true);
    Result->SetNumberField(TEXT("p04_physical_memory_before_load_bytes"),static_cast<double>(FPlatformMemory::GetStats().UsedPhysical));
    Event(TEXT("P04_NIGHT_ASYNC_LOAD_REQUESTED"));
}
void AYIXIT00TransitionController::ReleaseP04DayReferences()
{
    ULevelStreaming* Day=P04Level(DayStreamingLevel);
    ULevel* Level=Day ? Day->GetLoadedLevel() : nullptr;
    int32 Restored=0;
    for (int32 I=DiagnosticMeshes.Num()-1;I>=0;--I)
    {
        auto* Mesh=DiagnosticMeshes[I].Get();
        if (Mesh && Mesh->GetOwner() && Mesh->GetOwner()->GetLevel()==Level)
        {
            Mesh->SetMaterial(0,DiagnosticOriginalMaterials[I]);
            ++Restored;
            DiagnosticMeshes.RemoveAt(I); DiagnosticOriginalMaterials.RemoveAt(I);
        }
    }
    // Cameras, destination, FocusRig and global lighting remain in the Master.
    // The observation target is no longer used once the night handoff finishes.
    FocusTarget=nullptr;
    Result->SetNumberField(TEXT("p04_day_materials_restored_before_unload"),Restored);
    Event(TEXT("P04_DAY_REFERENCES_RELEASED"));
}
void AYIXIT00TransitionController::TickP04Streaming(double Now)
{
    auto* Day=P04Level(DayStreamingLevel);
    auto* Night=P04Level(NightStreamingLevel);
    if (!Day || !Night) return; // ScenesReady produces the initialization reason.
    if (FocusState==EYIXIT01FocusState::FocusReturn && !bInteractiveTransition)
    {
        bP04PendingConfirm=false; bP04PendingDebug=false;
        if (bP04Preloading || bP04NightReady)
        {
            Night->SetShouldBeVisible(false); Night->SetShouldBeLoaded(false);
            bP04Preloading=false; bP04NightReady=false;
            Event(TEXT("P04_CANCEL_NIGHT_UNLOAD_REQUESTED"));
        }
    }
    if (bP04Preloading)
    {
        if (Night->IsLevelLoaded() && Night->IsLevelVisible() && IsValid(Destination))
        {
            FHitResult Hit;
            const FVector Point=Destination->GetActorLocation();
            FCollisionQueryParams Query(SCENE_QUERY_STAT(P04LandingSurface),false);
            Query.AddIgnoredActor(TestPawn);
            const bool bSurface=GetWorld()->LineTraceSingleByChannel(Hit,Point+FVector(0,0,500),
                Point-FVector(0,0,1000),ECC_Visibility,Query) && Hit.GetActor() &&
                Hit.GetActor()->GetLevel()==Night->GetLoadedLevel() && FMath::Abs(Hit.ImpactPoint.Z-Point.Z)<=100;
            if (bSurface)
            {
                if (Captures.IsValidIndex(1) && Captures[1]) Captures[1]->CaptureScene();
                if (++P04NightReadyFrames>=30 && !bP04NightFenceStarted)
                { P04NightFence.BeginFence(); bP04NightFenceStarted=true; }
                if (bP04NightFenceStarted && P04NightFence.IsFenceComplete())
                {
                    bP04NightReady=true; bP04Preloading=false;
                    Result->SetBoolField(TEXT("p04_night_collision_verified"),true);
                    Result->SetNumberField(TEXT("p04_night_load_prepare_seconds"),Now-P04LoadAt);
                    Result->SetNumberField(TEXT("p04_physical_memory_after_load_bytes"),static_cast<double>(FPlatformMemory::GetStats().UsedPhysical));
                    Event(TEXT("P04_NIGHT_LOADED_VISIBLE_COLLISION_RENDER_FENCE_READY"));
                }
            }
            else P04NightReadyFrames=0;
        }
        if (bP04Preloading && Now-P04LoadAt>StreamingTimeoutSeconds)
        {
            bP04Preloading=false; bP04NightReady=false; bP04NightFailed=true;
            bP04PendingConfirm=false; bP04PendingDebug=false;
            Night->SetShouldBeVisible(false); Night->SetShouldBeLoaded(false);
            Result->SetStringField(TEXT("p04_load_failure"),TEXT("Night timed out: loaded/visible, landing collision or 30-frame render prewarm incomplete; Day retained, no teleport"));
            Event(TEXT("P04_NIGHT_LOAD_FAILED_DAY_RETAINED"));
        }
    }
    if (bP04NightFailed && FocusState==EYIXIT01FocusState::FocusHold)
    { BeginFocusReturn(false); return; }
    if (bP04PendingConfirm && P04CutReady())
    {
        bP04PendingConfirm=false;
        if (FocusState==EYIXIT01FocusState::FocusHold && SamePossession() && PC->GetViewTarget()==CameraA)
        {
            bInteractiveTransition=true; bConfirmArmed=false;
            SetFocusState(EYIXIT01FocusState::MatchCut);
            Phase=EPhase::Day; PhaseAt=Now-DayHoldSeconds;
            Event(TEXT("T01_CONFIRM_REUSE_T00_MATCH_CUT"));
        }
    }
    if (bP04PendingDebug && P04CutReady())
    { bP04PendingDebug=false; TriggerTransition(); }
    if (Phase==EPhase::Post && !bP04DayUnloadRequested && SamePossession() &&
        PC->GetViewTarget()==TestPawn && GameplayCamera && GameplayCamera->IsActive())
    {
        ReleaseP04DayReferences();
        Day->bShouldBlockOnUnload=false;
        Day->SetShouldBeVisible(false); Day->SetShouldBeLoaded(false);
        P04UnloadAt=Now; bP04DayUnloadRequested=true;
        Event(TEXT("P04_DAY_ASYNC_UNLOAD_REQUESTED_AFTER_CAMERA_HANDOFF"));
    }
    if (bP04DayUnloadRequested && !bP04DayUnloaded)
    {
        if (!Day->IsLevelLoaded() && !Day->GetLoadedLevel() && !Day->IsLevelVisible())
        {
            bP04DayUnloaded=true;
            Result->SetNumberField(TEXT("p04_day_unload_seconds"),Now-P04UnloadAt);
            Result->SetNumberField(TEXT("p04_physical_memory_after_day_unload_bytes"),static_cast<double>(FPlatformMemory::GetStats().UsedPhysical));
            Event(TEXT("P04_DAY_LEVEL_AND_LANDSCAPE_UNLOADED"));
        }
        else if (Now-P04UnloadAt>StreamingTimeoutSeconds)
        { Finish(false,TEXT("P04 Day unload timeout; night control retained, no forced GC or deletion")); }
    }
}
