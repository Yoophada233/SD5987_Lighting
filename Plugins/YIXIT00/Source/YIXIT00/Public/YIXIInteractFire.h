#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputCoreTypes.h"
#include "YIXIInteractFire.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class USphereComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UPointLightComponent;

/**
 * 可交互粒子火焰：玩家按 E 点燃 / 熄灭。
 *
 * - BodyMesh：随时在细节面板替换任意 StaticMesh 模型。
 * - FireAnchor：火焰在模型上的生成位置，在视口直接拖动（挂在 BodyMesh 下）。
 * - FireEffectScale：只缩放粒子特效，不缩放模型。
 * - 默认使用 /Game/VFX/NS_InteractFire，可在细节面板换成别的 Niagara。
 *
 * 输入走原生 E 键绑定，不依赖你现有的 IMC / IA_Interact，
 * 所以不用改角色蓝图和输入映射。想接提示 UI 时直接调 Interact() 即可。
 */
UCLASS(Blueprintable, BlueprintType)
class YIXIT00_API AYIXIInteractFire : public AActor
{
	GENERATED_BODY()

public:
	AYIXIInteractFire();

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type Reason) override;

	/** 根：移动整个物体用它，替换模型不会丢位置。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Fire")
	TObjectPtr<USceneComponent> Root;

	/** 本体模型：随时替换。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Body")
	TObjectPtr<UStaticMeshComponent> BodyMesh;

	/** 交互范围可视化（编辑器可见，游戏中隐藏，不做碰撞）。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Body")
	TObjectPtr<USphereComponent> InteractionArea;

	/** 火焰生成点：挂在 BodyMesh 下，视口拖动即可改位置。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Fire|Spawn")
	TObjectPtr<USceneComponent> FireAnchor;

	/** 粒子组件：只跟 FireAnchor 走，不跟模型缩放。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Fire|Spawn")
	TObjectPtr<UNiagaraComponent> FireEffect;

	/** 点光源：挂在 FireAnchor 下，跟火焰走；位置、强度、颜色、范围等直接在细节面板调组件即可。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Fire|Light")
	TObjectPtr<UPointLightComponent> FireLight;

	/** 点光源是否跟火焰开关走；关掉后灯光常亮、只手动控制。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Light")
	bool bFireLightFollowsFireState = true;

	/** 粒子模板，默认 NS_InteractFire，可换别的 Niagara。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Spawn")
	TObjectPtr<UNiagaraSystem> FireSystem;

	/** Sprite fire used in place of the default volume fire when volume rendering is disabled. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Spawn", AdvancedDisplay)
	TObjectPtr<UNiagaraSystem> SpriteFireFallback;

	/** 火焰形状采样网格：Grid3D 流体从这个模型的表面采样火源。
	 * 默认是模板自带的小火源网格，跟着 FireAnchor 走；
	 * 想让火焰贴着你的模型表面烧，就把它换成和 BodyMesh 同一个模型。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Spawn")
	TObjectPtr<UStaticMesh> SourceMesh;

	/** 编辑器里显示模拟包围盒（红框）方便摆放；进游戏自动强制关闭。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Spawn")
	bool bDrawSimulationBounds = true;

	/** 只缩放粒子，不缩放模型。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Spawn", meta = (ClampMin = "0.01", UIMin = "0.01"))
	float FireEffectScale = 1.0f;

	/** 靠近到这个距离内按 E 才有效。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Interaction", meta = (ClampMin = "0.0", Units = "cm"))
	float InteractionRadius = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Interaction")
	FKey InteractionKey = EKeys::E;

	/** 允许按键交互；感应火子类默认关掉，只走靠近自动点火。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Interaction")
	bool bEnableKeyInteract = true;

	/** 开局是否就点着。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Interaction")
	bool bFireOnStart = false;

	/** 第二次按 E 是否熄灭；关掉就是“只能点一次”。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Fire|Interaction")
	bool bToggleOffOnSecondInteract = true;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "YIXI|Fire")
	bool bFireOn = false;

	/** 给外部交互系统 / UI 调的入口。 */
	UFUNCTION(BlueprintCallable, Category = "YIXI|Fire")
	void Interact(APawn* InstigatorPawn);

	UFUNCTION(BlueprintCallable, Category = "YIXI|Fire")
	void SetFireOn(bool bOn);

	UFUNCTION(BlueprintCallable, Category = "YIXI|Fire")
	void ToggleFire();

	/** 运行时改粒子大小（会自动钳制到 >= 0.01）。 */
	UFUNCTION(BlueprintCallable, Category = "YIXI|Fire")
	void SetFireEffectScale(float Scale);

private:
	void InteractionPressed();
	void ApplyFireState();
	void ApplyTemplateAndScale();
};
