#pragma once

#include "CoreMinimal.h"
#include "YIXIInteractFire.h"
#include "YIXISenseFire.generated.h"

/**
 * 感应式粒子火焰（感应灯）：玩家走近自动点火，离开后延时熄灭。
 *
 * 继承 AYIXIInteractFire 的全部火焰能力：
 * - BodyMesh：随时替换任意 StaticMesh 模型。
 * - FireAnchor：在视口拖动，改粒子在模型上的生成位置。
 * - FireEffectScale：只缩放粒子，不缩放模型。
 * - FireSystem 默认 /Game/VFX/NS_InteractFire，可换。
 * - SourceMesh：火源采样网格，想贴模型表面烧就换成和 BodyMesh 同一个。
 *
 * 和按 E 版本的区别：默认关闭按键交互，只走靠近感应。
 * 想两个都要（靠近自动亮，也能按 E 手动开关）就把 bEnableKeyInteract 勾上。
 */
UCLASS(Blueprintable, BlueprintType)
class YIXIT00_API AYIXISenseFire : public AYIXIInteractFire
{
	GENERATED_BODY()

public:
	AYIXISenseFire();

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	/** 感应半径：玩家进入这个距离自动点火。
	 * 会自动同步到 InteractionRadius，编辑器里的球体显示的也是这个范围。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sense", meta = (ClampMin = "0.0", Units = "cm"))
	float SenseRadius = 400.0f;

	/** 距离检测间隔：每隔多久检查一次玩家距离，越小越灵敏、越大越省。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sense", meta = (ClampMin = "0.01", Units = "s"))
	float CheckInterval = 0.1f;

	/** 离开感应范围后是否自动熄灭；关掉就是触发后常亮（配合 bStayOnAfterTriggered 二选一即可）。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sense")
	bool bTurnOffOnLeave = true;

	/** 离开后延迟多久熄灭，模拟感应灯延时。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sense", meta = (ClampMin = "0.0", Units = "s", EditCondition = "bTurnOffOnLeave"))
	float TurnOffDelaySeconds = 2.0f;

	/** 触发一次后保持常亮，不再熄灭。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sense")
	bool bStayOnAfterTriggered = false;

private:
	float TimeSinceCheck = 0.0f;
	float LastSensedTime = -1e9f;
};
