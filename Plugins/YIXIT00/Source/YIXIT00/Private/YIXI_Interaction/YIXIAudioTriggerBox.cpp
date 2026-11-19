#include "YIXI_Interaction/YIXIAudioTriggerBox.h"

#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIAudioTrigger, Log, All);

AYIXIAudioTriggerBox::AYIXIAudioTriggerBox()
{
	PrimaryActorTick.bCanEverTick = false;
	bGenerateOverlapEventsDuringLevelStreaming = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	SetRootComponent(BoxCollision);
	BoxCollision->InitBoxExtent(FVector(150.0, 110.0, 110.0));
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCollision->SetCollisionObjectType(ECC_WorldDynamic);
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BoxCollision->SetGenerateOverlapEvents(true);
	BoxCollision->SetCanEverAffectNavigation(false);
	BoxCollision->SetHiddenInGame(true);

	AudioLocation = CreateDefaultSubobject<USceneComponent>(TEXT("AudioLocation"));
	AudioLocation->SetupAttachment(BoxCollision);
}

void AYIXIAudioTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AYIXIAudioTriggerBox::HandlePlayerEntered);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AYIXIAudioTriggerBox::HandlePlayerLeft);
	ScheduleOverlapCheck();
}

void AYIXIAudioTriggerBox::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	BoxCollision->OnComponentBeginOverlap.RemoveDynamic(this, &AYIXIAudioTriggerBox::HandlePlayerEntered);
	BoxCollision->OnComponentEndOverlap.RemoveDynamic(this, &AYIXIAudioTriggerBox::HandlePlayerLeft);
	GetWorldTimerManager().ClearAllTimersForObject(this);
	PlayersInside.Reset();
	bOverlapCheckScheduled = false;
	Super::EndPlay(EndPlayReason);
}

void AYIXIAudioTriggerBox::HandlePlayerEntered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (!IsValid(Pawn))
	{
		return;
	}

	if (Pawn->GetController())
	{
		TryTriggerForPawn(Pawn);
	}
	else
	{
		// Initial spawn can overlap the box before GameMode possesses the pawn.
		ScheduleOverlapCheck();
	}
}

void AYIXIAudioTriggerBox::HandlePlayerLeft(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	if (APawn* Pawn = Cast<APawn>(OtherActor); Pawn && !BoxCollision->IsOverlappingActor(Pawn))
	{
		PlayersInside.Remove(TWeakObjectPtr<APawn>(Pawn));
	}
}

void AYIXIAudioTriggerBox::ScheduleOverlapCheck()
{
	if (!bOverlapCheckScheduled)
	{
		bOverlapCheckScheduled = true;
		GetWorldTimerManager().SetTimerForNextTick(this, &AYIXIAudioTriggerBox::CheckOverlappingPlayers);
	}
}

void AYIXIAudioTriggerBox::CheckOverlappingPlayers()
{
	bOverlapCheckScheduled = false;
	TArray<AActor*> OverlappingActors;
	BoxCollision->GetOverlappingActors(OverlappingActors, APawn::StaticClass());
	for (AActor* Actor : OverlappingActors)
	{
		TryTriggerForPawn(Cast<APawn>(Actor));
	}
}

void AYIXIAudioTriggerBox::TryTriggerForPawn(APawn* Pawn)
{
	const APlayerController* Controller = IsValid(Pawn) ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
	if (!Controller || Controller->GetPawn() != Pawn || IsActorBeingDestroyed())
	{
		return;
	}

	for (auto It = PlayersInside.CreateIterator(); It; ++It)
	{
		if (!It->IsValid())
		{
			It.RemoveCurrent();
		}
	}
	const TWeakObjectPtr<APawn> Player(Pawn);
	if (PlayersInside.Contains(Player))
	{
		return;
	}
	PlayersInside.Add(Player);

	if (!bEnabled || (bTriggerOnce && TriggerCount > 0))
	{
		return;
	}

	++TriggerCount;
	UE_LOG(LogYIXIAudioTrigger, Display, TEXT("%s triggered by %s (count %d)."),
		*GetName(), *GetNameSafe(Pawn), TriggerCount);
	OnTriggered.Broadcast(Pawn);
	if (IsActorBeingDestroyed() || !bEnabled)
	{
		return;
	}

	QueueSound(CrowdPanicSound, CrowdPanicDelay, CrowdPanicVolume);
	QueueSound(HorseSound, HorseDelay, HorseVolume);
	QueueSound(DistantBellSound, DistantBellDelay, DistantBellVolume);
	for (const FYIXIAudioTriggerSound& Entry : AdditionalSounds)
	{
		QueueSound(Entry.Sound, Entry.Delay, Entry.Volume);
	}
}

void AYIXIAudioTriggerBox::QueueSound(USoundBase* Sound, float Delay, float Volume)
{
	if (!IsValid(Sound) || Volume <= 0.0f)
	{
		return;
	}

	const TWeakObjectPtr<USoundBase> SoundRef(Sound);
	if (Delay <= 0.0f)
	{
		PlaySound(SoundRef, Volume);
		return;
	}

	FTimerHandle Timer;
	const FTimerDelegate Callback = FTimerDelegate::CreateUObject(this, &AYIXIAudioTriggerBox::PlaySound, SoundRef, Volume);
	GetWorldTimerManager().SetTimer(Timer, Callback, Delay, false);
}

void AYIXIAudioTriggerBox::PlaySound(TWeakObjectPtr<USoundBase> Sound, float Volume)
{
	USoundBase* Asset = Sound.Get();
	if (!Asset || !bEnabled || IsActorBeingDestroyed())
	{
		return;
	}

	if (bUseSpatialAudio)
	{
		UGameplayStatics::PlaySoundAtLocation(this, Asset, AudioLocation->GetComponentLocation(),
			AudioLocation->GetComponentRotation(), Volume, 1.0f, 0.0f, AttenuationSettings);
	}
	else
	{
		UGameplayStatics::PlaySound2D(this, Asset, Volume, 1.0f, 0.0f, nullptr, this, false);
	}
}
