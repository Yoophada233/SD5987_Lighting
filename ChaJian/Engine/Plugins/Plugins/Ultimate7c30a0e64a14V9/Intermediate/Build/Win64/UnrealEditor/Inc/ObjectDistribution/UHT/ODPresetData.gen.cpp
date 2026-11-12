// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODPresetData.h"
#include "ODMeshData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODPresetData() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FDistObjectData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODPresetData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FPresetMixerMapData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FODPresetData *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FODPresetData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FODPresetData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FODPresetData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/ODPresetData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetName_MetaData[] = {
		{ "Category", "Preset Data" },
		{ "ModuleRelativePath", "Public/Data/ODPresetData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetColor_MetaData[] = {
		{ "Category", "Preset Data" },
		{ "ModuleRelativePath", "Public/Data/ODPresetData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistObjectData_MetaData[] = {
		{ "Category", "Preset Data" },
		{ "ModuleRelativePath", "Public/Data/ODPresetData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FODPresetData constinit property declarations *********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_PresetName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PresetColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DistObjectData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DistObjectData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FODPresetData constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FODPresetData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS
static_assert(std::is_polymorphic<FODPresetData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FODPresetData cannot be polymorphic unless super FTableRowBase is polymorphic");

// ********** Begin ScriptStruct FODPresetData Property Definitions ********************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_PresetName = { "PresetName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(FODPresetData, PresetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetName_MetaData), NewProp_PresetName_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PresetColor = { "PresetColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FODPresetData, PresetColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetColor_MetaData), NewProp_PresetColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DistObjectData_Inner = { "DistObjectData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDistObjectData, METADATA_PARAMS(0, nullptr) }; // 51fcd38d1b5761471938c94c04fa1ed2d7d2df34
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_DistObjectData = { "DistObjectData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(FODPresetData, DistObjectData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistObjectData_MetaData), NewProp_DistObjectData_MetaData) }; // 51fcd38d1b5761471938c94c04fa1ed2d7d2df34
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistObjectData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistObjectData,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FODPresetData Property Definitions **********************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"ODPresetData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FODPresetData>(),
	alignof(FODPresetData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FODPresetData;
UScriptStruct* Z_Construct_UScriptStruct_FODPresetData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FODPresetData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FODPresetData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FODPresetData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("ODPresetData"));
		}
		return Z_Registration_Info_UScriptStruct_FODPresetData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FODPresetData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FODPresetData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FODPresetData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FODPresetData *******************************************************

// ********** Begin ScriptStruct FPresetMixerMapData ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FPresetMixerMapData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FPresetMixerMapData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPresetMixerMapData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/ODPresetData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetName_MetaData[] = {
		{ "Category", "Preset Mixer Data" },
		{ "ModuleRelativePath", "Public/Data/ODPresetData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CheckState_MetaData[] = {
		{ "Category", "Preset Mixer Data" },
		{ "ModuleRelativePath", "Public/Data/ODPresetData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPresetMixerMapData constinit property declarations ***************
	static const UECodeGen_Private::FNamePropertyParams NewProp_PresetName;
	static void NewProp_CheckState_SetBit(void* Obj)
	{
		((FPresetMixerMapData*)Obj)->CheckState = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_CheckState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPresetMixerMapData constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPresetMixerMapData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FPresetMixerMapData Property Definitions **************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_PresetName = { "PresetName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(FPresetMixerMapData, PresetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetName_MetaData), NewProp_PresetName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_CheckState = { "CheckState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FPresetMixerMapData), &UHT_STATICS::NewProp_CheckState_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CheckState_MetaData), NewProp_CheckState_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CheckState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FPresetMixerMapData Property Definitions ****************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"PresetMixerMapData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FPresetMixerMapData>(),
	alignof(FPresetMixerMapData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPresetMixerMapData;
UScriptStruct* Z_Construct_UScriptStruct_FPresetMixerMapData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FPresetMixerMapData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FPresetMixerMapData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPresetMixerMapData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("PresetMixerMapData"));
		}
		return Z_Registration_Info_UScriptStruct_FPresetMixerMapData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FPresetMixerMapData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPresetMixerMapData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPresetMixerMapData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FPresetMixerMapData *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODPresetData_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FODPresetData, Z_Construct_UScriptStruct_FODPresetData_Statics::NewStructOps, TEXT("ODPresetData"),&Z_Registration_Info_UScriptStruct_FODPresetData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FODPresetData), 1119849142U) },
		{ Z_Construct_UScriptStruct_FPresetMixerMapData, Z_Construct_UScriptStruct_FPresetMixerMapData_Statics::NewStructOps, TEXT("PresetMixerMapData"),&Z_Registration_Info_UScriptStruct_FPresetMixerMapData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPresetMixerMapData), 1562164544U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODPresetData_h__Script_ObjectDistribution_539bf195e4c602a0b171840ad684995afcbfb0d4{
	TEXT("/Script/ObjectDistribution"),
	nullptr, 0,
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
