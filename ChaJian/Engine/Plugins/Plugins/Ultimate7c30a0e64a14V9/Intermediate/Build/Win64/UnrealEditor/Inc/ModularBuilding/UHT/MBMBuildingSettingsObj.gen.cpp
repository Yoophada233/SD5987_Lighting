// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBMBuildingSettingsObj.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBMBuildingSettingsObj() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBModularSnapType(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBMBuildingSettingsObj(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBMBuildingSettingsObj(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBMBuildingSettingsObj **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBMBuildingSettingsObj_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Data/MBMBuildingSettingsObj.h" },
		{ "ModuleRelativePath", "Public/Data/MBMBuildingSettingsObj.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableModularSnapping_MetaData[] = {
		{ "Category", "Modular Snapping" },
		{ "DisplayName", "Enable Modular Snapping" },
		{ "ModuleRelativePath", "Public/Data/MBMBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SnappingType_MetaData[] = {
		{ "Category", "Modular Snapping" },
		{ "ModuleRelativePath", "Public/Data/MBMBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoundCorrectionSensitivity_MetaData[] = {
		{ "Category", "Modular Snapping" },
		{ "ClampMin", "0" },
		{ "Delta", "50" },
		{ "EditCondition", "SnappingType == EMBModularSnapType::BoundCorrection" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/MBMBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSnapOffsetCond_MetaData[] = {
		{ "Category", "Offset" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/Data/MBMBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SnapOffset_MetaData[] = {
		{ "Category", "Offset" },
		{ "ClampMax", "10000.000000" },
		{ "ClampMin", "0" },
		{ "Delta", "50" },
		{ "EditCondition", "bSnapOffsetCond" },
		{ "ModuleRelativePath", "Public/Data/MBMBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bZOffsetCond_MetaData[] = {
		{ "Category", "Offset" },
		{ "DisplayName", "Z Offset" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/Data/MBMBuildingSettingsObj.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZOffset_MetaData[] = {
		{ "Category", "Offset" },
		{ "ClampMax", "10000.000000" },
		{ "ClampMin", "0" },
		{ "Delta", "50" },
		{ "EditCondition", "bZOffsetCond" },
		{ "ModuleRelativePath", "Public/Data/MBMBuildingSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBMBuildingSettingsObj constinit property declarations ******************
	static void NewProp_bEnableModularSnapping_SetBit(void* Obj)
	{
		((UMBMBuildingSettingsObj*)Obj)->bEnableModularSnapping = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableModularSnapping;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SnappingType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SnappingType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BoundCorrectionSensitivity;
	static void NewProp_bSnapOffsetCond_SetBit(void* Obj)
	{
		((UMBMBuildingSettingsObj*)Obj)->bSnapOffsetCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSnapOffsetCond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SnapOffset;
	static void NewProp_bZOffsetCond_SetBit(void* Obj)
	{
		((UMBMBuildingSettingsObj*)Obj)->bZOffsetCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bZOffsetCond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ZOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBMBuildingSettingsObj constinit property declarations ********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBMBuildingSettingsObj>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBMBuildingSettingsObj Property Definitions *****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableModularSnapping = { "bEnableModularSnapping", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBMBuildingSettingsObj), &UHT_STATICS::NewProp_bEnableModularSnapping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableModularSnapping_MetaData), NewProp_bEnableModularSnapping_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_SnappingType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_SnappingType = { "SnappingType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBMBuildingSettingsObj, SnappingType), Z_Construct_UEnum_ModularBuilding_EMBModularSnapType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SnappingType_MetaData), NewProp_SnappingType_MetaData) }; // cad1894023e8a4bfb7781085b322ae5283e0e3a6
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BoundCorrectionSensitivity = { "BoundCorrectionSensitivity", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBMBuildingSettingsObj, BoundCorrectionSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundCorrectionSensitivity_MetaData), NewProp_BoundCorrectionSensitivity_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSnapOffsetCond = { "bSnapOffsetCond", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBMBuildingSettingsObj), &UHT_STATICS::NewProp_bSnapOffsetCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSnapOffsetCond_MetaData), NewProp_bSnapOffsetCond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SnapOffset = { "SnapOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBMBuildingSettingsObj, SnapOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SnapOffset_MetaData), NewProp_SnapOffset_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bZOffsetCond = { "bZOffsetCond", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBMBuildingSettingsObj), &UHT_STATICS::NewProp_bZOffsetCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bZOffsetCond_MetaData), NewProp_bZOffsetCond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ZOffset = { "ZOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBMBuildingSettingsObj, ZOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZOffset_MetaData), NewProp_ZOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableModularSnapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SnappingType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SnappingType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BoundCorrectionSensitivity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSnapOffsetCond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SnapOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bZOffsetCond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ZOffset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBMBuildingSettingsObj Property Definitions *******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UObject,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBMBuildingSettingsObj,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UMBMBuildingSettingsObj;
UClass* Z_Construct_UClass_UMBMBuildingSettingsObj(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBMBuildingSettingsObj;
		if (!Z_Registration_Info_UClass_UMBMBuildingSettingsObj.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBMBuildingSettingsObj"),
				Z_Registration_Info_UClass_UMBMBuildingSettingsObj.InnerSingleton,
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
		return Z_Registration_Info_UClass_UMBMBuildingSettingsObj.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBMBuildingSettingsObj.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBMBuildingSettingsObj.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBMBuildingSettingsObj.OuterSingleton;
}
#undef UHT_STATICS
UMBMBuildingSettingsObj::UMBMBuildingSettingsObj(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBMBuildingSettingsObj);
UMBMBuildingSettingsObj::~UMBMBuildingSettingsObj() {}
// ********** End Class UMBMBuildingSettingsObj ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBMBuildingSettingsObj_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBMBuildingSettingsObj, TEXT("UMBMBuildingSettingsObj"), &Z_Registration_Info_UClass_UMBMBuildingSettingsObj, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBMBuildingSettingsObj), 3384345805U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBMBuildingSettingsObj_h__Script_ModularBuilding_399b17ef907f8c00cb93fb48c299efa737552c1b{
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
