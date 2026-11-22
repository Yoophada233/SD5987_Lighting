#pragma once

#include "Templates/SharedPointer.h"

class APlayerController;
class FYIXIFormalDayViewExtension;

// Own on the game thread, from the stable Day insert through the actual camera cut.
class FYIXIFormalCutFrameHold final
{
public:
    static TSharedPtr<FYIXIFormalCutFrameHold> Begin(APlayerController* Controller);
    bool IsCaptured() const;
    ~FYIXIFormalCutFrameHold();

private:
    explicit FYIXIFormalCutFrameHold(TSharedRef<FYIXIFormalDayViewExtension> InView);
    TSharedRef<FYIXIFormalDayViewExtension> View;
};
