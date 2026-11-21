#include "YIXI_Interaction/ScriptedProjectile/YIXIStoryTriggerBox.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"

AYIXIStoryTriggerBox::AYIXIStoryTriggerBox()
{
	PrimaryActorTick.bCanEverTick = false;
	bGenerateOverlapEventsDuringLevelStreaming = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	SetRootComponent(TriggerBox);
	TriggerBox->InitBoxExtent(FVector(120.0, 120.0, 110.0));
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionObjectType(ECC_WorldDynamic);
	TriggerBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	TriggerBox->SetGenerateOverlapEvents(true);
	TriggerBox->SetCanEverAffectNavigation(false);
	TriggerBox->SetHiddenInGame(true);
}

bool AYIXIStoryTriggerBox::ContainsPawn(const APawn* Pawn) const
{
	if (bEndingPlay || IsActorBeingDestroyed() || !IsValid(Pawn) || Pawn->IsActorBeingDestroyed())
	{
		return false;
	}
	const APlayerController* Controller = Cast<APlayerController>(Pawn->GetController());
	return IsValid(Controller) && Controller->GetPawn() == Pawn && TriggerBox->IsOverlappingActor(Pawn);
}

void AYIXIStoryTriggerBox::BeginPlay()
{
	bEndingPlay = false;
	Super::BeginPlay();
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AYIXIStoryTriggerBox::HandleBeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AYIXIStoryTriggerBox::HandleEndOverlap);
	ScheduleOverlapRefresh();
}

void AYIXIStoryTriggerBox::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	bEndingPlay = true;
	TriggerBox->OnComponentBeginOverlap.RemoveDynamic(this, &AYIXIStoryTriggerBox::HandleBeginOverlap);
	TriggerBox->OnComponentEndOverlap.RemoveDynamic(this, &AYIXIStoryTriggerBox::HandleEndOverlap);
	GetWorldTimerManager().ClearAllTimersForObject(this);
	bOverlapRefreshScheduled = false;

	for (const TPair<TWeakObjectPtr<APawn>, bool>& Entry : TrackedPawns)
	{
		if (APawn* Pawn = Entry.Key.Get())
		{
			UnbindPawn(*Pawn);
		}
	}
	TrackedPawns.Reset();
	Super::EndPlay(EndPlayReason);
}

void AYIXIStoryTriggerBox::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Sweep)
{
	TrackPawn(Cast<APawn>(OtherActor));
}

void AYIXIStoryTriggerBox::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (bEndingPlay || !IsValid(Pawn) || TriggerBox->IsOverlappingActor(Pawn))
	{
		return;
	}

	bool bWasPlayerInside = false;
	if (TrackedPawns.RemoveAndCopyValue(TWeakObjectPtr<APawn>(Pawn), bWasPlayerInside))
	{
		UnbindPawn(*Pawn);
		if (bWasPlayerInside && !Pawn->IsActorBeingDestroyed())
		{
			OnPlayerExited.Broadcast(Pawn);
		}
	}
}

void AYIXIStoryTriggerBox::HandleControllerChanged(APawn* Pawn, AController* OldController, AController* NewController)
{
	if (bEndingPlay || !IsValid(Pawn))
	{
		return;
	}

	// PossessedBy can notify before the player controller has assigned its new pawn.
	const APlayerController* PlayerController = Cast<APlayerController>(NewController);
	if (PlayerController && PlayerController->GetPawn() != Pawn)
	{
		ScheduleOverlapRefresh();
		return;
	}
	UpdatePresence(Pawn);
}

void AYIXIStoryTriggerBox::HandlePawnDestroyed(AActor* Actor)
{
	if (APawn* Pawn = Cast<APawn>(Actor))
	{
		TrackedPawns.Remove(TWeakObjectPtr<APawn>(Pawn));
		UnbindPawn(*Pawn);
	}
}

void AYIXIStoryTriggerBox::TrackPawn(APawn* Pawn)
{
	if (bEndingPlay || IsActorBeingDestroyed() || !IsValid(Pawn) || Pawn->IsActorBeingDestroyed())
	{
		return;
	}

	const TWeakObjectPtr<APawn> Key(Pawn);
	if (!TrackedPawns.Contains(Key))
	{
		TrackedPawns.Add(Key, false);
		Pawn->ReceiveControllerChangedDelegate.AddDynamic(this, &AYIXIStoryTriggerBox::HandleControllerChanged);
		Pawn->OnDestroyed.AddDynamic(this, &AYIXIStoryTriggerBox::HandlePawnDestroyed);
	}
	UpdatePresence(Pawn);
}

void AYIXIStoryTriggerBox::UpdatePresence(APawn* Pawn)
{
	bool* bWasInside = TrackedPawns.Find(TWeakObjectPtr<APawn>(Pawn));
	const bool bIsInside = ContainsPawn(Pawn);
	if (!bWasInside || *bWasInside == bIsInside)
	{
		return;
	}
	*bWasInside = bIsInside;
	if (bIsInside)
	{
		OnPlayerEntered.Broadcast(Pawn);
	}
	else
	{
		OnPlayerExited.Broadcast(Pawn);
	}
}

void AYIXIStoryTriggerBox::UnbindPawn(APawn& Pawn)
{
	Pawn.ReceiveControllerChangedDelegate.RemoveDynamic(this, &AYIXIStoryTriggerBox::HandleControllerChanged);
	Pawn.OnDestroyed.RemoveDynamic(this, &AYIXIStoryTriggerBox::HandlePawnDestroyed);
}

void AYIXIStoryTriggerBox::ScheduleOverlapRefresh()
{
	if (!bOverlapRefreshScheduled)
	{
		bOverlapRefreshScheduled = true;
		GetWorldTimerManager().SetTimerForNextTick(this, &AYIXIStoryTriggerBox::RefreshOverlaps);
	}
}

void AYIXIStoryTriggerBox::RefreshOverlaps()
{
	bOverlapRefreshScheduled = false;
	TArray<AActor*> Actors;
	TriggerBox->GetOverlappingActors(Actors, APawn::StaticClass());
	for (AActor* Actor : Actors)
	{
		TrackPawn(Cast<APawn>(Actor));
	}
}
