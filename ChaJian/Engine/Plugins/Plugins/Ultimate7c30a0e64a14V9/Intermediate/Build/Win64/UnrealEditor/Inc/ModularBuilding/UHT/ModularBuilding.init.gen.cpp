// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeModularBuilding_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
	MODULARBUILDING_API UFunction* Z_Construct_UDelegateFunction_ModularBuilding_OnModActorSlotClickedSignature__DelegateSignature(ETypeConstructPhase);
	MODULARBUILDING_API UFunction* Z_Construct_UDelegateFunction_ModularBuilding_OnPlacementTypeChanged__DelegateSignature(ETypeConstructPhase);
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ModularBuilding;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase)
	{
		if (!Z_Registration_Info_UPackage__Script_ModularBuilding.OuterSingleton)
		{
		static FTypeConstructFunc* SingletonFuncArray[] = {
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_ModularBuilding_OnModActorSlotClickedSignature__DelegateSignature,
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_ModularBuilding_OnPlacementTypeChanged__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/ModularBuilding",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000040,
			0x84779710,
			0x60EB459C,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ModularBuilding.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_ModularBuilding.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ModularBuilding(Z_Construct_UPackage__Script_ModularBuilding, TEXT("/Script/ModularBuilding"), Z_Registration_Info_UPackage__Script_ModularBuilding, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x84779710, 0x60EB459C));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
