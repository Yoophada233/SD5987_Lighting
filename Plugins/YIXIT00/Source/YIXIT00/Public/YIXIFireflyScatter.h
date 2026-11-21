#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXIFireflyScatter.generated.h"

class USceneComponent;
class USphereComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UPointLightComponent;

/**
 * 萤火虫（常亮式，惊散可选）：默认正常播放 NS_Firefly，玩家走近也不消失。
 *
 * - 不改原粒子资产：FireSystem 默认 /Game/VFX/NS_Firefly，原样播放。
 * - 常亮模式（默认，bScatterOnPlayer = false）：遇到玩家不惊散、不消失，点光也不灭。
 * - 想恢复老行为就勾上 bScatterOnPlayer：触发后保持 spawning 继续 ScatterDuration 秒，
 *   同时把 FireEffect 朝远离玩家的方向推，新粒子沿逃跑路径生成、旧粒子留在原地 →
 *   一团萤火虫"惊起四散"的拖尾；推完立刻 Deactivate 停掉新粒子，剩下的按自身寿命自然熄灭。
 * - 离开感应范围 + RegenDelay 后自动恢复（可关），回来继续飞。
 */
UCLASS(Blueprintable, BlueprintType)
class YIXIT00_API AYIXIFireflyScatter : public AActor
{
	GENERATED_BODY()

public:
	AYIXIFireflyScatter();

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	/** 粒子组件：驱散时整体平移的就是它，感应中心不动。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Firefly")
	TObjectPtr<UNiagaraComponent> FireEffect;

	/** 点光源：挂在 FireEffect 下，跟萤火虫一起跑；位置、强度、颜色、范围等直接在细节面板调组件即可。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Firefly|Light")
	TObjectPtr<UPointLightComponent> FireflyLight;

	/** 萤火虫惊散消失时灯光是否一起灭；关掉后灯光常亮、只手动控制。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Light")
	bool bFireflyLightFollowsScatter = true;

	/** 感应范围可视化（编辑器可见，游戏中隐藏）。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly")
	TObjectPtr<USphereComponent> SenseArea;

	/** 粒子模板，默认 NS_Firefly，原样播放，不改资产。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly")
	TObjectPtr<UNiagaraSystem> FireSystem;

	/** 只缩放粒子。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly", meta = (ClampMin = "0.01", UIMin = "0.01"))
	float FireEffectScale = 1.0f;

	/** 玩家进入这个距离即惊散。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Sense", meta = (ClampMin = "0.0", Units = "cm"))
	float SenseRadius = 300.0f;

	/** 距离检测间隔，越小越灵敏。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Sense", meta = (ClampMin = "0.01", Units = "s"))
	float CheckInterval = 0.1f;

	/** 遇到玩家是否惊散消失；默认关闭 = 常亮，遇到玩家也不散、灯也不灭。想恢复老行为就勾上。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Sense")
	bool bScatterOnPlayer = false;

	/** 惊起时长：这段时间内边推边生，拖出四散尾迹。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Scatter", meta = (ClampMin = "0.05", Units = "s"))
	float ScatterDuration = 0.7f;

	/** 推离速度。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Scatter", meta = (ClampMin = "0.0", Units = "cm/s"))
	float ScatterSpeed = 350.0f;

	/** 上飘分量 0~1：萤火虫受惊往上蹿一点更像。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Scatter", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ScatterUpBias = 0.35f;

	/** 抖动幅度，四散不走直线。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Scatter", meta = (ClampMin = "0.0", Units = "cm/s"))
	float ScatterJitter = 60.0f;

	/** 快速清场开关：默认关闭，还原上一版"停发后按寿命自然熄灭"；
	 * 觉得余烬拖就手动勾上，再调下面的 KillRemainderDelay。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Scatter")
	bool bInstantClearRemainder = false;

	/** 停发后多久把残留粒子直接清掉（仅 bInstantClearRemainder 开启时有效）。
	 * Deactivate 只停新粒子，旧粒子按寿命熄灭；到期调 DeactivateImmediate 瞬间清场。
	 * 改小散得快，改大保留一点消散过程。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Scatter", meta = (ClampMin = "0.0", Units = "s", EditCondition = "bInstantClearRemainder"))
	float KillRemainderDelay = 0.6f;

	/** 离开后自动恢复；关掉就是一次性，散了不再回来。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Regen")
	bool bRegenerate = true;

	/** 离开感应范围多久后恢复。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Regen", meta = (ClampMin = "0.0", Units = "s", EditCondition = "bRegenerate"))
	float RegenDelaySeconds = 6.0f;

	/** 恢复时先回到原位再点亮，避免"瞬移一团"。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Firefly|Regen", meta = (EditCondition = "bRegenerate"))
	bool bSnapHomeOnRegen = true;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "YIXI|Firefly")
	bool bScattered = false;

	UFUNCTION(BlueprintCallable, Category = "YIXI|Firefly")
	void TriggerScatter();

	UFUNCTION(BlueprintCallable, Category = "YIXI|Firefly")
	void Recover();

private:
	float TimeSinceCheck = 0.0f;
	float ScatterAge = 0.0f;
	bool bScattering = false;
	float ScatteredAt = -1e9f;
	float KillAt = -1e9f;
	bool bKillPending = false;
	FVector ScatterDir = FVector::ForwardVector;
	FVector HomeRelativeLocation = FVector::ZeroVector;
	float ScatterPhase = 0.0f;

	void ApplyTemplateAndScale();
	APawn* GetLocalPawn() const;
};
