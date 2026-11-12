// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBModularActorActionSettings.h"
#include "MBDataStructs.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBModularActorActionSettings() {}

// ********** Begin Cross Module References ********************************************************
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
SCRIPTABLEEDITORWIDGETS_API UClass* Z_Construct_UClass_UDetailsView(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UBorder(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UCheckBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UEditableTextBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FDuplicationData(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FDuplicationFilters(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBModularActorActionSettings(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBModularActorActionSettings(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBModularActorActionSettings Function ApplyBtnPressed *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_ApplyBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyBtnPressed constinit property declarations ***********************
// ********** End Function ApplyBtnPressed constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "ApplyBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_ApplyBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execApplyBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function ApplyBtnPressed *********************

// ********** Begin Class UMBModularActorActionSettings Function OnHoleCheckChanged ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnHoleCheckChanged_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnHoleCheckChanged_Parms
	{
		bool bInNewCondition;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnHoleCheckChanged constinit property declarations ********************
	static void NewProp_bInNewCondition_SetBit(void* Obj)
	{
		((MBModularActorActionSettings_eventOnHoleCheckChanged_Parms*)Obj)->bInNewCondition = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInNewCondition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnHoleCheckChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnHoleCheckChanged Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInNewCondition = { "bInNewCondition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(MBModularActorActionSettings_eventOnHoleCheckChanged_Parms), &UHT_STATICS::NewProp_bInNewCondition_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInNewCondition,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnHoleCheckChanged Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnHoleCheckChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnHoleCheckChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnHoleCheckChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnHoleCheckChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnHoleCheckChanged)
{
	P_GET_UBOOL(Z_Param_bInNewCondition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnHoleCheckChanged(Z_Param_bInNewCondition);
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnHoleCheckChanged ******************

// ********** Begin Class UMBModularActorActionSettings Function OnRectangleCheckChanged ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnRectangleCheckChanged_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnRectangleCheckChanged_Parms
	{
		bool bInNewCondition;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRectangleCheckChanged constinit property declarations ***************
	static void NewProp_bInNewCondition_SetBit(void* Obj)
	{
		((MBModularActorActionSettings_eventOnRectangleCheckChanged_Parms*)Obj)->bInNewCondition = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInNewCondition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnRectangleCheckChanged constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnRectangleCheckChanged Property Definitions **************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInNewCondition = { "bInNewCondition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(MBModularActorActionSettings_eventOnRectangleCheckChanged_Parms), &UHT_STATICS::NewProp_bInNewCondition_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInNewCondition,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnRectangleCheckChanged Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnRectangleCheckChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnRectangleCheckChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnRectangleCheckChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnRectangleCheckChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnRectangleCheckChanged)
{
	P_GET_UBOOL(Z_Param_bInNewCondition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRectangleCheckChanged(Z_Param_bInNewCondition);
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnRectangleCheckChanged *************

// ********** Begin Class UMBModularActorActionSettings Function OnXDirCheckChanged ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnXDirCheckChanged_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnXDirCheckChanged_Parms
	{
		bool bInNewCondition;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnXDirCheckChanged constinit property declarations ********************
	static void NewProp_bInNewCondition_SetBit(void* Obj)
	{
		((MBModularActorActionSettings_eventOnXDirCheckChanged_Parms*)Obj)->bInNewCondition = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInNewCondition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnXDirCheckChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnXDirCheckChanged Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInNewCondition = { "bInNewCondition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(MBModularActorActionSettings_eventOnXDirCheckChanged_Parms), &UHT_STATICS::NewProp_bInNewCondition_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInNewCondition,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnXDirCheckChanged Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnXDirCheckChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnXDirCheckChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnXDirCheckChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnXDirCheckChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnXDirCheckChanged)
{
	P_GET_UBOOL(Z_Param_bInNewCondition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnXDirCheckChanged(Z_Param_bInNewCondition);
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnXDirCheckChanged ******************

// ********** Begin Class UMBModularActorActionSettings Function OnXDupOffsetCommitted *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnXDupOffsetCommitted_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnXDupOffsetCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnXDupOffsetCommitted constinit property declarations *****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnXDupOffsetCommitted constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnXDupOffsetCommitted Property Definitions ****************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnXDupOffsetCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnXDupOffsetCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnXDupOffsetCommitted Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnXDupOffsetCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnXDupOffsetCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnXDupOffsetCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnXDupOffsetCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnXDupOffsetCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnXDupOffsetCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnXDupOffsetCommitted ***************

// ********** Begin Class UMBModularActorActionSettings Function OnXDupTextCommitted ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnXDupTextCommitted_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnXDupTextCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnXDupTextCommitted constinit property declarations *******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnXDupTextCommitted constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnXDupTextCommitted Property Definitions ******************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnXDupTextCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnXDupTextCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnXDupTextCommitted Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnXDupTextCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnXDupTextCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnXDupTextCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnXDupTextCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnXDupTextCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnXDupTextCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnXDupTextCommitted *****************

// ********** Begin Class UMBModularActorActionSettings Function OnYDirCheckChanged ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnYDirCheckChanged_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnYDirCheckChanged_Parms
	{
		bool bInNewCondition;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnYDirCheckChanged constinit property declarations ********************
	static void NewProp_bInNewCondition_SetBit(void* Obj)
	{
		((MBModularActorActionSettings_eventOnYDirCheckChanged_Parms*)Obj)->bInNewCondition = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInNewCondition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnYDirCheckChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnYDirCheckChanged Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInNewCondition = { "bInNewCondition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(MBModularActorActionSettings_eventOnYDirCheckChanged_Parms), &UHT_STATICS::NewProp_bInNewCondition_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInNewCondition,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnYDirCheckChanged Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnYDirCheckChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnYDirCheckChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnYDirCheckChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnYDirCheckChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnYDirCheckChanged)
{
	P_GET_UBOOL(Z_Param_bInNewCondition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnYDirCheckChanged(Z_Param_bInNewCondition);
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnYDirCheckChanged ******************

// ********** Begin Class UMBModularActorActionSettings Function OnYDupOffsetCommitted *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnYDupOffsetCommitted_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnYDupOffsetCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnYDupOffsetCommitted constinit property declarations *****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnYDupOffsetCommitted constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnYDupOffsetCommitted Property Definitions ****************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnYDupOffsetCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnYDupOffsetCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnYDupOffsetCommitted Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnYDupOffsetCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnYDupOffsetCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnYDupOffsetCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnYDupOffsetCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnYDupOffsetCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnYDupOffsetCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnYDupOffsetCommitted ***************

// ********** Begin Class UMBModularActorActionSettings Function OnYDupTextCommitted ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnYDupTextCommitted_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnYDupTextCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnYDupTextCommitted constinit property declarations *******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnYDupTextCommitted constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnYDupTextCommitted Property Definitions ******************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnYDupTextCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnYDupTextCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnYDupTextCommitted Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnYDupTextCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnYDupTextCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnYDupTextCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnYDupTextCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnYDupTextCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnYDupTextCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnYDupTextCommitted *****************

// ********** Begin Class UMBModularActorActionSettings Function OnZDirCheckChanged ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnZDirCheckChanged_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnZDirCheckChanged_Parms
	{
		bool bInNewCondition;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnZDirCheckChanged constinit property declarations ********************
	static void NewProp_bInNewCondition_SetBit(void* Obj)
	{
		((MBModularActorActionSettings_eventOnZDirCheckChanged_Parms*)Obj)->bInNewCondition = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInNewCondition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnZDirCheckChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnZDirCheckChanged Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInNewCondition = { "bInNewCondition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(MBModularActorActionSettings_eventOnZDirCheckChanged_Parms), &UHT_STATICS::NewProp_bInNewCondition_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInNewCondition,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnZDirCheckChanged Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnZDirCheckChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnZDirCheckChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnZDirCheckChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnZDirCheckChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnZDirCheckChanged)
{
	P_GET_UBOOL(Z_Param_bInNewCondition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnZDirCheckChanged(Z_Param_bInNewCondition);
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnZDirCheckChanged ******************

// ********** Begin Class UMBModularActorActionSettings Function OnZDupOffsetCommitted *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnZDupOffsetCommitted_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnZDupOffsetCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnZDupOffsetCommitted constinit property declarations *****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnZDupOffsetCommitted constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnZDupOffsetCommitted Property Definitions ****************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnZDupOffsetCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnZDupOffsetCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnZDupOffsetCommitted Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnZDupOffsetCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnZDupOffsetCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnZDupOffsetCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnZDupOffsetCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnZDupOffsetCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnZDupOffsetCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnZDupOffsetCommitted ***************

// ********** Begin Class UMBModularActorActionSettings Function OnZDupTextCommitted ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_OnZDupTextCommitted_Statics
struct UHT_STATICS
{
	struct MBModularActorActionSettings_eventOnZDupTextCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnZDupTextCommitted constinit property declarations *******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnZDupTextCommitted constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnZDupTextCommitted Property Definitions ******************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnZDupTextCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MBModularActorActionSettings_eventOnZDupTextCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnZDupTextCommitted Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "OnZDupTextCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBModularActorActionSettings_eventOnZDupTextCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBModularActorActionSettings_eventOnZDupTextCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_OnZDupTextCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execOnZDupTextCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnZDupTextCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function OnZDupTextCommitted *****************

// ********** Begin Class UMBModularActorActionSettings Function ResetDupBtnPressed ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModularActorActionSettings_ResetDupBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetDupBtnPressed constinit property declarations ********************
// ********** End Function ResetDupBtnPressed constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModularActorActionSettings, nullptr, "ResetDupBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBModularActorActionSettings_ResetDupBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModularActorActionSettings::execResetDupBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetDupBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMBModularActorActionSettings Function ResetDupBtnPressed ******************

// ********** Begin Class UMBModularActorActionSettings ********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBModularActorActionSettings_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/MBModularActorActionSettings.h" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApplyBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResetDupBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XDupText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YDupText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZDupText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XDupOffset_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YDupOffset_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZDupOffset_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XDirCheck_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YDirCheck_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZDirCheck_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HoleCheck_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RectangleCheck_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialAssignmentBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModActorActionDetails_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XDuplicationData_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YDuplicationData_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZDuplicationData_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DuplicationFilters_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModularActorActionSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBModularActorActionSettings constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ApplyBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ResetDupBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_XDupText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_YDupText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ZDupText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_XDupOffset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_YDupOffset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ZDupOffset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_XDirCheck;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_YDirCheck;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ZDirCheck;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HoleCheck;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RectangleCheck;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterialAssignmentBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ModActorActionDetails;
	static const UECodeGen_Private::FStructPropertyParams NewProp_XDuplicationData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_YDuplicationData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ZDuplicationData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DuplicationFilters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBModularActorActionSettings constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyBtnPressed"), .Pointer = &UMBModularActorActionSettings::execApplyBtnPressed },
		{ .NameUTF8 = UTF8TEXT("OnHoleCheckChanged"), .Pointer = &UMBModularActorActionSettings::execOnHoleCheckChanged },
		{ .NameUTF8 = UTF8TEXT("OnRectangleCheckChanged"), .Pointer = &UMBModularActorActionSettings::execOnRectangleCheckChanged },
		{ .NameUTF8 = UTF8TEXT("OnXDirCheckChanged"), .Pointer = &UMBModularActorActionSettings::execOnXDirCheckChanged },
		{ .NameUTF8 = UTF8TEXT("OnXDupOffsetCommitted"), .Pointer = &UMBModularActorActionSettings::execOnXDupOffsetCommitted },
		{ .NameUTF8 = UTF8TEXT("OnXDupTextCommitted"), .Pointer = &UMBModularActorActionSettings::execOnXDupTextCommitted },
		{ .NameUTF8 = UTF8TEXT("OnYDirCheckChanged"), .Pointer = &UMBModularActorActionSettings::execOnYDirCheckChanged },
		{ .NameUTF8 = UTF8TEXT("OnYDupOffsetCommitted"), .Pointer = &UMBModularActorActionSettings::execOnYDupOffsetCommitted },
		{ .NameUTF8 = UTF8TEXT("OnYDupTextCommitted"), .Pointer = &UMBModularActorActionSettings::execOnYDupTextCommitted },
		{ .NameUTF8 = UTF8TEXT("OnZDirCheckChanged"), .Pointer = &UMBModularActorActionSettings::execOnZDirCheckChanged },
		{ .NameUTF8 = UTF8TEXT("OnZDupOffsetCommitted"), .Pointer = &UMBModularActorActionSettings::execOnZDupOffsetCommitted },
		{ .NameUTF8 = UTF8TEXT("OnZDupTextCommitted"), .Pointer = &UMBModularActorActionSettings::execOnZDupTextCommitted },
		{ .NameUTF8 = UTF8TEXT("ResetDupBtnPressed"), .Pointer = &UMBModularActorActionSettings::execResetDupBtnPressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_ApplyBtnPressed, "ApplyBtnPressed" }, // 096a7c4d8b9b15638554f91f85d5937d652a65fc
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnHoleCheckChanged, "OnHoleCheckChanged" }, // 97a6d23c43b795f2493cca18a2bfdca97cde3f37
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnRectangleCheckChanged, "OnRectangleCheckChanged" }, // 379e538069d84bf4ebff9e2439baf28e4109fd43
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnXDirCheckChanged, "OnXDirCheckChanged" }, // 212bc40d9c342ded64f424cf602f2e1fde7a9d1c
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnXDupOffsetCommitted, "OnXDupOffsetCommitted" }, // 751c8bedba75e9ecf93360ec8f5542f8ce61c472
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnXDupTextCommitted, "OnXDupTextCommitted" }, // 5e5fe4e535bf8ca0934003ab6358155a4819b805
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnYDirCheckChanged, "OnYDirCheckChanged" }, // 696a8b444b7dcc8bfbd4322c496dae0d8365a003
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnYDupOffsetCommitted, "OnYDupOffsetCommitted" }, // 42eda1d6b3c4bfb21687a2d58f8e06b53b194ed2
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnYDupTextCommitted, "OnYDupTextCommitted" }, // 7d95102e4f9f6d115a3f8a0619822ef24837ddf1
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnZDirCheckChanged, "OnZDirCheckChanged" }, // ad07e855e8c8857d7d9279680bd3790ace62117f
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnZDupOffsetCommitted, "OnZDupOffsetCommitted" }, // 948cf1c88a1e1f72b0e189ea82d54cd86144316b
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_OnZDupTextCommitted, "OnZDupTextCommitted" }, // 08429d64db69fc554fc9967970173073e397f4dd
		{ &Z_Construct_UFunction_UMBModularActorActionSettings_ResetDupBtnPressed, "ResetDupBtnPressed" }, // 263f640da5e0f6fe81aa36033f9a818c50568b53
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBModularActorActionSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBModularActorActionSettings Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ApplyBtn = { "ApplyBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, ApplyBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApplyBtn_MetaData), NewProp_ApplyBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ResetDupBtn = { "ResetDupBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, ResetDupBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResetDupBtn_MetaData), NewProp_ResetDupBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_XDupText = { "XDupText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, XDupText), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XDupText_MetaData), NewProp_XDupText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_YDupText = { "YDupText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, YDupText), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YDupText_MetaData), NewProp_YDupText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ZDupText = { "ZDupText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, ZDupText), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZDupText_MetaData), NewProp_ZDupText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_XDupOffset = { "XDupOffset", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, XDupOffset), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XDupOffset_MetaData), NewProp_XDupOffset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_YDupOffset = { "YDupOffset", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, YDupOffset), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YDupOffset_MetaData), NewProp_YDupOffset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ZDupOffset = { "ZDupOffset", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, ZDupOffset), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZDupOffset_MetaData), NewProp_ZDupOffset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_XDirCheck = { "XDirCheck", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, XDirCheck), Z_Construct_UClass_UCheckBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XDirCheck_MetaData), NewProp_XDirCheck_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_YDirCheck = { "YDirCheck", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, YDirCheck), Z_Construct_UClass_UCheckBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YDirCheck_MetaData), NewProp_YDirCheck_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ZDirCheck = { "ZDirCheck", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, ZDirCheck), Z_Construct_UClass_UCheckBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZDirCheck_MetaData), NewProp_ZDirCheck_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HoleCheck = { "HoleCheck", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, HoleCheck), Z_Construct_UClass_UCheckBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HoleCheck_MetaData), NewProp_HoleCheck_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RectangleCheck = { "RectangleCheck", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, RectangleCheck), Z_Construct_UClass_UCheckBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RectangleCheck_MetaData), NewProp_RectangleCheck_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MaterialAssignmentBox = { "MaterialAssignmentBox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, MaterialAssignmentBox), Z_Construct_UClass_UBorder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialAssignmentBox_MetaData), NewProp_MaterialAssignmentBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ModActorActionDetails = { "ModActorActionDetails", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, ModActorActionDetails), Z_Construct_UClass_UDetailsView, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModActorActionDetails_MetaData), NewProp_ModActorActionDetails_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_XDuplicationData = { "XDuplicationData", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, XDuplicationData), Z_Construct_UScriptStruct_FDuplicationData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XDuplicationData_MetaData), NewProp_XDuplicationData_MetaData) }; // 62603a81de64ad7f08375f6aaa5834b14e33f1e6
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_YDuplicationData = { "YDuplicationData", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, YDuplicationData), Z_Construct_UScriptStruct_FDuplicationData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YDuplicationData_MetaData), NewProp_YDuplicationData_MetaData) }; // 62603a81de64ad7f08375f6aaa5834b14e33f1e6
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ZDuplicationData = { "ZDuplicationData", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, ZDuplicationData), Z_Construct_UScriptStruct_FDuplicationData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZDuplicationData_MetaData), NewProp_ZDuplicationData_MetaData) }; // 62603a81de64ad7f08375f6aaa5834b14e33f1e6
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DuplicationFilters = { "DuplicationFilters", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModularActorActionSettings, DuplicationFilters), Z_Construct_UScriptStruct_FDuplicationFilters, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DuplicationFilters_MetaData), NewProp_DuplicationFilters_MetaData) }; // 27c40ea3047e349dd8e589d1afd1c0d727fa8df7
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ApplyBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ResetDupBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_XDupText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_YDupText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ZDupText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_XDupOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_YDupOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ZDupOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_XDirCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_YDirCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ZDirCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HoleCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RectangleCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialAssignmentBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ModActorActionDetails,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_XDuplicationData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_YDuplicationData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ZDuplicationData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DuplicationFilters,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBModularActorActionSettings Property Definitions *************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBModularActorActionSettings,
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
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UMBModularActorActionSettings_StaticRegisterNativesUMBModularActorActionSettings()
{
	UClass* Class = UMBModularActorActionSettings::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBModularActorActionSettings;
UClass* Z_Construct_UClass_UMBModularActorActionSettings(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBModularActorActionSettings;
		if (!Z_Registration_Info_UClass_UMBModularActorActionSettings.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBModularActorActionSettings"),
				Z_Registration_Info_UClass_UMBModularActorActionSettings.InnerSingleton,
				UMBModularActorActionSettings_StaticRegisterNativesUMBModularActorActionSettings,
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
		return Z_Registration_Info_UClass_UMBModularActorActionSettings.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBModularActorActionSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBModularActorActionSettings.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBModularActorActionSettings.OuterSingleton;
}
#undef UHT_STATICS
UMBModularActorActionSettings::UMBModularActorActionSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBModularActorActionSettings);
UMBModularActorActionSettings::~UMBModularActorActionSettings() {}
// ********** End Class UMBModularActorActionSettings **********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBModularActorActionSettings_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBModularActorActionSettings, TEXT("UMBModularActorActionSettings"), &Z_Registration_Info_UClass_UMBModularActorActionSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBModularActorActionSettings), 449512551U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBModularActorActionSettings_h__Script_ModularBuilding_e1373752472712ade85ad98a2a655b78dc77028e{
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
