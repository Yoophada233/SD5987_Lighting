#pragma once

#include "MoverSimulationTypes.h"
#include "YIXIV3NeutralInput.generated.h"

/** Supplies local cinematic movement and facing while the director owns the pawn. */
UCLASS(Transient)
class UYIXIV3NeutralInput : public UObject, public IMoverInputProducerInterface
{
    GENERATED_BODY()
public:
    FVector MoveVelocity=FVector::ZeroVector;
    FVector Facing=FVector::ZeroVector;
    virtual void ProduceInput_Implementation(int32 SimTimeMs, FMoverInputCmdContext& Command) override;
};
