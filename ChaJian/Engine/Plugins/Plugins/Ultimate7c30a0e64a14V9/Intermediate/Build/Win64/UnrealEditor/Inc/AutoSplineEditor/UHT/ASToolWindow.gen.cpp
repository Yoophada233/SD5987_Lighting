// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASToolWindow.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeASToolWindow() {}

// ********** Begin Cross Module References ********************************************************
BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UCheckBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UContentWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UPanelWidget(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AutoSplineEditor(ETypeConstructPhase);
AUTOSPLINEEDITOR_API UClass* Z_Construct_UClass_UASToolWindow(ETypeConstructPhase);
AUTOSPLINEEDITOR_API UEnum* Z_Construct_UEnum_AutoSplineEditor_EAutoSplineEditorType(ETypeConstructPhase);
AUTOSPLINEEDITOR_API UClass* Z_Construct_UClass_UASSplineSlot(ETypeConstructPhase);
AUTOSPLINEEDITOR_API UClass* Z_Construct_UClass_UASToolWindow(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EAutoSplineEditorType *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_AutoSplineEditor_EAutoSplineEditorType_Statics
template<> AUTOSPLINEEDITOR_NON_ATTRIBUTED_API UEnum* StaticEnum<EAutoSplineEditorType>()
{
	return Z_Construct_UEnum_AutoSplineEditor_EAutoSplineEditorType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Auto Spline" },
		{ "CCDistribution.DisplayName", "Custom Class Distribution" },
		{ "CCDistribution.Name", "EAutoSplineEditorType::CCDistribution" },
		{ "Deformable.DisplayName", "Deformable Static Mesh" },
		{ "Deformable.Name", "EAutoSplineEditorType::Deformable" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EAutoSplineEditorType::None" },
		{ "SMDistribution.DisplayName", "Static Mesh Distribution" },
		{ "SMDistribution.Name", "EAutoSplineEditorType::SMDistribution" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAutoSplineEditorType::None", (int64)EAutoSplineEditorType::None },
		{ "EAutoSplineEditorType::Deformable", (int64)EAutoSplineEditorType::Deformable },
		{ "EAutoSplineEditorType::SMDistribution", (int64)EAutoSplineEditorType::SMDistribution },
		{ "EAutoSplineEditorType::CCDistribution", (int64)EAutoSplineEditorType::CCDistribution },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AutoSplineEditor,
	nullptr,
	"EAutoSplineEditorType",
	"EAutoSplineEditorType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EAutoSplineEditorType;
UEnum* Z_Construct_UEnum_AutoSplineEditor_EAutoSplineEditorType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EAutoSplineEditorType.OuterSingleton)
		{
			ZRIE_EAutoSplineEditorType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AutoSplineEditor_EAutoSplineEditorType, (UObject*)Z_Construct_UPackage__Script_AutoSplineEditor(ETypeConstructPhase::Outer), TEXT("EAutoSplineEditorType"));
		}
		return ZRIE_EAutoSplineEditorType.OuterSingleton;
	}
	if (!ZRIE_EAutoSplineEditorType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EAutoSplineEditorType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EAutoSplineEditorType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EAutoSplineEditorType *******************************************************

// ********** Begin Class UASToolWindow Function ClassDistributionBtnPressed ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASToolWindow_ClassDistributionBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClassDistributionBtnPressed constinit property declarations ***********
// ********** End Function ClassDistributionBtnPressed constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASToolWindow, nullptr, "ClassDistributionBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UASToolWindow_ClassDistributionBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASToolWindow::execClassDistributionBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClassDistributionBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UASToolWindow Function ClassDistributionBtnPressed *************************

// ********** Begin Class UASToolWindow Function CreateBtnPressed **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASToolWindow_CreateBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateBtnPressed constinit property declarations **********************
// ********** End Function CreateBtnPressed constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASToolWindow, nullptr, "CreateBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UASToolWindow_CreateBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASToolWindow::execCreateBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CreateBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UASToolWindow Function CreateBtnPressed ************************************

// ********** Begin Class UASToolWindow Function DeformableBtnPressed ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASToolWindow_DeformableBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DeformableBtnPressed constinit property declarations ******************
// ********** End Function DeformableBtnPressed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASToolWindow, nullptr, "DeformableBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UASToolWindow_DeformableBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASToolWindow::execDeformableBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DeformableBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UASToolWindow Function DeformableBtnPressed ********************************

// ********** Begin Class UASToolWindow Function MeshDistributionBtnPressed ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASToolWindow_MeshDistributionBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function MeshDistributionBtnPressed constinit property declarations ************
// ********** End Function MeshDistributionBtnPressed constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASToolWindow, nullptr, "MeshDistributionBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UASToolWindow_MeshDistributionBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASToolWindow::execMeshDistributionBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MeshDistributionBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UASToolWindow Function MeshDistributionBtnPressed **************************

// ********** Begin Class UASToolWindow Function SelectAllCheckboxChanged **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASToolWindow_SelectAllCheckboxChanged_Statics
struct UHT_STATICS
{
	struct ASToolWindow_eventSelectAllCheckboxChanged_Parms
	{
		bool InNewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SelectAllCheckboxChanged constinit property declarations **************
	static void NewProp_InNewState_SetBit(void* Obj)
	{
		((ASToolWindow_eventSelectAllCheckboxChanged_Parms*)Obj)->InNewState = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_InNewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SelectAllCheckboxChanged constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SelectAllCheckboxChanged Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_InNewState = { "InNewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ASToolWindow_eventSelectAllCheckboxChanged_Parms), &UHT_STATICS::NewProp_InNewState_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InNewState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SelectAllCheckboxChanged Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASToolWindow, nullptr, "SelectAllCheckboxChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ASToolWindow_eventSelectAllCheckboxChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ASToolWindow_eventSelectAllCheckboxChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UASToolWindow_SelectAllCheckboxChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASToolWindow::execSelectAllCheckboxChanged)
{
	P_GET_UBOOL(Z_Param_InNewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SelectAllCheckboxChanged(Z_Param_InNewState);
	P_NATIVE_END;
}
// ********** End Class UASToolWindow Function SelectAllCheckboxChanged ****************************

// ********** Begin Class UASToolWindow Function SelectBtnPressed **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASToolWindow_SelectBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SelectBtnPressed constinit property declarations **********************
// ********** End Function SelectBtnPressed constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASToolWindow, nullptr, "SelectBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UASToolWindow_SelectBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASToolWindow::execSelectBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SelectBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UASToolWindow Function SelectBtnPressed ************************************

// ********** Begin Class UASToolWindow Function ViewClassDistBtnPressed ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASToolWindow_ViewClassDistBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ViewClassDistBtnPressed constinit property declarations ***************
// ********** End Function ViewClassDistBtnPressed constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASToolWindow, nullptr, "ViewClassDistBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UASToolWindow_ViewClassDistBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASToolWindow::execViewClassDistBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ViewClassDistBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UASToolWindow Function ViewClassDistBtnPressed *****************************

// ********** Begin Class UASToolWindow Function ViewDeformableBtnPressed **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASToolWindow_ViewDeformableBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ViewDeformableBtnPressed constinit property declarations **************
// ********** End Function ViewDeformableBtnPressed constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASToolWindow, nullptr, "ViewDeformableBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UASToolWindow_ViewDeformableBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASToolWindow::execViewDeformableBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ViewDeformableBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UASToolWindow Function ViewDeformableBtnPressed ****************************

// ********** Begin Class UASToolWindow Function ViewMeshDistBtnPressed ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UASToolWindow_ViewMeshDistBtnPressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ViewMeshDistBtnPressed constinit property declarations ****************
// ********** End Function ViewMeshDistBtnPressed constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UASToolWindow, nullptr, "ViewMeshDistBtnPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UASToolWindow_ViewMeshDistBtnPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UASToolWindow::execViewMeshDistBtnPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ViewMeshDistBtnPressed();
	P_NATIVE_END;
}
// ********** End Class UASToolWindow Function ViewMeshDistBtnPressed ******************************

// ********** Begin Class UASToolWindow ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UASToolWindow_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/ASToolWindow.h" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplineSlots_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeformableBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshDistributionBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassDistributionBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewDeformableBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewMeshDistBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewClassDistBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CreateBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplineContentBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewList_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectAllCheckbox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ASToolWindow.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UASToolWindow constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SplineSlots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SplineSlots;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeformableBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshDistributionBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ClassDistributionBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ViewDeformableBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ViewMeshDistBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ViewClassDistBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CreateBtn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SplineContentBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ViewList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectAllCheckbox;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UASToolWindow constinit property declarations ******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ClassDistributionBtnPressed"), .Pointer = &UASToolWindow::execClassDistributionBtnPressed },
		{ .NameUTF8 = UTF8TEXT("CreateBtnPressed"), .Pointer = &UASToolWindow::execCreateBtnPressed },
		{ .NameUTF8 = UTF8TEXT("DeformableBtnPressed"), .Pointer = &UASToolWindow::execDeformableBtnPressed },
		{ .NameUTF8 = UTF8TEXT("MeshDistributionBtnPressed"), .Pointer = &UASToolWindow::execMeshDistributionBtnPressed },
		{ .NameUTF8 = UTF8TEXT("SelectAllCheckboxChanged"), .Pointer = &UASToolWindow::execSelectAllCheckboxChanged },
		{ .NameUTF8 = UTF8TEXT("SelectBtnPressed"), .Pointer = &UASToolWindow::execSelectBtnPressed },
		{ .NameUTF8 = UTF8TEXT("ViewClassDistBtnPressed"), .Pointer = &UASToolWindow::execViewClassDistBtnPressed },
		{ .NameUTF8 = UTF8TEXT("ViewDeformableBtnPressed"), .Pointer = &UASToolWindow::execViewDeformableBtnPressed },
		{ .NameUTF8 = UTF8TEXT("ViewMeshDistBtnPressed"), .Pointer = &UASToolWindow::execViewMeshDistBtnPressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UASToolWindow_ClassDistributionBtnPressed, "ClassDistributionBtnPressed" }, // 5d89662e3b2c3ac442289651e40e5ec0c7b4d008
		{ &Z_Construct_UFunction_UASToolWindow_CreateBtnPressed, "CreateBtnPressed" }, // 86ef9f8167c5cb8d515cf44615472b097bf59e48
		{ &Z_Construct_UFunction_UASToolWindow_DeformableBtnPressed, "DeformableBtnPressed" }, // 1a352bac2ced29f9aa3adc15dfabc72273e7e1d3
		{ &Z_Construct_UFunction_UASToolWindow_MeshDistributionBtnPressed, "MeshDistributionBtnPressed" }, // 9fae25957b1fb1526ad8d0ce08524b9dae23efe7
		{ &Z_Construct_UFunction_UASToolWindow_SelectAllCheckboxChanged, "SelectAllCheckboxChanged" }, // 74a91d1b3b3c7eee688faf3e21958ac5e2b52192
		{ &Z_Construct_UFunction_UASToolWindow_SelectBtnPressed, "SelectBtnPressed" }, // 075ef57d67c9183aacb868d0b6eada7f88a3b956
		{ &Z_Construct_UFunction_UASToolWindow_ViewClassDistBtnPressed, "ViewClassDistBtnPressed" }, // b9a39fe67d100805dbe86fa6788115550dc05d1f
		{ &Z_Construct_UFunction_UASToolWindow_ViewDeformableBtnPressed, "ViewDeformableBtnPressed" }, // d0a4a6ffbe0b60369526edd404e5c7da683cb49b
		{ &Z_Construct_UFunction_UASToolWindow_ViewMeshDistBtnPressed, "ViewMeshDistBtnPressed" }, // cd76911658fd540de80157b57e1e9d03adc85f9d
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UASToolWindow>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UASToolWindow Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SplineSlots_Inner = { "SplineSlots", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_UASSplineSlot, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_SplineSlots = { "SplineSlots", nullptr, (EPropertyFlags)0x0144008000000008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, SplineSlots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplineSlots_MetaData), NewProp_SplineSlots_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DeformableBtn = { "DeformableBtn", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, DeformableBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeformableBtn_MetaData), NewProp_DeformableBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MeshDistributionBtn = { "MeshDistributionBtn", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, MeshDistributionBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshDistributionBtn_MetaData), NewProp_MeshDistributionBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ClassDistributionBtn = { "ClassDistributionBtn", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, ClassDistributionBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassDistributionBtn_MetaData), NewProp_ClassDistributionBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ViewDeformableBtn = { "ViewDeformableBtn", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, ViewDeformableBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewDeformableBtn_MetaData), NewProp_ViewDeformableBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ViewMeshDistBtn = { "ViewMeshDistBtn", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, ViewMeshDistBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewMeshDistBtn_MetaData), NewProp_ViewMeshDistBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ViewClassDistBtn = { "ViewClassDistBtn", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, ViewClassDistBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewClassDistBtn_MetaData), NewProp_ViewClassDistBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectBtn = { "SelectBtn", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, SelectBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectBtn_MetaData), NewProp_SelectBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CreateBtn = { "CreateBtn", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, CreateBtn), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CreateBtn_MetaData), NewProp_CreateBtn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SplineContentBox = { "SplineContentBox", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, SplineContentBox), Z_Construct_UClass_UContentWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplineContentBox_MetaData), NewProp_SplineContentBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ViewList = { "ViewList", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, ViewList), Z_Construct_UClass_UPanelWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewList_MetaData), NewProp_ViewList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectAllCheckbox = { "SelectAllCheckbox", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UASToolWindow, SelectAllCheckbox), Z_Construct_UClass_UCheckBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectAllCheckbox_MetaData), NewProp_SelectAllCheckbox_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SplineSlots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SplineSlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DeformableBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MeshDistributionBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ClassDistributionBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ViewDeformableBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ViewMeshDistBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ViewClassDistBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CreateBtn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SplineContentBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ViewList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectAllCheckbox,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UASToolWindow Property Definitions *****************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UEditorUtilityWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AutoSplineEditor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UASToolWindow,
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
static void UASToolWindow_StaticRegisterNativesUASToolWindow()
{
	UClass* Class = UASToolWindow::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UASToolWindow;
UClass* Z_Construct_UClass_UASToolWindow(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UASToolWindow;
		if (!Z_Registration_Info_UClass_UASToolWindow.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ASToolWindow"),
				Z_Registration_Info_UClass_UASToolWindow.InnerSingleton,
				UASToolWindow_StaticRegisterNativesUASToolWindow,
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
		return Z_Registration_Info_UClass_UASToolWindow.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UASToolWindow.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UASToolWindow.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UASToolWindow.OuterSingleton;
}
#undef UHT_STATICS
UASToolWindow::UASToolWindow(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UASToolWindow);
UASToolWindow::~UASToolWindow() {}
// ********** End Class UASToolWindow **************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSplineEditor_Public_UI_ASToolWindow_h__Script_AutoSplineEditor_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_AutoSplineEditor_EAutoSplineEditorType, TEXT("EAutoSplineEditorType"), &ZRIE_EAutoSplineEditorType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3421616998U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UASToolWindow, TEXT("UASToolWindow"), &Z_Registration_Info_UClass_UASToolWindow, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UASToolWindow), 4034111454U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSplineEditor_Public_UI_ASToolWindow_h__Script_AutoSplineEditor_3011585966d3bb5b73cfdab747f5bd8cbce1cebb{
	TEXT("/Script/AutoSplineEditor"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
