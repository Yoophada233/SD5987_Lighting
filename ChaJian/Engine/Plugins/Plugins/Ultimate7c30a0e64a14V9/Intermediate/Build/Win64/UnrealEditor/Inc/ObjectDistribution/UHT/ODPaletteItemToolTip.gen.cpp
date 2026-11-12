// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODPaletteItemToolTip.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODPaletteItemToolTip() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_URichTextBlock(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODPaletteItemToolTip(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODPaletteItemToolTip(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODPaletteItemToolTip ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODPaletteItemToolTip_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI/ODPaletteItemToolTip.h" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteItemToolTip.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetNameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteItemToolTip.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetInfoText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteItemToolTip.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODPaletteItemToolTip constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AssetNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AssetInfoText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODPaletteItemToolTip constinit property declarations **********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODPaletteItemToolTip>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODPaletteItemToolTip Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AssetNameText = { "AssetNameText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteItemToolTip, AssetNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetNameText_MetaData), NewProp_AssetNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AssetInfoText = { "AssetInfoText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteItemToolTip, AssetInfoText), Z_Construct_UClass_URichTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetInfoText_MetaData), NewProp_AssetInfoText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AssetNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AssetInfoText,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODPaletteItemToolTip Property Definitions *********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODPaletteItemToolTip,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UODPaletteItemToolTip;
UClass* Z_Construct_UClass_UODPaletteItemToolTip(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODPaletteItemToolTip;
		if (!Z_Registration_Info_UClass_UODPaletteItemToolTip.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODPaletteItemToolTip"),
				Z_Registration_Info_UClass_UODPaletteItemToolTip.InnerSingleton,
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
		return Z_Registration_Info_UClass_UODPaletteItemToolTip.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODPaletteItemToolTip.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODPaletteItemToolTip.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODPaletteItemToolTip.OuterSingleton;
}
#undef UHT_STATICS
UODPaletteItemToolTip::UODPaletteItemToolTip(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODPaletteItemToolTip);
UODPaletteItemToolTip::~UODPaletteItemToolTip() {}
// ********** End Class UODPaletteItemToolTip ******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_UI_ODPaletteItemToolTip_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODPaletteItemToolTip, TEXT("UODPaletteItemToolTip"), &Z_Registration_Info_UClass_UODPaletteItemToolTip, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODPaletteItemToolTip), 2840898056U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_UI_ODPaletteItemToolTip_h__Script_ObjectDistribution_2576d74667d9cf84b203f5a3ede52c25c100dfaf{
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
