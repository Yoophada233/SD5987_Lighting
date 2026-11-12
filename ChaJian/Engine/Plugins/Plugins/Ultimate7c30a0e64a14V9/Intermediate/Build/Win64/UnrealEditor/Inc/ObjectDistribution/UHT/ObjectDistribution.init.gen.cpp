// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectDistribution_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
	OBJECTDISTRIBUTION_API UFunction* Z_Construct_UDelegateFunction_ObjectDistribution_OnLevelActorDeletedNativeSignature__DelegateSignature(ETypeConstructPhase);
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ObjectDistribution;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase)
	{
		if (!Z_Registration_Info_UPackage__Script_ObjectDistribution.OuterSingleton)
		{
		static FTypeConstructFunc* SingletonFuncArray[] = {
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_ObjectDistribution_OnLevelActorDeletedNativeSignature__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/ObjectDistribution",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000040,
			0x753DE43D,
			0x71A21EAE,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ObjectDistribution.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_ObjectDistribution.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ObjectDistribution(Z_Construct_UPackage__Script_ObjectDistribution, TEXT("/Script/ObjectDistribution"), Z_Registration_Info_UPackage__Script_ObjectDistribution, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x753DE43D, 0x71A21EAE));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
