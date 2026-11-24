#pragma once

#include "MoverSimulationTypes.h"
#include "YIXIFirstRockTitleInputFilter.generated.h"

/** Filters locomotion after the template has produced its ragdoll data. */
UCLASS(Transient)
class UYIXIFirstRockTitleInputFilter : public UObject, public IMoverInputProducerInterface
{
	GENERATED_BODY()

public:
	virtual void ProduceInput_Implementation(int32 SimTimeMs, FMoverInputCmdContext& Command) override;
};
