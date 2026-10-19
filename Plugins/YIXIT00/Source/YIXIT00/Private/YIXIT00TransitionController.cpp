#include "YIXIT00TransitionController.h"
#include "YIXIT01FocusRig.h"
#include "YIXIT01L01LightingRig.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/StaticMeshComponent.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/SkyLightComponent.h"
#include "Materials/MaterialInterface.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "MovieScene.h"
#include "MovieScenePossessable.h"
#include "Core/CameraAsset.h"
#include "Dom/JsonObject.h"
#include "Engine/GameViewportClient.h"
#include "Engine/LevelStreaming.h"
#include "Engine/LevelStreamingAlwaysLoaded.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/World.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/WorldSettings.h"
#include "GameFramework/GameplayCameraComponent.h"
#include "HAL/FileManager.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FileHelper.h"
#include "Misc/DateTime.h"
#include "Misc/Guid.h"
#include "Misc/Paths.h"
#include "MoverComponent.h"
#include "DefaultMovementSet/InstantMovementEffects/BasicInstantMovementEffects.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIT00, Log, All);
static const TCHAR* PawnClassPath = TEXT("/Game/Blueprints/SandboxCharacter_Mover_Ragdoll.SandboxCharacter_Mover_Ragdoll_C");
static const TCHAR* PCClassPath = TEXT("/Game/Blueprints/PC_Sandbox.PC_Sandbox_C");
static const TCHAR* GMClassPath = TEXT("/Game/Blueprints/GM_Sandbox_Ragdoll.GM_Sandbox_Ragdoll_C");
static TArray<TSharedPtr<FJsonValue>> XYZ(const FVector& V)
{
    return { MakeShared<FJsonValueNumber>(V.X), MakeShared<FJsonValueNumber>(V.Y), MakeShared<FJsonValueNumber>(V.Z) };
}
static FString Encode(const TSharedRef<FJsonObject>& Object)
{
    FString Text;
    FJsonSerializer::Serialize(Object, TJsonWriterFactory<>::Create(&Text));
    return Text;
}

FString AYIXIT00TransitionController::InspectWorld(UWorld* World)
{
    TSharedRef<FJsonObject> Info = MakeShared<FJsonObject>();
    Info->SetBoolField(TEXT("valid_world"), IsValid(World));
    if (!World) return Encode(Info);
    Info->SetStringField(TEXT("world"), World->GetPathName());
    Info->SetBoolField(TEXT("world_partition"), World->IsPartitionedWorld());
    TArray<TSharedPtr<FJsonValue>> Streams;
    for (ULevelStreaming* Level : World->GetStreamingLevels())
    {
        if (!Level) continue;
        auto Item = MakeShared<FJsonObject>();
        Item->SetStringField(TEXT("package"), Level->GetWorldAssetPackageName());
        Item->SetStringField(TEXT("class"), Level->GetClass()->GetPathName());
        Item->SetBoolField(TEXT("loaded"), Level->IsLevelLoaded());
        Item->SetBoolField(TEXT("visible"), Level->IsLevelVisible());
        Streams.Add(MakeShared<FJsonValueObject>(Item));
    }
    Info->SetArrayField(TEXT("streaming_levels"), Streams);
    const AWorldSettings* Settings = World->GetWorldSettings();
    UClass* GM = Settings ? Settings->DefaultGameMode.Get() : nullptr;
    const AGameModeBase* Defaults = GM ? GM->GetDefaultObject<AGameModeBase>() : nullptr;
    Info->SetStringField(TEXT("game_mode"), GetPathNameSafe(GM));
    Info->SetStringField(TEXT("default_pawn"), Defaults ? GetPathNameSafe(Defaults->DefaultPawnClass.Get()) : TEXT("UNAVAILABLE"));
    Info->SetStringField(TEXT("player_controller"), Defaults ? GetPathNameSafe(Defaults->PlayerControllerClass.Get()) : TEXT("UNAVAILABLE"));
    return Encode(Info);
}

AYIXIT00TransitionController::AYIXIT00TransitionController()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.TickGroup = TG_PostUpdateWork; // Observe completed camera update, not only requested ViewTarget.
}
void AYIXIT00TransitionController::BeginPlay()
{
    Super::BeginPlay();
    StartedAt = LastTickAt = PhaseAt = FPlatformTime::Seconds();
    Result = MakeShared<FJsonObject>();
    Result->SetStringField(TEXT("utc_started"), FDateTime::UtcNow().ToIso8601());
    Result->SetStringField(TEXT("world"), GetWorld()->GetPathName());
    Result->SetStringField(TEXT("net_mode"), GetNetMode() == NM_Standalone ? TEXT("StandaloneWorld") : TEXT("OTHER"));
#if WITH_EDITOR
    Result->SetStringField(TEXT("world_type"), GetWorld()->WorldType == EWorldType::PIE ? TEXT("PIE") : TEXT("Game/Standalone"));
#else
    Result->SetStringField(TEXT("world_type"), TEXT("Game/Packaged"));
#endif
    Result->SetStringField(TEXT("frame_time_scope"), TEXT("Wall-clock interval between post-camera game-thread ticks; NOT GPU timestamps or proof of zero hitch."));
    Event(TEXT("BeginPlay"));
    Event(TEXT("T00_CONTROLLER_BEGINPLAY"));
}
FString AYIXIT00TransitionController::PhaseName() const
{
    static const TCHAR* Names[] = {TEXT("Warming"),TEXT("Ready"),TEXT("Day"),TEXT("AwaitCut"),TEXT("Night"),TEXT("AwaitTeleport"),TEXT("Settling"),TEXT("AwaitRestore"),TEXT("Post"),TEXT("Done")};
    return Names[static_cast<int32>(Phase)];
}
bool AYIXIT00TransitionController::ScenesReady(FString* Reason) const
{
    const auto& Streams = GetWorld()->GetStreamingLevels();
    if (Streams.Num() != 2 || GetWorld()->IsPartitionedWorld())
    {
        if (Reason) *Reason = FString::Printf(TEXT("Expected two non-WP sublevels; count=%d partitioned=%d"), Streams.Num(), GetWorld()->IsPartitionedWorld());
        return false;
    }
    bool Day = false, Night = false;
    for (ULevelStreaming* Stream : Streams)
    {
        if (!Stream || !Stream->IsA<ULevelStreamingAlwaysLoaded>() || !Stream->IsLevelLoaded() || !Stream->IsLevelVisible())
        {
            if (Reason) *Reason = FString::Printf(TEXT("Sublevel not ready: package=%s class=%s loaded=%d visible=%d"),
                Stream ? *Stream->GetWorldAssetPackageName() : TEXT("NULL"),
                Stream ? *Stream->GetClass()->GetPathName() : TEXT("NULL"),
                Stream && Stream->IsLevelLoaded(), Stream && Stream->IsLevelVisible());
            return false;
        }
        Day |= Stream->GetWorldAssetPackageName().EndsWith(TEXT("L_YIXI_T00_Day"));
        Night |= Stream->GetWorldAssetPackageName().EndsWith(TEXT("L_YIXI_T00_Night"));
    }
    if (Reason && !(Day && Night)) *Reason = TEXT("Expected T00 Day/Night package names not found");
    return Day && Night;
}
void AYIXIT00TransitionController::ReportWaiting(const FString& Reason)
{
    if (LastWaitingReason != Reason)
    {
        LastWaitingReason = Reason;
        UE_LOG(LogYIXIT00, Display, TEXT("[YIXI_T00] T00_WAITING phase=%s reason=%s"), *PhaseName(), *Reason);
    }
}
bool AYIXIT00TransitionController::SamePossession() const
{
    return IsValid(PC) && IsValid(TestPawn) && PC->GetPawn() == TestPawn && TestPawn->GetController() == PC;
}
bool AYIXIT00TransitionController::ResolveTestActors()
{
    PC = UGameplayStatics::GetPlayerController(this, 0);
    if (!PC || !PC->GetPawn())
    {
        ReportWaiting(PC ? TEXT("PlayerController has no possessed Pawn yet") : TEXT("Local PlayerController 0 not available yet"));
        return false;
    }
    TestPawn = PC->GetPawn();
    const auto* GM = GetWorld()->GetAuthGameMode();
    if (!GM || GM->GetClass()->GetPathName() != GMClassPath || PC->GetClass()->GetPathName() != PCClassPath || TestPawn->GetClass()->GetPathName() != PawnClassPath)
    { Finish(false, FString::Printf(TEXT("Effective configuration mismatch: GameMode=%s Pawn=%s Controller=%s"),
        GM ? *GM->GetClass()->GetPathName() : TEXT("NULL"), *TestPawn->GetClass()->GetPathName(), *PC->GetClass()->GetPathName())); return false; }
    GameplayCamera = TestPawn->FindComponentByClass<UGameplayCameraComponentBase>();
    Mover = TestPawn->FindComponentByClass<UMoverComponent>();
    auto Find = [this](FName Tag)->AActor*
    {
        TArray<AActor*> Found; UGameplayStatics::GetAllActorsWithTag(this, Tag, Found);
        return Found.Num() == 1 ? Found[0] : nullptr;
    };
    CameraA = Cast<ACameraActor>(Find(TEXT("T00_CameraA")));
    CameraB = Cast<ACameraActor>(Find(TEXT("T00_CameraB")));
    Destination = Find(TEXT("T00_Destination"));
    if (!GameplayCamera || !GameplayCamera->IsActive() || !Mover || !CameraA || !CameraB || !Destination)
    { Finish(false, FString::Printf(TEXT("Required references not ready: CameraA=%s CameraB=%s Destination=%s GameplayCamera=%s active=%d Mover=%s; check unique T00 tags"),
        *GetPathNameSafe(CameraA.Get()), *GetPathNameSafe(CameraB.Get()), *GetPathNameSafe(Destination.Get()),
        *GetPathNameSafe(GameplayCamera.Get()), GameplayCamera && GameplayCamera->IsActive(), *GetPathNameSafe(Mover.Get()))); return false; }
    Event(TEXT("T00_CAMERA_REFERENCES_READY"));
    Event(TEXT("T00_PAWN_READY"));
    Result->SetStringField(TEXT("pawn"), TestPawn->GetPathName());
    Result->SetStringField(TEXT("controller"), PC->GetPathName());
    Result->SetStringField(TEXT("gameplay_camera"), GameplayCamera->GetPathName());
    Result->SetArrayField(TEXT("camera_a_location"), XYZ(CameraA->GetActorLocation()));
    Result->SetArrayField(TEXT("camera_b_location"), XYZ(CameraB->GetActorLocation()));
    Result->SetStringField(TEXT("camera_a_actor"),CameraA->GetPathName());
    Result->SetStringField(TEXT("camera_b_actor"),CameraB->GetPathName());
    Result->SetNumberField(TEXT("camera_a_fov"),CameraA->GetCameraComponent()->FieldOfView);
    Result->SetNumberField(TEXT("camera_b_fov"),CameraB->GetCameraComponent()->FieldOfView);
    if (const auto* Camera = Cast<UGameplayCameraComponent>(GameplayCamera))
        Result->SetStringField(TEXT("camera_asset"), GetPathNameSafe(Camera->CameraReference.GetCameraAsset()));
    Mover->OnTeleportSucceeded.AddUniqueDynamic(this, &AYIXIT00TransitionController::Teleported);
    EnableInput(PC);
    if (!InputComponent) { Finish(false, TEXT("EnableInput did not create a T00 InputComponent")); return false; }
    InputComponent->BindKey(EKeys::T, IE_Pressed, this, &AYIXIT00TransitionController::TriggerTransition);
    Event(TEXT("T00_INPUT_BOUND"));
    FString FocusReason;
    if (!SetupFocusInteraction(FocusReason)) { Finish(false, FocusReason); return false; }
    if (LightStateSequence)
    {
        if (!PrepareSequenceTransition(FocusReason)) { Finish(false,FocusReason); return false; }
        Event(TEXT("T01_NATIVE_SEQUENCE_READY"));
    }
    else
    {
        TArray<AActor*> LightingRigs;
        UGameplayStatics::GetAllActorsOfClass(this,AYIXIT01L01LightingRig::StaticClass(),LightingRigs);
        if (LightingRigs.Num()>1) { Finish(false,TEXT("Multiple L01 lighting rigs; keep scene and resolve manually")); return false; }
        if (LightingRigs.Num()==1)
        {
            L01LightingRig=Cast<AYIXIT01L01LightingRig>(LightingRigs[0]);
            if (!L01LightingRig->Prepare(PC,FocusReason)) { Finish(false,FocusReason); return false; }
            L01LightingRig->AddTickPrerequisiteActor(this);
            Event(TEXT("T01_L01_LIGHTING_READY"));
        }
    }
    PrimeViews();
    return true;
}
bool AYIXIT00TransitionController::ApplySequenceLightingFrame(int32 Frame,FString& Reason)
{
    auto* Player=LightStateSequence ? LightStateSequence->GetSequencePlayer() : nullptr;
    auto* Sequence=LightStateSequence ? LightStateSequence->GetSequence() : nullptr;
    auto* Scene=Sequence ? Sequence->GetMovieScene() : nullptr;
    if (!Player || !Scene || Scene->GetPossessableCount()==0 || Scene->GetSpawnableCount()!=0)
    { Reason=TEXT("T01 needs the existing initialized lighting SequencePlayer and local possessables"); return false; }
    TArray<TSharedPtr<FJsonValue>> Bindings;
    for (int32 I=0;I<Scene->GetPossessableCount();++I)
    {
        const auto& P=Scene->GetPossessable(I);
        const FMovieSceneObjectBindingID ID(UE::MovieScene::FFixedObjectBindingID(P.GetGuid(),MovieSceneSequenceID::Root));
        const auto Objects=Player->GetBoundObjects(ID);
        if (Objects.Num()!=1 || !Objects[0] || Objects[0]->GetWorld()!=GetWorld())
        { Reason=TEXT("T01 lighting binding is not unique and World-local: ")+P.GetName(); return false; }
        if (Objects[0]->IsA<AYIXIT01L01LightingRig>() || Objects[0]->GetTypedOuter<AYIXIT01L01LightingRig>())
        { Reason=TEXT("T01 lighting still targets a retired L01 rig: ")+P.GetName(); return false; }
        auto Item=MakeShared<FJsonObject>();
        Item->SetStringField(TEXT("binding"),P.GetName());
        Item->SetStringField(TEXT("target"),Objects[0]->GetPathName());
        Bindings.Add(MakeShared<FJsonValueObject>(Item));
    }
    auto Info=MakeShared<FJsonObject>();
    Info->SetStringField(TEXT("sequence"),Sequence->GetPathName());
    Info->SetArrayField(TEXT("bindings"),Bindings);
    LightingBindingReport=Encode(Info);
    Player->SetCompletionModeOverride(EMovieSceneCompletionModeOverride::ForceKeepState);
    Player->Pause();
    FMovieSceneSequencePlaybackParams Params(FFrameTime(Frame),EUpdatePositionMethod::Jump);
    Params.bHasJumped=true;
    Player->SetPlaybackPosition(Params);
    if (Player->IsPlaying() || Player->GetCurrentTime().Time.FrameNumber.Value!=Frame)
    { Reason=TEXT("T01 lighting player failed to hold the requested frame"); return false; }
    LightingSequenceFrame=Frame;
    UE_LOG(LogYIXIT00,Display,TEXT("[YIXI_T01] NATIVE_SEQUENCE_JUMP frame=%d engine_frame=%llu player=%s L01=UNUSED"),
        Frame,GFrameCounter,*Player->GetPathName());
    return true;
}
bool AYIXIT00TransitionController::PrepareSequenceTransition(FString& Reason)
{
    if (!DiagnosticLitMaterial || DiagnosticLitMaterial->GetShadingModels().HasShadingModel(MSM_Unlit))
    { Reason=TEXT("T01 diagnostic material must be the existing preloaded lit material"); return false; }
    TArray<UStaticMeshComponent*> Targets;
    for (const TCHAR* Tag : {TEXT("T00_FloorA"),TEXT("T00_BackdropA"),TEXT("T00_BodyA"),TEXT("T00_HeadA"),
                             TEXT("T00_FloorB"),TEXT("T00_BackdropB"),TEXT("T00_BodyB"),TEXT("T00_HeadB")})
    {
        TArray<AActor*> Found; UGameplayStatics::GetAllActorsWithTag(this,FName(Tag),Found);
        auto* Mesh=Found.Num()==1 ? Found[0]->FindComponentByClass<UStaticMeshComponent>() : nullptr;
        if (!Mesh || Mesh->GetNumMaterials()!=1)
        { Reason=FString::Printf(TEXT("T01 expected one diagnostic mesh for %s"),Tag); return false; }
        Targets.Add(Mesh);
    }
    TArray<AActor*> Actors; UGameplayStatics::GetAllActorsOfClass(this,AActor::StaticClass(),Actors);
    for (AActor* Actor : Actors)
    {
        TArray<ULightComponentBase*> Lights; Actor->GetComponents(Lights);
        for (auto* Light : Lights)
        {
            if (!(Light->IsA<UDirectionalLightComponent>() || Light->IsA<USkyLightComponent>()) || !Light->IsVisible()) continue;
            if (Actor->ActorHasTag(TEXT("YIXI_SequenceLight"))) continue;
            if (!Actor->ActorHasTag(TEXT("T00_TestLight")) || !Light->IsA<UDirectionalLightComponent>())
            { Reason=TEXT("T01 found an uncontrolled global light: ")+Light->GetPathName(); return false; }
            DiagnosticSuppressedLights.Add(Light); DiagnosticOriginalVisibility.Add(Light->IsVisible());
        }
    }
    if (!ApplySequenceLightingFrame(0,Reason)) return false;
    for (const auto& Light : DiagnosticSuppressedLights) Light->SetVisibility(false);
    for (auto* Mesh : Targets)
    { DiagnosticMeshes.Add(Mesh); DiagnosticOriginalMaterials.Add(Mesh->GetMaterial(0)); Mesh->SetMaterial(0,DiagnosticLitMaterial); }
    return true;
}
TSharedRef<FJsonObject> AYIXIT00TransitionController::SequenceLightingDiagnostics() const
{
    auto Info=MakeShared<FJsonObject>();
    Info->SetBoolField(TEXT("legacy_rig_used"),L01LightingRig!=nullptr);
    Info->SetNumberField(TEXT("sequence_frame"),LightingSequenceFrame);
    Info->SetStringField(TEXT("binding_report"),LightingBindingReport);
    Info->SetNumberField(TEXT("diagnostic_material_overrides"),DiagnosticMeshes.Num());
    Info->SetBoolField(TEXT("playing"),LightStateSequence && LightStateSequence->GetSequencePlayer() && LightStateSequence->GetSequencePlayer()->IsPlaying());
    return Info;
}
void AYIXIT00TransitionController::RestoreSequenceDiagnostics()
{
    const int32 Expected=DiagnosticMeshes.Num();
    int32 Restored=0;
    for (int32 I=0;I<Expected;++I)
        if (IsValid(DiagnosticMeshes[I]))
        { DiagnosticMeshes[I]->SetMaterial(0,DiagnosticOriginalMaterials[I]); if (DiagnosticMeshes[I]->GetMaterial(0)==DiagnosticOriginalMaterials[I]) ++Restored; }
    for (int32 I=0;I<DiagnosticSuppressedLights.Num();++I)
        if (IsValid(DiagnosticSuppressedLights[I])) DiagnosticSuppressedLights[I]->SetVisibility(DiagnosticOriginalVisibility[I]);
    DiagnosticMeshes.Reset(); DiagnosticOriginalMaterials.Reset(); DiagnosticSuppressedLights.Reset(); DiagnosticOriginalVisibility.Reset();
    if (Expected==0) return;
    auto Info=MakeShared<FJsonObject>();
    Info->SetStringField(TEXT("world"),GetPathNameSafe(GetWorld()));
    Info->SetNumberField(TEXT("expected"),Expected); Info->SetNumberField(TEXT("restored"),Restored);
    const FString Path=FPaths::Combine(FPaths::ProjectSavedDir(),TEXT("YIXI/Reports/YIXI_T01_MATERIAL_RESTORE_")+FGuid::NewGuid().ToString(EGuidFormats::Digits)+TEXT(".json"));
    FFileHelper::SaveStringToFile(Encode(Info),*Path,FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM,&IFileManager::Get(),FILEWRITE_NoReplaceExisting);
    UE_LOG(LogYIXIT00,Display,TEXT("[YIXI_T01] DIAGNOSTIC_MATERIALS_RESTORED %d/%d JSON=%s"),Restored,Expected,*Path);
}
void AYIXIT00TransitionController::PrimeViews()
{
    for (ACameraActor* Camera : {CameraA.Get(), CameraB.Get()})
    {
        auto* Target = NewObject<UTextureRenderTarget2D>(this, NAME_None, RF_Transient);
        Target->RenderTargetFormat = RTF_RGBA8;
        Target->InitAutoFormat(640, 360); RenderTargets.Add(Target);
        auto* Capture = NewObject<USceneCaptureComponent2D>(this, NAME_None, RF_Transient);
        Capture->SetupAttachment(RootComponent); Capture->TextureTarget = Target;
        Capture->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
        Capture->bCaptureEveryFrame = false; Capture->bCaptureOnMovement = false;
        Capture->bAlwaysPersistRenderingState = true;
        Capture->FOVAngle = Camera->GetCameraComponent()->FieldOfView;
        Capture->RegisterComponent(); Capture->SetWorldTransform(Camera->GetActorTransform());
        Captures.Add(Capture);
    }
}
void AYIXIT00TransitionController::Event(const FString& Name)
{
    auto Row = MakeShared<FJsonObject>();
    Row->SetStringField(TEXT("name"), Name); Row->SetNumberField(TEXT("t_seconds"), FPlatformTime::Seconds()-StartedAt);
    Row->SetNumberField(TEXT("frame"), static_cast<double>(GFrameCounter));
    Row->SetStringField(TEXT("phase"), PhaseName());
    Row->SetStringField(TEXT("focus_state"), FocusStateName());
    Row->SetBoolField(TEXT("same_possession"), SamePossession());
    Row->SetStringField(TEXT("view_target"), PC ? GetPathNameSafe(PC->GetViewTarget()) : TEXT("UNAVAILABLE"));
    if (PC && PC->PlayerCameraManager)
    {
        Row->SetBoolField(TEXT("native_camera_cut_flag"),PC->PlayerCameraManager->bGameCameraCutThisFrame);
        Row->SetArrayField(TEXT("camera_cache_location"),XYZ(PC->PlayerCameraManager->GetCameraLocation()));
    }
    if (TestPawn) Row->SetArrayField(TEXT("pawn_location"), XYZ(TestPawn->GetActorLocation()));
    Events.Add(Row);
    UE_LOG(LogYIXIT00, Display, TEXT("[YIXI_T00] %s frame=%llu t=%.3f"), *Name, GFrameCounter, FPlatformTime::Seconds()-StartedAt);
}
void AYIXIT00TransitionController::HardCut(ACameraActor* Camera)
{
    FViewTargetTransitionParams Cut; Cut.BlendTime = 0.f;
    PC->SetViewTarget(Camera, Cut);
    if (PC->PlayerCameraManager) PC->PlayerCameraManager->SetGameCameraCutThisFrame();
}
void AYIXIT00TransitionController::TriggerTransition()
{
    Event(TEXT("T00_TRIGGER_RECEIVED"));
    if (FocusState != EYIXIT01FocusState::Explore)
    { Event(TEXT("T00_DEBUG_IGNORED_DURING_INTERACTION")); return; }
    if (Phase != EPhase::Ready) { UE_LOG(LogYIXIT00, Display, TEXT("[YIXI_T00] Not ready/already used; wait READY, or restart play for another run.")); return; }
    if (!ScenesReady() || !SamePossession()) { Finish(false,TEXT("Scenes/possession not ready at trigger")); return; }
    HoldInput();
    Phase = EPhase::Day; PhaseAt = FPlatformTime::Seconds();
    Event(TEXT("TriggerInputLocked")); HardCut(CameraA); Event(TEXT("DayCloseupRequested"));
}
void AYIXIT00TransitionController::HoldInput()
{
    if (bInputHeld) return;
    PawnAtTrigger = TestPawn->GetPathName();
    PC->SetIgnoreMoveInput(true); PC->SetIgnoreLookInput(true);
    TestPawn->DisableInput(PC); bInputHeld = true;
    // Neutral Mover input during the closeups, including cached Blueprint input.
    // Only this live instance changes; restore the exact producer list below.
    SavedInputProducers=Mover->InputProducers; Mover->InputProducers.Reset();
    auto Stop=MakeShared<FApplyVelocityEffect>(); Stop->VelocityToApply=FVector::ZeroVector; Stop->bAdditiveVelocity=false;
    Mover->QueueInstantMovementEffect(Stop);
}
void AYIXIT00TransitionController::Teleported(const FVector&, const FQuat&, const FVector&, const FQuat&)
{
    if (Phase != EPhase::AwaitTeleport) return;
    bTeleportConfirmed = true;
    PC->SetControlRotation(Destination->GetActorRotation());
    Event(TEXT("MoverTeleportEventReceived"));
}
void AYIXIT00TransitionController::RestoreInput()
{
    if (!bInputHeld) return;
    if (Mover) { Mover->InputProducers=SavedInputProducers; SavedInputProducers.Reset(); }
    if (PC)
    {
        PC->SetIgnoreMoveInput(false); PC->SetIgnoreLookInput(false);
        if (TestPawn) TestPawn->EnableInput(PC);
    }
    bInputHeld = false;
}
void AYIXIT00TransitionController::RestoreCamera()
{
    if (GameplayCamera && PC && SamePossession())
    {
        GameplayCamera->ActivateCameraForPlayerController(PC, true);
        if (PC->PlayerCameraManager) PC->PlayerCameraManager->SetGameCameraCutThisFrame();
    }
}
void AYIXIT00TransitionController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    const double Now = FPlatformTime::Seconds();
    if (Phase == EPhase::Done) return;
    auto Frame = MakeShared<FJsonObject>();
    Frame->SetNumberField(TEXT("frame"), static_cast<double>(GFrameCounter));
    Frame->SetNumberField(TEXT("t_seconds"), Now-StartedAt);
    Frame->SetNumberField(TEXT("frame_interval_ms"), (Now-LastTickAt)*1000.0);
    Frame->SetStringField(TEXT("phase"), PhaseName()); LastTickAt = Now;
    if (PC) Frame->SetStringField(TEXT("view_target"),GetPathNameSafe(PC->GetViewTarget()));
    if (PC && PC->PlayerCameraManager)
        Frame->SetArrayField(TEXT("camera_location"), XYZ(PC->PlayerCameraManager->GetCameraLocation()));
    if (TestPawn) Frame->SetArrayField(TEXT("pawn_location"), XYZ(TestPawn->GetActorLocation()));
    Frame->SetStringField(TEXT("focus_state"), FocusStateName());
    if (Frames.Num() < 20000) Frames.Add(Frame);
    else { Frames[FrameWriteIndex] = Frame; FrameWriteIndex = (FrameWriteIndex+1)%20000; }
    // Observation/exploration have no countdown. Keep telemetry bounded instead
    // of terminating FocusHold after the old 180-second T00 sample limit.
    if (Phase == EPhase::Warming && Now-StartedAt > 180) { Finish(false,TEXT("Initialization timed out after 180 seconds")); return; }
    if (Phase == EPhase::Warming)
    {
        FString WaitingReason;
        if (!ScenesReady(&WaitingReason)) { ReportWaiting(WaitingReason); return; }
        if (!bSublevelsReported) { bSublevelsReported = true; Event(TEXT("T00_SUBLEVELS_READY")); }
        if (!TestPawn && !ResolveTestActors()) return;
        if (Phase == EPhase::Done) return;
        if (!bFenceStarted)
        {
            ReportWaiting(TEXT("Render prewarm pending: at least 30 frames and WarmupSeconds"));
            for (auto Capture : Captures) Capture->CaptureScene();
            ++WarmupFrames;
            if (WarmupFrames >= 30 && Now-StartedAt >= WarmupSeconds) { WarmupFence.BeginFence(); bFenceStarted = true; }
        }
        else if (WarmupFence.IsFenceComplete())
        { Phase = EPhase::Ready; PhaseAt = Now; Event(TEXT("T00_READY")); Event(TEXT("READY_press_T_after_2_seconds_baseline")); }
        else ReportWaiting(TEXT("Render-thread prewarm fence pending"));
        return;
    }
    if (!ScenesReady() || !SamePossession()) { Finish(false,TEXT("Streaming/possession changed during test")); return; }
    if (TickFocus(Now, DeltaSeconds)) return;
    if ((Phase==EPhase::Night || Phase==EPhase::AwaitTeleport || Phase==EPhase::Settling) && PC->GetViewTarget()!=CameraB)
    { Finish(false,TEXT("Night closeup shielding ViewTarget lost")); return; }
    if (Phase == EPhase::Day && Now-PhaseAt >= DayHoldSeconds)
    {
        if (!PC->PlayerCameraManager || PC->GetViewTarget()!=CameraA || FVector::Dist(PC->PlayerCameraManager->GetCameraLocation(),CameraA->GetActorLocation())>1.0)
        { Finish(false,TEXT("Day Camera_A was not the actual camera before cut")); return; }
        Event(TEXT("DayCloseupObserved"));
        HardCut(CameraB); Phase=EPhase::AwaitCut; PhaseAt=Now; CutAt=Now; Event(TEXT("CameraCutRequested"));
    }
    else if (Phase == EPhase::AwaitCut)
    {
        if (PC->GetViewTarget()==CameraB && PC->PlayerCameraManager && FVector::Dist(PC->PlayerCameraManager->GetCameraLocation(),CameraB->GetActorLocation())<1.0)
        {
            // Actual Camera_B cache is now confirmed, rather than the earlier cut request.
            if (LightStateSequence)
            {
                FString LightingReason;
                if (!ApplySequenceLightingFrame(30,LightingReason)) { Finish(false,LightingReason); return; }
                Event(TEXT("T01_NATIVE_SEQUENCE_CUT_OBSERVED"));
            }
            else if (L01LightingRig)
            {
                if (!L01LightingRig->CameraBCutObserved()) { Finish(false,TEXT("P03 Sequence frame 30 failed; see lighting diagnostic")); return; }
                Event(L01LightingRig->bSequenceOwnsLighting ? TEXT("T01_P03_SEQUENCE_CUT_OBSERVED") : TEXT("T01_L01_CUT_OBSERVED"));
            }
            Phase=EPhase::Night; PhaseAt=Now; CutObservedFrame=GFrameCounter; Event(TEXT("CameraCutObserved")); Event(TEXT("T00_CAMERA_CUT"));
        }
        else if (Now-PhaseAt>2) Finish(false,TEXT("Hard cut did not reach Camera_B; possible camera ownership conflict"));
    }
    else if (Phase == EPhase::Night && GFrameCounter>CutObservedFrame)
    {
        auto* Capsule=TestPawn->FindComponentByClass<UCapsuleComponent>();
        if (!Capsule || TestPawn->GetRootComponent()!=Capsule) { Finish(false,TEXT("Live root Capsule missing")); return; }
        TargetLocation=Destination->GetActorLocation()+FVector(0,0,Capsule->GetScaledCapsuleHalfHeight()+10);
        auto Teleport=MakeShared<FTeleportEffect>(); Teleport->TargetLocation=TargetLocation;
        Teleport->bUseActorRotation=false; Teleport->TargetRotation=Destination->GetActorRotation();
        PC->SetControlRotation(Destination->GetActorRotation());
        Phase=EPhase::AwaitTeleport; PhaseAt=Now;
        Mover->QueueInstantMovementEffect(Teleport);
        auto Stop=MakeShared<FApplyVelocityEffect>(); Stop->VelocityToApply=FVector::ZeroVector; Stop->bAdditiveVelocity=false;
        Mover->QueueInstantMovementEffect(Stop); Event(TEXT("MoverTeleportQueuedWhileCameraB"));
    }
    else if (Phase == EPhase::AwaitTeleport)
    {
        if (PC->GetViewTarget()!=CameraB) { Finish(false,TEXT("Teleport shielding camera lost")); return; }
        const bool bAtTarget=FVector::Dist2D(TestPawn->GetActorLocation(),TargetLocation)<20
            && FMath::Abs(TestPawn->GetActorLocation().Z-TargetLocation.Z)<30;
        TeleportReadbackFrames=bAtTarget?TeleportReadbackFrames+1:0;
        if (bAtTarget && (bTeleportConfirmed || TeleportReadbackFrames>=2))
        {
            if (FVector::Dist2D(TestPawn->GetActorLocation(),TargetLocation)>20 || TestPawn->GetPathName()!=PawnAtTrigger)
            { Finish(false,TEXT("Teleport position/Pawn identity mismatch")); return; }
            Result->SetNumberField(TEXT("teleport_yaw_error_degrees"),FMath::Abs(FMath::FindDeltaAngleDegrees(TestPawn->GetActorRotation().Yaw,Destination->GetActorRotation().Yaw)));
            Result->SetNumberField(TEXT("control_yaw_error_degrees"),FMath::Abs(FMath::FindDeltaAngleDegrees(PC->GetControlRotation().Yaw,Destination->GetActorRotation().Yaw)));
            if (Result->GetNumberField(TEXT("teleport_yaw_error_degrees"))>5 || Result->GetNumberField(TEXT("control_yaw_error_degrees"))>5)
            { Finish(false,TEXT("Pawn or control yaw did not match Destination")); return; }
            Result->SetStringField(TEXT("teleport_confirmation"),bTeleportConfirmed?TEXT("Mover success event + live transform"):TEXT("Two consecutive live transform readbacks; backend event unavailable"));
            Event(TEXT("MoverTeleportConfirmed"));
            Event(TEXT("T00_TELEPORT"));
            Phase=EPhase::Settling; PhaseAt=Now;
        }
        else if (Now-PhaseAt>3) Finish(false,TEXT("Mover teleport not confirmed within 3 seconds"));
    }
    else if (Phase == EPhase::Settling && Now-PhaseAt>=NightHoldSeconds)
    {
        if (bInteractiveTransition) { BeginFocusReturn(true); }
        else { RestoreCamera(); Phase=EPhase::AwaitRestore; PhaseAt=Now; Event(TEXT("GameplayCameraRestoreRequested")); }
    }
    else if (Phase == EPhase::AwaitRestore)
    {
        if (PC->GetViewTarget()==TestPawn && GameplayCamera->IsActive() && PC->PlayerCameraManager
            && FVector::Dist(PC->PlayerCameraManager->GetCameraLocation(),TestPawn->GetActorLocation())<1500)
        {
            RestoreInput(); Phase=EPhase::Post; PhaseAt=RestoredAt=Now;
            PostStartLocation=TestPawn->GetActorLocation(); Event(TEXT("GameplayCameraRestored_InputEnabled_MOVE_NOW"));
            Event(TEXT("T00_CAMERA_RESTORED"));
        }
        else if (Now-PhaseAt>3) Finish(false,TEXT("Gameplay Camera did not recover to night Pawn"));
    }
    else if (Phase==EPhase::Post && Now-PhaseAt>=PostMeasureSeconds)
    {
        Result->SetNumberField(TEXT("post_restore_displacement_cm"), FVector::Dist2D(PostStartLocation,TestPawn->GetActorLocation()));
        Finish(true,TEXT("Telemetry complete; manual visual, animation, movement and Standalone acceptance still required"));
    }
}
void AYIXIT00TransitionController::Finish(bool bFunctional, const FString& Reason)
{
    if (bReportWritten || Phase==EPhase::Done) return;
    if (!bFunctional && !bSessionEnding)
    {
        UE_LOG(LogYIXIT00, Error, TEXT("[YIXI_T00] T00_FAILED phase=%s reason=%s"), *PhaseName(), *Reason);
    }
    if (bInputHeld) { RestoreCamera(); RestoreInput(); }
    if (!bFunctional && !bSessionEnding && FocusRig) SetFocusState(EYIXIT01FocusState::Failed);
    Result->SetBoolField(TEXT("functional_telemetry_complete"),bFunctional);
    Result->SetStringField(TEXT("reason"),Reason);
    Result->SetStringField(TEXT("manual_acceptance"),TEXT("PENDING: framing, no fly-through, input/animation, PIE then Standalone, GPU/streaming attribution."));
    Result->SetBoolField(TEXT("same_pawn_and_controller"),SamePossession());
    Result->SetBoolField(TEXT("levels_loaded_visible"),ScenesReady());
    Result->SetNumberField(TEXT("cut_wall_seconds"),CutAt>0?CutAt-StartedAt:-1);
    Result->SetNumberField(TEXT("restore_wall_seconds"),RestoredAt>0?RestoredAt-StartedAt:-1);
    Result->SetStringField(TEXT("render_readiness_limit"),TEXT("Both views captured >=30 frames and render-thread fence complete. This does not guarantee GPU/PSO/texture residency or a hitch-free first main-view draw."));
    auto Values=[](const TArray<TSharedPtr<FJsonObject>>& Rows)
    { TArray<TSharedPtr<FJsonValue>> Out; for (const auto& Row:Rows) Out.Add(MakeShared<FJsonValueObject>(Row)); return Out; };
    Frames.Sort([](const TSharedPtr<FJsonObject>& A, const TSharedPtr<FJsonObject>& B) { return A->GetNumberField(TEXT("frame")) < B->GetNumberField(TEXT("frame")); });
    Result->SetStringField(TEXT("focus_state"), FocusStateName());
    if (L01LightingRig) Result->SetObjectField(TEXT("l01_lighting"),L01LightingRig->Diagnostics());
    if (LightStateSequence) Result->SetObjectField(TEXT("sequencer_lighting"),SequenceLightingDiagnostics());
    Result->SetArrayField(TEXT("events"),Values(Events)); Result->SetArrayField(TEXT("frames"),Values(Frames));
    const FString Folder=FPaths::Combine(FPaths::ProjectSavedDir(),TEXT("YIXI/Reports"));
    IFileManager::Get().MakeDirectory(*Folder,true);
    const FString File=FPaths::Combine(Folder,TEXT("YIXI_T00_RUNTIME_")+FGuid::NewGuid().ToString(EGuidFormats::Digits)+TEXT(".json"));
    if (IFileManager::Get().FileExists(*File)) { UE_LOG(LogYIXIT00,Error,TEXT("[YIXI_T00] Unexpected report collision; no overwrite.")); return; }
    bReportWritten=FFileHelper::SaveStringToFile(Encode(Result.ToSharedRef()),*File,FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM,&IFileManager::Get(),FILEWRITE_NoReplaceExisting);
    if (bReportWritten)
    {
        UE_LOG(LogYIXIT00,Display,TEXT("[YIXI_T00] %s; JSON=%s"), bFunctional?TEXT("TELEMETRY_COMPLETE_NOT_MANUALLY_ACCEPTED"):TEXT("FAILED_PRESERVED"),*File);
    }
    else
    {
        UE_LOG(LogYIXIT00,Error,TEXT("[YIXI_T00] REPORT_WRITE_FAILED; preserve scene. Target=%s"),*File);
    }
    Phase=EPhase::Done; SetActorTickEnabled(false);
}
void AYIXIT00TransitionController::EndPlay(const EEndPlayReason::Type Reason)
{
    bSessionEnding = true;
    RestoreSequenceDiagnostics();
    if (Result.IsValid() && !bReportWritten) Finish(false,TEXT("Play ended before test report completed"));
    RestoreInput();
    ShutdownFocusInteraction();
    if (Mover) Mover->OnTeleportSucceeded.RemoveDynamic(this,&AYIXIT00TransitionController::Teleported);
    Super::EndPlay(Reason);
}
