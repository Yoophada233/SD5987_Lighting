#include "YIXISenseFire.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

AYIXISenseFire::AYIXISenseFire()
{
	// 感应火默认只走靠近感应，不占 E 键；想同时保留按键就勾上 bEnableKeyInteract。
	bEnableKeyInteract = false;
	PrimaryActorTick.bCanEverTick = true;
}

void AYIXISenseFire::OnConstruction(const FTransform& Transform)
{
	// SenseRadius 是唯一范围入口：同步给 InteractionRadius，
	// 基类的球体可视化和 Interact() 距离检查都跟着走。
	InteractionRadius = FMath::Max(0.0f, SenseRadius);
	Super::OnConstruction(Transform);
}

void AYIXISenseFire::BeginPlay()
{
	InteractionRadius = FMath::Max(0.0f, SenseRadius);
	Super::BeginPlay();

	LastSensedTime = -1e9f;
	TimeSinceCheck = CheckInterval; // 第一帧立刻检测一次，进场站在圈里直接点火。
}

void AYIXISenseFire::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	TimeSinceCheck += DeltaSeconds;
	if (TimeSinceCheck < CheckInterval)
	{
		return;
	}
	TimeSinceCheck = 0.0f;

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}
	APawn* Pawn = nullptr;
	if (APlayerController* FirstPC = World->GetFirstPlayerController())
	{
		Pawn = FirstPC->GetPawn();
	}
	if (!IsValid(Pawn))
	{
		Pawn = UGameplayStatics::GetPlayerPawn(this, 0);
	}
	if (!IsValid(Pawn))
	{
		return;
	}

	const float Now = World->GetTimeSeconds();
	const float Dist = FVector::Dist(Pawn->GetActorLocation(), GetActorLocation());
	if (Dist <= SenseRadius)
	{
		LastSensedTime = Now;
		if (!bFireOn)
		{
			SetFireOn(true);
		}
	}
	else if (bFireOn && bTurnOffOnLeave && !bStayOnAfterTriggered)
	{
		if (Now - LastSensedTime >= TurnOffDelaySeconds)
		{
			SetFireOn(false);
		}
	}
}
