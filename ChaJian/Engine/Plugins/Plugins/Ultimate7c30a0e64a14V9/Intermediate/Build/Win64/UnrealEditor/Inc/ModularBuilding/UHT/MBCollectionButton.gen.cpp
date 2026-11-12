// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBCollectionButton.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBCollectionButton() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBCollectionButton(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBCollectionButton(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBCollectionButton Function ModularCollectionBtnPressed *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBCollectionButton_ModularCollectionBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBCollectionButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ModularCollectionBtnPressed constinit property declarations ***********
// ********** End Function ModularCollectionBtnPressed constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBCollectionButton, nullptr, "ModularCollectionBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBCollectionButton_ModularCollectionBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBCollectionButton::execModularCollectionBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ModularCollectionBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMBCollectionButton Function ModularCollectionBtnPressed *******************

// ********** Begin Class UMBCollectionButton Function OnTimerFinished *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBCollectionButton_OnTimerFinished_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBCollectionButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnTimerFinished constinit property declarations ***********************
// ********** End Function OnTimerFinished constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBCollectionButton, nullptr, "OnTimerFinished", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBCollectionButton_OnTimerFinished(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBCollectionButton::execOnTimerFinished)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnTimerFinished();
	P_NATIVE_END;
}
// ********** End Class UMBCollectionButton Function OnTimerFinished *******************************

// ********** Begin Class UMBCollectionButton Function SetSelectionState ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBCollectionButton_SetSelectionState_Statics
struct UHT_STATICS
{
	struct MBCollectionButton_eventSetSelectionState_Parms
	{
		bool InSelectionState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBCollectionButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSelectionState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSelectionState constinit property declarations *********************
	static void NewProp_InSelectionState_SetBit(void* Obj)
	{
		((MBCollectionButton_eventSetSelectionState_Parms*)Obj)->InSelectionState = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_InSelectionState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSelectionState constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSelectionState Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_InSelectionState = { "InSelectionState", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(MBCollectionButton_eventSetSelectionState_Parms), &UHT_STATICS::NewProp_InSelectionState_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSelectionState_MetaData), NewProp_InSelectionState_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InSelectionState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetSelectionState Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBCollectionButton, nullptr, "SetSelectionState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBCollectionButton_eventSetSelectionState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBCollectionButton_eventSetSelectionState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBCollectionButton_SetSelectionState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBCollectionButton::execSetSelectionState)
{
	P_GET_UBOOL(Z_Param_InSelectionState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSelectionState(Z_Param_InSelectionState);
	P_NATIVE_END;
}
// ********** End Class UMBCollectionButton Function SetSelectionState *****************************

// ********** Begin Class UMBCollectionButton ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBCollectionButton_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/MBCollectionButton.h" },
		{ "ModuleRelativePath", "Public/UI/MBCollectionButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollectionName_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBCollectionButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModularCollectionBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBCollectionButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollectionText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBCollectionButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBCollectionButton constinit property declarations **********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_CollectionName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ModularCollectionBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollectionText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBCollectionButton constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ModularCollectionBtnPressed"), .Pointer = &UMBCollectionButton::execModularCollectionBtnPressed },
		{ .NameUTF8 = UTF8TEXT("OnTimerFinished"), .Pointer = &UMBCollectionButton::execOnTimerFinished },
		{ .NameUTF8 = UTF8TEXT("SetSelectionState"), .Pointer = &UMBCollectionButton::execSetSelectionState },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBCollectionButton_ModularCollectionBtnPressed, "ModularCollectionBtnPressed" }, // aaaccdbe288468905d9ca1bf753a27cb1e82ba32
		{ &Z_Construct_UFunction_UMBCollectionButton_OnTimerFinished, "OnTimerFinished" }, // 993bf5845271a01ac234d96bf5066145e103852a
		{ &Z_Construct_UFunction_UMBCollectionButton_SetSelectionState, "SetSelectionState" }, // 9c88035231ca1cdc2f31aa4b810c360bb8a33d92
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBCollectionButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBCollectionButton Property Definitions *********************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_CollectionName = { "CollectionName", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UMBCollectionButton, CollectionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollectionName_MetaData), NewProp_CollectionName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ModularCollectionBtn = { "ModularCollectionBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBCollectionButton, ModularCollectionBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModularCollectionBtn_MetaData), NewProp_ModularCollectionBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CollectionText = { "CollectionText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBCollectionButton, CollectionText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollectionText_MetaData), NewProp_CollectionText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CollectionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ModularCollectionBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CollectionText,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBCollectionButton Property Definitions ***********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBCollectionButton,
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
static void UMBCollectionButton_StaticRegisterNativesUMBCollectionButton()
{
	UClass* Class = UMBCollectionButton::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBCollectionButton;
UClass* Z_Construct_UClass_UMBCollectionButton(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBCollectionButton;
		if (!Z_Registration_Info_UClass_UMBCollectionButton.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBCollectionButton"),
				Z_Registration_Info_UClass_UMBCollectionButton.InnerSingleton,
				UMBCollectionButton_StaticRegisterNativesUMBCollectionButton,
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
		return Z_Registration_Info_UClass_UMBCollectionButton.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBCollectionButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBCollectionButton.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBCollectionButton.OuterSingleton;
}
#undef UHT_STATICS
UMBCollectionButton::UMBCollectionButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBCollectionButton);
UMBCollectionButton::~UMBCollectionButton() {}
// ********** End Class UMBCollectionButton ********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBCollectionButton_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBCollectionButton, TEXT("UMBCollectionButton"), &Z_Registration_Info_UClass_UMBCollectionButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBCollectionButton), 2877557432U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBCollectionButton_h__Script_ModularBuilding_90aafd0ea13c61be8563b1afb87a170c6025e072{
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
