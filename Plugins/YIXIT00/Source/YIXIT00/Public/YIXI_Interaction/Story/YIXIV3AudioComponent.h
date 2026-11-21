#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "YIXIV3AudioComponent.generated.h"

class UAudioComponent;
class UCurveFloat;
class USoundBase;
class USoundSubmix;

UCLASS(ClassGroup=(YIXI), meta=(BlueprintSpawnableComponent))
class YIXIT00_API UYIXIV3AudioComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UYIXIV3AudioComponent();
    UPROPERTY(EditAnywhere, Category="Day sound") TObjectPtr<USoundBase> Crowd;
    UPROPERTY(EditAnywhere, Category="Day sound") TObjectPtr<USoundBase> Atmosphere;
    UPROPERTY(EditAnywhere, Category="Day sound") TObjectPtr<USoundBase> Music;
    UPROPERTY(EditAnywhere, Category="Day sound") TObjectPtr<USoundSubmix> WetReturn;
    /** Dedicated V3 crowd, ambience and music bus. Never assign the game's master. */
    UPROPERTY(EditAnywhere, Category="Day sound") TObjectPtr<USoundSubmix> DayDirect;
    UPROPERTY(EditAnywhere, Category="Day sound", meta=(ClampMin="0",ClampMax="1")) float PeakSend = 0.85f;
    UPROPERTY(EditAnywhere, Category="Subjective hearing", meta=(ClampMin="80",ClampMax="20000",Units="Hz")) float MuffledCutoffHz = 360.f;
    UPROPERTY(EditAnywhere, Category="Subjective hearing", meta=(ClampMin="0",ClampMax="1")) float MuffledDryLevel = .40f;
    /** Optional 0..1 response to the director's pre-cut envelope. */
    UPROPERTY(EditAnywhere, Category="Subjective hearing") TObjectPtr<UCurveFloat> HearingCurve;
    UPROPERTY(EditAnywhere, Category="Subjective hearing") TObjectPtr<USoundBase> RingingSound;
    UPROPERTY(EditAnywhere, Category="Subjective hearing", meta=(ClampMin="0",ClampMax="1")) float RingingVolume = .25f;
    UPROPERTY(EditAnywhere, Category="Subjective hearing", meta=(ClampMin="0.05",ClampMax="5",Units="s")) float TailSeconds = 2.5f;
    /** Fraction of the tail before the wet return and remaining ringing taper to silence. */
    UPROPERTY(EditAnywhere, Category="Subjective hearing", meta=(ClampMin="0",ClampMax="0.95")) float TailTaperStart = .78f;
    UPROPERTY(EditAnywhere, Category="Night sound") TObjectPtr<USoundBase> NightAtmosphere;
    UPROPERTY(EditAnywhere, Category="Night sound", meta=(ClampMin="0",Units="s")) float NightDelay = 1.8f;
    UPROPERTY(EditAnywhere, Category="Night sound", meta=(ClampMin="0",Units="s")) float NightFadeInSeconds = 1.25f;

    void BeginDayMix();
    void SetDayEcho(float Alpha);
    void CommitNightMix();
    void RestoreDayMix();
    void EndNightPreview();

protected:
    virtual void TickComponent(float DeltaSeconds, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    UPROPERTY(Transient) TArray<TObjectPtr<UAudioComponent>> DayVoices;
    UPROPERTY(Transient) TObjectPtr<UAudioComponent> NightVoice;
    UPROPERTY(Transient) TObjectPtr<UAudioComponent> RingingVoice;
    FTimerHandle NightTimer;
    double CutGameTime = 0.;
    float LastAmount = -1.f;
    float RingingGainAtCut = 0.f;
    bool bDayActive = false;
    bool bCut = false;

    UAudioComponent* CreateVoice(USoundBase* Sound, float Gain = 1.f, float FadeInSeconds = 0.f);
    void StopRinging();
    void StopDayVoices();
    void StartNight();
};
