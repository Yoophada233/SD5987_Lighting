// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBExtendedMath.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBExtendedMath() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBAxis(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBExtendedMath(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBExtendedMath(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBExtendedMath Function GetAxisEnumOfDirectionVector ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBExtendedMath_GetAxisEnumOfDirectionVector_Statics
struct UHT_STATICS
{
	struct MBExtendedMath_eventGetAxisEnumOfDirectionVector_Parms
	{
		FVector InVector;
		EMBAxis ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBMath" },
		{ "Keywords", "Editor Math" },
		{ "ModuleRelativePath", "Public/Libraries/MBExtendedMath.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InVector_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAxisEnumOfDirectionVector constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_InVector;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAxisEnumOfDirectionVector constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAxisEnumOfDirectionVector Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InVector = { "InVector", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetAxisEnumOfDirectionVector_Parms, InVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InVector_MetaData), NewProp_InVector_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetAxisEnumOfDirectionVector_Parms, ReturnValue), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(0, nullptr) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InVector,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAxisEnumOfDirectionVector Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBExtendedMath, nullptr, "GetAxisEnumOfDirectionVector", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBExtendedMath_eventGetAxisEnumOfDirectionVector_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBExtendedMath_eventGetAxisEnumOfDirectionVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBExtendedMath_GetAxisEnumOfDirectionVector(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBExtendedMath::execGetAxisEnumOfDirectionVector)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_InVector);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EMBAxis*)Z_Param__Result=UMBExtendedMath::GetAxisEnumOfDirectionVector(Z_Param_Out_InVector);
	P_NATIVE_END;
}
// ********** End Class UMBExtendedMath Function GetAxisEnumOfDirectionVector **********************

// ********** Begin Class UMBExtendedMath Function GetAxisOfVector *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBExtendedMath_GetAxisOfVector_Statics
struct UHT_STATICS
{
	struct MBExtendedMath_eventGetAxisOfVector_Parms
	{
		EMBAxis InAxis;
		FVector InVector;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBMath" },
		{ "Keywords", "Editor Math" },
		{ "ModuleRelativePath", "Public/Libraries/MBExtendedMath.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InAxis_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InVector_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAxisOfVector constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InAxis;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InVector;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAxisOfVector constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAxisOfVector Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InAxis = { "InAxis", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetAxisOfVector_Parms, InAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InAxis_MetaData), NewProp_InAxis_MetaData) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InVector = { "InVector", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetAxisOfVector_Parms, InVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InVector_MetaData), NewProp_InVector_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetAxisOfVector_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InVector,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAxisOfVector Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBExtendedMath, nullptr, "GetAxisOfVector", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBExtendedMath_eventGetAxisOfVector_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBExtendedMath_eventGetAxisOfVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBExtendedMath_GetAxisOfVector(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBExtendedMath::execGetAxisOfVector)
{
	P_GET_ENUM(EMBAxis,Z_Param_InAxis);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_InVector);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UMBExtendedMath::GetAxisOfVector(EMBAxis(Z_Param_InAxis),Z_Param_Out_InVector);
	P_NATIVE_END;
}
// ********** End Class UMBExtendedMath Function GetAxisOfVector ***********************************

// ********** Begin Class UMBExtendedMath Function GetAxisVectorWithEnumValue **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBExtendedMath_GetAxisVectorWithEnumValue_Statics
struct UHT_STATICS
{
	struct MBExtendedMath_eventGetAxisVectorWithEnumValue_Parms
	{
		EMBAxis InAxis;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBMath" },
		{ "Keywords", "Editor Math" },
		{ "ModuleRelativePath", "Public/Libraries/MBExtendedMath.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InAxis_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAxisVectorWithEnumValue constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InAxis;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAxisVectorWithEnumValue constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAxisVectorWithEnumValue Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InAxis = { "InAxis", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetAxisVectorWithEnumValue_Parms, InAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InAxis_MetaData), NewProp_InAxis_MetaData) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetAxisVectorWithEnumValue_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAxisVectorWithEnumValue Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBExtendedMath, nullptr, "GetAxisVectorWithEnumValue", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBExtendedMath_eventGetAxisVectorWithEnumValue_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBExtendedMath_eventGetAxisVectorWithEnumValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBExtendedMath_GetAxisVectorWithEnumValue(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBExtendedMath::execGetAxisVectorWithEnumValue)
{
	P_GET_ENUM_REF(EMBAxis,Z_Param_Out_InAxis);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UMBExtendedMath::GetAxisVectorWithEnumValue((EMBAxis&)(Z_Param_Out_InAxis));
	P_NATIVE_END;
}
// ********** End Class UMBExtendedMath Function GetAxisVectorWithEnumValue ************************

// ********** Begin Class UMBExtendedMath Function GetHighestAxisAndDirectionOfVector **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBExtendedMath_GetHighestAxisAndDirectionOfVector_Statics
struct UHT_STATICS
{
	struct MBExtendedMath_eventGetHighestAxisAndDirectionOfVector_Parms
	{
		FVector InVector;
		EMBAxis OutAxis;
		bool OutDirection;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBMath" },
		{ "Keywords", "Editor Math" },
		{ "ModuleRelativePath", "Public/Libraries/MBExtendedMath.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InVector_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetHighestAxisAndDirectionOfVector constinit property declarations ****
	static const UECodeGen_Private::FStructPropertyParams NewProp_InVector;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OutAxis;
	static void NewProp_OutDirection_SetBit(void* Obj)
	{
		((MBExtendedMath_eventGetHighestAxisAndDirectionOfVector_Parms*)Obj)->OutDirection = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_OutDirection;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHighestAxisAndDirectionOfVector constinit property declarations ******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHighestAxisAndDirectionOfVector Property Definitions ***************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InVector = { "InVector", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetHighestAxisAndDirectionOfVector_Parms, InVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InVector_MetaData), NewProp_InVector_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_OutAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_OutAxis = { "OutAxis", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetHighestAxisAndDirectionOfVector_Parms, OutAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(0, nullptr) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_OutDirection = { "OutDirection", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(MBExtendedMath_eventGetHighestAxisAndDirectionOfVector_Parms), &UHT_STATICS::NewProp_OutDirection_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InVector,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutDirection,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetHighestAxisAndDirectionOfVector Property Definitions *****************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBExtendedMath, nullptr, "GetHighestAxisAndDirectionOfVector", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBExtendedMath_eventGetHighestAxisAndDirectionOfVector_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBExtendedMath_eventGetHighestAxisAndDirectionOfVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBExtendedMath_GetHighestAxisAndDirectionOfVector(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBExtendedMath::execGetHighestAxisAndDirectionOfVector)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_InVector);
	P_GET_ENUM_REF(EMBAxis,Z_Param_Out_OutAxis);
	P_GET_UBOOL_REF(Z_Param_Out_OutDirection);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMBExtendedMath::GetHighestAxisAndDirectionOfVector(Z_Param_Out_InVector,(EMBAxis&)(Z_Param_Out_OutAxis),Z_Param_Out_OutDirection);
	P_NATIVE_END;
}
// ********** End Class UMBExtendedMath Function GetHighestAxisAndDirectionOfVector ****************

// ********** Begin Class UMBExtendedMath Function GetNearestAxisOfVector **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBExtendedMath_GetNearestAxisOfVector_Statics
struct UHT_STATICS
{
	struct MBExtendedMath_eventGetNearestAxisOfVector_Parms
	{
		FVector InVector;
		EMBAxis OutAxis;
		FVector OutDirection;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBMath" },
		{ "Keywords", "Editor Math" },
		{ "ModuleRelativePath", "Public/Libraries/MBExtendedMath.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InVector_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetNearestAxisOfVector constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InVector;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OutAxis;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutDirection;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNearestAxisOfVector constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNearestAxisOfVector Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InVector = { "InVector", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetNearestAxisOfVector_Parms, InVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InVector_MetaData), NewProp_InVector_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_OutAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_OutAxis = { "OutAxis", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetNearestAxisOfVector_Parms, OutAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(0, nullptr) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OutDirection = { "OutDirection", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetNearestAxisOfVector_Parms, OutDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InVector,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutDirection,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetNearestAxisOfVector Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBExtendedMath, nullptr, "GetNearestAxisOfVector", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBExtendedMath_eventGetNearestAxisOfVector_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBExtendedMath_eventGetNearestAxisOfVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBExtendedMath_GetNearestAxisOfVector(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBExtendedMath::execGetNearestAxisOfVector)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_InVector);
	P_GET_ENUM_REF(EMBAxis,Z_Param_Out_OutAxis);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutDirection);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMBExtendedMath::GetNearestAxisOfVector(Z_Param_Out_InVector,(EMBAxis&)(Z_Param_Out_OutAxis),Z_Param_Out_OutDirection);
	P_NATIVE_END;
}
// ********** End Class UMBExtendedMath Function GetNearestAxisOfVector ****************************

// ********** Begin Class UMBExtendedMath Function GetSecAxis **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBExtendedMath_GetSecAxis_Statics
struct UHT_STATICS
{
	struct MBExtendedMath_eventGetSecAxis_Parms
	{
		EMBAxis InWorkingAxis;
		EMBAxis InBlockedAxis;
		EMBAxis ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBMath" },
		{ "Keywords", "Editor Math" },
		{ "ModuleRelativePath", "Public/Libraries/MBExtendedMath.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InWorkingAxis_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBlockedAxis_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSecAxis constinit property declarations ****************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InWorkingAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InWorkingAxis;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InBlockedAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InBlockedAxis;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSecAxis constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSecAxis Property Definitions ***************************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InWorkingAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InWorkingAxis = { "InWorkingAxis", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetSecAxis_Parms, InWorkingAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InWorkingAxis_MetaData), NewProp_InWorkingAxis_MetaData) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InBlockedAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InBlockedAxis = { "InBlockedAxis", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetSecAxis_Parms, InBlockedAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBlockedAxis_MetaData), NewProp_InBlockedAxis_MetaData) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventGetSecAxis_Parms, ReturnValue), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(0, nullptr) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InWorkingAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InWorkingAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InBlockedAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InBlockedAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSecAxis Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBExtendedMath, nullptr, "GetSecAxis", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBExtendedMath_eventGetSecAxis_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBExtendedMath_eventGetSecAxis_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBExtendedMath_GetSecAxis(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBExtendedMath::execGetSecAxis)
{
	P_GET_ENUM_REF(EMBAxis,Z_Param_Out_InWorkingAxis);
	P_GET_ENUM_REF(EMBAxis,Z_Param_Out_InBlockedAxis);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EMBAxis*)Z_Param__Result=UMBExtendedMath::GetSecAxis((EMBAxis&)(Z_Param_Out_InWorkingAxis),(EMBAxis&)(Z_Param_Out_InBlockedAxis));
	P_NATIVE_END;
}
// ********** End Class UMBExtendedMath Function GetSecAxis ****************************************

// ********** Begin Class UMBExtendedMath Function SetAxisOfVector *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBExtendedMath_SetAxisOfVector_Statics
struct UHT_STATICS
{
	struct MBExtendedMath_eventSetAxisOfVector_Parms
	{
		EMBAxis InAxis;
		FVector InVector;
		float InNewValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor/MBMath" },
		{ "Keywords", "Editor Math" },
		{ "ModuleRelativePath", "Public/Libraries/MBExtendedMath.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InAxis_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InNewValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAxisOfVector constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InAxis;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InVector;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InNewValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAxisOfVector constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAxisOfVector Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InAxis = { "InAxis", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventSetAxisOfVector_Parms, InAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InAxis_MetaData), NewProp_InAxis_MetaData) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InVector = { "InVector", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventSetAxisOfVector_Parms, InVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InNewValue = { "InNewValue", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(MBExtendedMath_eventSetAxisOfVector_Parms, InNewValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InNewValue_MetaData), NewProp_InNewValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InVector,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InNewValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetAxisOfVector Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBExtendedMath, nullptr, "SetAxisOfVector", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBExtendedMath_eventSetAxisOfVector_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBExtendedMath_eventSetAxisOfVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBExtendedMath_SetAxisOfVector(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBExtendedMath::execSetAxisOfVector)
{
	P_GET_ENUM(EMBAxis,Z_Param_InAxis);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_InVector);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_InNewValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMBExtendedMath::SetAxisOfVector(EMBAxis(Z_Param_InAxis),Z_Param_Out_InVector,Z_Param_Out_InNewValue);
	P_NATIVE_END;
}
// ********** End Class UMBExtendedMath Function SetAxisOfVector ***********************************

// ********** Begin Class UMBExtendedMath **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBExtendedMath_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Libraries/MBExtendedMath.h" },
		{ "ModuleRelativePath", "Public/Libraries/MBExtendedMath.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBExtendedMath constinit property declarations **************************
// ********** End Class UMBExtendedMath constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetAxisEnumOfDirectionVector"), .Pointer = &UMBExtendedMath::execGetAxisEnumOfDirectionVector },
		{ .NameUTF8 = UTF8TEXT("GetAxisOfVector"), .Pointer = &UMBExtendedMath::execGetAxisOfVector },
		{ .NameUTF8 = UTF8TEXT("GetAxisVectorWithEnumValue"), .Pointer = &UMBExtendedMath::execGetAxisVectorWithEnumValue },
		{ .NameUTF8 = UTF8TEXT("GetHighestAxisAndDirectionOfVector"), .Pointer = &UMBExtendedMath::execGetHighestAxisAndDirectionOfVector },
		{ .NameUTF8 = UTF8TEXT("GetNearestAxisOfVector"), .Pointer = &UMBExtendedMath::execGetNearestAxisOfVector },
		{ .NameUTF8 = UTF8TEXT("GetSecAxis"), .Pointer = &UMBExtendedMath::execGetSecAxis },
		{ .NameUTF8 = UTF8TEXT("SetAxisOfVector"), .Pointer = &UMBExtendedMath::execSetAxisOfVector },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBExtendedMath_GetAxisEnumOfDirectionVector, "GetAxisEnumOfDirectionVector" }, // 6c89d57552c54ed94cab3da449b868ad33c2421e
		{ &Z_Construct_UFunction_UMBExtendedMath_GetAxisOfVector, "GetAxisOfVector" }, // 2c5ddd2fa7cb06b39f74422acbc014aa060cc8bc
		{ &Z_Construct_UFunction_UMBExtendedMath_GetAxisVectorWithEnumValue, "GetAxisVectorWithEnumValue" }, // 757c6cd14ce06e28afb3245f1621f5bdbdbcc26b
		{ &Z_Construct_UFunction_UMBExtendedMath_GetHighestAxisAndDirectionOfVector, "GetHighestAxisAndDirectionOfVector" }, // 88ea612652d4be20030977b4059a142057fb4464
		{ &Z_Construct_UFunction_UMBExtendedMath_GetNearestAxisOfVector, "GetNearestAxisOfVector" }, // 5f8e7c5611446b588618bafa383d46b47dda9254
		{ &Z_Construct_UFunction_UMBExtendedMath_GetSecAxis, "GetSecAxis" }, // 9377af5590cf59bcc4b45c00321e09c475604b82
		{ &Z_Construct_UFunction_UMBExtendedMath_SetAxisOfVector, "SetAxisOfVector" }, // 3bb9fc69f7a8c667a771bbe994b5d8cee5df274b
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBExtendedMath>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UBlueprintFunctionLibrary,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBExtendedMath,
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
static void UMBExtendedMath_StaticRegisterNativesUMBExtendedMath()
{
	UClass* Class = UMBExtendedMath::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBExtendedMath;
UClass* Z_Construct_UClass_UMBExtendedMath(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBExtendedMath;
		if (!Z_Registration_Info_UClass_UMBExtendedMath.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBExtendedMath"),
				Z_Registration_Info_UClass_UMBExtendedMath.InnerSingleton,
				UMBExtendedMath_StaticRegisterNativesUMBExtendedMath,
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
		return Z_Registration_Info_UClass_UMBExtendedMath.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBExtendedMath.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBExtendedMath.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBExtendedMath.OuterSingleton;
}
#undef UHT_STATICS
UMBExtendedMath::UMBExtendedMath(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBExtendedMath);
UMBExtendedMath::~UMBExtendedMath() {}
// ********** End Class UMBExtendedMath ************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBExtendedMath, TEXT("UMBExtendedMath"), &Z_Registration_Info_UClass_UMBExtendedMath, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBExtendedMath), 2387072193U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h__Script_ModularBuilding_3beb56b372700d04257ae32d1ca0462a25429e42{
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
