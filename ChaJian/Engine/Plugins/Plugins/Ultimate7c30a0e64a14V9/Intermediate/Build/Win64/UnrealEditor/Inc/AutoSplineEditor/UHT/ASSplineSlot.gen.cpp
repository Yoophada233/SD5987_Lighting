// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASSplineSlot.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeASSplineSlot() {}

// ********** Begin Cross Module References ********************************************************
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UCheckBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UEditableTextBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AutoSplineEditor(ETypeConstructPhase);
AUTOSPLINEEDITOR_API UClass* Z_Construct_UClass_UASSplineSlot(ETypeConstructPhase);
AUTOSPLINEEDITOR_API UClass* Z_Construct_UClass_UASSplineSlot(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UASSplineSlot Function RenameBtnPressed **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASSplineSlot_RenameBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RenameBtnPressed constinit property declarations **********************
// ********** End Function RenameBtnPressed constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASSplineSlot, nullptr, "RenameBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UASSplineSlot_RenameBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASSplineSlot::execRenameBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RenameBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UASSplineSlot Function RenameBtnPressed ************************************

// ********** Begin Class UASSplineSlot Function SeeSplineBtnPressed *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASSplineSlot_SeeSplineBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SeeSplineBtnPressed constinit property declarations *******************
// ********** End Function SeeSplineBtnPressed constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASSplineSlot, nullptr, "SeeSplineBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UASSplineSlot_SeeSplineBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASSplineSlot::execSeeSplineBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SeeSplineBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UASSplineSlot Function SeeSplineBtnPressed *********************************

// ********** Begin Class UASSplineSlot Function SelectionCheckboxChanged **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASSplineSlot_SelectionCheckboxChanged_Statics
struct UHT_STATICS
{
	struct ASSplineSlot_eventSelectionCheckboxChanged_Parms
	{
		bool InNewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SelectionCheckboxChanged constinit property declarations **************
	static void NewProp_InNewState_SetBit(void* Obj)
	{
		((ASSplineSlot_eventSelectionCheckboxChanged_Parms*)Obj)->InNewState = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_InNewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SelectionCheckboxChanged constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SelectionCheckboxChanged Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_InNewState = { "InNewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ASSplineSlot_eventSelectionCheckboxChanged_Parms), &UHT_STATICS::NewProp_InNewState_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InNewState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SelectionCheckboxChanged Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASSplineSlot, nullptr, "SelectionCheckboxChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ASSplineSlot_eventSelectionCheckboxChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ASSplineSlot_eventSelectionCheckboxChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UASSplineSlot_SelectionCheckboxChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASSplineSlot::execSelectionCheckboxChanged)
{
	P_GET_UBOOL(Z_Param_InNewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SelectionCheckboxChanged(Z_Param_InNewState);
	P_NATIVE_END;
}
// ********** End Class UASSplineSlot Function SelectionCheckboxChanged ****************************

// ********** Begin Class UASSplineSlot Function SplineNameTextBoxCommitted ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASSplineSlot_SplineNameTextBoxCommitted_Statics
struct UHT_STATICS
{
	struct ASSplineSlot_eventSplineNameTextBoxCommitted_Parms
	{
		FText InText;
		TEnumAsByte<ETextCommit::Type> InCommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SplineNameTextBoxCommitted constinit property declarations ************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InCommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SplineNameTextBoxCommitted constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SplineNameTextBoxCommitted Property Definitions ***********************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ASSplineSlot_eventSplineNameTextBoxCommitted_Parms, InText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InText_MetaData), NewProp_InText_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InCommitMethod = { "InCommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ASSplineSlot_eventSplineNameTextBoxCommitted_Parms, InCommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InCommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SplineNameTextBoxCommitted Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASSplineSlot, nullptr, "SplineNameTextBoxCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ASSplineSlot_eventSplineNameTextBoxCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ASSplineSlot_eventSplineNameTextBoxCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UASSplineSlot_SplineNameTextBoxCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASSplineSlot::execSplineNameTextBoxCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
	P_GET_PROPERTY(FByteProperty,Z_Param_InCommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SplineNameTextBoxCommitted(Z_Param_Out_InText,ETextCommit::Type(Z_Param_InCommitMethod));
	P_NATIVE_END;
}
// ********** End Class UASSplineSlot Function SplineNameTextBoxCommitted **************************

// ********** Begin Class UASSplineSlot ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UASSplineSlot_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/ASSplineSlot.h" },
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplineObjectName_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplineObjectLabel_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplineNameTextBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SeeSplineBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenameBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectionCheckbox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASSplineSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UASSplineSlot constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SplineObjectName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SplineObjectLabel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SplineNameTextBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SeeSplineBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenameBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectionCheckbox;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UASSplineSlot constinit property declarations ******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("RenameBtnPressed"), .Pointer = &UASSplineSlot::execRenameBtnPressed },
		{ .NameUTF8 = UTF8TEXT("SeeSplineBtnPressed"), .Pointer = &UASSplineSlot::execSeeSplineBtnPressed },
		{ .NameUTF8 = UTF8TEXT("SelectionCheckboxChanged"), .Pointer = &UASSplineSlot::execSelectionCheckboxChanged },
		{ .NameUTF8 = UTF8TEXT("SplineNameTextBoxCommitted"), .Pointer = &UASSplineSlot::execSplineNameTextBoxCommitted },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UASSplineSlot_RenameBtnPressed, "RenameBtnPressed" }, // 1d20f79d715b4f9673d856591ac613f6d633deee
		{ &Z_Construct_UFunction_UASSplineSlot_SeeSplineBtnPressed, "SeeSplineBtnPressed" }, // 3bc61e7115f7916c9e82fcccd37a061cf5412313
		{ &Z_Construct_UFunction_UASSplineSlot_SelectionCheckboxChanged, "SelectionCheckboxChanged" }, // 4ea1e446dfc06f6ab6e62029da3162b1ef662906
		{ &Z_Construct_UFunction_UASSplineSlot_SplineNameTextBoxCommitted, "SplineNameTextBoxCommitted" }, // ae0eb20a7742a9335c235ef98c9f3362da9da551
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UASSplineSlot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UASSplineSlot Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SplineObjectName = { "SplineObjectName", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UASSplineSlot, SplineObjectName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplineObjectName_MetaData), NewProp_SplineObjectName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SplineObjectLabel = { "SplineObjectLabel", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UASSplineSlot, SplineObjectLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplineObjectLabel_MetaData), NewProp_SplineObjectLabel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SplineNameTextBox = { "SplineNameTextBox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASSplineSlot, SplineNameTextBox), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplineNameTextBox_MetaData), NewProp_SplineNameTextBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SeeSplineBtn = { "SeeSplineBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASSplineSlot, SeeSplineBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SeeSplineBtn_MetaData), NewProp_SeeSplineBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RenameBtn = { "RenameBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASSplineSlot, RenameBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenameBtn_MetaData), NewProp_RenameBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectionCheckbox = { "SelectionCheckbox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASSplineSlot, SelectionCheckbox), Z_Construct_UClass_UCheckBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectionCheckbox_MetaData), NewProp_SelectionCheckbox_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SplineObjectName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SplineObjectLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SplineNameTextBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SeeSplineBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RenameBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectionCheckbox,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UASSplineSlot Property Definitions *****************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AutoSplineEditor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UASSplineSlot,
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
static void UASSplineSlot_StaticRegisterNativesUASSplineSlot()
{
	UClass* Class = UASSplineSlot::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UASSplineSlot;
UClass* Z_Construct_UClass_UASSplineSlot(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UASSplineSlot;
		if (!Z_Registration_Info_UClass_UASSplineSlot.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ASSplineSlot"),
				Z_Registration_Info_UClass_UASSplineSlot.InnerSingleton,
				UASSplineSlot_StaticRegisterNativesUASSplineSlot,
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
		return Z_Registration_Info_UClass_UASSplineSlot.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UASSplineSlot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UASSplineSlot.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UASSplineSlot.OuterSingleton;
}
#undef UHT_STATICS
UASSplineSlot::UASSplineSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UASSplineSlot);
UASSplineSlot::~UASSplineSlot() {}
// ********** End Class UASSplineSlot **************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSplineEditor_Public_UI_ASSplineSlot_h__Script_AutoSplineEditor_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UASSplineSlot, TEXT("UASSplineSlot"), &Z_Registration_Info_UClass_UASSplineSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UASSplineSlot), 3997937047U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSplineEditor_Public_UI_ASSplineSlot_h__Script_AutoSplineEditor_15e1c6eab3c63aaf0fe1e90b26d64c0092048db2{
	TEXT("/Script/AutoSplineEditor"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
