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
#include "UObject/ConstructorHelpers.h"

#define LOCTEXT_NAMESPACE "YIXIStoryGirl"

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
	return IsValid(VoiceAnchor) && VoiceAnchor->IsPlaying();
}

void AYIXIStoryGirl::StopVoice()
{
	// Neither completion nor an explicit stop should change the request gate.
	if (IsValid(VoiceAnchor))
	{
		VoiceAnchor->Stop();
	}
	FSubtitleManager::GetSubtitleManager()->KillSubtitles(reinterpret_cast<PTRINT>(this));
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

	if (RequestState == EYIXIStoryGirlState::RequestReady)
	{
		RequestState = EYIXIStoryGirlState::Requested;
		PlayVoice(RequestVoice);
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
