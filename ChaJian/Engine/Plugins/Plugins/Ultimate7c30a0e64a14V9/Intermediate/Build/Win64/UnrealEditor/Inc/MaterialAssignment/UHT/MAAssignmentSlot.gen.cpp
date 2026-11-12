// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MAAssignmentSlot.h"
#include "AssetRegistry/AssetData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMAAssignmentSlot() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FAssetData(ETypeConstructPhase);
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
SCRIPTABLEEDITORWIDGETS_API UClass* Z_Construct_UClass_USinglePropertyView(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UEditableTextBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UPanelWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_MaterialAssignment(ETypeConstructPhase);
MATERIALASSIGNMENT_API UClass* Z_Construct_UClass_UMAAssignmentSlot(ETypeConstructPhase);
MATERIALASSIGNMENT_API UClass* Z_Construct_UClass_UMAAssignmentSlot(ETypeConstructPhase);
MATERIALASSIGNMENT_API UClass* Z_Construct_UClass_UMAMaterialParamObject(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMAAssignmentSlot Function ApplyBtnPressed *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMAAssignmentSlot_ApplyBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyBtnPressed constinit property declarations ***********************
// ********** End Function ApplyBtnPressed constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMAAssignmentSlot, nullptr, "ApplyBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMAAssignmentSlot_ApplyBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMAAssignmentSlot::execApplyBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMAAssignmentSlot Function ApplyBtnPressed *********************************

// ********** Begin Class UMAAssignmentSlot Function DeleteBtnPressed ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMAAssignmentSlot_DeleteBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DeleteBtnPressed constinit property declarations **********************
// ********** End Function DeleteBtnPressed constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMAAssignmentSlot, nullptr, "DeleteBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMAAssignmentSlot_DeleteBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMAAssignmentSlot::execDeleteBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DeleteBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMAAssignmentSlot Function DeleteBtnPressed ********************************

// ********** Begin Class UMAAssignmentSlot Function OnSlotNameTextCommitted ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMAAssignmentSlot_OnSlotNameTextCommitted_Statics
struct UHT_STATICS
{
	struct MAAssignmentSlot_eventOnSlotNameTextCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnSlotNameTextCommitted constinit property declarations ***************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnSlotNameTextCommitted constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnSlotNameTextCommitted Property Definitions **************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(MAAssignmentSlot_eventOnSlotNameTextCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MAAssignmentSlot_eventOnSlotNameTextCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnSlotNameTextCommitted Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMAAssignmentSlot, nullptr, "OnSlotNameTextCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MAAssignmentSlot_eventOnSlotNameTextCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MAAssignmentSlot_eventOnSlotNameTextCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMAAssignmentSlot_OnSlotNameTextCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMAAssignmentSlot::execOnSlotNameTextCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSlotNameTextCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UMAAssignmentSlot Function OnSlotNameTextCommitted *************************

// ********** Begin Class UMAAssignmentSlot Function QuickAssignBtnPressed *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMAAssignmentSlot_QuickAssignBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function QuickAssignBtnPressed constinit property declarations *****************
// ********** End Function QuickAssignBtnPressed constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMAAssignmentSlot, nullptr, "QuickAssignBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMAAssignmentSlot_QuickAssignBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMAAssignmentSlot::execQuickAssignBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->QuickAssignBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMAAssignmentSlot Function QuickAssignBtnPressed ***************************

// ********** Begin Class UMAAssignmentSlot ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMAAssignmentSlot_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/MAAssignmentSlot.h" },
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SuggestedMaterialData_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialParamObject_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CounterText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MultipleChoiceBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotRenameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshNameList_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialPropertyView_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApplyBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuickAssignBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeleteBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuickAssignText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAAssignmentSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMAAssignmentSlot constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SuggestedMaterialData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterialParamObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CounterText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MultipleChoiceBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotRenameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshNameList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterialPropertyView;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ApplyBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuickAssignBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeleteBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuickAssignText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMAAssignmentSlot constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyBtnPressed"), .Pointer = &UMAAssignmentSlot::execApplyBtnPressed },
		{ .NameUTF8 = UTF8TEXT("DeleteBtnPressed"), .Pointer = &UMAAssignmentSlot::execDeleteBtnPressed },
		{ .NameUTF8 = UTF8TEXT("OnSlotNameTextCommitted"), .Pointer = &UMAAssignmentSlot::execOnSlotNameTextCommitted },
		{ .NameUTF8 = UTF8TEXT("QuickAssignBtnPressed"), .Pointer = &UMAAssignmentSlot::execQuickAssignBtnPressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMAAssignmentSlot_ApplyBtnPressed, "ApplyBtnPressed" }, // b2adda5c9be20c7dc3b28a5f73760617b3f1b5b6
		{ &Z_Construct_UFunction_UMAAssignmentSlot_DeleteBtnPressed, "DeleteBtnPressed" }, // 541a1cdc752dffadea81c9f14ad4a7b361af8ce7
		{ &Z_Construct_UFunction_UMAAssignmentSlot_OnSlotNameTextCommitted, "OnSlotNameTextCommitted" }, // 6d41c225ed2903af8e709e05a02cdce17970613c
		{ &Z_Construct_UFunction_UMAAssignmentSlot_QuickAssignBtnPressed, "QuickAssignBtnPressed" }, // 3febc2e3ece4a15853147c71487397a0bc4df6ac
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMAAssignmentSlot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMAAssignmentSlot Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SuggestedMaterialData = { "SuggestedMaterialData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, SuggestedMaterialData), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SuggestedMaterialData_MetaData), NewProp_SuggestedMaterialData_MetaData) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MaterialParamObject = { "MaterialParamObject", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, MaterialParamObject), Z_Construct_UClass_UMAMaterialParamObject, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialParamObject_MetaData), NewProp_MaterialParamObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CounterText = { "CounterText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, CounterText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CounterText_MetaData), NewProp_CounterText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MultipleChoiceBox = { "MultipleChoiceBox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, MultipleChoiceBox), Z_Construct_UClass_UPanelWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MultipleChoiceBox_MetaData), NewProp_MultipleChoiceBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SlotRenameText = { "SlotRenameText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, SlotRenameText), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotRenameText_MetaData), NewProp_SlotRenameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MeshNameList = { "MeshNameList", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, MeshNameList), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshNameList_MetaData), NewProp_MeshNameList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MaterialPropertyView = { "MaterialPropertyView", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, MaterialPropertyView), Z_Construct_UClass_USinglePropertyView, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialPropertyView_MetaData), NewProp_MaterialPropertyView_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ApplyBtn = { "ApplyBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, ApplyBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApplyBtn_MetaData), NewProp_ApplyBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_QuickAssignBtn = { "QuickAssignBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, QuickAssignBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuickAssignBtn_MetaData), NewProp_QuickAssignBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DeleteBtn = { "DeleteBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, DeleteBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeleteBtn_MetaData), NewProp_DeleteBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_QuickAssignText = { "QuickAssignText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAAssignmentSlot, QuickAssignText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuickAssignText_MetaData), NewProp_QuickAssignText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SuggestedMaterialData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialParamObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CounterText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MultipleChoiceBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotRenameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MeshNameList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialPropertyView,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ApplyBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_QuickAssignBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DeleteBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_QuickAssignText,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMAAssignmentSlot Property Definitions *************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_MaterialAssignment,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMAAssignmentSlot,
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
static void UMAAssignmentSlot_StaticRegisterNativesUMAAssignmentSlot()
{
	UClass* Class = UMAAssignmentSlot::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMAAssignmentSlot;
UClass* Z_Construct_UClass_UMAAssignmentSlot(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMAAssignmentSlot;
		if (!Z_Registration_Info_UClass_UMAAssignmentSlot.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MAAssignmentSlot"),
				Z_Registration_Info_UClass_UMAAssignmentSlot.InnerSingleton,
				UMAAssignmentSlot_StaticRegisterNativesUMAAssignmentSlot,
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
		return Z_Registration_Info_UClass_UMAAssignmentSlot.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMAAssignmentSlot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMAAssignmentSlot.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMAAssignmentSlot.OuterSingleton;
}
#undef UHT_STATICS
UMAAssignmentSlot::UMAAssignmentSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMAAssignmentSlot);
UMAAssignmentSlot::~UMAAssignmentSlot() {}
// ********** End Class UMAAssignmentSlot **********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_UI_MAAssignmentSlot_h__Script_MaterialAssignment_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMAAssignmentSlot, TEXT("UMAAssignmentSlot"), &Z_Registration_Info_UClass_UMAAssignmentSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMAAssignmentSlot), 4241014012U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_UI_MAAssignmentSlot_h__Script_MaterialAssignment_cb7df42c5108ab63c1df11182bcc1ef14a6892a9{
	TEXT("/Script/MaterialAssignment"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
