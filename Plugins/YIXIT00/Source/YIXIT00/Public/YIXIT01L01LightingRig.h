#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXIT01L01LightingRig.generated.h"

class UPointLightComponent;
class UDirectionalLightComponent;
class USkyLightComponent;
class UPostProcessComponent;
class UTextureCube;
class UMaterialInterface;
class UStaticMeshComponent;
class ULightComponentBase;
class APlayerController;
class FJsonObject;

UENUM(BlueprintType)
enum class EYIXIL01Mode : uint8
{
    LocalPrelit, GlobalDayOnly, GlobalNightOnly, GlobalSwitchAtCut
};

// Test-only components and runtime overrides. No asset saves or loads at the cut.
UCLASS(Blueprintable)
class YIXIT00_API AYIXIT01L01LightingRig : public AActor
{
    GENERATED_BODY()
public:
    AYIXIT01L01LightingRig();
    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void EndPlay(const EEndPlayReason::Type Reason) override;
    bool Prepare(APlayerController* Controller, FString& Reason);
    void CameraBCutObserved();
    TSharedRef<FJsonObject> Diagnostics() const;

    UPROPERTY(EditAnywhere, Category="L01") EYIXIL01Mode Mode = EYIXIL01Mode::LocalPrelit;
    // Legacy serialized fields: retained for existing maps, hidden from Details.
    // Native point-light components are the sole source of instance settings.
    // These values only seed newly created native subobject defaults.
    UPROPERTY() FVector DayAnchor = FVector(0,0,100);
    UPROPERTY() FVector NightAnchor = FVector(0,100000,100);
    UPROPERTY() FVector KeyOffset = FVector(-180,-160,220);
    UPROPERTY() FVector FillOffset = FVector(-120,200,120);
    UPROPERTY() float RadiusCm = 1500;
    UPROPERTY() float DayKeyLumens = 1600;
    UPROPERTY() float DayFillLumens = 500;
    UPROPERTY() float NightKeyLumens = 300;
    UPROPERTY() float NightFillLumens = 80;
    UPROPERTY(EditAnywhere, Category="L01|Global|Color") FLinearColor DayColor = FLinearColor(1,.86f,.64f);
    UPROPERTY(EditAnywhere, Category="L01|Global|Color") FLinearColor NightColor = FLinearColor(.18f,.32f,1);
    UPROPERTY(EditAnywhere, Category="L01|Global", meta=(ClampMin="0")) float DaySunLux = 6;
    UPROPERTY(EditAnywhere, Category="L01|Global", meta=(ClampMin="0")) float NightSunLux = .4f;
    UPROPERTY(EditAnywhere, Category="L01|Global", meta=(ClampMin="0")) float DaySkyIntensity = .25f;
    UPROPERTY(EditAnywhere, Category="L01|Global", meta=(ClampMin="0")) float NightSkyIntensity = .04f;
    UPROPERTY(EditAnywhere, Category="L01|Global") FRotator SunRotation = FRotator(-45,30,0);
    UPROPERTY(EditAnywhere, Category="L01|Global") TObjectPtr<UTextureCube> DiagnosticSkyCubemap;
    UPROPERTY(EditAnywhere, Category="L01|Exposure") float ExposureCompensation = -3;
    UPROPERTY(EditAnywhere, Category="L01|Material") TObjectPtr<UMaterialInterface> DiagnosticLitMaterial;

    // Edit intensity, color, attenuation, transform and lighting options on each component.
    // Mode owns visibility only: LocalPrelit shows them; global modes hide them.
    UPROPERTY(VisibleAnywhere, Category="L01|Components") TObjectPtr<UPointLightComponent> DayKey;
    UPROPERTY(VisibleAnywhere, Category="L01|Components") TObjectPtr<UPointLightComponent> DayFill;
    UPROPERTY(VisibleAnywhere, Category="L01|Components") TObjectPtr<UPointLightComponent> NightKey;
    UPROPERTY(VisibleAnywhere, Category="L01|Components") TObjectPtr<UPointLightComponent> NightFill;
    UPROPERTY(VisibleAnywhere, Category="L01|Components") TObjectPtr<UDirectionalLightComponent> Sun;
    UPROPERTY(VisibleAnywhere, Category="L01|Components") TObjectPtr<USkyLightComponent> Sky;
    UPROPERTY(VisibleAnywhere, Category="L01|Components") TObjectPtr<UPostProcessComponent> Exposure;

private:
    TWeakObjectPtr<APlayerController> PC;
    UPROPERTY(Transient) TArray<TObjectPtr<UStaticMeshComponent>> ChangedMeshes;
    UPROPERTY(Transient) TArray<TObjectPtr<UMaterialInterface>> OriginalMaterials;
    UPROPERTY(Transient) TArray<TObjectPtr<ULightComponentBase>> SuppressedLights;
    TArray<bool> OriginalVisibility;
    TSharedPtr<FJsonObject> SwitchRecord;
    bool bPrepared = false, bNight = false;
    uint64 ChangeFrame = 0, ExposureFrame = MAX_uint64;
    void Configure();
    void ApplyGlobal(bool bUseNight);
    void RestoreOverrides();
};
