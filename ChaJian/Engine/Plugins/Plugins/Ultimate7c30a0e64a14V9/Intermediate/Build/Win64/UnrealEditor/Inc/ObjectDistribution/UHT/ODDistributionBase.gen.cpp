// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODDistributionBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODDistributionBase() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UEnum* Z_Construct_UEnum_ObjectDistribution_EObjectDistributionType(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDistributionBase(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDistributionBase(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODToolSubsystem(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODToolWindow(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODDistributionBase Function OnPresetLoaded ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODDistributionBase_OnPresetLoaded_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnPresetLoaded constinit property declarations ************************
// ********** End Function OnPresetLoaded constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODDistributionBase, nullptr, "OnPresetLoaded", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODDistributionBase_OnPresetLoaded(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODDistributionBase::execOnPresetLoaded)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPresetLoaded();
	P_NATIVE_END;
}
// ********** End Class UODDistributionBase Function OnPresetLoaded ********************************

// ********** Begin Class UODDistributionBase ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODDistributionBase_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "ObjectDistribution/ODDistributionBase.h" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolWindow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsInMixerMode_MetaData[] = {
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistributionType_MetaData[] = {
		{ "Category", "Distribution" },
		{ "DisplayPriority", "1" },
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionBase.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorsInKillZ_MetaData[] = {
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SimulatedActors_MetaData[] = {
		{ "ModuleRelativePath", "Public/ObjectDistribution/ODDistributionBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODDistributionBase constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToolWindow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToolSubsystem;
	static void NewProp_bIsInMixerMode_SetBit(void* Obj)
	{
		((UODDistributionBase*)Obj)->bIsInMixerMode = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsInMixerMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DistributionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DistributionType;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ActorsInKillZ_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ActorsInKillZ;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SimulatedActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SimulatedActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODDistributionBase constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnPresetLoaded"), .Pointer = &UODDistributionBase::execOnPresetLoaded },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UODDistributionBase_OnPresetLoaded, "OnPresetLoaded" }, // 3c987731ff7636388bd8afbc22c0db61a9859eb6
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODDistributionBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODDistributionBase Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ToolWindow = { "ToolWindow", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODDistributionBase, ToolWindow), Z_Construct_UClass_UODToolWindow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolWindow_MetaData), NewProp_ToolWindow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ToolSubsystem = { "ToolSubsystem", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODDistributionBase, ToolSubsystem), Z_Construct_UClass_UODToolSubsystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolSubsystem_MetaData), NewProp_ToolSubsystem_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsInMixerMode = { "bIsInMixerMode", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODDistributionBase), &UHT_STATICS::NewProp_bIsInMixerMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsInMixerMode_MetaData), NewProp_bIsInMixerMode_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_DistributionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_DistributionType = { "DistributionType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UODDistributionBase, DistributionType), Z_Construct_UEnum_ObjectDistribution_EObjectDistributionType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistributionType_MetaData), NewProp_DistributionType_MetaData) }; // 2ac9876f7487d3b25a3525da95d8dbf4025e5eee
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_ActorsInKillZ_Inner = { "ActorsInKillZ", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ActorsInKillZ = { "ActorsInKillZ", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UODDistributionBase, ActorsInKillZ), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorsInKillZ_MetaData), NewProp_ActorsInKillZ_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SimulatedActors_Inner = { "SimulatedActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_SimulatedActors = { "SimulatedActors", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UODDistributionBase, SimulatedActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SimulatedActors_MetaData), NewProp_SimulatedActors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ToolWindow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ToolSubsystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsInMixerMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistributionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistributionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActorsInKillZ_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActorsInKillZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SimulatedActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SimulatedActors,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODDistributionBase Property Definitions ***********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UObject,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODDistributionBase,
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
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UODDistributionBase_StaticRegisterNativesUODDistributionBase()
{
	UClass* Class = UODDistributionBase::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UODDistributionBase;
UClass* Z_Construct_UClass_UODDistributionBase(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODDistributionBase;
		if (!Z_Registration_Info_UClass_UODDistributionBase.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODDistributionBase"),
				Z_Registration_Info_UClass_UODDistributionBase.InnerSingleton,
				UODDistributionBase_StaticRegisterNativesUODDistributionBase,
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
		return Z_Registration_Info_UClass_UODDistributionBase.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODDistributionBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODDistributionBase.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODDistributionBase.OuterSingleton;
}
#undef UHT_STATICS
UODDistributionBase::UODDistributionBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODDistributionBase);
UODDistributionBase::~UODDistributionBase() {}
// ********** End Class UODDistributionBase ********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_ObjectDistribution_ODDistributionBase_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODDistributionBase, TEXT("UODDistributionBase"), &Z_Registration_Info_UClass_UODDistributionBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODDistributionBase), 3312966090U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_ObjectDistribution_ODDistributionBase_h__Script_ObjectDistribution_03f69124a5e3af37e541434f645d12c0a54fa9e4{
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
