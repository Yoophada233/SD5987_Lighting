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

DEFINE_LOG_CATEGORY_STATIC(LogYIXIInteractFire, Log, All);

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
				InputComponent->BindKey(InteractionKey, IE_Pressed, this, &AYIXIInteractFire::InteractionPressed);
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
	Interact(Pawn);
}

void AYIXIInteractFire::ApplyFireState()
{
	// 编辑器预览时灯光保持可见，方便调位置/强度；进游戏才跟火焰开关走。
	if (!HasActorBegunPlay())
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
	if (!HasActorBegunPlay())
	{
		FireEffect->bAutoActivate = bFireOn;
		return;
	}
	if (bFireOn)
	{
		ApplyTemplateAndScale();
		FireEffect->Activate(true);
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
	if (IsValid(FireSystem) && FireEffect->GetAsset() != FireSystem)
	{
		// 保留我们后面要重设的 override 参数，不被模板切换清空。
		FireEffect->SetAsset(FireSystem, false);
	}
	// Grid3D 流体需要火源采样网格：没有它只画包围盒、不出火。
	// 要贴着自己模型烧，就把 SourceMesh 换成和 BodyMesh 同一个模型。
	if (IsValid(SourceMesh))
	{
		FireEffect->SetVariableStaticMesh(FName(TEXT("User.StaticMesh")), SourceMesh);
	}
	// 截图里的红框就是这个，仅调试用。
	FireEffect->SetVariableBool(FName(TEXT("User.DrawBounds")), bDrawSimulationBounds);
	FireEffect->SetRelativeScale3D(FVector(FMath::Max(0.01f, FireEffectScale)));
}
