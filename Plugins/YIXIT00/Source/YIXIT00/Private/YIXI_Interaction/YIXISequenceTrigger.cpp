#include "YIXI_Interaction/YIXISequenceTrigger.h"

#include "Bindings/MovieSceneCustomBinding.h"
#include "Components/ActorComponent.h"
#include "Engine/Level.h"
#include "Engine/World.h"
#include "EntitySystem/MovieSceneSharedPlaybackState.h"
#include "Evaluation/MovieSceneSequenceHierarchy.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "IMovieScenePlaybackClient.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "MovieScene.h"
#include "MovieSceneBinding.h"
#include "MovieSceneBindingReferences.h"
#include "MovieSceneObjectBindingID.h"
#include "MovieScenePossessable.h"
#include "MovieSceneSpawnable.h"
#include "UObject/UnrealType.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXISequenceTrigger, Log, All);

namespace
{
using namespace UE::MovieScene;

// Bindings whose objects will be spawned by Sequencer cannot be resolved before evaluation.
bool IsSpawnedBySequence(const UMovieSceneSequence& Sequence, UMovieScene& Scene, const ALevelSequenceActor& Actor,
	FGuid BindingID, FMovieSceneSequenceID SequenceID, const TSharedRef<const FSharedPlaybackState>& State)
{
	for (int32 Depth = 0; BindingID.IsValid() && Depth <= Scene.GetPossessableCount(); ++Depth)
	{
		TArray<UObject*, TInlineAllocator<1>> Overrides;
		if (!static_cast<const IMovieScenePlaybackClient&>(Actor).RetrieveBindingOverrides(BindingID, SequenceID, Overrides))
		{
			// An override can explicitly replace even a spawnable and prevent its default object from spawning.
			return false;
		}
		if (Scene.FindSpawnable(BindingID))
		{
			return true;
		}
		if (const FMovieSceneBindingReferences* References = Sequence.GetBindingReferences())
		{
			for (const FMovieSceneBindingReference& Reference : References->GetReferences(BindingID))
			{
				if (Reference.CustomBinding && Reference.CustomBinding->WillSpawnObject(State))
				{
					return true;
				}
			}
		}
		const FMovieScenePossessable* Possessable = Scene.FindPossessable(BindingID);
		BindingID = Possessable ? Possessable->GetParent() : FGuid();
	}
	return false;
}

bool CheckBindings(ULevelSequencePlayer& Player, const UMovieSceneSequence& Sequence,
	FMovieSceneSequenceID SequenceID, const TSharedRef<const FSharedPlaybackState>& State,
	const ALevelSequenceActor& PlaybackActor, const AActor& Trigger)
{
	UMovieScene* Scene = Sequence.GetMovieScene();
	if (!Scene)
	{
		return false;
	}
	for (const FMovieSceneBinding& Binding : AsConst(*Scene).GetBindings())
	{
		const FGuid& BindingID = Binding.GetObjectGuid();
		if (IsSpawnedBySequence(Sequence, *Scene, PlaybackActor, BindingID, SequenceID, State))
		{
			continue;
		}

		const TArray<UObject*> Objects = Player.GetBoundObjects(FFixedObjectBindingID(BindingID, SequenceID));
		const bool bHasTarget = Objects.ContainsByPredicate([&Trigger](const UObject* Object)
		{
			const AActor* Actor = Cast<AActor>(Object);
			if (const UActorComponent* Component = Cast<UActorComponent>(Object))
			{
				Actor = Component->GetOwner();
				if (!IsValid(Actor))
				{
					return false;
				}
			}
			return IsValid(Object) && (!Actor ||
				(IsValid(Actor) && !Actor->IsActorBeingDestroyed() && Actor->GetWorld() == Trigger.GetWorld()
					&& Actor->GetLevel() && Actor->GetLevel()->bIsVisible && !Actor->GetLevel()->bIsBeingRemoved));
		});
		if (!bHasTarget)
		{
			const FMovieScenePossessable* Possessable = Scene->FindPossessable(BindingID);
			const FMovieSceneSpawnable* Spawnable = Scene->FindSpawnable(BindingID);
			const FString BindingName = Possessable ? Possessable->GetName() : Spawnable ? Spawnable->GetName() : TEXT("Unnamed");
			UE_LOG(LogYIXISequenceTrigger, Warning,
				TEXT("%s [%s]: '%s' binding '%s' (%s) has no loaded target. Check the binding or load its level before retrying."),
				*Trigger.GetActorNameOrLabel(), *Trigger.GetPathName(), *Sequence.GetPathName(),
				*BindingName, *BindingID.ToString());
			return false;
		}
	}
	return true;
}

FMovieSceneSequencePlaybackSettings CaptureSettings(const ULevelSequencePlayer& Player, const ALevelSequenceActor& Actor)
{
	// The player exposes a settings setter but no full getter. Preserve runtime edits as well as authored settings.
	static const FStructProperty* Property = FindFProperty<FStructProperty>(
		UMovieSceneSequencePlayer::StaticClass(), TEXT("PlaybackSettings"));
	return Property && Property->Struct == FMovieSceneSequencePlaybackSettings::StaticStruct()
		? *Property->ContainerPtrToValuePtr<FMovieSceneSequencePlaybackSettings>(&Player)
		: Actor.PlaybackSettings;
}
}

void AYIXISequenceTrigger::BeginPlay()
{
	bEndingPlay = false;
	bHasTriggered = false;
	OnPlayerEntered.AddUniqueDynamic(this, &ThisClass::HandlePlayerEntered);
	Super::BeginPlay();

	const ALevelSequenceActor* ExistingActor = ExistingSequenceActor.Get();
	if (bEnabled && IsValid(ExistingActor) && ExistingActor->PlaybackSettings.bAutoPlay)
	{
		WarnAutoPlay(*ExistingActor);
	}
}

void AYIXISequenceTrigger::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	bEndingPlay = true;
	OnPlayerEntered.RemoveDynamic(this, &ThisClass::HandlePlayerEntered);
	StopSequence();
	ClearPlayback();
	if (IsValid(OwnedSequenceActor) && !OwnedSequenceActor->IsActorBeingDestroyed())
	{
		const ULevelSequencePlayer* Player = OwnedSequenceActor->GetSequencePlayer();
		if (IsValid(Player) && Player->IsEvaluating())
		{
			// A sequence event can destroy the trigger during evaluation. Let the deferred stop run first.
			OwnedSequenceActor->SetLifeSpan(UE_KINDA_SMALL_NUMBER);
		}
		else
		{
			OwnedSequenceActor->Destroy();
		}
	}
	OwnedSequenceActor = nullptr;
	Super::EndPlay(EndPlayReason);
}

void AYIXISequenceTrigger::HandlePlayerEntered(APawn* Pawn)
{
	const APlayerController* Controller = IsValid(Pawn) ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
	if (IsValid(Controller) && Controller->IsLocalController() && ContainsPawn(Pawn))
	{
		PlaySequence();
	}
}

bool AYIXISequenceTrigger::PlaySequence()
{
	UWorld* World = GetWorld();
	if (!bEnabled || bEndingPlay || !HasActorBegunPlay() || IsActorBeingDestroyed()
		|| !World || World->bIsTearingDown || (bTriggerOnce && bHasTriggered) || ActivePlayer.IsValid())
	{
		return false;
	}
	if (!FMath::IsFinite(PlayRate) || PlayRate <= 0.0f)
	{
		UE_LOG(LogYIXISequenceTrigger, Warning, TEXT("%s: Play Rate must be a finite positive value."), *GetActorNameOrLabel());
		return false;
	}

	ALevelSequenceActor* Actor = GetOrCreatePlaybackActor();
	if (!Actor)
	{
		return false;
	}
	if (Actor->PlaybackSettings.bAutoPlay)
	{
		WarnAutoPlay(*Actor);
		return false;
	}

	ULevelSequence* Sequence = Actor->GetSequence();
	ULevelSequencePlayer* Player = Actor->GetSequencePlayer();
	if (!IsValid(Sequence) || !IsValid(Player) || Player->GetSequence() != Sequence
		|| Player->GetDuration().Time.AsDecimal() <= 0.0)
	{
		UE_LOG(LogYIXISequenceTrigger, Warning,
			TEXT("%s: '%s' has no initialized Level Sequence with a positive playback range."),
			*GetActorNameOrLabel(), *Actor->GetPathName());
		return false;
	}
	if (Player->IsPlaying() || Player->IsPaused() || Player->IsEvaluating())
	{
		return false;
	}

	const TSharedPtr<UE::MovieScene::FSharedPlaybackState> State = Player->FindSharedPlaybackState();
	if (!State)
	{
		UE_LOG(LogYIXISequenceTrigger, Warning, TEXT("%s: the Sequence Player has no playback state."), *GetActorNameOrLabel());
		return false;
	}
	// A previous attempt might have resolved an unloaded level to no objects.
	State->ClearObjectCaches();
	if (!CheckBindings(*Player, *Sequence, MovieSceneSequenceID::Root, State.ToSharedRef(), *Actor, *this))
	{
		return false;
	}
	if (const FMovieSceneSequenceHierarchy* Hierarchy = State->GetHierarchy())
	{
		for (const auto& Entry : Hierarchy->AllSubSequenceData())
		{
			const UMovieSceneSequence* Child = Entry.Value.GetSequence();
			if (!IsValid(Child))
			{
				UE_LOG(LogYIXISequenceTrigger, Warning, TEXT("%s: '%s' has an unavailable subsequence."),
					*GetActorNameOrLabel(), *Sequence->GetPathName());
				return false;
			}
			if (!CheckBindings(*Player, *Child, Entry.Key, State.ToSharedRef(), *Actor, *this))
			{
				return false;
			}
		}
	}

	PreviousSettings = CaptureSettings(*Player, *Actor);
	FMovieSceneSequencePlaybackSettings Settings = PreviousSettings;
	Settings.LoopCount.Value = bLoopPlayback ? -1 : 0;
	Settings.PlayRate = PlayRate;
	Settings.bPauseAtEnd = false;
	Player->SetPlaybackSettings(Settings);

	ActivePlayer = Player;
	Player->OnPlay.AddUniqueDynamic(this, &ThisClass::HandlePlaybackStarted);
	// Native natural finish also stops the player when Pause at End is off.
	Player->OnStop.AddUniqueDynamic(this, &ThisClass::ClearPlayback);
	Player->SetPlaybackPosition(FMovieSceneSequencePlaybackParams(Player->GetStartTime().Time, EUpdatePositionMethod::Jump));
	if (ActivePlayer.Get() != Player || bEndingPlay)
	{
		return false;
	}
	Player->Play();
	if (IsValid(Player) && Player->IsPlaying())
	{
		return true;
	}
	ClearPlayback();
	UE_LOG(LogYIXISequenceTrigger, Warning, TEXT("%s: the Sequence Player did not start."), *GetActorNameOrLabel());
	return false;
}

void AYIXISequenceTrigger::HandlePlaybackStarted()
{
	bHasTriggered = true;
}

void AYIXISequenceTrigger::StopSequence()
{
	if (ULevelSequencePlayer* Player = ActivePlayer.Get())
	{
		if (Player->IsPlaying() || Player->IsPaused())
		{
			Player->StopAtCurrentTime();
			return;
		}
	}
	ClearPlayback();
}

void AYIXISequenceTrigger::ClearPlayback()
{
	if (ULevelSequencePlayer* Player = ActivePlayer.Get())
	{
		Player->OnPlay.RemoveDynamic(this, &ThisClass::HandlePlaybackStarted);
		Player->OnStop.RemoveDynamic(this, &ThisClass::ClearPlayback);
		Player->SetPlaybackSettings(PreviousSettings);
	}
	ActivePlayer.Reset();
}

void AYIXISequenceTrigger::ResetTrigger()
{
	bHasTriggered = false;
}

ALevelSequenceActor* AYIXISequenceTrigger::GetOrCreatePlaybackActor()
{
	if (!ExistingSequenceActor.IsNull())
	{
		ALevelSequenceActor* Actor = ExistingSequenceActor.Get();
		if (!IsValid(Actor) || Actor->IsActorBeingDestroyed() || Actor->GetWorld() != GetWorld()
			|| !Actor->HasActorBegunPlay())
		{
			UE_LOG(LogYIXISequenceTrigger, Warning, TEXT("%s: Existing Sequence Actor '%s' is not loaded for play."),
				*GetActorNameOrLabel(), *ExistingSequenceActor.ToSoftObjectPath().ToString());
			return nullptr;
		}
		return Actor;
	}
	if (!IsValid(SequenceAsset))
	{
		UE_LOG(LogYIXISequenceTrigger, Warning, TEXT("%s: assign a Sequence Asset or Existing Sequence Actor."), *GetActorNameOrLabel());
		return nullptr;
	}
	if (IsValid(OwnedSequenceActor))
	{
		if (OwnedSequenceActor->GetSequence() != SequenceAsset)
		{
			OwnedSequenceActor->SetSequence(SequenceAsset);
		}
		return OwnedSequenceActor;
	}

	// Locators resolve relative to the player's level. Use the trigger's actual streamed level.
	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.OverrideLevel = GetLevel();
	Params.ObjectFlags |= RF_Transient;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Params.bDeferConstruction = true;
	OwnedSequenceActor = GetWorld()->SpawnActor<ALevelSequenceActor>(Params);
	if (OwnedSequenceActor)
	{
		OwnedSequenceActor->SetSequence(SequenceAsset);
		OwnedSequenceActor->FinishSpawning(FTransform::Identity);
	}
	else
	{
		UE_LOG(LogYIXISequenceTrigger, Warning, TEXT("%s: couldn't create a player for '%s'."),
			*GetActorNameOrLabel(), *SequenceAsset->GetPathName());
	}
	return OwnedSequenceActor;
}

void AYIXISequenceTrigger::WarnAutoPlay(const ALevelSequenceActor& Actor) const
{
	UE_LOG(LogYIXISequenceTrigger, Warning,
		TEXT("%s: turn off Auto Play on Existing Sequence Actor '%s' so this box can start it."),
		*GetActorNameOrLabel(), *Actor.GetPathName());
}
