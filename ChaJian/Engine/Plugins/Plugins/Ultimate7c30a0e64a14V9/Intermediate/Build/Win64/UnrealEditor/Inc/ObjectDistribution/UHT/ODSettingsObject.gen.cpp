// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODSettingsObject.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODSettingsObject() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODSettingsObject(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODSettingsObject(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODSettingsObject ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODSettingsObject_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Data/ODSettingsObject.h" },
		{ "ModuleRelativePath", "Public/Data/ODSettingsObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSimulatePhysics_MetaData[] = {
		{ "Category", "Simulation" },
		{ "DisplayPriority", "1" },
		{ "ModuleRelativePath", "Public/Data/ODSettingsObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableSimAfterFinish_MetaData[] = {
		{ "Category", "Simulation" },
		{ "DisplayName", "Disable Sim After Finishing" },
		{ "DisplayPriority", "1" },
		{ "EditCondition", "bSimulatePhysics" },
		{ "ModuleRelativePath", "Public/Data/ODSettingsObject.h" },
		{ "NoResetToDefault", "" },
		{ "ToolTip", "Disable simulate physics option on the actors after finishing the distribution." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawSpawnBounds_MetaData[] = {
		{ "Category", "Visualization" },
		{ "DisplayName", "Draw Spawn Bounds" },
		{ "ModuleRelativePath", "Public/Data/ODSettingsObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoundsColor_MetaData[] = {
		{ "Category", "Visualization" },
		{ "Comment", "/*EditConditionHides,*/" },
		{ "EditCondition", "bDrawSpawnBounds" },
		{ "HideAlphaChannel", "" },
		{ "ModuleRelativePath", "Public/Data/ODSettingsObject.h" },
		{ "NoResetToDefault", "" },
		{ "ToolTip", "EditConditionHides," },
	};
#endif // WITH_METADATA

// ********** Begin Class UODSettingsObject constinit property declarations ************************
	static void NewProp_bSimulatePhysics_SetBit(void* Obj)
	{
		((UODSettingsObject*)Obj)->bSimulatePhysics = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSimulatePhysics;
	static void NewProp_bDisableSimAfterFinish_SetBit(void* Obj)
	{
		((UODSettingsObject*)Obj)->bDisableSimAfterFinish = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableSimAfterFinish;
	static void NewProp_bDrawSpawnBounds_SetBit(void* Obj)
	{
		((UODSettingsObject*)Obj)->bDrawSpawnBounds = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawSpawnBounds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BoundsColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODSettingsObject constinit property declarations **************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODSettingsObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODSettingsObject Property Definitions ***********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSimulatePhysics = { "bSimulatePhysics", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODSettingsObject), &UHT_STATICS::NewProp_bSimulatePhysics_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSimulatePhysics_MetaData), NewProp_bSimulatePhysics_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDisableSimAfterFinish = { "bDisableSimAfterFinish", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODSettingsObject), &UHT_STATICS::NewProp_bDisableSimAfterFinish_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableSimAfterFinish_MetaData), NewProp_bDisableSimAfterFinish_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDrawSpawnBounds = { "bDrawSpawnBounds", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODSettingsObject), &UHT_STATICS::NewProp_bDrawSpawnBounds_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawSpawnBounds_MetaData), NewProp_bDrawSpawnBounds_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_BoundsColor = { "BoundsColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODSettingsObject, BoundsColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundsColor_MetaData), NewProp_BoundsColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSimulatePhysics,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDisableSimAfterFinish,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDrawSpawnBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BoundsColor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODSettingsObject Property Definitions *************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UObject,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODSettingsObject,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UODSettingsObject;
UClass* Z_Construct_UClass_UODSettingsObject(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODSettingsObject;
		if (!Z_Registration_Info_UClass_UODSettingsObject.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODSettingsObject"),
				Z_Registration_Info_UClass_UODSettingsObject.InnerSingleton,
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
		return Z_Registration_Info_UClass_UODSettingsObject.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODSettingsObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODSettingsObject.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODSettingsObject.OuterSingleton;
}
#undef UHT_STATICS
UODSettingsObject::UODSettingsObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODSettingsObject);
UODSettingsObject::~UODSettingsObject() {}
// ********** End Class UODSettingsObject **********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODSettingsObject_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODSettingsObject, TEXT("UODSettingsObject"), &Z_Registration_Info_UClass_UODSettingsObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODSettingsObject), 3091658248U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODSettingsObject_h__Script_ObjectDistribution_72bfeb064418ef8396c82e6c512622b9a7bea5a6{
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
