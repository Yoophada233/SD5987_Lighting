// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODToolSubsystem.h"
#include "ODMeshData.h"
#include "ODPresetData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODToolSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UDataTable(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FDistObjectData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODToolSubsystem(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FPresetMixerMapData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODSettingsObject(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODToolSettings(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODToolSubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODToolSubsystem *********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODToolSubsystem_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Data/ODToolSubsystem.h" },
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ODToolSettings_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetColorMap_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SettingsObject_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetMixerMapData_MetaData[] = {
		{ "Comment", "//This data updated automatically when a preset checked or unchecked\n" },
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
		{ "ToolTip", "This data updated automatically when a preset checked or unchecked" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CreatedDistObjects_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectDataMap_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectDistributionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialRelativeLocations_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialRelativeRotations_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedPaletteSlotIndexes_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastSelectIndex_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialTotal_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DensityMap_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODToolSubsystem constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ODToolSettings;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PresetData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PresetColorMap_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PresetColorMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PresetColorMap;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SettingsObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PresetMixerMapData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PresetMixerMapData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CreatedDistObjects_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CreatedDistObjects;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectDataMap_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ObjectDataMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ObjectDataMap;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectDistributionData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ObjectDistributionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InitialRelativeLocations_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InitialRelativeLocations;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InitialRelativeRotations_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InitialRelativeRotations;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SelectedPaletteSlotIndexes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SelectedPaletteSlotIndexes;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LastSelectIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InitialTotal;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DensityMap_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DensityMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_DensityMap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODToolSubsystem constinit property declarations ***************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODToolSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODToolSubsystem Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ODToolSettings = { "ODToolSettings", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, ODToolSettings), Z_Construct_UClass_UODToolSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ODToolSettings_MetaData), NewProp_ODToolSettings_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PresetData = { "PresetData", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, PresetData), Z_Construct_UClass_UDataTable, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetData_MetaData), NewProp_PresetData_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PresetColorMap_ValueProp = { "PresetColorMap", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_PresetColorMap_Key_KeyProp = { "PresetColorMap_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams UHT_STATICS::NewProp_PresetColorMap = { "PresetColorMap", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, PresetColorMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetColorMap_MetaData), NewProp_PresetColorMap_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SettingsObject = { "SettingsObject", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, SettingsObject), Z_Construct_UClass_UODSettingsObject, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SettingsObject_MetaData), NewProp_SettingsObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PresetMixerMapData_Inner = { "PresetMixerMapData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPresetMixerMapData, METADATA_PARAMS(0, nullptr) }; // 5d1cbd404df57a8e7b689066653d2391f21a2678
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_PresetMixerMapData = { "PresetMixerMapData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, PresetMixerMapData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetMixerMapData_MetaData), NewProp_PresetMixerMapData_MetaData) }; // 5d1cbd404df57a8e7b689066653d2391f21a2678
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CreatedDistObjects_Inner = { "CreatedDistObjects", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_AStaticMeshActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_CreatedDistObjects = { "CreatedDistObjects", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, CreatedDistObjects), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CreatedDistObjects_MetaData), NewProp_CreatedDistObjects_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ObjectDataMap_ValueProp = { "ObjectDataMap", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FDistObjectData, METADATA_PARAMS(0, nullptr) }; // 51fcd38d1b5761471938c94c04fa1ed2d7d2df34
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ObjectDataMap_Key_KeyProp = { "ObjectDataMap_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams UHT_STATICS::NewProp_ObjectDataMap = { "ObjectDataMap", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, ObjectDataMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectDataMap_MetaData), NewProp_ObjectDataMap_MetaData) }; // 51fcd38d1b5761471938c94c04fa1ed2d7d2df34
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ObjectDistributionData_Inner = { "ObjectDistributionData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDistObjectData, METADATA_PARAMS(0, nullptr) }; // 51fcd38d1b5761471938c94c04fa1ed2d7d2df34
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ObjectDistributionData = { "ObjectDistributionData", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, ObjectDistributionData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectDistributionData_MetaData), NewProp_ObjectDistributionData_MetaData) }; // 51fcd38d1b5761471938c94c04fa1ed2d7d2df34
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InitialRelativeLocations_Inner = { "InitialRelativeLocations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_InitialRelativeLocations = { "InitialRelativeLocations", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, InitialRelativeLocations), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialRelativeLocations_MetaData), NewProp_InitialRelativeLocations_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InitialRelativeRotations_Inner = { "InitialRelativeRotations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_InitialRelativeRotations = { "InitialRelativeRotations", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, InitialRelativeRotations), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialRelativeRotations_MetaData), NewProp_InitialRelativeRotations_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SelectedPaletteSlotIndexes_Inner = { "SelectedPaletteSlotIndexes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_SelectedPaletteSlotIndexes = { "SelectedPaletteSlotIndexes", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, SelectedPaletteSlotIndexes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedPaletteSlotIndexes_MetaData), NewProp_SelectedPaletteSlotIndexes_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_LastSelectIndex = { "LastSelectIndex", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, LastSelectIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastSelectIndex_MetaData), NewProp_LastSelectIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_InitialTotal = { "InitialTotal", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, InitialTotal), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialTotal_MetaData), NewProp_InitialTotal_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DensityMap_ValueProp = { "DensityMap", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DensityMap_Key_KeyProp = { "DensityMap_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams UHT_STATICS::NewProp_DensityMap = { "DensityMap", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSubsystem, DensityMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DensityMap_MetaData), NewProp_DensityMap_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ODToolSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetColorMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetColorMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetColorMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SettingsObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetMixerMapData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetMixerMapData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CreatedDistObjects_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CreatedDistObjects,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ObjectDataMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ObjectDataMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ObjectDataMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ObjectDistributionData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ObjectDistributionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InitialRelativeLocations_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InitialRelativeLocations,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InitialRelativeRotations_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InitialRelativeRotations,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedPaletteSlotIndexes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedPaletteSlotIndexes,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastSelectIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InitialTotal,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DensityMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DensityMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DensityMap,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODToolSubsystem Property Definitions **************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UEditorSubsystem,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODToolSubsystem,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UODToolSubsystem;
UClass* Z_Construct_UClass_UODToolSubsystem(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODToolSubsystem;
		if (!Z_Registration_Info_UClass_UODToolSubsystem.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODToolSubsystem"),
				Z_Registration_Info_UClass_UODToolSubsystem.InnerSingleton,
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
		return Z_Registration_Info_UClass_UODToolSubsystem.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODToolSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODToolSubsystem.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODToolSubsystem.OuterSingleton;
}
#undef UHT_STATICS
UODToolSubsystem::UODToolSubsystem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODToolSubsystem);
UODToolSubsystem::~UODToolSubsystem() {}
// ********** End Class UODToolSubsystem ***********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODToolSubsystem_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODToolSubsystem, TEXT("UODToolSubsystem"), &Z_Registration_Info_UClass_UODToolSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODToolSubsystem), 4106058306U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODToolSubsystem_h__Script_ObjectDistribution_40ef18e1b3665f7478a4c33996e247371902dedd{
	TEXT("/Script/ObjectDistribution"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
