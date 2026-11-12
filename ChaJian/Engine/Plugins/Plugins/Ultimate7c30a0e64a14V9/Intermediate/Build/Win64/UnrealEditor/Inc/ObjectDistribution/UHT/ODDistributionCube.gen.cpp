// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODDistributionCube.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODDistributionCube() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDistributionBase(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDistributionCube(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDistributionCube(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODDistributionCube ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODDistributionCube_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "ObjectDistribution/ODDistributionCube.h" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionCube.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleDistance_MetaData[] = {
		{ "Category", "Distribution" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionCube.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomOffset_MetaData[] = {
		{ "Category", "Distribution" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionCube.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomOffset_MetaData[] = {
		{ "Category", "Distribution" },
		{ "EditCondition", "bRandomOffset" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionCube.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODDistributionCube constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleDistance;
	static void NewProp_bRandomOffset_SetBit(void* Obj)
	{
		((UODDistributionCube*)Obj)->bRandomOffset = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODDistributionCube constinit property declarations ************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODDistributionCube>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODDistributionCube Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ScaleDistance = { "ScaleDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UODDistributionCube, ScaleDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleDistance_MetaData), NewProp_ScaleDistance_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRandomOffset = { "bRandomOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODDistributionCube), &UHT_STATICS::NewProp_bRandomOffset_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomOffset_MetaData), NewProp_bRandomOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RandomOffset = { "RandomOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODDistributionCube, RandomOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomOffset_MetaData), NewProp_RandomOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScaleDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRandomOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RandomOffset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODDistributionCube Property Definitions ***********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UODDistributionBase,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODDistributionCube,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UODDistributionCube;
UClass* Z_Construct_UClass_UODDistributionCube(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODDistributionCube;
		if (!Z_Registration_Info_UClass_UODDistributionCube.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODDistributionCube"),
				Z_Registration_Info_UClass_UODDistributionCube.InnerSingleton,
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
		return Z_Registration_Info_UClass_UODDistributionCube.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODDistributionCube.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODDistributionCube.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODDistributionCube.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODDistributionCube);
UODDistributionCube::~UODDistributionCube() {}
// ********** End Class UODDistributionCube ********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_ObjectDistribution_ODDistributionCube_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODDistributionCube, TEXT("UODDistributionCube"), &Z_Registration_Info_UClass_UODDistributionCube, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODDistributionCube), 394191631U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_ObjectDistribution_ODDistributionCube_h__Script_ObjectDistribution_a051973692a1167a40d2a466930e9a9c78279d58{
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
