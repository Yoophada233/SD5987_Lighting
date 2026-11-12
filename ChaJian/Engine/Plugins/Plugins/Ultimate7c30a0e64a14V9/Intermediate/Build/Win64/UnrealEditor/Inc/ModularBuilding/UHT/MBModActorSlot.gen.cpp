// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBModActorSlot.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBModActorSlot() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBModActorSlot(ETypeConstructPhase);
MODULARBUILDING_API UFunction* Z_Construct_UDelegateFunction_ModularBuilding_OnModActorSlotClickedSignature__DelegateSignature(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBModActorSlot(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FOnModActorSlotClickedSignature ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_ModularBuilding_OnModActorSlotClickedSignature__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_ModularBuilding_eventOnModActorSlotClickedSignature_Parms
	{
		int32 InSlotIndex;
		uint8 InSection;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModActorSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnModActorSlotClickedSignature constinit property declarations *******
	static const UECodeGen_Private::FIntPropertyParams NewProp_InSlotIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InSection;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnModActorSlotClickedSignature constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnModActorSlotClickedSignature Property Definitions ******************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_InSlotIndex = { "InSlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ModularBuilding_eventOnModActorSlotClickedSignature_Parms, InSlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InSection = { "InSection", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ModularBuilding_eventOnModActorSlotClickedSignature_Parms, InSection), nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InSlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InSection,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FOnModActorSlotClickedSignature Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding, nullptr, "OnModActorSlotClickedSignature__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_ModularBuilding_eventOnModActorSlotClickedSignature_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_ModularBuilding_eventOnModActorSlotClickedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ModularBuilding_OnModActorSlotClickedSignature__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FOnModActorSlotClickedSignature *****************************************

// ********** Begin Class UMBModActorSlot Function TabSlotSelectBtnPressed *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBModActorSlot_TabSlotSelectBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModActorSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TabSlotSelectBtnPressed constinit property declarations ***************
// ********** End Function TabSlotSelectBtnPressed constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBModActorSlot, nullptr, "TabSlotSelectBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBModActorSlot_TabSlotSelectBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBModActorSlot::execTabSlotSelectBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TabSlotSelectBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UMBModActorSlot Function TabSlotSelectBtnPressed ***************************

// ********** Begin Class UMBModActorSlot **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBModActorSlot_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/MBModActorSlot.h" },
		{ "ModuleRelativePath", "Public/UI/MBModActorSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialInterface_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/MBModActorSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TabSlotSelectBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModActorSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotImage_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/MBModActorSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBModActorSlot constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterialInterface;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TabSlotSelectBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotImage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBModActorSlot constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("TabSlotSelectBtnPressed"), .Pointer = &UMBModActorSlot::execTabSlotSelectBtnPressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBModActorSlot_TabSlotSelectBtnPressed, "TabSlotSelectBtnPressed" }, // b6686ed938218b2ef6fc0741ebbd77f4d79a86f2
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBModActorSlot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBModActorSlot Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MaterialInterface = { "MaterialInterface", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModActorSlot, MaterialInterface), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialInterface_MetaData), NewProp_MaterialInterface_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TabSlotSelectBtn = { "TabSlotSelectBtn", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModActorSlot, TabSlotSelectBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TabSlotSelectBtn_MetaData), NewProp_TabSlotSelectBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SlotImage = { "SlotImage", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBModActorSlot, SlotImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotImage_MetaData), NewProp_SlotImage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialInterface,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TabSlotSelectBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotImage,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBModActorSlot Property Definitions ***************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBModActorSlot,
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
static void UMBModActorSlot_StaticRegisterNativesUMBModActorSlot()
{
	UClass* Class = UMBModActorSlot::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBModActorSlot;
UClass* Z_Construct_UClass_UMBModActorSlot(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBModActorSlot;
		if (!Z_Registration_Info_UClass_UMBModActorSlot.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBModActorSlot"),
				Z_Registration_Info_UClass_UMBModActorSlot.InnerSingleton,
				UMBModActorSlot_StaticRegisterNativesUMBModActorSlot,
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
		return Z_Registration_Info_UClass_UMBModActorSlot.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBModActorSlot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBModActorSlot.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBModActorSlot.OuterSingleton;
}
#undef UHT_STATICS
UMBModActorSlot::UMBModActorSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBModActorSlot);
UMBModActorSlot::~UMBModActorSlot() {}
// ********** End Class UMBModActorSlot ************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBModActorSlot_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBModActorSlot, TEXT("UMBModActorSlot"), &Z_Registration_Info_UClass_UMBModActorSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBModActorSlot), 4215771964U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_UI_MBModActorSlot_h__Script_ModularBuilding_f67851d73de8b09136d6090d332946beb2119d9a{
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
