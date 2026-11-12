// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBUserSettingsObject.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBUserSettingsObject() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBUserSettingsObject(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBUserSettingsObject(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBUserSettingsObject ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBUserSettingsObject_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Data/MBUserSettingsObject.h" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectTracingDistance_MetaData[] = {
		{ "Category", "Placement" },
		{ "ClampMax", "100000.000000" },
		{ "ClampMin", "5000.000000" },
		{ "DisplayName", "Object Tracing Distance" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
		{ "ShowOnlyInnerProperties", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FreePlacementDistance_MetaData[] = {
		{ "Category", "Placement" },
		{ "ClampMax", "50000.000000" },
		{ "ClampMin", "500.000000" },
		{ "DisplayName", "Free Placement Distance" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
		{ "ShowOnlyInnerProperties", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UsePreviewShader_MetaData[] = {
		{ "Category", "Debugging" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaceableColor_MetaData[] = {
		{ "Category", "Debugging" },
		{ "DisplayName", "Mesh Placeable Color" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
		{ "ShowOnlyInnerProperties", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NotPlaceableColor_MetaData[] = {
		{ "Category", "Modular Placement" },
		{ "DisplayName", "Mesh Not Placeable Color" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
		{ "ShowOnlyInnerProperties", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplaceableColor_MetaData[] = {
		{ "Category", "Debugging" },
		{ "DisplayName", "Mesh Replaceable Color" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
		{ "ShowOnlyInnerProperties", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnableDirectionDebugger_MetaData[] = {
		{ "Category", "Debugging" },
		{ "DisplayName", "Enable Direction Debugger" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
		{ "ShowOnlyInnerProperties", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DirectionDebugColor_MetaData[] = {
		{ "Category", "Debugging" },
		{ "DisplayName", "Direction Debug Color" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugThickness_MetaData[] = {
		{ "Category", "Debugging" },
		{ "ClampMax", "50.000000" },
		{ "ClampMin", "0.100000" },
		{ "DisplayName", "Debug Thickness" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
		{ "ShowOnlyInnerProperties", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetSelectionColor_MetaData[] = {
		{ "Category", "User Interface" },
		{ "DisplayName", "Asset Selection Color" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollectionSelectionColor_MetaData[] = {
		{ "Category", "User Interface" },
		{ "DisplayName", "Collection Selection Color" },
		{ "ModuleRelativePath", "Public/Data/MBUserSettingsObject.h" },
		{ "NoResetToDefault", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBUserSettingsObject constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ObjectTracingDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FreePlacementDistance;
	static void NewProp_UsePreviewShader_SetBit(void* Obj)
	{
		((UMBUserSettingsObject*)Obj)->UsePreviewShader = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_UsePreviewShader;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlaceableColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NotPlaceableColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReplaceableColor;
	static void NewProp_EnableDirectionDebugger_SetBit(void* Obj)
	{
		((UMBUserSettingsObject*)Obj)->EnableDirectionDebugger = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_EnableDirectionDebugger;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DirectionDebugColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DebugThickness;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AssetSelectionColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CollectionSelectionColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBUserSettingsObject constinit property declarations **********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBUserSettingsObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBUserSettingsObject Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ObjectTracingDistance = { "ObjectTracingDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsObject, ObjectTracingDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectTracingDistance_MetaData), NewProp_ObjectTracingDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FreePlacementDistance = { "FreePlacementDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsObject, FreePlacementDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FreePlacementDistance_MetaData), NewProp_FreePlacementDistance_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_UsePreviewShader = { "UsePreviewShader", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBUserSettingsObject), &UHT_STATICS::NewProp_UsePreviewShader_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UsePreviewShader_MetaData), NewProp_UsePreviewShader_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PlaceableColor = { "PlaceableColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsObject, PlaceableColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaceableColor_MetaData), NewProp_PlaceableColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NotPlaceableColor = { "NotPlaceableColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsObject, NotPlaceableColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NotPlaceableColor_MetaData), NewProp_NotPlaceableColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReplaceableColor = { "ReplaceableColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsObject, ReplaceableColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplaceableColor_MetaData), NewProp_ReplaceableColor_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_EnableDirectionDebugger = { "EnableDirectionDebugger", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBUserSettingsObject), &UHT_STATICS::NewProp_EnableDirectionDebugger_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnableDirectionDebugger_MetaData), NewProp_EnableDirectionDebugger_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DirectionDebugColor = { "DirectionDebugColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsObject, DirectionDebugColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DirectionDebugColor_MetaData), NewProp_DirectionDebugColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DebugThickness = { "DebugThickness", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsObject, DebugThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugThickness_MetaData), NewProp_DebugThickness_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_AssetSelectionColor = { "AssetSelectionColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsObject, AssetSelectionColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetSelectionColor_MetaData), NewProp_AssetSelectionColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_CollectionSelectionColor = { "CollectionSelectionColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsObject, CollectionSelectionColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollectionSelectionColor_MetaData), NewProp_CollectionSelectionColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ObjectTracingDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FreePlacementDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UsePreviewShader,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlaceableColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NotPlaceableColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplaceableColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnableDirectionDebugger,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DirectionDebugColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DebugThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AssetSelectionColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CollectionSelectionColor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBUserSettingsObject Property Definitions *********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UObject,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBUserSettingsObject,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UMBUserSettingsObject;
UClass* Z_Construct_UClass_UMBUserSettingsObject(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBUserSettingsObject;
		if (!Z_Registration_Info_UClass_UMBUserSettingsObject.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBUserSettingsObject"),
				Z_Registration_Info_UClass_UMBUserSettingsObject.InnerSingleton,
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
		return Z_Registration_Info_UClass_UMBUserSettingsObject.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBUserSettingsObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBUserSettingsObject.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBUserSettingsObject.OuterSingleton;
}
#undef UHT_STATICS
UMBUserSettingsObject::UMBUserSettingsObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBUserSettingsObject);
UMBUserSettingsObject::~UMBUserSettingsObject() {}
// ********** End Class UMBUserSettingsObject ******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBUserSettingsObject_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBUserSettingsObject, TEXT("UMBUserSettingsObject"), &Z_Registration_Info_UClass_UMBUserSettingsObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBUserSettingsObject), 1638932228U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBUserSettingsObject_h__Script_ModularBuilding_3724e00c66363ee3a8a9a4905d5df3152fb88f4c{
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
