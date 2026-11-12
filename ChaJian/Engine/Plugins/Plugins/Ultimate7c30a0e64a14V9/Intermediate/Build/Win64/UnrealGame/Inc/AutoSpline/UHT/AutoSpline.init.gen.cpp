// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAutoSpline_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_AutoSpline;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_AutoSpline(ETypeConstructPhase)
	{
		if (!Z_Registration_Info_UPackage__Script_AutoSpline.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/AutoSpline",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000000,
			0x4CDB1E5E,
			0x02B49E9B,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_AutoSpline.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_AutoSpline.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_AutoSpline(Z_Construct_UPackage__Script_AutoSpline, TEXT("/Script/AutoSpline"), Z_Registration_Info_UPackage__Script_AutoSpline, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x4CDB1E5E, 0x02B49E9B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
