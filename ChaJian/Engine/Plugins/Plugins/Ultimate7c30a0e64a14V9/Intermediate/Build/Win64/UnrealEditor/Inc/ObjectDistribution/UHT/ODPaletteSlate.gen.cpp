// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODPaletteSlate.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODPaletteSlate() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D(ETypeConstructPhase);
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EHorizontalAlignment(ETypeConstructPhase);
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EOrientation(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UPanelWidget(ETypeConstructPhase);
SCRIPTABLEEDITORWIDGETS_API UClass* Z_Construct_UClass_UDetailsView(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UWrapBoxSlot(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODPaletteSlate(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODPaletteDataObject(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODPaletteSlate(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODToolSubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODPaletteSlate Function AddChildToWrapBox *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODPaletteSlate_AddChildToWrapBox_Statics
struct UHT_STATICS
{
	struct ODPaletteSlate_eventAddChildToWrapBox_Parms
	{
		UWidget* Content;
		UWrapBoxSlot* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Panel" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Content_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddChildToWrapBox constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Content;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddChildToWrapBox constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddChildToWrapBox Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Content = { "Content", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ODPaletteSlate_eventAddChildToWrapBox_Parms, Content), Z_Construct_UClass_UWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Content_MetaData), NewProp_Content_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ODPaletteSlate_eventAddChildToWrapBox_Parms, ReturnValue), Z_Construct_UClass_UWrapBoxSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Content,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddChildToWrapBox Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODPaletteSlate, nullptr, "AddChildToWrapBox", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODPaletteSlate_eventAddChildToWrapBox_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODPaletteSlate_eventAddChildToWrapBox_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODPaletteSlate_AddChildToWrapBox(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODPaletteSlate::execAddChildToWrapBox)
{
	P_GET_OBJECT(UWidget,Z_Param_Content);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UWrapBoxSlot**)Z_Param__Result=P_THIS->AddChildToWrapBox(Z_Param_Content);
	P_NATIVE_END;
}
// ********** End Class UODPaletteSlate Function AddChildToWrapBox *********************************

// ********** Begin Class UODPaletteSlate Function SetHorizontalAlignment **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODPaletteSlate_SetHorizontalAlignment_Statics
struct UHT_STATICS
{
	struct ODPaletteSlate_eventSetHorizontalAlignment_Parms
	{
		TEnumAsByte<EHorizontalAlignment> InHorizontalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Content Layout" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetHorizontalAlignment constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InHorizontalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetHorizontalAlignment constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetHorizontalAlignment Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InHorizontalAlignment = { "InHorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ODPaletteSlate_eventSetHorizontalAlignment_Parms, InHorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(0, nullptr) }; // 3f023049cc80e43da7923f57b30f243ac6f1902f
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InHorizontalAlignment,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetHorizontalAlignment Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODPaletteSlate, nullptr, "SetHorizontalAlignment", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODPaletteSlate_eventSetHorizontalAlignment_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODPaletteSlate_eventSetHorizontalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODPaletteSlate_SetHorizontalAlignment(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODPaletteSlate::execSetHorizontalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InHorizontalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHorizontalAlignment(EHorizontalAlignment(Z_Param_InHorizontalAlignment));
	P_NATIVE_END;
}
// ********** End Class UODPaletteSlate Function SetHorizontalAlignment ****************************

// ********** Begin Class UODPaletteSlate Function SetInnerSlotPadding *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODPaletteSlate_SetInnerSlotPadding_Statics
struct UHT_STATICS
{
	struct ODPaletteSlate_eventSetInnerSlotPadding_Parms
	{
		FVector2D InPadding;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Content Layout" },
		{ "Comment", "/** Sets the inner slot padding goes between slots sharing borders */" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
		{ "ToolTip", "Sets the inner slot padding goes between slots sharing borders" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetInnerSlotPadding constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InPadding;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetInnerSlotPadding constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetInnerSlotPadding Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InPadding = { "InPadding", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ODPaletteSlate_eventSetInnerSlotPadding_Parms, InPadding), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InPadding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetInnerSlotPadding Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODPaletteSlate, nullptr, "SetInnerSlotPadding", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODPaletteSlate_eventSetInnerSlotPadding_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODPaletteSlate_eventSetInnerSlotPadding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODPaletteSlate_SetInnerSlotPadding(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODPaletteSlate::execSetInnerSlotPadding)
{
	P_GET_STRUCT(FVector2D,Z_Param_InPadding);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetInnerSlotPadding(Z_Param_InPadding);
	P_NATIVE_END;
}
// ********** End Class UODPaletteSlate Function SetInnerSlotPadding *******************************

// ********** Begin Class UODPaletteSlate **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODPaletteSlate_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/ODPaletteSlate.h" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InnerSlotPadding_MetaData[] = {
		{ "Category", "Content Layout" },
		{ "Comment", "/** The inner slot padding goes between slots sharing borders */" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
		{ "ToolTip", "The inner slot padding goes between slots sharing borders" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WrapSize_MetaData[] = {
		{ "Category", "Content Layout" },
		{ "Comment", "/** When this size is exceeded, elements will start appearing on the next line. */" },
		{ "EditCondition", "bExplicitWrapSize" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
		{ "ToolTip", "When this size is exceeded, elements will start appearing on the next line." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bExplicitWrapSize_MetaData[] = {
		{ "Category", "Content Layout" },
		{ "Comment", "/** Use explicit wrap size whenever possible. It greatly simplifies layout calculations and reduces likelihood of \"wiggling UI\" */" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
		{ "ToolTip", "Use explicit wrap size whenever possible. It greatly simplifies layout calculations and reduces likelihood of \"wiggling UI\"" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HorizontalAlignment_MetaData[] = {
		{ "Category", "Content Layout" },
		{ "Comment", "/** The alignment of each line of wrapped content. */" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
		{ "ToolTip", "The alignment of each line of wrapped content." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[] = {
		{ "Category", "Content Layout" },
		{ "Comment", "/** Determines if the Wrap Box should arranges the widgets left-to-right or top-to-bottom */" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
		{ "ToolTip", "Determines if the Wrap Box should arranges the widgets left-to-right or top-to-bottom" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PaletteDataObject_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PaletteObjectDataDetails_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropDistributionDetails_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODPaletteSlate.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODPaletteSlate constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToolSubsystem;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InnerSlotPadding;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WrapSize;
	static void NewProp_bExplicitWrapSize_SetBit(void* Obj)
	{
		((UODPaletteSlate*)Obj)->bExplicitWrapSize = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bExplicitWrapSize;
	static const UECodeGen_Private::FBytePropertyParams NewProp_HorizontalAlignment;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Orientation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PaletteDataObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PaletteObjectDataDetails;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PropDistributionDetails;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODPaletteSlate constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddChildToWrapBox"), .Pointer = &UODPaletteSlate::execAddChildToWrapBox },
		{ .NameUTF8 = UTF8TEXT("SetHorizontalAlignment"), .Pointer = &UODPaletteSlate::execSetHorizontalAlignment },
		{ .NameUTF8 = UTF8TEXT("SetInnerSlotPadding"), .Pointer = &UODPaletteSlate::execSetInnerSlotPadding },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UODPaletteSlate_AddChildToWrapBox, "AddChildToWrapBox" }, // 1a6c0ffac7c0ab3ccbd91ff84a4f0b1e4fc84f07
		{ &Z_Construct_UFunction_UODPaletteSlate_SetHorizontalAlignment, "SetHorizontalAlignment" }, // 8bf7106e2a3513e2453d77f8d8c560437302b0fb
		{ &Z_Construct_UFunction_UODPaletteSlate_SetInnerSlotPadding, "SetInnerSlotPadding" }, // b98ef5f2bd47b031b9ee2a7737a3e17f0d163aab
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODPaletteSlate>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODPaletteSlate Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ToolSubsystem = { "ToolSubsystem", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteSlate, ToolSubsystem), Z_Construct_UClass_UODToolSubsystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolSubsystem_MetaData), NewProp_ToolSubsystem_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InnerSlotPadding = { "InnerSlotPadding", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteSlate, InnerSlotPadding), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InnerSlotPadding_MetaData), NewProp_InnerSlotPadding_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_WrapSize = { "WrapSize", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteSlate, WrapSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WrapSize_MetaData), NewProp_WrapSize_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bExplicitWrapSize = { "bExplicitWrapSize", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODPaletteSlate), &UHT_STATICS::NewProp_bExplicitWrapSize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bExplicitWrapSize_MetaData), NewProp_bExplicitWrapSize_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_HorizontalAlignment = { "HorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteSlate, HorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HorizontalAlignment_MetaData), NewProp_HorizontalAlignment_MetaData) }; // 3f023049cc80e43da7923f57b30f243ac6f1902f
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteSlate, Orientation), Z_Construct_UEnum_SlateCore_EOrientation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orientation_MetaData), NewProp_Orientation_MetaData) }; // f79ba0f256ae50762653c0ab3a2c37fcce3e74b1
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PaletteDataObject = { "PaletteDataObject", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteSlate, PaletteDataObject), Z_Construct_UClass_UODPaletteDataObject, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PaletteDataObject_MetaData), NewProp_PaletteDataObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PaletteObjectDataDetails = { "PaletteObjectDataDetails", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteSlate, PaletteObjectDataDetails), Z_Construct_UClass_UDetailsView, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PaletteObjectDataDetails_MetaData), NewProp_PaletteObjectDataDetails_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PropDistributionDetails = { "PropDistributionDetails", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteSlate, PropDistributionDetails), Z_Construct_UClass_UDetailsView, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropDistributionDetails_MetaData), NewProp_PropDistributionDetails_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ToolSubsystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InnerSlotPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WrapSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bExplicitWrapSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HorizontalAlignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Orientation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PaletteDataObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PaletteObjectDataDetails,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PropDistributionDetails,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODPaletteSlate Property Definitions ***************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UPanelWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODPaletteSlate,
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
static void UODPaletteSlate_StaticRegisterNativesUODPaletteSlate()
{
	UClass* Class = UODPaletteSlate::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UODPaletteSlate;
UClass* Z_Construct_UClass_UODPaletteSlate(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODPaletteSlate;
		if (!Z_Registration_Info_UClass_UODPaletteSlate.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODPaletteSlate"),
				Z_Registration_Info_UClass_UODPaletteSlate.InnerSingleton,
				UODPaletteSlate_StaticRegisterNativesUODPaletteSlate,
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
		return Z_Registration_Info_UClass_UODPaletteSlate.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODPaletteSlate.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODPaletteSlate.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODPaletteSlate.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODPaletteSlate);
UODPaletteSlate::~UODPaletteSlate() {}
// ********** End Class UODPaletteSlate ************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_UI_ODPaletteSlate_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODPaletteSlate, TEXT("UODPaletteSlate"), &Z_Registration_Info_UClass_UODPaletteSlate, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODPaletteSlate), 1592562229U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_UI_ODPaletteSlate_h__Script_ObjectDistribution_e4bbf05a04da5d8a5525c629cc2c7df427ac956c{
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
