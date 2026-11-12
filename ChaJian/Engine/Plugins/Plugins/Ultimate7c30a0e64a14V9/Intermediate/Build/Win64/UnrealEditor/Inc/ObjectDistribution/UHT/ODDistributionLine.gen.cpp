// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODDistributionLine.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODDistributionLine() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UEnum* Z_Construct_UEnum_ObjectDistribution_EODLineAxis(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDistributionBase(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDistributionLine(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDistributionLine(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODDistributionLine ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODDistributionLine_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "ObjectDistribution/ODDistributionLine.h" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionLine.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineAxis_MetaData[] = {
		{ "Category", "Distribution" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionLine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineLength_MetaData[] = {
		{ "Category", "Distribution" },
		{ "ClampMin", "1.000000" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionLine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomOffset_MetaData[] = {
		{ "Category", "Distribution" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionLine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomOffset_MetaData[] = {
		{ "Category", "Distribution" },
		{ "EditCondition", "bRandomOffset" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionLine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PivotCentered_MetaData[] = {
		{ "Category", "Distribution" },
		{ "DisplayName", "Pivot Centered Distribution" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionLine.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODDistributionLine constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_LineAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LineAxis;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineLength;
	static void NewProp_bRandomOffset_SetBit(void* Obj)
	{
		((UODDistributionLine*)Obj)->bRandomOffset = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomOffset;
	static void NewProp_PivotCentered_SetBit(void* Obj)
	{
		((UODDistributionLine*)Obj)->PivotCentered = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_PivotCentered;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODDistributionLine constinit property declarations ************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODDistributionLine>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODDistributionLine Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_LineAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_LineAxis = { "LineAxis", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UODDistributionLine, LineAxis), Z_Construct_UEnum_ObjectDistribution_EODLineAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineAxis_MetaData), NewProp_LineAxis_MetaData) }; // 48b146bedcebede5e2f0c42a5cfeba0f79722848
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LineLength = { "LineLength", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UODDistributionLine, LineLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineLength_MetaData), NewProp_LineLength_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRandomOffset = { "bRandomOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODDistributionLine), &UHT_STATICS::NewProp_bRandomOffset_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomOffset_MetaData), NewProp_bRandomOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RandomOffset = { "RandomOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODDistributionLine, RandomOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomOffset_MetaData), NewProp_RandomOffset_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_PivotCentered = { "PivotCentered", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODDistributionLine), &UHT_STATICS::NewProp_PivotCentered_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PivotCentered_MetaData), NewProp_PivotCentered_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LineAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LineAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LineLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRandomOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RandomOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PivotCentered,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODDistributionLine Property Definitions ***********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UODDistributionBase,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODDistributionLine,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UODDistributionLine;
UClass* Z_Construct_UClass_UODDistributionLine(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODDistributionLine;
		if (!Z_Registration_Info_UClass_UODDistributionLine.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODDistributionLine"),
				Z_Registration_Info_UClass_UODDistributionLine.InnerSingleton,
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
		return Z_Registration_Info_UClass_UODDistributionLine.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODDistributionLine.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODDistributionLine.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODDistributionLine.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODDistributionLine);
UODDistributionLine::~UODDistributionLine() {}
// ********** End Class UODDistributionLine ********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_ObjectDistribution_ODDistributionLine_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODDistributionLine, TEXT("UODDistributionLine"), &Z_Registration_Info_UClass_UODDistributionLine, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODDistributionLine), 1470236199U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_ObjectDistribution_ODDistributionLine_h__Script_ObjectDistribution_9c31ad22c5a74f000292352a21a214528aea899a{
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
