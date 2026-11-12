// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBPBuildingSettingsObj.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBPBuildingSettingsObj() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBPBuildingSettingsObj(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBPBuildingSettingsObj(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBPBuildingSettingsObj **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBPBuildingSettingsObj_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Data/MBPBuildingSettingsObj.h" },
		{ "ModuleRelativePath", "Public/Data/MBPBuildingSettingsObj.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableSurfaceSnapping_MetaData[] = {
		{ "Category", "Prop Placement" },
		{ "DisplayName", "Enable Modular Snapping" },
		{ "ModuleRelativePath", "Public/Data/MBPBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCustomRotationRateCond_MetaData[] = {
		{ "Category", "Prop Placement" },
		{ "DisplayName", "Custom Rotation Rate" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/Data/MBPBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomRotationRate_MetaData[] = {
		{ "Category", "Prop Placement" },
		{ "ClampMax", "359.000000" },
		{ "ClampMin", "0" },
		{ "Delta", "1" },
		{ "EditCondition", "bCustomRotationRateCond" },
		{ "ModuleRelativePath", "Public/Data/MBPBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bScaleRateCond_MetaData[] = {
		{ "Category", "Prop Placement" },
		{ "DisplayName", "Scale Rate" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/Data/MBPBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleRate_MetaData[] = {
		{ "Category", "Prop Placement" },
		{ "ClampMin", "0.100000" },
		{ "Delta", "0.100000" },
		{ "EditCondition", "bScaleRateCond" },
		{ "ModuleRelativePath", "Public/Data/MBPBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bZOffsetCond_MetaData[] = {
		{ "Category", "Prop Placement" },
		{ "DisplayName", "Z Offset" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/Data/MBPBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZOffset_MetaData[] = {
		{ "Category", "Prop Placement" },
		{ "ClampMax", "50000.000000" },
		{ "ClampMin", "-1000.000000" },
		{ "Delta", "50" },
		{ "DisplayName", "Z Offset" },
		{ "EditCondition", "bZOffsetCond" },
		{ "ModuleRelativePath", "Public/Data/MBPBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBPBuildingSettingsObj constinit property declarations ******************
	static void NewProp_bEnableSurfaceSnapping_SetBit(void* Obj)
	{
		((UMBPBuildingSettingsObj*)Obj)->bEnableSurfaceSnapping = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableSurfaceSnapping;
	static void NewProp_bCustomRotationRateCond_SetBit(void* Obj)
	{
		((UMBPBuildingSettingsObj*)Obj)->bCustomRotationRateCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCustomRotationRateCond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CustomRotationRate;
	static void NewProp_bScaleRateCond_SetBit(void* Obj)
	{
		((UMBPBuildingSettingsObj*)Obj)->bScaleRateCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bScaleRateCond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleRate;
	static void NewProp_bZOffsetCond_SetBit(void* Obj)
	{
		((UMBPBuildingSettingsObj*)Obj)->bZOffsetCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bZOffsetCond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ZOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBPBuildingSettingsObj constinit property declarations ********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBPBuildingSettingsObj>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBPBuildingSettingsObj Property Definitions *****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableSurfaceSnapping = { "bEnableSurfaceSnapping", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBPBuildingSettingsObj), &UHT_STATICS::NewProp_bEnableSurfaceSnapping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableSurfaceSnapping_MetaData), NewProp_bEnableSurfaceSnapping_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCustomRotationRateCond = { "bCustomRotationRateCond", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBPBuildingSettingsObj), &UHT_STATICS::NewProp_bCustomRotationRateCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCustomRotationRateCond_MetaData), NewProp_bCustomRotationRateCond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CustomRotationRate = { "CustomRotationRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPBuildingSettingsObj, CustomRotationRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomRotationRate_MetaData), NewProp_CustomRotationRate_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bScaleRateCond = { "bScaleRateCond", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBPBuildingSettingsObj), &UHT_STATICS::NewProp_bScaleRateCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bScaleRateCond_MetaData), NewProp_bScaleRateCond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ScaleRate = { "ScaleRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPBuildingSettingsObj, ScaleRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleRate_MetaData), NewProp_ScaleRate_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bZOffsetCond = { "bZOffsetCond", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBPBuildingSettingsObj), &UHT_STATICS::NewProp_bZOffsetCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bZOffsetCond_MetaData), NewProp_bZOffsetCond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ZOffset = { "ZOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPBuildingSettingsObj, ZOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZOffset_MetaData), NewProp_ZOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableSurfaceSnapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCustomRotationRateCond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CustomRotationRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bScaleRateCond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScaleRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bZOffsetCond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ZOffset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBPBuildingSettingsObj Property Definitions *******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UObject,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBPBuildingSettingsObj,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UMBPBuildingSettingsObj;
UClass* Z_Construct_UClass_UMBPBuildingSettingsObj(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBPBuildingSettingsObj;
		if (!Z_Registration_Info_UClass_UMBPBuildingSettingsObj.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBPBuildingSettingsObj"),
				Z_Registration_Info_UClass_UMBPBuildingSettingsObj.InnerSingleton,
				nullptr,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_UMBPBuildingSettingsObj.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBPBuildingSettingsObj.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBPBuildingSettingsObj.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBPBuildingSettingsObj.OuterSingleton;
}
#undef UHT_STATICS
UMBPBuildingSettingsObj::UMBPBuildingSettingsObj(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBPBuildingSettingsObj);
UMBPBuildingSettingsObj::~UMBPBuildingSettingsObj() {}
// ********** End Class UMBPBuildingSettingsObj ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBPBuildingSettingsObj_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBPBuildingSettingsObj, TEXT("UMBPBuildingSettingsObj"), &Z_Registration_Info_UClass_UMBPBuildingSettingsObj, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBPBuildingSettingsObj), 3617284539U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBPBuildingSettingsObj_h__Script_ModularBuilding_503ebb46a3d7df99c96023f1da48266f5392830d{
	TEXT("/Script/ModularBuilding"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
