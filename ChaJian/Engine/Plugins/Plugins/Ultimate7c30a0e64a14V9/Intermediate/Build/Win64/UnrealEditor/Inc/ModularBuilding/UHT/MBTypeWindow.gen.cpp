// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBTypeWindow.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBTypeWindow() {}

// ********** Begin Cross Module References ********************************************************
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UEditableTextBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UScrollBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBTypeWindow(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBAssetBorder(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBAssetSlot(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBTypeWindow(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBTypeWindow Function DeleteBtnPressed **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBTypeWindow_DeleteBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DeleteBtnPressed constinit property declarations **********************
// ********** End Function DeleteBtnPressed constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBTypeWindow, nullptr, "DeleteBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBTypeWindow_DeleteBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBTypeWindow::execDeleteBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DeleteBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMBTypeWindow Function DeleteBtnPressed ************************************

// ********** Begin Class UMBTypeWindow Function OnTitleTextBoxCommitted ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBTypeWindow_OnTitleTextBoxCommitted_Statics
struct UHT_STATICS
{
	struct MBTypeWindow_eventOnTitleTextBoxCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnTitleTextBoxCommitted constinit property declarations ***************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnTitleTextBoxCommitted constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnTitleTextBoxCommitted Property Definitions **************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(MBTypeWindow_eventOnTitleTextBoxCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MBTypeWindow_eventOnTitleTextBoxCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnTitleTextBoxCommitted Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBTypeWindow, nullptr, "OnTitleTextBoxCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBTypeWindow_eventOnTitleTextBoxCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBTypeWindow_eventOnTitleTextBoxCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBTypeWindow_OnTitleTextBoxCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBTypeWindow::execOnTitleTextBoxCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnTitleTextBoxCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UMBTypeWindow Function OnTitleTextBoxCommitted *****************************

// ********** Begin Class UMBTypeWindow Function TypeDownBtnPressed ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBTypeWindow_TypeDownBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TypeDownBtnPressed constinit property declarations ********************
// ********** End Function TypeDownBtnPressed constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBTypeWindow, nullptr, "TypeDownBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBTypeWindow_TypeDownBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBTypeWindow::execTypeDownBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TypeDownBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMBTypeWindow Function TypeDownBtnPressed **********************************

// ********** Begin Class UMBTypeWindow Function TypeUpBtnPressed **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBTypeWindow_TypeUpBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TypeUpBtnPressed constinit property declarations **********************
// ********** End Function TypeUpBtnPressed constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBTypeWindow, nullptr, "TypeUpBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBTypeWindow_TypeUpBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBTypeWindow::execTypeUpBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TypeUpBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMBTypeWindow Function TypeUpBtnPressed ************************************

// ********** Begin Class UMBTypeWindow ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBTypeWindow_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/MBTypeWindow.h" },
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MenuType_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AddedSlots_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleTextBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetDropBorder_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeUpBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
		{ "ToolTip", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeDownBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
		{ "ToolTip", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeleteBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBTypeWindow.h" },
		{ "ToolTip", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBTypeWindow constinit property declarations ****************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_MenuType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AddedSlots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AddedSlots;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AssetBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TitleTextBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AssetDropBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TypeUpBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TypeDownBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeleteBtn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBTypeWindow constinit property declarations ******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("DeleteBtnPressed"), .Pointer = &UMBTypeWindow::execDeleteBtnPressed },
		{ .NameUTF8 = UTF8TEXT("OnTitleTextBoxCommitted"), .Pointer = &UMBTypeWindow::execOnTitleTextBoxCommitted },
		{ .NameUTF8 = UTF8TEXT("TypeDownBtnPressed"), .Pointer = &UMBTypeWindow::execTypeDownBtnPressed },
		{ .NameUTF8 = UTF8TEXT("TypeUpBtnPressed"), .Pointer = &UMBTypeWindow::execTypeUpBtnPressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBTypeWindow_DeleteBtnPressed, "DeleteBtnPressed" }, // 2e0b332ebc026e962550b5f84a3faf9aacfec9bb
		{ &Z_Construct_UFunction_UMBTypeWindow_OnTitleTextBoxCommitted, "OnTitleTextBoxCommitted" }, // 95deb2af423a6e88255dbcc2596c9f2343488ed1
		{ &Z_Construct_UFunction_UMBTypeWindow_TypeDownBtnPressed, "TypeDownBtnPressed" }, // 1237327f7246ad3422cf283901d4866425e040d7
		{ &Z_Construct_UFunction_UMBTypeWindow_TypeUpBtnPressed, "TypeUpBtnPressed" }, // 3a4becd02c93c2fa1e0dd9a1d29000b693e7abf2
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBTypeWindow>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBTypeWindow Property Definitions ***************************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_MenuType = { "MenuType", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UMBTypeWindow, MenuType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MenuType_MetaData), NewProp_MenuType_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AddedSlots_Inner = { "AddedSlots", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_UMBAssetSlot, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_AddedSlots = { "AddedSlots", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UMBTypeWindow, AddedSlots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AddedSlots_MetaData), NewProp_AddedSlots_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AssetBox = { "AssetBox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBTypeWindow, AssetBox), Z_Construct_UClass_UScrollBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetBox_MetaData), NewProp_AssetBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TitleTextBox = { "TitleTextBox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBTypeWindow, TitleTextBox), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleTextBox_MetaData), NewProp_TitleTextBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AssetDropBorder = { "AssetDropBorder", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBTypeWindow, AssetDropBorder), Z_Construct_UClass_UMBAssetBorder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetDropBorder_MetaData), NewProp_AssetDropBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TypeUpBtn = { "TypeUpBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBTypeWindow, TypeUpBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeUpBtn_MetaData), NewProp_TypeUpBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TypeDownBtn = { "TypeDownBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBTypeWindow, TypeDownBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeDownBtn_MetaData), NewProp_TypeDownBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DeleteBtn = { "DeleteBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBTypeWindow, DeleteBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeleteBtn_MetaData), NewProp_DeleteBtn_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MenuType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AddedSlots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AddedSlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AssetBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TitleTextBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AssetDropBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TypeUpBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TypeDownBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DeleteBtn,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBTypeWindow Property Definitions *****************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBTypeWindow,
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
static void UMBTypeWindow_StaticRegisterNativesUMBTypeWindow()
{
	UClass* Class = UMBTypeWindow::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBTypeWindow;
UClass* Z_Construct_UClass_UMBTypeWindow(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBTypeWindow;
		if (!Z_Registration_Info_UClass_UMBTypeWindow.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBTypeWindow"),
				Z_Registration_Info_UClass_UMBTypeWindow.InnerSingleton,
				UMBTypeWindow_StaticRegisterNativesUMBTypeWindow,
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
		return Z_Registration_Info_UClass_UMBTypeWindow.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBTypeWindow.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBTypeWindow.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBTypeWindow.OuterSingleton;
}
#undef UHT_STATICS
UMBTypeWindow::UMBTypeWindow(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBTypeWindow);
UMBTypeWindow::~UMBTypeWindow() {}
// ********** End Class UMBTypeWindow **************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBTypeWindow_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBTypeWindow, TEXT("UMBTypeWindow"), &Z_Registration_Info_UClass_UMBTypeWindow, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBTypeWindow), 3724502857U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBTypeWindow_h__Script_ModularBuilding_cc83a7fc1d2db4ca6f0d21ee2135ac5814477dbc{
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
