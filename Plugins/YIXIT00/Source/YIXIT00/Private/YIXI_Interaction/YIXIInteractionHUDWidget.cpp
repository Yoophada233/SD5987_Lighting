#include "YIXI_Interaction/YIXIInteractionHUDWidget.h"

#include "Blueprint/WidgetLayoutLibrary.h"
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

	TArray<FString> WrapSubtitle(const FString& Text, const FSlateFontInfo& Font,
		const FSlateFontMeasure& Measure, double MaxWidth)
	{
		TArray<FString> Paragraphs;
		Text.ParseIntoArrayLines(Paragraphs, false);
		TArray<FString> Lines;
		for (const FString& Paragraph : Paragraphs)
		{
			TArray<FString> Words;
			Paragraph.ParseIntoArrayWS(Words);
			FString Line;
			for (const FString& Word : Words)
			{
				FString Candidate = Line.IsEmpty() ? Word : Line + TEXT(" ") + Word;
				const FVector2D CandidateSize = Measure.Measure(Candidate, Font);
				if (!Line.IsEmpty() && CandidateSize.X > MaxWidth)
				{
					Lines.Add(MoveTemp(Line));
					Line = Word;
				}
				else
				{
					Line = MoveTemp(Candidate);
				}
			}
			Lines.Add(MoveTemp(Line));
		}
		return Lines;
	}
}

void UYIXIInteractionHUDWidget::ShowDialogueSubtitle(UObject* SpeakerSession, const FText& Text)
{
	if (!IsValid(SpeakerSession))
	{
		return;
	}

	ClearDialogueSubtitle();
	if (bShowDialogueSubtitles && !Text.IsEmpty())
	{
		SubtitleOwner = SpeakerSession;
		ActiveDialogueSubtitle = Text;
		DialogueSubtitleAlpha = DialogueSubtitleEnterDuration <= 0.0f ? 1.0f : 0.0f;
	}
	if (const TSharedPtr<SWidget> Widget = GetCachedWidget())
	{
		Widget->Invalidate(EInvalidateWidgetReason::Paint);
	}
}

void UYIXIInteractionHUDWidget::UpdateDialogueSubtitle(UObject* SpeakerSession, const FText& Text)
{
	if (SpeakerSession && SubtitleOwner.Get() == SpeakerSession && !bSubtitleExiting)
	{
		ActiveDialogueSubtitle = Text;
		if (const TSharedPtr<SWidget> Widget = GetCachedWidget())
		{
			Widget->Invalidate(EInvalidateWidgetReason::Paint);
		}
	}
}

void UYIXIInteractionHUDWidget::HideDialogueSubtitle(UObject* SpeakerSession, bool bImmediate)
{
	if (!SpeakerSession || SubtitleOwner.Get() != SpeakerSession)
	{
		return;
	}

	if (bImmediate || DialogueSubtitleExitDuration <= 0.0f)
	{
		ClearDialogueSubtitle();
		if (const TSharedPtr<SWidget> Widget = GetCachedWidget())
		{
			Widget->Invalidate(EInvalidateWidgetReason::Paint);
		}
	}
	else if (!bSubtitleExiting)
	{
		bSubtitleExiting = true;
		SubtitleExitStartAlpha = DialogueSubtitleAlpha;
		SubtitleTransitionElapsed = 0.0f;
	}
}

void UYIXIInteractionHUDWidget::ClearDialogueSubtitle()
{
	SubtitleOwner.Reset();
	ActiveDialogueSubtitle = FText::GetEmpty();
	DialogueSubtitleAlpha = 0.0f;
	SubtitleTransitionElapsed = 0.0f;
	SubtitleExitStartAlpha = 0.0f;
	bSubtitleExiting = false;
}

void UYIXIInteractionHUDWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (!SubtitleOwner.IsValid() || !bShowDialogueSubtitles)
	{
		if (SubtitleOwner.IsValid() || !ActiveDialogueSubtitle.IsEmpty() || DialogueSubtitleAlpha > 0.0f)
		{
			ClearDialogueSubtitle();
			if (const TSharedPtr<SWidget> Widget = GetCachedWidget())
			{
				Widget->Invalidate(EInvalidateWidgetReason::Paint);
			}
		}
		return;
	}

	if (!bSubtitleExiting && DialogueSubtitleAlpha >= 1.0f)
	{
		return;
	}

	SubtitleTransitionElapsed += InDeltaTime;
	const float Duration = bSubtitleExiting ? DialogueSubtitleExitDuration : DialogueSubtitleEnterDuration;
	const float Progress = Duration <= UE_SMALL_NUMBER ? 1.0f : FMath::Clamp(SubtitleTransitionElapsed / Duration, 0.0f, 1.0f);
	const float EasedProgress = FMath::SmoothStep(0.0f, 1.0f, Progress);
	DialogueSubtitleAlpha = bSubtitleExiting ? SubtitleExitStartAlpha * (1.0f - EasedProgress) : EasedProgress;
	if (bSubtitleExiting && Progress >= 1.0f)
	{
		ClearDialogueSubtitle();
	}
	if (const TSharedPtr<SWidget> Widget = GetCachedWidget())
	{
		Widget->Invalidate(EInvalidateWidgetReason::Paint);
	}
}

void UYIXIInteractionHUDWidget::NativeDestruct()
{
	ClearDialogueSubtitle();
	Super::NativeDestruct();
}

int32 UYIXIInteractionHUDWidget::PaintDialogueSubtitle(const FGeometry& Geometry,
	FSlateWindowElementList& OutDrawElements, int32 Layer, const FWidgetStyle& InWidgetStyle) const
{
	if (!bShowDialogueSubtitles || !SubtitleOwner.IsValid() || ActiveDialogueSubtitle.IsEmpty()
		|| DialogueSubtitleAlpha <= UE_KINDA_SMALL_NUMBER || !FSlateApplication::IsInitialized())
	{
		return Layer;
	}

	const FVector2D CanvasSize = Geometry.GetLocalSize();
	if (CanvasSize.X <= 0.0 || CanvasSize.Y <= 0.0)
	{
		return Layer;
	}

	FMargin SafePadding(0.0f);
	const FVector2D ViewportPixels = UWidgetLayoutLibrary::GetViewportSize(this);
	if (ViewportPixels.X > 0.0 && ViewportPixels.Y > 0.0)
	{
		FSlateApplication::Get().GetSafeZoneSize(SafePadding, ViewportPixels);
		SafePadding = SafePadding * FMargin(CanvasSize.X / ViewportPixels.X, CanvasSize.Y / ViewportPixels.Y,
			CanvasSize.X / ViewportPixels.X, CanvasSize.Y / ViewportPixels.Y);
	}

	constexpr int32 OutlineSize = 2;
	FSlateFontInfo Font = FCoreStyle::GetDefaultFontStyle(TEXT("Regular"), FMath::Clamp(DialogueSubtitleFontSize, 12, 96));
	const FLinearColor Ink = InWidgetStyle.GetColorAndOpacityTint() * FLinearColor(0.99f, 0.975f, 0.94f, 1.0f);
	const FLinearColor Outline = WithOpacity(FLinearColor(0.015f, 0.012f, 0.01f, 0.95f), DialogueSubtitleAlpha * Ink.A);
	Font.OutlineSettings = FFontOutlineSettings(OutlineSize, Outline);
	const FSlateFontMeasure& Measure = *FSlateApplication::Get().GetRenderer()->GetFontMeasureService();
	const double SafeWidth = FMath::Max(1.0, CanvasSize.X - SafePadding.Left - SafePadding.Right);
	const double Width = FMath::Max(1.0, FMath::Min(SafeWidth, CanvasSize.X * FMath::Clamp(DialogueSubtitleMaxWidth, 0.2f, 1.0f))
		- 2.0 * OutlineSize);
	const TArray<FString> Lines = WrapSubtitle(ActiveDialogueSubtitle.ToString(), Font, Measure, Width);
	const double LineHeight = Measure.GetMaxCharacterHeight(Font) + 4.0;
	const double BlockHeight = LineHeight * Lines.Num();
	const double MaxCenterY = CanvasSize.Y - SafePadding.Bottom - FMath::Max(12.0, CanvasSize.Y * 0.02) - BlockHeight * 0.5;
	const double MinCenterY = SafePadding.Top + OutlineSize + BlockHeight * 0.5;
	const double CenterY = FMath::Clamp(CanvasSize.Y * DialogueSubtitleScreenPosition.Y,
		MinCenterY, FMath::Max(MinCenterY, MaxCenterY));
	const double CenterX = FMath::Clamp(CanvasSize.X * DialogueSubtitleScreenPosition.X,
		SafePadding.Left + Width * 0.5, CanvasSize.X - SafePadding.Right - Width * 0.5);

	// At zero visibility the top edge, including the outline, is below the whole player viewport.
	const double OffscreenY = CanvasSize.Y + OutlineSize + 1.0;
	double LineY = FMath::Lerp(OffscreenY, CenterY - BlockHeight * 0.5, DialogueSubtitleAlpha);
	for (const FString& Line : Lines)
	{
		const FVector2D TextSize = Measure.Measure(Line, Font);
		const FVector2D TopLeft(CenterX - TextSize.X * 0.5, LineY);
		FSlateDrawElement::MakeText(OutDrawElements, ++Layer,
			Geometry.ToPaintGeometry(TextSize, FSlateLayoutTransform(TopLeft)), Line, Font,
			ESlateDrawEffect::None, WithOpacity(Ink, DialogueSubtitleAlpha));
		LineY += LineHeight;
	}
	return Layer;
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
		return PaintDialogueSubtitle(AllottedGeometry, OutDrawElements, Layer, InWidgetStyle);
	}

	const FVector2D Center = Position + ScreenOffset;
	const FVector2D CanvasSize = AllottedGeometry.GetLocalSize();
	if (Center.X < 0.0 || Center.Y < 0.0 || Center.X >= CanvasSize.X || Center.Y >= CanvasSize.Y)
	{
		return PaintDialogueSubtitle(AllottedGeometry, OutDrawElements, Layer, InWidgetStyle);
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

	return PaintDialogueSubtitle(AllottedGeometry, OutDrawElements, Layer, InWidgetStyle);
}
