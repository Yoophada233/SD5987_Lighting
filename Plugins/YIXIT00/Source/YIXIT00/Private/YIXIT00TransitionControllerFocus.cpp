#include "YIXIT00TransitionController.h"
#include "YIXIT01FocusRig.h"
#include "Camera/CameraComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Core/CameraSystemEvaluator.h"
#include "Dom/JsonObject.h"
#include "Engine/GameViewportClient.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "Framework/Application/IInputProcessor.h"
#include "Framework/Application/SlateApplication.h"
#include "GameFramework/GameplayCameraComponentBase.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/SOverlay.h"
#include "Widgets/SViewport.h"
#include "Widgets/Text/STextBlock.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIT01, Log, All);

namespace
{
FVector Bezier(const FVector& A, const FVector& B, const FVector& C, float T)
{
    return FMath::Square(1.f-T)*A + 2.f*(1.f-T)*T*B + FMath::Square(T)*C;
}

// PIE reserves Escape before gameplay input. Only intercept it for this live
// controller in FocusHold while its own game viewport has keyboard focus.
class FYIXIT01EscapeInput final : public IInputProcessor
{
public:
    explicit FYIXIT01EscapeInput(AYIXIT00TransitionController* InOwner) : Owner(InOwner) {}
    virtual void Tick(float, FSlateApplication&, TSharedRef<ICursor>) override {}
    virtual bool HandleKeyDownEvent(FSlateApplication&, const FKeyEvent& Key) override
    {
        if (Key.GetKey() == EKeys::Escape && bConsumedEscape) return true;
        if (Key.GetKey() == EKeys::Escape && Owner.IsValid() && Owner->HandleFocusEscapeFromViewport())
        { bConsumedEscape = true; return true; }
        return false;
    }
    virtual bool HandleKeyUpEvent(FSlateApplication&, const FKeyEvent& Key) override
    {
        if (Key.GetKey() == EKeys::Escape && bConsumedEscape) { bConsumedEscape = false; return true; }
        return false;
    }
private:
    TWeakObjectPtr<AYIXIT00TransitionController> Owner;
    bool bConsumedEscape = false;
};
}

FString AYIXIT00TransitionController::FocusStateName() const
{
    static const TCHAR* Names[] = {TEXT("Explore"),TEXT("FocusEnter"),TEXT("FocusHold"),TEXT("MatchCut"),
        TEXT("FocusExit"),TEXT("ExploreNight"),TEXT("FocusReturn"),TEXT("Failed")};
    return Names[static_cast<uint8>(FocusState)];
}

void AYIXIT00TransitionController::SetFocusState(EYIXIT01FocusState State)
{
    FocusState = State;
    if (FocusPromptWidget.IsValid() && State!=EYIXIT01FocusState::Explore && State!=EYIXIT01FocusState::FocusHold)
        FocusPromptWidget->SetVisibility(EVisibility::Collapsed);
    Event(TEXT("T01_STATE_") + FocusStateName());
}

bool AYIXIT00TransitionController::SetupFocusInteraction(FString& Reason)
{
    if (!FocusRig)
    {
        TArray<AActor*> Found;
        UGameplayStatics::GetAllActorsOfClass(this, AYIXIT01FocusRig::StaticClass(), Found);
        if (Found.Num()>1) { Reason = TEXT("Multiple T01 Focus Rigs; assign one on T00_Controller"); return false; }
        if (Found.Num()==1) FocusRig = Cast<AYIXIT01FocusRig>(Found[0]);
    }
    if (!FocusRig) { Event(TEXT("T01_NOT_CONFIGURED_T00_DEBUG_ONLY")); return true; }
    if (!FocusRig->Validate(Reason)) return false;
    if (!FocusRig->DayCloseupCamera.IsNull()) CameraA = FocusRig->DayCloseupCamera.Get();
    if (!FocusRig->NightCloseupCamera.IsNull()) CameraB = FocusRig->NightCloseupCamera.Get();
    if (!CameraA || !CameraB || CameraA->GetWorld()!=GetWorld() || CameraB->GetWorld()!=GetWorld())
    { Reason = TEXT("T01 closeup cameras are not already loaded in this play World"); return false; }
    FocusTarget = FocusRig->ResolveTarget(Reason);
    if (!FocusTarget) return false;
    Result->SetStringField(TEXT("camera_a_actor"),CameraA->GetPathName());
    Result->SetStringField(TEXT("camera_b_actor"),CameraB->GetPathName());
    Result->SetStringField(TEXT("focus_rig"),FocusRig->GetPathName());
    if (!PC->GetLocalPlayer() || !PC->GetLocalPlayer()->ViewportClient || !FSlateApplication::IsInitialized())
    { Reason = TEXT("T01 requires a local game viewport for the interaction prompt/Escape"); return false; }

    InputComponent->BindKey(EKeys::F, IE_Pressed, this, &AYIXIT00TransitionController::InteractionPressed);
    InputComponent->BindKey(EKeys::F, IE_Released, this, &AYIXIT00TransitionController::InteractionReleased);
    InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AYIXIT00TransitionController::CancelFocus);
    FocusEscapeProcessor = MakeShared<FYIXIT01EscapeInput>(this);
    if (!FSlateApplication::Get().RegisterInputPreProcessor(FocusEscapeProcessor, 0))
    { Reason = TEXT("Could not register the T01 viewport-only Escape handler"); return false; }

    TWeakObjectPtr<AYIXIT00TransitionController> Weak(this);
    FocusPromptWidget = SNew(SOverlay)
        + SOverlay::Slot().HAlign(HAlign_Center).VAlign(VAlign_Bottom).Padding(0,0,0,90)
        [ SNew(SBorder).Padding(FMargin(14,8)).BorderBackgroundColor(FLinearColor(.03f,.03f,.03f,.85f))
            [ SNew(STextBlock).Font(FCoreStyle::GetDefaultFontStyle(TEXT("Regular"),22))
                .ColorAndOpacity(FLinearColor::White)
                .Text_Lambda([Weak]()
                {
                    const auto* Self = Weak.Get();
                    if (!Self || !Self->FocusRig) return FText::GetEmpty();
                    return Self->FocusState==EYIXIT01FocusState::FocusHold
                        ? Self->FocusRig->ObservationPrompt : Self->FocusRig->InteractionPrompt;
                }) ] ];
    FocusPromptWidget->SetVisibility(EVisibility::Collapsed);
    PC->GetLocalPlayer()->ViewportClient->AddViewportWidgetForPlayer(PC->GetLocalPlayer(), FocusPromptWidget.ToSharedRef(), 20);
    Event(TEXT("T01_INTERACTION_BOUND_F_PRESS_RELEASE_ESC"));
    return true;
}

void AYIXIT00TransitionController::ShutdownFocusInteraction()
{
    if (FocusEscapeProcessor.IsValid() && FSlateApplication::IsInitialized())
        FSlateApplication::Get().UnregisterInputPreProcessor(FocusEscapeProcessor);
    FocusEscapeProcessor.Reset();
    if (FocusPromptWidget.IsValid() && PC && PC->GetLocalPlayer() && PC->GetLocalPlayer()->ViewportClient)
        PC->GetLocalPlayer()->ViewportClient->RemoveViewportWidgetForPlayer(PC->GetLocalPlayer(), FocusPromptWidget.ToSharedRef());
    FocusPromptWidget.Reset();
}

bool AYIXIT00TransitionController::HandleFocusEscapeFromViewport()
{
    if (FocusState==EYIXIT01FocusState::Explore || FocusState==EYIXIT01FocusState::ExploreNight
        || FocusState==EYIXIT01FocusState::Failed || !PC || !PC->GetLocalPlayer() || !PC->GetLocalPlayer()->ViewportClient)
        return false;
    auto Viewport = PC->GetLocalPlayer()->ViewportClient->GetGameViewportWidget();
    if (!Viewport.IsValid() || !(Viewport->HasKeyboardFocus() || Viewport->HasFocusedDescendants())) return false;
    if (FocusState==EYIXIT01FocusState::FocusHold) CancelFocus();
    else Event(TEXT("T01_ESCAPE_IGNORED_DURING_MOTION"));
    return true;
}

void AYIXIT00TransitionController::InteractionPressed()
{
    if (bInteractionKeyDown) return;
    bInteractionKeyDown = true;
    if (!FocusRig) return;
    if (FocusState==EYIXIT01FocusState::Explore && Phase==EPhase::Ready)
    {
        if (!FocusRig->ContainsPawn(TestPawn)) { Event(TEXT("T01_F_IGNORED_OUT_OF_RANGE")); return; }
        bFocusRequested = true; // Capture PCM after this frame's actual camera evaluation.
    }
    else if (FocusState==EYIXIT01FocusState::FocusHold && bConfirmArmed)
    {
        if (!ScenesReady() || !SamePossession() || PC->GetViewTarget()!=CameraA)
        { FocusFailure(TEXT("Cannot confirm: scenes, possession or day closeup changed")); return; }
        bConfirmArmed = false;
        bInteractiveTransition = true;
        SetFocusState(EYIXIT01FocusState::MatchCut);
        Phase = EPhase::Day;
        PhaseAt = FPlatformTime::Seconds()-DayHoldSeconds; // Reuse the proven T00 cut on the next tick, without another day hold.
        Event(TEXT("T01_CONFIRM_REUSE_T00_MATCH_CUT"));
    }
    else Event(TEXT("T01_F_IGNORED_DURING_MOTION_OR_NOT_REARMED"));
}

void AYIXIT00TransitionController::InteractionReleased()
{
    bInteractionKeyDown = false;
    if (FocusState==EYIXIT01FocusState::FocusHold) bConfirmArmed = true;
}

void AYIXIT00TransitionController::CancelFocus()
{
    if (FocusState==EYIXIT01FocusState::FocusHold) BeginFocusReturn(false);
}

bool AYIXIT00TransitionController::ReadGameplayView(FMinimalViewInfo& View, FString& Reason) const
{
    if (!IsValid(GameplayCamera) || !GameplayCamera->IsActive())
    { Reason=TEXT("Original Gameplay Camera is not active"); return false; }
    const auto Evaluator = GameplayCamera->GetCameraSystemEvaluator();
    if (!Evaluator.IsValid() || !Evaluator->GetEvaluatedResult().bIsValid)
    { Reason=TEXT("Original Gameplay Camera has no evaluated live view"); return false; }
    Evaluator->GetEvaluatedCameraView(View);
    if (View.Location.ContainsNaN() || View.Rotation.ContainsNaN() || !FMath::IsFinite(View.FOV) || View.FOV<=0)
    { Reason=TEXT("Original Gameplay Camera returned an invalid view"); return false; }
    return true;
}

bool AYIXIT00TransitionController::SafeCameraSegment(const FVector& Start, const FVector& End, FString& Reason) const
{
    if (Start.ContainsNaN() || End.ContainsNaN()) { Reason=TEXT("Camera path contains invalid coordinates"); return false; }
    FCollisionQueryParams Query(SCENE_QUERY_STAT(YIXIT01FocusCamera), false);
    Query.AddIgnoredActor(this); Query.AddIgnoredActor(FocusRig);
    if (FocusViewCamera) Query.AddIgnoredActor(FocusViewCamera);
    FHitResult Hit;
    if (GetWorld()->SweepSingleByChannel(Hit, Start, End, FQuat::Identity, ECC_Camera,
            FCollisionShape::MakeSphere(FocusRig->CameraProbeRadius), Query))
    { Reason=FString::Printf(TEXT("Camera path blocked by %s; adjust the shoulder/return control point"), *GetNameSafe(Hit.GetActor())); return false; }

    // GASP often ignores its own Pawn on ECC_Camera; explicitly protect the head.
    FVector Head = TestPawn->GetActorLocation();
    if (auto* Mesh = TestPawn->FindComponentByClass<USkeletalMeshComponent>(); Mesh && Mesh->DoesSocketExist(TEXT("head")))
        Head = Mesh->GetSocketLocation(TEXT("head"));
    else if (auto* Capsule = TestPawn->FindComponentByClass<UCapsuleComponent>())
        Head += FVector(0,0,Capsule->GetScaledCapsuleHalfHeight()*.75f);
    if (FVector::DistSquared(FMath::ClosestPointOnSegment(Head,Start,End),Head)
            < FMath::Square(FocusRig->CameraProbeRadius + FocusRig->HeadAvoidanceRadius))
    { Reason=TEXT("Camera path too close to the player's head; adjust shoulder side/offset"); return false; }
    return true;
}

bool AYIXIT00TransitionController::ValidateFocusPath(const FMinimalViewInfo& Start, const FMinimalViewInfo& End,
    const FVector& Control, FString& Reason) const
{
    if (Start.ProjectionMode!=ECameraProjectionMode::Perspective || End.ProjectionMode!=ECameraProjectionMode::Perspective
        || !FMath::IsFinite(End.FOV) || End.FOV<=0 || Control.ContainsNaN())
    { Reason=TEXT("Focus path requires valid perspective cameras/FOV/control point"); return false; }
    FVector Previous=Start.Location;
    for (int32 Index=1; Index<=FocusRig->PathSamples; ++Index)
    {
        const FVector Position=Bezier(Start.Location,Control,End.Location,Index/static_cast<float>(FocusRig->PathSamples));
        if (!SafeCameraSegment(Previous,Position,Reason)) return false;
        Previous=Position;
    }
    return true;
}

void AYIXIT00TransitionController::FocusFailure(const FString& Reason)
{
    const FString Detail=TEXT("T01 stage=")+FocusStateName()+TEXT(" reason=")+Reason;
    bFocusRequested=false;
    if (FocusPromptWidget.IsValid()) FocusPromptWidget->SetVisibility(EVisibility::Collapsed);
    Finish(false,Detail); // Existing T00 recovery restores the same Pawn/camera/input.
}

void AYIXIT00TransitionController::BeginFocusEnter()
{
    bFocusRequested=false;
    FString Reason;
    if (!SamePossession() || !ScenesReady() || !FocusRig || !FocusRig->ContainsPawn(TestPawn)
        || !IsValid(FocusTarget) || !IsValid(CameraA) || !PC->PlayerCameraManager || PC->GetViewTarget()!=TestPawn)
    { FocusFailure(TEXT("FocusEnter needs the nearby Pawn's actual third-person view and loaded scene references")); return; }
    if (!FocusRig->Validate(Reason)) { FocusFailure(Reason); return; }
    FocusStartView=PC->PlayerCameraManager->GetCameraCacheView();
    CameraA->CalcCamera(0,FocusEndView);
    FocusControlPoint=EnterControlPoint=FocusRig->ControlPoint(FocusStartView);
    if (!ValidateFocusPath(FocusStartView,FocusEndView,FocusControlPoint,Reason))
    {
        // An obstructed approach is recoverable: stay in Explore, without
        // taking camera ownership or locking movement. No clipped shot.
        UE_LOG(LogYIXIT01, Warning, TEXT("[YIXI_T01] ENTER_REJECTED stage=Explore reason=%s"), *Reason);
        Result->SetStringField(TEXT("last_focus_path_rejection"),Reason);
        Event(TEXT("T01_ENTER_REJECTED_PATH"));
        return;
    }
    if (!FocusViewCamera)
    {
        FActorSpawnParameters Params; Params.Owner=this; Params.ObjectFlags|=RF_Transient;
        Params.SpawnCollisionHandlingOverride=ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        FocusViewCamera=GetWorld()->SpawnActor<AYIXIT01ViewCamera>(AYIXIT01ViewCamera::StaticClass(),FTransform::Identity,Params);
    }
    if (!FocusViewCamera) { FocusFailure(TEXT("Could not create the runtime-owned view proxy")); return; }
    FocusViewCamera->View=FocusStartView;
    FocusViewCamera->SetActorLocationAndRotation(FocusStartView.Location,FocusStartView.Rotation);
    HoldInput();
    bConfirmArmed=false;
    FocusAt=FPlatformTime::Seconds();
    // Zero-time ownership change to an identical PCM snapshot. The first
    // rendered pose remains the captured pose; motion starts on later ticks.
    PC->SetViewTarget(FocusViewCamera);
    bEntryCameraSamplePending=true;
    SetFocusState(EYIXIT01FocusState::FocusEnter);
    Result->SetNumberField(TEXT("focus_entry_snapshot_fov"),FocusStartView.FOV);
    Event(TEXT("T01_CAPTURED_ACTUAL_PCM_VIEW"));
}

void AYIXIT00TransitionController::BeginFocusReturn(bool bNight)
{
    FString Reason;
    if (!FocusRig || !PC || !PC->PlayerCameraManager || !FocusViewCamera || !SamePossession())
    { FocusFailure(TEXT("Return camera/Pawn/controller unavailable")); return; }
    GameplayCamera->ActivateCameraForPlayerController(PC,false); // Keep the outgoing view; no abrupt GASP SetViewTarget.
    FocusStartView=PC->PlayerCameraManager->GetCameraCacheView();
    if (!ReadGameplayView(FocusEndView,Reason)) { FocusFailure(Reason); return; }
    if (FVector::Dist(FocusEndView.Location,TestPawn->GetActorLocation())>=1500)
    { FocusFailure(TEXT("Gameplay Camera output has not settled near the same Pawn; refusing a cross-scene return")); return; }
    FocusControlPoint=bNight
        ? (FocusStartView.Location+FocusEndView.Location)*.5 + FocusEndView.Rotation.RotateVector(FocusRig->NightReturnArcOffset)
        : EnterControlPoint;
    if (!ValidateFocusPath(FocusStartView,FocusEndView,FocusControlPoint,Reason))
    { FocusFailure(TEXT("Return path unsafe: ")+Reason); return; }
    FocusViewCamera->View=FocusStartView;
    FocusViewCamera->SetActorLocationAndRotation(FocusStartView.Location,FocusStartView.Rotation);
    PC->SetViewTarget(FocusViewCamera);
    FocusAt=FPlatformTime::Seconds();
    bAwaitingHandoff=false;
    if (bNight) Phase=EPhase::AwaitRestore;
    SetFocusState(bNight ? EYIXIT01FocusState::FocusExit : EYIXIT01FocusState::FocusReturn);
}

bool AYIXIT00TransitionController::TickFocus(double Now, float DeltaSeconds)
{
    if (!FocusRig) return false;
    if (FocusPromptWidget.IsValid())
    {
        const bool Show=(FocusState==EYIXIT01FocusState::Explore && Phase==EPhase::Ready && FocusRig->ContainsPawn(TestPawn))
            || FocusState==EYIXIT01FocusState::FocusHold;
        FocusPromptWidget->SetVisibility(Show ? EVisibility::SelfHitTestInvisible : EVisibility::Collapsed);
    }
    if (bFocusRequested)
    {
        if (FocusState==EYIXIT01FocusState::Explore && Phase==EPhase::Ready) BeginFocusEnter();
        else bFocusRequested=false;
        return true; // Preserve the captured view for this first frame.
    }
    if (FocusState==EYIXIT01FocusState::FocusHold)
    {
        if (!IsValid(CameraA) || PC->GetViewTarget()!=CameraA)
            FocusFailure(TEXT("FocusHold lost the day closeup camera"));
        return true; // Unlimited, with no automatic match cut.
    }
    const bool bEntering=FocusState==EYIXIT01FocusState::FocusEnter;
    const bool bReturning=FocusState==EYIXIT01FocusState::FocusReturn || FocusState==EYIXIT01FocusState::FocusExit;
    if (!bEntering && !bReturning) return false; // MatchCut uses the original T00 machine.
    FString Reason;
    if (!IsValid(FocusViewCamera)) { FocusFailure(TEXT("View proxy removed during motion")); return true; }
    if (!FocusRig->Validate(Reason)) { FocusFailure(Reason); return true; }

    if (bAwaitingHandoff)
    {
        if (Now-HandoffAt >= FocusRig->HandoffSeconds+.05f && PC->GetViewTarget()==TestPawn && GameplayCamera->IsActive())
        {
            const bool bNight=FocusState==EYIXIT01FocusState::FocusExit;
            RestoreInput();
            bAwaitingHandoff=false;
            bInteractionKeyDown=PC->IsInputKeyDown(EKeys::F);
            SetFocusState(bNight ? EYIXIT01FocusState::ExploreNight : EYIXIT01FocusState::Explore);
            Event(TEXT("T01_GAMEPLAY_CAMERA_AND_INPUT_RESTORED"));
            if (bNight)
            {
                Phase=EPhase::Post; PhaseAt=RestoredAt=Now;
                PostStartLocation=TestPawn->GetActorLocation();
                Event(TEXT("GameplayCameraRestored_InputEnabled_MOVE_NOW")); Event(TEXT("T00_CAMERA_RESTORED"));
            }
            else
            {
                Phase=EPhase::Ready;
                Event(TEXT("T01_CANCEL_COMPLETE"));
            }
        }
        else if (Now-HandoffAt>FocusRig->HandoffSeconds+3)
            FocusFailure(TEXT("Original Gameplay Camera handoff did not complete"));
        return true;
    }
    if (PC->GetViewTarget()!=FocusViewCamera)
    { FocusFailure(TEXT("Cinematic motion lost ownership of the camera")); return true; }
    if (bEntering && bEntryCameraSamplePending && PC->PlayerCameraManager)
    {
        const auto& Actual=PC->PlayerCameraManager->GetCameraCacheView();
        Result->SetNumberField(TEXT("focus_handover_position_error_cm"),FVector::Dist(Actual.Location,FocusStartView.Location));
        Result->SetNumberField(TEXT("focus_handover_rotation_error_degrees"),FMath::RadiansToDegrees(Actual.Rotation.Quaternion().AngularDistance(FocusStartView.Rotation.Quaternion())));
        Result->SetNumberField(TEXT("focus_handover_fov_error_degrees"),FMath::Abs(Actual.FOV-FocusStartView.FOV));
        bEntryCameraSamplePending=false;
        Event(TEXT("T01_FIRST_ACTUAL_PROXY_VIEW_MEASURED"));
    }
    if (bReturning)
    {
        if (!ReadGameplayView(FocusEndView,Reason)) { FocusFailure(Reason); return true; }
        if (FVector::Dist(FocusEndView.Location,TestPawn->GetActorLocation())>=1500)
        { FocusFailure(TEXT("Live return camera moved away from the Pawn")); return true; }
    }
    if (!IsValid(FocusTarget)) { FocusFailure(TEXT("Observation target was removed")); return true; }
    const float Duration=bEntering ? FocusRig->EnterSeconds : FocusRig->ReturnSeconds;
    const float A=FocusRig->Ease(static_cast<float>((Now-FocusAt)/Duration));
    FMinimalViewInfo View=FocusStartView;
    View.Location=Bezier(FocusStartView.Location,FocusControlPoint,FocusEndView.Location,A);
    FQuat Rotation;
    if (bEntering)
    {
        const FVector Aim=FocusTarget->GetActorLocation()+FocusTarget->GetActorRotation().RotateVector(FocusRig->TargetLocalOffset);
        const FQuat Look=(Aim-View.Location).Rotation().Quaternion();
        Rotation=FQuat::Slerp(FocusStartView.Rotation.Quaternion(),Look,A);
        Rotation=FQuat::Slerp(Rotation,FocusEndView.Rotation.Quaternion(),A*A);
    }
    else Rotation=FQuat::Slerp(FocusStartView.Rotation.Quaternion(),FocusEndView.Rotation.Quaternion(),A);
    View.Rotation=Rotation.GetNormalized().Rotator();
    View.FOV=FMath::Lerp(FocusStartView.FOV,FocusEndView.FOV,A);
    View.AspectRatio=FMath::Lerp(FocusStartView.AspectRatio,FocusEndView.AspectRatio,A);
    if (A>=1) View=FocusEndView; // Exact endpoint pose/FOV, no final snap to a different camera.
    if (!SafeCameraSegment(FocusViewCamera->View.Location,View.Location,Reason))
    { FocusFailure(TEXT("Camera motion obstructed: ")+Reason); return true; }
    FocusViewCamera->View=View;
    FocusViewCamera->SetActorLocationAndRotation(View.Location,View.Rotation);
    if (A>=1)
    {
        if (bEntering)
        {
            PC->SetViewTarget(CameraA);
            bConfirmArmed=!bInteractionKeyDown && !PC->IsInputKeyDown(EKeys::F);
            SetFocusState(EYIXIT01FocusState::FocusHold);
            Event(TEXT("T01_HOLD_NO_COUNTDOWN_RELEASE_F_BEFORE_CONFIRM"));
        }
        else
        {
            // GASP remains active during the curve. A short outgoing-locked
            // blend absorbs the final frame of live camera motion on handoff.
            FViewTargetTransitionParams Blend;
            Blend.BlendTime=FocusRig->HandoffSeconds;
            Blend.BlendFunction=VTBlend_EaseInOut; Blend.BlendExp=2.f; Blend.bLockOutgoing=true;
            PC->SetViewTarget(TestPawn,Blend);
            HandoffAt=Now; bAwaitingHandoff=true;
            Event(TEXT("T01_GAMEPLAY_CAMERA_HANDOFF_REQUESTED"));
        }
    }
    return true;
}
