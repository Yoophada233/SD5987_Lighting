#include "YIXIT01L01LightingRig.h"
#include "Camera/PlayerCameraManager.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/SkyLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Dom/JsonObject.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/TextureCube.h"
#include "GameFramework/PlayerController.h"
#include "HAL/IConsoleManager.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInterface.h"
#include "Components/SkyAtmosphereComponent.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "MovieScene.h"
#include "MovieSceneBindingOverrides.h"
#include "MovieScenePossessable.h"
#include "MovieSceneTrack.h"
#include "MovieSceneSection.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIL01, Log, All);

AYIXIT01L01LightingRig::AYIXIT01L01LightingRig()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("T01_L01_Root"));
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.TickGroup = TG_PostUpdateWork;
    // Defaults only: serialized native-component instance edits load afterwards.
    auto Local = [this](FName Name, const FVector& Position, float Lumens, const FLinearColor& Color)
    {
        auto* Light = CreateDefaultSubobject<UPointLightComponent>(Name);
        Light->SetupAttachment(RootComponent);
        Light->SetMobility(EComponentMobility::Movable);
        Light->SetIntensityUnits(ELightUnits::Lumens);
        Light->SetRelativeLocation(Position);
        Light->SetAttenuationRadius(RadiusCm);
        Light->SetIntensity(Lumens);
        Light->SetLightColor(Color, false);
        return Light;
    };
    DayKey=Local(TEXT("T01_L01_DayKey"),DayAnchor+KeyOffset,DayKeyLumens,DayColor);
    DayFill=Local(TEXT("T01_L01_DayFill"),DayAnchor+FillOffset,DayFillLumens,DayColor);
    NightKey=Local(TEXT("T01_L01_NightKey"),NightAnchor+KeyOffset,NightKeyLumens,NightColor);
    NightFill=Local(TEXT("T01_L01_NightFill"),NightAnchor+FillOffset,NightFillLumens,NightColor);
    Sun=CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("T01_L01_Directional"));
    Sun->SetupAttachment(RootComponent); Sun->SetMobility(EComponentMobility::Movable);
    Sun->bAtmosphereSunLight=false;
    Sky=CreateDefaultSubobject<USkyLightComponent>(TEXT("T01_L01_SkyLight"));
    Sky->SetupAttachment(RootComponent); Sky->SetMobility(EComponentMobility::Movable);
    Sky->SourceType=SLS_SpecifiedCubemap; Sky->bRealTimeCapture=false;
    Exposure=CreateDefaultSubobject<UPostProcessComponent>(TEXT("T01_L01_FixedExposure"));
    Exposure->SetupAttachment(RootComponent);
    Configure();
}
void AYIXIT01L01LightingRig::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform); Configure();
}
void AYIXIT01L01LightingRig::Configure()
{
    if (bSequenceOwnsLighting)
    {
        FString Reason;
        if (!BindLightSequence(Reason)) SequenceBindingReport=Reason;
        return; // No legacy rotation, light, sky or exposure writes in P03.
    }
    const bool bLocal = Mode==EYIXIL01Mode::LocalPrelit;
    // Never re-author local component settings here. Construction, mode changes
    // and Prepare must preserve native instance edits, including hidden lights.
    for (auto* Light : {DayKey.Get(),DayFill.Get(),NightKey.Get(),NightFill.Get()})
        Light->SetVisibility(bLocal);
    Sun->SetRelativeRotation(SunRotation); Sun->SetVisibility(!bLocal);
    Sky->SourceType=SLS_SpecifiedCubemap; Sky->bRealTimeCapture=false;
    if (Sky->Cubemap!=DiagnosticSkyCubemap) Sky->SetCubemap(DiagnosticSkyCubemap);
    Sky->SetVisibility(!bLocal);
    ApplyGlobal(Mode==EYIXIL01Mode::GlobalNightOnly);
    Exposure->bUnbound=true; Exposure->bEnabled=true; Exposure->Priority=10000; Exposure->BlendWeight=1;
    auto& S=Exposure->Settings;
    S.bOverride_AutoExposureMethod=true; S.AutoExposureMethod=AEM_Manual;
    S.bOverride_AutoExposureApplyPhysicalCameraExposure=true; S.AutoExposureApplyPhysicalCameraExposure=false;
    S.bOverride_AutoExposureBias=true; S.AutoExposureBias=ExposureCompensation;
    S.bOverride_AutoExposureBiasCurve=true; S.AutoExposureBiasCurve=nullptr;
    S.bOverride_LocalExposureMethod=true; S.LocalExposureMethod=ELocalExposureMethod::Bilateral;
    S.bOverride_LocalExposureHighlightContrastScale=true; S.LocalExposureHighlightContrastScale=1;
    S.bOverride_LocalExposureShadowContrastScale=true; S.LocalExposureShadowContrastScale=1;
    S.bOverride_LocalExposureHighlightContrastCurve=true; S.LocalExposureHighlightContrastCurve=nullptr;
    S.bOverride_LocalExposureShadowContrastCurve=true; S.LocalExposureShadowContrastCurve=nullptr;
    S.bOverride_LocalExposureDetailStrength=true; S.LocalExposureDetailStrength=1;
    S.bOverride_LocalExposureMiddleGreyBias=true; S.LocalExposureMiddleGreyBias=0;
    // Do not override GI/reflections, Lumen cache/update speeds, or project CVars.
}
bool AYIXIT01L01LightingRig::BindLightSequence(FString& Reason)
{
    if (!LightStateSequence || LightStateSequence->GetWorld()!=GetWorld()
        || !LightStateSequence->GetSequence() || !LightStateSequence->BindingOverrides)
    { Reason=TEXT("P03 needs the Master-local LevelSequenceActor with a saved Sequence"); return false; }
    UMovieScene* Scene=LightStateSequence->GetSequence()->GetMovieScene();
    if (!Scene || Scene->GetPossessableCount()==0 || Scene->GetSpawnableCount()!=0)
    { Reason=TEXT("P03 expects existing lighting possessables, no spawnables"); return false; }
    TArray<TPair<FMovieSceneObjectBindingID,UObject*>> Bindings;
    TArray<TSharedPtr<FJsonValue>> Records;
    for (int32 I=0;I<Scene->GetPossessableCount();++I)
    {
        const FMovieScenePossessable& P=Scene->GetPossessable(I);
        const FMovieScenePossessable* Root=&P;
        for (int32 Depth=0;Root->GetParent().IsValid() && Depth<Scene->GetPossessableCount();++Depth)
        {
            Root=Scene->FindPossessable(Root->GetParent());
            if (!Root) { Reason=TEXT("P03 broken parent binding"); return false; }
        }
        const FString Name=Root->GetName();
        UObject* Target=nullptr;
        // Actor/component bindings both resolve to the actual Master component.
        // Transform tracks support USceneComponent; PP settings share FPostProcessSettings.
        if (Name.Contains(TEXT("DirectionalLight"))) Target=Sun.Get();
        else if (Name.Contains(TEXT("SkyLight"))) Target=Sky.Get();
        else if (Name.Contains(TEXT("PostProcessVolume"))) Target=Exposure.Get();
        else if (Name.Contains(TEXT("SkyAtmosphere")) && SequenceSkyAtmosphere)
            Target=P.GetParent().IsValid() ? static_cast<UObject*>(SequenceSkyAtmosphere->FindComponentByClass<USkyAtmosphereComponent>()) : SequenceSkyAtmosphere.Get();
        if (!Target)
        { Reason=TEXT("P03 unmapped existing track; preserve and explicitly adapt: ")+P.GetName()+TEXT(" / ")+Name; return false; }
        auto Record=MakeShared<FJsonObject>();
        Record->SetStringField(TEXT("binding"),P.GetName());
        Record->SetStringField(TEXT("guid"),P.GetGuid().ToString());
        Record->SetStringField(TEXT("target"),Target->GetPathName());
        TArray<TSharedPtr<FJsonValue>> Tracks;
        if (const auto* Binding=Scene->FindBinding(P.GetGuid()))
            for (const auto* Track : Binding->GetTracks())
            {
                Tracks.Add(MakeShared<FJsonValueString>(Track->GetClass()->GetName()+TEXT(":")+Track->GetName()));
                const FFrameNumber NightTick=FFrameRate::TransformTime(FFrameTime(30),Scene->GetDisplayRate(),Scene->GetTickResolution()).FloorToFrame();
                bool bNightCovered=false;
                for (const auto* Section : Track->GetAllSections())
                    if (Section && Section->IsActive() && Section->GetRange().Contains(NightTick)) bNightCovered=true;
                if (!bNightCovered)
                { Reason=TEXT("P03 track does not cover frame 30: ")+Track->GetPathName(); return false; }
            }
        Record->SetArrayField(TEXT("tracks"),Tracks); Records.Add(MakeShared<FJsonValueObject>(Record));
        Bindings.Emplace(FMovieSceneObjectBindingID(UE::MovieScene::FFixedObjectBindingID(P.GetGuid(),MovieSceneSequenceID::Root)),Target);
    }
    // Only after every existing binding is understood, replace defaults completely.
    for (const auto& Binding : Bindings)
    {
        LightStateSequence->BindingOverrides->SetBinding(Binding.Key,{Binding.Value},false);
        if (auto* Player=LightStateSequence->GetSequencePlayer()) Player->RequestInvalidateBinding(Binding.Key);
    }
    auto Info=MakeShared<FJsonObject>();
    Info->SetStringField(TEXT("sequence"),LightStateSequence->GetSequence()->GetPathName());
    Info->SetArrayField(TEXT("bindings"),Records);
    FJsonSerializer::Serialize(Info,TJsonWriterFactory<>::Create(&SequenceBindingReport));
    return true;
}
bool AYIXIT01L01LightingRig::ApplySequenceFrame(int32 Frame,FString& Reason)
{
    auto* Player=LightStateSequence ? LightStateSequence->GetSequencePlayer() : nullptr;
    if (!Player) { Reason=TEXT("P03 native SequencePlayer is not initialized"); return false; }
    UMovieScene* Scene=LightStateSequence->GetSequence()->GetMovieScene();
    for (int32 I=0;I<Scene->GetPossessableCount();++I)
    {
        const auto& P=Scene->GetPossessable(I);
        const FMovieSceneObjectBindingID ID(UE::MovieScene::FFixedObjectBindingID(P.GetGuid(),MovieSceneSequenceID::Root));
        const auto Objects=Player->GetBoundObjects(ID);
        if (Objects.Num()!=1 || !Objects[0] || Objects[0]->GetWorld()!=GetWorld())
        { Reason=TEXT("P03 binding is not unique and Master-local: ")+P.GetName(); return false; }
    }
    Player->SetCompletionModeOverride(EMovieSceneCompletionModeOverride::ForceKeepState);
    Player->Pause();
    FMovieSceneSequencePlaybackParams Params(FFrameTime(Frame),EUpdatePositionMethod::Jump);
    Params.bHasJumped=true;
    Player->SetPlaybackPosition(Params);
    if (Player->IsPlaying() || Player->GetCurrentTime().Time.FrameNumber.Value!=Frame)
    { Reason=TEXT("P03 player did not hold the requested display frame"); return false; }
    AppliedSequenceFrame=Frame; bNight=(Frame==30);
    UE_LOG(LogYIXIL01,Display,TEXT("[YIXI_P03] SEQUENCE_JUMP frame=%d engine_frame=%llu player=%s playing=0 legacy_lighting=DISABLED sun=%g sky=%g exposure_bias=%g"),
        Frame,GFrameCounter,*Player->GetPathName(),Sun->Intensity,Sky->Intensity,Exposure->Settings.AutoExposureBias);
    return true;
}
void AYIXIT01L01LightingRig::ApplyGlobal(bool bUseNight)
{
    if (bSequenceOwnsLighting) { ++LegacyWritesAfterSequenceReady; return; }
    bNight=bUseNight;
    Sun->SetIntensity(bNight?NightSunLux:DaySunLux);
    Sun->SetLightColor(bNight?NightColor:DayColor,false);
    Sky->SetIntensity(bNight?NightSkyIntensity:DaySkyIntensity);
    Sky->SetLightColor(bNight?NightColor:DayColor);
}
bool AYIXIT01L01LightingRig::Prepare(APlayerController* Controller,FString& Reason)
{
    if (bPrepared) return true;
    if (!Controller || !Controller->PlayerCameraManager || !DiagnosticLitMaterial
        || DiagnosticLitMaterial->GetShadingModels().HasShadingModel(MSM_Unlit))
    { Reason=TEXT("L01 needs a local camera manager and a preloaded lit diagnostic material"); return false; }
    if (!bSequenceOwnsLighting && Mode!=EYIXIL01Mode::LocalPrelit && !DiagnosticSkyCubemap)
    { Reason=TEXT("L01 global test requires a preloaded specified SkyLight cubemap"); return false; }
    if (!bSequenceOwnsLighting) Configure();
    if (!bSequenceOwnsLighting && Mode==EYIXIL01Mode::LocalPrelit)
        for (auto* Day : {DayKey.Get(),DayFill.Get()}) for (auto* Night : {NightKey.Get(),NightFill.Get()})
            if (FVector::Dist(Day->GetComponentLocation(),Night->GetComponentLocation())
                <=Day->AttenuationRadius+Night->AttenuationRadius)
            { Reason=TEXT("L01 day/night direct-light attenuation spheres overlap (native component radii)"); return false; }
    TArray<UStaticMeshComponent*> Targets;
    for (const TCHAR* Tag : {TEXT("T00_FloorA"),TEXT("T00_BackdropA"),TEXT("T00_BodyA"),TEXT("T00_HeadA"),
                             TEXT("T00_FloorB"),TEXT("T00_BackdropB"),TEXT("T00_BodyB"),TEXT("T00_HeadB")})
    {
        TArray<AActor*> Found; UGameplayStatics::GetAllActorsWithTag(this,FName(Tag),Found);
        auto* Mesh=Found.Num()==1?Found[0]->FindComponentByClass<UStaticMeshComponent>():nullptr;
        if (!Mesh || Mesh->GetNumMaterials()!=1)
        { Reason=FString::Printf(TEXT("L01 expected one loaded single-slot diagnostic mesh for %s"),Tag); return false; }
        Targets.Add(Mesh);
    }
    TArray<AActor*> Existing; UGameplayStatics::GetAllActorsOfClass(this,AActor::StaticClass(),Existing);
    for (AActor* Actor : Existing)
    {
        if (Actor==this) continue;
        TArray<ULightComponentBase*> Lights; Actor->GetComponents(Lights);
        for (auto* Light : Lights)
        {
            if (!(Light->IsA<UDirectionalLightComponent>() || Light->IsA<USkyLightComponent>()) || !Light->IsVisible()) continue;
            if (!Actor->ActorHasTag(TEXT("T00_TestLight")) || !Light->IsA<UDirectionalLightComponent>())
            { Reason=TEXT("L01 uncontrolled visible global light: ")+Light->GetPathName(); return false; }
            SuppressedLights.Add(Light); OriginalVisibility.Add(Light->IsVisible());
        }
    }
    PC=Controller;
    if (bSequenceOwnsLighting)
    {
        if (!BindLightSequence(Reason) || !ApplySequenceFrame(0,Reason)) return false;
        LegacyWritesAfterSequenceReady=0;
        SetActorTickEnabled(false); // Sequencer owns exposure; no cached PP override.
    }
    for (const TObjectPtr<ULightComponentBase>& LightPtr : SuppressedLights)
    {
        ULightComponentBase* Light = LightPtr.Get();
        if (IsValid(Light)) Light->SetVisibility(false);
    }
    for (auto* Mesh : Targets)
    { ChangedMeshes.Add(Mesh); OriginalMaterials.Add(Mesh->GetMaterial(0)); Mesh->SetMaterial(0,DiagnosticLitMaterial); }
    AddTickPrerequisiteActor(Controller);
    bPrepared=true;
    if (!bSequenceOwnsLighting)
        UE_LOG(LogYIXIL01,Display,TEXT("[YIXI_L01] READY mode=%d lit_meshes=%d exposure=Manual bias=%.2f; GPU/Lumen convergence UNVERIFIED"),
            static_cast<int32>(Mode),ChangedMeshes.Num(),ExposureCompensation);
    return true;
}
void AYIXIT01L01LightingRig::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    // Runs after the original camera evaluation and the T00 controller. Changes
    // exposure only; never writes Transform/FOV or any Gameplay Camera asset.
    if (!bSequenceOwnsLighting && bPrepared && PC.IsValid() && PC->PlayerCameraManager && ExposureFrame!=GFrameCounter)
    {
        PC->PlayerCameraManager->AddCachedPPBlend(Exposure->Settings,1,VTBlendOrder_Override);
        ExposureFrame=GFrameCounter;
    }
}
bool AYIXIT01L01LightingRig::CameraBCutObserved()
{
    if (!bPrepared) return false;
    if (ChangeFrame!=0) return true;
    if (bSequenceOwnsLighting)
    {
        FString Reason;
        if (!ApplySequenceFrame(30,Reason))
        { UE_LOG(LogYIXIL01,Error,TEXT("[YIXI_P03] FRAME_30_FAILED %s"),*Reason); return false; }
        ChangeFrame=GFrameCounter;
        return true;
    }
    ChangeFrame=GFrameCounter;
    SwitchRecord=MakeShared<FJsonObject>();
    SwitchRecord->SetNumberField(TEXT("before_directional_lux"),Sun->Intensity);
    SwitchRecord->SetNumberField(TEXT("before_skylight_intensity"),Sky->Intensity);
    SwitchRecord->SetStringField(TEXT("before_directional_color"),Sun->LightColor.ToString());
    SwitchRecord->SetStringField(TEXT("before_skylight_color"),Sky->LightColor.ToString());
    const double SubmitAt=FPlatformTime::Seconds();
    if (Mode==EYIXIL01Mode::GlobalSwitchAtCut) ApplyGlobal(true);
    SwitchRecord->SetNumberField(TEXT("setter_cpu_wall_ms_NOT_GPU"),(FPlatformTime::Seconds()-SubmitAt)*1000);
    SwitchRecord->SetNumberField(TEXT("after_directional_lux"),Sun->Intensity);
    SwitchRecord->SetNumberField(TEXT("after_skylight_intensity"),Sky->Intensity);
    SwitchRecord->SetStringField(TEXT("after_directional_color"),Sun->LightColor.ToString());
    SwitchRecord->SetStringField(TEXT("after_skylight_color"),Sky->LightColor.ToString());
    SwitchRecord->SetBoolField(TEXT("processed_sky_texture_pointer_present_NOT_GPU_readiness"),Sky->GetProcessedSkyTexture()!=nullptr);
    UE_LOG(LogYIXIL01,Display,TEXT("[YIXI_L01] CAMERA_B_OBSERVED frame=%llu global_setters=%d; no load/recapture; rendered response UNMEASURED"),
        ChangeFrame,Mode==EYIXIL01Mode::GlobalSwitchAtCut);
    return true;
}
TSharedRef<FJsonObject> AYIXIT01L01LightingRig::Diagnostics() const
{
    auto R=MakeShared<FJsonObject>();
    R->SetBoolField(TEXT("sequence_owns_lighting"),bSequenceOwnsLighting);
    if (bSequenceOwnsLighting)
    {
        R->SetStringField(TEXT("sequence_actor"),GetPathNameSafe(LightStateSequence.Get()));
        R->SetStringField(TEXT("sequence_binding_report"),SequenceBindingReport);
        R->SetNumberField(TEXT("sequence_frame"),AppliedSequenceFrame);
        R->SetNumberField(TEXT("legacy_writes_after_sequence_ready"),LegacyWritesAfterSequenceReady);
        R->SetBoolField(TEXT("legacy_exposure_tick_enabled"),false);
    }
    R->SetStringField(TEXT("mode"),StaticEnum<EYIXIL01Mode>()->GetNameStringByValue(static_cast<int64>(Mode)));
    R->SetBoolField(TEXT("prepared"),bPrepared); R->SetBoolField(TEXT("global_night_state"),bNight);
    R->SetNumberField(TEXT("camera_b_observed_frame"),static_cast<double>(ChangeFrame));
    R->SetNumberField(TEXT("light_submit_frame"),Mode==EYIXIL01Mode::GlobalSwitchAtCut?static_cast<double>(ChangeFrame):0);
    R->SetNumberField(TEXT("directional_intensity_lux"),Sun->Intensity);
    R->SetBoolField(TEXT("directional_visible"),Sun->IsVisible());
    R->SetStringField(TEXT("directional_color"),Sun->LightColor.ToString());
    R->SetNumberField(TEXT("skylight_intensity"),Sky->Intensity);
    R->SetBoolField(TEXT("skylight_visible"),Sky->IsVisible());
    R->SetStringField(TEXT("skylight_color"),Sky->LightColor.ToString());
    R->SetStringField(TEXT("skylight_source"),TEXT("SpecifiedCubemap; unchanged at cut; RealTimeCapture=false"));
    R->SetNumberField(TEXT("cut_recapture_calls_by_L01"),0);
    R->SetStringField(TEXT("fixed_exposure"),bSequenceOwnsLighting ? TEXT("Sequencer owns exposure; no legacy cached PP blend") : TEXT("Manual; PhysicalCamera=false; camera override PP blend applied each frame"));
    R->SetNumberField(TEXT("exposure_compensation"),ExposureCompensation);
    R->SetStringField(TEXT("local_settings_source"),TEXT("Serialized native point-light components; mode controls visibility only"));
    auto LocalState=[](const UPointLightComponent* Light)
    {
        auto State=MakeShared<FJsonObject>();
        State->SetNumberField(TEXT("intensity"),Light->Intensity);
        State->SetNumberField(TEXT("intensity_units"),static_cast<int32>(Light->IntensityUnits));
        State->SetStringField(TEXT("color"),Light->LightColor.ToString());
        State->SetNumberField(TEXT("attenuation_radius_cm"),Light->AttenuationRadius);
        State->SetStringField(TEXT("relative_transform"),Light->GetRelativeTransform().ToString());
        State->SetStringField(TEXT("world_location_cm"),Light->GetComponentLocation().ToString());
        State->SetBoolField(TEXT("visible"),Light->IsVisible());
        return State;
    };
    auto Locals=MakeShared<FJsonObject>();
    Locals->SetObjectField(TEXT("day_key"),LocalState(DayKey.Get()));
    Locals->SetObjectField(TEXT("day_fill"),LocalState(DayFill.Get()));
    Locals->SetObjectField(TEXT("night_key"),LocalState(NightKey.Get()));
    Locals->SetObjectField(TEXT("night_fill"),LocalState(NightFill.Get()));
    R->SetObjectField(TEXT("local_components"),Locals);
    R->SetNumberField(TEXT("runtime_material_overrides"),ChangedMeshes.Num());
    R->SetStringField(TEXT("diagnostic_cubemap"),GetPathNameSafe(DiagnosticSkyCubemap.Get()));
    if (SwitchRecord.IsValid()) R->SetObjectField(TEXT("switch_readback_game_thread_only"),SwitchRecord);
    for (const TCHAR* Name : {TEXT("r.DynamicGlobalIlluminationMethod"),TEXT("r.ReflectionMethod"),TEXT("r.Lumen.DiffuseIndirect.Allow"),TEXT("r.Lumen.HardwareRayTracing"),
        TEXT("r.LumenScene.Lighting.ForceLightingUpdate"),TEXT("r.EyeAdaptationQuality")})
    {
        const auto* C=IConsoleManager::Get().FindConsoleVariable(Name);
        R->SetStringField(Name,C?C->GetString():TEXT("UNAVAILABLE"));
    }
    R->SetStringField(TEXT("render_validation"),TEXT("PENDING: actual exposure/luminance, Lumen GI/reflections, GPU timing and Standalone. Setters/frame counters are not rendered-pixel evidence."));
    return R;
}
void AYIXIT01L01LightingRig::RestoreOverrides()
{
    for (int32 I=0;I<ChangedMeshes.Num();++I)
        if (IsValid(ChangedMeshes[I])) ChangedMeshes[I]->SetMaterial(0,OriginalMaterials[I]);
    for (int32 I=0;I<SuppressedLights.Num();++I)
        if (IsValid(SuppressedLights[I])) SuppressedLights[I]->SetVisibility(OriginalVisibility[I]);
    ChangedMeshes.Reset(); OriginalMaterials.Reset(); SuppressedLights.Reset(); OriginalVisibility.Reset(); bPrepared=false;
}
void AYIXIT01L01LightingRig::EndPlay(const EEndPlayReason::Type Reason)
{
    RestoreOverrides(); Super::EndPlay(Reason);
}
