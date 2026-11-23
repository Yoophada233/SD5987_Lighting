#include "YIXISenseLight.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/RectLightComponent.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AYIXISenseLight::AYIXISenseLight()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	BodyMesh->SetupAttachment(Root);
	BodyMesh->SetCollisionProfileName(TEXT("BlockAll"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMesh.Succeeded())
	{
		BodyMesh->SetStaticMesh(CubeMesh.Object);
	}

	SenseArea = CreateDefaultSubobject<USphereComponent>(TEXT("SenseArea"));
	SenseArea->SetupAttachment(Root);
	SenseArea->InitSphereRadius(SenseRadius);
	SenseArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SenseArea->SetGenerateOverlapEvents(false);
	SenseArea->SetHiddenInGame(true);

	// 灯光挂点挂在模型下：换模型后相对位置不变，拖动它就是改"灯在模型上的位置"。
	LightAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("LightAnchor"));
	LightAnchor->SetupAttachment(BodyMesh);
	LightAnchor->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

	RectLight0 = CreateDefaultSubobject<URectLightComponent>(TEXT("RectLight0"));
	RectLight0->SetupAttachment(LightAnchor);
	RectLight0->SetMobility(EComponentMobility::Movable);

	RectLight1 = CreateDefaultSubobject<URectLightComponent>(TEXT("RectLight1"));
	RectLight1->SetupAttachment(LightAnchor);
	RectLight1->SetMobility(EComponentMobility::Movable);
	RectLight1->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));

	RectLight2 = CreateDefaultSubobject<URectLightComponent>(TEXT("RectLight2"));
	RectLight2->SetupAttachment(LightAnchor);
	RectLight2->SetMobility(EComponentMobility::Movable);
	RectLight2->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));

	RectLight3 = CreateDefaultSubobject<URectLightComponent>(TEXT("RectLight3"));
	RectLight3->SetupAttachment(LightAnchor);
	RectLight3->SetMobility(EComponentMobility::Movable);
	RectLight3->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
}

void AYIXISenseLight::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (SenseArea)
	{
		SenseArea->SetSphereRadius(FMath::Max(0.0f, SenseRadius), false);
	}
	// 编辑器里能立刻预览开关状态。
	ApplyLightState();
}

void AYIXISenseLight::BeginPlay()
{
	Super::BeginPlay();

	TimeSinceCheck = CheckInterval; // 第一帧立刻检测一次，进场站在圈里直接开灯。
	SetLightOn(bLightOnStart);
}

void AYIXISenseLight::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

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

	// 触发一次后常亮：玩家离开也不熄灭。
	const float Dist = FVector::Dist(Pawn->GetActorLocation(), GetActorLocation());
	if (Dist <= SenseRadius && !bLightOn)
	{
		SetLightOn(true);
	}
}

void AYIXISenseLight::SetLightOn(bool bOn)
{
	bLightOn = bOn;
	ApplyLightState();
}

void AYIXISenseLight::ToggleLight()
{
	SetLightOn(!bLightOn);
}

void AYIXISenseLight::ApplyLightState()
{
	URectLightComponent* Lights[] = { RectLight0, RectLight1, RectLight2, RectLight3 };
	// 编辑器预览时灯光保持可见，方便调位置/强度；进游戏才跟感应开关走。
	const bool bVisible = !HasActorBegunPlay() ? true : bLightOn;
	for (URectLightComponent* Light : Lights)
	{
		if (IsValid(Light))
		{
			Light->SetVisibility(bVisible);
		}
	}
}

APawn* AYIXISenseLight::GetLocalPawn() const
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
