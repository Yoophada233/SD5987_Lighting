// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBPropDistributionBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBPropDistributionBase() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBDistributionType(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBPropOrientation(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBPropDistributionBase(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBPropDistributionBase(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBToolSubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBPropDistributionBase **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBPropDistributionBase_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Building/MBPropDistributionBase.h" },
		{ "ModuleRelativePath", "Public/Building/MBPropDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolSettingsSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBPropDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bActorSelected_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBPropDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOneActorDistribution_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBPropDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistributionActors_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBPropDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfDistribution_MetaData[] = {
		{ "Category", "Distribution" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Building/MBPropDistributionBase.h" },
		{ "NoResetToDefault", "" },
		{ "NoSpinbox", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistributionType_MetaData[] = {
		{ "Category", "Distribution" },
		{ "ModuleRelativePath", "Public/Building/MBPropDistributionBase.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorToFollow_MetaData[] = {
		{ "Category", "Distribution" },
		{ "ModuleRelativePath", "Public/Building/MBPropDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "Distribution" },
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "Public/Building/MBPropDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[] = {
		{ "Category", "Distribution" },
		{ "ModuleRelativePath", "Public/Building/MBPropDistributionBase.h" },
		{ "NoResetToDefault", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBPropDistributionBase constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToolSettingsSubsystem;
	static void NewProp_bActorSelected_SetBit(void* Obj)
	{
		((UMBPropDistributionBase*)Obj)->bActorSelected = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bActorSelected;
	static void NewProp_bOneActorDistribution_SetBit(void* Obj)
	{
		((UMBPropDistributionBase*)Obj)->bOneActorDistribution = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOneActorDistribution;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistributionActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DistributionActors;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfDistribution;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DistributionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DistributionType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActorToFollow;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Orientation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Orientation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBPropDistributionBase constinit property declarations ********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBPropDistributionBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBPropDistributionBase Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ToolSettingsSubsystem = { "ToolSettingsSubsystem", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPropDistributionBase, ToolSettingsSubsystem), Z_Construct_UClass_UMBToolSubsystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolSettingsSubsystem_MetaData), NewProp_ToolSettingsSubsystem_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bActorSelected = { "bActorSelected", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBPropDistributionBase), &UHT_STATICS::NewProp_bActorSelected_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bActorSelected_MetaData), NewProp_bActorSelected_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bOneActorDistribution = { "bOneActorDistribution", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBPropDistributionBase), &UHT_STATICS::NewProp_bOneActorDistribution_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOneActorDistribution_MetaData), NewProp_bOneActorDistribution_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DistributionActors_Inner = { "DistributionActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_DistributionActors = { "DistributionActors", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPropDistributionBase, DistributionActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistributionActors_MetaData), NewProp_DistributionActors_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NumberOfDistribution = { "NumberOfDistribution", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPropDistributionBase, NumberOfDistribution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumberOfDistribution_MetaData), NewProp_NumberOfDistribution_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_DistributionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_DistributionType = { "DistributionType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPropDistributionBase, DistributionType), Z_Construct_UEnum_ModularBuilding_EMBDistributionType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistributionType_MetaData), NewProp_DistributionType_MetaData) }; // c8eed0609af4a634f40ab413dc43a167fb24f4fa
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActorToFollow = { "ActorToFollow", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPropDistributionBase, ActorToFollow), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorToFollow_MetaData), NewProp_ActorToFollow_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPropDistributionBase, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Orientation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBPropDistributionBase, Orientation), Z_Construct_UEnum_ModularBuilding_EMBPropOrientation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orientation_MetaData), NewProp_Orientation_MetaData) }; // 4c03d65582b65e148d5412b5f37f2cf4f1aff204
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ToolSettingsSubsystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bActorSelected,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bOneActorDistribution,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistributionActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistributionActors,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NumberOfDistribution,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistributionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistributionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActorToFollow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Orientation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Orientation,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBPropDistributionBase Property Definitions *******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UObject,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBPropDistributionBase,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UMBPropDistributionBase;
UClass* Z_Construct_UClass_UMBPropDistributionBase(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBPropDistributionBase;
		if (!Z_Registration_Info_UClass_UMBPropDistributionBase.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBPropDistributionBase"),
				Z_Registration_Info_UClass_UMBPropDistributionBase.InnerSingleton,
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
		return Z_Registration_Info_UClass_UMBPropDistributionBase.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBPropDistributionBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBPropDistributionBase.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBPropDistributionBase.OuterSingleton;
}
#undef UHT_STATICS
UMBPropDistributionBase::UMBPropDistributionBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBPropDistributionBase);
UMBPropDistributionBase::~UMBPropDistributionBase() {}
// ********** End Class UMBPropDistributionBase ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBPropDistributionBase_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBPropDistributionBase, TEXT("UMBPropDistributionBase"), &Z_Registration_Info_UClass_UMBPropDistributionBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBPropDistributionBase), 1848453452U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBPropDistributionBase_h__Script_ModularBuilding_7952df8201f088a8e363be19b51c7ee43b3642a8{
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
