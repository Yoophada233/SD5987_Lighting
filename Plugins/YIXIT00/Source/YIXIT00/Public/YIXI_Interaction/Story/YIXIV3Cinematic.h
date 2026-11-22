#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraTypes.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/Actor.h"
#include "YIXIV3Cinematic.generated.h"

class ACineCameraActor;
class ABlockingVolume;
class UBoxComponent;
class UCapsuleComponent;
class UCineCameraComponent;
class USkeletalMeshComponent;
class ALevelSequenceActor;
class ULevelSequence;
class ULevelSequencePlayer;
class UNiagaraSystem;
class AYIXIInteractionStoryCoordinator;
class AYIXIT00TransitionController;
class AYIXIScriptedRock;
class AYIXIStoryGirl;
class AYIXIStoryToyPickup;
class UYIXIToyCarryComponent;
class UYIXIV3AudioComponent;
class UYIXIInteractorComponent;
class UYIXIV3NeutralInput;

UENUM(BlueprintType)
enum class EYIXIV3Shot : uint8 { Idle, Shoulder, Hand, Fall, Hold, Night, Handoff, HandBlend, FloorReframe, StageAlign, ReturningToDay };

/** Isolated day/night presentation. Story progression and ownership of the toy stay with their existing actors. */
UCLASS(Blueprintable)
class YIXIT00_API AYIXIV3Cinematic : public AActor
{
    GENERATED_BODY()
public:
    AYIXIV3Cinematic();
    void PrepareNight(AYIXIInteractionStoryCoordinator* Sender, APawn* Participant);
    bool BeginDiscovery(AYIXIInteractionStoryCoordinator* Sender, APawn* Participant);
    void HandleAttackImpact(AYIXIScriptedRock* Rock);
    bool CanEnterFixedStage(APawn* Participant) const;

    UFUNCTION(BlueprintCallable, Category="V3") void RequestSkip();
    UFUNCTION(BlueprintCallable, Category="V3") void InterruptPresentation();

    UPROPERTY(EditAnywhere, Category="V3") TObjectPtr<ULevelSequence> Sequence;
    UPROPERTY(EditInstanceOnly, Category="V3|Stage") bool bUseFixedStage=false;
    /** Use the formal Day story's actor instances and release control after the daytime hold. */
    UPROPERTY(EditInstanceOnly, Category="V3|Day Preview") bool bDayOnlyPreview=false;
    /** Enables the Master-owned real Night while using the same formal Day pickup, rock and girl. */
    UPROPERTY(EditInstanceOnly, Category="V3|Formal Transition") TObjectPtr<AYIXIInteractionStoryCoordinator> FormalStory;
    UPROPERTY(EditInstanceOnly, Category="V3|Day Bindings")
    TObjectPtr<AYIXIStoryToyPickup> DayPreviewPickup;
    UPROPERTY(EditInstanceOnly, Category="V3|Day Bindings")
    TObjectPtr<AYIXIScriptedRock> DayPreviewRock;
    UPROPERTY(EditInstanceOnly, Category="V3|Day Bindings")
    TObjectPtr<AYIXIStoryGirl> DayPreviewGirl;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3|Stage") TObjectPtr<USceneComponent> StageRoot;
    /** Place this marker on the ground and point its X axis along the desired player facing. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3|Stage") TObjectPtr<USceneComponent> PlayerStandMarker;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3|Stage") TObjectPtr<UCineCameraComponent> ShoulderCamera;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3|Stage") TObjectPtr<USceneComponent> RockFocusMarker;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3|Stage") TObjectPtr<USceneComponent> HandCameraMarker;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3|Stage") TObjectPtr<UBoxComponent> StageTrigger;
    /** Invisible gameplay floor volumes to exclude from the toy insert's camera sweeps and sightlines. */
    UPROPERTY(EditInstanceOnly, Category="V3|Stage")
    TArray<TObjectPtr<ABlockingVolume>> ToyCameraFloorVolumes;
    /** Walkable surface the toy must hit beneath its release position. Required by the formal Day preview. */
    UPROPERTY(EditInstanceOnly, Category="V3|Stage|Toy Landing")
    TObjectPtr<AActor> ToyLandingSurface;
    /** When enabled, the marker must agree with the support height and the toy's vertical projection. */
    UPROPERTY(EditInstanceOnly, Category="V3|Stage|Toy Landing")
    bool bUseToyLandingMarker = false;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3|Stage|Toy Landing")
    TObjectPtr<USceneComponent> ToyLandingMarker;
    UPROPERTY(EditInstanceOnly, Category="V3|Stage", meta=(ClampMin="5",Units="cm")) float MaxStageEntryDistance=180.f;
    UPROPERTY(EditInstanceOnly, Category="V3|Stage", meta=(ClampMin="1",Units="cm")) float StagePositionTolerance=5.f;
    UPROPERTY(EditInstanceOnly, Category="V3|Stage", meta=(ClampMin="1",ClampMax="15",Units="deg")) float StageFacingTolerance=3.f;
    UPROPERTY(EditInstanceOnly, Category="V3|Stage", meta=(ClampMin="5",Units="cm/s")) float StageMoveSpeed=100.f;
    UPROPERTY(EditInstanceOnly, Category="V3|Stage", meta=(ClampMin="1",Units="s")) float StageMoveTimeout=7.f;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3") TObjectPtr<USceneComponent> Shoulder;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3") TObjectPtr<USceneComponent> AlternateShoulder;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3") TObjectPtr<USceneComponent> NightLanding;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3") TObjectPtr<USceneComponent> DropLanding;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3") TObjectPtr<USceneComponent> AlternateDropLanding;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="V3") TObjectPtr<UYIXIV3AudioComponent> Audio;
    UPROPERTY(EditInstanceOnly, Category="V3|Set") TArray<TObjectPtr<AActor>> NightSet;
    UPROPERTY(EditAnywhere, Category="V3|Set") TObjectPtr<UNiagaraSystem> DustEffect;
    UPROPERTY(EditAnywhere, Category="V3|Set") bool bNightPreviewReady = true;
    UPROPERTY(EditAnywhere, Category="V3|Drop") bool bUseAuthoredDrop = false;
    /** Camera offsets from the right shoulder reference, in pawn-facing axes and world up. */
    UPROPERTY(EditAnywhere, Interp, Category="V3|Camera", meta=(ClampMin="1",Units="cm")) float ShoulderBackDistance=58.f;
    UPROPERTY(EditAnywhere, Interp, Category="V3|Camera", meta=(ClampMin="1",Units="cm")) float ShoulderRightDistance=12.f;
    UPROPERTY(EditAnywhere, Interp, Category="V3|Camera", meta=(Units="cm")) float ShoulderHeight=7.f;
    /** Independent rack, zero at the rubble, one at the visible toy surface. */
    UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category="V3|Sequence", meta=(ClampMin="0",ClampMax="1")) float FocusTravel=0.f;
    UPROPERTY(EditAnywhere, Interp, Category="V3|Camera", meta=(ClampMin="1",ClampMax="22")) float LensAperture=1.4f;
    UPROPERTY(EditAnywhere, Category="V3|Camera") FVector DayToyCameraOffset = FVector(-38,42,32);
    /** Final floor camera offset from the settled toy, in pawn-facing axes and world up. */
    UPROPERTY(EditAnywhere, Category="V3|Camera", meta=(Units="cm")) FVector FloorCameraOffset = FVector(-100,32,33);
    UPROPERTY(EditAnywhere, Category="V3|Camera") FVector PullbackOffset = FVector(-285,68,85);
    UPROPERTY(EditAnywhere, Interp, Category="V3|Camera", meta=(ClampMin="5",ClampMax="120")) float ShoulderFOV = 62;
    UPROPERTY(EditAnywhere, Interp, Category="V3|Camera", meta=(ClampMin="5",ClampMax="120")) float ToyFOV = 34;
    UPROPERTY(EditAnywhere, Interp, Category="V3|Camera", meta=(ClampMin="30",Units="cm")) float CloseupDistance = 104;
    UPROPERTY(EditAnywhere, Category="V3|Camera") FVector NightCloseupDirection = FVector(-1,0.18,0.14);
    UPROPERTY(EditAnywhere, Category="V3|Timing", meta=(ClampMin="0.05",ClampMax="5.0",Units="s")) float EchoLeadSeconds = 4.0f;
    /** Normalized, monotonic fall from Release to Landed. */
    UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category="V3|Sequence") float DropProgress = 0;
    /** Key this property on the V3Host possessable for the shoulder approach and night pullback. */
    UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category="V3|Sequence") float CameraTravel = 0;
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="V3") EYIXIV3Shot Shot = EYIXIV3Shot::Idle;
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="V3") float SequenceSeconds = 0;
protected:
    virtual void Tick(float DeltaSeconds) override;
    virtual void BeginPlay() override;
    virtual void EndPlay(EEndPlayReason::Type Reason) override;
private:
    UFUNCTION() void HandleDayPreviewPickup(APawn* PickingPawn);
    void TryPendingDayPreview();
    bool UsesDayBindings() const { return bDayOnlyPreview || FormalStory!=nullptr; }
    AYIXIT00TransitionController* FindFormalTransition() const;
    UYIXIV3AudioComponent* PresentationAudio() const;
    bool ValidateFormalNightCamera() const;
    void PrepareSequence();
    bool BeginPresentation(AYIXIInteractionStoryCoordinator* Sender, APawn* Participant);
    bool ReadTimeline();
    bool ClearCameraPath(FVector Start, FVector End, bool bToyRail=false) const;
    bool ClearToySight(FVector Subject, FVector Eye) const;
    bool ChooseShoulderView();
    bool ClearStageWalk(const APawn& Participant, const UCapsuleComponent& Capsule) const;
    bool PrepareStageCameraRoute(const UCapsuleComponent& Capsule);
    void UpdateStageAlignment(float Delta);
    bool ResolveToyLanding(FTransform& Landing);
    bool PrepareHandRail();
    bool PrepareDropCamera();
    bool UpdateDropCamera();
    bool NightDestination(FVector& Location) const;
    bool MoveParticipant(const FTransform& Pose);
    void Sample(float Time);
    void ShowNight(bool bVisible);
    void SetShot(EYIXIV3Shot Next);
    void Camera(const FMinimalViewInfo& View);
    void HoldParticipantPose();
    void ReleaseParticipantPose();
    void CaptureWaistInsert();
    void UpdateWaistInsert(float FollowSocket);
    void RestoreWaistAttachment();
    FMinimalViewInfo ToyView(bool bNight) const;
    FMinimalViewInfo DayToyView(FVector Eye, FVector Center) const;
    float DayToyFOV(double Distance) const;
    void BeginHandoff();
    void Close(bool bCompleted, const TCHAR* Reason);
    UPROPERTY(Transient) TObjectPtr<ULevelSequencePlayer> Player;
    UPROPERTY(Transient) TObjectPtr<ALevelSequenceActor> PlayerActor;
    UPROPERTY(Transient) TObjectPtr<ACineCameraActor> CameraActor;
    UPROPERTY(Transient) TObjectPtr<AYIXIInteractionStoryCoordinator> Story;
    UPROPERTY(Transient) TObjectPtr<APawn> Pawn;
    UPROPERTY(Transient) TObjectPtr<APlayerController> PC;
    UPROPERTY(Transient) TObjectPtr<UYIXIToyCarryComponent> Carry;
    UPROPERTY(Transient) TObjectPtr<UYIXIInteractorComponent> Interactor;
    UPROPERTY(Transient) TObjectPtr<AActor> Toy;
    UPROPERTY(Transient) TArray<TObjectPtr<UObject>> SavedMoverInputs;
    UPROPERTY(Transient) TObjectPtr<UYIXIV3NeutralInput> CinematicInput;
    TWeakObjectPtr<AActor> PreviousView;
    TWeakObjectPtr<APawn> DayPreviewPawn;
    TWeakObjectPtr<AActor> DayPreviewToy;
    TWeakObjectPtr<AYIXIT00TransitionController> FormalTransition;
    FTimerHandle DayPreviewRetryTimer;
    bool bDayPreviewConsumed=false;
    bool bDayPreviewRequiresExit=false;
    bool bReportedToyLandingIssue=false;
    FTransform DayPawnPose, FloorPose;
    FTransform FormalNightPose;
    FRotator DayControlRotation;
    FMinimalViewInfo EntryView, ShoulderView, DropStartView, FloorView, NightView;
    TOptional<FVector> StageCameraBend;
    TArray<TWeakObjectPtr<USkeletalMeshComponent>> FrozenMeshes;
    TWeakObjectPtr<USceneComponent> WaistParent;
    FName WaistSocket=NAME_None;
    FTransform AuthoredWaistRelative, InsertInPawn;
    FVector GoalLocation, FloorToyCenter, HandEye, HandToyCenter;
    double DropStartDistance=0., FloorViewDistance=0.;
    float HandRailHeight=0, ApproachStartTravel=0;
    bool bShoulderFramed=false;
    float LockedToyFOV=34;
    float ShoulderSetAt=0, HandBlendAt=0, HandAt=0, ReleaseAt=0, LandedAt=0, StableAt=0, CutAt=0, PullAt=0, ReturnAt=0, EndAt=0;
    float Waiting=0, SkipHeld=0, HoldGameStart=0;
    float StageAlignmentTime=0, StageSettleTime=0;
    bool bInputHeld=false, bPawnInputWasEnabled=false, bWasSuppressed=false, bMoved=false, bCut=false, bSkip=false, bClosing=false;
    bool bEndingPresentationPlay=false;
};
