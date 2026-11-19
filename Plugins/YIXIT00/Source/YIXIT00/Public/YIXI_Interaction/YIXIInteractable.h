#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "YIXIInteractable.generated.h"

class APawn;

USTRUCT(BlueprintType)
struct YIXIT00_API FYIXIInteractionPrompt
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    FVector WorldLocation = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction", meta = (ClampMin = "0", Units = "cm"))
    float DetectionRange = 300.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction", meta = (ClampMin = "0", Units = "cm"))
    float InteractRange = 150.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    FText ActionText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    bool bShowPrompt = true;
};

UINTERFACE(BlueprintType, Blueprintable)
class YIXIT00_API UYIXIInteractable : public UInterface
{
    GENERATED_BODY()
};

class YIXIT00_API IYIXIInteractable
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "YIXI|Interaction")
    bool CanInteract(APawn* Interactor) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "YIXI|Interaction")
    void Interact(APawn* Interactor);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "YIXI|Interaction")
    FYIXIInteractionPrompt GetInteractionPrompt(APawn* Interactor) const;
};
