// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODDiskDistribution.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODDiskDistribution() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDiskDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDistributionBase(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDiskDistribution(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODDiskDistribution ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODDiskDistribution_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "ObjectDistribution/ODDiskDistribution.h" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDiskDistribution.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[] = {
		{ "Category", "Distribution" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDiskDistribution.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandZRangeCond_MetaData[] = {
		{ "Category", "Distribution" },
		{ "DisplayName", "Random Z Offset" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDiskDistribution.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandZRange_MetaData[] = {
		{ "Category", "Distribution" },
		{ "DisplayName", "Random Z Offset" },
		{ "EditCondition", "bRandZRangeCond" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDiskDistribution.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Chaos_MetaData[] = {
		{ "Category", "Distribution" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDiskDistribution.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODDiskDistribution constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static void NewProp_bRandZRangeCond_SetBit(void* Obj)
	{
		((UODDiskDistribution*)Obj)->bRandZRangeCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandZRangeCond;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandZRange;
	static void NewProp_Chaos_SetBit(void* Obj)
	{
		((UODDiskDistribution*)Obj)->Chaos = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Chaos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODDiskDistribution constinit property declarations ************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODDiskDistribution>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODDiskDistribution Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UODDiskDistribution, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radius_MetaData), NewProp_Radius_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRandZRangeCond = { "bRandZRangeCond", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODDiskDistribution), &UHT_STATICS::NewProp_bRandZRangeCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandZRangeCond_MetaData), NewProp_bRandZRangeCond_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RandZRange = { "RandZRange", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODDiskDistribution, RandZRange), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandZRange_MetaData), NewProp_RandZRange_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Chaos = { "Chaos", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODDiskDistribution), &UHT_STATICS::NewProp_Chaos_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Chaos_MetaData), NewProp_Chaos_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRandZRangeCond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RandZRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Chaos,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODDiskDistribution Property Definitions ***********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UODDistributionBase,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODDiskDistribution,
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
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UODDiskDistribution;
UClass* Z_Construct_UClass_UODDiskDistribution(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODDiskDistribution;
		if (!Z_Registration_Info_UClass_UODDiskDistribution.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODDiskDistribution"),
				Z_Registration_Info_UClass_UODDiskDistribution.InnerSingleton,
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
		return Z_Registration_Info_UClass_UODDiskDistribution.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODDiskDistribution.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODDiskDistribution.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODDiskDistribution.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODDiskDistribution);
UODDiskDistribution::~UODDiskDistribution() {}
// ********** End Class UODDiskDistribution ********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_ObjectDistribution_ODDiskDistribution_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODDiskDistribution, TEXT("UODDiskDistribution"), &Z_Registration_Info_UClass_UODDiskDistribution, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODDiskDistribution), 2886368023U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_ObjectDistribution_ODDiskDistribution_h__Script_ObjectDistribution_213a540626b75a09106b5456dae8a6285586d921{
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
