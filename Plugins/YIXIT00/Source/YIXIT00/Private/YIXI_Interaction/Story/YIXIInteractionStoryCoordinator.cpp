#include "YIXI_Interaction/Story/YIXIInteractionStoryCoordinator.h"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "YIXI_Interaction/DialogueToy/YIXIStoryGirl.h"
#include "YIXI_Interaction/DialogueToy/YIXIStoryToyPickup.h"
#include "YIXI_Interaction/DialogueToy/YIXIToyCarryComponent.h"
#include "YIXI_Interaction/ScriptedProjectile/YIXIScriptedRock.h"
#include "YIXI_Interaction/ScriptedProjectile/YIXIStoryTriggerBox.h"
#include "YIXI_Interaction/YIXIAudioTriggerBox.h"
#include "YIXI_Interaction/YIXIDoubleDoor.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIInteractionStory, Log, All);

AYIXIInteractionStoryCoordinator::AYIXIInteractionStoryCoordinator()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AYIXIInteractionStoryCoordinator::BeginPlay()
{
	Super::BeginPlay();

	const AActor* RequiredActors[] = {
		ClassroomDoor, CorridorAudio, RoadRock, BypassTrigger, Girl, ToyPickup, ReturnTrigger, AttackCue, DiscoveryTrigger
	};
	TSet<const AActor*> UniqueActors;
	for (const AActor* Actor : RequiredActors)
	{
		if (!IsValid(Actor) || Actor->GetWorld() != GetWorld() || UniqueActors.Contains(Actor))
		{
			StopStory(TEXT("assign one valid actor in this world to each story role"));
			return;
		}
		UniqueActors.Add(Actor);
	}
	if (!CorridorAudio->bTriggerOnce || CorridorAudio->TriggerCount != 0
		|| !RoadRock->bEnableBlockageAfterImpact || AttackCue->bEnableBlockageAfterImpact
		|| (GirlAftermath && (!IsValid(GirlAftermath) || GirlAftermath->GetWorld() != GetWorld()
			|| UniqueActors.Contains(GirlAftermath) || GirlAftermath == this)))
	{
		StopStory(TEXT("configure an unused one-shot corridor, a blocking road cue, and a non-blocking attack cue"));
		return;
	}

	CorridorAudio->bEnabled = false;
	Girl->SetRequestAvailable(false);
	ToyPickup->SetPickupAvailable(false);
	if (GirlAftermath)
	{
		GirlAftermath->SetActorHiddenInGame(true);
		GirlAftermath->SetActorEnableCollision(false);
	}

	ClassroomDoor->OnDoorOpened.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleClassroomOpened);
	CorridorAudio->OnTriggered.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleCorridorTriggered);
	RoadRock->OnBlockageReady.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleRoadBlockageReady);
	BypassTrigger->OnPlayerEntered.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleBypassEntered);
	Girl->OnToyRequested.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleToyRequested);
	ToyPickup->OnToyPickedUp.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleToyPickedUp);
	ReturnTrigger->OnPlayerEntered.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleReturnEntered);
	AttackCue->OnImpact.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleAttackImpact);
	DiscoveryTrigger->OnPlayerEntered.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleDiscoveryEntered);
	GetWorldTimerManager().SetTimerForNextTick(this, &AYIXIInteractionStoryCoordinator::CheckInitialDoorState);
	UE_LOG(LogYIXIInteractionStory, Display, TEXT("%s is waiting for the classroom door."), *GetName());
}

void AYIXIInteractionStoryCoordinator::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	bEndingPlay = true;
	GetWorldTimerManager().ClearAllTimersForObject(this);

	if (IsValid(ClassroomDoor)) { ClassroomDoor->OnDoorOpened.RemoveAll(this); }
	if (IsValid(CorridorAudio)) { CorridorAudio->OnTriggered.RemoveAll(this); }
	if (IsValid(RoadRock)) { RoadRock->OnBlockageReady.RemoveAll(this); }
	if (IsValid(BypassTrigger)) { BypassTrigger->OnPlayerEntered.RemoveAll(this); }
	if (IsValid(Girl)) { Girl->OnToyRequested.RemoveAll(this); }
	if (IsValid(ToyPickup)) { ToyPickup->OnToyPickedUp.RemoveAll(this); }
	if (IsValid(ReturnTrigger)) { ReturnTrigger->OnPlayerEntered.RemoveAll(this); }
	if (IsValid(AttackCue)) { AttackCue->OnImpact.RemoveAll(this); }
	if (IsValid(DiscoveryTrigger)) { DiscoveryTrigger->OnPlayerEntered.RemoveAll(this); }

	Super::EndPlay(EndPlayReason);
}

bool AYIXIInteractionStoryCoordinator::IsLocalPlayer(const APawn* Pawn) const
{
	const APlayerController* Controller = IsValid(Pawn) ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
	return !bEndingPlay && Controller && Controller->IsLocalController() && Controller->GetPawn() == Pawn
		&& Pawn->GetWorld() == GetWorld();
}

bool AYIXIInteractionStoryCoordinator::IsParticipant(const APawn* Pawn) const
{
	return IsLocalPlayer(Pawn) && StoryPawn.Get() == Pawn;
}

void AYIXIInteractionStoryCoordinator::SetStage(EYIXIInteractionStoryStage NewStage)
{
	Stage = NewStage;
	UE_LOG(LogYIXIInteractionStory, Display, TEXT("%s stage %s."), *GetName(), *UEnum::GetValueAsString(Stage));
	OnStageChanged.Broadcast(Stage);
}

void AYIXIInteractionStoryCoordinator::StopStory(const TCHAR* Reason)
{
	UE_LOG(LogYIXIInteractionStory, Warning, TEXT("%s stopped: %s."), *GetName(), Reason);
	SetStage(EYIXIInteractionStoryStage::Stopped);
}

void AYIXIInteractionStoryCoordinator::CheckInitialDoorState()
{
	if (IsValid(ClassroomDoor) && ClassroomDoor->DoorState == EYIXIDoorState::Open)
	{
		HandleClassroomOpened();
	}
}

void AYIXIInteractionStoryCoordinator::HandleClassroomOpened()
{
	if (Stage != EYIXIInteractionStoryStage::WaitingForDoor)
	{
		return;
	}
	if (!IsValid(CorridorAudio))
	{
		StopStory(TEXT("corridor audio actor is no longer available"));
		return;
	}

	CorridorAudio->bEnabled = true;
	SetStage(EYIXIInteractionStoryStage::Corridor);
	const APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	if (Controller && IsValid(CorridorAudio) && !bEndingPlay)
	{
		CorridorAudio->TryTriggerFirstOverlappingPlayer(Controller->GetPawn());
	}
}

void AYIXIInteractionStoryCoordinator::HandleCorridorTriggered(APawn* Pawn)
{
	if (Stage != EYIXIInteractionStoryStage::Corridor || !IsLocalPlayer(Pawn))
	{
		return;
	}
	StoryPawn = Pawn;
	SetStage(EYIXIInteractionStoryStage::RoadCuePending);
	if (bEndingPlay)
	{
		return;
	}

	// Allow the audio box to finish its broadcast and queue its configured clips first.
	if (RoadLaunchDelay > 0.0f)
	{
		GetWorldTimerManager().SetTimer(RoadCueTimer, this, &AYIXIInteractionStoryCoordinator::LaunchRoadCue, RoadLaunchDelay, false);
	}
	else
	{
		GetWorldTimerManager().SetTimerForNextTick(this, &AYIXIInteractionStoryCoordinator::LaunchRoadCue);
	}
}

void AYIXIInteractionStoryCoordinator::LaunchRoadCue()
{
	if (Stage != EYIXIInteractionStoryStage::RoadCuePending || !IsParticipant(StoryPawn.Get()))
	{
		return;
	}
	const int32 RequestId = ++NextRequestId;
	SetStage(EYIXIInteractionStoryStage::RoadCueInFlight);
	if (!bEndingPlay && (!IsValid(RoadRock) || !RoadRock->Launch(RequestId)))
	{
		StopStory(TEXT("road cue rejected its launch"));
	}
}

void AYIXIInteractionStoryCoordinator::HandleRoadBlockageReady(int32 RequestId)
{
	APawn* Pawn = StoryPawn.Get();
	if (Stage != EYIXIInteractionStoryStage::RoadCueInFlight || RequestId != NextRequestId
		|| !IsParticipant(Pawn) || !IsValid(RoadRock) || !RoadRock->IsBlockageReady())
	{
		return;
	}
	SetStage(EYIXIInteractionStoryStage::Bypass);
	if (IsValid(BypassTrigger) && BypassTrigger->ContainsPawn(Pawn))
	{
		HandleBypassEntered(Pawn);
	}
}

void AYIXIInteractionStoryCoordinator::HandleBypassEntered(APawn* Pawn)
{
	if (Stage == EYIXIInteractionStoryStage::Bypass && IsParticipant(Pawn))
	{
		if (!IsValid(Girl))
		{
			StopStory(TEXT("girl actor is no longer available"));
			return;
		}
		Girl->SetRequestAvailable(true);
		SetStage(EYIXIInteractionStoryStage::GirlRequest);
	}
}

void AYIXIInteractionStoryCoordinator::HandleToyRequested(APawn* Pawn)
{
	if (Stage != EYIXIInteractionStoryStage::GirlRequest || !IsParticipant(Pawn))
	{
		return;
	}
	if (!IsValid(Girl) || !IsValid(ToyPickup))
	{
		StopStory(TEXT("toy request actors are no longer available"));
		return;
	}
	const FText Line = Girl->GetRequestDialogue();
	ToyPickup->SetPickupAvailable(true);
	SetStage(EYIXIInteractionStoryStage::ToyPickup);
	ShowDialogue(Pawn, Line);
}

void AYIXIInteractionStoryCoordinator::ShowDialogue(APawn* Pawn, const FText& Line)
{
	if (!IsParticipant(Pawn) || Line.IsEmpty())
	{
		return;
	}
	if (bShowWhiteboxDialogue && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::White, Line.ToString());
	}
	OnDialogue.Broadcast(Pawn, Line);
}

void AYIXIInteractionStoryCoordinator::HandleToyPickedUp(APawn* Pawn)
{
	if (Stage != EYIXIInteractionStoryStage::ToyPickup || !IsParticipant(Pawn))
	{
		return;
	}
	const UYIXIToyCarryComponent* Carry = UYIXIToyCarryComponent::FindForPawn(Pawn);
	if (!IsValid(Carry) || Carry->GetCarryState() != EYIXIToyCarryState::HeldHand)
	{
		return;
	}
	SetStage(EYIXIInteractionStoryStage::Return);
	if (IsValid(ReturnTrigger) && ReturnTrigger->ContainsPawn(Pawn))
	{
		HandleReturnEntered(Pawn);
	}
}

void AYIXIInteractionStoryCoordinator::HandleReturnEntered(APawn* Pawn)
{
	if (Stage != EYIXIInteractionStoryStage::Return || !IsParticipant(Pawn))
	{
		return;
	}
	const int32 RequestId = ++NextRequestId;
	SetStage(EYIXIInteractionStoryStage::AttackCueInFlight);
	if (!bEndingPlay && (!IsValid(AttackCue) || !AttackCue->Launch(RequestId)))
	{
		StopStory(TEXT("attack cue rejected its launch"));
	}
}

void AYIXIInteractionStoryCoordinator::HandleAttackImpact(int32 RequestId)
{
	APawn* Pawn = StoryPawn.Get();
	if (Stage != EYIXIInteractionStoryStage::AttackCueInFlight || RequestId != NextRequestId
		|| !IsParticipant(Pawn) || !IsValid(AttackCue) || !AttackCue->HasImpacted())
	{
		return;
	}
	SetStage(EYIXIInteractionStoryStage::Discovery);
	if (IsValid(DiscoveryTrigger) && DiscoveryTrigger->ContainsPawn(Pawn))
	{
		HandleDiscoveryEntered(Pawn);
	}
}

void AYIXIInteractionStoryCoordinator::HandleDiscoveryEntered(APawn* Pawn)
{
	if (Stage != EYIXIInteractionStoryStage::Discovery || !IsParticipant(Pawn))
	{
		return;
	}
	if (IsValid(Girl))
	{
		Girl->SetUnavailable();
		Girl->SetActorHiddenInGame(true);
	}
	if (IsValid(GirlAftermath))
	{
		GirlAftermath->SetActorHiddenInGame(false);
	}

	UYIXIToyCarryComponent* Carry = UYIXIToyCarryComponent::FindForPawn(Pawn);
	if (!IsValid(Carry) || (Carry->GetCarryState() != EYIXIToyCarryState::Dropped && !Carry->TryDrop()))
	{
		UE_LOG(LogYIXIInteractionStory, Warning, TEXT("%s could not drop the toy here; reenter discovery from clear ground."), *GetName());
		return;
	}
	if (Stage == EYIXIInteractionStoryStage::Discovery && IsParticipant(Pawn) && IsValid(Carry)
		&& Carry->GetCarryState() == EYIXIToyCarryState::Dropped && IsValid(Carry->GetToyActor()))
	{
		StartMatchCut(Pawn, Carry->GetToyActor());
	}
}

void AYIXIInteractionStoryCoordinator::StartMatchCut(APawn* Pawn, AActor* DroppedToy)
{
	if (Stage != EYIXIInteractionStoryStage::Discovery || PendingMatchCut != 0)
	{
		return;
	}
	const int32 RequestId = ++NextRequestId;
	PendingMatchCut = RequestId;
	SetStage(EYIXIInteractionStoryStage::MatchCut);
	if (bEndingPlay || PendingMatchCut != RequestId)
	{
		return;
	}
	UE_LOG(LogYIXIInteractionStory, Display, TEXT("%s Match Cut request %d with %s."), *GetName(), RequestId, *GetNameSafe(DroppedToy));
	GetWorldTimerManager().SetTimer(MatchCutTimeoutTimer, FTimerDelegate::CreateWeakLambda(this, [this, RequestId]
	{
		UE_LOG(LogYIXIInteractionStory, Warning, TEXT("%s Match Cut request %d timed out."), *GetName(), RequestId);
		CompleteMatchCut(RequestId, false);
	}), FMath::Max(0.1f, MatchCutTimeout), false);
	if (bUseIsolatedMatchCutStandIn)
	{
		GetWorldTimerManager().SetTimer(StandInTimer, FTimerDelegate::CreateWeakLambda(this, [this, RequestId]
		{
			CompleteMatchCut(RequestId, true);
		}), FMath::Max(0.01f, StandInDelay), false);
	}
	OnMatchCutRequested.Broadcast(RequestId, Pawn, DroppedToy);
}

bool AYIXIInteractionStoryCoordinator::CompleteMatchCut(int32 RequestId, bool bSucceeded)
{
	if (bEndingPlay || Stage != EYIXIInteractionStoryStage::MatchCut || RequestId <= 0 || RequestId != PendingMatchCut)
	{
		return false;
	}
	PendingMatchCut = 0;
	GetWorldTimerManager().ClearTimer(MatchCutTimeoutTimer);
	GetWorldTimerManager().ClearTimer(StandInTimer);

	APawn* Pawn = StoryPawn.Get();
	UYIXIToyCarryComponent* Carry = bSucceeded && IsParticipant(Pawn) ? UYIXIToyCarryComponent::FindForPawn(Pawn) : nullptr;
	const bool bAttached = IsValid(Carry) && Carry->GetCarryState() == EYIXIToyCarryState::Dropped
		&& Carry->TryAttachToWaist() && IsParticipant(Pawn) && IsValid(Carry)
		&& Carry->GetCarryState() == EYIXIToyCarryState::AttachedAtWaist && IsValid(Carry->GetToyActor());
	if (!bEndingPlay)
	{
		UE_LOG(LogYIXIInteractionStory, Display, TEXT("%s Match Cut request %d: %s."), *GetName(), RequestId,
			bAttached ? TEXT("toy attached at waist") : TEXT("not completed; reenter discovery to retry"));
		SetStage(bAttached ? EYIXIInteractionStoryStage::Completed : EYIXIInteractionStoryStage::Discovery);
	}
	return bAttached;
}
