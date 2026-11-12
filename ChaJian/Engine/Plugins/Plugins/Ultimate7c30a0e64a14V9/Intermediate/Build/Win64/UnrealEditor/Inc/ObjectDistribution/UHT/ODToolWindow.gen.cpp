// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODToolWindow.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODToolWindow() {}

// ********** Begin Cross Module References ********************************************************
BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityWidget(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
SCRIPTABLEEDITORWIDGETS_API UClass* Z_Construct_UClass_UDetailsView(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UBorder(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UEditableTextBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UPanelWidget(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODToolWindow(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UFunction* Z_Construct_UDelegateFunction_ObjectDistribution_OnLevelActorDeletedNativeSignature__DelegateSignature(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODDistributionBase(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODObjectSlot(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODPaletteSlate(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODPresetObject(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODSimulationWidget(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_AODSpawnCenter(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODToolWindow(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FOnLevelActorDeletedNativeSignature ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_ObjectDistribution_OnLevelActorDeletedNativeSignature__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_ObjectDistribution_eventOnLevelActorDeletedNativeSignature_Parms
	{
		AActor* Actor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnLevelActorDeletedNativeSignature constinit property declarations ***
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnLevelActorDeletedNativeSignature constinit property declarations *****
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnLevelActorDeletedNativeSignature Property Definitions **************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ObjectDistribution_eventOnLevelActorDeletedNativeSignature_Parms, Actor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Actor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FOnLevelActorDeletedNativeSignature Property Definitions ****************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution, nullptr, "OnLevelActorDeletedNativeSignature__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_ObjectDistribution_eventOnLevelActorDeletedNativeSignature_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_ObjectDistribution_eventOnLevelActorDeletedNativeSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ObjectDistribution_OnLevelActorDeletedNativeSignature__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FOnLevelActorDeletedNativeSignature *************************************

// ********** Begin Class UODToolWindow Function AddNewPresetBtnPressed ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_AddNewPresetBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddNewPresetBtnPressed constinit property declarations ****************
// ********** End Function AddNewPresetBtnPressed constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "AddNewPresetBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODToolWindow_AddNewPresetBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execAddNewPresetBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddNewPresetBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function AddNewPresetBtnPressed ******************************

// ********** Begin Class UODToolWindow Function AddSelectedAssetsBtnPressed ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_AddSelectedAssetsBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddSelectedAssetsBtnPressed constinit property declarations ***********
// ********** End Function AddSelectedAssetsBtnPressed constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "AddSelectedAssetsBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODToolWindow_AddSelectedAssetsBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execAddSelectedAssetsBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddSelectedAssetsBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function AddSelectedAssetsBtnPressed *************************

// ********** Begin Class UODToolWindow Function FinishBtnPressed **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_FinishBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function FinishBtnPressed constinit property declarations **********************
// ********** End Function FinishBtnPressed constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "FinishBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODToolWindow_FinishBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execFinishBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FinishBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function FinishBtnPressed ************************************

// ********** Begin Class UODToolWindow Function OnAddAssetsTextCommitted **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_OnAddAssetsTextCommitted_Statics
struct UHT_STATICS
{
	struct ODToolWindow_eventOnAddAssetsTextCommitted_Parms
	{
		FText InText;
		TEnumAsByte<ETextCommit::Type> InCommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnAddAssetsTextCommitted constinit property declarations **************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InCommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnAddAssetsTextCommitted constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnAddAssetsTextCommitted Property Definitions *************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ODToolWindow_eventOnAddAssetsTextCommitted_Parms, InText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InText_MetaData), NewProp_InText_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InCommitMethod = { "InCommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ODToolWindow_eventOnAddAssetsTextCommitted_Parms, InCommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InCommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnAddAssetsTextCommitted Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "OnAddAssetsTextCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODToolWindow_eventOnAddAssetsTextCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODToolWindow_eventOnAddAssetsTextCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODToolWindow_OnAddAssetsTextCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execOnAddAssetsTextCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
	P_GET_PROPERTY(FByteProperty,Z_Param_InCommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAddAssetsTextCommitted(Z_Param_Out_InText,ETextCommit::Type(Z_Param_InCommitMethod));
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function OnAddAssetsTextCommitted ****************************

// ********** Begin Class UODToolWindow Function OnNewPresetTextCommitted **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_OnNewPresetTextCommitted_Statics
struct UHT_STATICS
{
	struct ODToolWindow_eventOnNewPresetTextCommitted_Parms
	{
		FText InText;
		TEnumAsByte<ETextCommit::Type> InCommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnNewPresetTextCommitted constinit property declarations **************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InCommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnNewPresetTextCommitted constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnNewPresetTextCommitted Property Definitions *************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ODToolWindow_eventOnNewPresetTextCommitted_Parms, InText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InText_MetaData), NewProp_InText_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InCommitMethod = { "InCommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ODToolWindow_eventOnNewPresetTextCommitted_Parms, InCommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InCommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnNewPresetTextCommitted Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "OnNewPresetTextCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODToolWindow_eventOnNewPresetTextCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODToolWindow_eventOnNewPresetTextCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODToolWindow_OnNewPresetTextCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execOnNewPresetTextCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
	P_GET_PROPERTY(FByteProperty,Z_Param_InCommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnNewPresetTextCommitted(Z_Param_Out_InText,ETextCommit::Type(Z_Param_InCommitMethod));
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function OnNewPresetTextCommitted ****************************

// ********** Begin Class UODToolWindow Function OnObjectSlotPressed *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_OnObjectSlotPressed_Statics
struct UHT_STATICS
{
	struct ODToolWindow_eventOnObjectSlotPressed_Parms
	{
		bool InFormalSelectionState;
		int32 InSlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InFormalSelectionState_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSlotIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnObjectSlotPressed constinit property declarations *******************
	static void NewProp_InFormalSelectionState_SetBit(void* Obj)
	{
		((ODToolWindow_eventOnObjectSlotPressed_Parms*)Obj)->InFormalSelectionState = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_InFormalSelectionState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InSlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnObjectSlotPressed constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnObjectSlotPressed Property Definitions ******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_InFormalSelectionState = { "InFormalSelectionState", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ODToolWindow_eventOnObjectSlotPressed_Parms), &UHT_STATICS::NewProp_InFormalSelectionState_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InFormalSelectionState_MetaData), NewProp_InFormalSelectionState_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_InSlotIndex = { "InSlotIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ODToolWindow_eventOnObjectSlotPressed_Parms, InSlotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSlotIndex_MetaData), NewProp_InSlotIndex_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InFormalSelectionState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InSlotIndex,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnObjectSlotPressed Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "OnObjectSlotPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODToolWindow_eventOnObjectSlotPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODToolWindow_eventOnObjectSlotPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODToolWindow_OnObjectSlotPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execOnObjectSlotPressed)
{
	P_GET_UBOOL(Z_Param_InFormalSelectionState);
	P_GET_PROPERTY(FIntProperty,Z_Param_InSlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnObjectSlotPressed(Z_Param_InFormalSelectionState,Z_Param_InSlotIndex);
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function OnObjectSlotPressed *********************************

// ********** Begin Class UODToolWindow Function OnPresetLoaded ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_OnPresetLoaded_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "//Palette\n" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
		{ "ToolTip", "Palette" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnPresetLoaded constinit property declarations ************************
// ********** End Function OnPresetLoaded constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "OnPresetLoaded", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODToolWindow_OnPresetLoaded(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execOnPresetLoaded)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPresetLoaded();
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function OnPresetLoaded **************************************

// ********** Begin Class UODToolWindow Function OnRenamePresetTextCommitted ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_OnRenamePresetTextCommitted_Statics
struct UHT_STATICS
{
	struct ODToolWindow_eventOnRenamePresetTextCommitted_Parms
	{
		FText InText;
		TEnumAsByte<ETextCommit::Type> InCommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRenamePresetTextCommitted constinit property declarations ***********
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InCommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnRenamePresetTextCommitted constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnRenamePresetTextCommitted Property Definitions **********************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ODToolWindow_eventOnRenamePresetTextCommitted_Parms, InText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InText_MetaData), NewProp_InText_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InCommitMethod = { "InCommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ODToolWindow_eventOnRenamePresetTextCommitted_Parms, InCommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InCommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnRenamePresetTextCommitted Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "OnRenamePresetTextCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODToolWindow_eventOnRenamePresetTextCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODToolWindow_eventOnRenamePresetTextCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODToolWindow_OnRenamePresetTextCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execOnRenamePresetTextCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
	P_GET_PROPERTY(FByteProperty,Z_Param_InCommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRenamePresetTextCommitted(Z_Param_Out_InText,ETextCommit::Type(Z_Param_InCommitMethod));
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function OnRenamePresetTextCommitted *************************

// ********** Begin Class UODToolWindow Function OnSaveAsTextCommitted *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_OnSaveAsTextCommitted_Statics
struct UHT_STATICS
{
	struct ODToolWindow_eventOnSaveAsTextCommitted_Parms
	{
		FText InText;
		TEnumAsByte<ETextCommit::Type> InCommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnSaveAsTextCommitted constinit property declarations *****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InCommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnSaveAsTextCommitted constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnSaveAsTextCommitted Property Definitions ****************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ODToolWindow_eventOnSaveAsTextCommitted_Parms, InText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InText_MetaData), NewProp_InText_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InCommitMethod = { "InCommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ODToolWindow_eventOnSaveAsTextCommitted_Parms, InCommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InCommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnSaveAsTextCommitted Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "OnSaveAsTextCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODToolWindow_eventOnSaveAsTextCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODToolWindow_eventOnSaveAsTextCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODToolWindow_OnSaveAsTextCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execOnSaveAsTextCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
	P_GET_PROPERTY(FByteProperty,Z_Param_InCommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSaveAsTextCommitted(Z_Param_Out_InText,ETextCommit::Type(Z_Param_InCommitMethod));
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function OnSaveAsTextCommitted *******************************

// ********** Begin Class UODToolWindow Function PaletteBackgroundBtnPressed ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_PaletteBackgroundBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function PaletteBackgroundBtnPressed constinit property declarations ***********
// ********** End Function PaletteBackgroundBtnPressed constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "PaletteBackgroundBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODToolWindow_PaletteBackgroundBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execPaletteBackgroundBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PaletteBackgroundBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function PaletteBackgroundBtnPressed *************************

// ********** Begin Class UODToolWindow Function RebuildPalette ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_RebuildPalette_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RebuildPalette constinit property declarations ************************
// ********** End Function RebuildPalette constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "RebuildPalette", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODToolWindow_RebuildPalette(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execRebuildPalette)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RebuildPalette();
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function RebuildPalette **************************************

// ********** Begin Class UODToolWindow Function RemovePresetBtnPressed ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_RemovePresetBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemovePresetBtnPressed constinit property declarations ****************
// ********** End Function RemovePresetBtnPressed constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "RemovePresetBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODToolWindow_RemovePresetBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execRemovePresetBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemovePresetBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function RemovePresetBtnPressed ******************************

// ********** Begin Class UODToolWindow Function RenamePresetBtnPressed ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_RenamePresetBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RenamePresetBtnPressed constinit property declarations ****************
// ********** End Function RenamePresetBtnPressed constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "RenamePresetBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODToolWindow_RenamePresetBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execRenamePresetBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RenamePresetBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function RenamePresetBtnPressed ******************************

// ********** Begin Class UODToolWindow Function SaveAsNewPresetBtnPressed *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_SaveAsNewPresetBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SaveAsNewPresetBtnPressed constinit property declarations *************
// ********** End Function SaveAsNewPresetBtnPressed constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "SaveAsNewPresetBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODToolWindow_SaveAsNewPresetBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execSaveAsNewPresetBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SaveAsNewPresetBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function SaveAsNewPresetBtnPressed ***************************

// ********** Begin Class UODToolWindow Function SavePresetBtnPressed ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODToolWindow_SavePresetBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SavePresetBtnPressed constinit property declarations ******************
// ********** End Function SavePresetBtnPressed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODToolWindow, nullptr, "SavePresetBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODToolWindow_SavePresetBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODToolWindow::execSavePresetBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SavePresetBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UODToolWindow Function SavePresetBtnPressed ********************************

// ********** Begin Class UODToolWindow ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODToolWindow_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/ODToolWindow.h" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsToolDestroying_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bTraceForVelocity_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastSpawnCenterLocation_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnCenterVelocity_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bTraceForRotationDiff_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastSpawnCenterRotation_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnCenterRotation_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropDistributionBase_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetObject_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetDetails_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetSettingsBorder_MetaData[] = {
		{ "BindWidget", "" },
		{ "Comment", "/*UPROPERTY(meta = (BindWidget))\n\x09TObjectPtr<UDetailsView> PropDistributionDetails;*/" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
		{ "ToolTip", "UPROPERTY(meta = (BindWidget))\n       TObjectPtr<UDetailsView> PropDistributionDetails;" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleBorder_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PaletteSlate_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinishBtn_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Comment", "/*UPROPERTY(meta = (BindWidgetOptional))\n\x09TObjectPtr<UButton> PaletteBackgroundBtn;*/" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
		{ "ToolTip", "UPROPERTY(meta = (BindWidgetOptional))\n       TObjectPtr<UButton> PaletteBackgroundBtn;" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SimulationBorder_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SimulationWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnCenterRef_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLevelActorDeletedNative_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AddNewPresetBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AddSelectedAssetsBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewPresetText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AddAssetsText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenamePresetBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenamePresetText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RemovePresetBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavePresetBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveAsNewPresetBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveAsText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectSlots_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODToolWindow constinit property declarations ****************************
	static void NewProp_bIsToolDestroying_SetBit(void* Obj)
	{
		((UODToolWindow*)Obj)->bIsToolDestroying = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsToolDestroying;
	static void NewProp_bTraceForVelocity_SetBit(void* Obj)
	{
		((UODToolWindow*)Obj)->bTraceForVelocity = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTraceForVelocity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastSpawnCenterLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnCenterVelocity;
	static void NewProp_bTraceForRotationDiff_SetBit(void* Obj)
	{
		((UODToolWindow*)Obj)->bTraceForRotationDiff = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTraceForRotationDiff;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastSpawnCenterRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnCenterRotation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PropDistributionBase;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PresetObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PresetDetails;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PresetSettingsBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TitleBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PaletteSlate;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FinishBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SimulationBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SimulationWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnCenterRef;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLevelActorDeletedNative;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AddNewPresetBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AddSelectedAssetsBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewPresetText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AddAssetsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenamePresetBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenamePresetText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RemovePresetBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SavePresetBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveAsNewPresetBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveAsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObjectSlots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ObjectSlots;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODToolWindow constinit property declarations ******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddNewPresetBtnPressed"), .Pointer = &UODToolWindow::execAddNewPresetBtnPressed },
		{ .NameUTF8 = UTF8TEXT("AddSelectedAssetsBtnPressed"), .Pointer = &UODToolWindow::execAddSelectedAssetsBtnPressed },
		{ .NameUTF8 = UTF8TEXT("FinishBtnPressed"), .Pointer = &UODToolWindow::execFinishBtnPressed },
		{ .NameUTF8 = UTF8TEXT("OnAddAssetsTextCommitted"), .Pointer = &UODToolWindow::execOnAddAssetsTextCommitted },
		{ .NameUTF8 = UTF8TEXT("OnNewPresetTextCommitted"), .Pointer = &UODToolWindow::execOnNewPresetTextCommitted },
		{ .NameUTF8 = UTF8TEXT("OnObjectSlotPressed"), .Pointer = &UODToolWindow::execOnObjectSlotPressed },
		{ .NameUTF8 = UTF8TEXT("OnPresetLoaded"), .Pointer = &UODToolWindow::execOnPresetLoaded },
		{ .NameUTF8 = UTF8TEXT("OnRenamePresetTextCommitted"), .Pointer = &UODToolWindow::execOnRenamePresetTextCommitted },
		{ .NameUTF8 = UTF8TEXT("OnSaveAsTextCommitted"), .Pointer = &UODToolWindow::execOnSaveAsTextCommitted },
		{ .NameUTF8 = UTF8TEXT("PaletteBackgroundBtnPressed"), .Pointer = &UODToolWindow::execPaletteBackgroundBtnPressed },
		{ .NameUTF8 = UTF8TEXT("RebuildPalette"), .Pointer = &UODToolWindow::execRebuildPalette },
		{ .NameUTF8 = UTF8TEXT("RemovePresetBtnPressed"), .Pointer = &UODToolWindow::execRemovePresetBtnPressed },
		{ .NameUTF8 = UTF8TEXT("RenamePresetBtnPressed"), .Pointer = &UODToolWindow::execRenamePresetBtnPressed },
		{ .NameUTF8 = UTF8TEXT("SaveAsNewPresetBtnPressed"), .Pointer = &UODToolWindow::execSaveAsNewPresetBtnPressed },
		{ .NameUTF8 = UTF8TEXT("SavePresetBtnPressed"), .Pointer = &UODToolWindow::execSavePresetBtnPressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UODToolWindow_AddNewPresetBtnPressed, "AddNewPresetBtnPressed" }, // be0bbc33b74be4cf582848008dbab541f9977376
		{ &Z_Construct_UFunction_UODToolWindow_AddSelectedAssetsBtnPressed, "AddSelectedAssetsBtnPressed" }, // 89e1b7cf805d567ce0c604411a2557ba476d614d
		{ &Z_Construct_UFunction_UODToolWindow_FinishBtnPressed, "FinishBtnPressed" }, // 4c7e608c3a79b80af43305d6ca5b9375a8755f73
		{ &Z_Construct_UFunction_UODToolWindow_OnAddAssetsTextCommitted, "OnAddAssetsTextCommitted" }, // f250656a98a7b5fd76d2421111e4081a3f9e1b4b
		{ &Z_Construct_UFunction_UODToolWindow_OnNewPresetTextCommitted, "OnNewPresetTextCommitted" }, // 754bd2559d0957e688344b5c1eacc4d15553481c
		{ &Z_Construct_UFunction_UODToolWindow_OnObjectSlotPressed, "OnObjectSlotPressed" }, // bc525eb404388befcbbff30146928568740faa88
		{ &Z_Construct_UFunction_UODToolWindow_OnPresetLoaded, "OnPresetLoaded" }, // 07a18872f7747525ecff402e7b0e1085658765fa
		{ &Z_Construct_UFunction_UODToolWindow_OnRenamePresetTextCommitted, "OnRenamePresetTextCommitted" }, // b8ab3d0cab455ded53f204d7029eeeb3ff6d37e4
		{ &Z_Construct_UFunction_UODToolWindow_OnSaveAsTextCommitted, "OnSaveAsTextCommitted" }, // d062364a2f88b0f43748ffb0303e98582429ccd3
		{ &Z_Construct_UFunction_UODToolWindow_PaletteBackgroundBtnPressed, "PaletteBackgroundBtnPressed" }, // c06c33e266b12d027a8a1b02690ab063d0432746
		{ &Z_Construct_UFunction_UODToolWindow_RebuildPalette, "RebuildPalette" }, // e3f5f7726243b3bc06cc1be21eb576cfd8198f6c
		{ &Z_Construct_UFunction_UODToolWindow_RemovePresetBtnPressed, "RemovePresetBtnPressed" }, // 13b5f1ba6167fbf01845389c534a2391ac714bb0
		{ &Z_Construct_UFunction_UODToolWindow_RenamePresetBtnPressed, "RenamePresetBtnPressed" }, // 35bbe0963171bda586840ad32774f3962d9c934f
		{ &Z_Construct_UFunction_UODToolWindow_SaveAsNewPresetBtnPressed, "SaveAsNewPresetBtnPressed" }, // fe1b52d1c1283cdeea18f7983effc4a3b17e5a0a
		{ &Z_Construct_UFunction_UODToolWindow_SavePresetBtnPressed, "SavePresetBtnPressed" }, // 516b2c83f203ccfcb1359cb4d7c8b43b8c4e79cd
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODToolWindow>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODToolWindow Property Definitions ***************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsToolDestroying = { "bIsToolDestroying", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODToolWindow), &UHT_STATICS::NewProp_bIsToolDestroying_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsToolDestroying_MetaData), NewProp_bIsToolDestroying_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bTraceForVelocity = { "bTraceForVelocity", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODToolWindow), &UHT_STATICS::NewProp_bTraceForVelocity_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bTraceForVelocity_MetaData), NewProp_bTraceForVelocity_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_LastSpawnCenterLocation = { "LastSpawnCenterLocation", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, LastSpawnCenterLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastSpawnCenterLocation_MetaData), NewProp_LastSpawnCenterLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpawnCenterVelocity = { "SpawnCenterVelocity", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, SpawnCenterVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnCenterVelocity_MetaData), NewProp_SpawnCenterVelocity_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bTraceForRotationDiff = { "bTraceForRotationDiff", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODToolWindow), &UHT_STATICS::NewProp_bTraceForRotationDiff_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bTraceForRotationDiff_MetaData), NewProp_bTraceForRotationDiff_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_LastSpawnCenterRotation = { "LastSpawnCenterRotation", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, LastSpawnCenterRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastSpawnCenterRotation_MetaData), NewProp_LastSpawnCenterRotation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpawnCenterRotation = { "SpawnCenterRotation", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, SpawnCenterRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnCenterRotation_MetaData), NewProp_SpawnCenterRotation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PropDistributionBase = { "PropDistributionBase", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, PropDistributionBase), Z_Construct_UClass_UODDistributionBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropDistributionBase_MetaData), NewProp_PropDistributionBase_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PresetObject = { "PresetObject", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, PresetObject), Z_Construct_UClass_UODPresetObject, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetObject_MetaData), NewProp_PresetObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PresetDetails = { "PresetDetails", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, PresetDetails), Z_Construct_UClass_UDetailsView, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetDetails_MetaData), NewProp_PresetDetails_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PresetSettingsBorder = { "PresetSettingsBorder", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, PresetSettingsBorder), Z_Construct_UClass_UPanelWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetSettingsBorder_MetaData), NewProp_PresetSettingsBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TitleBorder = { "TitleBorder", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, TitleBorder), Z_Construct_UClass_UBorder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleBorder_MetaData), NewProp_TitleBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PaletteSlate = { "PaletteSlate", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, PaletteSlate), Z_Construct_UClass_UODPaletteSlate, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PaletteSlate_MetaData), NewProp_PaletteSlate_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FinishBtn = { "FinishBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, FinishBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinishBtn_MetaData), NewProp_FinishBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SimulationBorder = { "SimulationBorder", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, SimulationBorder), Z_Construct_UClass_UBorder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SimulationBorder_MetaData), NewProp_SimulationBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SimulationWidget = { "SimulationWidget", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, SimulationWidget), Z_Construct_UClass_UODSimulationWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SimulationWidget_MetaData), NewProp_SimulationWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpawnCenterRef = { "SpawnCenterRef", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, SpawnCenterRef), Z_Construct_UClass_AODSpawnCenter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnCenterRef_MetaData), NewProp_SpawnCenterRef_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnLevelActorDeletedNative = { "OnLevelActorDeletedNative", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, OnLevelActorDeletedNative), Z_Construct_UDelegateFunction_ObjectDistribution_OnLevelActorDeletedNativeSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLevelActorDeletedNative_MetaData), NewProp_OnLevelActorDeletedNative_MetaData) }; // b642f2bc4e7306c1826fbf9f06aa33b2d4f63938
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AddNewPresetBtn = { "AddNewPresetBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, AddNewPresetBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AddNewPresetBtn_MetaData), NewProp_AddNewPresetBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AddSelectedAssetsBtn = { "AddSelectedAssetsBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, AddSelectedAssetsBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AddSelectedAssetsBtn_MetaData), NewProp_AddSelectedAssetsBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NewPresetText = { "NewPresetText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, NewPresetText), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewPresetText_MetaData), NewProp_NewPresetText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AddAssetsText = { "AddAssetsText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, AddAssetsText), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AddAssetsText_MetaData), NewProp_AddAssetsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RenamePresetBtn = { "RenamePresetBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, RenamePresetBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenamePresetBtn_MetaData), NewProp_RenamePresetBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RenamePresetText = { "RenamePresetText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, RenamePresetText), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenamePresetText_MetaData), NewProp_RenamePresetText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RemovePresetBtn = { "RemovePresetBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, RemovePresetBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RemovePresetBtn_MetaData), NewProp_RemovePresetBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SavePresetBtn = { "SavePresetBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, SavePresetBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavePresetBtn_MetaData), NewProp_SavePresetBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SaveAsNewPresetBtn = { "SaveAsNewPresetBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, SaveAsNewPresetBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveAsNewPresetBtn_MetaData), NewProp_SaveAsNewPresetBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SaveAsText = { "SaveAsText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, SaveAsText), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveAsText_MetaData), NewProp_SaveAsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ObjectSlots_Inner = { "ObjectSlots", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_UODObjectSlot, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ObjectSlots = { "ObjectSlots", nullptr, (EPropertyFlags)0x0144008000000008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UODToolWindow, ObjectSlots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectSlots_MetaData), NewProp_ObjectSlots_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsToolDestroying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bTraceForVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastSpawnCenterLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnCenterVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bTraceForRotationDiff,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastSpawnCenterRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnCenterRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PropDistributionBase,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetDetails,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetSettingsBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TitleBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PaletteSlate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FinishBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SimulationBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SimulationWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnCenterRef,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnLevelActorDeletedNative,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AddNewPresetBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AddSelectedAssetsBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPresetText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AddAssetsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RenamePresetBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RenamePresetText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RemovePresetBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SavePresetBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SaveAsNewPresetBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SaveAsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ObjectSlots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ObjectSlots,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODToolWindow Property Definitions *****************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UEditorUtilityWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODToolWindow,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UODToolWindow_StaticRegisterNativesUODToolWindow()
{
	UClass* Class = UODToolWindow::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UODToolWindow;
UClass* Z_Construct_UClass_UODToolWindow(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODToolWindow;
		if (!Z_Registration_Info_UClass_UODToolWindow.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODToolWindow"),
				Z_Registration_Info_UClass_UODToolWindow.InnerSingleton,
				UODToolWindow_StaticRegisterNativesUODToolWindow,
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
		return Z_Registration_Info_UClass_UODToolWindow.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODToolWindow.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODToolWindow.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODToolWindow.OuterSingleton;
}
#undef UHT_STATICS
UODToolWindow::UODToolWindow(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODToolWindow);
UODToolWindow::~UODToolWindow() {}
// ********** End Class UODToolWindow **************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_UI_ODToolWindow_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODToolWindow, TEXT("UODToolWindow"), &Z_Registration_Info_UClass_UODToolWindow, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODToolWindow), 3893911025U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_UI_ODToolWindow_h__Script_ObjectDistribution_b57577dcbbf1db4b02cf69859193bac71fcb130f{
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
