// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODToolSettings.h"
#include "ODDistributionData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODToolSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UEnum* Z_Construct_UEnum_ObjectDistribution_EObjectDistributionType(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODCubeDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODDiskDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODGridDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODLineDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODPlaneDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODRingDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODSphereDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODSpiralDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODToolSettings(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODToolSettings(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODToolSettings **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODToolSettings_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Data/ODToolSettings.h" },
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiskDistributionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeDistributionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineDistributionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RingDistributionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereDistributionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridDistributionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneDistributionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpiralDistributionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSimulatePhysics_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableSimAfterFinish_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KillZ_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawSpawnBounds_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoundsColor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinishingType_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetType_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bTestForCollider_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCollisionTest_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastSelectedDistributionType_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODToolSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODToolSettings constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_DiskDistributionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CubeDistributionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LineDistributionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RingDistributionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SphereDistributionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridDistributionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlaneDistributionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpiralDistributionData;
	static void NewProp_bSimulatePhysics_SetBit(void* Obj)
	{
		((UODToolSettings*)Obj)->bSimulatePhysics = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSimulatePhysics;
	static void NewProp_bDisableSimAfterFinish_SetBit(void* Obj)
	{
		((UODToolSettings*)Obj)->bDisableSimAfterFinish = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableSimAfterFinish;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_KillZ;
	static void NewProp_bDrawSpawnBounds_SetBit(void* Obj)
	{
		((UODToolSettings*)Obj)->bDrawSpawnBounds = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawSpawnBounds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BoundsColor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FinishingType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetType;
	static void NewProp_bTestForCollider_SetBit(void* Obj)
	{
		((UODToolSettings*)Obj)->bTestForCollider = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTestForCollider;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxCollisionTest;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LastSelectedDistributionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LastSelectedDistributionType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODToolSettings constinit property declarations ****************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODToolSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODToolSettings Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DiskDistributionData = { "DiskDistributionData", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, DiskDistributionData), Z_Construct_UScriptStruct_FODDiskDistributionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiskDistributionData_MetaData), NewProp_DiskDistributionData_MetaData) }; // 236bbdfc573c776274cffb989b658950dc7f4370
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_CubeDistributionData = { "CubeDistributionData", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, CubeDistributionData), Z_Construct_UScriptStruct_FODCubeDistributionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeDistributionData_MetaData), NewProp_CubeDistributionData_MetaData) }; // 467dbb0b7354a37e374d148734b3295aa5c33297
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_LineDistributionData = { "LineDistributionData", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, LineDistributionData), Z_Construct_UScriptStruct_FODLineDistributionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineDistributionData_MetaData), NewProp_LineDistributionData_MetaData) }; // b87a66fa02745348e4016c71c5693658592a2954
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RingDistributionData = { "RingDistributionData", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, RingDistributionData), Z_Construct_UScriptStruct_FODRingDistributionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RingDistributionData_MetaData), NewProp_RingDistributionData_MetaData) }; // d5de74614f8995c265ea8e25b37f390b9a414cf5
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SphereDistributionData = { "SphereDistributionData", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, SphereDistributionData), Z_Construct_UScriptStruct_FODSphereDistributionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereDistributionData_MetaData), NewProp_SphereDistributionData_MetaData) }; // 3862d1bd0432a0a3a25aa4a1650b8cb89165cbf7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_GridDistributionData = { "GridDistributionData", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, GridDistributionData), Z_Construct_UScriptStruct_FODGridDistributionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridDistributionData_MetaData), NewProp_GridDistributionData_MetaData) }; // 49f51bc62e57e9f5e078cbc83b132bddb7dc0d36
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PlaneDistributionData = { "PlaneDistributionData", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, PlaneDistributionData), Z_Construct_UScriptStruct_FODPlaneDistributionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneDistributionData_MetaData), NewProp_PlaneDistributionData_MetaData) }; // 35357fd4f449599a84d3cf799248d4091de6110f
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpiralDistributionData = { "SpiralDistributionData", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, SpiralDistributionData), Z_Construct_UScriptStruct_FODSpiralDistributionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpiralDistributionData_MetaData), NewProp_SpiralDistributionData_MetaData) }; // 49f153c9f91884ddbd573a38a684e28f3410f84d
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSimulatePhysics = { "bSimulatePhysics", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODToolSettings), &UHT_STATICS::NewProp_bSimulatePhysics_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSimulatePhysics_MetaData), NewProp_bSimulatePhysics_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDisableSimAfterFinish = { "bDisableSimAfterFinish", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODToolSettings), &UHT_STATICS::NewProp_bDisableSimAfterFinish_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableSimAfterFinish_MetaData), NewProp_bDisableSimAfterFinish_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_KillZ = { "KillZ", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, KillZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KillZ_MetaData), NewProp_KillZ_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDrawSpawnBounds = { "bDrawSpawnBounds", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODToolSettings), &UHT_STATICS::NewProp_bDrawSpawnBounds_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawSpawnBounds_MetaData), NewProp_bDrawSpawnBounds_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_BoundsColor = { "BoundsColor", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, BoundsColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundsColor_MetaData), NewProp_BoundsColor_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FinishingType = { "FinishingType", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, FinishingType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinishingType_MetaData), NewProp_FinishingType_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TargetType = { "TargetType", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, TargetType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetType_MetaData), NewProp_TargetType_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bTestForCollider = { "bTestForCollider", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODToolSettings), &UHT_STATICS::NewProp_bTestForCollider_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bTestForCollider_MetaData), NewProp_bTestForCollider_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxCollisionTest = { "MaxCollisionTest", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, MaxCollisionTest), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCollisionTest_MetaData), NewProp_MaxCollisionTest_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_LastSelectedDistributionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_LastSelectedDistributionType = { "LastSelectedDistributionType", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolSettings, LastSelectedDistributionType), Z_Construct_UEnum_ObjectDistribution_EObjectDistributionType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastSelectedDistributionType_MetaData), NewProp_LastSelectedDistributionType_MetaData) }; // 2ac9876f7487d3b25a3525da95d8dbf4025e5eee
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DiskDistributionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CubeDistributionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LineDistributionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RingDistributionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SphereDistributionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GridDistributionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlaneDistributionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpiralDistributionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSimulatePhysics,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDisableSimAfterFinish,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_KillZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDrawSpawnBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BoundsColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FinishingType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bTestForCollider,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxCollisionTest,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastSelectedDistributionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastSelectedDistributionType,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODToolSettings Property Definitions ***************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UObject,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODToolSettings,
	"ODToolSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UODToolSettings;
UClass* Z_Construct_UClass_UODToolSettings(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODToolSettings;
		if (!Z_Registration_Info_UClass_UODToolSettings.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODToolSettings"),
				Z_Registration_Info_UClass_UODToolSettings.InnerSingleton,
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
		return Z_Registration_Info_UClass_UODToolSettings.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODToolSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODToolSettings.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODToolSettings.OuterSingleton;
}
#undef UHT_STATICS
UODToolSettings::UODToolSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODToolSettings);
UODToolSettings::~UODToolSettings() {}
// ********** End Class UODToolSettings ************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODToolSettings_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODToolSettings, TEXT("UODToolSettings"), &Z_Registration_Info_UClass_UODToolSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODToolSettings), 2769007123U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODToolSettings_h__Script_ObjectDistribution_7ae0ed6a2aa0706660096e0f8fcd850577475537{
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
