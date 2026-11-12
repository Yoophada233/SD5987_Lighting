// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBUserSettingsWindow.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBUserSettingsWindow() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
SCRIPTABLEEDITORWIDGETS_API UClass* Z_Construct_UClass_UDetailsView(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBUserSettingsWindow(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBUserSettingsObject(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBUserSettingsWindow(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBUserSettingsWindow Function ClearTheSceneBtnPressed *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBUserSettingsWindow_ClearTheSceneBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBUserSettingsWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearTheSceneBtnPressed constinit property declarations ***************
// ********** End Function ClearTheSceneBtnPressed constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBUserSettingsWindow, nullptr, "ClearTheSceneBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBUserSettingsWindow_ClearTheSceneBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBUserSettingsWindow::execClearTheSceneBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearTheSceneBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMBUserSettingsWindow Function ClearTheSceneBtnPressed *********************

// ********** Begin Class UMBUserSettingsWindow Function ResetToolBtnPressed ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBUserSettingsWindow_ResetToolBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBUserSettingsWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetToolBtnPressed constinit property declarations *******************
// ********** End Function ResetToolBtnPressed constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBUserSettingsWindow, nullptr, "ResetToolBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBUserSettingsWindow_ResetToolBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBUserSettingsWindow::execResetToolBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetToolBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMBUserSettingsWindow Function ResetToolBtnPressed *************************

// ********** Begin Class UMBUserSettingsWindow ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBUserSettingsWindow_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/MBUserSettingsWindow.h" },
		{ "ModuleRelativePath", "Public/UI/MBUserSettingsWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserSettingsObject_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBUserSettingsWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResetToolBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBUserSettingsWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClearTheSceneBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBUserSettingsWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserSettingsDetails_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Modular Building" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBUserSettingsWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBUserSettingsWindow constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UserSettingsObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ResetToolBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ClearTheSceneBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UserSettingsDetails;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBUserSettingsWindow constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ClearTheSceneBtnPressed"), .Pointer = &UMBUserSettingsWindow::execClearTheSceneBtnPressed },
		{ .NameUTF8 = UTF8TEXT("ResetToolBtnPressed"), .Pointer = &UMBUserSettingsWindow::execResetToolBtnPressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBUserSettingsWindow_ClearTheSceneBtnPressed, "ClearTheSceneBtnPressed" }, // e282256f07ebb3f137a900de18c2338a51a892ef
		{ &Z_Construct_UFunction_UMBUserSettingsWindow_ResetToolBtnPressed, "ResetToolBtnPressed" }, // 82118c0fb02ec7703c34175093fb6d17c2f0ddd1
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBUserSettingsWindow>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBUserSettingsWindow Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_UserSettingsObject = { "UserSettingsObject", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsWindow, UserSettingsObject), Z_Construct_UClass_UMBUserSettingsObject, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserSettingsObject_MetaData), NewProp_UserSettingsObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ResetToolBtn = { "ResetToolBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsWindow, ResetToolBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResetToolBtn_MetaData), NewProp_ResetToolBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ClearTheSceneBtn = { "ClearTheSceneBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsWindow, ClearTheSceneBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClearTheSceneBtn_MetaData), NewProp_ClearTheSceneBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_UserSettingsDetails = { "UserSettingsDetails", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBUserSettingsWindow, UserSettingsDetails), Z_Construct_UClass_UDetailsView, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserSettingsDetails_MetaData), NewProp_UserSettingsDetails_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UserSettingsObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ResetToolBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ClearTheSceneBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UserSettingsDetails,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBUserSettingsWindow Property Definitions *********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBUserSettingsWindow,
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
static void UMBUserSettingsWindow_StaticRegisterNativesUMBUserSettingsWindow()
{
	UClass* Class = UMBUserSettingsWindow::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBUserSettingsWindow;
UClass* Z_Construct_UClass_UMBUserSettingsWindow(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBUserSettingsWindow;
		if (!Z_Registration_Info_UClass_UMBUserSettingsWindow.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBUserSettingsWindow"),
				Z_Registration_Info_UClass_UMBUserSettingsWindow.InnerSingleton,
				UMBUserSettingsWindow_StaticRegisterNativesUMBUserSettingsWindow,
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
		return Z_Registration_Info_UClass_UMBUserSettingsWindow.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBUserSettingsWindow.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBUserSettingsWindow.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBUserSettingsWindow.OuterSingleton;
}
#undef UHT_STATICS
UMBUserSettingsWindow::UMBUserSettingsWindow(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBUserSettingsWindow);
UMBUserSettingsWindow::~UMBUserSettingsWindow() {}
// ********** End Class UMBUserSettingsWindow ******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBUserSettingsWindow_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBUserSettingsWindow, TEXT("UMBUserSettingsWindow"), &Z_Registration_Info_UClass_UMBUserSettingsWindow, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBUserSettingsWindow), 4086465064U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBUserSettingsWindow_h__Script_ModularBuilding_dd4cfe5d4ce620a3e4cf9d0f428846c0d3fb4cdc{
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
