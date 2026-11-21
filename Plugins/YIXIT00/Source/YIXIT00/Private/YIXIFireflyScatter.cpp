#include "YIXIFireflyScatter.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/PointLightComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "UObject/ConstructorHelpers.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIFirefly, Log, All);

AYIXIFireflyScatter::AYIXIFireflyScatter()
{
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Root")));

	SenseArea = CreateDefaultSubobject<USphereComponent>(TEXT("SenseArea"));
	SenseArea->SetupAttachment(GetRootComponent());
	SenseArea->InitSphereRadius(SenseRadius);
	SenseArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SenseArea->SetGenerateOverlapEvents(false);
	SenseArea->SetHiddenInGame(true);

	FireEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("FireEffect"));
	FireEffect->SetupAttachment(GetRootComponent());
	FireEffect->SetAutoActivate(true);
	FireEffect->bAutoActivate = true;

	FireflyLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("FireflyLight"));
	FireflyLight->SetupAttachment(FireEffect);
	FireflyLight->SetMobility(EComponentMobility::Movable);

	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> DefaultFireflies(TEXT("/Game/VFX/NS_Firefly.NS_Firefly"));
	if (DefaultFireflies.Succeeded())
	{
		FireSystem = DefaultFireflies.Object;
		FireEffect->SetAsset(DefaultFireflies.Object);
	}
	else
	{
		UE_LOG(LogYIXIFirefly, Warning, TEXT("Default NS_Firefly not found; assign FireSystem in Details."));
	}
}

void AYIXIFireflyScatter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (SenseArea)
	{
		SenseArea->SetSphereRadius(FMath::Max(0.0f, SenseRadius), false);
	}
	ApplyTemplateAndScale();
	if (FireEffect && !HasActorBegunPlay())
	{
		FireEffect->bAutoActivate = true;
	}
}

void AYIXIFireflyScatter::BeginPlay()
{
	Super::BeginPlay();

	ApplyTemplateAndScale();
	HomeRelativeLocation = FireEffect ? FireEffect->GetRelativeLocation() : FVector::ZeroVector;

	if (FireEffect)
	{
		FireEffect->SetVisibility(true);
		FireEffect->Activate(true);
	}
	if (bFireflyLightFollowsScatter && IsValid(FireflyLight))
	{
		FireflyLight->SetVisibility(true);
	}
	bScattered = false;
	bScattering = false;
	bKillPending = false;
	KillAt = -1e9f;
	ScatteredAt = -1e9f;
	TimeSinceCheck = CheckInterval; // 第一帧立刻检测一次。
}

void AYIXIFireflyScatter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!IsValid(FireEffect))
	{
		return;
	}

	// 惊起推进：边生边推，拖出四散尾迹；推完停发，余烬自然熄灭。
	if (bScattering)
	{
		ScatterAge += DeltaSeconds;
		const float T = FMath::Clamp(ScatterAge / FMath::Max(0.05f, ScatterDuration), 0.0f, 1.0f);
		const float SpeedFade = 1.0f - 0.5f * T;
		ScatterPhase += DeltaSeconds * 9.0f;
		const FVector Jitter(
			FMath::Sin(ScatterPhase * 1.3f) * ScatterJitter,
			FMath::Sin(ScatterPhase * 1.7f + 1.3f) * ScatterJitter,
			FMath::Sin(ScatterPhase * 2.1f + 2.6f) * ScatterJitter * 0.6f);
		FireEffect->AddWorldOffset((ScatterDir * ScatterSpeed * SpeedFade + Jitter) * DeltaSeconds);

		if (ScatterAge >= ScatterDuration)
		{
			bScattering = false;
			bScattered = true;
			ScatteredAt = GetWorld()->GetTimeSeconds();
			FireEffect->Deactivate(); // 先停新粒子；默认余烬按寿命自然熄灭。
			if (bFireflyLightFollowsScatter && IsValid(FireflyLight))
			{
				FireflyLight->SetVisibility(false);
			}
			// 手动开了快速清场才到期清场。
			if (bInstantClearRemainder)
			{
				KillAt = ScatteredAt + FMath::Max(0.0f, KillRemainderDelay);
				bKillPending = true;
			}
		}
		return;
	}

	// 余烬清理（手动开启时）：到期瞬间清场，散得干脆。
	if (bInstantClearRemainder && bKillPending && GetWorld() && GetWorld()->GetTimeSeconds() >= KillAt)
	{
		bKillPending = false;
		FireEffect->DeactivateImmediate();
	}

	TimeSinceCheck += DeltaSeconds;
	if (TimeSinceCheck < CheckInterval)
	{
		return;
	}
	TimeSinceCheck = 0.0f;

	APawn* Pawn = GetLocalPawn();
	if (!IsValid(Pawn))
	{
		return;
	}

	const float Dist = FVector::Dist(Pawn->GetActorLocation(), GetActorLocation());
	if (!bScattered)
	{
		if (Dist <= SenseRadius)
		{
			TriggerScatter();
		}
		return;
	}

	// 已散：玩家走远 + 过了恢复延迟 → 回来。
	if (bRegenerate && Dist > SenseRadius + 100.0f
		&& GetWorld()->GetTimeSeconds() - ScatteredAt >= RegenDelaySeconds)
	{
		Recover();
	}
}

void AYIXIFireflyScatter::TriggerScatter()
{
	if (bScattered || bScattering || !IsValid(FireEffect))
	{
		return;
	}
	// 逃跑方向：远离玩家 + 上飘，当场算好，之后匀速推。
	FVector Away = FireEffect->GetComponentLocation();
	if (APawn* Pawn = GetLocalPawn())
	{
		Away -= Pawn->GetActorLocation();
	}
	Away.Z += Away.Size() * ScatterUpBias + 1.0f; // 保证非零且带上飘。
	Away.Normalize();
	ScatterDir = Away;

	ScatterAge = 0.0f;
	ScatterPhase = 0.0f;
	bScattering = true;
	FireEffect->SetVisibility(true);
	if (bFireflyLightFollowsScatter && IsValid(FireflyLight))
	{
		FireflyLight->SetVisibility(true);
	}
	if (!FireEffect->IsActive())
	{
		FireEffect->Activate(true);
	}
}

void AYIXIFireflyScatter::Recover()
{
	if (!IsValid(FireEffect))
	{
		return;
	}
	if (bSnapHomeOnRegen)
	{
		FireEffect->SetRelativeLocation(HomeRelativeLocation);
		FireEffect->SetRelativeScale3D(FVector(FMath::Max(0.01f, FireEffectScale)));
	}
	FireEffect->SetVisibility(true);
	FireEffect->Activate(true);
	if (bFireflyLightFollowsScatter && IsValid(FireflyLight))
	{
		FireflyLight->SetVisibility(true);
	}
	bScattered = false;
	bScattering = false;
	bKillPending = false;
	KillAt = -1e9f;
	ScatteredAt = -1e9f;
}

void AYIXIFireflyScatter::ApplyTemplateAndScale()
{
	if (!IsValid(FireEffect))
	{
		return;
	}
	if (IsValid(FireSystem) && FireEffect->GetAsset() != FireSystem)
	{
		FireEffect->SetAsset(FireSystem, false);
	}
	FireEffect->SetRelativeScale3D(FVector(FMath::Max(0.01f, FireEffectScale)));
}

APawn* AYIXIFireflyScatter::GetLocalPawn() const
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return nullptr;
	}
	if (APlayerController* FirstPC = World->GetFirstPlayerController())
	{
		if (APawn* Pawn = FirstPC->GetPawn())
		{
			return Pawn;
		}
	}
	return UGameplayStatics::GetPlayerPawn(this, 0);
}
