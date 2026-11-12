// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBCategoryWindow.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBCategoryWindow() {}

// ********** Begin Cross Module References ********************************************************
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UEditableTextBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_USizeBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UVerticalBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EBuildingCategory(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBCategoryWindow(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBCategoryWindow(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBTypeWindow(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBCategoryWindow Function OnAddNewTypeTextCommitted *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBCategoryWindow_OnAddNewTypeTextCommitted_Statics
struct UHT_STATICS
{
	struct MBCategoryWindow_eventOnAddNewTypeTextCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBCategoryWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnAddNewTypeTextCommitted constinit property declarations *************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnAddNewTypeTextCommitted constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnAddNewTypeTextCommitted Property Definitions ************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(MBCategoryWindow_eventOnAddNewTypeTextCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(MBCategoryWindow_eventOnAddNewTypeTextCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnAddNewTypeTextCommitted Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBCategoryWindow, nullptr, "OnAddNewTypeTextCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBCategoryWindow_eventOnAddNewTypeTextCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBCategoryWindow_eventOnAddNewTypeTextCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBCategoryWindow_OnAddNewTypeTextCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBCategoryWindow::execOnAddNewTypeTextCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAddNewTypeTextCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UMBCategoryWindow Function OnAddNewTypeTextCommitted ***********************

// ********** Begin Class UMBCategoryWindow ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBCategoryWindow_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/MBCategoryWindow.h" },
		{ "ModuleRelativePath", "Public/UI/MBCategoryWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeWindows_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBCategoryWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBCategoryWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CategoryMenuBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBCategoryWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainCategoryBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBCategoryWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AddNewTypeText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBCategoryWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBCategoryWindow constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TypeWindows_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_TypeWindows_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_TypeWindows;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Category_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Category;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CategoryMenuBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MainCategoryBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AddNewTypeText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBCategoryWindow constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnAddNewTypeTextCommitted"), .Pointer = &UMBCategoryWindow::execOnAddNewTypeTextCommitted },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBCategoryWindow_OnAddNewTypeTextCommitted, "OnAddNewTypeTextCommitted" }, // 97e45f2014e3ea87bfb68f2c1def9b08b6a370dc
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBCategoryWindow>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBCategoryWindow Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TypeWindows_ValueProp = { "TypeWindows", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 1, Z_Construct_UClass_UMBTypeWindow, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_TypeWindows_Key_KeyProp = { "TypeWindows_Key", nullptr, (EPropertyFlags)0x0100000000080008, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams UHT_STATICS::NewProp_TypeWindows = { "TypeWindows", nullptr, (EPropertyFlags)0x0144008000000008, UECodeGen_Private::EPropertyGenFlags::Map, nullptr, nullptr, 1, STRUCT_OFFSET(UMBCategoryWindow, TypeWindows), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeWindows_MetaData), NewProp_TypeWindows_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Category_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBCategoryWindow, Category), Z_Construct_UEnum_ModularBuilding_EBuildingCategory, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Category_MetaData), NewProp_Category_MetaData) }; // 07cf8117a6e577cac6ce1c747d6b11cc85196fdc
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CategoryMenuBox = { "CategoryMenuBox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBCategoryWindow, CategoryMenuBox), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CategoryMenuBox_MetaData), NewProp_CategoryMenuBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MainCategoryBox = { "MainCategoryBox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBCategoryWindow, MainCategoryBox), Z_Construct_UClass_USizeBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainCategoryBox_MetaData), NewProp_MainCategoryBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AddNewTypeText = { "AddNewTypeText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBCategoryWindow, AddNewTypeText), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AddNewTypeText_MetaData), NewProp_AddNewTypeText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TypeWindows_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TypeWindows_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TypeWindows,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Category_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Category,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CategoryMenuBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MainCategoryBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AddNewTypeText,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBCategoryWindow Property Definitions *************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBCategoryWindow,
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
static void UMBCategoryWindow_StaticRegisterNativesUMBCategoryWindow()
{
	UClass* Class = UMBCategoryWindow::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBCategoryWindow;
UClass* Z_Construct_UClass_UMBCategoryWindow(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBCategoryWindow;
		if (!Z_Registration_Info_UClass_UMBCategoryWindow.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBCategoryWindow"),
				Z_Registration_Info_UClass_UMBCategoryWindow.InnerSingleton,
				UMBCategoryWindow_StaticRegisterNativesUMBCategoryWindow,
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
		return Z_Registration_Info_UClass_UMBCategoryWindow.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBCategoryWindow.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBCategoryWindow.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBCategoryWindow.OuterSingleton;
}
#undef UHT_STATICS
UMBCategoryWindow::UMBCategoryWindow(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBCategoryWindow);
UMBCategoryWindow::~UMBCategoryWindow() {}
// ********** End Class UMBCategoryWindow **********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBCategoryWindow_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBCategoryWindow, TEXT("UMBCategoryWindow"), &Z_Registration_Info_UClass_UMBCategoryWindow, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBCategoryWindow), 1377393800U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBCategoryWindow_h__Script_ModularBuilding_488585e0649b17285c8d8bc728256dbd5021573e{
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
