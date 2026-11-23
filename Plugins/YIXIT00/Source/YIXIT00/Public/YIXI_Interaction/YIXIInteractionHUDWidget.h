#pragma once

#include "Blueprint/UserWidget.h"
#include "YIXIInteractionHUDWidget.generated.h"

UENUM(BlueprintType)
enum class EYIXIInteractionPromptState : uint8
{
	Hidden,
	Dot,
	Ready
};

/** Draws one interaction marker on a full-screen, non-interactive UMG player layer. */
UCLASS(Blueprintable)
class YIXIT00_API UYIXIInteractionHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Appearance", meta = (ClampMin = "1.0"))
	float DotSize = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Appearance", meta = (ClampMin = "8.0"))
	float RingSize = 24.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Appearance", meta = (ClampMin = "0.5"))
	float RingThickness = 1.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Appearance")
	FLinearColor PromptColor = FLinearColor(0.96f, 0.95f, 0.91f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Appearance", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float PromptOpacity = 0.95f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Appearance")
	FVector2D ScreenOffset = FVector2D(0.0, -6.0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Appearance", meta = (ClampMin = "0.0", Units = "s"))
	float UITransitionDuration = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Subtitles")
	bool bShowDialogueSubtitles = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Subtitles", meta = (ClampMin = "12", ClampMax = "96"))
	int32 DialogueSubtitleFontSize = 42;

	/** Normalized center of the subtitle block, clamped to the player's safe area. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Subtitles", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	FVector2D DialogueSubtitleScreenPosition = FVector2D(0.5, 0.905);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Subtitles", meta = (ClampMin = "0.2", ClampMax = "1.0"))
	float DialogueSubtitleMaxWidth = 0.75f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Subtitles", meta = (ClampMin = "0.0", Units = "s"))
	float DialogueSubtitleEnterDuration = 0.30f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Subtitles", meta = (ClampMin = "0.0", Units = "s"))
	float DialogueSubtitleExitDuration = 0.25f;

	void UpdatePrompt(EYIXIInteractionPromptState NewState, const FVector2D& PlayerPosition,
		const FText& KeyText, float DeltaTime, bool bTargetChanged);

	void ShowDialogueSubtitle(UObject* SpeakerSession, const FText& Text);
	void UpdateDialogueSubtitle(UObject* SpeakerSession, const FText& Text);
	void HideDialogueSubtitle(UObject* SpeakerSession, bool bImmediate);

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void NativeDestruct() override;
	virtual int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
		const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements,
		int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

private:
	void ClearDialogueSubtitle();
	int32 PaintDialogueSubtitle(const FGeometry& Geometry, FSlateWindowElementList& OutDrawElements,
		int32 Layer, const FWidgetStyle& InWidgetStyle) const;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "Dialogue|Subtitles", meta = (AllowPrivateAccess = "true"))
	FText ActiveDialogueSubtitle;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "Dialogue|Subtitles", meta = (AllowPrivateAccess = "true"))
	float DialogueSubtitleAlpha = 0.0f;

	TWeakObjectPtr<UObject> SubtitleOwner;
	float SubtitleTransitionElapsed = 0.0f;
	float SubtitleExitStartAlpha = 0.0f;
	bool bSubtitleExiting = false;

	EYIXIInteractionPromptState State = EYIXIInteractionPromptState::Hidden;
	FVector2D Position = FVector2D::ZeroVector;
	FString KeyLabel;
	float VisibleAlpha = 0.0f;
	float ReadyAlpha = 0.0f;
};
