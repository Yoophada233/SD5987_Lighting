// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MAToolWindow.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMAToolWindow() {}

// ********** Begin Cross Module References ********************************************************
BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityWidget(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UPanelWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UScrollBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UWidgetAnimation(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_MaterialAssignment(ETypeConstructPhase);
MATERIALASSIGNMENT_API UClass* Z_Construct_UClass_UMAToolWindow(ETypeConstructPhase);
MATERIALASSIGNMENT_API UClass* Z_Construct_UClass_UMAAssignmentSlot(ETypeConstructPhase);
MATERIALASSIGNMENT_API UClass* Z_Construct_UClass_UMAToolWindow(ETypeConstructPhase);
MATERIALASSIGNMENT_API UClass* Z_Construct_UClass_IMAToolWindowInterface(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMAToolWindow Function ApplyAllBtnPressed ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMAToolWindow_ApplyAllBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MAToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyAllBtnPressed constinit property declarations ********************
// ********** End Function ApplyAllBtnPressed constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMAToolWindow, nullptr, "ApplyAllBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMAToolWindow_ApplyAllBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMAToolWindow::execApplyAllBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyAllBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMAToolWindow Function ApplyAllBtnPressed **********************************

// ********** Begin Class UMAToolWindow ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMAToolWindow_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/MAToolWindow.h" },
		{ "ModuleRelativePath", "Public/UI/MAToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotNames_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MAToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedStaticMeshes_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MAToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialSlotWidgets_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApplyAllBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApplyAllBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NoMeshText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MAToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectMeshTextAnim_MetaData[] = {
		{ "BindWidgetAnim", "" },
		{ "ModuleRelativePath", "Public/UI/MAToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMAToolWindow constinit property declarations ****************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_SlotNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SlotNames;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedStaticMeshes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SelectedStaticMeshes;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterialSlotWidgets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MaterialSlotWidgets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ApplyAllBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ApplyAllBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NoMeshText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectMeshTextAnim;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMAToolWindow constinit property declarations ******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyAllBtnPressed"), .Pointer = &UMAToolWindow::execApplyAllBtnPressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMAToolWindow_ApplyAllBtnPressed, "ApplyAllBtnPressed" }, // 3eec1b21f15a64715e93b7473330ccd01029906c
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMAToolWindow>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMAToolWindow Property Definitions ***************************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_SlotNames_Inner = { "SlotNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_SlotNames = { "SlotNames", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UMAToolWindow, SlotNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotNames_MetaData), NewProp_SlotNames_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedStaticMeshes_Inner = { "SelectedStaticMeshes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_SelectedStaticMeshes = { "SelectedStaticMeshes", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UMAToolWindow, SelectedStaticMeshes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedStaticMeshes_MetaData), NewProp_SelectedStaticMeshes_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MaterialSlotWidgets_Inner = { "MaterialSlotWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_UMAAssignmentSlot, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_MaterialSlotWidgets = { "MaterialSlotWidgets", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UMAToolWindow, MaterialSlotWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialSlotWidgets_MetaData), NewProp_MaterialSlotWidgets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ApplyAllBtn = { "ApplyAllBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAToolWindow, ApplyAllBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApplyAllBtn_MetaData), NewProp_ApplyAllBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SlotBox = { "SlotBox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAToolWindow, SlotBox), Z_Construct_UClass_UScrollBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotBox_MetaData), NewProp_SlotBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ApplyAllBox = { "ApplyAllBox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAToolWindow, ApplyAllBox), Z_Construct_UClass_UPanelWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApplyAllBox_MetaData), NewProp_ApplyAllBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NoMeshText = { "NoMeshText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAToolWindow, NoMeshText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NoMeshText_MetaData), NewProp_NoMeshText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectMeshTextAnim = { "SelectMeshTextAnim", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMAToolWindow, SelectMeshTextAnim), Z_Construct_UClass_UWidgetAnimation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectMeshTextAnim_MetaData), NewProp_SelectMeshTextAnim_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedStaticMeshes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedStaticMeshes,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialSlotWidgets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialSlotWidgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ApplyAllBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ApplyAllBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NoMeshText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectMeshTextAnim,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMAToolWindow Property Definitions *****************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UEditorUtilityWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_MaterialAssignment,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams UHT_STATICS::InterfaceParams[] = {
	{ Z_Construct_UClass_UMAToolWindowInterface, (int32)VTABLE_OFFSET(UMAToolWindow, IMAToolWindowInterface), false },  // 72a6aa3b217c9f823bd32b825a1d5167097d6f49
};
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMAToolWindow,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UMAToolWindow_StaticRegisterNativesUMAToolWindow()
{
	UClass* Class = UMAToolWindow::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMAToolWindow;
UClass* Z_Construct_UClass_UMAToolWindow(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMAToolWindow;
		if (!Z_Registration_Info_UClass_UMAToolWindow.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MAToolWindow"),
				Z_Registration_Info_UClass_UMAToolWindow.InnerSingleton,
				UMAToolWindow_StaticRegisterNativesUMAToolWindow,
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
		return Z_Registration_Info_UClass_UMAToolWindow.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMAToolWindow.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMAToolWindow.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMAToolWindow.OuterSingleton;
}
#undef UHT_STATICS
UMAToolWindow::UMAToolWindow(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMAToolWindow);
UMAToolWindow::~UMAToolWindow() {}
// ********** End Class UMAToolWindow **************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_UI_MAToolWindow_h__Script_MaterialAssignment_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMAToolWindow, TEXT("UMAToolWindow"), &Z_Registration_Info_UClass_UMAToolWindow, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMAToolWindow), 1054766990U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_UI_MAToolWindow_h__Script_MaterialAssignment_96c2ff1695728175b9b3e6c18b96c4a993adcb0d{
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
