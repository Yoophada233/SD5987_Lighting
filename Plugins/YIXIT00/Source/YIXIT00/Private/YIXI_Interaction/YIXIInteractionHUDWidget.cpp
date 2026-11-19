#include "YIXI_Interaction/YIXIInteractionHUDWidget.h"

#include "Brushes/SlateRoundedBoxBrush.h"
#include "Fonts/FontMeasure.h"
#include "Framework/Application/SlateApplication.h"
#include "Rendering/DrawElements.h"
#include "Rendering/SlateRenderer.h"
#include "Styling/CoreStyle.h"
#include "Widgets/SWidget.h"

namespace
{
	FLinearColor WithOpacity(const FLinearColor& Color, float Opacity)
	{
		return FLinearColor(Color.R, Color.G, Color.B, Color.A * Opacity);
	}
}

void UYIXIInteractionHUDWidget::UpdatePrompt(EYIXIInteractionPromptState NewState,
	const FVector2D& PlayerPosition, const FText& KeyText, float DeltaTime, bool bTargetChanged)
{
	const bool bWasVisible = State != EYIXIInteractionPromptState::Hidden;
	State = NewState;
	if (State == EYIXIInteractionPromptState::Hidden)
	{
		VisibleAlpha = 0.0f;
		ReadyAlpha = 0.0f;
		if (!bWasVisible)
		{
			return;
		}
	}
	else
	{
		Position = PlayerPosition;
		KeyLabel = KeyText.ToString();
		if (bTargetChanged)
		{
			VisibleAlpha = 0.0f;
			ReadyAlpha = 0.0f;
		}

		const float ReadyGoal = State == EYIXIInteractionPromptState::Ready ? 1.0f : 0.0f;
		if (UITransitionDuration > UE_SMALL_NUMBER)
		{
			const float Rate = 1.0f / UITransitionDuration;
			VisibleAlpha = FMath::FInterpConstantTo(VisibleAlpha, 1.0f, DeltaTime, Rate);
			ReadyAlpha = FMath::FInterpConstantTo(ReadyAlpha, ReadyGoal, DeltaTime, Rate);
		}
		else
		{
			VisibleAlpha = 1.0f;
			ReadyAlpha = ReadyGoal;
		}
	}

	if (const TSharedPtr<SWidget> Widget = GetCachedWidget())
	{
		Widget->Invalidate(EInvalidateWidgetReason::Paint);
	}
}

int32 UYIXIInteractionHUDWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	int32 Layer = Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements,
		LayerId, InWidgetStyle, bParentEnabled);
	if (State == EYIXIInteractionPromptState::Hidden || VisibleAlpha <= UE_KINDA_SMALL_NUMBER)
	{
		return Layer;
	}

	const FVector2D Center = Position + ScreenOffset;
	const FVector2D CanvasSize = AllottedGeometry.GetLocalSize();
	if (Center.X < 0.0 || Center.Y < 0.0 || Center.X >= CanvasSize.X || Center.Y >= CanvasSize.Y)
	{
		return Layer;
	}

	const float DotDiameter = FMath::Max(DotSize, 1.0f);
	const float RingDiameter = FMath::Max(RingSize, DotDiameter + 1.0f);
	const float Blend = FMath::SmoothStep(0.0f, 1.0f, ReadyAlpha);
	const float Alpha = FMath::Clamp(PromptOpacity, 0.0f, 1.0f)
		* FMath::SmoothStep(0.0f, 1.0f, VisibleAlpha);
	const FLinearColor Ink = InWidgetStyle.GetColorAndOpacityTint() * PromptColor;
	const FLinearColor Shadow = FLinearColor(0.0f, 0.0f, 0.0f, 0.68f);

	if (Blend < 1.0f - UE_KINDA_SMALL_NUMBER)
	{
		static const FSlateRoundedBoxBrush CircularBrush(FLinearColor::White);
		const float DotAlpha = Alpha * (1.0f - Blend);
		const float DotShadowSize = DotDiameter + 1.75f;
		const FVector2D ShadowCenter = Center + FVector2D(0.0, 0.5);
		FSlateDrawElement::MakeBox(OutDrawElements, ++Layer,
			AllottedGeometry.ToPaintGeometry(FVector2D(DotShadowSize), FSlateLayoutTransform(ShadowCenter - FVector2D(DotShadowSize * 0.5f))),
			&CircularBrush, ESlateDrawEffect::None, WithOpacity(Shadow, DotAlpha));
		FSlateDrawElement::MakeBox(OutDrawElements, ++Layer,
			AllottedGeometry.ToPaintGeometry(FVector2D(DotDiameter), FSlateLayoutTransform(Center - FVector2D(DotDiameter * 0.5f))),
			&CircularBrush, ESlateDrawEffect::None, WithOpacity(Ink, DotAlpha));
	}

	if (Blend > UE_KINDA_SMALL_NUMBER)
	{
		constexpr int32 SegmentCount = 32;
		const double Radius = 0.5 * FMath::Lerp(DotDiameter, RingDiameter, Blend);
		TArray<FVector2D> Ring;
		Ring.Reserve(SegmentCount + 1);
		for (int32 Segment = 0; Segment <= SegmentCount; ++Segment)
		{
			const double Angle = 2.0 * UE_DOUBLE_PI * Segment / SegmentCount;
			Ring.Emplace(Center + FVector2D(FMath::Cos(Angle), FMath::Sin(Angle)) * Radius);
		}
		const float Thickness = FMath::Max(RingThickness, 0.5f);
		const float RingAlpha = Alpha * Blend;
		FSlateDrawElement::MakeLines(OutDrawElements, ++Layer, AllottedGeometry.ToPaintGeometry(),
			Ring, ESlateDrawEffect::None, WithOpacity(Shadow, RingAlpha), true, Thickness + 2.0f);
		FSlateDrawElement::MakeLines(OutDrawElements, ++Layer, AllottedGeometry.ToPaintGeometry(),
			Ring, ESlateDrawEffect::None, WithOpacity(Ink, RingAlpha), true, Thickness);

		if (!KeyLabel.IsEmpty() && FSlateApplication::IsInitialized())
		{
			const FSlateFontInfo Font = FCoreStyle::GetDefaultFontStyle(TEXT("Regular"),
				FMath::Max(8.0f, RingDiameter * 0.48f));
			const FVector2D TextSize = FSlateApplication::Get().GetRenderer()->GetFontMeasureService()->Measure(KeyLabel, Font);
			const FPaintGeometry TextGeometry = AllottedGeometry.ToPaintGeometry(TextSize,
				FSlateLayoutTransform(Center - TextSize * 0.5));
			FSlateDrawElement::MakeText(OutDrawElements, ++Layer, TextGeometry, KeyLabel, Font,
				ESlateDrawEffect::None, WithOpacity(Ink, RingAlpha));
		}
	}

	return Layer;
}
