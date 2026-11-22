#include "YIXI_Interaction/Story/YIXIInteractionStoryCoordinator.h"

#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "YIXI_Interaction/DialogueToy/YIXIStoryGirl.h"
#include "YIXI_Interaction/DialogueToy/YIXIStoryToyPickup.h"
#include "YIXI_Interaction/DialogueToy/YIXIToyCarryComponent.h"
#include "YIXI_Interaction/ScriptedProjectile/YIXIScriptedRock.h"
#include "YIXI_Interaction/ScriptedProjectile/YIXIStoryTriggerBox.h"
#include "YIXI_Interaction/Story/YIXIV3Cinematic.h"
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

	bUsesV3Presentation = V3Cinematic != nullptr;
	if (bUsesV3Presentation && (!IsValid(V3Cinematic) || V3Cinematic->GetWorld() != GetWorld()))
	{
		StopStory(TEXT("the cinematic must belong to this story world"));
		return;
	}

	if (bExternalV3Only)
	{
		if (!V3Cinematic || V3Cinematic->GetLevel() != GetLevel())
			StopStory(TEXT("the external V3 must belong to this Day level"));
		else
			SetStage(EYIXIInteractionStoryStage::Discovery);
		return;
	}

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
	if (UBoxComponent* Box = GetFixedStageTrigger())
	{
		Box->OnComponentBeginOverlap.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleFixedStageEntered);
		Box->OnComponentEndOverlap.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleFixedStageExited);
	}
	else
	{
		DiscoveryTrigger->OnPlayerEntered.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleDiscoveryEntered);
		if (bUsesV3Presentation)
		{
			DiscoveryTrigger->OnPlayerExited.AddDynamic(this, &AYIXIInteractionStoryCoordinator::HandleDiscoveryExited);
		}
	}
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
	if (IsValid(DiscoveryTrigger))
	{
		DiscoveryTrigger->OnPlayerEntered.RemoveAll(this);
		DiscoveryTrigger->OnPlayerExited.RemoveAll(this);
	}
	if (UBoxComponent* Box = GetFixedStageTrigger())
	{
		Box->OnComponentBeginOverlap.RemoveAll(this);
		Box->OnComponentEndOverlap.RemoveAll(this);
	}

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
	if (NewStage != EYIXIInteractionStoryStage::Discovery)
	{
		GetWorldTimerManager().ClearTimer(FixedStageRetryTimer);
	}
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
	if (IsValid(V3Cinematic))
	{
		V3Cinematic->PrepareNight(this, Pawn);
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
	if (bUsesV3Presentation)
	{
		if (!IsValid(V3Cinematic))
		{
			StopStory(TEXT("the assigned cinematic is no longer available"));
			return;
		}
		if (IsValid(Girl))
		{
			Girl->SetUnavailable();
			Girl->SetActorHiddenInGame(true);
			Girl->SetActorEnableCollision(false);
		}
		V3Cinematic->HandleAttackImpact(AttackCue);
	}
	SetStage(EYIXIInteractionStoryStage::Discovery);
	const UBoxComponent* FixedTrigger = GetFixedStageTrigger();
	if (FixedTrigger ? FixedTrigger->IsOverlappingActor(Pawn) :
		(IsValid(DiscoveryTrigger) && DiscoveryTrigger->ContainsPawn(Pawn)))
	{
		HandleDiscoveryEntered(Pawn);
	}
}

void AYIXIInteractionStoryCoordinator::HandleDiscoveryEntered(APawn* Pawn)
{
	if (Stage != EYIXIInteractionStoryStage::Discovery || bRequiresDiscoveryExit || !IsParticipant(Pawn))
	{
		return;
	}
	if (bUsesV3Presentation)
	{
		if (GetFixedStageTrigger())
		{
			if (!GetWorldTimerManager().IsTimerActive(FixedStageRetryTimer))
			{
				UE_LOG(LogYIXIInteractionStory, Display, TEXT("Fixed stage pending for %s."), *GetNameSafe(Pawn));
				GetWorldTimerManager().SetTimer(FixedStageRetryTimer, this, &AYIXIInteractionStoryCoordinator::TryPendingFixedStage, .15f, true);
			}
			return;
		}
		BeginV3Presentation(Pawn);
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

void AYIXIInteractionStoryCoordinator::TryPendingFixedStage()
{
	APawn* Pawn = StoryPawn.Get();
	const UBoxComponent* Box = GetFixedStageTrigger();
	if (bEndingPlay || Stage != EYIXIInteractionStoryStage::Discovery || bRequiresDiscoveryExit ||
		!IsParticipant(Pawn) || !Box || !Box->IsOverlappingActor(Pawn))
	{
		GetWorldTimerManager().ClearTimer(FixedStageRetryTimer);
		return;
	}
	if (V3Cinematic->CanEnterFixedStage(Pawn))
	{
		BeginV3Presentation(Pawn);
	}
}

void AYIXIInteractionStoryCoordinator::BeginV3Presentation(APawn* Pawn)
{
	const UYIXIToyCarryComponent* Carry = UYIXIToyCarryComponent::FindForPawn(Pawn);
	if (!IsValid(V3Cinematic) || !IsValid(Carry) || !IsValid(Carry->GetToyActor())
		|| Carry->GetCarryState() != EYIXIToyCarryState::HeldHand)
	{
		GetWorldTimerManager().ClearTimer(FixedStageRetryTimer);
		UE_LOG(LogYIXIInteractionStory, Warning, TEXT("Discovery requires the cinematic and the player's hand-held toy."));
		return;
	}
	PresentationToy = Carry->GetToyActor();
	SetStage(EYIXIInteractionStoryStage::V3Presentation);
	if (Stage == EYIXIInteractionStoryStage::V3Presentation && !bEndingPlay
		&& (!IsValid(V3Cinematic) || !V3Cinematic->BeginDiscovery(this, Pawn)))
	{
		AbortV3Presentation(Pawn);
	}
}

void AYIXIInteractionStoryCoordinator::HandleDiscoveryExited(APawn* Pawn)
{
	if (!bRequiresDiscoveryExit || Stage != EYIXIInteractionStoryStage::Discovery || !IsParticipant(Pawn))
	{
		return;
	}
	// Mover may refresh overlap pairs while restoring the same pose. Re-arm only outside the authored box.
	const UBoxComponent* Box = GetFixedStageTrigger();
	if (!Box && IsValid(DiscoveryTrigger)) Box = DiscoveryTrigger->TriggerBox;
	if (!IsValid(Box)) return;
	const FVector LocalPosition = Box->GetComponentTransform().InverseTransformPosition(Pawn->GetActorLocation());
	if (!FBox::BuildAABB(FVector::ZeroVector, Box->GetUnscaledBoxExtent()).IsInsideOrOn(LocalPosition)
		&& !Box->IsOverlappingActor(Pawn))
	{
		bRequiresDiscoveryExit = false;
	}
}

UBoxComponent* AYIXIInteractionStoryCoordinator::GetFixedStageTrigger() const
{
	return IsValid(V3Cinematic) && V3Cinematic->bUseFixedStage ? V3Cinematic->StageTrigger.Get() : nullptr;
}

void AYIXIInteractionStoryCoordinator::HandleFixedStageEntered(UPrimitiveComponent* Component, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Sweep)
{
	HandleDiscoveryEntered(Cast<APawn>(OtherActor));
}

void AYIXIInteractionStoryCoordinator::HandleFixedStageExited(UPrimitiveComponent* Component, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	HandleDiscoveryExited(Cast<APawn>(OtherActor));
}

bool AYIXIInteractionStoryCoordinator::BeginExternalV3Presentation(AYIXIV3Cinematic* Source, APawn* Pawn, AActor* HeldToy)
{
	if (!bExternalV3Only || bEndingPlay || Stage != EYIXIInteractionStoryStage::Discovery ||
		!IsValid(Source) || Source != V3Cinematic || Source->GetLevel() != GetLevel() ||
		!IsValid(Pawn) || Pawn->GetWorld() != GetWorld() || !IsValid(HeldToy))
		return false;
	const APlayerController* Controller = Cast<APlayerController>(Pawn->GetController());
	const UYIXIToyCarryComponent* Carry = UYIXIToyCarryComponent::FindForPawn(Pawn);
	if (!Controller || !Controller->IsLocalController() || Controller->GetPawn() != Pawn ||
		!Carry || Carry->GetCarryState() != EYIXIToyCarryState::HeldHand || Carry->GetToyActor() != HeldToy ||
		HeldToy->GetAttachParentActor() != Pawn)
		return false;
	StoryPawn = Pawn;
	PresentationToy = HeldToy;
	SetStage(EYIXIInteractionStoryStage::V3Presentation);
	return true;
}

int32 AYIXIInteractionStoryCoordinator::RequestV3Cut(APawn* Pawn, AActor* DroppedToy)
{
	if (Stage != EYIXIInteractionStoryStage::V3Presentation || !IsParticipant(Pawn)
		|| !IsValid(DroppedToy) || PresentationToy.Get() != DroppedToy)
	{
		return 0;
	}
	const UYIXIToyCarryComponent* Carry = UYIXIToyCarryComponent::FindForPawn(Pawn);
	if (!IsValid(Carry) || Carry->GetCarryState() != EYIXIToyCarryState::Dropped || Carry->GetToyActor() != DroppedToy)
	{
		return 0;
	}
	return StartMatchCut(Pawn, DroppedToy);
}

void AYIXIInteractionStoryCoordinator::FinishV3Presentation(APawn* Pawn)
{
	if (bEndingPlay || Pawn != StoryPawn.Get() || Stage != EYIXIInteractionStoryStage::V3NightPresentation)
	{
		return;
	}
	const UYIXIToyCarryComponent* Carry = IsParticipant(Pawn) ? UYIXIToyCarryComponent::FindForPawn(Pawn) : nullptr;
	if (!IsValid(Carry) || !PresentationToy.IsValid() || Carry->GetToyActor() != PresentationToy.Get()
		|| Carry->GetCarryState() != EYIXIToyCarryState::AttachedAtWaist)
	{
		StopStory(TEXT("the night presentation lost its waist-mounted toy"));
		return;
	}
	PresentationToy.Reset();
	SetStage(EYIXIInteractionStoryStage::Completed);
}

void AYIXIInteractionStoryCoordinator::AbortV3Presentation(APawn* Pawn)
{
	if (bEndingPlay || !bUsesV3Presentation || Pawn != StoryPawn.Get()
		|| (Stage != EYIXIInteractionStoryStage::V3Presentation && Stage != EYIXIInteractionStoryStage::MatchCut))
	{
		return;
	}
	GetWorldTimerManager().ClearTimer(MatchCutTimeoutTimer);
	PendingMatchCut = 0;
	PendingToy.Reset();
	const UYIXIToyCarryComponent* Carry = IsParticipant(Pawn) ? UYIXIToyCarryComponent::FindForPawn(Pawn) : nullptr;
	const bool bCanRetry = IsValid(Carry) && PresentationToy.IsValid()
		&& Carry->GetToyActor() == PresentationToy.Get() && Carry->GetCarryState() == EYIXIToyCarryState::HeldHand;
	PresentationToy.Reset();
	if (bCanRetry)
	{
		bRequiresDiscoveryExit = true;
		SetStage(EYIXIInteractionStoryStage::Discovery);
		if (GetFixedStageTrigger()) HandleDiscoveryExited(Pawn);
	}
	else
	{
		StopStory(TEXT("the cinematic ended without the original pawn and hand-held toy; player control must be returned"));
	}
}

int32 AYIXIInteractionStoryCoordinator::StartMatchCut(APawn* Pawn, AActor* DroppedToy)
{
	const EYIXIInteractionStoryStage ExpectedStage = bUsesV3Presentation ?
		EYIXIInteractionStoryStage::V3Presentation : EYIXIInteractionStoryStage::Discovery;
	if (Stage != ExpectedStage || PendingMatchCut != 0)
	{
		return 0;
	}
	const int32 RequestId = ++NextRequestId;
	SetStage(EYIXIInteractionStoryStage::MatchCut);
	if (bEndingPlay || Stage != EYIXIInteractionStoryStage::MatchCut || NextRequestId != RequestId
		|| !IsParticipant(Pawn) || !IsValid(DroppedToy))
	{
		if (!bEndingPlay && !bUsesV3Presentation && Stage == EYIXIInteractionStoryStage::MatchCut && NextRequestId == RequestId)
		{
			SetStage(EYIXIInteractionStoryStage::Discovery);
		}
		return 0;
	}
	PendingMatchCut = RequestId;
	PendingToy = DroppedToy;
	UE_LOG(LogYIXIInteractionStory, Display, TEXT("%s Match Cut request %d with %s."), *GetName(), RequestId, *GetNameSafe(DroppedToy));
	GetWorldTimerManager().SetTimer(MatchCutTimeoutTimer, FTimerDelegate::CreateWeakLambda(this, [this, RequestId]
	{
		UE_LOG(LogYIXIInteractionStory, Warning, TEXT("%s Match Cut request %d timed out."), *GetName(), RequestId);
		CompleteMatchCut(RequestId, false);
	}), FMath::Max(0.1f, MatchCutTimeout), false);
	if (bUseIsolatedMatchCutStandIn && !bUsesV3Presentation)
	{
		GetWorldTimerManager().SetTimer(StandInTimer, FTimerDelegate::CreateWeakLambda(this, [this, RequestId]
		{
			CompleteMatchCut(RequestId, true);
		}), FMath::Max(0.01f, StandInDelay), false);
	}
	OnMatchCutRequested.Broadcast(RequestId, Pawn, DroppedToy);
	return RequestId;
}

bool AYIXIInteractionStoryCoordinator::CompleteMatchCut(int32 RequestId, bool bSucceeded)
{
	if (bEndingPlay || Stage != EYIXIInteractionStoryStage::MatchCut || RequestId <= 0 || RequestId != PendingMatchCut)
	{
		return false;
	}
	PendingMatchCut = 0;
	const TWeakObjectPtr<AActor> ExpectedToy = PendingToy;
	PendingToy.Reset();
	GetWorldTimerManager().ClearTimer(MatchCutTimeoutTimer);
	GetWorldTimerManager().ClearTimer(StandInTimer);

	APawn* Pawn = StoryPawn.Get();
	UYIXIToyCarryComponent* Carry = bSucceeded && IsParticipant(Pawn) ? UYIXIToyCarryComponent::FindForPawn(Pawn) : nullptr;
	const bool bAttached = IsValid(Carry) && Carry->GetCarryState() == EYIXIToyCarryState::Dropped
		&& ExpectedToy.IsValid() && Carry->GetToyActor() == ExpectedToy.Get()
		&& Carry->TryAttachToWaist() && IsParticipant(Pawn) && IsValid(Carry)
		&& Carry->GetCarryState() == EYIXIToyCarryState::AttachedAtWaist && ExpectedToy.IsValid()
		&& Carry->GetToyActor() == ExpectedToy.Get();
	// Attaching broadcasts the carry transition and may synchronously abort this presentation.
	if (bEndingPlay || Stage != EYIXIInteractionStoryStage::MatchCut || NextRequestId != RequestId)
	{
		return false;
	}
	UE_LOG(LogYIXIInteractionStory, Display, TEXT("%s Match Cut request %d: %s."), *GetName(), RequestId,
		bAttached ? TEXT("toy attached at waist") : TEXT("not completed; reenter discovery to retry"));
	if (bAttached)
	{
		SetStage(bUsesV3Presentation ? EYIXIInteractionStoryStage::V3NightPresentation : EYIXIInteractionStoryStage::Completed);
	}
	else if (!bUsesV3Presentation)
	{
		SetStage(EYIXIInteractionStoryStage::Discovery);
	}
	// A failed cinematic commit restores the pawn and prop before AbortV3Presentation reopens the trigger.
	return bAttached;
}
