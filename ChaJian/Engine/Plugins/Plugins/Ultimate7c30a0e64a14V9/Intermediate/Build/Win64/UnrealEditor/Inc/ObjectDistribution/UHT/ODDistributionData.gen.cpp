// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODDistributionData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODDistributionData() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UEnum* Z_Construct_UEnum_ObjectDistribution_EODLineAxis(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODCubeDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODDiskDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODGridDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODLineDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODPlaneDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODRingDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODSphereDistributionData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FODSpiralDistributionData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FODDiskDistributionData *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FODDiskDistributionData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FODDiskDistributionData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FODDiskDistributionData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandZRangeCond_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandZRange_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Chaos_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FODDiskDistributionData constinit property declarations ***********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static void NewProp_bRandZRangeCond_SetBit(void* Obj)
	{
		((FODDiskDistributionData*)Obj)->bRandZRangeCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandZRangeCond;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandZRange;
	static void NewProp_Chaos_SetBit(void* Obj)
	{
		((FODDiskDistributionData*)Obj)->Chaos = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Chaos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FODDiskDistributionData constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FODDiskDistributionData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FODDiskDistributionData Property Definitions **********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODDiskDistributionData, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radius_MetaData), NewProp_Radius_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRandZRangeCond = { "bRandZRangeCond", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FODDiskDistributionData), &UHT_STATICS::NewProp_bRandZRangeCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandZRangeCond_MetaData), NewProp_bRandZRangeCond_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RandZRange = { "RandZRange", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FODDiskDistributionData, RandZRange), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandZRange_MetaData), NewProp_RandZRange_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Chaos = { "Chaos", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FODDiskDistributionData), &UHT_STATICS::NewProp_Chaos_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Chaos_MetaData), NewProp_Chaos_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRandZRangeCond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RandZRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Chaos,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FODDiskDistributionData Property Definitions ************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"ODDiskDistributionData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FODDiskDistributionData>(),
	alignof(FODDiskDistributionData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FODDiskDistributionData;
UScriptStruct* Z_Construct_UScriptStruct_FODDiskDistributionData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FODDiskDistributionData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FODDiskDistributionData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FODDiskDistributionData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("ODDiskDistributionData"));
		}
		return Z_Registration_Info_UScriptStruct_FODDiskDistributionData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FODDiskDistributionData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FODDiskDistributionData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FODDiskDistributionData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FODDiskDistributionData *********************************************

// ********** Begin ScriptStruct FODCubeDistributionData *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FODCubeDistributionData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FODCubeDistributionData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FODCubeDistributionData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "//********************************************************************************************************************************//\n" },
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleDistance_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomOffset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomOffset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FODCubeDistributionData constinit property declarations ***********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleDistance;
	static void NewProp_bRandomOffset_SetBit(void* Obj)
	{
		((FODCubeDistributionData*)Obj)->bRandomOffset = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FODCubeDistributionData constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FODCubeDistributionData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FODCubeDistributionData Property Definitions **********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ScaleDistance = { "ScaleDistance", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODCubeDistributionData, ScaleDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleDistance_MetaData), NewProp_ScaleDistance_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRandomOffset = { "bRandomOffset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FODCubeDistributionData), &UHT_STATICS::NewProp_bRandomOffset_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomOffset_MetaData), NewProp_bRandomOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RandomOffset = { "RandomOffset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FODCubeDistributionData, RandomOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomOffset_MetaData), NewProp_RandomOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScaleDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRandomOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RandomOffset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FODCubeDistributionData Property Definitions ************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"ODCubeDistributionData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FODCubeDistributionData>(),
	alignof(FODCubeDistributionData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FODCubeDistributionData;
UScriptStruct* Z_Construct_UScriptStruct_FODCubeDistributionData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FODCubeDistributionData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FODCubeDistributionData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FODCubeDistributionData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("ODCubeDistributionData"));
		}
		return Z_Registration_Info_UScriptStruct_FODCubeDistributionData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FODCubeDistributionData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FODCubeDistributionData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FODCubeDistributionData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FODCubeDistributionData *********************************************

// ********** Begin ScriptStruct FODLineDistributionData *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FODLineDistributionData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FODLineDistributionData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FODLineDistributionData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/********************************************************************************************************************************/" },
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineAxis_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineLength_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomOffset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomOffset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PivotCentered_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FODLineDistributionData constinit property declarations ***********
	static const UECodeGen_Private::FBytePropertyParams NewProp_LineAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LineAxis;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineLength;
	static void NewProp_bRandomOffset_SetBit(void* Obj)
	{
		((FODLineDistributionData*)Obj)->bRandomOffset = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomOffset;
	static void NewProp_PivotCentered_SetBit(void* Obj)
	{
		((FODLineDistributionData*)Obj)->PivotCentered = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_PivotCentered;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FODLineDistributionData constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FODLineDistributionData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FODLineDistributionData Property Definitions **********************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_LineAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_LineAxis = { "LineAxis", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FODLineDistributionData, LineAxis), Z_Construct_UEnum_ObjectDistribution_EODLineAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineAxis_MetaData), NewProp_LineAxis_MetaData) }; // 48b146bedcebede5e2f0c42a5cfeba0f79722848
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LineLength = { "LineLength", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODLineDistributionData, LineLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineLength_MetaData), NewProp_LineLength_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRandomOffset = { "bRandomOffset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FODLineDistributionData), &UHT_STATICS::NewProp_bRandomOffset_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomOffset_MetaData), NewProp_bRandomOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RandomOffset = { "RandomOffset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FODLineDistributionData, RandomOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomOffset_MetaData), NewProp_RandomOffset_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_PivotCentered = { "PivotCentered", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FODLineDistributionData), &UHT_STATICS::NewProp_PivotCentered_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PivotCentered_MetaData), NewProp_PivotCentered_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LineAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LineAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LineLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRandomOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RandomOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PivotCentered,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FODLineDistributionData Property Definitions ************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"ODLineDistributionData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FODLineDistributionData>(),
	alignof(FODLineDistributionData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FODLineDistributionData;
UScriptStruct* Z_Construct_UScriptStruct_FODLineDistributionData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FODLineDistributionData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FODLineDistributionData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FODLineDistributionData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("ODLineDistributionData"));
		}
		return Z_Registration_Info_UScriptStruct_FODLineDistributionData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FODLineDistributionData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FODLineDistributionData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FODLineDistributionData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FODLineDistributionData *********************************************

// ********** Begin ScriptStruct FODRingDistributionData *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FODRingDistributionData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FODRingDistributionData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FODRingDistributionData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/********************************************************************************************************************************/" },
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArcAngle_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandZRangeCond_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandZRange_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Chaos_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FODRingDistributionData constinit property declarations ***********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArcAngle;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Offset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static void NewProp_bRandZRangeCond_SetBit(void* Obj)
	{
		((FODRingDistributionData*)Obj)->bRandZRangeCond = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandZRangeCond;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandZRange;
	static void NewProp_Chaos_SetBit(void* Obj)
	{
		((FODRingDistributionData*)Obj)->Chaos = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Chaos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FODRingDistributionData constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FODRingDistributionData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FODRingDistributionData Property Definitions **********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ArcAngle = { "ArcAngle", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODRingDistributionData, ArcAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArcAngle_MetaData), NewProp_ArcAngle_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODRingDistributionData, Offset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODRingDistributionData, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radius_MetaData), NewProp_Radius_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRandZRangeCond = { "bRandZRangeCond", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FODRingDistributionData), &UHT_STATICS::NewProp_bRandZRangeCond_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandZRangeCond_MetaData), NewProp_bRandZRangeCond_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RandZRange = { "RandZRange", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FODRingDistributionData, RandZRange), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandZRange_MetaData), NewProp_RandZRange_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Chaos = { "Chaos", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FODRingDistributionData), &UHT_STATICS::NewProp_Chaos_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Chaos_MetaData), NewProp_Chaos_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ArcAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRandZRangeCond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RandZRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Chaos,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FODRingDistributionData Property Definitions ************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"ODRingDistributionData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FODRingDistributionData>(),
	alignof(FODRingDistributionData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FODRingDistributionData;
UScriptStruct* Z_Construct_UScriptStruct_FODRingDistributionData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FODRingDistributionData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FODRingDistributionData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FODRingDistributionData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("ODRingDistributionData"));
		}
		return Z_Registration_Info_UScriptStruct_FODRingDistributionData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FODRingDistributionData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FODRingDistributionData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FODRingDistributionData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FODRingDistributionData *********************************************

// ********** Begin ScriptStruct FODSphereDistributionData *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FODSphereDistributionData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FODSphereDistributionData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FODSphereDistributionData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/********************************************************************************************************************************/" },
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpiralWinding_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereRadius_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Chaos_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FODSphereDistributionData constinit property declarations *********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpiralWinding;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SphereRadius;
	static void NewProp_Chaos_SetBit(void* Obj)
	{
		((FODSphereDistributionData*)Obj)->Chaos = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Chaos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FODSphereDistributionData constinit property declarations ***********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FODSphereDistributionData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FODSphereDistributionData Property Definitions ********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SpiralWinding = { "SpiralWinding", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODSphereDistributionData, SpiralWinding), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpiralWinding_MetaData), NewProp_SpiralWinding_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SphereRadius = { "SphereRadius", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODSphereDistributionData, SphereRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereRadius_MetaData), NewProp_SphereRadius_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Chaos = { "Chaos", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FODSphereDistributionData), &UHT_STATICS::NewProp_Chaos_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Chaos_MetaData), NewProp_Chaos_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpiralWinding,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SphereRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Chaos,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FODSphereDistributionData Property Definitions **********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"ODSphereDistributionData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FODSphereDistributionData>(),
	alignof(FODSphereDistributionData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FODSphereDistributionData;
UScriptStruct* Z_Construct_UScriptStruct_FODSphereDistributionData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FODSphereDistributionData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FODSphereDistributionData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FODSphereDistributionData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("ODSphereDistributionData"));
		}
		return Z_Registration_Info_UScriptStruct_FODSphereDistributionData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FODSphereDistributionData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FODSphereDistributionData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FODSphereDistributionData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FODSphereDistributionData *******************************************

// ********** Begin ScriptStruct FODGridDistributionData *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FODGridDistributionData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FODGridDistributionData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FODGridDistributionData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/********************************************************************************************************************************/" },
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSize_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridLength_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Chaos_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FODGridDistributionData constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GridLength;
	static void NewProp_Chaos_SetBit(void* Obj)
	{
		((FODGridDistributionData*)Obj)->Chaos = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Chaos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FODGridDistributionData constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FODGridDistributionData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FODGridDistributionData Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_GridSize = { "GridSize", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FODGridDistributionData, GridSize), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSize_MetaData), NewProp_GridSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_GridLength = { "GridLength", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODGridDistributionData, GridLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridLength_MetaData), NewProp_GridLength_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Chaos = { "Chaos", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FODGridDistributionData), &UHT_STATICS::NewProp_Chaos_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Chaos_MetaData), NewProp_Chaos_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GridSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GridLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Chaos,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FODGridDistributionData Property Definitions ************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"ODGridDistributionData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FODGridDistributionData>(),
	alignof(FODGridDistributionData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FODGridDistributionData;
UScriptStruct* Z_Construct_UScriptStruct_FODGridDistributionData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FODGridDistributionData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FODGridDistributionData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FODGridDistributionData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("ODGridDistributionData"));
		}
		return Z_Registration_Info_UScriptStruct_FODGridDistributionData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FODGridDistributionData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FODGridDistributionData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FODGridDistributionData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FODGridDistributionData *********************************************

// ********** Begin ScriptStruct FODPlaneDistributionData ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FODPlaneDistributionData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FODPlaneDistributionData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FODPlaneDistributionData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/********************************************************************************************************************************/" },
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomOffset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomOffset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FODPlaneDistributionData constinit property declarations **********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Offset;
	static void NewProp_bRandomOffset_SetBit(void* Obj)
	{
		((FODPlaneDistributionData*)Obj)->bRandomOffset = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FODPlaneDistributionData constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FODPlaneDistributionData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FODPlaneDistributionData Property Definitions *********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODPlaneDistributionData, Offset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRandomOffset = { "bRandomOffset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FODPlaneDistributionData), &UHT_STATICS::NewProp_bRandomOffset_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomOffset_MetaData), NewProp_bRandomOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RandomOffset = { "RandomOffset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FODPlaneDistributionData, RandomOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomOffset_MetaData), NewProp_RandomOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRandomOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RandomOffset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FODPlaneDistributionData Property Definitions ***********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"ODPlaneDistributionData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FODPlaneDistributionData>(),
	alignof(FODPlaneDistributionData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FODPlaneDistributionData;
UScriptStruct* Z_Construct_UScriptStruct_FODPlaneDistributionData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FODPlaneDistributionData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FODPlaneDistributionData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FODPlaneDistributionData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("ODPlaneDistributionData"));
		}
		return Z_Registration_Info_UScriptStruct_FODPlaneDistributionData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FODPlaneDistributionData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FODPlaneDistributionData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FODPlaneDistributionData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FODPlaneDistributionData ********************************************

// ********** Begin ScriptStruct FODSpiralDistributionData *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FODSpiralDistributionData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FODSpiralDistributionData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FODSpiralDistributionData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/********************************************************************************************************************************/" },
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Length_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleDistance_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODDistributionData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FODSpiralDistributionData constinit property declarations *********
	static const UECodeGen_Private::FIntPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Length;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FODSpiralDistributionData constinit property declarations ***********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FODSpiralDistributionData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FODSpiralDistributionData Property Definitions ********************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FODSpiralDistributionData, Rotation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODSpiralDistributionData, Length), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Length_MetaData), NewProp_Length_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ScaleDistance = { "ScaleDistance", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FODSpiralDistributionData, ScaleDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleDistance_MetaData), NewProp_ScaleDistance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Length,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScaleDistance,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FODSpiralDistributionData Property Definitions **********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"ODSpiralDistributionData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FODSpiralDistributionData>(),
	alignof(FODSpiralDistributionData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FODSpiralDistributionData;
UScriptStruct* Z_Construct_UScriptStruct_FODSpiralDistributionData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FODSpiralDistributionData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FODSpiralDistributionData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FODSpiralDistributionData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("ODSpiralDistributionData"));
		}
		return Z_Registration_Info_UScriptStruct_FODSpiralDistributionData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FODSpiralDistributionData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FODSpiralDistributionData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FODSpiralDistributionData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FODSpiralDistributionData *******************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODDistributionData_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FODDiskDistributionData, Z_Construct_UScriptStruct_FODDiskDistributionData_Statics::NewStructOps, TEXT("ODDiskDistributionData"),&Z_Registration_Info_UScriptStruct_FODDiskDistributionData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FODDiskDistributionData), 594263548U) },
		{ Z_Construct_UScriptStruct_FODCubeDistributionData, Z_Construct_UScriptStruct_FODCubeDistributionData_Statics::NewStructOps, TEXT("ODCubeDistributionData"),&Z_Registration_Info_UScriptStruct_FODCubeDistributionData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FODCubeDistributionData), 1182645003U) },
		{ Z_Construct_UScriptStruct_FODLineDistributionData, Z_Construct_UScriptStruct_FODLineDistributionData_Statics::NewStructOps, TEXT("ODLineDistributionData"),&Z_Registration_Info_UScriptStruct_FODLineDistributionData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FODLineDistributionData), 3095029498U) },
		{ Z_Construct_UScriptStruct_FODRingDistributionData, Z_Construct_UScriptStruct_FODRingDistributionData_Statics::NewStructOps, TEXT("ODRingDistributionData"),&Z_Registration_Info_UScriptStruct_FODRingDistributionData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FODRingDistributionData), 3588125793U) },
		{ Z_Construct_UScriptStruct_FODSphereDistributionData, Z_Construct_UScriptStruct_FODSphereDistributionData_Statics::NewStructOps, TEXT("ODSphereDistributionData"),&Z_Registration_Info_UScriptStruct_FODSphereDistributionData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FODSphereDistributionData), 946000317U) },
		{ Z_Construct_UScriptStruct_FODGridDistributionData, Z_Construct_UScriptStruct_FODGridDistributionData_Statics::NewStructOps, TEXT("ODGridDistributionData"),&Z_Registration_Info_UScriptStruct_FODGridDistributionData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FODGridDistributionData), 1240800198U) },
		{ Z_Construct_UScriptStruct_FODPlaneDistributionData, Z_Construct_UScriptStruct_FODPlaneDistributionData_Statics::NewStructOps, TEXT("ODPlaneDistributionData"),&Z_Registration_Info_UScriptStruct_FODPlaneDistributionData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FODPlaneDistributionData), 892698580U) },
		{ Z_Construct_UScriptStruct_FODSpiralDistributionData, Z_Construct_UScriptStruct_FODSpiralDistributionData_Statics::NewStructOps, TEXT("ODSpiralDistributionData"),&Z_Registration_Info_UScriptStruct_FODSpiralDistributionData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FODSpiralDistributionData), 1240552393U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODDistributionData_h__Script_ObjectDistribution_91fb4927fe6fcd6e5a068bdf381cddad6046a2aa{
	TEXT("/Script/ObjectDistribution"),
	nullptr, 0,
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
