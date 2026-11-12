// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAutoSplineEditor_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_AutoSplineEditor;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_AutoSplineEditor(ETypeConstructPhase)
	{
		if (!Z_Registration_Info_UPackage__Script_AutoSplineEditor.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/AutoSplineEditor",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000040,
			0x184827AE,
			0x2CC86D8C,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_AutoSplineEditor.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_AutoSplineEditor.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_AutoSplineEditor(Z_Construct_UPackage__Script_AutoSplineEditor, TEXT("/Script/AutoSplineEditor"), Z_Registration_Info_UPackage__Script_AutoSplineEditor, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x184827AE, 0x2CC86D8C));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
