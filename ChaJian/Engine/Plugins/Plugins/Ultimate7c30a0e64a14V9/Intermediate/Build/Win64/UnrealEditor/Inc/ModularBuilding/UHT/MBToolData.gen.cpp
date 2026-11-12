// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBToolData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBToolData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UDataAsset(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EBuildingCategory(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBModularSnapType(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FMBModBuildingSettingsData(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FMBPropBuildingSettingsData(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBToolData(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBToolData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FMBModBuildingSettingsData ****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FMBModBuildingSettingsData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FMBModBuildingSettingsData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FMBModBuildingSettingsData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableModularSnapping_MetaData[] = {
		{ "Category", "Modular Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSnapOffsetCond_MetaData[] = {
		{ "Category", "Modular Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SnapOffset_MetaData[] = {
		{ "Category", "Modular Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bZOffsetCond_MetaData[] = {
		{ "Category", "Modular Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZOffset_MetaData[] = {
		{ "Category", "Modular Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SnappingType_MetaData[] = {
		{ "Category", "Modular Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoundCorrectionSensitivity_MetaData[] = {
		{ "Category", "Modular Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FMBModBuildingSettingsData constinit property declarations ********
	static void NewProp_bEnableModularSnapping_SetBit(void* Obj)
	{
		((FMBModBuildingSettingsData*)Obj)->bEnableModularSnapping = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableModularSnapping;
	static void NewProp_bSnapOffsetCond_SetBit(void* Obj)
	{
		((FMBModBuildingSettingsData*)Obj)->bSnapOffsetCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSnapOffsetCond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SnapOffset;
	static void NewProp_bZOffsetCond_SetBit(void* Obj)
	{
		((FMBModBuildingSettingsData*)Obj)->bZOffsetCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bZOffsetCond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ZOffset;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SnappingType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SnappingType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BoundCorrectionSensitivity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FMBModBuildingSettingsData constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMBModBuildingSettingsData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FMBModBuildingSettingsData Property Definitions *******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableModularSnapping = { "bEnableModularSnapping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FMBModBuildingSettingsData), &UHT_STATICS::NewProp_bEnableModularSnapping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableModularSnapping_MetaData), NewProp_bEnableModularSnapping_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSnapOffsetCond = { "bSnapOffsetCond", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FMBModBuildingSettingsData), &UHT_STATICS::NewProp_bSnapOffsetCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSnapOffsetCond_MetaData), NewProp_bSnapOffsetCond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SnapOffset = { "SnapOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FMBModBuildingSettingsData, SnapOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SnapOffset_MetaData), NewProp_SnapOffset_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bZOffsetCond = { "bZOffsetCond", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FMBModBuildingSettingsData), &UHT_STATICS::NewProp_bZOffsetCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bZOffsetCond_MetaData), NewProp_bZOffsetCond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ZOffset = { "ZOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FMBModBuildingSettingsData, ZOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZOffset_MetaData), NewProp_ZOffset_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_SnappingType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_SnappingType = { "SnappingType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FMBModBuildingSettingsData, SnappingType), Z_Construct_UEnum_ModularBuilding_EMBModularSnapType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SnappingType_MetaData), NewProp_SnappingType_MetaData) }; // cad1894023e8a4bfb7781085b322ae5283e0e3a6
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BoundCorrectionSensitivity = { "BoundCorrectionSensitivity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FMBModBuildingSettingsData, BoundCorrectionSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundCorrectionSensitivity_MetaData), NewProp_BoundCorrectionSensitivity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableModularSnapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSnapOffsetCond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SnapOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bZOffsetCond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ZOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SnappingType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SnappingType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BoundCorrectionSensitivity,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FMBModBuildingSettingsData Property Definitions *********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	&NewStructOps,
	"MBModBuildingSettingsData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FMBModBuildingSettingsData>(),
	alignof(FMBModBuildingSettingsData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMBModBuildingSettingsData;
UScriptStruct* Z_Construct_UScriptStruct_FMBModBuildingSettingsData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FMBModBuildingSettingsData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FMBModBuildingSettingsData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMBModBuildingSettingsData, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("MBModBuildingSettingsData"));
		}
		return Z_Registration_Info_UScriptStruct_FMBModBuildingSettingsData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FMBModBuildingSettingsData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMBModBuildingSettingsData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FMBModBuildingSettingsData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FMBModBuildingSettingsData ******************************************

// ********** Begin ScriptStruct FMBPropBuildingSettingsData ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FMBPropBuildingSettingsData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FMBPropBuildingSettingsData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FMBPropBuildingSettingsData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableSurfaceSnapping_MetaData[] = {
		{ "Category", "Prop Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCustomRotationRateCond_MetaData[] = {
		{ "Category", "Prop Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomRotationRate_MetaData[] = {
		{ "Category", "Prop Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bScaleRateCond_MetaData[] = {
		{ "Category", "Prop Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleRate_MetaData[] = {
		{ "Category", "Prop Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bZOffsetCond_MetaData[] = {
		{ "Category", "Prop Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZOffset_MetaData[] = {
		{ "Category", "Prop Building" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FMBPropBuildingSettingsData constinit property declarations *******
	static void NewProp_bEnableSurfaceSnapping_SetBit(void* Obj)
	{
		((FMBPropBuildingSettingsData*)Obj)->bEnableSurfaceSnapping = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableSurfaceSnapping;
	static void NewProp_bCustomRotationRateCond_SetBit(void* Obj)
	{
		((FMBPropBuildingSettingsData*)Obj)->bCustomRotationRateCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCustomRotationRateCond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CustomRotationRate;
	static void NewProp_bScaleRateCond_SetBit(void* Obj)
	{
		((FMBPropBuildingSettingsData*)Obj)->bScaleRateCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bScaleRateCond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleRate;
	static void NewProp_bZOffsetCond_SetBit(void* Obj)
	{
		((FMBPropBuildingSettingsData*)Obj)->bZOffsetCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bZOffsetCond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ZOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FMBPropBuildingSettingsData constinit property declarations *********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMBPropBuildingSettingsData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FMBPropBuildingSettingsData Property Definitions ******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableSurfaceSnapping = { "bEnableSurfaceSnapping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FMBPropBuildingSettingsData), &UHT_STATICS::NewProp_bEnableSurfaceSnapping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableSurfaceSnapping_MetaData), NewProp_bEnableSurfaceSnapping_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCustomRotationRateCond = { "bCustomRotationRateCond", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FMBPropBuildingSettingsData), &UHT_STATICS::NewProp_bCustomRotationRateCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCustomRotationRateCond_MetaData), NewProp_bCustomRotationRateCond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CustomRotationRate = { "CustomRotationRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FMBPropBuildingSettingsData, CustomRotationRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomRotationRate_MetaData), NewProp_CustomRotationRate_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bScaleRateCond = { "bScaleRateCond", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FMBPropBuildingSettingsData), &UHT_STATICS::NewProp_bScaleRateCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bScaleRateCond_MetaData), NewProp_bScaleRateCond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ScaleRate = { "ScaleRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FMBPropBuildingSettingsData, ScaleRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleRate_MetaData), NewProp_ScaleRate_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bZOffsetCond = { "bZOffsetCond", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FMBPropBuildingSettingsData), &UHT_STATICS::NewProp_bZOffsetCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bZOffsetCond_MetaData), NewProp_bZOffsetCond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ZOffset = { "ZOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FMBPropBuildingSettingsData, ZOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZOffset_MetaData), NewProp_ZOffset_MetaData) };
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
// ********** End ScriptStruct FMBPropBuildingSettingsData Property Definitions ********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	&NewStructOps,
	"MBPropBuildingSettingsData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FMBPropBuildingSettingsData>(),
	alignof(FMBPropBuildingSettingsData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMBPropBuildingSettingsData;
UScriptStruct* Z_Construct_UScriptStruct_FMBPropBuildingSettingsData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FMBPropBuildingSettingsData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FMBPropBuildingSettingsData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMBPropBuildingSettingsData, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("MBPropBuildingSettingsData"));
		}
		return Z_Registration_Info_UScriptStruct_FMBPropBuildingSettingsData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FMBPropBuildingSettingsData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMBPropBuildingSettingsData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FMBPropBuildingSettingsData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FMBPropBuildingSettingsData *****************************************

// ********** Begin Class UMBToolData **************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBToolData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/MBToolData.h" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModularMeshTypes_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropMeshTypes_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Collections_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastActiveBuildingCategory_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuildingSettingsData_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropBuildingSettingsData_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Data/MBToolData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBToolData constinit property declarations ******************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ModularMeshTypes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ModularMeshTypes;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropMeshTypes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PropMeshTypes;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Collections_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Collections;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LastActiveBuildingCategory_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LastActiveBuildingCategory;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BuildingSettingsData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PropBuildingSettingsData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBToolData constinit property declarations ********************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBToolData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBToolData Property Definitions *****************************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_ModularMeshTypes_Inner = { "ModularMeshTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ModularMeshTypes = { "ModularMeshTypes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolData, ModularMeshTypes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModularMeshTypes_MetaData), NewProp_ModularMeshTypes_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_PropMeshTypes_Inner = { "PropMeshTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_PropMeshTypes = { "PropMeshTypes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolData, PropMeshTypes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropMeshTypes_MetaData), NewProp_PropMeshTypes_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_Collections_Inner = { "Collections", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Collections = { "Collections", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolData, Collections), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Collections_MetaData), NewProp_Collections_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_LastActiveBuildingCategory_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_LastActiveBuildingCategory = { "LastActiveBuildingCategory", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolData, LastActiveBuildingCategory), Z_Construct_UEnum_ModularBuilding_EBuildingCategory, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastActiveBuildingCategory_MetaData), NewProp_LastActiveBuildingCategory_MetaData) }; // 07cf8117a6e577cac6ce1c747d6b11cc85196fdc
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_BuildingSettingsData = { "BuildingSettingsData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolData, BuildingSettingsData), Z_Construct_UScriptStruct_FMBModBuildingSettingsData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuildingSettingsData_MetaData), NewProp_BuildingSettingsData_MetaData) }; // e36d1b54a0e44c1362a8dbed01ba82fea0db3c56
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PropBuildingSettingsData = { "PropBuildingSettingsData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolData, PropBuildingSettingsData), Z_Construct_UScriptStruct_FMBPropBuildingSettingsData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropBuildingSettingsData_MetaData), NewProp_PropBuildingSettingsData_MetaData) }; // dee9bf9f73574e3cc72d5df4527d7e1dcaf00775
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ModularMeshTypes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ModularMeshTypes,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PropMeshTypes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PropMeshTypes,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Collections_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Collections,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastActiveBuildingCategory_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastActiveBuildingCategory,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BuildingSettingsData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PropBuildingSettingsData,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBToolData Property Definitions *******************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UDataAsset,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBToolData,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UMBToolData;
UClass* Z_Construct_UClass_UMBToolData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBToolData;
		if (!Z_Registration_Info_UClass_UMBToolData.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBToolData"),
				Z_Registration_Info_UClass_UMBToolData.InnerSingleton,
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
		return Z_Registration_Info_UClass_UMBToolData.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBToolData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBToolData.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBToolData.OuterSingleton;
}
#undef UHT_STATICS
UMBToolData::UMBToolData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBToolData);
UMBToolData::~UMBToolData() {}
// ********** End Class UMBToolData ****************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBToolData_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FMBModBuildingSettingsData, Z_Construct_UScriptStruct_FMBModBuildingSettingsData_Statics::NewStructOps, TEXT("MBModBuildingSettingsData"),&Z_Registration_Info_UScriptStruct_FMBModBuildingSettingsData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMBModBuildingSettingsData), 3815578452U) },
		{ Z_Construct_UScriptStruct_FMBPropBuildingSettingsData, Z_Construct_UScriptStruct_FMBPropBuildingSettingsData_Statics::NewStructOps, TEXT("MBPropBuildingSettingsData"),&Z_Registration_Info_UScriptStruct_FMBPropBuildingSettingsData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMBPropBuildingSettingsData), 3739860895U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBToolData, TEXT("UMBToolData"), &Z_Registration_Info_UClass_UMBToolData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBToolData), 3052309991U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBToolData_h__Script_ModularBuilding_ca87638dd20e67c6c32cc4e4b6a558270bc1889a{
	TEXT("/Script/ModularBuilding"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
