#include "YIXI_Interaction/Story/YIXIV3AudioComponent.h"

#include "Components/AudioComponent.h"
#include "Curves/CurveFloat.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundBase.h"
#include "Sound/SoundSubmix.h"
#include "TimerManager.h"

UYIXIV3AudioComponent::UYIXIV3AudioComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

UAudioComponent* UYIXIV3AudioComponent::CreateVoice(USoundBase* Sound, float Gain, float FadeInSeconds)
{
    if (!IsValid(Sound)) return nullptr;
    UAudioComponent* Voice = NewObject<UAudioComponent>(GetOwner());
    Voice->bAutoActivate = false;
    Voice->bAllowSpatialization = false;
    Voice->SetupAttachment(GetOwner()->GetRootComponent());
    Voice->SetSound(Sound);
    Voice->SetVolumeMultiplier(Gain);
    Voice->RegisterComponent();
    if (FadeInSeconds > 0.f) Voice->FadeIn(FadeInSeconds);
    else Voice->Play();
    return Voice;
}

void UYIXIV3AudioComponent::BeginDayMix()
{
    if (bDayActive || bCut) return;
    bDayActive = true;
    LastAmount = -1.f;
    for (USoundBase* Sound : {Crowd.Get(), Atmosphere.Get(), Music.Get()})
    {
        if (UAudioComponent* Voice = CreateVoice(Sound))
        {
            DayVoices.Add(Voice);
        }
    }
    SetDayEcho(0.f);
}

void UYIXIV3AudioComponent::SetDayEcho(float Alpha)
{
    if (!bDayActive) return;
    Alpha = FMath::Clamp(Alpha, 0.f, 1.f);
    // Give the early part of the four-second ramp audible weight while easing into the effect.
    const float DefaultAmount = FMath::Lerp(Alpha, FMath::SmoothStep(0.f, 1.f, Alpha), .5f);
    const float Amount = Alpha > 0.f && HearingCurve
        ? FMath::Clamp(HearingCurve->GetFloatValue(Alpha), 0.f, 1.f) : DefaultAmount;
    if (FMath::IsNearlyEqual(Amount, LastAmount)) return;
    // A daytime interruption must silence buffered reverb as well as removing the sends.
    if (WetReturn && (Amount <= 0.f || LastAmount <= 0.f))
    {
        WetReturn->SetSubmixOutputVolume(this, Amount > 0.f ? 1.f : 0.f);
    }
    LastAmount = Amount;
    // Exponential frequency interpolation keeps the muffling audible before the last few frames.
    const float Cutoff = 20000.f * FMath::Pow(FMath::Clamp(MuffledCutoffHz, 80.f, 20000.f) / 20000.f, Amount);
    if (DayDirect) DayDirect->SetSubmixOutputVolume(this, FMath::Lerp(1.f, MuffledDryLevel, Amount));
    for (UAudioComponent* Voice : DayVoices)
    {
        Voice->SetLowPassFilterEnabled(Amount > 0.f);
        Voice->SetLowPassFilterFrequency(Cutoff);
        if (WetReturn) Voice->SetSubmixSend(WetReturn, Amount * PeakSend);
    }
    const float RingGain = RingingVolume * Amount;
    if (Amount <= 0.f) StopRinging();
    else if (IsValid(RingingVoice)) RingingVoice->SetVolumeMultiplier(RingGain);
    else if (RingGain > .001f) RingingVoice = CreateVoice(RingingSound, RingGain);
}

void UYIXIV3AudioComponent::StopRinging()
{
    if (!IsValid(RingingVoice)) return;
    RingingVoice->Stop();
    RingingVoice->DestroyComponent();
    RingingVoice = nullptr;
}

void UYIXIV3AudioComponent::StopDayVoices()
{
    for (UAudioComponent* Voice : DayVoices)
    {
        Voice->Stop();
        Voice->DestroyComponent();
    }
    DayVoices.Reset();
    bDayActive = false;
}

void UYIXIV3AudioComponent::CommitNightMix()
{
    if (bCut) return;
    bCut = true;
    CutGameTime = GetWorld()->GetTimeSeconds();
    StopDayVoices();
    RingingGainAtCut = RingingVolume * FMath::Max(0.f, LastAmount);
    SetComponentTickEnabled(true);
    // The dedicated reverb continues processing its buffered input after the sources stop.
    UE_LOG(LogTemp, Display, TEXT("YIXI_V3 DayDirectStopped frame=%llu clock=%.3f"), GFrameCounter, GetWorld()->GetTimeSeconds());
    if (NightDelay > 0.f)
        GetWorld()->GetTimerManager().SetTimer(NightTimer, this, &UYIXIV3AudioComponent::StartNight, NightDelay, false);
    else
        StartNight();
}

void UYIXIV3AudioComponent::TickComponent(float DeltaSeconds, ELevelTick TickType, FActorComponentTickFunction* TickFunction)
{
    Super::TickComponent(DeltaSeconds, TickType, TickFunction);
    if (!bCut) return;
    const float Fraction = FMath::Clamp(float(GetWorld()->GetTimeSeconds() - CutGameTime) / FMath::Max(.05f, TailSeconds), 0.f, 1.f);
    const float Taper = 1.f - FMath::SmoothStep(FMath::Clamp(TailTaperStart, 0.f, .95f), 1.f, Fraction);
    // The wet bus has its own decay. Let that decay through before easing its output to silence.
    if (WetReturn) WetReturn->SetSubmixOutputVolume(this, Taper);
    if (RingingVoice) RingingVoice->SetVolumeMultiplier(RingingGainAtCut * FMath::Lerp(1.f, .55f, Fraction) * Taper);
    if (Fraction >= 1.f)
    {
        StopRinging();
        SetComponentTickEnabled(false);
    }
}

void UYIXIV3AudioComponent::StartNight()
{
    if (bCut && !IsValid(NightVoice))
    {
        NightVoice = CreateVoice(NightAtmosphere, 1.f, NightFadeInSeconds);
        UE_LOG(LogTemp, Display, TEXT("YIXI_V3 NightAtmosphere frame=%llu clock=%.3f voice=%d"), GFrameCounter, GetWorld()->GetTimeSeconds(), IsValid(NightVoice));
    }
}

void UYIXIV3AudioComponent::EndNightPreview()
{
    GetWorld()->GetTimerManager().ClearTimer(NightTimer);
    SetComponentTickEnabled(false);
    StopRinging();
    if (bCut && WetReturn) WetReturn->SetSubmixOutputVolume(this, 0.f);
    RingingGainAtCut = 0.f;
    if (IsValid(NightVoice))
    {
        NightVoice->Stop();
        NightVoice->DestroyComponent();
        NightVoice = nullptr;
    }
    bCut = false;
}

void UYIXIV3AudioComponent::RestoreDayMix()
{
    EndNightPreview();
    BeginDayMix();
    LastAmount = -1.f;
    SetDayEcho(0.f);
}

void UYIXIV3AudioComponent::CancelDayMix()
{
    EndNightPreview();
    StopDayVoices();
    if (DayDirect) DayDirect->SetSubmixOutputVolume(this, 1.f);
    if (WetReturn) WetReturn->SetSubmixOutputVolume(this, 0.f);
}

void UYIXIV3AudioComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    EndNightPreview();
    StopDayVoices();
    if (DayDirect) DayDirect->SetSubmixOutputVolume(this, 1.f);
    if (WetReturn) WetReturn->SetSubmixOutputVolume(this, 1.f);
    Super::EndPlay(EndPlayReason);
}
