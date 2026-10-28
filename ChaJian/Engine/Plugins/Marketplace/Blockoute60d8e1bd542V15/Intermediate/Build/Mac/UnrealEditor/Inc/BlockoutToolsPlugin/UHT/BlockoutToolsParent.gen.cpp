// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlockoutToolsParent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeBlockoutToolsParent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UBillboardComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USceneComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_BlockoutToolsPlugin(ETypeConstructPhase);
BLOCKOUTTOOLSPLUGIN_API UClass* Z_Construct_UClass_ABlockoutToolsParent(ETypeConstructPhase);
BLOCKOUTTOOLSPLUGIN_API UEnum* Z_Construct_UEnum_BlockoutToolsPlugin_EBlockoutMaterialType(ETypeConstructPhase);
BLOCKOUTTOOLSPLUGIN_API UClass* Z_Construct_UClass_ABlockoutToolsParent(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EBlockoutMaterialType *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_BlockoutToolsPlugin_EBlockoutMaterialType_Statics
template<> BLOCKOUTTOOLSPLUGIN_NON_ATTRIBUTED_API UEnum* StaticEnum<EBlockoutMaterialType>()
{
	return Z_Construct_UEnum_BlockoutToolsPlugin_EBlockoutMaterialType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlockoutMaterialType_CustomMaterial.DisplayName", "Custom Material" },
		{ "BlockoutMaterialType_CustomMaterial.Name", "BlockoutMaterialType_CustomMaterial" },
		{ "BlockoutMaterialType_Grid.DisplayName", "Blockout Grid" },
		{ "BlockoutMaterialType_Grid.Name", "BlockoutMaterialType_Grid" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "BlockoutMaterialType_Grid", (int64)BlockoutMaterialType_Grid },
		{ "BlockoutMaterialType_CustomMaterial", (int64)BlockoutMaterialType_CustomMaterial },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_BlockoutToolsPlugin,
	nullptr,
	"EBlockoutMaterialType",
	"EBlockoutMaterialType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	(uint8)UEnum::EUnderlyingType::int32,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EBlockoutMaterialType;
UEnum* Z_Construct_UEnum_BlockoutToolsPlugin_EBlockoutMaterialType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EBlockoutMaterialType.OuterSingleton)
		{
			ZRIE_EBlockoutMaterialType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_BlockoutToolsPlugin_EBlockoutMaterialType, (UObject*)Z_Construct_UPackage__Script_BlockoutToolsPlugin(ETypeConstructPhase::Outer), TEXT("EBlockoutMaterialType"));
		}
		return ZRIE_EBlockoutMaterialType.OuterSingleton;
	}
	if (!ZRIE_EBlockoutMaterialType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EBlockoutMaterialType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EBlockoutMaterialType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EBlockoutMaterialType *******************************************************

// ********** Begin Class ABlockoutToolsParent Function BlockoutSetMaterial ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ABlockoutToolsParent_BlockoutSetMaterial_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Blockout Tools" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BlockoutSetMaterial constinit property declarations *******************
// ********** End Function BlockoutSetMaterial constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ABlockoutToolsParent, nullptr, "BlockoutSetMaterial", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ABlockoutToolsParent_BlockoutSetMaterial(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ABlockoutToolsParent::execBlockoutSetMaterial)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BlockoutSetMaterial();
	P_NATIVE_END;
}
// ********** End Class ABlockoutToolsParent Function BlockoutSetMaterial **************************

// ********** Begin Class ABlockoutToolsParent Function RerunConstructionScript ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ABlockoutToolsParent_RerunConstructionScript_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Blockout Tools" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RerunConstructionScript constinit property declarations ***************
// ********** End Function RerunConstructionScript constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ABlockoutToolsParent, nullptr, "RerunConstructionScript", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ABlockoutToolsParent_RerunConstructionScript(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ABlockoutToolsParent::execRerunConstructionScript)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RerunConstructionScript();
	P_NATIVE_END;
}
// ********** End Class ABlockoutToolsParent Function RerunConstructionScript **********************

// ********** Begin Class ABlockoutToolsParent *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ABlockoutToolsParent_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "BlockoutToolsParent.h" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[] = {
		{ "Category", "Blockout Tools" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Billboard_MetaData[] = {
		{ "Category", "Blockout Tools" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutGridParent_MetaData[] = {
		{ "Category", "Blockout Tools" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutGridMID_MetaData[] = {
		{ "Category", "Blockout Tools" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutCurrentMaterial_MetaData[] = {
		{ "Category", "Blockout Tools" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutMeshComponents_MetaData[] = {
		{ "Category", "Blockout Tools" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutMaterialType_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "DisplayName", "Material Type" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutMaterialColor_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "DisplayName", "Color" },
		{ "EditCondition", "BlockoutMaterialType == EBlockoutMaterialType::BlockoutMaterialType_Grid" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBlockoutMaterialUseGrid_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "DisplayName", "Use Grid" },
		{ "EditCondition", "BlockoutMaterialType == EBlockoutMaterialType::BlockoutMaterialType_Grid" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBlockoutWorldAligned_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "Comment", "// Sets if triplanar material is local-aligned or world-aligned\n" },
		{ "DisplayName", "World Aligned" },
		{ "EditCondition", "BlockoutMaterialType == EBlockoutMaterialType::BlockoutMaterialType_Grid" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
		{ "ToolTip", "Sets if triplanar material is local-aligned or world-aligned" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutMaterialGridSize_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "DisplayName", "Grid Size" },
		{ "EditCondition", "bBlockoutMaterialUseGrid && BlockoutMaterialType == EBlockoutMaterialType::BlockoutMaterialType_Grid" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutMaterialCheckerLuminance_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "DisplayName", "Checker Luminance" },
		{ "EditCondition", "bBlockoutMaterialUseGrid && BlockoutMaterialType == EBlockoutMaterialType::BlockoutMaterialType_Grid" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutMaterialRoughness_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "DisplayName", "Roughness" },
		{ "EditCondition", "BlockoutMaterialType == EBlockoutMaterialType::BlockoutMaterialType_Grid" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBlockoutMaterialUseTopColor_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "DisplayName", "Use Top Color" },
		{ "EditCondition", "BlockoutMaterialType == EBlockoutMaterialType::BlockoutMaterialType_Grid" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutMaterialTopColor_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "DisplayName", "Top Color" },
		{ "EditCondition", "bBlockoutMaterialUseTopColor && BlockoutMaterialType == EBlockoutMaterialType::BlockoutMaterialType_Grid" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseCustomMaterial_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "DisplayName", "Use Custom Material" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomMaterial_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "DisplayName", "Custom Material" },
		{ "EditCondition", "BlockoutMaterialType == EBlockoutMaterialType::BlockoutMaterialType_CustomMaterial" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutCustomMaterial_MetaData[] = {
		{ "Category", "Blockout Tools|Blockout Material" },
		{ "DisplayName", "Custom Material" },
		{ "EditCondition", "BlockoutMaterialType == EBlockoutMaterialType::BlockoutMaterialType_CustomMaterial" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBlockoutEnableCollisions_MetaData[] = {
		{ "Category", "Blockout Tools|Collision" },
		{ "DisplayName", "Enable Actor Collision" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBlockoutEnableCustomCollision_MetaData[] = {
		{ "Category", "Blockout Tools|Collision" },
		{ "Comment", "//, meta = (InlineEditConditionToggle))\n" },
		{ "DisplayName", "Enable Custom Collision" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
		{ "ToolTip", ", meta = (InlineEditConditionToggle))" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockoutCustomCollisionProfileName_MetaData[] = {
		{ "Category", "Blockout Tools|Collision" },
		{ "DisplayName", "Custom Collision Profile Name" },
		{ "EditCondition", "bBlockoutEnableCustomCollision" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBlockoutCastShadows_MetaData[] = {
		{ "Category", "Blockout Tools|Rendering" },
		{ "DisplayName", "Cast Shadows" },
		{ "ModuleRelativePath", "Private/BlockoutToolsParent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ABlockoutToolsParent constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Root;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Billboard;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BlockoutGridParent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BlockoutGridMID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BlockoutCurrentMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BlockoutMeshComponents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_BlockoutMeshComponents;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BlockoutMaterialType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BlockoutMaterialColor;
	static void NewProp_bBlockoutMaterialUseGrid_SetBit(void* Obj)
	{
		((ABlockoutToolsParent*)Obj)->bBlockoutMaterialUseGrid = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBlockoutMaterialUseGrid;
	static void NewProp_bBlockoutWorldAligned_SetBit(void* Obj)
	{
		((ABlockoutToolsParent*)Obj)->bBlockoutWorldAligned = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBlockoutWorldAligned;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlockoutMaterialGridSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlockoutMaterialCheckerLuminance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlockoutMaterialRoughness;
	static void NewProp_bBlockoutMaterialUseTopColor_SetBit(void* Obj)
	{
		((ABlockoutToolsParent*)Obj)->bBlockoutMaterialUseTopColor = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBlockoutMaterialUseTopColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BlockoutMaterialTopColor;
	static void NewProp_bUseCustomMaterial_SetBit(void* Obj)
	{
		((ABlockoutToolsParent*)Obj)->bUseCustomMaterial = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseCustomMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CustomMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BlockoutCustomMaterial;
	static void NewProp_bBlockoutEnableCollisions_SetBit(void* Obj)
	{
		((ABlockoutToolsParent*)Obj)->bBlockoutEnableCollisions = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBlockoutEnableCollisions;
	static void NewProp_bBlockoutEnableCustomCollision_SetBit(void* Obj)
	{
		((ABlockoutToolsParent*)Obj)->bBlockoutEnableCustomCollision = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBlockoutEnableCustomCollision;
	static const UECodeGen_Private::FNamePropertyParams NewProp_BlockoutCustomCollisionProfileName;
	static void NewProp_bBlockoutCastShadows_SetBit(void* Obj)
	{
		((ABlockoutToolsParent*)Obj)->bBlockoutCastShadows = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBlockoutCastShadows;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ABlockoutToolsParent constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BlockoutSetMaterial"), .Pointer = &ABlockoutToolsParent::execBlockoutSetMaterial },
		{ .NameUTF8 = UTF8TEXT("RerunConstructionScript"), .Pointer = &ABlockoutToolsParent::execRerunConstructionScript },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABlockoutToolsParent_BlockoutSetMaterial, "BlockoutSetMaterial" }, // 3ad8af103343dfb6724b1da236d6154f167e15a7
		{ &Z_Construct_UFunction_ABlockoutToolsParent_RerunConstructionScript, "RerunConstructionScript" }, // 8bebcaae4d51f091238f8e5ba6aff40106611156
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABlockoutToolsParent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ABlockoutToolsParent Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, Root), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Root_MetaData), NewProp_Root_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Billboard = { "Billboard", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, Billboard), Z_Construct_UClass_UBillboardComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Billboard_MetaData), NewProp_Billboard_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BlockoutGridParent = { "BlockoutGridParent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutGridParent), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutGridParent_MetaData), NewProp_BlockoutGridParent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BlockoutGridMID = { "BlockoutGridMID", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutGridMID), Z_Construct_UClass_UMaterialInstanceDynamic, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutGridMID_MetaData), NewProp_BlockoutGridMID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BlockoutCurrentMaterial = { "BlockoutCurrentMaterial", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutCurrentMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutCurrentMaterial_MetaData), NewProp_BlockoutCurrentMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BlockoutMeshComponents_Inner = { "BlockoutMeshComponents", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_BlockoutMeshComponents = { "BlockoutMeshComponents", nullptr, (EPropertyFlags)0x001000800000001c, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutMeshComponents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutMeshComponents_MetaData), NewProp_BlockoutMeshComponents_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_BlockoutMaterialType = { "BlockoutMaterialType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutMaterialType), Z_Construct_UEnum_BlockoutToolsPlugin_EBlockoutMaterialType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutMaterialType_MetaData), NewProp_BlockoutMaterialType_MetaData) }; // 201ce16c7d3250e80c9aa82f3f20975df83458c3
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_BlockoutMaterialColor = { "BlockoutMaterialColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutMaterialColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutMaterialColor_MetaData), NewProp_BlockoutMaterialColor_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bBlockoutMaterialUseGrid = { "bBlockoutMaterialUseGrid", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ABlockoutToolsParent), &UHT_STATICS::NewProp_bBlockoutMaterialUseGrid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBlockoutMaterialUseGrid_MetaData), NewProp_bBlockoutMaterialUseGrid_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bBlockoutWorldAligned = { "bBlockoutWorldAligned", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ABlockoutToolsParent), &UHT_STATICS::NewProp_bBlockoutWorldAligned_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBlockoutWorldAligned_MetaData), NewProp_bBlockoutWorldAligned_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BlockoutMaterialGridSize = { "BlockoutMaterialGridSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutMaterialGridSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutMaterialGridSize_MetaData), NewProp_BlockoutMaterialGridSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BlockoutMaterialCheckerLuminance = { "BlockoutMaterialCheckerLuminance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutMaterialCheckerLuminance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutMaterialCheckerLuminance_MetaData), NewProp_BlockoutMaterialCheckerLuminance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BlockoutMaterialRoughness = { "BlockoutMaterialRoughness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutMaterialRoughness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutMaterialRoughness_MetaData), NewProp_BlockoutMaterialRoughness_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bBlockoutMaterialUseTopColor = { "bBlockoutMaterialUseTopColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ABlockoutToolsParent), &UHT_STATICS::NewProp_bBlockoutMaterialUseTopColor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBlockoutMaterialUseTopColor_MetaData), NewProp_bBlockoutMaterialUseTopColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_BlockoutMaterialTopColor = { "BlockoutMaterialTopColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutMaterialTopColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutMaterialTopColor_MetaData), NewProp_BlockoutMaterialTopColor_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUseCustomMaterial = { "bUseCustomMaterial", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ABlockoutToolsParent), &UHT_STATICS::NewProp_bUseCustomMaterial_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseCustomMaterial_MetaData), NewProp_bUseCustomMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CustomMaterial = { "CustomMaterial", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, CustomMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomMaterial_MetaData), NewProp_CustomMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BlockoutCustomMaterial = { "BlockoutCustomMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutCustomMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutCustomMaterial_MetaData), NewProp_BlockoutCustomMaterial_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bBlockoutEnableCollisions = { "bBlockoutEnableCollisions", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ABlockoutToolsParent), &UHT_STATICS::NewProp_bBlockoutEnableCollisions_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBlockoutEnableCollisions_MetaData), NewProp_bBlockoutEnableCollisions_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bBlockoutEnableCustomCollision = { "bBlockoutEnableCustomCollision", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ABlockoutToolsParent), &UHT_STATICS::NewProp_bBlockoutEnableCustomCollision_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBlockoutEnableCustomCollision_MetaData), NewProp_bBlockoutEnableCustomCollision_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_BlockoutCustomCollisionProfileName = { "BlockoutCustomCollisionProfileName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ABlockoutToolsParent, BlockoutCustomCollisionProfileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockoutCustomCollisionProfileName_MetaData), NewProp_BlockoutCustomCollisionProfileName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bBlockoutCastShadows = { "bBlockoutCastShadows", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ABlockoutToolsParent), &UHT_STATICS::NewProp_bBlockoutCastShadows_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBlockoutCastShadows_MetaData), NewProp_bBlockoutCastShadows_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Root,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Billboard,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutGridParent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutGridMID,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutCurrentMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutMeshComponents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutMeshComponents,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutMaterialType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutMaterialColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bBlockoutMaterialUseGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bBlockoutWorldAligned,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutMaterialGridSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutMaterialCheckerLuminance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutMaterialRoughness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bBlockoutMaterialUseTopColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutMaterialTopColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUseCustomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CustomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutCustomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bBlockoutEnableCollisions,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bBlockoutEnableCustomCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlockoutCustomCollisionProfileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bBlockoutCastShadows,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ABlockoutToolsParent Property Definitions **********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_BlockoutToolsPlugin,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ABlockoutToolsParent,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void ABlockoutToolsParent_StaticRegisterNativesABlockoutToolsParent()
{
	UClass* Class = ABlockoutToolsParent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ABlockoutToolsParent;
UClass* Z_Construct_UClass_ABlockoutToolsParent(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ABlockoutToolsParent;
		if (!Z_Registration_Info_UClass_ABlockoutToolsParent.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("BlockoutToolsParent"),
				Z_Registration_Info_UClass_ABlockoutToolsParent.InnerSingleton,
				ABlockoutToolsParent_StaticRegisterNativesABlockoutToolsParent,
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
		return Z_Registration_Info_UClass_ABlockoutToolsParent.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ABlockoutToolsParent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABlockoutToolsParent.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ABlockoutToolsParent.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ABlockoutToolsParent);
ABlockoutToolsParent::~ABlockoutToolsParent() {}
// ********** End Class ABlockoutToolsParent *******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Build_U5M_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_BlockoutToolsPlugin_Source_BlockoutToolsPlugin_Private_BlockoutToolsParent_h__Script_BlockoutToolsPlugin_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_BlockoutToolsPlugin_EBlockoutMaterialType, TEXT("EBlockoutMaterialType"), &ZRIE_EBlockoutMaterialType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 538763628U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABlockoutToolsParent, TEXT("ABlockoutToolsParent"), &Z_Registration_Info_UClass_ABlockoutToolsParent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABlockoutToolsParent), 2202288809U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_BlockoutToolsPlugin_Source_BlockoutToolsPlugin_Private_BlockoutToolsParent_h__Script_BlockoutToolsPlugin_7afd639c0ea8af46cf0b7e189c541cfda028b7d2{
	TEXT("/Script/BlockoutToolsPlugin"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
