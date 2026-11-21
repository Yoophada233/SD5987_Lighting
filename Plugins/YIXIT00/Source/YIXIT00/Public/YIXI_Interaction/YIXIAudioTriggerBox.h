#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YIXIAudioTriggerBox.generated.h"

class APawn;
class UBoxComponent;
class UPrimitiveComponent;
class USceneComponent;
class USoundAttenuation;
class USoundBase;

USTRUCT(BlueprintType)
struct YIXIT00_API FYIXIAudioTriggerSound
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	TObjectPtr<USoundBase> Sound = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound", meta = (ClampMin = "0", Units = "s"))
	float Delay = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound", meta = (ClampMin = "0"))
	float Volume = 1.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FYIXIAudioTriggered, APawn*, PlayerPawn);

/** A configurable sound sequence fired when a possessed player pawn enters the box. */
UCLASS(Blueprintable)
class YIXIT00_API AYIXIAudioTriggerBox : public AActor
{
	GENERATED_BODY()

public:
	AYIXIAudioTriggerBox();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Trigger")
	TObjectPtr<UBoxComponent> BoxCollision;

	/** Move this component to place the origin of spatial sounds. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|Spatial Audio")
	TObjectPtr<USceneComponent> AudioLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Trigger")
	bool bEnabled = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Trigger")
	bool bTriggerOnce = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sounds|Crowd Panic")
	TObjectPtr<USoundBase> CrowdPanicSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sounds|Crowd Panic", meta = (ClampMin = "0", Units = "s"))
	float CrowdPanicDelay = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sounds|Crowd Panic", meta = (ClampMin = "0"))
	float CrowdPanicVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sounds|Horse")
	TObjectPtr<USoundBase> HorseSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sounds|Horse", meta = (ClampMin = "0", Units = "s"))
	float HorseDelay = 0.45f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sounds|Horse", meta = (ClampMin = "0"))
	float HorseVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sounds|Distant Bell")
	TObjectPtr<USoundBase> DistantBellSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sounds|Distant Bell", meta = (ClampMin = "0", Units = "s"))
	float DistantBellDelay = 1.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sounds|Distant Bell", meta = (ClampMin = "0"))
	float DistantBellVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Sounds")
	TArray<FYIXIAudioTriggerSound> AdditionalSounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Spatial Audio")
	bool bUseSpatialAudio = true;

	/** If unset, playback uses the sound asset's own attenuation settings. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|Spatial Audio", meta = (EditCondition = "bUseSpatialAudio"))
	TObjectPtr<USoundAttenuation> AttenuationSettings;

	UPROPERTY(BlueprintAssignable, Category = "YIXI|Trigger")
	FYIXIAudioTriggered OnTriggered;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "YIXI|Trigger")
	int32 TriggerCount = 0;

	/** Gives an armed one-shot trigger a chance to accept a player who was already inside. */
	bool TryTriggerFirstOverlappingPlayer(APawn* Pawn);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UFUNCTION()
	void HandlePlayerEntered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void HandlePlayerLeft(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);

	void ScheduleOverlapCheck();
	void CheckOverlappingPlayers();
	void TryTriggerForPawn(APawn* Pawn);
	bool TriggerForPlayer(APawn* Pawn);
	void QueueSound(USoundBase* Sound, float Delay, float Volume);
	void PlaySound(TWeakObjectPtr<USoundBase> Sound, float Volume);

	TSet<TWeakObjectPtr<APawn>> PlayersInside;
	bool bOverlapCheckScheduled = false;
};
