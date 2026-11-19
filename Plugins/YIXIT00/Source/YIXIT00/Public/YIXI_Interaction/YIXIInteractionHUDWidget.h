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

	void UpdatePrompt(EYIXIInteractionPromptState NewState, const FVector2D& PlayerPosition,
		const FText& KeyText, float DeltaTime, bool bTargetChanged);

protected:
	virtual int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
		const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements,
		int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

private:
	EYIXIInteractionPromptState State = EYIXIInteractionPromptState::Hidden;
	FVector2D Position = FVector2D::ZeroVector;
	FString KeyLabel;
	float VisibleAlpha = 0.0f;
	float ReadyAlpha = 0.0f;
};
