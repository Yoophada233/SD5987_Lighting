#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXIV3ImpactDust.generated.h"

class AYIXIInteractionStoryCoordinator;
class AYIXIScriptedRock;
class UMaterialBillboardComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
enum class EYIXIInteractionStoryStage : uint8;

/** Sandboxed impact dressing. A faint remnant persists until the player discovers the landing site. */
UCLASS(Blueprintable)
class YIXIT00_API AYIXIV3ImpactDust : public AActor
{
	GENERATED_BODY()

public:
	AYIXIV3ImpactDust();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Dust")
	TObjectPtr<AYIXIInteractionStoryCoordinator> Story;

	/** Defaults to the story's return attack. */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "YIXI|Dust")
	TObjectPtr<AYIXIScriptedRock> AttackRock;

	/** Translucent soft-edge material with a DustOpacity scalar parameter. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Dust")
	TObjectPtr<UMaterialInterface> DustMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Dust", meta=(ClampMin="0", ClampMax="1"))
	float ImpactOpacity = 0.58f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Dust", meta=(ClampMin="0", ClampMax="1"))
	float ResidualOpacity = 0.18f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "YIXI|Dust", meta=(ClampMin="0.1", Units="s"))
	float RevealFadeSeconds = 3.0f;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaSeconds) override;

private:
	UFUNCTION()
	void OnRockLanded(int32 RequestId);

	UFUNCTION()
	void OnStoryStageChanged(EYIXIInteractionStoryStage Stage);

	UPROPERTY()
	TArray<TObjectPtr<UMaterialBillboardComponent>> Puffs;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> DustInstance;

	int32 ImpactId = 0;
	float Age = 0.0f;
	float RevealAge = -1.0f;
};
