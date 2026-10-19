#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraTypes.h"
#include "RenderCommandFence.h"
#include "YIXIT00TransitionController.generated.h"

class ACameraActor;
class APawn;
class APlayerController;
class UCapsuleComponent;
class UMoverComponent;
class UGameplayCameraComponentBase;
class USceneCaptureComponent2D;
class UTextureRenderTarget2D;
class FJsonObject;
class AYIXIT01FocusRig;
class AYIXIT01ViewCamera;
class AYIXIT01L01LightingRig;
class ALevelSequenceActor;
class UMaterialInterface;
class UStaticMeshComponent;
class ULightComponentBase;
class SWidget;
class IInputProcessor;

UENUM(BlueprintType)
enum class EYIXIT01FocusState : uint8
{
    Explore, FocusEnter, FocusHold, MatchCut, FocusExit, ExploreNight, FocusReturn, Failed
};

// No editor-Python runtime dependency. No Level load/unload calls in this Actor.
UCLASS(Blueprintable)
class YIXIT00_API AYIXIT00TransitionController : public AActor
{
    GENERATED_BODY()
public:
    AYIXIT00TransitionController();
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void EndPlay(const EEndPlayReason::Type Reason) override;
    UFUNCTION(BlueprintCallable, Category="YIXI Tests|T00") void TriggerTransition();
    UFUNCTION(BlueprintCallable, Category="YIXI Tests|T00") static FString InspectWorld(UWorld* World);
    UPROPERTY(EditInstanceOnly, Category="T01") TObjectPtr<AYIXIT01FocusRig> FocusRig;
    // Formal maps use native light actors and the existing Sequencer player.
    // Null keeps the frozen L01 regression maps on their existing path.
    UPROPERTY(EditInstanceOnly, Category="T01|Sequencer") TObjectPtr<ALevelSequenceActor> LightStateSequence;
    UPROPERTY(EditInstanceOnly, Category="T01|Diagnostics") TObjectPtr<UMaterialInterface> DiagnosticLitMaterial;
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="T01|Sequencer") int32 LightingSequenceFrame = -1;
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="T01|Sequencer") FString LightingBindingReport;
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="T01") EYIXIT01FocusState FocusState = EYIXIT01FocusState::Explore;
    bool HandleFocusEscapeFromViewport();
    UPROPERTY(EditAnywhere, Category="T00") float WarmupSeconds = 2.f;
    UPROPERTY(EditAnywhere, Category="T00") float DayHoldSeconds = 1.25f;
    UPROPERTY(EditAnywhere, Category="T00") float NightHoldSeconds = 1.25f;
    UPROPERTY(EditAnywhere, Category="T00") float PostMeasureSeconds = 5.f;
private:
    enum class EPhase { Warming, Ready, Day, AwaitCut, Night, AwaitTeleport, Settling, AwaitRestore, Post, Done };
    EPhase Phase = EPhase::Warming;
    UPROPERTY(Transient) TObjectPtr<APlayerController> PC;
    UPROPERTY(Transient) TObjectPtr<APawn> TestPawn;
    UPROPERTY(Transient) TObjectPtr<UGameplayCameraComponentBase> GameplayCamera;
    UPROPERTY(Transient) TObjectPtr<UMoverComponent> Mover;
    UPROPERTY(Transient) TObjectPtr<ACameraActor> CameraA;
    UPROPERTY(Transient) TObjectPtr<ACameraActor> CameraB;
    UPROPERTY(Transient) TObjectPtr<AYIXIT01L01LightingRig> L01LightingRig;
    UPROPERTY(Transient) TArray<TObjectPtr<UStaticMeshComponent>> DiagnosticMeshes;
    UPROPERTY(Transient) TArray<TObjectPtr<UMaterialInterface>> DiagnosticOriginalMaterials;
    UPROPERTY(Transient) TArray<TObjectPtr<ULightComponentBase>> DiagnosticSuppressedLights;
    TArray<bool> DiagnosticOriginalVisibility;
    UPROPERTY(Transient) TObjectPtr<AActor> Destination;
    UPROPERTY(Transient) TArray<TObjectPtr<USceneCaptureComponent2D>> Captures;
    UPROPERTY(Transient) TArray<TObjectPtr<UTextureRenderTarget2D>> RenderTargets;
    UPROPERTY(Transient) TArray<TObjectPtr<UObject>> SavedInputProducers;
    TArray<TSharedPtr<FJsonObject>> Frames;
    TArray<TSharedPtr<FJsonObject>> Events;
    FRenderCommandFence WarmupFence;
    bool bFenceStarted = false, bInputHeld = false, bReportWritten = false, bTeleportConfirmed = false;
    int32 WarmupFrames = 0;
    int32 TeleportReadbackFrames = 0;
    double StartedAt = 0, LastTickAt = 0, PhaseAt = 0, CutAt = -1, RestoredAt = -1;
    FVector TargetLocation = FVector::ZeroVector, PostStartLocation = FVector::ZeroVector;
    uint64 CutObservedFrame = 0;
    FString PawnAtTrigger;
    FString LastWaitingReason;
    bool bSublevelsReported = false;
    TSharedPtr<FJsonObject> Result;
    UPROPERTY(Transient) TObjectPtr<AYIXIT01ViewCamera> FocusViewCamera;
    UPROPERTY(Transient) TObjectPtr<AActor> FocusTarget;
    TSharedPtr<SWidget> FocusPromptWidget;
    TSharedPtr<IInputProcessor> FocusEscapeProcessor;
    FMinimalViewInfo FocusStartView, FocusEndView;
    FVector FocusControlPoint = FVector::ZeroVector;
    FVector EnterControlPoint = FVector::ZeroVector;
    double FocusAt = 0, HandoffAt = 0;
    int32 FrameWriteIndex = 0;
    bool bInteractionKeyDown = false, bConfirmArmed = false, bFocusRequested = false;
    bool bInteractiveTransition = false, bAwaitingHandoff = false, bSessionEnding = false;
    bool bEntryCameraSamplePending = false;
    void HoldInput();
    bool SetupFocusInteraction(FString& Reason);
    void ShutdownFocusInteraction();
    void InteractionPressed();
    void InteractionReleased();
    void CancelFocus();
    bool TickFocus(double Now, float DeltaSeconds);
    void BeginFocusEnter();
    void BeginFocusReturn(bool bNight);
    bool ReadGameplayView(FMinimalViewInfo& View, FString& Reason) const;
    bool SafeCameraSegment(const FVector& Start, const FVector& End, FString& Reason) const;
    bool ValidateFocusPath(const FMinimalViewInfo& Start, const FMinimalViewInfo& End, const FVector& Control, FString& Reason) const;
    void FocusFailure(const FString& Reason);
    void SetFocusState(EYIXIT01FocusState State);
    FString FocusStateName() const;
    bool ResolveTestActors();
    bool PrepareSequenceTransition(FString& Reason);
    bool ApplySequenceLightingFrame(int32 Frame, FString& Reason);
    TSharedRef<FJsonObject> SequenceLightingDiagnostics() const;
    void RestoreSequenceDiagnostics();
    bool ScenesReady(FString* Reason = nullptr) const;
    bool SamePossession() const;
    void PrimeViews();
    void HardCut(ACameraActor* Camera);
    void RestoreInput();
    void RestoreCamera();
    void Event(const FString& Name);
    void ReportWaiting(const FString& Reason);
    void Finish(bool bFunctional, const FString& Reason);
    FString PhaseName() const;
    UFUNCTION() void Teleported(const FVector& FromLocation, const FQuat& FromRotation,
                              const FVector& ToLocation, const FQuat& ToRotation);
};
