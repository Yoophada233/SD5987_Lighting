#include "YIXI_Interaction/DialogueToy/YIXIStoryGirl.h"

#include "Components/AudioComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundBase.h"
#include "SubtitleManager.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "YIXI_Interaction/YIXIInteractionHUDWidget.h"
#include "YIXI_Interaction/YIXIInteractorComponent.h"

#define LOCTEXT_NAMESPACE "YIXIStoryGirl"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIStoryGirlDialogue, Log, All);

namespace
{
	constexpr float PlaybackGuardInterval = 0.10f;
	constexpr double StartupGrace = 0.35;
}

AYIXIStoryGirl::AYIXIStoryGirl()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("StoryRoot")));

	GirlMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GirlMesh"));
	GirlMesh->SetupAttachment(GetRootComponent());
	GirlMesh->SetRelativeLocation(FVector(0.0, 0.0, 65.0));
	GirlMesh->SetRelativeScale3D(FVector(0.42, 0.42, 1.3));
	GirlMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	static const ConstructorHelpers::FObjectFinder<UStaticMesh> PlaceholderMesh(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	GirlMesh->SetStaticMesh(PlaceholderMesh.Object);

	GirlSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GirlSkeletalMesh"));
	GirlSkeletalMesh->SetupAttachment(GetRootComponent());
	GirlSkeletalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GirlSkeletalMesh->SetGenerateOverlapEvents(false);

	InteractionAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("InteractionAnchor"));
	InteractionAnchor->SetupAttachment(GetRootComponent());
	InteractionAnchor->SetRelativeLocation(FVector(0.0, 0.0, 110.0));

	VoiceAnchor = CreateDefaultSubobject<UAudioComponent>(TEXT("VoiceAnchor"));
	VoiceAnchor->SetupAttachment(GetRootComponent());
	VoiceAnchor->SetRelativeLocation(FVector(0.0, 0.0, 110.0));
	VoiceAnchor->SetAutoActivate(false);
	VoiceAnchor->bAllowSpatialization = true;
	VoiceAnchor->bOverrideAttenuation = true;
	VoiceAnchor->AttenuationOverrides.bAttenuate = true;
	VoiceAnchor->AttenuationOverrides.bSpatialize = true;

	RequestDialogue = LOCTEXT("RequestDialogue", "Could you look for my toy in the back courtyard?");
}

void AYIXIStoryGirl::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
#if WITH_EDITOR
	if (GetWorld() && !GetWorld()->IsGameWorld())
	{
		GirlMesh->SetIsTemporarilyHiddenInEditor(GirlSkeletalMesh->GetSkeletalMeshAsset() != nullptr);
	}
#endif
}

void AYIXIStoryGirl::BeginPlay()
{
	GirlSkeletalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GirlSkeletalMesh->SetGenerateOverlapEvents(false);
	GirlSkeletalMesh->SetSimulatePhysics(false);
	if (GirlSkeletalMesh->GetSkeletalMeshAsset())
	{
		GirlMesh->SetHiddenInGame(true);
	}
	Super::BeginPlay();
	if (!bRequestGateSet)
	{
		SetRequestAvailable(bStartRequestAvailable);
	}
}

void AYIXIStoryGirl::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	StopVoice();
	Super::EndPlay(EndPlayReason);
}

void AYIXIStoryGirl::SetRequestAvailable(bool bAvailable)
{
	bRequestGateSet = true;
	if (RequestState == EYIXIStoryGirlState::Waiting || RequestState == EYIXIStoryGirlState::RequestReady)
	{
		RequestState = bAvailable ? EYIXIStoryGirlState::RequestReady : EYIXIStoryGirlState::Waiting;
	}
}

void AYIXIStoryGirl::SetUnavailable()
{
	bRequestGateSet = true;
	RequestState = EYIXIStoryGirlState::Unavailable;
	StopVoice();
}

bool AYIXIStoryGirl::IsVoicePlaying() const
{
	return (IsValid(VoiceAnchor) && VoiceAnchor->IsPlaying())
		|| (IsValid(PlayerDialogueVoiceComponent) && PlayerDialogueVoiceComponent->IsPlaying());
}

void AYIXIStoryGirl::StopVoice()
{
	FinishDialogue(true, TEXT("Stopped"));
	if (IsValid(VoiceAnchor) && VoiceAnchor->IsPlaying())
	{
		VoiceAnchor->Stop();
	}
}

bool AYIXIStoryGirl::HasAvailableDialogue() const
{
	return RequestState == EYIXIStoryGirlState::RequestReady
		|| RequestState == EYIXIStoryGirlState::Requested;
}

bool AYIXIStoryGirl::CanInteract_Implementation(APawn* Interactor) const
{
	return HasAvailableDialogue()
		&& IsValid(Interactor)
		&& Interactor->IsPlayerControlled()
		&& Interactor->GetWorld() == GetWorld();
}

void AYIXIStoryGirl::Interact_Implementation(APawn* Interactor)
{
	if (!IYIXIInteractable::Execute_CanInteract(this, Interactor))
	{
		return;
	}
	if (DialoguePhase != EYIXIStoryGirlDialoguePhase::Idle)
	{
		return;
	}

	if (RequestState == EYIXIStoryGirlState::RequestReady)
	{
		RequestState = EYIXIStoryGirlState::Requested;
		APlayerController* Controller = Cast<APlayerController>(Interactor->GetController());
		if (Controller && IsValid(RequestVoice) && IsValid(PlayerReplyVoice))
		{
			StartRequestDialogue(*Interactor, *Controller);
		}
		else
		{
			PlayVoice(RequestVoice);
		}
		OnToyRequested.Broadcast(Interactor);
	}
	else if (RequestState == EYIXIStoryGirlState::Requested)
	{
		if (IsVoicePlaying())
		{
			return;
		}
		PlayVoice(ReminderVoice);
		if (const APlayerController* Controller = Cast<APlayerController>(Interactor->GetController());
			Controller && Controller->IsLocalController())
		{
			constexpr float ReminderDuration = 3.0f;
			TArray<FSubtitleCue> Cues;
			FSubtitleCue& Cue = Cues.AddDefaulted_GetRef();
			Cue.Text = LOCTEXT("ReminderDialogue", "我把玩具落在后院了。");
			Cue.Time = 0.0f;
			FSubtitleManager::GetSubtitleManager()->QueueSubtitles(
				reinterpret_cast<PTRINT>(this), 1.0f, false, true,
				ReminderDuration, Cues, 0.0f, GetWorld()->GetAudioTimeSeconds());
		}
	}
}

bool AYIXIStoryGirl::IsDialogueValid(uint32 Session) const
{
	const APawn* Pawn = DialoguePawn.Get();
	const APlayerController* Controller = DialogueController.Get();
	return Session == DialogueSession && DialoguePhase != EYIXIStoryGirlDialoguePhase::Idle
		&& RequestState == EYIXIStoryGirlState::Requested && !IsActorBeingDestroyed()
		&& Pawn && !Pawn->IsActorBeingDestroyed() && Pawn->GetWorld() == GetWorld()
		&& Controller && Controller->GetPawn() == Pawn;
}

void AYIXIStoryGirl::StartRequestDialogue(APawn& Pawn, APlayerController& Controller)
{
	if (!IsValid(VoiceAnchor) || IsVoicePlaying())
	{
		return;
	}

	DialoguePawn = &Pawn;
	DialogueController = &Controller;
	if (bDialogueSubtitlesEnabled)
	{
		DialogueHUD = UYIXIInteractorComponent::FindDialogueHUD(Controller);
	}
	DialoguePhase = EYIXIStoryGirlDialoguePhase::Girl;
	++DialogueSession;
	Pawn.OnEndPlay.AddUniqueDynamic(this, &ThisClass::OnDialoguePawnEndPlay);
	Controller.OnPossessedPawnChanged.AddUniqueDynamic(this, &ThisClass::OnDialoguePawnChanged);
	GetWorld()->GetTimerManager().SetTimer(DialogueWatchTimer,
		FTimerDelegate::CreateUObject(this, &ThisClass::CheckDialoguePlayback, DialogueSession),
		PlaybackGuardInterval, true);
	StartDialogueClip(*VoiceAnchor, *RequestVoice, RequestDialogue, VoiceVolume, VoiceAttenuation);

	if (DialoguePhase == EYIXIStoryGirlDialoguePhase::Girl && !RequestFollowUpSubtitle.IsEmpty()
		&& RequestFollowUpSubtitleTime > 0.0f && RequestFollowUpSubtitleTime < ClipDuration)
	{
		GetWorld()->GetTimerManager().SetTimer(SubtitleCueTimer,
			FTimerDelegate::CreateUObject(this, &ThisClass::ShowRequestFollowUp, DialogueSession),
			RequestFollowUpSubtitleTime, false);
	}
}

void AYIXIStoryGirl::StartDialogueClip(UAudioComponent& Component, USoundBase& Sound, const FText& Line,
	float Volume, USoundAttenuation* Attenuation)
{
	ClipDuration = Sound.GetDuration();
	if (Sound.IsLooping() || !FMath::IsFinite(ClipDuration) || ClipDuration <= 0.0f || Volume <= 0.0f)
	{
		FinishDialogue(true, TEXT("Dialogue requires a finite, audible clip"));
		return;
	}

	ClipStartedAt = GetWorld()->GetAudioTimeSeconds();
	DialogueClip = &Component;
	ClipFinishedHandle = Component.OnAudioFinishedNative.AddUObject(this, &ThisClass::OnDialogueClipFinished,
		DialogueSession, DialoguePhase);
	ClipStateHandle = Component.OnAudioPlayStateChangedNative.AddUObject(this, &ThisClass::OnDialogueClipStateChanged,
		DialogueSession);
	bClipPreviouslySuppressedSubtitles = Component.bSuppressSubtitles;
	Component.bSuppressSubtitles = true;
	Component.AttenuationSettings = Attenuation;
	Component.bOverrideAttenuation = !IsValid(Attenuation);
	Component.SetSound(&Sound);
	Component.SetVolumeMultiplier(Volume);
	Component.Play();
	if (DialogueClip.Get() != &Component)
	{
		return;
	}
	if (UYIXIInteractionHUDWidget* HUD = DialogueHUD.Get())
	{
		HUD->ShowDialogueSubtitle(this, Line);
	}
	UE_LOG(LogYIXIStoryGirlDialogue, Display, TEXT("Clip started phase=%s session=%u clip=%s duration=%.3f audioTime=%.3f owner=%s position=%s"),
		*UEnum::GetValueAsString(DialoguePhase), DialogueSession, *Sound.GetName(), ClipDuration, ClipStartedAt,
		*GetNameSafe(Component.GetOwner()), *Component.GetComponentLocation().ToCompactString());
}

void AYIXIStoryGirl::ShowRequestFollowUp(uint32 Session)
{
	if (IsDialogueValid(Session) && DialoguePhase == EYIXIStoryGirlDialoguePhase::Girl
		&& DialogueClip.IsValid() && DialogueClip->IsPlaying())
	{
		if (UYIXIInteractionHUDWidget* HUD = DialogueHUD.Get())
		{
			HUD->UpdateDialogueSubtitle(this, RequestFollowUpSubtitle);
		}
	}
}

void AYIXIStoryGirl::OnDialogueClipFinished(UAudioComponent* Component, uint32 Session, EYIXIStoryGirlDialoguePhase Phase)
{
	if (Session != DialogueSession || Phase != DialoguePhase || Component != DialogueClip.Get())
	{
		return;
	}
	const UWorld* World = GetWorld();
	if (!World || !IsDialogueValid(Session))
	{
		FinishDialogue(true, TEXT("Clip interrupted"));
		return;
	}
	const double Elapsed = World->GetAudioTimeSeconds() - ClipStartedAt;
	UE_LOG(LogYIXIStoryGirlDialogue, Display, TEXT("Clip finished phase=%s session=%u elapsed=%.3f audioTime=%.3f"),
		*UEnum::GetValueAsString(Phase), Session, Elapsed, GetWorld()->GetAudioTimeSeconds());
	UnbindDialogueClip();
	GetWorld()->GetTimerManager().ClearTimer(SubtitleCueTimer);
	if (Phase == EYIXIStoryGirlDialoguePhase::Player)
	{
		FinishDialogue(false, TEXT("Complete"));
		return;
	}

	if (UYIXIInteractionHUDWidget* HUD = DialogueHUD.Get())
	{
		HUD->HideDialogueSubtitle(this, false);
	}
	DialoguePhase = EYIXIStoryGirlDialoguePhase::Gap;
	if (DialogueGap > 0.0f)
	{
		GetWorld()->GetTimerManager().SetTimer(DialogueGapTimer,
			FTimerDelegate::CreateUObject(this, &ThisClass::StartPlayerReply, Session), DialogueGap, false);
	}
	else
	{
		StartPlayerReply(Session);
	}
}

void AYIXIStoryGirl::OnDialogueClipStateChanged(const UAudioComponent* Component, EAudioComponentPlayState State,
	uint32 Session)
{
	// Direct Stop publishes Stopped before completion. A natural finish unbinds this listener
	// in OnAudioFinishedNative before the engine publishes its final play state.
	if (Session == DialogueSession && Component == DialogueClip.Get()
		&& (State == EAudioComponentPlayState::Stopped || State == EAudioComponentPlayState::FadingOut))
	{
		FinishDialogue(true, TEXT("Audio stopped or faded out"));
	}
}

void AYIXIStoryGirl::StartPlayerReply(uint32 Session)
{
	if (Session != DialogueSession || DialoguePhase != EYIXIStoryGirlDialoguePhase::Gap)
	{
		return;
	}
	if (!IsDialogueValid(Session) || !IsValid(PlayerReplyVoice) || !IsValid(DialoguePawn->GetRootComponent()))
	{
		FinishDialogue(true, TEXT("Player voice source unavailable"));
		return;
	}

	APawn* Pawn = DialoguePawn.Get();
	USceneComponent* Root = Pawn->GetRootComponent();
	UAudioComponent* Reply = NewObject<UAudioComponent>(Pawn);
	PlayerDialogueVoiceComponent = Reply;
	Reply->SetAutoActivate(false);
	Reply->bAllowSpatialization = true;
	Reply->AttenuationOverrides.bAttenuate = true;
	Reply->AttenuationOverrides.bSpatialize = true;
	Reply->SetupAttachment(Root);
	Reply->SetRelativeLocation(Root->GetComponentTransform().InverseTransformPosition(Pawn->GetPawnViewLocation()));
	Reply->RegisterComponent();
	DialoguePhase = EYIXIStoryGirlDialoguePhase::Player;
	StartDialogueClip(*Reply, *PlayerReplyVoice, PlayerReplySubtitle, PlayerVoiceVolume, PlayerVoiceAttenuation);
}

void AYIXIStoryGirl::CheckDialoguePlayback(uint32 Session)
{
	if (Session != DialogueSession)
	{
		return;
	}
	if (!IsDialogueValid(Session))
	{
		FinishDialogue(true, TEXT("Dialogue participant changed"));
	}
	else if (DialoguePhase != EYIXIStoryGirlDialoguePhase::Gap
		&& GetWorld()->GetAudioTimeSeconds() - ClipStartedAt > StartupGrace
		&& (!DialogueClip.IsValid() || !DialogueClip->IsPlaying()))
	{
		// Failed audio-device startup can skip OnAudioFinished entirely.
		FinishDialogue(true, TEXT("No active audio playback"));
	}
}

void AYIXIStoryGirl::OnDialoguePawnChanged(APawn* OldPawn, APawn* NewPawn)
{
	if (NewPawn != DialoguePawn.Get())
	{
		FinishDialogue(true, TEXT("Player possessed another Pawn"));
	}
}

void AYIXIStoryGirl::OnDialoguePawnEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
	FinishDialogue(true, TEXT("Player Pawn ended play"));
}

void AYIXIStoryGirl::UnbindDialogueClip()
{
	if (UAudioComponent* Component = DialogueClip.Get())
	{
		Component->OnAudioFinishedNative.Remove(ClipFinishedHandle);
		Component->OnAudioPlayStateChangedNative.Remove(ClipStateHandle);
		Component->bSuppressSubtitles = bClipPreviouslySuppressedSubtitles;
	}
	ClipFinishedHandle.Reset();
	ClipStateHandle.Reset();
	DialogueClip.Reset();
}

void AYIXIStoryGirl::FinishDialogue(bool bCancelled, const TCHAR* Reason)
{
	if (DialoguePhase == EYIXIStoryGirlDialoguePhase::Idle)
	{
		return;
	}
	const uint32 EndingSession = DialogueSession++;
	DialoguePhase = EYIXIStoryGirlDialoguePhase::Idle;
	UAudioComponent* Clip = DialogueClip.Get();
	UnbindDialogueClip();
	if (UWorld* World = GetWorld())
	{
		FTimerManager& Timers = World->GetTimerManager();
		Timers.ClearTimer(DialogueWatchTimer);
		Timers.ClearTimer(DialogueGapTimer);
		Timers.ClearTimer(SubtitleCueTimer);
	}
	if (APawn* Pawn = DialoguePawn.Get())
	{
		Pawn->OnEndPlay.RemoveDynamic(this, &ThisClass::OnDialoguePawnEndPlay);
	}
	if (APlayerController* Controller = DialogueController.Get())
	{
		Controller->OnPossessedPawnChanged.RemoveDynamic(this, &ThisClass::OnDialoguePawnChanged);
	}
	if (UYIXIInteractionHUDWidget* HUD = DialogueHUD.Get())
	{
		HUD->HideDialogueSubtitle(this, bCancelled);
	}
	DialogueHUD.Reset();
	DialoguePawn.Reset();
	DialogueController.Reset();
	if (bCancelled && IsValid(Clip))
	{
		Clip->Stop();
	}
	if (IsValid(PlayerDialogueVoiceComponent))
	{
		PlayerDialogueVoiceComponent->DestroyComponent();
	}
	PlayerDialogueVoiceComponent = nullptr;
	UE_LOG(LogYIXIStoryGirlDialogue, Display, TEXT("Dialogue ended session=%u cancelled=%d reason=%s"),
		EndingSession, bCancelled, Reason);
}

void AYIXIStoryGirl::PlayVoice(USoundBase* Sound)
{
	if (!IsValid(Sound) || !IsValid(VoiceAnchor) || VoiceVolume <= 0.0f || IsVoicePlaying())
	{
		return;
	}

	VoiceAnchor->AttenuationSettings = VoiceAttenuation;
	VoiceAnchor->bOverrideAttenuation = !IsValid(VoiceAttenuation);
	VoiceAnchor->SetVolumeMultiplier(VoiceVolume);
	VoiceAnchor->SetSound(Sound);
	VoiceAnchor->Play();
}

FYIXIInteractionPrompt AYIXIStoryGirl::GetInteractionPrompt_Implementation(APawn* Interactor) const
{
	FYIXIInteractionPrompt Prompt;
	Prompt.WorldLocation = InteractionAnchor->GetComponentLocation();
	Prompt.bShowPrompt = HasAvailableDialogue();
	Prompt.DetectionRange = Prompt.bShowPrompt ? DetectionRange : 0.0f;
	Prompt.InteractRange = Prompt.bShowPrompt ? InteractRange : 0.0f;
	Prompt.ActionText = LOCTEXT("AskAboutToy", "Talk");
	return Prompt;
}

#undef LOCTEXT_NAMESPACE
