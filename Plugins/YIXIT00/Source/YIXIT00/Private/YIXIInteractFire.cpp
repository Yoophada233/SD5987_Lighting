#include "YIXIInteractFire.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "Components/PointLightComponent.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "UObject/ConstructorHelpers.h"
#include "DataDrivenShaderPlatformInfo.h"
#include "EngineUtils.h"
#include "HAL/IConsoleManager.h"
#include "RenderUtils.h"
#include "RHI.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIInteractFire, Log, All);

namespace
{
	bool CanRenderVolumeFire()
	{
		const IConsoleVariable* VolumesAllowed =
			IConsoleManager::Get().FindConsoleVariable(TEXT("r.HeterogeneousVolumes.Allowed"));
		return (!VolumesAllowed || VolumesAllowed->GetInt() != 0)
			&& FDataDrivenShaderPlatformInfo::IsValid(GMaxRHIShaderPlatform)
			&& DoesRuntimeSupportHeterogeneousVolumes(GMaxRHIShaderPlatform);
	}
}

AYIXIInteractFire::AYIXIInteractFire()
{
	PrimaryActorTick.bCanEverTick = false;

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

	InteractionArea = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionArea"));
	InteractionArea->SetupAttachment(Root);
	InteractionArea->InitSphereRadius(InteractionRadius);
	InteractionArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	InteractionArea->SetGenerateOverlapEvents(false);
	InteractionArea->SetHiddenInGame(true);

	// 生成点挂在模型下：换模型后相对位置不变，拖动它就是改“粒子在模型上的位置”。
	FireAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("FireAnchor"));
	FireAnchor->SetupAttachment(BodyMesh);
	FireAnchor->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

	FireEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("FireEffect"));
	FireEffect->SetupAttachment(FireAnchor);
	FireEffect->SetAutoActivate(false);
	FireEffect->bAutoActivate = false;

	FireLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("FireLight"));
	FireLight->SetupAttachment(FireAnchor);
	FireLight->SetMobility(EComponentMobility::Movable);

	// 默认用你指定的粒子。
	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> DefaultFire(TEXT("/Game/VFX/NS_InteractFire.NS_InteractFire"));
	if (DefaultFire.Succeeded())
	{
		FireSystem = DefaultFire.Object;
		FireEffect->SetAsset(DefaultFire.Object);
	}
	else
	{
		UE_LOG(LogYIXIInteractFire, Warning, TEXT("Default NS_InteractFire not found; assign FireSystem in Details."));
	}

	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> SpriteFallback(
		TEXT("/Game/F_FreeFlameFx_Pack/FX/NS_Flame_8_Torch.NS_Flame_8_Torch"));
	SpriteFireFallback = SpriteFallback.Object;

	// 默认火源采样网格：模板自带的小火源，跟着 FireAnchor 走。
	// 想让火焰贴着你的模型表面烧，在细节面板把 SourceMesh 换成和 BodyMesh 同一个模型。
	static ConstructorHelpers::FObjectFinder<UStaticMesh> DefaultSource(TEXT("/NiagaraFluids/Meshes/FireSourceMesh.FireSourceMesh"));
	if (DefaultSource.Succeeded())
	{
		SourceMesh = DefaultSource.Object;
	}
}

void AYIXIInteractFire::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (InteractionArea)
	{
		InteractionArea->SetSphereRadius(FMath::Max(0.0f, InteractionRadius), false);
	}
	ApplyTemplateAndScale();
	// 编辑器里拖 FireEffectScale / 换模板能立刻预览开关状态。
	ApplyFireState();
}

void AYIXIInteractFire::BeginPlay()
{
	Super::BeginPlay();

	// Keep the placement cube available in the editor without rendering it or blocking players in-game.
	const UStaticMesh* DefaultBody = GetDefault<AYIXIInteractFire>()->BodyMesh->GetStaticMesh();
	if (BodyMesh && DefaultBody && BodyMesh->GetStaticMesh() == DefaultBody)
	{
		BodyMesh->SetHiddenInGame(true);
		BodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	// 游戏里强制关红框：只在编辑器摆放时显示。
	bDrawSimulationBounds = false;
	ApplyTemplateAndScale();
	SetFireOn(bFireOnStart);

	if (bEnableKeyInteract)
	{
		if (APlayerController* PC = GetWorld() ? GetWorld()->GetFirstPlayerController() : nullptr)
		{
			EnableInput(PC);
			if (InputComponent)
			{
				InputComponent->BindKey(InteractionKey, IE_Pressed, this, &AYIXIInteractFire::InteractionPressed).bConsumeInput = false;
			}
		}
	}
}

void AYIXIInteractFire::EndPlay(const EEndPlayReason::Type Reason)
{
	if (bEnableKeyInteract)
	{
		DisableInput(GetWorld() ? GetWorld()->GetFirstPlayerController() : nullptr);
	}
	Super::EndPlay(Reason);
}

void AYIXIInteractFire::Interact(APawn* InstigatorPawn)
{
	if (!IsValid(InstigatorPawn))
	{
		return;
	}
	// 距离门槛：防止隔着半张图也能点。
	const float Dist = FVector::Dist(InstigatorPawn->GetActorLocation(), GetActorLocation());
	if (Dist > InteractionRadius)
	{
		return;
	}
	if (!bFireOn)
	{
		SetFireOn(true);
	}
	else if (bToggleOffOnSecondInteract)
	{
		SetFireOn(false);
	}
}

void AYIXIInteractFire::SetFireOn(bool bOn)
{
	bFireOn = bOn;
	ApplyFireState();
}

void AYIXIInteractFire::ToggleFire()
{
	SetFireOn(!bFireOn);
}

void AYIXIInteractFire::SetFireEffectScale(float Scale)
{
	FireEffectScale = FMath::Max(0.01f, Scale);
	ApplyTemplateAndScale();
}

void AYIXIInteractFire::InteractionPressed()
{
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

	const FVector PlayerLocation = Pawn->GetActorLocation();
	const double DistanceSquared = FVector::DistSquared(PlayerLocation, GetActorLocation());
	if (DistanceSquared > FMath::Square(InteractionRadius))
	{
		return;
	}

	// Non-consuming bindings let nearby fires receive E even when a distant fire bound it first.
	// Pick just one recipient when their interaction areas overlap.
	for (TActorIterator<AYIXIInteractFire> It(World); It; ++It)
	{
		const AYIXIInteractFire* Other = *It;
		if (Other == this || !Other->bEnableKeyInteract || !Other->InputComponent || Other->InteractionKey != InteractionKey)
		{
			continue;
		}
		const double OtherDistance = FVector::DistSquared(PlayerLocation, Other->GetActorLocation());
		if (OtherDistance <= FMath::Square(Other->InteractionRadius)
			&& (OtherDistance < DistanceSquared || (OtherDistance == DistanceSquared && Other->GetUniqueID() < GetUniqueID())))
		{
			return;
		}
	}
	Interact(Pawn);
}

void AYIXIInteractFire::ApplyFireState()
{
	const bool bInPlay = HasActorBegunPlay() || IsActorBeginningPlay();
	// 编辑器预览时灯光保持可见，方便调位置/强度；进游戏才跟火焰开关走。
	if (!bInPlay)
	{
		if (IsValid(FireLight))
		{
			FireLight->SetVisibility(true);
		}
	}
	else if (bFireLightFollowsFireState && IsValid(FireLight))
	{
		FireLight->SetVisibility(bFireOn);
	}
	if (!IsValid(FireEffect))
	{
		return;
	}
	// HasBegunPlay 为 false 时（编辑器预览）只切激活标记，不调 Activate/Deactivate。
	// 注意：直接写 bAutoActivate 字段，不要调 SetAutoActivate（构造后调用会报 warning）。
	if (!bInPlay)
	{
		FireEffect->bAutoActivate = bFireOn;
		return;
	}
	if (bFireOn)
	{
		ApplyTemplateAndScale();
		FireEffect->Activate(true);
	}
	else if (SpriteFireFallback && FireEffect->GetAsset() == SpriteFireFallback)
	{
		// The looping flipbook holds a particle after emission stops. Remove it when the torch is switched off.
		FireEffect->DeactivateImmediate();
	}
	else
	{
		FireEffect->Deactivate();
	}
}

void AYIXIInteractFire::ApplyTemplateAndScale()
{
	if (!IsValid(FireEffect))
	{
		return;
	}
	const bool bUseSprites = IsValid(SpriteFireFallback)
		&& FireSystem == GetDefault<AYIXIInteractFire>()->FireSystem
		&& (!IsValid(FireSystem) || !CanRenderVolumeFire());
	UNiagaraSystem* SelectedSystem = bUseSprites ? SpriteFireFallback.Get() : FireSystem.Get();
	if (IsValid(SelectedSystem) && FireEffect->GetAsset() != SelectedSystem)
	{
		FireEffect->SetAsset(SelectedSystem, false);
	}
	// Grid3D 流体需要火源采样网格：没有它只画包围盒、不出火。
	// 要贴着自己模型烧，就把 SourceMesh 换成和 BodyMesh 同一个模型。
	if (!bUseSprites)
	{
		if (IsValid(SourceMesh))
		{
			FireEffect->SetVariableStaticMesh(FName(TEXT("User.StaticMesh")), SourceMesh);
		}
		FireEffect->SetVariableBool(FName(TEXT("User.DrawBounds")), bDrawSimulationBounds);
	}
	FireEffect->SetRelativeScale3D(FVector(FMath::Max(0.01f, FireEffectScale)));
}
