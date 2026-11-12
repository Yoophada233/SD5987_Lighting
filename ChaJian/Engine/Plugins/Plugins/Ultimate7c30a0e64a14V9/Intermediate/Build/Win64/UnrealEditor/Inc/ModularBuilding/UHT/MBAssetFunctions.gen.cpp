// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBAssetFunctions.h"
#include "AssetRegistry/AssetData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBAssetFunctions() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FAssetData(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UTexture2D(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBAssetThumbnailFormant(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBAssetFunctions(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBAssetFunctions(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EMBAssetThumbnailFormant **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_ModularBuilding_EMBAssetThumbnailFormant_Statics
template<> MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EMBAssetThumbnailFormant>()
{
	return Z_Construct_UEnum_ModularBuilding_EMBAssetThumbnailFormant(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Modular Building Tool" },
		{ "JPEG.DisplayName", "JPEG" },
		{ "JPEG.Name", "EMBAssetThumbnailFormant::JPEG" },
		{ "ModuleRelativePath", "Public/Libraries/MBAssetFunctions.h" },
		{ "PNG.DisplayName", "PNG" },
		{ "PNG.Name", "EMBAssetThumbnailFormant::PNG" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMBAssetThumbnailFormant::JPEG", (int64)EMBAssetThumbnailFormant::JPEG },
		{ "EMBAssetThumbnailFormant::PNG", (int64)EMBAssetThumbnailFormant::PNG },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	"EMBAssetThumbnailFormant",
	"EMBAssetThumbnailFormant",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EMBAssetThumbnailFormant;
UEnum* Z_Construct_UEnum_ModularBuilding_EMBAssetThumbnailFormant(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EMBAssetThumbnailFormant.OuterSingleton)
		{
			ZRIE_EMBAssetThumbnailFormant.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModularBuilding_EMBAssetThumbnailFormant, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("EMBAssetThumbnailFormant"));
		}
		return ZRIE_EMBAssetThumbnailFormant.OuterSingleton;
	}
	if (!ZRIE_EMBAssetThumbnailFormant.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EMBAssetThumbnailFormant.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EMBAssetThumbnailFormant.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EMBAssetThumbnailFormant ****************************************************

// ********** Begin Class UMBAssetFunctions Function GenerateThumbnailForAsset *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetFunctions_GenerateThumbnailForAsset_Statics
struct UHT_STATICS
{
	struct MBAssetFunctions_eventGenerateThumbnailForAsset_Parms
	{
		FAssetData InAssetPath;
		EMBAssetThumbnailFormant InImageFormat;
		UTexture2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "ModularBuilding|Asset" },
		{ "ModuleRelativePath", "Public/Libraries/MBAssetFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InAssetPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InImageFormat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GenerateThumbnailForAsset constinit property declarations *************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InAssetPath;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InImageFormat_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InImageFormat;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GenerateThumbnailForAsset constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GenerateThumbnailForAsset Property Definitions ************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InAssetPath = { "InAssetPath", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetFunctions_eventGenerateThumbnailForAsset_Parms, InAssetPath), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InAssetPath_MetaData), NewProp_InAssetPath_MetaData) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InImageFormat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InImageFormat = { "InImageFormat", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetFunctions_eventGenerateThumbnailForAsset_Parms, InImageFormat), Z_Construct_UEnum_ModularBuilding_EMBAssetThumbnailFormant, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InImageFormat_MetaData), NewProp_InImageFormat_MetaData) }; // fa9880038f93d122764b869fb2dc0e4d69545894
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetFunctions_eventGenerateThumbnailForAsset_Parms, ReturnValue), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InAssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InImageFormat_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InImageFormat,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GenerateThumbnailForAsset Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetFunctions, nullptr, "GenerateThumbnailForAsset", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetFunctions_eventGenerateThumbnailForAsset_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetFunctions_eventGenerateThumbnailForAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetFunctions_GenerateThumbnailForAsset(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetFunctions::execGenerateThumbnailForAsset)
{
	P_GET_STRUCT_REF(FAssetData,Z_Param_Out_InAssetPath);
	P_GET_ENUM(EMBAssetThumbnailFormant,Z_Param_InImageFormat);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture2D**)Z_Param__Result=UMBAssetFunctions::GenerateThumbnailForAsset(Z_Param_Out_InAssetPath,EMBAssetThumbnailFormant(Z_Param_InImageFormat));
	P_NATIVE_END;
}
// ********** End Class UMBAssetFunctions Function GenerateThumbnailForAsset ***********************

// ********** Begin Class UMBAssetFunctions Function GetAssetDataFromObject ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetFunctions_GetAssetDataFromObject_Statics
struct UHT_STATICS
{
	struct MBAssetFunctions_eventGetAssetDataFromObject_Parms
	{
		const UObject* Object;
		FAssetData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor|Asset" },
		{ "ModuleRelativePath", "Public/Libraries/MBAssetFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Object_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAssetDataFromObject constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Object;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAssetDataFromObject constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAssetDataFromObject Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetFunctions_eventGetAssetDataFromObject_Parms, Object), Z_Construct_UClass_UObject, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Object_MetaData), NewProp_Object_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetFunctions_eventGetAssetDataFromObject_Parms, ReturnValue), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(0, nullptr) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Object,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAssetDataFromObject Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetFunctions, nullptr, "GetAssetDataFromObject", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetFunctions_eventGetAssetDataFromObject_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetFunctions_eventGetAssetDataFromObject_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetFunctions_GetAssetDataFromObject(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetFunctions::execGetAssetDataFromObject)
{
	P_GET_OBJECT(UObject,Z_Param_Object);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FAssetData*)Z_Param__Result=UMBAssetFunctions::GetAssetDataFromObject(Z_Param_Object);
	P_NATIVE_END;
}
// ********** End Class UMBAssetFunctions Function GetAssetDataFromObject **************************

// ********** Begin Class UMBAssetFunctions Function GetAssetDataFromPath **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetFunctions_GetAssetDataFromPath_Statics
struct UHT_STATICS
{
	struct MBAssetFunctions_eventGetAssetDataFromPath_Parms
	{
		FString AssetPath;
		FAssetData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "ModularBuilding|Asset" },
		{ "ModuleRelativePath", "Public/Libraries/MBAssetFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAssetDataFromPath constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAssetDataFromPath constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAssetDataFromPath Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_AssetPath = { "AssetPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetFunctions_eventGetAssetDataFromPath_Parms, AssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetPath_MetaData), NewProp_AssetPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetFunctions_eventGetAssetDataFromPath_Parms, ReturnValue), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(0, nullptr) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAssetDataFromPath Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetFunctions, nullptr, "GetAssetDataFromPath", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetFunctions_eventGetAssetDataFromPath_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetFunctions_eventGetAssetDataFromPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetFunctions_GetAssetDataFromPath(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetFunctions::execGetAssetDataFromPath)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FAssetData*)Z_Param__Result=UMBAssetFunctions::GetAssetDataFromPath(Z_Param_AssetPath);
	P_NATIVE_END;
}
// ********** End Class UMBAssetFunctions Function GetAssetDataFromPath ****************************

// ********** Begin Class UMBAssetFunctions Function GetAssetPathFromObject ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBAssetFunctions_GetAssetPathFromObject_Statics
struct UHT_STATICS
{
	struct MBAssetFunctions_eventGetAssetPathFromObject_Parms
	{
		const UObject* Object;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "ModularBuilding|Asset" },
		{ "ModuleRelativePath", "Public/Libraries/MBAssetFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Object_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAssetPathFromObject constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Object;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAssetPathFromObject constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAssetPathFromObject Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetFunctions_eventGetAssetPathFromObject_Parms, Object), Z_Construct_UClass_UObject, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Object_MetaData), NewProp_Object_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(MBAssetFunctions_eventGetAssetPathFromObject_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Object,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAssetPathFromObject Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBAssetFunctions, nullptr, "GetAssetPathFromObject", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MBAssetFunctions_eventGetAssetPathFromObject_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MBAssetFunctions_eventGetAssetPathFromObject_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMBAssetFunctions_GetAssetPathFromObject(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBAssetFunctions::execGetAssetPathFromObject)
{
	P_GET_OBJECT(UObject,Z_Param_Object);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UMBAssetFunctions::GetAssetPathFromObject(Z_Param_Object);
	P_NATIVE_END;
}
// ********** End Class UMBAssetFunctions Function GetAssetPathFromObject **************************

// ********** Begin Class UMBAssetFunctions ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBAssetFunctions_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Libraries/MBAssetFunctions.h" },
		{ "ModuleRelativePath", "Public/Libraries/MBAssetFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBAssetFunctions constinit property declarations ************************
// ********** End Class UMBAssetFunctions constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GenerateThumbnailForAsset"), .Pointer = &UMBAssetFunctions::execGenerateThumbnailForAsset },
		{ .NameUTF8 = UTF8TEXT("GetAssetDataFromObject"), .Pointer = &UMBAssetFunctions::execGetAssetDataFromObject },
		{ .NameUTF8 = UTF8TEXT("GetAssetDataFromPath"), .Pointer = &UMBAssetFunctions::execGetAssetDataFromPath },
		{ .NameUTF8 = UTF8TEXT("GetAssetPathFromObject"), .Pointer = &UMBAssetFunctions::execGetAssetPathFromObject },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBAssetFunctions_GenerateThumbnailForAsset, "GenerateThumbnailForAsset" }, // 826cbdc6a49e5b4d83053a4fc29639e72daf21b9
		{ &Z_Construct_UFunction_UMBAssetFunctions_GetAssetDataFromObject, "GetAssetDataFromObject" }, // c30b59d9adad515c61fe8dfdac3309b1936c50bb
		{ &Z_Construct_UFunction_UMBAssetFunctions_GetAssetDataFromPath, "GetAssetDataFromPath" }, // f296b544cc62b0772910b0d38dcff86d68734cf9
		{ &Z_Construct_UFunction_UMBAssetFunctions_GetAssetPathFromObject, "GetAssetPathFromObject" }, // ed645ff209a04189d25f1e9e41a3eb4bbe9344cb
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBAssetFunctions>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UBlueprintFunctionLibrary,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBAssetFunctions,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UMBAssetFunctions_StaticRegisterNativesUMBAssetFunctions()
{
	UClass* Class = UMBAssetFunctions::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBAssetFunctions;
UClass* Z_Construct_UClass_UMBAssetFunctions(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBAssetFunctions;
		if (!Z_Registration_Info_UClass_UMBAssetFunctions.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBAssetFunctions"),
				Z_Registration_Info_UClass_UMBAssetFunctions.InnerSingleton,
				UMBAssetFunctions_StaticRegisterNativesUMBAssetFunctions,
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
		return Z_Registration_Info_UClass_UMBAssetFunctions.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBAssetFunctions.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBAssetFunctions.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBAssetFunctions.OuterSingleton;
}
#undef UHT_STATICS
UMBAssetFunctions::UMBAssetFunctions(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBAssetFunctions);
UMBAssetFunctions::~UMBAssetFunctions() {}
// ********** End Class UMBAssetFunctions **********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_ModularBuilding_EMBAssetThumbnailFormant, TEXT("EMBAssetThumbnailFormant"), &ZRIE_EMBAssetThumbnailFormant, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4204298243U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBAssetFunctions, TEXT("UMBAssetFunctions"), &Z_Registration_Info_UClass_UMBAssetFunctions, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBAssetFunctions), 1189053758U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h__Script_ModularBuilding_904851db5fca343ad25a3053517b631919de9f22{
	TEXT("/Script/ModularBuilding"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
