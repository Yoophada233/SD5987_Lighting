// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBDataStructs.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBDataStructs() {}

// ********** Begin Cross Module References ********************************************************
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FDuplicationData(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FDuplicationFilters(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBAxis(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FDuplicationData **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDuplicationData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDuplicationData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDuplicationData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/MBDataStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DupAxis_MetaData[] = {
		{ "Category", "ModularDuplication" },
		{ "ModuleRelativePath", "Public/Data/MBDataStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumOfDup_MetaData[] = {
		{ "Category", "ModularDuplication" },
		{ "ModuleRelativePath", "Public/Data/MBDataStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "Category", "ModularDuplication" },
		{ "ModuleRelativePath", "Public/Data/MBDataStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDirection_MetaData[] = {
		{ "Category", "ModularDuplication" },
		{ "ModuleRelativePath", "Public/Data/MBDataStructs.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDuplicationData constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_DupAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DupAxis;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumOfDup;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Offset;
	static void NewProp_bDirection_SetBit(void* Obj)
	{
		((FDuplicationData*)Obj)->bDirection = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDirection;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDuplicationData constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDuplicationData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDuplicationData Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_DupAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_DupAxis = { "DupAxis", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FDuplicationData, DupAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DupAxis_MetaData), NewProp_DupAxis_MetaData) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NumOfDup = { "NumOfDup", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDuplicationData, NumOfDup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumOfDup_MetaData), NewProp_NumOfDup_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDuplicationData, Offset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDirection = { "bDirection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDuplicationData), &UHT_STATICS::NewProp_bDirection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDirection_MetaData), NewProp_bDirection_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DupAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DupAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NumOfDup,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDirection,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDuplicationData Property Definitions *******************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	&NewStructOps,
	"DuplicationData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDuplicationData>(),
	alignof(FDuplicationData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDuplicationData;
UScriptStruct* Z_Construct_UScriptStruct_FDuplicationData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDuplicationData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDuplicationData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDuplicationData, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("DuplicationData"));
		}
		return Z_Registration_Info_UScriptStruct_FDuplicationData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDuplicationData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDuplicationData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDuplicationData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDuplicationData ****************************************************

// ********** Begin ScriptStruct FDuplicationFilters ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDuplicationFilters_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDuplicationFilters>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDuplicationFilters); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/MBDataStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hole_MetaData[] = {
		{ "Category", "ModularDuplication" },
		{ "ModuleRelativePath", "Public/Data/MBDataStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rectangle_MetaData[] = {
		{ "Category", "ModularDuplication" },
		{ "ModuleRelativePath", "Public/Data/MBDataStructs.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDuplicationFilters constinit property declarations ***************
	static void NewProp_Hole_SetBit(void* Obj)
	{
		((FDuplicationFilters*)Obj)->Hole = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Hole;
	static void NewProp_Rectangle_SetBit(void* Obj)
	{
		((FDuplicationFilters*)Obj)->Rectangle = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Rectangle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDuplicationFilters constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDuplicationFilters>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDuplicationFilters Property Definitions **************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Hole = { "Hole", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDuplicationFilters), &UHT_STATICS::NewProp_Hole_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hole_MetaData), NewProp_Hole_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Rectangle = { "Rectangle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDuplicationFilters), &UHT_STATICS::NewProp_Rectangle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rectangle_MetaData), NewProp_Rectangle_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Hole,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rectangle,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDuplicationFilters Property Definitions ****************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	&NewStructOps,
	"DuplicationFilters",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDuplicationFilters>(),
	alignof(FDuplicationFilters),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDuplicationFilters;
UScriptStruct* Z_Construct_UScriptStruct_FDuplicationFilters(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDuplicationFilters.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDuplicationFilters.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDuplicationFilters, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("DuplicationFilters"));
		}
		return Z_Registration_Info_UScriptStruct_FDuplicationFilters.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDuplicationFilters.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDuplicationFilters.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDuplicationFilters.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDuplicationFilters *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBDataStructs_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDuplicationData, Z_Construct_UScriptStruct_FDuplicationData_Statics::NewStructOps, TEXT("DuplicationData"),&Z_Registration_Info_UScriptStruct_FDuplicationData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDuplicationData), 1650473601U) },
		{ Z_Construct_UScriptStruct_FDuplicationFilters, Z_Construct_UScriptStruct_FDuplicationFilters_Statics::NewStructOps, TEXT("DuplicationFilters"),&Z_Registration_Info_UScriptStruct_FDuplicationFilters, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDuplicationFilters), 667160227U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBDataStructs_h__Script_ModularBuilding_e62e82291698e2f2d9519c7bfb1fbc7b2a5a3ae5{
	TEXT("/Script/ModularBuilding"),
	nullptr, 0,
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
