// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODObjectSlot.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODObjectSlot() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UBorder(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UCheckBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODObjectSlot(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODObjectSlot(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODObjectSlot Function OnActivateCheckBoxChanged *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODObjectSlot_OnActivateCheckBoxChanged_Statics
struct UHT_STATICS
{
	struct ODObjectSlot_eventOnActivateCheckBoxChanged_Parms
	{
		bool bInNewCondition;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODObjectSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnActivateCheckBoxChanged constinit property declarations *************
	static void NewProp_bInNewCondition_SetBit(void* Obj)
	{
		((ODObjectSlot_eventOnActivateCheckBoxChanged_Parms*)Obj)->bInNewCondition = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInNewCondition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnActivateCheckBoxChanged constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnActivateCheckBoxChanged Property Definitions ************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInNewCondition = { "bInNewCondition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ODObjectSlot_eventOnActivateCheckBoxChanged_Parms), &UHT_STATICS::NewProp_bInNewCondition_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInNewCondition,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnActivateCheckBoxChanged Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODObjectSlot, nullptr, "OnActivateCheckBoxChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODObjectSlot_eventOnActivateCheckBoxChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODObjectSlot_eventOnActivateCheckBoxChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODObjectSlot_OnActivateCheckBoxChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODObjectSlot::execOnActivateCheckBoxChanged)
{
	P_GET_UBOOL(Z_Param_bInNewCondition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnActivateCheckBoxChanged(Z_Param_bInNewCondition);
	P_NATIVE_END;
}
// ********** End Class UODObjectSlot Function OnActivateCheckBoxChanged ***************************

// ********** Begin Class UODObjectSlot Function SlotSelectBtnPressed ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODObjectSlot_SlotSelectBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ODObjectSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SlotSelectBtnPressed constinit property declarations ******************
// ********** End Function SlotSelectBtnPressed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODObjectSlot, nullptr, "SlotSelectBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODObjectSlot_SlotSelectBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODObjectSlot::execSlotSelectBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SlotSelectBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UODObjectSlot Function SlotSelectBtnPressed ********************************

// ********** Begin Class UODObjectSlot ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODObjectSlot_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/ODObjectSlot.h" },
		{ "ModuleRelativePath", "Public/UI/ODObjectSlot.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotSelectBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODObjectSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotImage_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODObjectSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnCountText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODObjectSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetBorder_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODObjectSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CheckBoxBorder_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODObjectSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivateCheckBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ODObjectSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODObjectSlot constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotSelectBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnCountText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PresetBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CheckBoxBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActivateCheckBox;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODObjectSlot constinit property declarations ******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnActivateCheckBoxChanged"), .Pointer = &UODObjectSlot::execOnActivateCheckBoxChanged },
		{ .NameUTF8 = UTF8TEXT("SlotSelectBtnPressed"), .Pointer = &UODObjectSlot::execSlotSelectBtnPressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UODObjectSlot_OnActivateCheckBoxChanged, "OnActivateCheckBoxChanged" }, // 8ba56da86640582cffee966716af97d88a95f439
		{ &Z_Construct_UFunction_UODObjectSlot_SlotSelectBtnPressed, "SlotSelectBtnPressed" }, // 2d12a291c8c424f5c3e89a070a2730b0024730ac
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODObjectSlot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODObjectSlot Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SlotSelectBtn = { "SlotSelectBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODObjectSlot, SlotSelectBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotSelectBtn_MetaData), NewProp_SlotSelectBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SlotImage = { "SlotImage", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODObjectSlot, SlotImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotImage_MetaData), NewProp_SlotImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpawnCountText = { "SpawnCountText", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODObjectSlot, SpawnCountText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnCountText_MetaData), NewProp_SpawnCountText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PresetBorder = { "PresetBorder", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODObjectSlot, PresetBorder), Z_Construct_UClass_UBorder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetBorder_MetaData), NewProp_PresetBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CheckBoxBorder = { "CheckBoxBorder", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODObjectSlot, CheckBoxBorder), Z_Construct_UClass_UBorder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CheckBoxBorder_MetaData), NewProp_CheckBoxBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActivateCheckBox = { "ActivateCheckBox", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UODObjectSlot, ActivateCheckBox), Z_Construct_UClass_UCheckBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivateCheckBox_MetaData), NewProp_ActivateCheckBox_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotSelectBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnCountText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresetBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CheckBoxBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActivateCheckBox,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODObjectSlot Property Definitions *****************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODObjectSlot,
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
static void UODObjectSlot_StaticRegisterNativesUODObjectSlot()
{
	UClass* Class = UODObjectSlot::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UODObjectSlot;
UClass* Z_Construct_UClass_UODObjectSlot(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODObjectSlot;
		if (!Z_Registration_Info_UClass_UODObjectSlot.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODObjectSlot"),
				Z_Registration_Info_UClass_UODObjectSlot.InnerSingleton,
				UODObjectSlot_StaticRegisterNativesUODObjectSlot,
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
		return Z_Registration_Info_UClass_UODObjectSlot.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODObjectSlot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODObjectSlot.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODObjectSlot.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODObjectSlot);
UODObjectSlot::~UODObjectSlot() {}
// ********** End Class UODObjectSlot **************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_UI_ODObjectSlot_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODObjectSlot, TEXT("UODObjectSlot"), &Z_Registration_Info_UClass_UODObjectSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODObjectSlot), 2381682679U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_UI_ODObjectSlot_h__Script_ObjectDistribution_8d52f59fe0d0a1f89888558789a0f0e27760cbe0{
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
