// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBModularAssetData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBModularAssetData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EBuildingCategory(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FModularBuildingAssetData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FModularBuildingAssetData *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FModularBuildingAssetData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FModularBuildingAssetData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModularBuildingAssetData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/MBModularAssetData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshType_MetaData[] = {
		{ "Category", "ToolAsset" },
		{ "ModuleRelativePath", "Public/Data/MBModularAssetData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshCategory_MetaData[] = {
		{ "Category", "ToolAsset" },
		{ "ModuleRelativePath", "Public/Data/MBModularAssetData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetReference_MetaData[] = {
		{ "Category", "ToolAsset" },
		{ "ModuleRelativePath", "Public/Data/MBModularAssetData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModularBuildingAssetData constinit property declarations *********
	static const UECodeGen_Private::FNamePropertyParams NewProp_MeshType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MeshCategory_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MeshCategory;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_AssetReference;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModularBuildingAssetData constinit property declarations ***********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModularBuildingAssetData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS
static_assert(std::is_polymorphic<FModularBuildingAssetData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FModularBuildingAssetData cannot be polymorphic unless super FTableRowBase is polymorphic");

// ********** Begin ScriptStruct FModularBuildingAssetData Property Definitions ********************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_MeshType = { "MeshType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(FModularBuildingAssetData, MeshType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshType_MetaData), NewProp_MeshType_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_MeshCategory_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_MeshCategory = { "MeshCategory", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FModularBuildingAssetData, MeshCategory), Z_Construct_UEnum_ModularBuilding_EBuildingCategory, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshCategory_MetaData), NewProp_MeshCategory_MetaData) }; // 07cf8117a6e577cac6ce1c747d6b11cc85196fdc
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_AssetReference = { "AssetReference", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FModularBuildingAssetData, AssetReference), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetReference_MetaData), NewProp_AssetReference_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MeshType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MeshCategory_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MeshCategory,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AssetReference,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FModularBuildingAssetData Property Definitions **********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"ModularBuildingAssetData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FModularBuildingAssetData>(),
	alignof(FModularBuildingAssetData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModularBuildingAssetData;
UScriptStruct* Z_Construct_UScriptStruct_FModularBuildingAssetData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FModularBuildingAssetData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FModularBuildingAssetData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModularBuildingAssetData, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("ModularBuildingAssetData"));
		}
		return Z_Registration_Info_UScriptStruct_FModularBuildingAssetData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FModularBuildingAssetData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModularBuildingAssetData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModularBuildingAssetData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FModularBuildingAssetData *******************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBModularAssetData_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FModularBuildingAssetData, Z_Construct_UScriptStruct_FModularBuildingAssetData_Statics::NewStructOps, TEXT("ModularBuildingAssetData"),&Z_Registration_Info_UScriptStruct_FModularBuildingAssetData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModularBuildingAssetData), 4051815140U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBModularAssetData_h__Script_ModularBuilding_a9817ec9dfb2383ebdbc6b53af77b28f2f5d0687{
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
