// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBToolSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBToolSubsystem() {}

// ********** Begin Cross Module References ********************************************************
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UDataTable(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EBuildingCategory(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBWorkingMode(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EPlacementMode(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBToolSubsystem(ETypeConstructPhase);
MODULARBUILDING_API UFunction* Z_Construct_UDelegateFunction_ModularBuilding_OnPlacementTypeChanged__DelegateSignature(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBToolData(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBToolSubsystem(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBUserSettings(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FOnPlacementTypeChanged ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_ModularBuilding_OnPlacementTypeChanged__DelegateSignature_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnPlacementTypeChanged constinit property declarations ***************
// ********** End Delegate FOnPlacementTypeChanged constinit property declarations *****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding, nullptr, "OnPlacementTypeChanged__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UDelegateFunction_ModularBuilding_OnPlacementTypeChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FOnPlacementTypeChanged *************************************************

// ********** Begin Class UMBToolSubsystem *********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBToolSubsystem_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/MBToolSubsystem.h" },
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolUserSettings_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModularAssetData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MBToolMainScreen_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnNewAssetsAdded_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPlacementTypeChanged_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsTheSettingsOn_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlacementMode_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsMouseOnToolWindow_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovedAssetCategory_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorkingMode_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsDuplicationInprogress_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastActiveCollectionIndex_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveCollectionWindow_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsShiftPressed_MetaData[] = {
		{ "Comment", "//Input Modifiers\n" },
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
		{ "ToolTip", "Input Modifiers" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsCtrlPressed_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastCreatedAsset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBToolSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBToolSubsystem constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToolData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToolUserSettings;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ModularAssetData;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_MBToolMainScreen;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnNewAssetsAdded;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlacementTypeChanged;
	static void NewProp_IsTheSettingsOn_SetBit(void* Obj)
	{
		((UMBToolSubsystem*)Obj)->IsTheSettingsOn = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsTheSettingsOn;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PlacementMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PlacementMode;
	static void NewProp_bIsMouseOnToolWindow_SetBit(void* Obj)
	{
		((UMBToolSubsystem*)Obj)->bIsMouseOnToolWindow = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMouseOnToolWindow;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MovedAssetCategory_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MovedAssetCategory;
	static const UECodeGen_Private::FBytePropertyParams NewProp_WorkingMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_WorkingMode;
	static void NewProp_bIsDuplicationInprogress_SetBit(void* Obj)
	{
		((UMBToolSubsystem*)Obj)->bIsDuplicationInprogress = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsDuplicationInprogress;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LastActiveCollectionIndex;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ActiveCollectionWindow;
	static void NewProp_bIsShiftPressed_SetBit(void* Obj)
	{
		((UMBToolSubsystem*)Obj)->bIsShiftPressed = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsShiftPressed;
	static void NewProp_bIsCtrlPressed_SetBit(void* Obj)
	{
		((UMBToolSubsystem*)Obj)->bIsCtrlPressed = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsCtrlPressed;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LastCreatedAsset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBToolSubsystem constinit property declarations ***************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBToolSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBToolSubsystem Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ToolData = { "ToolData", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, ToolData), Z_Construct_UClass_UMBToolData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolData_MetaData), NewProp_ToolData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ToolUserSettings = { "ToolUserSettings", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, ToolUserSettings), Z_Construct_UClass_UMBUserSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolUserSettings_MetaData), NewProp_ToolUserSettings_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ModularAssetData = { "ModularAssetData", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, ModularAssetData), Z_Construct_UClass_UDataTable, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModularAssetData_MetaData), NewProp_ModularAssetData_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams UHT_STATICS::NewProp_MBToolMainScreen = { "MBToolMainScreen", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, MBToolMainScreen), Z_Construct_UClass_UObject, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MBToolMainScreen_MetaData), NewProp_MBToolMainScreen_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnNewAssetsAdded = { "OnNewAssetsAdded", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, OnNewAssetsAdded), Z_Construct_UDelegateFunction_ModularBuilding_OnPlacementTypeChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnNewAssetsAdded_MetaData), NewProp_OnNewAssetsAdded_MetaData) }; // 3f2b5ea589fa8a14424bc8969a7ea01d7f0c8c8e
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnPlacementTypeChanged = { "OnPlacementTypeChanged", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, OnPlacementTypeChanged), Z_Construct_UDelegateFunction_ModularBuilding_OnPlacementTypeChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPlacementTypeChanged_MetaData), NewProp_OnPlacementTypeChanged_MetaData) }; // 3f2b5ea589fa8a14424bc8969a7ea01d7f0c8c8e
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_IsTheSettingsOn = { "IsTheSettingsOn", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBToolSubsystem), &UHT_STATICS::NewProp_IsTheSettingsOn_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsTheSettingsOn_MetaData), NewProp_IsTheSettingsOn_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_PlacementMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_PlacementMode = { "PlacementMode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, PlacementMode), Z_Construct_UEnum_ModularBuilding_EPlacementMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlacementMode_MetaData), NewProp_PlacementMode_MetaData) }; // 0993f5001b1cd1a1a7df86e4ff4e7a71742cd071
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsMouseOnToolWindow = { "bIsMouseOnToolWindow", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBToolSubsystem), &UHT_STATICS::NewProp_bIsMouseOnToolWindow_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsMouseOnToolWindow_MetaData), NewProp_bIsMouseOnToolWindow_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_MovedAssetCategory_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_MovedAssetCategory = { "MovedAssetCategory", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, MovedAssetCategory), Z_Construct_UEnum_ModularBuilding_EBuildingCategory, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovedAssetCategory_MetaData), NewProp_MovedAssetCategory_MetaData) }; // 07cf8117a6e577cac6ce1c747d6b11cc85196fdc
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_WorkingMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_WorkingMode = { "WorkingMode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, WorkingMode), Z_Construct_UEnum_ModularBuilding_EMBWorkingMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorkingMode_MetaData), NewProp_WorkingMode_MetaData) }; // 493d2844b215f4431c6b3892ec315a12e2549200
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsDuplicationInprogress = { "bIsDuplicationInprogress", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBToolSubsystem), &UHT_STATICS::NewProp_bIsDuplicationInprogress_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsDuplicationInprogress_MetaData), NewProp_bIsDuplicationInprogress_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_LastActiveCollectionIndex = { "LastActiveCollectionIndex", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, LastActiveCollectionIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastActiveCollectionIndex_MetaData), NewProp_LastActiveCollectionIndex_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_ActiveCollectionWindow = { "ActiveCollectionWindow", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, ActiveCollectionWindow), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveCollectionWindow_MetaData), NewProp_ActiveCollectionWindow_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsShiftPressed = { "bIsShiftPressed", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBToolSubsystem), &UHT_STATICS::NewProp_bIsShiftPressed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsShiftPressed_MetaData), NewProp_bIsShiftPressed_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsCtrlPressed = { "bIsCtrlPressed", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBToolSubsystem), &UHT_STATICS::NewProp_bIsCtrlPressed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsCtrlPressed_MetaData), NewProp_bIsCtrlPressed_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_LastCreatedAsset = { "LastCreatedAsset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UMBToolSubsystem, LastCreatedAsset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastCreatedAsset_MetaData), NewProp_LastCreatedAsset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ToolData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ToolUserSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ModularAssetData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MBToolMainScreen,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnNewAssetsAdded,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnPlacementTypeChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_IsTheSettingsOn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlacementMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlacementMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsMouseOnToolWindow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MovedAssetCategory_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MovedAssetCategory,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorkingMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorkingMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsDuplicationInprogress,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastActiveCollectionIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActiveCollectionWindow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsShiftPressed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsCtrlPressed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastCreatedAsset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBToolSubsystem Property Definitions **************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UEditorSubsystem,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBToolSubsystem,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UMBToolSubsystem;
UClass* Z_Construct_UClass_UMBToolSubsystem(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBToolSubsystem;
		if (!Z_Registration_Info_UClass_UMBToolSubsystem.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBToolSubsystem"),
				Z_Registration_Info_UClass_UMBToolSubsystem.InnerSingleton,
				nullptr,
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
		return Z_Registration_Info_UClass_UMBToolSubsystem.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBToolSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBToolSubsystem.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBToolSubsystem.OuterSingleton;
}
#undef UHT_STATICS
UMBToolSubsystem::UMBToolSubsystem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBToolSubsystem);
UMBToolSubsystem::~UMBToolSubsystem() {}
// ********** End Class UMBToolSubsystem ***********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBToolSubsystem_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBToolSubsystem, TEXT("UMBToolSubsystem"), &Z_Registration_Info_UClass_UMBToolSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBToolSubsystem), 947070725U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBToolSubsystem_h__Script_ModularBuilding_3980d4b508858d131e9ba94c895cc84c113d6417{
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
