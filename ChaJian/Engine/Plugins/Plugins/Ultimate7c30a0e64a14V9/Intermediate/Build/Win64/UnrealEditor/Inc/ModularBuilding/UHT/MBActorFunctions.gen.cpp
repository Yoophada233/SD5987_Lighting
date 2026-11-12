// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBActorFunctions.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBActorFunctions() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FBox(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EBuildingCategory(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBActorFunctions(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBActorFunctions(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBActorFunctions Function FilterForCategory *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBActorFunctions_FilterForCategory_Statics
struct UHT_STATICS
{
	struct MBActorFunctions_eventFilterForCategory_Parms
	{
		EBuildingCategory InCategory;
		TArray<AActor*> InActors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBActor" },
		{ "Keywords", "Modular Actor" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InCategory_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FilterForCategory constinit property declarations *********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InCategory_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InCategory;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FilterForCategory constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FilterForCategory Property Definitions ********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InCategory_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InCategory = { "InCategory", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventFilterForCategory_Parms, InCategory), Z_Construct_UEnum_ModularBuilding_EBuildingCategory, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InCategory_MetaData), NewProp_InCategory_MetaData) }; // 07cf8117a6e577cac6ce1c747d6b11cc85196fdc
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InActors_Inner = { "InActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_InActors = { "InActors", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventFilterForCategory_Parms, InActors), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InCategory_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InCategory,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InActors,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function FilterForCategory Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBActorFunctions, nullptr, "FilterForCategory", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBActorFunctions_eventFilterForCategory_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBActorFunctions_eventFilterForCategory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBActorFunctions_FilterForCategory(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBActorFunctions::execFilterForCategory)
{
	P_GET_ENUM(EBuildingCategory,Z_Param_InCategory);
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_InActors);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMBActorFunctions::FilterForCategory(EBuildingCategory(Z_Param_InCategory),Z_Param_Out_InActors);
	P_NATIVE_END;
}
// ********** End Class UMBActorFunctions Function FilterForCategory *******************************

// ********** Begin Class UMBActorFunctions Function FilterModularActors ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBActorFunctions_FilterModularActors_Statics
struct UHT_STATICS
{
	struct MBActorFunctions_eventFilterModularActors_Parms
	{
		TArray<AActor*> InActors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBActor" },
		{ "Keywords", "Modular Actor" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function FilterModularActors constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FilterModularActors constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FilterModularActors Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InActors_Inner = { "InActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_InActors = { "InActors", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventFilterModularActors_Parms, InActors), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InActors,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function FilterModularActors Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBActorFunctions, nullptr, "FilterModularActors", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBActorFunctions_eventFilterModularActors_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBActorFunctions_eventFilterModularActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBActorFunctions_FilterModularActors(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBActorFunctions::execFilterModularActors)
{
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_InActors);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMBActorFunctions::FilterModularActors(Z_Param_Out_InActors);
	P_NATIVE_END;
}
// ********** End Class UMBActorFunctions Function FilterModularActors *****************************

// ********** Begin Class UMBActorFunctions Function GetActorWithObjectName ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBActorFunctions_GetActorWithObjectName_Statics
struct UHT_STATICS
{
	struct MBActorFunctions_eventGetActorWithObjectName_Parms
	{
		FString InName;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBActor" },
		{ "Keywords", "Modular Actor" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActorWithObjectName constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActorWithObjectName constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActorWithObjectName Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_InName = { "InName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetActorWithObjectName_Parms, InName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InName_MetaData), NewProp_InName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetActorWithObjectName_Parms, ReturnValue), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetActorWithObjectName Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBActorFunctions, nullptr, "GetActorWithObjectName", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBActorFunctions_eventGetActorWithObjectName_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBActorFunctions_eventGetActorWithObjectName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBActorFunctions_GetActorWithObjectName(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBActorFunctions::execGetActorWithObjectName)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=UMBActorFunctions::GetActorWithObjectName(Z_Param_InName);
	P_NATIVE_END;
}
// ********** End Class UMBActorFunctions Function GetActorWithObjectName **************************

// ********** Begin Class UMBActorFunctions Function GetAllActorsTransportPoint ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBActorFunctions_GetAllActorsTransportPoint_Statics
struct UHT_STATICS
{
	struct MBActorFunctions_eventGetAllActorsTransportPoint_Parms
	{
		TArray<AActor*> InActors;
		FBox ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBActor" },
		{ "Keywords", "Modular Actor" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InActors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllActorsTransportPoint constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InActors;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllActorsTransportPoint constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllActorsTransportPoint Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InActors_Inner = { "InActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_InActors = { "InActors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetAllActorsTransportPoint_Parms, InActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InActors_MetaData), NewProp_InActors_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetAllActorsTransportPoint_Parms, ReturnValue), Z_Construct_UScriptStruct_FBox, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InActors,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAllActorsTransportPoint Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBActorFunctions, nullptr, "GetAllActorsTransportPoint", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBActorFunctions_eventGetAllActorsTransportPoint_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBActorFunctions_eventGetAllActorsTransportPoint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBActorFunctions_GetAllActorsTransportPoint(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBActorFunctions::execGetAllActorsTransportPoint)
{
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_InActors);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FBox*)Z_Param__Result=UMBActorFunctions::GetAllActorsTransportPoint(Z_Param_Out_InActors);
	P_NATIVE_END;
}
// ********** End Class UMBActorFunctions Function GetAllActorsTransportPoint **********************

// ********** Begin Class UMBActorFunctions Function GetAllActorsTransportPointWithExtents *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBActorFunctions_GetAllActorsTransportPointWithExtents_Statics
struct UHT_STATICS
{
	struct MBActorFunctions_eventGetAllActorsTransportPointWithExtents_Parms
	{
		TArray<AActor*> InActors;
		FBox ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBActor" },
		{ "Keywords", "Modular Actor" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InActors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllActorsTransportPointWithExtents constinit property declarations *
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InActors;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllActorsTransportPointWithExtents constinit property declarations ***
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllActorsTransportPointWithExtents Property Definitions ************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InActors_Inner = { "InActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_InActors = { "InActors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetAllActorsTransportPointWithExtents_Parms, InActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InActors_MetaData), NewProp_InActors_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetAllActorsTransportPointWithExtents_Parms, ReturnValue), Z_Construct_UScriptStruct_FBox, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InActors,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAllActorsTransportPointWithExtents Property Definitions **************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBActorFunctions, nullptr, "GetAllActorsTransportPointWithExtents", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBActorFunctions_eventGetAllActorsTransportPointWithExtents_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBActorFunctions_eventGetAllActorsTransportPointWithExtents_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBActorFunctions_GetAllActorsTransportPointWithExtents(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBActorFunctions::execGetAllActorsTransportPointWithExtents)
{
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_InActors);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FBox*)Z_Param__Result=UMBActorFunctions::GetAllActorsTransportPointWithExtents(Z_Param_Out_InActors);
	P_NATIVE_END;
}
// ********** End Class UMBActorFunctions Function GetAllActorsTransportPointWithExtents ***********

// ********** Begin Class UMBActorFunctions Function GetAllActorsUnderTheFolderPath ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBActorFunctions_GetAllActorsUnderTheFolderPath_Statics
struct UHT_STATICS
{
	struct MBActorFunctions_eventGetAllActorsUnderTheFolderPath_Parms
	{
		FName InFolderPath;
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBActor" },
		{ "Keywords", "Modular Actor" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InFolderPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllActorsUnderTheFolderPath constinit property declarations ********
	static const UECodeGen_Private::FNamePropertyParams NewProp_InFolderPath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllActorsUnderTheFolderPath constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllActorsUnderTheFolderPath Property Definitions *******************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_InFolderPath = { "InFolderPath", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetAllActorsUnderTheFolderPath_Parms, InFolderPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InFolderPath_MetaData), NewProp_InFolderPath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetAllActorsUnderTheFolderPath_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InFolderPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAllActorsUnderTheFolderPath Property Definitions *********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBActorFunctions, nullptr, "GetAllActorsUnderTheFolderPath", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBActorFunctions_eventGetAllActorsUnderTheFolderPath_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBActorFunctions_eventGetAllActorsUnderTheFolderPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBActorFunctions_GetAllActorsUnderTheFolderPath(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBActorFunctions::execGetAllActorsUnderTheFolderPath)
{
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_InFolderPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=UMBActorFunctions::GetAllActorsUnderTheFolderPath(Z_Param_Out_InFolderPath);
	P_NATIVE_END;
}
// ********** End Class UMBActorFunctions Function GetAllActorsUnderTheFolderPath ******************

// ********** Begin Class UMBActorFunctions Function GetAllActorsWithGivenObjectNames **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBActorFunctions_GetAllActorsWithGivenObjectNames_Statics
struct UHT_STATICS
{
	struct MBActorFunctions_eventGetAllActorsWithGivenObjectNames_Parms
	{
		TArray<FString> InNames;
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBActor" },
		{ "Keywords", "Modular Actor" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllActorsWithGivenObjectNames constinit property declarations ******
	static const UECodeGen_Private::FStrPropertyParams NewProp_InNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InNames;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllActorsWithGivenObjectNames constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllActorsWithGivenObjectNames Property Definitions *****************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_InNames_Inner = { "InNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_InNames = { "InNames", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetAllActorsWithGivenObjectNames_Parms, InNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InNames_MetaData), NewProp_InNames_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetAllActorsWithGivenObjectNames_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAllActorsWithGivenObjectNames Property Definitions *******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBActorFunctions, nullptr, "GetAllActorsWithGivenObjectNames", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBActorFunctions_eventGetAllActorsWithGivenObjectNames_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBActorFunctions_eventGetAllActorsWithGivenObjectNames_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBActorFunctions_GetAllActorsWithGivenObjectNames(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBActorFunctions::execGetAllActorsWithGivenObjectNames)
{
	P_GET_TARRAY_REF(FString,Z_Param_Out_InNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=UMBActorFunctions::GetAllActorsWithGivenObjectNames(Z_Param_Out_InNames);
	P_NATIVE_END;
}
// ********** End Class UMBActorFunctions Function GetAllActorsWithGivenObjectNames ****************

// ********** Begin Class UMBActorFunctions Function GetAllModularActorsInWorld ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBActorFunctions_GetAllModularActorsInWorld_Statics
struct UHT_STATICS
{
	struct MBActorFunctions_eventGetAllModularActorsInWorld_Parms
	{
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBActor" },
		{ "Keywords", "Modular Actor" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllModularActorsInWorld constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllModularActorsInWorld constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllModularActorsInWorld Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetAllModularActorsInWorld_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAllModularActorsInWorld Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBActorFunctions, nullptr, "GetAllModularActorsInWorld", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBActorFunctions_eventGetAllModularActorsInWorld_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBActorFunctions_eventGetAllModularActorsInWorld_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBActorFunctions_GetAllModularActorsInWorld(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBActorFunctions::execGetAllModularActorsInWorld)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=UMBActorFunctions::GetAllModularActorsInWorld();
	P_NATIVE_END;
}
// ********** End Class UMBActorFunctions Function GetAllModularActorsInWorld **********************

// ********** Begin Class UMBActorFunctions Function GetBuildingCategory ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBActorFunctions_GetBuildingCategory_Statics
struct UHT_STATICS
{
	struct MBActorFunctions_eventGetBuildingCategory_Parms
	{
		const AActor* InActor;
		EBuildingCategory ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBActor" },
		{ "Keywords", "Modular Actor" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetBuildingCategory constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBuildingCategory constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBuildingCategory Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InActor = { "InActor", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetBuildingCategory_Parms, InActor), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InActor_MetaData), NewProp_InActor_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventGetBuildingCategory_Parms, ReturnValue), Z_Construct_UEnum_ModularBuilding_EBuildingCategory, METADATA_PARAMS(0, nullptr) }; // 07cf8117a6e577cac6ce1c747d6b11cc85196fdc
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetBuildingCategory Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBActorFunctions, nullptr, "GetBuildingCategory", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBActorFunctions_eventGetBuildingCategory_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBActorFunctions_eventGetBuildingCategory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBActorFunctions_GetBuildingCategory(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBActorFunctions::execGetBuildingCategory)
{
	P_GET_OBJECT(AActor,Z_Param_InActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EBuildingCategory*)Z_Param__Result=UMBActorFunctions::GetBuildingCategory(Z_Param_InActor);
	P_NATIVE_END;
}
// ********** End Class UMBActorFunctions Function GetBuildingCategory *****************************

// ********** Begin Class UMBActorFunctions Function IsActorFromTool *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBActorFunctions_IsActorFromTool_Statics
struct UHT_STATICS
{
	struct MBActorFunctions_eventIsActorFromTool_Parms
	{
		const AActor* InActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBActor" },
		{ "Keywords", "Modular Actor" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsActorFromTool constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActor;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MBActorFunctions_eventIsActorFromTool_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsActorFromTool constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsActorFromTool Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InActor = { "InActor", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MBActorFunctions_eventIsActorFromTool_Parms, InActor), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InActor_MetaData), NewProp_InActor_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(MBActorFunctions_eventIsActorFromTool_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsActorFromTool Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBActorFunctions, nullptr, "IsActorFromTool", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBActorFunctions_eventIsActorFromTool_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBActorFunctions_eventIsActorFromTool_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBActorFunctions_IsActorFromTool(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBActorFunctions::execIsActorFromTool)
{
	P_GET_OBJECT(AActor,Z_Param_InActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UMBActorFunctions::IsActorFromTool(Z_Param_InActor);
	P_NATIVE_END;
}
// ********** End Class UMBActorFunctions Function IsActorFromTool *********************************

// ********** Begin Class UMBActorFunctions ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBActorFunctions_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Libraries/MBActorFunctions.h" },
		{ "ModuleRelativePath", "Public/Libraries/MBActorFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBActorFunctions constinit property declarations ************************
// ********** End Class UMBActorFunctions constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("FilterForCategory"), .Pointer = &UMBActorFunctions::execFilterForCategory },
		{ .NameUTF8 = UTF8TEXT("FilterModularActors"), .Pointer = &UMBActorFunctions::execFilterModularActors },
		{ .NameUTF8 = UTF8TEXT("GetActorWithObjectName"), .Pointer = &UMBActorFunctions::execGetActorWithObjectName },
		{ .NameUTF8 = UTF8TEXT("GetAllActorsTransportPoint"), .Pointer = &UMBActorFunctions::execGetAllActorsTransportPoint },
		{ .NameUTF8 = UTF8TEXT("GetAllActorsTransportPointWithExtents"), .Pointer = &UMBActorFunctions::execGetAllActorsTransportPointWithExtents },
		{ .NameUTF8 = UTF8TEXT("GetAllActorsUnderTheFolderPath"), .Pointer = &UMBActorFunctions::execGetAllActorsUnderTheFolderPath },
		{ .NameUTF8 = UTF8TEXT("GetAllActorsWithGivenObjectNames"), .Pointer = &UMBActorFunctions::execGetAllActorsWithGivenObjectNames },
		{ .NameUTF8 = UTF8TEXT("GetAllModularActorsInWorld"), .Pointer = &UMBActorFunctions::execGetAllModularActorsInWorld },
		{ .NameUTF8 = UTF8TEXT("GetBuildingCategory"), .Pointer = &UMBActorFunctions::execGetBuildingCategory },
		{ .NameUTF8 = UTF8TEXT("IsActorFromTool"), .Pointer = &UMBActorFunctions::execIsActorFromTool },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBActorFunctions_FilterForCategory, "FilterForCategory" }, // 88e54daa36ee492fdd2d1250795efb267f83972f
		{ &Z_Construct_UFunction_UMBActorFunctions_FilterModularActors, "FilterModularActors" }, // 26611d219e765f4cc70405d55bc8935544aadee5
		{ &Z_Construct_UFunction_UMBActorFunctions_GetActorWithObjectName, "GetActorWithObjectName" }, // 14f0f20149a7552284588f938da2d27a19b9131f
		{ &Z_Construct_UFunction_UMBActorFunctions_GetAllActorsTransportPoint, "GetAllActorsTransportPoint" }, // 8243427aebe47837c52b36d4ab6c23d3d1065331
		{ &Z_Construct_UFunction_UMBActorFunctions_GetAllActorsTransportPointWithExtents, "GetAllActorsTransportPointWithExtents" }, // 03056ceaabd2667b1c819dd44efa8345e4407c1e
		{ &Z_Construct_UFunction_UMBActorFunctions_GetAllActorsUnderTheFolderPath, "GetAllActorsUnderTheFolderPath" }, // 2371a0f7cccd91739ba953adb214989fc61efe91
		{ &Z_Construct_UFunction_UMBActorFunctions_GetAllActorsWithGivenObjectNames, "GetAllActorsWithGivenObjectNames" }, // b6c2979a2161d7b53aa9e80434a2cfc3aaf934c5
		{ &Z_Construct_UFunction_UMBActorFunctions_GetAllModularActorsInWorld, "GetAllModularActorsInWorld" }, // e4959ecd5a5e8d7e37ae37ace6f193a54d5b6315
		{ &Z_Construct_UFunction_UMBActorFunctions_GetBuildingCategory, "GetBuildingCategory" }, // d3227f7d161716b2c564141b6f9881722f23af4f
		{ &Z_Construct_UFunction_UMBActorFunctions_IsActorFromTool, "IsActorFromTool" }, // ce7debc4e1cd84c910916a6d156d9e865cf7ccbc
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBActorFunctions>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UBlueprintFunctionLibrary,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBActorFunctions,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UMBActorFunctions_StaticRegisterNativesUMBActorFunctions()
{
	UClass* Class = UMBActorFunctions::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBActorFunctions;
UClass* Z_Construct_UClass_UMBActorFunctions(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBActorFunctions;
		if (!Z_Registration_Info_UClass_UMBActorFunctions.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBActorFunctions"),
				Z_Registration_Info_UClass_UMBActorFunctions.InnerSingleton,
				UMBActorFunctions_StaticRegisterNativesUMBActorFunctions,
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
		return Z_Registration_Info_UClass_UMBActorFunctions.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBActorFunctions.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBActorFunctions.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBActorFunctions.OuterSingleton;
}
#undef UHT_STATICS
UMBActorFunctions::UMBActorFunctions(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBActorFunctions);
UMBActorFunctions::~UMBActorFunctions() {}
// ********** End Class UMBActorFunctions **********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBActorFunctions, TEXT("UMBActorFunctions"), &Z_Registration_Info_UClass_UMBActorFunctions, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBActorFunctions), 2625984104U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h__Script_ModularBuilding_eaec046d09b3b900b9bf998fa06fcae8b9292716{
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
