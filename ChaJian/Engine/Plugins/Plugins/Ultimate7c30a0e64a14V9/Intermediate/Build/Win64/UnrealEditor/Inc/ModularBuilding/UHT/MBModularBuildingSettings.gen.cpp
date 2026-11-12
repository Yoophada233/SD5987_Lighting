// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBModularBuildingSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBModularBuildingSettings() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
SCRIPTABLEEDITORWIDGETS_API UClass* Z_Construct_UClass_UDetailsView(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBModularBuildingSettings(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBMBuildingSettingsObj(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBModularBuildingSettings(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBModularBuildingSettings Function OnPlacementTypeChanged ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularBuildingSettings_OnPlacementTypeChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularBuildingSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnPlacementTypeChanged constinit property declarations ****************
// ********** End Function OnPlacementTypeChanged constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularBuildingSettings, nullptr, "OnPlacementTypeChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBModularBuildingSettings_OnPlacementTypeChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularBuildingSettings::execOnPlacementTypeChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPlacementTypeChanged();
	P_NATIVE_END;
}
// ********** End Class UMBModularBuildingSettings Function OnPlacementTypeChanged *****************

// ********** Begin Class UMBModularBuildingSettings Function PlacementTypeBtnPressed **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularBuildingSettings_PlacementTypeBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularBuildingSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function PlacementTypeBtnPressed constinit property declarations ***************
// ********** End Function PlacementTypeBtnPressed constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularBuildingSettings, nullptr, "PlacementTypeBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBModularBuildingSettings_PlacementTypeBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularBuildingSettings::execPlacementTypeBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlacementTypeBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMBModularBuildingSettings Function PlacementTypeBtnPressed ****************

// ********** Begin Class UMBModularBuildingSettings ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBModularBuildingSettings_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/MBModularBuildingSettings.h" },
		{ "ModuleRelativePath", "Public/UI/MBModularBuildingSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuildingSettingsObj_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularBuildingSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlacementTypeBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularBuildingSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlacementTypeText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularBuildingSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MBDetails_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularBuildingSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBModularBuildingSettings constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BuildingSettingsObj;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlacementTypeBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlacementTypeText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MBDetails;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBModularBuildingSettings constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnPlacementTypeChanged"), .Pointer = &UMBModularBuildingSettings::execOnPlacementTypeChanged },
		{ .NameUTF8 = UTF8TEXT("PlacementTypeBtnPressed"), .Pointer = &UMBModularBuildingSettings::execPlacementTypeBtnPressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBModularBuildingSettings_OnPlacementTypeChanged, "OnPlacementTypeChanged" }, // 179b2016d3a664cad0e7b9b499c6174b1a4553f2
		{ &Z_Construct_UFunction_UMBModularBuildingSettings_PlacementTypeBtnPressed, "PlacementTypeBtnPressed" }, // 8f454ee101f82bca963366121308f624410a8864
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBModularBuildingSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBModularBuildingSettings Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BuildingSettingsObj = { "BuildingSettingsObj", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularBuildingSettings, BuildingSettingsObj), Z_Construct_UClass_UMBMBuildingSettingsObj, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuildingSettingsObj_MetaData), NewProp_BuildingSettingsObj_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlacementTypeBtn = { "PlacementTypeBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularBuildingSettings, PlacementTypeBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlacementTypeBtn_MetaData), NewProp_PlacementTypeBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlacementTypeText = { "PlacementTypeText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularBuildingSettings, PlacementTypeText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlacementTypeText_MetaData), NewProp_PlacementTypeText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MBDetails = { "MBDetails", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularBuildingSettings, MBDetails), Z_Construct_UClass_UDetailsView, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MBDetails_MetaData), NewProp_MBDetails_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BuildingSettingsObj,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlacementTypeBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlacementTypeText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MBDetails,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBModularBuildingSettings Property Definitions ****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBModularBuildingSettings,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UMBModularBuildingSettings_StaticRegisterNativesUMBModularBuildingSettings()
{
	UClass* Class = UMBModularBuildingSettings::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBModularBuildingSettings;
UClass* Z_Construct_UClass_UMBModularBuildingSettings(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBModularBuildingSettings;
		if (!Z_Registration_Info_UClass_UMBModularBuildingSettings.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBModularBuildingSettings"),
				Z_Registration_Info_UClass_UMBModularBuildingSettings.InnerSingleton,
				UMBModularBuildingSettings_StaticRegisterNativesUMBModularBuildingSettings,
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
		return Z_Registration_Info_UClass_UMBModularBuildingSettings.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBModularBuildingSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBModularBuildingSettings.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBModularBuildingSettings.OuterSingleton;
}
#undef UHT_STATICS
UMBModularBuildingSettings::UMBModularBuildingSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBModularBuildingSettings);
UMBModularBuildingSettings::~UMBModularBuildingSettings() {}
// ********** End Class UMBModularBuildingSettings *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBModularBuildingSettings_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBModularBuildingSettings, TEXT("UMBModularBuildingSettings"), &Z_Registration_Info_UClass_UMBModularBuildingSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBModularBuildingSettings), 1780082344U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBModularBuildingSettings_h__Script_ModularBuilding_e7b7d41e1779c813ebf83c0b481f33b4299d5a6e{
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
