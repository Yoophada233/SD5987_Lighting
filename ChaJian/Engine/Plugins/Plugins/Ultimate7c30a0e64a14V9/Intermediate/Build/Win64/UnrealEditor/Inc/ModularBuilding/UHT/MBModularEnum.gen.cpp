// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBModularEnum.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBModularEnum() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FDistributionBaseData(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EBuildingCategory(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBAxis(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBDistributionType(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBMeshConversionType(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBModularSnapType(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBPropOrientation(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBWorkingMode(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EModularDirection(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EPlacementMode(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EPlacementStatus(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EPlacementType(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_ESettingsMenuType(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EBuildingCategory *********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EBuildingCategory_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EBuildingCategory>()
{
	return Z_Construct_UEnum_ModularBuilding_EBuildingCategory(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "Modular.DisplayName", "Modular" },
		{ "Modular.Name", "EBuildingCategory::Modular" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EBuildingCategory::None" },
		{ "Prop.DisplayName", "Prop" },
		{ "Prop.Name", "EBuildingCategory::Prop" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EBuildingCategory::None", (int64)EBuildingCategory::None },
		{ "EBuildingCategory::Modular", (int64)EBuildingCategory::Modular },
		{ "EBuildingCategory::Prop", (int64)EBuildingCategory::Prop },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EBuildingCategory",
	"EBuildingCategory",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EBuildingCategory;
UEnum* Z_Construct_UEnum_ModularBuilding_EBuildingCategory(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EBuildingCategory.OuterSingleton)
		{
			ZRIE_EBuildingCategory.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EBuildingCategory, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EBuildingCategory"));
		}
		return ZRIE_EBuildingCategory.OuterSingleton;
	}
	if (!ZRIE_EBuildingCategory.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EBuildingCategory.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EBuildingCategory.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EBuildingCategory ***********************************************************

// ********** Begin Enum EPlacementMode ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EPlacementMode_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlacementMode>()
{
	return Z_Construct_UEnum_ModularBuilding_EPlacementMode(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "MultiModular.DisplayName", "MultiModular" },
		{ "MultiModular.Name", "EPlacementMode::MultiModular" },
		{ "MultiProp.DisplayName", "Right" },
		{ "MultiProp.Name", "EPlacementMode::MultiProp" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EPlacementMode::None" },
		{ "SingleModular.DisplayName", "SingleModular" },
		{ "SingleModular.Name", "EPlacementMode::SingleModular" },
		{ "SingleProp.DisplayName", "Left" },
		{ "SingleProp.Name", "EPlacementMode::SingleProp" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlacementMode::None", (int64)EPlacementMode::None },
		{ "EPlacementMode::SingleModular", (int64)EPlacementMode::SingleModular },
		{ "EPlacementMode::MultiModular", (int64)EPlacementMode::MultiModular },
		{ "EPlacementMode::SingleProp", (int64)EPlacementMode::SingleProp },
		{ "EPlacementMode::MultiProp", (int64)EPlacementMode::MultiProp },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EPlacementMode",
	"EPlacementMode",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EPlacementMode;
UEnum* Z_Construct_UEnum_ModularBuilding_EPlacementMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EPlacementMode.OuterSingleton)
		{
			ZRIE_EPlacementMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EPlacementMode, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EPlacementMode"));
		}
		return ZRIE_EPlacementMode.OuterSingleton;
	}
	if (!ZRIE_EPlacementMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EPlacementMode.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EPlacementMode.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EPlacementMode **************************************************************

// ********** Begin Enum EPlacementType ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EPlacementType_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlacementType>()
{
	return Z_Construct_UEnum_ModularBuilding_EPlacementType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "Multiple.DisplayName", "Multiple" },
		{ "Multiple.Name", "EPlacementType::Multiple" },
		{ "Single.DisplayName", "Single" },
		{ "Single.Name", "EPlacementType::Single" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlacementType::Single", (int64)EPlacementType::Single },
		{ "EPlacementType::Multiple", (int64)EPlacementType::Multiple },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EPlacementType",
	"EPlacementType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EPlacementType;
UEnum* Z_Construct_UEnum_ModularBuilding_EPlacementType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EPlacementType.OuterSingleton)
		{
			ZRIE_EPlacementType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EPlacementType, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EPlacementType"));
		}
		return ZRIE_EPlacementType.OuterSingleton;
	}
	if (!ZRIE_EPlacementType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EPlacementType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EPlacementType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EPlacementType **************************************************************

// ********** Begin Enum EMBWorkingMode ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EMBWorkingMode_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EMBWorkingMode>()
{
	return Z_Construct_UEnum_ModularBuilding_EMBWorkingMode(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "ModActorAction.DisplayName", "ModActorAction" },
		{ "ModActorAction.Name", "EMBWorkingMode::ModActorAction" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EMBWorkingMode::None" },
		{ "Placement.DisplayName", "Placement" },
		{ "Placement.Name", "EMBWorkingMode::Placement" },
		{ "PropActorAction.DisplayName", "PropActorAction" },
		{ "PropActorAction.Name", "EMBWorkingMode::PropActorAction" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMBWorkingMode::None", (int64)EMBWorkingMode::None },
		{ "EMBWorkingMode::Placement", (int64)EMBWorkingMode::Placement },
		{ "EMBWorkingMode::ModActorAction", (int64)EMBWorkingMode::ModActorAction },
		{ "EMBWorkingMode::PropActorAction", (int64)EMBWorkingMode::PropActorAction },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EMBWorkingMode",
	"EMBWorkingMode",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EMBWorkingMode;
UEnum* Z_Construct_UEnum_ModularBuilding_EMBWorkingMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EMBWorkingMode.OuterSingleton)
		{
			ZRIE_EMBWorkingMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EMBWorkingMode, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EMBWorkingMode"));
		}
		return ZRIE_EMBWorkingMode.OuterSingleton;
	}
	if (!ZRIE_EMBWorkingMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EMBWorkingMode.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EMBWorkingMode.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EMBWorkingMode **************************************************************

// ********** Begin Enum EPlacementStatus **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EPlacementStatus_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlacementStatus>()
{
	return Z_Construct_UEnum_ModularBuilding_EPlacementStatus(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EPlacementStatus::None" },
		{ "NotPlaceable.DisplayName", "NotPlaceable" },
		{ "NotPlaceable.Name", "EPlacementStatus::NotPlaceable" },
		{ "Placeable.DisplayName", "Placeable" },
		{ "Placeable.Name", "EPlacementStatus::Placeable" },
		{ "Replaceable.DisplayName", "Replaceable" },
		{ "Replaceable.Name", "EPlacementStatus::Replaceable" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlacementStatus::None", (int64)EPlacementStatus::None },
		{ "EPlacementStatus::NotPlaceable", (int64)EPlacementStatus::NotPlaceable },
		{ "EPlacementStatus::Placeable", (int64)EPlacementStatus::Placeable },
		{ "EPlacementStatus::Replaceable", (int64)EPlacementStatus::Replaceable },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EPlacementStatus",
	"EPlacementStatus",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EPlacementStatus;
UEnum* Z_Construct_UEnum_ModularBuilding_EPlacementStatus(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EPlacementStatus.OuterSingleton)
		{
			ZRIE_EPlacementStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EPlacementStatus, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EPlacementStatus"));
		}
		return ZRIE_EPlacementStatus.OuterSingleton;
	}
	if (!ZRIE_EPlacementStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EPlacementStatus.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EPlacementStatus.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EPlacementStatus ************************************************************

// ********** Begin Enum EModularDirection *********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EModularDirection_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EModularDirection>()
{
	return Z_Construct_UEnum_ModularBuilding_EModularDirection(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Back.DisplayName", "Back" },
		{ "Back.Name", "EModularDirection::Back" },
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "Front.DisplayName", "Front" },
		{ "Front.Name", "EModularDirection::Front" },
		{ "Left.DisplayName", "Left" },
		{ "Left.Name", "EModularDirection::Left" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EModularDirection::None" },
		{ "Right.DisplayName", "Right" },
		{ "Right.Name", "EModularDirection::Right" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EModularDirection::None", (int64)EModularDirection::None },
		{ "EModularDirection::Front", (int64)EModularDirection::Front },
		{ "EModularDirection::Back", (int64)EModularDirection::Back },
		{ "EModularDirection::Left", (int64)EModularDirection::Left },
		{ "EModularDirection::Right", (int64)EModularDirection::Right },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EModularDirection",
	"EModularDirection",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EModularDirection;
UEnum* Z_Construct_UEnum_ModularBuilding_EModularDirection(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EModularDirection.OuterSingleton)
		{
			ZRIE_EModularDirection.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EModularDirection, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EModularDirection"));
		}
		return ZRIE_EModularDirection.OuterSingleton;
	}
	if (!ZRIE_EModularDirection.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EModularDirection.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EModularDirection.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EModularDirection ***********************************************************

// ********** Begin Enum ESettingsMenuType *********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_ESettingsMenuType_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<ESettingsMenuType>()
{
	return Z_Construct_UEnum_ModularBuilding_ESettingsMenuType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "ModActorAction.DisplayName", "Left" },
		{ "ModActorAction.Name", "ESettingsMenuType::ModActorAction" },
		{ "ModBuilding.DisplayName", "Front" },
		{ "ModBuilding.Name", "ESettingsMenuType::ModBuilding" },
		{ "ModPropAction.DisplayName", "Right" },
		{ "ModPropAction.Name", "ESettingsMenuType::ModPropAction" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "ESettingsMenuType::None" },
		{ "PropBuilding.DisplayName", "Back" },
		{ "PropBuilding.Name", "ESettingsMenuType::PropBuilding" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESettingsMenuType::None", (int64)ESettingsMenuType::None },
		{ "ESettingsMenuType::ModBuilding", (int64)ESettingsMenuType::ModBuilding },
		{ "ESettingsMenuType::PropBuilding", (int64)ESettingsMenuType::PropBuilding },
		{ "ESettingsMenuType::ModActorAction", (int64)ESettingsMenuType::ModActorAction },
		{ "ESettingsMenuType::ModPropAction", (int64)ESettingsMenuType::ModPropAction },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"ESettingsMenuType",
	"ESettingsMenuType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_ESettingsMenuType;
UEnum* Z_Construct_UEnum_ModularBuilding_ESettingsMenuType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_ESettingsMenuType.OuterSingleton)
		{
			ZRIE_ESettingsMenuType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_ESettingsMenuType, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("ESettingsMenuType"));
		}
		return ZRIE_ESettingsMenuType.OuterSingleton;
	}
	if (!ZRIE_ESettingsMenuType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_ESettingsMenuType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_ESettingsMenuType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum ESettingsMenuType ***********************************************************

// ********** Begin Enum EMBAxis *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EMBAxis_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EMBAxis>()
{
	return Z_Construct_UEnum_ModularBuilding_EMBAxis(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AxisX.DisplayName", "X" },
		{ "AxisX.Name", "EMBAxis::AxisX" },
		{ "AxisY.DisplayName", "Y" },
		{ "AxisY.Name", "EMBAxis::AxisY" },
		{ "AxisZ.DisplayName", "Z" },
		{ "AxisZ.Name", "EMBAxis::AxisZ" },
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EMBAxis::None" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMBAxis::None", (int64)EMBAxis::None },
		{ "EMBAxis::AxisX", (int64)EMBAxis::AxisX },
		{ "EMBAxis::AxisY", (int64)EMBAxis::AxisY },
		{ "EMBAxis::AxisZ", (int64)EMBAxis::AxisZ },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EMBAxis",
	"EMBAxis",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EMBAxis;
UEnum* Z_Construct_UEnum_ModularBuilding_EMBAxis(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EMBAxis.OuterSingleton)
		{
			ZRIE_EMBAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EMBAxis, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EMBAxis"));
		}
		return ZRIE_EMBAxis.OuterSingleton;
	}
	if (!ZRIE_EMBAxis.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EMBAxis.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EMBAxis.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EMBAxis *********************************************************************

// ********** Begin Enum EMBDistributionType *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EMBDistributionType_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EMBDistributionType>()
{
	return Z_Construct_UEnum_ModularBuilding_EMBDistributionType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Box.DisplayName", "Box" },
		{ "Box.Name", "EMBDistributionType::Box" },
		{ "Category", "Modular Building Tool" },
		{ "Circle.DisplayName", "Circle" },
		{ "Circle.Name", "EMBDistributionType::Circle" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "Sphere.DisplayName", "Sphere" },
		{ "Sphere.Name", "EMBDistributionType::Sphere" },
		{ "TDGrid.DisplayName", "3DGrid" },
		{ "TDGrid.Name", "EMBDistributionType::TDGrid" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMBDistributionType::Box", (int64)EMBDistributionType::Box },
		{ "EMBDistributionType::Circle", (int64)EMBDistributionType::Circle },
		{ "EMBDistributionType::Sphere", (int64)EMBDistributionType::Sphere },
		{ "EMBDistributionType::TDGrid", (int64)EMBDistributionType::TDGrid },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EMBDistributionType",
	"EMBDistributionType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EMBDistributionType;
UEnum* Z_Construct_UEnum_ModularBuilding_EMBDistributionType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EMBDistributionType.OuterSingleton)
		{
			ZRIE_EMBDistributionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EMBDistributionType, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EMBDistributionType"));
		}
		return ZRIE_EMBDistributionType.OuterSingleton;
	}
	if (!ZRIE_EMBDistributionType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EMBDistributionType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EMBDistributionType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EMBDistributionType *********************************************************

// ********** Begin Enum EMBPropOrientation ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EMBPropOrientation_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EMBPropOrientation>()
{
	return Z_Construct_UEnum_ModularBuilding_EMBPropOrientation(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "Inside.DisplayName", "Inside" },
		{ "Inside.Name", "EMBPropOrientation::Inside" },
		{ "Keep.DisplayName", "Keep" },
		{ "Keep.Name", "EMBPropOrientation::Keep" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "Outside.DisplayName", "Outside" },
		{ "Outside.Name", "EMBPropOrientation::Outside" },
		{ "Random.DisplayName", "Random" },
		{ "Random.Name", "EMBPropOrientation::Random" },
		{ "RandomZ.DisplayName", "Random Around" },
		{ "RandomZ.Name", "EMBPropOrientation::RandomZ" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMBPropOrientation::Keep", (int64)EMBPropOrientation::Keep },
		{ "EMBPropOrientation::Inside", (int64)EMBPropOrientation::Inside },
		{ "EMBPropOrientation::Outside", (int64)EMBPropOrientation::Outside },
		{ "EMBPropOrientation::RandomZ", (int64)EMBPropOrientation::RandomZ },
		{ "EMBPropOrientation::Random", (int64)EMBPropOrientation::Random },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EMBPropOrientation",
	"EMBPropOrientation",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EMBPropOrientation;
UEnum* Z_Construct_UEnum_ModularBuilding_EMBPropOrientation(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EMBPropOrientation.OuterSingleton)
		{
			ZRIE_EMBPropOrientation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EMBPropOrientation, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EMBPropOrientation"));
		}
		return ZRIE_EMBPropOrientation.OuterSingleton;
	}
	if (!ZRIE_EMBPropOrientation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EMBPropOrientation.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EMBPropOrientation.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EMBPropOrientation **********************************************************

// ********** Begin Enum EMBMeshConversionType *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EMBMeshConversionType_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EMBMeshConversionType>()
{
	return Z_Construct_UEnum_ModularBuilding_EMBMeshConversionType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "HIsm.DisplayName", "HISM Component" },
		{ "HIsm.Name", "EMBMeshConversionType::HIsm" },
		{ "Ism.DisplayName", "ISM Component" },
		{ "Ism.Name", "EMBMeshConversionType::Ism" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "Sm.DisplayName", "SM Component" },
		{ "Sm.Name", "EMBMeshConversionType::Sm" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMBMeshConversionType::Sm", (int64)EMBMeshConversionType::Sm },
		{ "EMBMeshConversionType::Ism", (int64)EMBMeshConversionType::Ism },
		{ "EMBMeshConversionType::HIsm", (int64)EMBMeshConversionType::HIsm },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EMBMeshConversionType",
	"EMBMeshConversionType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EMBMeshConversionType;
UEnum* Z_Construct_UEnum_ModularBuilding_EMBMeshConversionType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EMBMeshConversionType.OuterSingleton)
		{
			ZRIE_EMBMeshConversionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EMBMeshConversionType, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EMBMeshConversionType"));
		}
		return ZRIE_EMBMeshConversionType.OuterSingleton;
	}
	if (!ZRIE_EMBMeshConversionType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EMBMeshConversionType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EMBMeshConversionType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EMBMeshConversionType *******************************************************

// ********** Begin Enum EMBModularSnapType ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EMBModularSnapType_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EMBModularSnapType>()
{
	return Z_Construct_UEnum_ModularBuilding_EMBModularSnapType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "BoundCorrection.DisplayName", "Bound Correction Sensitivity" },
		{ "BoundCorrection.Name", "EMBModularSnapType::BoundCorrection" },
		{ "Category", "Modular Building Tool" },
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
		{ "SMBounds.DisplayName", "Static Mesh Bounds" },
		{ "SMBounds.Name", "EMBModularSnapType::SMBounds" },
		{ "SMCollision.DisplayName", "Static Mesh Collision" },
		{ "SMCollision.Name", "EMBModularSnapType::SMCollision" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMBModularSnapType::SMBounds", (int64)EMBModularSnapType::SMBounds },
		{ "EMBModularSnapType::BoundCorrection", (int64)EMBModularSnapType::BoundCorrection },
		{ "EMBModularSnapType::SMCollision", (int64)EMBModularSnapType::SMCollision },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EMBModularSnapType",
	"EMBModularSnapType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EMBModularSnapType;
UEnum* Z_Construct_UEnum_ModularBuilding_EMBModularSnapType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EMBModularSnapType.OuterSingleton)
		{
			ZRIE_EMBModularSnapType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EMBModularSnapType, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EMBModularSnapType"));
		}
		return ZRIE_EMBModularSnapType.OuterSingleton;
	}
	if (!ZRIE_EMBModularSnapType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EMBModularSnapType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EMBModularSnapType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EMBModularSnapType **********************************************************

// ********** Begin ScriptStruct FDistributionBaseData *********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDistributionBaseData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDistributionBaseData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDistributionBaseData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bActorSelected_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOneActorDistribution_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistributionType_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorToFollow_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/MBModularEnum.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDistributionBaseData constinit property declarations *************
	static void NewProp_bActorSelected_SetBit(void* Obj)
	{
		((FDistributionBaseData*)Obj)->bActorSelected = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bActorSelected;
	static void NewProp_bOneActorDistribution_SetBit(void* Obj)
	{
		((FDistributionBaseData*)Obj)->bOneActorDistribution = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOneActorDistribution;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DistributionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DistributionType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActorToFollow;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Orientation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Orientation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDistributionBaseData constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDistributionBaseData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDistributionBaseData Property Definitions ************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bActorSelected = { "bActorSelected", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDistributionBaseData), &UHT_STATICS::NewProp_bActorSelected_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bActorSelected_MetaData), NewProp_bActorSelected_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bOneActorDistribution = { "bOneActorDistribution", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDistributionBaseData), &UHT_STATICS::NewProp_bOneActorDistribution_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOneActorDistribution_MetaData), NewProp_bOneActorDistribution_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_DistributionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_DistributionType = { "DistributionType", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FDistributionBaseData, DistributionType), Z_Construct_UEnum_ModularBuilding_EMBDistributionType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistributionType_MetaData), NewProp_DistributionType_MetaData) }; // c8eed0609af4a634f40ab413dc43a167fb24f4fa
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActorToFollow = { "ActorToFollow", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(FDistributionBaseData, ActorToFollow), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorToFollow_MetaData), NewProp_ActorToFollow_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDistributionBaseData, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Orientation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FDistributionBaseData, Orientation), Z_Construct_UEnum_ModularBuilding_EMBPropOrientation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orientation_MetaData), NewProp_Orientation_MetaData) }; // 4c03d65582b65e148d5412b5f37f2cf4f1aff204
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bActorSelected,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bOneActorDistribution,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistributionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistributionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActorToFollow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Orientation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Orientation,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDistributionBaseData Property Definitions **************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	&NewStructOps,
	"DistributionBaseData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDistributionBaseData>(),
	alignof(FDistributionBaseData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDistributionBaseData;
UScriptStruct* Z_Construct_UScriptStruct_FDistributionBaseData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDistributionBaseData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDistributionBaseData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDistributionBaseData, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("DistributionBaseData"));
		}
		return Z_Registration_Info_UScriptStruct_FDistributionBaseData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDistributionBaseData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDistributionBaseData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDistributionBaseData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDistributionBaseData ***********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBModularEnum_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_ModularBuilding_EBuildingCategory, TEXT("EBuildingCategory"), &ZRIE_EBuildingCategory, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 131039511U) },
		{ Z_Construct_UEnum_ModularBuilding_EPlacementMode, TEXT("EPlacementMode"), &ZRIE_EPlacementMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 160691456U) },
		{ Z_Construct_UEnum_ModularBuilding_EPlacementType, TEXT("EPlacementType"), &ZRIE_EPlacementType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3356690712U) },
		{ Z_Construct_UEnum_ModularBuilding_EMBWorkingMode, TEXT("EMBWorkingMode"), &ZRIE_EMBWorkingMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1228744772U) },
		{ Z_Construct_UEnum_ModularBuilding_EPlacementStatus, TEXT("EPlacementStatus"), &ZRIE_EPlacementStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 842975300U) },
		{ Z_Construct_UEnum_ModularBuilding_EModularDirection, TEXT("EModularDirection"), &ZRIE_EModularDirection, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2088963720U) },
		{ Z_Construct_UEnum_ModularBuilding_ESettingsMenuType, TEXT("ESettingsMenuType"), &ZRIE_ESettingsMenuType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2907032166U) },
		{ Z_Construct_UEnum_ModularBuilding_EMBAxis, TEXT("EMBAxis"), &ZRIE_EMBAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2537698759U) },
		{ Z_Construct_UEnum_ModularBuilding_EMBDistributionType, TEXT("EMBDistributionType"), &ZRIE_EMBDistributionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3371094112U) },
		{ Z_Construct_UEnum_ModularBuilding_EMBPropOrientation, TEXT("EMBPropOrientation"), &ZRIE_EMBPropOrientation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1275319893U) },
		{ Z_Construct_UEnum_ModularBuilding_EMBMeshConversionType, TEXT("EMBMeshConversionType"), &ZRIE_EMBMeshConversionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3023780430U) },
		{ Z_Construct_UEnum_ModularBuilding_EMBModularSnapType, TEXT("EMBModularSnapType"), &ZRIE_EMBModularSnapType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3402729792U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDistributionBaseData, Z_Construct_UScriptStruct_FDistributionBaseData_Statics::NewStructOps, TEXT("DistributionBaseData"),&Z_Registration_Info_UScriptStruct_FDistributionBaseData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDistributionBaseData), 2230814511U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBModularEnum_h__Script_ModularBuilding_fc2fb6a6dd798882b9c5de9ce3445377e929a1d7{
	TEXT("/Script/ModularBuilding"),
	nullptr, 0,
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
