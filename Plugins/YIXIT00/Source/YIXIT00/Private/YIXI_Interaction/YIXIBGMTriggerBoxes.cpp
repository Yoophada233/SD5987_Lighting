#include "YIXI_Interaction/YIXIBGMTriggerBoxes.h"

#include "Components/AudioComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"

namespace
{
	bool IsLocalPlayerPawn(const APawn* Pawn)
	{
		const APlayerController* Controller = IsValid(Pawn) ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
		return IsValid(Controller) && Controller->IsLocalController() && Controller->GetPawn() == Pawn;
	}
}

AYIXIBGMStartBox::AYIXIBGMStartBox()
{
	MusicAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("MusicAudio"));
	MusicAudio->SetupAttachment(GetRootComponent());
	MusicAudio->SetAutoActivate(false);
	MusicAudio->bAutoDestroy = false;
	MusicAudio->bAllowSpatialization = false;
	MusicAudio->bIsMusic = true;
	MusicAudio->bReverb = false;
	MusicAudio->bSuppressSubtitles = true;
}

void AYIXIBGMStartBox::BeginPlay()
{
	bHasPlayed = false;
	OnPlayerEntered.AddUniqueDynamic(this, &ThisClass::OnLocalPlayerEntered);
	Super::BeginPlay();
}

void AYIXIBGMStartBox::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	OnPlayerEntered.RemoveDynamic(this, &ThisClass::OnLocalPlayerEntered);
	GetWorldTimerManager().ClearTimer(PlaybackDelayTimer);
	MusicAudio->Stop();
	Super::EndPlay(EndPlayReason);
}

void AYIXIBGMStartBox::OnLocalPlayerEntered(APawn* Pawn)
{
	FTimerManager& Timers = GetWorldTimerManager();
	if (!IsLocalPlayerPawn(Pawn) || !CanStartMusic() || Timers.TimerExists(PlaybackDelayTimer))
	{
		return;
	}

	if (FMath::IsFinite(PlaybackDelay) && PlaybackDelay > 0.0f)
	{
		Timers.SetTimer(PlaybackDelayTimer, this, &ThisClass::StartMusic, PlaybackDelay, false);
	}
	else
	{
		StartMusic();
	}
}

bool AYIXIBGMStartBox::CanStartMusic() const
{
	return IsValid(MusicSound) && MusicVolume > 0.0f
		&& (!bPlayOnce || !bHasPlayed) && !MusicAudio->IsPlaying();
}

void AYIXIBGMStartBox::StartMusic()
{
	if (!CanStartMusic())
	{
		return;
	}

	MusicAudio->SetSound(MusicSound);
	MusicAudio->SetVolumeMultiplier(MusicVolume);
	MusicAudio->FadeIn(FMath::Max(0.0f, FadeInDuration), 1.0f, 0.0f, EAudioFaderCurve::SCurve);
	bHasPlayed = MusicAudio->IsPlaying();
}

void AYIXIBGMStartBox::FadeOutMusic(float Duration)
{
	GetWorldTimerManager().ClearTimer(PlaybackDelayTimer);
	if (!MusicAudio->IsPlaying() || MusicAudio->GetPlayState() == EAudioComponentPlayState::FadingOut)
	{
		return;
	}

	if (Duration > 0.0f)
	{
		MusicAudio->FadeOut(Duration, 0.0f, EAudioFaderCurve::SCurve);
	}
	else
	{
		MusicAudio->Stop();
	}
}

void AYIXIBGMStopBox::BeginPlay()
{
	OnPlayerEntered.AddUniqueDynamic(this, &ThisClass::OnLocalPlayerEntered);
	Super::BeginPlay();
}

void AYIXIBGMStopBox::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	OnPlayerEntered.RemoveDynamic(this, &ThisClass::OnLocalPlayerEntered);
	Super::EndPlay(EndPlayReason);
}

void AYIXIBGMStopBox::OnLocalPlayerEntered(APawn* Pawn)
{
	if (IsLocalPlayerPawn(Pawn) && IsValid(TargetBGMBox) && !TargetBGMBox->IsActorBeingDestroyed()
		&& TargetBGMBox->GetWorld() == GetWorld())
	{
		TargetBGMBox->FadeOutMusic(FadeOutDuration);
	}
}
