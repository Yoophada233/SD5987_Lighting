#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "YIXIP04EditorLibrary.generated.h"

class ULevel;
class ULevelStreaming;

// Editor-only operations; no runtime terrain generation or MCP server.
UCLASS()
class YIXIT00_API UYIXIP04EditorLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="YIXI|P04|Editor")
    static FString CreateFlatLandscape(ULevel* TargetLevel, const FString& Label,
        FVector Origin, int32 ComponentsX, int32 ComponentsY, float XYScale, bool bValidateOnly,
        int32 NumSubsections = 1);

    UFUNCTION(BlueprintCallable, Category="YIXI|P04|Editor")
    static FString InspectLandscape(AActor* Actor);

    UFUNCTION(BlueprintCallable, Category="YIXI|P04|Editor")
    static FString ConfigureStreaming(ULevelStreaming* Stream,
        bool bInitiallyLoaded, bool bInitiallyVisible, bool bValidateOnly);
};
