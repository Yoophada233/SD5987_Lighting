#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXISenseLight.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class USphereComponent;
class UPointLightComponent;

/**
 * 感应式点光源（感应灯）：玩家走近自动亮，之后常亮不再熄灭。
 *
 * 逻辑对标 AYIXISenseFire，只是把"点火"换成"开灯"，且去掉了离开熄灭：
 * - BodyMesh：随时替换任意 StaticMesh 模型。
 * - LightAnchor：在视口拖动，改灯光在模型上的位置（挂在 BodyMesh 下）。
 * - SenseLight：点光源本体，位置、强度、颜色、范围等直接在细节面板调组件即可。
 * - SenseRadius：感应半径，编辑器里的球体显示的也是这个范围。
 */
UCLASS(Blueprintable, BlueprintType)
class YIXIT00_API AYIXISenseLight : public AActor
{
	GENERATED_BODY()

public:
	AYIXISenseLight();

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	/** 根：移动整个物体用它，替换模型不会丢位置。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|SenseLight")
	TObjectPtr<USceneComponent> Root;

	/** 本体模型：随时替换；纯灯光用不到模型时可以删掉，不影响灯。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|SenseLight|Body")
	TObjectPtr<UStaticMeshComponent> BodyMesh;

	/** 感应范围可视化（编辑器可见，游戏中隐藏，不做碰撞）。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|SenseLight|Body")
	TObjectPtr<USphereComponent> SenseArea;

	/** 灯光挂点：挂在 BodyMesh 下，视口拖动即可改位置。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|SenseLight|Light")
	TObjectPtr<USceneComponent> LightAnchor;

	/** 点光源：只跟 LightAnchor 走；位置、强度、颜色、范围等直接在细节面板调组件即可。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|SenseLight|Light")
	TObjectPtr<UPointLightComponent> SenseLight;

	/** 感应半径：玩家进入这个距离自动开灯，编辑器里的球体显示的也是这个范围。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|SenseLight|Sense", meta = (ClampMin = "0.0", Units = "cm"))
	float SenseRadius = 400.0f;

	/** 距离检测间隔：每隔多久检查一次玩家距离，越小越灵敏、越大越省。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|SenseLight|Sense", meta = (ClampMin = "0.01", Units = "s"))
	float CheckInterval = 0.1f;

	/** 开局是否就亮着。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|SenseLight|Sense")
	bool bLightOnStart = false;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "YIXI|SenseLight")
	bool bLightOn = false;

	UFUNCTION(BlueprintCallable, Category = "YIXI|SenseLight")
	void SetLightOn(bool bOn);

	UFUNCTION(BlueprintCallable, Category = "YIXI|SenseLight")
	void ToggleLight();

private:
	float TimeSinceCheck = 0.0f;

	void ApplyLightState();
	APawn* GetLocalPawn() const;
};
