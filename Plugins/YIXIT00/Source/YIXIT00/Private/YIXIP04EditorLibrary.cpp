#include "YIXIP04EditorLibrary.h"
#include "Engine/Level.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Engine/World.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#if WITH_EDITOR
#include "Landscape.h"
#include "LandscapeInfo.h"
#include "LandscapeComponent.h"
#include "LandscapeHeightfieldCollisionComponent.h"
#include "LandscapeDataAccess.h"
#endif

namespace
{
FString P04Reply(const TSharedRef<FJsonObject>& Info)
{
    FString Text;
    FJsonSerializer::Serialize(Info,TJsonWriterFactory<>::Create(&Text));
    return Text;
}
bool P04TestWorld(const UWorld* World)
{
    return World && World->WorldType==EWorldType::Editor &&
        World->GetOutermost()->GetName().StartsWith(TEXT("/Game/YIXI/Tests/P04/"));
}
}

FString UYIXIP04EditorLibrary::CreateFlatLandscape(ULevel* TargetLevel, const FString& Label,
    FVector Origin, int32 ComponentsX, int32 ComponentsY, float XYScale, bool bValidateOnly,
    int32 NumSubsections)
{
    auto Info=MakeShared<FJsonObject>();
    Info->SetBoolField(TEXT("success"),false);
#if WITH_EDITOR
    UWorld* World=TargetLevel ? TargetLevel->GetWorld() : nullptr;
    if (!P04TestWorld(World) || !TargetLevel->GetOutermost()->GetName().StartsWith(TEXT("/Game/YIXI/Tests/P04/")) ||
        !Label.StartsWith(TEXT("P04_")) || ComponentsX<1 || ComponentsX>8 || ComponentsY<1 || ComponentsY>8 ||
        !FMath::IsFinite(XYScale) || XYScale<25 || XYScale>200 || Origin.ContainsNaN() ||
        (NumSubsections!=1 && NumSubsections!=2))
    { Info->SetStringField(TEXT("error"),TEXT("Invalid parameters or target outside isolated P04 Editor maps")); return P04Reply(Info); }
    for (AActor* Actor : TargetLevel->Actors)
        if (Actor && Actor->GetActorLabel()==Label)
        { Info->SetStringField(TEXT("error"),TEXT("Landscape label already exists; no overwrite")); return P04Reply(Info); }
    constexpr int32 Quads=63;
    const int32 SizeX=ComponentsX*Quads*NumSubsections+1, SizeY=ComponentsY*Quads*NumSubsections+1;
    Info->SetNumberField(TEXT("vertices_x"),SizeX); Info->SetNumberField(TEXT("vertices_y"),SizeY);
    Info->SetNumberField(TEXT("components"),ComponentsX*ComponentsY);
    if (bValidateOnly)
    { Info->SetBoolField(TEXT("success"),true); Info->SetBoolField(TEXT("dry_run"),true); return P04Reply(Info); }
    FActorSpawnParameters Params;
    Params.OverrideLevel=TargetLevel;
    Params.SpawnCollisionHandlingOverride=ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ALandscape* Landscape=World->SpawnActor<ALandscape>(ALandscape::StaticClass(),FTransform(FRotator::ZeroRotator,Origin),Params);
    if (!Landscape) { Info->SetStringField(TEXT("error"),TEXT("Landscape spawn failed")); return P04Reply(Info); }
    Landscape->SetActorLabel(Label);
    Landscape->Tags.Add(TEXT("YIXI_P04_Terrain"));
    Landscape->SetActorScale3D(FVector(XYScale,XYScale,100));
    TMap<FGuid,TArray<uint16>> Heights;
    Heights.Add(FGuid()).Init(32768,SizeX*SizeY);
    TMap<FGuid,TArray<FLandscapeImportLayerInfo>> Layers;
    Layers.Add(FGuid());
    // Same Import entry point and empty edit-layer view as the 5.8 Landscape UI.
    Landscape->Import(FGuid::NewGuid(),0,0,SizeX-1,SizeY-1,NumSubsections,Quads,Heights,TEXT(""),Layers,
        ELandscapeImportAlphamapType::Additive,TArrayView<const FLandscapeLayer>());
    Landscape->RegisterAllComponents();
    if (ULandscapeInfo* LandscapeInfo=Landscape->GetLandscapeInfo()) LandscapeInfo->UpdateLayerInfoMap(Landscape);
    Landscape->MarkPackageDirty();
    Info->SetStringField(TEXT("actor"),Landscape->GetPathName());
    Info->SetNumberField(TEXT("render_components"),Landscape->LandscapeComponents.Num());
    Info->SetNumberField(TEXT("collision_components"),Landscape->CollisionComponents.Num());
    Info->SetBoolField(TEXT("success"),Landscape->LandscapeComponents.Num()==ComponentsX*ComponentsY &&
        Landscape->CollisionComponents.Num()==ComponentsX*ComponentsY);
    Info->SetStringField(TEXT("failure_policy"),TEXT("Retain any partial actor and report; never delete or retry automatically"));
#else
    Info->SetStringField(TEXT("error"),TEXT("Editor-only API"));
#endif
    return P04Reply(Info);
}

FString UYIXIP04EditorLibrary::InspectLandscape(AActor* Actor)
{
    auto Info=MakeShared<FJsonObject>(); Info->SetBoolField(TEXT("success"),false);
#if WITH_EDITOR
    ALandscape* Landscape=Cast<ALandscape>(Actor);
    ULandscapeInfo* LandscapeInfo=Landscape ? Landscape->GetLandscapeInfo() : nullptr;
    int32 MinX=0,MinY=0,MaxX=0,MaxY=0;
    if (!Landscape || !P04TestWorld(Landscape->GetWorld()) || !LandscapeInfo ||
        !Landscape->GetOutermost()->GetName().StartsWith(TEXT("/Game/YIXI/Tests/P04/")) ||
        !LandscapeInfo->GetLandscapeExtent(MinX,MinY,MaxX,MaxY) ||
        MaxX-MinX>1008 || MaxY-MinY>1008)
    { Info->SetStringField(TEXT("error"),TEXT("Expected isolated P04 Landscape of at most 1009 vertices per axis")); return P04Reply(Info); }
    uint16 Lowest=65535,Highest=0;
    int32 AllocatedWeightLayers=0,PaintLayers=0;
    for (const FLandscapeInfoLayerSettings& Layer:LandscapeInfo->Layers)
        if (Layer.LayerName!=FName(TEXT("Visibility"))) ++PaintLayers;
    // DataAccess copies source mip data. LandscapeEdit would call Texture::Modify
    // even on a read, so it must not be used for this read-only inspection.
    for (ULandscapeComponent* Component:Landscape->LandscapeComponents)
    {
        FLandscapeComponentDataInterface Data(Component,0,false);
        for (int32 Y=0;Y<=Component->ComponentSizeQuads;++Y)
            for (int32 X=0;X<=Component->ComponentSizeQuads;++X)
            {
                const uint16 Height=Data.GetHeight(X,Y);
                Lowest=FMath::Min(Lowest,Height); Highest=FMath::Max(Highest,Height);
            }
        for (const FWeightmapLayerAllocationInfo& Allocation:Component->GetWeightmapLayerAllocations())
            if (Allocation.IsAllocated()) ++AllocatedWeightLayers;
    }
    Info->SetBoolField(TEXT("success"),true);
    Info->SetStringField(TEXT("actor"),Landscape->GetPathName());
    Info->SetNumberField(TEXT("vertices_x"),MaxX-MinX+1);
    Info->SetNumberField(TEXT("vertices_y"),MaxY-MinY+1);
    Info->SetNumberField(TEXT("height_min"),Lowest); Info->SetNumberField(TEXT("height_max"),Highest);
    Info->SetNumberField(TEXT("edit_layers"),Landscape->GetLayersConst().Num());
    Info->SetNumberField(TEXT("paint_layers"),PaintLayers);
    Info->SetNumberField(TEXT("allocated_weight_layers"),AllocatedWeightLayers);
    Info->SetBoolField(TEXT("has_assigned_material"),Landscape->LandscapeMaterial!=nullptr);
    Info->SetNumberField(TEXT("render_components"),Landscape->LandscapeComponents.Num());
    Info->SetNumberField(TEXT("collision_components"),Landscape->CollisionComponents.Num());
    Info->SetBoolField(TEXT("unsculpted_flat_base"),Lowest==32768 && Highest==32768 &&
        Landscape->GetLayersConst().Num()<=1 && PaintLayers==0 &&
        AllocatedWeightLayers==0 && Landscape->LandscapeMaterial==nullptr);
#else
    Info->SetStringField(TEXT("error"),TEXT("Editor-only API"));
#endif
    return P04Reply(Info);
}

FString UYIXIP04EditorLibrary::ConfigureStreaming(ULevelStreaming* Stream,
    bool bInitiallyLoaded, bool bInitiallyVisible, bool bValidateOnly)
{
    auto Info=MakeShared<FJsonObject>(); Info->SetBoolField(TEXT("success"),false);
#if WITH_EDITOR
    auto* Dynamic=Cast<ULevelStreamingDynamic>(Stream);
    if (!Dynamic || !P04TestWorld(Dynamic->GetWorld()))
    { Info->SetStringField(TEXT("error"),TEXT("Expected Blueprint streaming object in isolated P04 Editor World")); return P04Reply(Info); }
    if (!bValidateOnly)
    {
        Dynamic->Modify();
        Dynamic->bInitiallyLoaded=bInitiallyLoaded; Dynamic->bInitiallyVisible=bInitiallyVisible;
        Dynamic->bShouldBlockOnLoad=bInitiallyLoaded; // Initial Day only; Night remains asynchronous.
        Dynamic->bShouldBlockOnUnload=false;
        Dynamic->MarkPackageDirty();
    }
    Info->SetBoolField(TEXT("success"),true);
    Info->SetBoolField(TEXT("dry_run"),bValidateOnly);
    Info->SetStringField(TEXT("package"),Dynamic->GetWorldAssetPackageName());
    Info->SetBoolField(TEXT("initially_loaded"),Dynamic->bInitiallyLoaded);
    Info->SetBoolField(TEXT("initially_visible"),Dynamic->bInitiallyVisible);
#else
    Info->SetStringField(TEXT("error"),TEXT("Editor-only API"));
#endif
    return P04Reply(Info);
}
