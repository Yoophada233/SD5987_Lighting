#pragma once

#include "YIXI_Interaction/ScriptedProjectile/YIXIStoryTriggerBox.h"
#include "YIXIBGMTriggerBoxes.generated.h"

class UAudioComponent;
class USoundBase;

/** Plays one non-spatial music stream when the local player enters. */
UCLASS(Blueprintable)
class YIXIT00_API AYIXIBGMStartBox : public AYIXIStoryTriggerBox
{
	GENERATED_BODY()

public:
	AYIXIBGMStartBox();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|BGM", meta = (DisplayName = "BGM Sound"))
	TObjectPtr<USoundBase> MusicSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|BGM", meta = (ClampMin = "0.0", UIMax = "1.0", DisplayName = "BGM Volume"))
	float MusicVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|BGM", meta = (ClampMin = "0.0", Units = "s"))
	float FadeInDuration = 2.0f;

	/** If off, entering again can replay the music after it has stopped. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|BGM")
	bool bPlayOnce = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "YIXI|BGM")
	TObjectPtr<UAudioComponent> MusicAudio;

	void FadeOutMusic(float Duration);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UFUNCTION()
	void OnLocalPlayerEntered(APawn* Pawn);

	bool bHasPlayed = false;
};

/** Fades out the specific placed start box assigned to this volume. */
UCLASS(Blueprintable)
class YIXIT00_API AYIXIBGMStopBox : public AYIXIStoryTriggerBox
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "YIXI|BGM", meta = (DisplayName = "Target BGM Box"))
	TObjectPtr<AYIXIBGMStartBox> TargetBGMBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YIXI|BGM", meta = (ClampMin = "0.0", Units = "s"))
	float FadeOutDuration = 2.0f;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UFUNCTION()
	void OnLocalPlayerEntered(APawn* Pawn);
};
