#include "YIXI_Interaction/Story/YIXIV3ImpactDust.h"

#include "Components/MaterialBillboardComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "YIXI_Interaction/ScriptedProjectile/YIXIScriptedRock.h"
#include "YIXI_Interaction/Story/YIXIInteractionStoryCoordinator.h"

namespace
{
	const FName DustOpacityParameter(TEXT("DustOpacity"));
	const FVector PlumeOrigins[] = { FVector(-43, 16, 14), FVector(29, -38, 21), FVector(19, 37, 32) };
}

AYIXIV3ImpactDust::AYIXIV3ImpactDust()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("LandingPoint")));
	for (int32 Index = 0; Index < UE_ARRAY_COUNT(PlumeOrigins); ++Index)
	{
		const FName Name(*FString::Printf(TEXT("DustPlume%d"), Index));
		UMaterialBillboardComponent* Puff = CreateDefaultSubobject<UMaterialBillboardComponent>(Name);
		Puff->SetupAttachment(GetRootComponent());
		Puff->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Puff->SetGenerateOverlapEvents(false);
		Puff->SetCanEverAffectNavigation(false);
		Puff->SetCastShadow(false);
		Puff->SetRelativeLocation(PlumeOrigins[Index]);
		Puffs.Add(Puff);
	}
	SetActorHiddenInGame(true);
}

void AYIXIV3ImpactDust::BeginPlay()
{
	Super::BeginPlay();
	if (!IsValid(Story) || !IsValid(DustMaterial) || Story->GetWorld() != GetWorld())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: assign the local story and a soft dust material."), *GetName());
		return;
	}
	if (!AttackRock)
	{
		AttackRock = Story->AttackCue;
	}
	if (!IsValid(AttackRock) || AttackRock != Story->AttackCue || AttackRock->GetWorld() != GetWorld())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: dust requires the story's return attack rock."), *GetName());
		return;
	}
	DustInstance = UMaterialInstanceDynamic::Create(DustMaterial, this);
	DustInstance->SetScalarParameterValue(DustOpacityParameter, 0.0f);
	for (int32 Index = 0; Index < Puffs.Num(); ++Index)
	{
		Puffs[Index]->AddElement(DustInstance, nullptr, false, 58.f + Index * 8.f, 42.f + Index * 10.f, nullptr);
	}
	AttackRock->OnImpact.AddDynamic(this, &ThisClass::OnRockLanded);
	Story->OnStageChanged.AddDynamic(this, &ThisClass::OnStoryStageChanged);
	if (AttackRock->HasImpacted())
	{
		OnRockLanded(AttackRock->GetActiveRequestId());
	}
}

void AYIXIV3ImpactDust::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (IsValid(Story)) { Story->OnStageChanged.RemoveAll(this); }
	if (IsValid(AttackRock)) { AttackRock->OnImpact.RemoveAll(this); }
	Super::EndPlay(EndPlayReason);
}

void AYIXIV3ImpactDust::OnRockLanded(int32 RequestId)
{
	if (ImpactId != 0 || RequestId <= 0 || !IsValid(AttackRock) || !IsValid(AttackRock->RockMesh)
		|| !AttackRock->HasImpacted() || AttackRock->GetActiveRequestId() != RequestId || !IsValid(Story))
	{
		return;
	}
	ImpactId = RequestId;
	const FBoxSphereBounds& RockBounds = AttackRock->RockMesh->Bounds;
	SetActorLocation(RockBounds.Origin - FVector::UpVector * RockBounds.BoxExtent.Z);
	DustInstance->SetScalarParameterValue(DustOpacityParameter, ImpactOpacity);
	SetActorHiddenInGame(false);
	SetActorTickEnabled(true);
	OnStoryStageChanged(Story->Stage);
}

void AYIXIV3ImpactDust::OnStoryStageChanged(EYIXIInteractionStoryStage Stage)
{
	if (ImpactId == 0)
	{
		return;
	}
	if (Stage == EYIXIInteractionStoryStage::Discovery)
	{
		RevealAge = -1.0f;
		SetActorHiddenInGame(false);
		SetActorTickEnabled(true);
	}
	else if (Stage == EYIXIInteractionStoryStage::V3Presentation)
	{
		RevealAge = 0.0f;
	}
	else if (Stage == EYIXIInteractionStoryStage::MatchCut || Stage == EYIXIInteractionStoryStage::Stopped
		|| Stage == EYIXIInteractionStoryStage::Completed || Stage == EYIXIInteractionStoryStage::V3NightPresentation)
	{
		SetActorHiddenInGame(true);
		SetActorTickEnabled(false);
	}
}

void AYIXIV3ImpactDust::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	Age += DeltaSeconds;
	const float Settle = FMath::SmoothStep(0.f, 1.6f, Age);
	float Opacity = FMath::Lerp(ImpactOpacity, ResidualOpacity, Settle);
	if (RevealAge >= 0.0f)
	{
		RevealAge += DeltaSeconds;
		Opacity *= 1.0f - FMath::SmoothStep(0.f, FMath::Max(0.1f, RevealFadeSeconds), RevealAge);
		if (Opacity <= UE_KINDA_SMALL_NUMBER)
		{
			SetActorHiddenInGame(true);
			SetActorTickEnabled(false);
			return;
		}
	}
	DustInstance->SetScalarParameterValue(DustOpacityParameter, Opacity);
	for (int32 Index = 0; Index < Puffs.Num(); ++Index)
	{
		const float Phase = Age * 0.62f + 2.1f * Index;
		const FVector Drift(15.f * Settle + 5.f * FMath::Sin(Phase), 5.f * FMath::Cos(Phase),
			(19.f + 5.f * Index) * Settle + 3.f * FMath::Sin(Phase * 0.8f));
		Puffs[Index]->SetRelativeLocation(PlumeOrigins[Index] + Drift);
	}
}
