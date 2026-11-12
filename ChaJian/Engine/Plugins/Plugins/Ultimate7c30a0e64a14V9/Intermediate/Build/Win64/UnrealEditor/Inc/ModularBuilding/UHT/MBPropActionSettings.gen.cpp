// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBPropActionSettings.h"
#include "MBModularEnum.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBPropActionSettings() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
SCRIPTABLEEDITORWIDGETS_API UClass* Z_Construct_UClass_UDetailsView(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FDistributionBaseData(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBPropActionSettings(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBPropActionSettings(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBPropDistributionBase(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBPropActionSettings ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBPropActionSettings_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/MBPropActionSettings.h" },
		{ "ModuleRelativePath", "Public/UI/MBPropActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropDistributionDetails_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Prop Distribution" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBPropActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropDistributionBase_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBPropActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistributionBaseData_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBPropActionSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBPropActionSettings constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PropDistributionDetails;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PropDistributionBase;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DistributionBaseData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBPropActionSettings constinit property declarations **********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBPropActionSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBPropActionSettings Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PropDistributionDetails = { "PropDistributionDetails", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPropActionSettings, PropDistributionDetails), Z_Construct_UClass_UDetailsView, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropDistributionDetails_MetaData), NewProp_PropDistributionDetails_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PropDistributionBase = { "PropDistributionBase", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPropActionSettings, PropDistributionBase), Z_Construct_UClass_UMBPropDistributionBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropDistributionBase_MetaData), NewProp_PropDistributionBase_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DistributionBaseData = { "DistributionBaseData", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPropActionSettings, DistributionBaseData), Z_Construct_UScriptStruct_FDistributionBaseData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistributionBaseData_MetaData), NewProp_DistributionBaseData_MetaData) }; // 84f7872f91c93322fa3c614048935f6565bfd90b
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PropDistributionDetails,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PropDistributionBase,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistributionBaseData,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBPropActionSettings Property Definitions *********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBPropActionSettings,
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
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UMBPropActionSettings;
UClass* Z_Construct_UClass_UMBPropActionSettings(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBPropActionSettings;
		if (!Z_Registration_Info_UClass_UMBPropActionSettings.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBPropActionSettings"),
				Z_Registration_Info_UClass_UMBPropActionSettings.InnerSingleton,
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
		return Z_Registration_Info_UClass_UMBPropActionSettings.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBPropActionSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBPropActionSettings.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBPropActionSettings.OuterSingleton;
}
#undef UHT_STATICS
UMBPropActionSettings::UMBPropActionSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBPropActionSettings);
UMBPropActionSettings::~UMBPropActionSettings() {}
// ********** End Class UMBPropActionSettings ******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBPropActionSettings_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBPropActionSettings, TEXT("UMBPropActionSettings"), &Z_Registration_Info_UClass_UMBPropActionSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBPropActionSettings), 2421078992U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBPropActionSettings_h__Script_ModularBuilding_f29289506e6b56730091e55e7403816937162cd8{
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
