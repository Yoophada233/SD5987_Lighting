// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODMeshData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODMeshData() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FDistObjectData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FDistObjectPropertyData(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UEnum* Z_Construct_UEnum_ObjectDistribution_EODDistributionFinishType(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UEnum* Z_Construct_UEnum_ObjectDistribution_EODLineAxis(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UEnum* Z_Construct_UEnum_ObjectDistribution_EODMeshConversionType(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UEnum* Z_Construct_UEnum_ObjectDistribution_EObjectDistributionType(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UEnum* Z_Construct_UEnum_ObjectDistribution_EObjectOrientation(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EObjectDistributionType ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ObjectDistribution_EObjectDistributionType_Statics
template<> OBJECTDISTRIBUTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EObjectDistributionType>()
{
	return Z_Construct_UEnum_ObjectDistribution_EObjectDistributionType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Object Distribution Data" },
		{ "Cube.DisplayName", "Cube" },
		{ "Cube.Name", "EObjectDistributionType::Cube" },
		{ "Disk.DisplayName", "Disk" },
		{ "Disk.Name", "EObjectDistributionType::Disk" },
		{ "Grid.DisplayName", "Grid" },
		{ "Grid.Name", "EObjectDistributionType::Grid" },
		{ "Line.DisplayName", "Line" },
		{ "Line.Name", "EObjectDistributionType::Line" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
		{ "Plane.DisplayName", "Plane" },
		{ "Plane.Name", "EObjectDistributionType::Plane" },
		{ "Ring.DisplayName", "Ring" },
		{ "Ring.Name", "EObjectDistributionType::Ring" },
		{ "Sphere.DisplayName", "Sphere" },
		{ "Sphere.Name", "EObjectDistributionType::Sphere" },
		{ "Spiral.DisplayName", "Spiral" },
		{ "Spiral.Name", "EObjectDistributionType::Spiral" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EObjectDistributionType::Cube", (int64)EObjectDistributionType::Cube },
		{ "EObjectDistributionType::Ring", (int64)EObjectDistributionType::Ring },
		{ "EObjectDistributionType::Disk", (int64)EObjectDistributionType::Disk },
		{ "EObjectDistributionType::Sphere", (int64)EObjectDistributionType::Sphere },
		{ "EObjectDistributionType::Spiral", (int64)EObjectDistributionType::Spiral },
		{ "EObjectDistributionType::Line", (int64)EObjectDistributionType::Line },
		{ "EObjectDistributionType::Plane", (int64)EObjectDistributionType::Plane },
		{ "EObjectDistributionType::Grid", (int64)EObjectDistributionType::Grid },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	"EObjectDistributionType",
	"EObjectDistributionType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EObjectDistributionType;
UEnum* Z_Construct_UEnum_ObjectDistribution_EObjectDistributionType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EObjectDistributionType.OuterSingleton)
		{
			ZRIE_EObjectDistributionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ObjectDistribution_EObjectDistributionType, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("EObjectDistributionType"));
		}
		return ZRIE_EObjectDistributionType.OuterSingleton;
	}
	if (!ZRIE_EObjectDistributionType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EObjectDistributionType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EObjectDistributionType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EObjectDistributionType *****************************************************

// ********** Begin Enum EObjectOrientation ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ObjectDistribution_EObjectOrientation_Statics
template<> OBJECTDISTRIBUTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EObjectOrientation>()
{
	return Z_Construct_UEnum_ObjectDistribution_EObjectOrientation(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Object Distribution Data" },
		{ "Inside.DisplayName", "Inside" },
		{ "Inside.Name", "EObjectOrientation::Inside" },
		{ "Keep.DisplayName", "Keep" },
		{ "Keep.Name", "EObjectOrientation::Keep" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
		{ "Outside.DisplayName", "Outside" },
		{ "Outside.Name", "EObjectOrientation::Outside" },
		{ "Random.DisplayName", "Random" },
		{ "Random.Name", "EObjectOrientation::Random" },
		{ "RandomZ.DisplayName", "Random Around" },
		{ "RandomZ.Name", "EObjectOrientation::RandomZ" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EObjectOrientation::Keep", (int64)EObjectOrientation::Keep },
		{ "EObjectOrientation::Inside", (int64)EObjectOrientation::Inside },
		{ "EObjectOrientation::Outside", (int64)EObjectOrientation::Outside },
		{ "EObjectOrientation::RandomZ", (int64)EObjectOrientation::RandomZ },
		{ "EObjectOrientation::Random", (int64)EObjectOrientation::Random },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	"EObjectOrientation",
	"EObjectOrientation",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EObjectOrientation;
UEnum* Z_Construct_UEnum_ObjectDistribution_EObjectOrientation(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EObjectOrientation.OuterSingleton)
		{
			ZRIE_EObjectOrientation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ObjectDistribution_EObjectOrientation, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("EObjectOrientation"));
		}
		return ZRIE_EObjectOrientation.OuterSingleton;
	}
	if (!ZRIE_EObjectOrientation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EObjectOrientation.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EObjectOrientation.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EObjectOrientation **********************************************************

// ********** Begin Enum EODLineAxis ***************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ObjectDistribution_EODLineAxis_Statics
template<> OBJECTDISTRIBUTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EODLineAxis>()
{
	return Z_Construct_UEnum_ObjectDistribution_EODLineAxis(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AxisX.DisplayName", "AxisX" },
		{ "AxisX.Name", "EODLineAxis::AxisX" },
		{ "AxisY.DisplayName", "AxisY" },
		{ "AxisY.Name", "EODLineAxis::AxisY" },
		{ "AxisZ.DisplayName", "AxisZ" },
		{ "AxisZ.Name", "EODLineAxis::AxisZ" },
		{ "BlueprintType", "true" },
		{ "Category", "Object Distribution Data" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EODLineAxis::None" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EODLineAxis::None", (int64)EODLineAxis::None },
		{ "EODLineAxis::AxisX", (int64)EODLineAxis::AxisX },
		{ "EODLineAxis::AxisY", (int64)EODLineAxis::AxisY },
		{ "EODLineAxis::AxisZ", (int64)EODLineAxis::AxisZ },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	"EODLineAxis",
	"EODLineAxis",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EODLineAxis;
UEnum* Z_Construct_UEnum_ObjectDistribution_EODLineAxis(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EODLineAxis.OuterSingleton)
		{
			ZRIE_EODLineAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ObjectDistribution_EODLineAxis, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("EODLineAxis"));
		}
		return ZRIE_EODLineAxis.OuterSingleton;
	}
	if (!ZRIE_EODLineAxis.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EODLineAxis.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EODLineAxis.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EODLineAxis *****************************************************************

// ********** Begin Enum EODDistributionFinishType *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ObjectDistribution_EODDistributionFinishType_Statics
template<> OBJECTDISTRIBUTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EODDistributionFinishType>()
{
	return Z_Construct_UEnum_ObjectDistribution_EODDistributionFinishType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Batch.DisplayName", "Batch" },
		{ "Batch.Name", "EODDistributionFinishType::Batch" },
		{ "Batch.ToolTip", "Batch the selected objects under a common actor based on the selected target component type." },
		{ "BlueprintType", "true" },
		{ "Category", "Object Distribution Data" },
		{ "Keep.DisplayName", "Keep" },
		{ "Keep.Name", "EODDistributionFinishType::Keep" },
		{ "Keep.ToolTip", "It leaves the objects as separate individual static mesh actors." },
		{ "Merge.DisplayName", "Run Merge Tool" },
		{ "Merge.Name", "EODDistributionFinishType::Merge" },
		{ "Merge.ToolTip", "Runs the built-in merge tool for the created objects. " },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EODDistributionFinishType::Keep", (int64)EODDistributionFinishType::Keep },
		{ "EODDistributionFinishType::Batch", (int64)EODDistributionFinishType::Batch },
		{ "EODDistributionFinishType::Merge", (int64)EODDistributionFinishType::Merge },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	"EODDistributionFinishType",
	"EODDistributionFinishType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EODDistributionFinishType;
UEnum* Z_Construct_UEnum_ObjectDistribution_EODDistributionFinishType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EODDistributionFinishType.OuterSingleton)
		{
			ZRIE_EODDistributionFinishType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ObjectDistribution_EODDistributionFinishType, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("EODDistributionFinishType"));
		}
		return ZRIE_EODDistributionFinishType.OuterSingleton;
	}
	if (!ZRIE_EODDistributionFinishType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EODDistributionFinishType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EODDistributionFinishType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EODDistributionFinishType ***************************************************

// ********** Begin Enum EODMeshConversionType *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ObjectDistribution_EODMeshConversionType_Statics
template<> OBJECTDISTRIBUTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EODMeshConversionType>()
{
	return Z_Construct_UEnum_ObjectDistribution_EODMeshConversionType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Object Distribution Data" },
		{ "HIsm.DisplayName", "HISM Component" },
		{ "HIsm.Name", "EODMeshConversionType::HIsm" },
		{ "HIsm.ToolTip", "Hierarchical Instanced Static Mesh Component" },
		{ "Ism.DisplayName", "ISM Component" },
		{ "Ism.Name", "EODMeshConversionType::Ism" },
		{ "Ism.ToolTip", "Instanced Static Mesh Component" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
		{ "Sm.DisplayName", "SM Component" },
		{ "Sm.Name", "EODMeshConversionType::Sm" },
		{ "Sm.ToolTip", "Static Mesh Component" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EODMeshConversionType::Sm", (int64)EODMeshConversionType::Sm },
		{ "EODMeshConversionType::Ism", (int64)EODMeshConversionType::Ism },
		{ "EODMeshConversionType::HIsm", (int64)EODMeshConversionType::HIsm },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	"EODMeshConversionType",
	"EODMeshConversionType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EODMeshConversionType;
UEnum* Z_Construct_UEnum_ObjectDistribution_EODMeshConversionType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EODMeshConversionType.OuterSingleton)
		{
			ZRIE_EODMeshConversionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ObjectDistribution_EODMeshConversionType, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("EODMeshConversionType"));
		}
		return ZRIE_EODMeshConversionType.OuterSingleton;
	}
	if (!ZRIE_EODMeshConversionType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EODMeshConversionType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EODMeshConversionType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EODMeshConversionType *******************************************************

// ********** Begin ScriptStruct FDistObjectPropertyData *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDistObjectPropertyData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDistObjectPropertyData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDistObjectPropertyData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnCount_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleRange_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinearDamping_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AngularDamping_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrientationType_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDistObjectPropertyData constinit property declarations ***********
	static const UECodeGen_Private::FIntPropertyParams NewProp_SpawnCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ScaleRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LinearDamping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AngularDamping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Mass;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OrientationType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OrientationType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDistObjectPropertyData constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDistObjectPropertyData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDistObjectPropertyData Property Definitions **********************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SpawnCount = { "SpawnCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDistObjectPropertyData, SpawnCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnCount_MetaData), NewProp_SpawnCount_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ScaleRange = { "ScaleRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDistObjectPropertyData, ScaleRange), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleRange_MetaData), NewProp_ScaleRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LinearDamping = { "LinearDamping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDistObjectPropertyData, LinearDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinearDamping_MetaData), NewProp_LinearDamping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AngularDamping = { "AngularDamping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDistObjectPropertyData, AngularDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AngularDamping_MetaData), NewProp_AngularDamping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDistObjectPropertyData, Mass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mass_MetaData), NewProp_Mass_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_OrientationType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_OrientationType = { "OrientationType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FDistObjectPropertyData, OrientationType), Z_Construct_UEnum_ObjectDistribution_EObjectOrientation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrientationType_MetaData), NewProp_OrientationType_MetaData) }; // 6776627ad0cc7a6f37b91a7cdb5f9110a452040e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScaleRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LinearDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AngularDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Mass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OrientationType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OrientationType,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDistObjectPropertyData Property Definitions ************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"DistObjectPropertyData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDistObjectPropertyData>(),
	alignof(FDistObjectPropertyData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDistObjectPropertyData;
UScriptStruct* Z_Construct_UScriptStruct_FDistObjectPropertyData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDistObjectPropertyData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDistObjectPropertyData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDistObjectPropertyData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("DistObjectPropertyData"));
		}
		return Z_Registration_Info_UScriptStruct_FDistObjectPropertyData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDistObjectPropertyData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDistObjectPropertyData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDistObjectPropertyData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDistObjectPropertyData *********************************************

// ********** Begin ScriptStruct FDistObjectData ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDistObjectData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDistObjectData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDistObjectData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSelectRandomMaterial_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "DisplayName", "Override Material" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
		{ "ToolTip", "Assign new material for first material slot" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SecondRandomMaterial_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "DisplayName", "New Material" },
		{ "EditCondition", "bSelectRandomMaterial" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSelectMaterialRandomly_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "DisplayName", "Select Material Randomly" },
		{ "EditCondition", "bSelectRandomMaterial" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
		{ "ToolTip", "It randomly changes the assigned material or doesn't change it at all." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistributionProperties_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveStatus_MetaData[] = {
		{ "Category", "Object Distribution Data" },
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerPreset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODMeshData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDistObjectData constinit property declarations *******************
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_StaticMesh;
	static void NewProp_bSelectRandomMaterial_SetBit(void* Obj)
	{
		((FDistObjectData*)Obj)->bSelectRandomMaterial = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSelectRandomMaterial;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SecondRandomMaterial;
	static void NewProp_bSelectMaterialRandomly_SetBit(void* Obj)
	{
		((FDistObjectData*)Obj)->bSelectMaterialRandomly = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSelectMaterialRandomly;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DistributionProperties;
	static void NewProp_ActiveStatus_SetBit(void* Obj)
	{
		((FDistObjectData*)Obj)->ActiveStatus = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ActiveStatus;
	static const UECodeGen_Private::FNamePropertyParams NewProp_OwnerPreset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDistObjectData constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDistObjectData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDistObjectData Property Definitions ******************************
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FDistObjectData, StaticMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticMesh_MetaData), NewProp_StaticMesh_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSelectRandomMaterial = { "bSelectRandomMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDistObjectData), &UHT_STATICS::NewProp_bSelectRandomMaterial_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSelectRandomMaterial_MetaData), NewProp_bSelectRandomMaterial_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_SecondRandomMaterial = { "SecondRandomMaterial", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FDistObjectData, SecondRandomMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SecondRandomMaterial_MetaData), NewProp_SecondRandomMaterial_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSelectMaterialRandomly = { "bSelectMaterialRandomly", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDistObjectData), &UHT_STATICS::NewProp_bSelectMaterialRandomly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSelectMaterialRandomly_MetaData), NewProp_bSelectMaterialRandomly_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DistributionProperties = { "DistributionProperties", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDistObjectData, DistributionProperties), Z_Construct_UScriptStruct_FDistObjectPropertyData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistributionProperties_MetaData), NewProp_DistributionProperties_MetaData) }; // 1ca50778e10c0b6b0bbf30a2824618b30646f20f
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ActiveStatus = { "ActiveStatus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDistObjectData), &UHT_STATICS::NewProp_ActiveStatus_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveStatus_MetaData), NewProp_ActiveStatus_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_OwnerPreset = { "OwnerPreset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(FDistObjectData, OwnerPreset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerPreset_MetaData), NewProp_OwnerPreset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StaticMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSelectRandomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SecondRandomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSelectMaterialRandomly,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistributionProperties,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActiveStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OwnerPreset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDistObjectData Property Definitions ********************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
	nullptr,
	&NewStructOps,
	"DistObjectData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDistObjectData>(),
	alignof(FDistObjectData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDistObjectData;
UScriptStruct* Z_Construct_UScriptStruct_FDistObjectData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDistObjectData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDistObjectData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDistObjectData, (UObject*)Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase::Outer), TEXT("DistObjectData"));
		}
		return Z_Registration_Info_UScriptStruct_FDistObjectData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDistObjectData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDistObjectData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDistObjectData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDistObjectData *****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODMeshData_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_ObjectDistribution_EObjectDistributionType, TEXT("EObjectDistributionType"), &ZRIE_EObjectDistributionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 717850479U) },
		{ Z_Construct_UEnum_ObjectDistribution_EObjectOrientation, TEXT("EObjectOrientation"), &ZRIE_EObjectOrientation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1735811706U) },
		{ Z_Construct_UEnum_ObjectDistribution_EODLineAxis, TEXT("EODLineAxis"), &ZRIE_EODLineAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1219577534U) },
		{ Z_Construct_UEnum_ObjectDistribution_EODDistributionFinishType, TEXT("EODDistributionFinishType"), &ZRIE_EODDistributionFinishType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 571305616U) },
		{ Z_Construct_UEnum_ObjectDistribution_EODMeshConversionType, TEXT("EODMeshConversionType"), &ZRIE_EODMeshConversionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1954314140U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDistObjectPropertyData, Z_Construct_UScriptStruct_FDistObjectPropertyData_Statics::NewStructOps, TEXT("DistObjectPropertyData"),&Z_Registration_Info_UScriptStruct_FDistObjectPropertyData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDistObjectPropertyData), 480577400U) },
		{ Z_Construct_UScriptStruct_FDistObjectData, Z_Construct_UScriptStruct_FDistObjectData_Statics::NewStructOps, TEXT("DistObjectData"),&Z_Registration_Info_UScriptStruct_FDistObjectData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDistObjectData), 1375523725U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODMeshData_h__Script_ObjectDistribution_46cc60192dabe594c4a6ad6edc6ac0b51da1111f{
	TEXT("/Script/ObjectDistribution"),
	nullptr, 0,
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
