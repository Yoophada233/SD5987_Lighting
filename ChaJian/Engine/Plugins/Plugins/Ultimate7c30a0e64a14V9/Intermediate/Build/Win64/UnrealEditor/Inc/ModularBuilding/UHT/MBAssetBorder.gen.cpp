// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBAssetBorder.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBAssetBorder() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D(ETypeConstructPhase);
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EHorizontalAlignment(ETypeConstructPhase);
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EVerticalAlignment(ETypeConstructPhase);
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin(ETypeConstructPhase);
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UContentWidget(ETypeConstructPhase);
UMG_API UFunction* Z_Construct_UDelegateFunction_UWidget_GetLinearColor__DelegateSignature(ETypeConstructPhase);
UMG_API UFunction* Z_Construct_UDelegateFunction_UWidget_GetSlateBrush__DelegateSignature(ETypeConstructPhase);
UMG_API UFunction* Z_Construct_UDelegateFunction_UWidget_OnPointerEvent__DelegateSignature(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USlateBrushAsset(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UTexture2D(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBAssetBorder(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBAssetBorder(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBAssetBorder Function GetDynamicMaterial *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_GetDynamicMaterial_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventGetDynamicMaterial_Parms
	{
		UMaterialInstanceDynamic* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/**  */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDynamicMaterial constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDynamicMaterial constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDynamicMaterial Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventGetDynamicMaterial_Parms, ReturnValue), Z_Construct_UClass_UMaterialInstanceDynamic, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetDynamicMaterial Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "GetDynamicMaterial", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventGetDynamicMaterial_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventGetDynamicMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_GetDynamicMaterial(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execGetDynamicMaterial)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UMaterialInstanceDynamic**)Z_Param__Result=P_THIS->GetDynamicMaterial();
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function GetDynamicMaterial *********************************

// ********** Begin Class UMBAssetBorder Function SetBrush *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_SetBrush_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventSetBrush_Parms
	{
		FSlateBrush InBrush;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/**  */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBrush_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBrush constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InBrush;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBrush constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBrush Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InBrush = { "InBrush", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventSetBrush_Parms, InBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBrush_MetaData), NewProp_InBrush_MetaData) }; // f1c9c1e4b09dc6483c33acb71e869f4a6352dbfa
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InBrush,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetBrush Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "SetBrush", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventSetBrush_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventSetBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_SetBrush(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execSetBrush)
{
	P_GET_STRUCT_REF(FSlateBrush,Z_Param_Out_InBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBrush(Z_Param_Out_InBrush);
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function SetBrush *******************************************

// ********** Begin Class UMBAssetBorder Function SetBrushColor ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_SetBrushColor_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventSetBrushColor_Parms
	{
		FLinearColor InBrushColor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/**  */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBrushColor constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InBrushColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBrushColor constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBrushColor Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InBrushColor = { "InBrushColor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventSetBrushColor_Parms, InBrushColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InBrushColor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetBrushColor Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "SetBrushColor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventSetBrushColor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventSetBrushColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_SetBrushColor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execSetBrushColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InBrushColor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBrushColor(Z_Param_InBrushColor);
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function SetBrushColor **************************************

// ********** Begin Class UMBAssetBorder Function SetBrushFromAsset ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_SetBrushFromAsset_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventSetBrushFromAsset_Parms
	{
		USlateBrushAsset* Asset;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/**  */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBrushFromAsset constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBrushFromAsset constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBrushFromAsset Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventSetBrushFromAsset_Parms, Asset), Z_Construct_UClass_USlateBrushAsset, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Asset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetBrushFromAsset Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "SetBrushFromAsset", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventSetBrushFromAsset_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventSetBrushFromAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_SetBrushFromAsset(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execSetBrushFromAsset)
{
	P_GET_OBJECT(USlateBrushAsset,Z_Param_Asset);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBrushFromAsset(Z_Param_Asset);
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function SetBrushFromAsset **********************************

// ********** Begin Class UMBAssetBorder Function SetBrushFromMaterial *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_SetBrushFromMaterial_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventSetBrushFromMaterial_Parms
	{
		UMaterialInterface* Material;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/**  */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBrushFromMaterial constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Material;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBrushFromMaterial constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBrushFromMaterial Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventSetBrushFromMaterial_Parms, Material), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Material,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetBrushFromMaterial Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "SetBrushFromMaterial", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventSetBrushFromMaterial_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventSetBrushFromMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_SetBrushFromMaterial(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execSetBrushFromMaterial)
{
	P_GET_OBJECT(UMaterialInterface,Z_Param_Material);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBrushFromMaterial(Z_Param_Material);
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function SetBrushFromMaterial *******************************

// ********** Begin Class UMBAssetBorder Function SetBrushFromTexture ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_SetBrushFromTexture_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventSetBrushFromTexture_Parms
	{
		UTexture2D* Texture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/**  */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBrushFromTexture constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBrushFromTexture constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBrushFromTexture Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventSetBrushFromTexture_Parms, Texture), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Texture,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetBrushFromTexture Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "SetBrushFromTexture", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventSetBrushFromTexture_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventSetBrushFromTexture_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_SetBrushFromTexture(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execSetBrushFromTexture)
{
	P_GET_OBJECT(UTexture2D,Z_Param_Texture);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBrushFromTexture(Z_Param_Texture);
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function SetBrushFromTexture ********************************

// ********** Begin Class UMBAssetBorder Function SetContentColorAndOpacity ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_SetContentColorAndOpacity_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventSetContentColorAndOpacity_Parms
	{
		FLinearColor InContentColorAndOpacity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/**  */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetContentColorAndOpacity constinit property declarations *************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InContentColorAndOpacity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetContentColorAndOpacity constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetContentColorAndOpacity Property Definitions ************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InContentColorAndOpacity = { "InContentColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventSetContentColorAndOpacity_Parms, InContentColorAndOpacity), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InContentColorAndOpacity,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetContentColorAndOpacity Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "SetContentColorAndOpacity", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventSetContentColorAndOpacity_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventSetContentColorAndOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_SetContentColorAndOpacity(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execSetContentColorAndOpacity)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InContentColorAndOpacity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetContentColorAndOpacity(Z_Param_InContentColorAndOpacity);
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function SetContentColorAndOpacity **************************

// ********** Begin Class UMBAssetBorder Function SetDesiredSizeScale ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_SetDesiredSizeScale_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventSetDesiredSizeScale_Parms
	{
		FVector2D InScale;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/**\n\x09* Sets the DesireSizeScale of this border.\n\x09*\n\x09* @param InScale    The X and Y multipliers for the desired size\n\x09*/" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "Sets the DesireSizeScale of this border.\n\n@param InScale    The X and Y multipliers for the desired size" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDesiredSizeScale constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InScale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDesiredSizeScale constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDesiredSizeScale Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InScale = { "InScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventSetDesiredSizeScale_Parms, InScale), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InScale,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetDesiredSizeScale Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "SetDesiredSizeScale", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventSetDesiredSizeScale_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventSetDesiredSizeScale_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_SetDesiredSizeScale(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execSetDesiredSizeScale)
{
	P_GET_STRUCT(FVector2D,Z_Param_InScale);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDesiredSizeScale(Z_Param_InScale);
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function SetDesiredSizeScale ********************************

// ********** Begin Class UMBAssetBorder Function SetHorizontalAlignment ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_SetHorizontalAlignment_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventSetHorizontalAlignment_Parms
	{
		TEnumAsByte<EHorizontalAlignment> InHorizontalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetHorizontalAlignment constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InHorizontalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetHorizontalAlignment constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetHorizontalAlignment Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InHorizontalAlignment = { "InHorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventSetHorizontalAlignment_Parms, InHorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(0, nullptr) }; // 3f023049cc80e43da7923f57b30f243ac6f1902f
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InHorizontalAlignment,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetHorizontalAlignment Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "SetHorizontalAlignment", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventSetHorizontalAlignment_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventSetHorizontalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_SetHorizontalAlignment(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execSetHorizontalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InHorizontalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHorizontalAlignment(EHorizontalAlignment(Z_Param_InHorizontalAlignment));
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function SetHorizontalAlignment *****************************

// ********** Begin Class UMBAssetBorder Function SetPadding ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_SetPadding_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventSetPadding_Parms
	{
		FMargin InPadding;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPadding constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InPadding;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPadding constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPadding Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InPadding = { "InPadding", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventSetPadding_Parms, InPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(0, nullptr) }; // e053c82a2bec9f2134e5372b3e38e80abbf94847
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InPadding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetPadding Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "SetPadding", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventSetPadding_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventSetPadding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_SetPadding(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execSetPadding)
{
	P_GET_STRUCT(FMargin,Z_Param_InPadding);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPadding(Z_Param_InPadding);
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function SetPadding *****************************************

// ********** Begin Class UMBAssetBorder Function SetVerticalAlignment *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetBorder_SetVerticalAlignment_Statics
struct UHT_STATICS
{
	struct MBAssetBorder_eventSetVerticalAlignment_Parms
	{
		TEnumAsByte<EVerticalAlignment> InVerticalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Appearance" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetVerticalAlignment constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InVerticalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVerticalAlignment constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVerticalAlignment Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InVerticalAlignment = { "InVerticalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetBorder_eventSetVerticalAlignment_Parms, InVerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(0, nullptr) }; // 31457a7d8127f9ca5ce4c7d034aca2357bf6c511
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InVerticalAlignment,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetVerticalAlignment Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetBorder, nullptr, "SetVerticalAlignment", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetBorder_eventSetVerticalAlignment_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetBorder_eventSetVerticalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetBorder_SetVerticalAlignment(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetBorder::execSetVerticalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InVerticalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVerticalAlignment(EVerticalAlignment(Z_Param_InVerticalAlignment));
	P_NATIVE_END;
}
// ********** End Class UMBAssetBorder Function SetVerticalAlignment *******************************

// ********** Begin Class UMBAssetBorder ***********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBAssetBorder_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/**\n * A border is a container widget that can contain one child widget, providing an opportunity \n * to surround it with a background image and adjustable padding.\n *\n * * Single Child\n * * Image\n */" },
		{ "IncludePath", "Slate/MBAssetBorder.h" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "A border is a container widget that can contain one child widget, providing an opportunity\nto surround it with a background image and adjustable padding.\n\n* Single Child\n* Image" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HorizontalAlignment_MetaData[] = {
		{ "Category", "Content" },
		{ "Comment", "/** The alignment of the content horizontally. */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "The alignment of the content horizontally." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VerticalAlignment_MetaData[] = {
		{ "Category", "Content" },
		{ "Comment", "/** The alignment of the content vertically. */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "The alignment of the content vertically." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowEffectWhenDisabled_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/** Whether or not to show the disabled effect when this border is disabled */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "Whether or not to show the disabled effect when this border is disabled" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContentColorAndOpacity_MetaData[] = {
		{ "Category", "Content" },
		{ "Comment", "/** Color and opacity multiplier of content in the border */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "sRGB", "true" },
		{ "ToolTip", "Color and opacity multiplier of content in the border" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContentColorAndOpacityDelegate_MetaData[] = {
		{ "Comment", "/** A bindable delegate for the ContentColorAndOpacity. */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "A bindable delegate for the ContentColorAndOpacity." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Padding_MetaData[] = {
		{ "Category", "Content" },
		{ "Comment", "/** The padding area between the slot and the content it contains. */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "The padding area between the slot and the content it contains." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Background_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/** Brush to drag as the background */" },
		{ "DisplayName", "Brush" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "Brush to drag as the background" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackgroundDelegate_MetaData[] = {
		{ "Comment", "/** A bindable delegate for the Brush. */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "A bindable delegate for the Brush." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrushColor_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/** Color and opacity of the actual border image */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "sRGB", "true" },
		{ "ToolTip", "Color and opacity of the actual border image" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrushColorDelegate_MetaData[] = {
		{ "Comment", "/** A bindable delegate for the BrushColor. */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "A bindable delegate for the BrushColor." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DesiredSizeScale_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "/**\n\x09 * Scales the computed desired size of this border and its contents. Useful\n\x09 * for making things that slide open without having to hard-code their size.\n\x09 * Note: if the parent widget is set up to ignore this widget's desired size,\n\x09 * then changing this value will have no effect.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "Scales the computed desired size of this border and its contents. Useful\nfor making things that slide open without having to hard-code their size.\nNote: if the parent widget is set up to ignore this widget's desired size,\nthen changing this value will have no effect." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFlipForRightToLeftFlowDirection_MetaData[] = {
		{ "Category", "Localization" },
		{ "Comment", "/** Flips the background image if the localization's flow direction is RightToLeft */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "Flips the background image if the localization's flow direction is RightToLeft" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMouseButtonDownEvent_MetaData[] = {
		{ "Category", "Events" },
		{ "IsBindableEvent", "True" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMouseButtonUpEvent_MetaData[] = {
		{ "Category", "Events" },
		{ "IsBindableEvent", "True" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMouseMoveEvent_MetaData[] = {
		{ "Category", "Events" },
		{ "IsBindableEvent", "True" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMouseDoubleClickEvent_MetaData[] = {
		{ "Category", "Events" },
		{ "IsBindableEvent", "True" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Brush_MetaData[] = {
		{ "Comment", "/** Image to use for the border */" },
		{ "ModuleRelativePath", "Public/Slate/MBAssetBorder.h" },
		{ "ToolTip", "Image to use for the border" },
	};
#endif // WITH_EDITORONLY_DATA
#endif // WITH_METADATA

// ********** Begin Class UMBAssetBorder constinit property declarations ***************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_HorizontalAlignment;
	static const UECodeGen_Private::FBytePropertyParams NewProp_VerticalAlignment;
	static void NewProp_bShowEffectWhenDisabled_SetBit(void* Obj)
	{
		((UMBAssetBorder*)Obj)->bShowEffectWhenDisabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowEffectWhenDisabled;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContentColorAndOpacity;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_ContentColorAndOpacityDelegate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Padding;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Background;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_BackgroundDelegate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BrushColor;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_BrushColorDelegate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DesiredSizeScale;
	static void NewProp_bFlipForRightToLeftFlowDirection_SetBit(void* Obj)
	{
		((UMBAssetBorder*)Obj)->bFlipForRightToLeftFlowDirection = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipForRightToLeftFlowDirection;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnMouseButtonDownEvent;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnMouseButtonUpEvent;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnMouseMoveEvent;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnMouseDoubleClickEvent;
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Brush;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBAssetBorder constinit property declarations *****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetDynamicMaterial"), .Pointer = &UMBAssetBorder::execGetDynamicMaterial },
		{ .NameUTF8 = UTF8TEXT("SetBrush"), .Pointer = &UMBAssetBorder::execSetBrush },
		{ .NameUTF8 = UTF8TEXT("SetBrushColor"), .Pointer = &UMBAssetBorder::execSetBrushColor },
		{ .NameUTF8 = UTF8TEXT("SetBrushFromAsset"), .Pointer = &UMBAssetBorder::execSetBrushFromAsset },
		{ .NameUTF8 = UTF8TEXT("SetBrushFromMaterial"), .Pointer = &UMBAssetBorder::execSetBrushFromMaterial },
		{ .NameUTF8 = UTF8TEXT("SetBrushFromTexture"), .Pointer = &UMBAssetBorder::execSetBrushFromTexture },
		{ .NameUTF8 = UTF8TEXT("SetContentColorAndOpacity"), .Pointer = &UMBAssetBorder::execSetContentColorAndOpacity },
		{ .NameUTF8 = UTF8TEXT("SetDesiredSizeScale"), .Pointer = &UMBAssetBorder::execSetDesiredSizeScale },
		{ .NameUTF8 = UTF8TEXT("SetHorizontalAlignment"), .Pointer = &UMBAssetBorder::execSetHorizontalAlignment },
		{ .NameUTF8 = UTF8TEXT("SetPadding"), .Pointer = &UMBAssetBorder::execSetPadding },
		{ .NameUTF8 = UTF8TEXT("SetVerticalAlignment"), .Pointer = &UMBAssetBorder::execSetVerticalAlignment },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBAssetBorder_GetDynamicMaterial, "GetDynamicMaterial" }, // d4b64ff78bf200248c914391ec17bb11910eae1d
		{ &Z_Construct_UFunction_UMBAssetBorder_SetBrush, "SetBrush" }, // 6d115db7697490a03a5741db6212ec42aad1cab1
		{ &Z_Construct_UFunction_UMBAssetBorder_SetBrushColor, "SetBrushColor" }, // ed277016f5de35000a4e1dd798c05c8067bd5ec5
		{ &Z_Construct_UFunction_UMBAssetBorder_SetBrushFromAsset, "SetBrushFromAsset" }, // f0d6f9bdcbe2fce67ab989a906212ce3a28c9207
		{ &Z_Construct_UFunction_UMBAssetBorder_SetBrushFromMaterial, "SetBrushFromMaterial" }, // 8b36054cb9fda2e422aacc827ec3ce0d03920fd1
		{ &Z_Construct_UFunction_UMBAssetBorder_SetBrushFromTexture, "SetBrushFromTexture" }, // 25495b2f2cb3d725b063ff6daa39be019533d049
		{ &Z_Construct_UFunction_UMBAssetBorder_SetContentColorAndOpacity, "SetContentColorAndOpacity" }, // 0d9b054e47c9df353623e6f1c6b9e41d9898132c
		{ &Z_Construct_UFunction_UMBAssetBorder_SetDesiredSizeScale, "SetDesiredSizeScale" }, // eff115c176fa4ff1e98264b53265e2a8c4f6ab8e
		{ &Z_Construct_UFunction_UMBAssetBorder_SetHorizontalAlignment, "SetHorizontalAlignment" }, // d2696a6235495086b74f1d7efaabd9034903bf95
		{ &Z_Construct_UFunction_UMBAssetBorder_SetPadding, "SetPadding" }, // ea05acf8005ea4063e05273a63013230f26a5b2e
		{ &Z_Construct_UFunction_UMBAssetBorder_SetVerticalAlignment, "SetVerticalAlignment" }, // d3056164ea2eadcab43a161f907ab64c3cb2a360
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBAssetBorder>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBAssetBorder Property Definitions **************************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_HorizontalAlignment = { "HorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, HorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HorizontalAlignment_MetaData), NewProp_HorizontalAlignment_MetaData) }; // 3f023049cc80e43da7923f57b30f243ac6f1902f
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_VerticalAlignment = { "VerticalAlignment", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, VerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VerticalAlignment_MetaData), NewProp_VerticalAlignment_MetaData) }; // 31457a7d8127f9ca5ce4c7d034aca2357bf6c511
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowEffectWhenDisabled = { "bShowEffectWhenDisabled", nullptr, (EPropertyFlags)0x0010040000000015, UECodeGen_Private::EPropertyGenFlags::Bool, nullptr, nullptr, 1, sizeof(uint8), sizeof(UMBAssetBorder), &UHT_STATICS::NewProp_bShowEffectWhenDisabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowEffectWhenDisabled_MetaData), NewProp_bShowEffectWhenDisabled_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ContentColorAndOpacity = { "ContentColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, ContentColorAndOpacity), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContentColorAndOpacity_MetaData), NewProp_ContentColorAndOpacity_MetaData) };
const UECodeGen_Private::FDelegatePropertyParams UHT_STATICS::NewProp_ContentColorAndOpacityDelegate = { "ContentColorAndOpacityDelegate", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::Delegate, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, ContentColorAndOpacityDelegate), Z_Construct_UDelegateFunction_UWidget_GetLinearColor__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContentColorAndOpacityDelegate_MetaData), NewProp_ContentColorAndOpacityDelegate_MetaData) }; // 5a52a94d6931015a0513df3efbd2cf05a542c15d
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Padding = { "Padding", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, Padding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Padding_MetaData), NewProp_Padding_MetaData) }; // e053c82a2bec9f2134e5372b3e38e80abbf94847
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Background = { "Background", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, Background), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Background_MetaData), NewProp_Background_MetaData) }; // f1c9c1e4b09dc6483c33acb71e869f4a6352dbfa
const UECodeGen_Private::FDelegatePropertyParams UHT_STATICS::NewProp_BackgroundDelegate = { "BackgroundDelegate", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::Delegate, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, BackgroundDelegate), Z_Construct_UDelegateFunction_UWidget_GetSlateBrush__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackgroundDelegate_MetaData), NewProp_BackgroundDelegate_MetaData) }; // 06a8695af1cb3c5c60c2ad081810aa1a1b893fcc
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_BrushColor = { "BrushColor", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, BrushColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrushColor_MetaData), NewProp_BrushColor_MetaData) };
const UECodeGen_Private::FDelegatePropertyParams UHT_STATICS::NewProp_BrushColorDelegate = { "BrushColorDelegate", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::Delegate, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, BrushColorDelegate), Z_Construct_UDelegateFunction_UWidget_GetLinearColor__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrushColorDelegate_MetaData), NewProp_BrushColorDelegate_MetaData) }; // 5a52a94d6931015a0513df3efbd2cf05a542c15d
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DesiredSizeScale = { "DesiredSizeScale", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, DesiredSizeScale), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DesiredSizeScale_MetaData), NewProp_DesiredSizeScale_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bFlipForRightToLeftFlowDirection = { "bFlipForRightToLeftFlowDirection", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBAssetBorder), &UHT_STATICS::NewProp_bFlipForRightToLeftFlowDirection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFlipForRightToLeftFlowDirection_MetaData), NewProp_bFlipForRightToLeftFlowDirection_MetaData) };
const UECodeGen_Private::FDelegatePropertyParams UHT_STATICS::NewProp_OnMouseButtonDownEvent = { "OnMouseButtonDownEvent", nullptr, (EPropertyFlags)0x0010000000080001, UECodeGen_Private::EPropertyGenFlags::Delegate, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, OnMouseButtonDownEvent), Z_Construct_UDelegateFunction_UWidget_OnPointerEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMouseButtonDownEvent_MetaData), NewProp_OnMouseButtonDownEvent_MetaData) }; // 665d1bb8ffd7d33bb69cf5e6f53ee7e5de9111c1
const UECodeGen_Private::FDelegatePropertyParams UHT_STATICS::NewProp_OnMouseButtonUpEvent = { "OnMouseButtonUpEvent", nullptr, (EPropertyFlags)0x0010000000080001, UECodeGen_Private::EPropertyGenFlags::Delegate, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, OnMouseButtonUpEvent), Z_Construct_UDelegateFunction_UWidget_OnPointerEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMouseButtonUpEvent_MetaData), NewProp_OnMouseButtonUpEvent_MetaData) }; // 665d1bb8ffd7d33bb69cf5e6f53ee7e5de9111c1
const UECodeGen_Private::FDelegatePropertyParams UHT_STATICS::NewProp_OnMouseMoveEvent = { "OnMouseMoveEvent", nullptr, (EPropertyFlags)0x0010000000080001, UECodeGen_Private::EPropertyGenFlags::Delegate, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, OnMouseMoveEvent), Z_Construct_UDelegateFunction_UWidget_OnPointerEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMouseMoveEvent_MetaData), NewProp_OnMouseMoveEvent_MetaData) }; // 665d1bb8ffd7d33bb69cf5e6f53ee7e5de9111c1
const UECodeGen_Private::FDelegatePropertyParams UHT_STATICS::NewProp_OnMouseDoubleClickEvent = { "OnMouseDoubleClickEvent", nullptr, (EPropertyFlags)0x0010000000080001, UECodeGen_Private::EPropertyGenFlags::Delegate, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, OnMouseDoubleClickEvent), Z_Construct_UDelegateFunction_UWidget_OnPointerEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMouseDoubleClickEvent_MetaData), NewProp_OnMouseDoubleClickEvent_MetaData) }; // 665d1bb8ffd7d33bb69cf5e6f53ee7e5de9111c1
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Brush = { "Brush", nullptr, (EPropertyFlags)0x0124080820000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBAssetBorder, Brush_DEPRECATED), Z_Construct_UClass_USlateBrushAsset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Brush_MetaData), NewProp_Brush_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HorizontalAlignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VerticalAlignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowEffectWhenDisabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ContentColorAndOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ContentColorAndOpacityDelegate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Padding,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Background,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BackgroundDelegate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BrushColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BrushColorDelegate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DesiredSizeScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bFlipForRightToLeftFlowDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnMouseButtonDownEvent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnMouseButtonUpEvent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnMouseMoveEvent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnMouseDoubleClickEvent,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Brush,
#endif // WITH_EDITORONLY_DATA
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBAssetBorder Property Definitions ****************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UContentWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBAssetBorder,
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
	0x00B000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UMBAssetBorder_StaticRegisterNativesUMBAssetBorder()
{
	UClass* Class = UMBAssetBorder::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBAssetBorder;
UClass* Z_Construct_UClass_UMBAssetBorder(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBAssetBorder;
		if (!Z_Registration_Info_UClass_UMBAssetBorder.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBAssetBorder"),
				Z_Registration_Info_UClass_UMBAssetBorder.InnerSingleton,
				UMBAssetBorder_StaticRegisterNativesUMBAssetBorder,
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
		return Z_Registration_Info_UClass_UMBAssetBorder.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBAssetBorder.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBAssetBorder.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBAssetBorder.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBAssetBorder);
UMBAssetBorder::~UMBAssetBorder() {}
// ********** End Class UMBAssetBorder *************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBAssetBorder, TEXT("UMBAssetBorder"), &Z_Registration_Info_UClass_UMBAssetBorder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBAssetBorder), 1136391887U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h__Script_ModularBuilding_8b5c976fc1d3f57a74e05c7a317a805a7ba135ce{
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
