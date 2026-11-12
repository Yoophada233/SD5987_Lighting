// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODAssetFunctions.h"
#include "AssetRegistry/AssetData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODAssetFunctions() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FAssetData(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UTexture2D(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODAssetFunctions(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODAssetFunctions(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODAssetFunctions Function GenerateThumbnailForSM ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODAssetFunctions_GenerateThumbnailForSM_Statics
struct UHT_STATICS
{
	struct ODAssetFunctions_eventGenerateThumbnailForSM_Parms
	{
		FAssetData InAssetPath;
		UTexture2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "ModularBuilding|Asset" },
		{ "ModuleRelativePath", "Public/Library/ODAssetFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InAssetPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GenerateThumbnailForSM constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InAssetPath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GenerateThumbnailForSM constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GenerateThumbnailForSM Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InAssetPath = { "InAssetPath", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ODAssetFunctions_eventGenerateThumbnailForSM_Parms, InAssetPath), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InAssetPath_MetaData), NewProp_InAssetPath_MetaData) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ODAssetFunctions_eventGenerateThumbnailForSM_Parms, ReturnValue), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InAssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GenerateThumbnailForSM Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODAssetFunctions, nullptr, "GenerateThumbnailForSM", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODAssetFunctions_eventGenerateThumbnailForSM_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODAssetFunctions_eventGenerateThumbnailForSM_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODAssetFunctions_GenerateThumbnailForSM(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODAssetFunctions::execGenerateThumbnailForSM)
{
	P_GET_STRUCT_REF(FAssetData,Z_Param_Out_InAssetPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture2D**)Z_Param__Result=UODAssetFunctions::GenerateThumbnailForSM(Z_Param_Out_InAssetPath);
	P_NATIVE_END;
}
// ********** End Class UODAssetFunctions Function GenerateThumbnailForSM **************************

// ********** Begin Class UODAssetFunctions Function GetAssetDataFromObject ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODAssetFunctions_GetAssetDataFromObject_Statics
struct UHT_STATICS
{
	struct ODAssetFunctions_eventGetAssetDataFromObject_Parms
	{
		const UObject* Object;
		FAssetData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Editor|Asset" },
		{ "ModuleRelativePath", "Public/Library/ODAssetFunctions.h" },
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
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ODAssetFunctions_eventGetAssetDataFromObject_Parms, Object), Z_Construct_UClass_UObject, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Object_MetaData), NewProp_Object_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ODAssetFunctions_eventGetAssetDataFromObject_Parms, ReturnValue), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(0, nullptr) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Object,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAssetDataFromObject Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODAssetFunctions, nullptr, "GetAssetDataFromObject", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODAssetFunctions_eventGetAssetDataFromObject_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODAssetFunctions_eventGetAssetDataFromObject_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODAssetFunctions_GetAssetDataFromObject(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODAssetFunctions::execGetAssetDataFromObject)
{
	P_GET_OBJECT(UObject,Z_Param_Object);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FAssetData*)Z_Param__Result=UODAssetFunctions::GetAssetDataFromObject(Z_Param_Object);
	P_NATIVE_END;
}
// ********** End Class UODAssetFunctions Function GetAssetDataFromObject **************************

// ********** Begin Class UODAssetFunctions Function GetAssetDataFromPath **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODAssetFunctions_GetAssetDataFromPath_Statics
struct UHT_STATICS
{
	struct ODAssetFunctions_eventGetAssetDataFromPath_Parms
	{
		FString AssetPath;
		FAssetData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "ModularBuilding|Asset" },
		{ "ModuleRelativePath", "Public/Library/ODAssetFunctions.h" },
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
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_AssetPath = { "AssetPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ODAssetFunctions_eventGetAssetDataFromPath_Parms, AssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetPath_MetaData), NewProp_AssetPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ODAssetFunctions_eventGetAssetDataFromPath_Parms, ReturnValue), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(0, nullptr) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAssetDataFromPath Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODAssetFunctions, nullptr, "GetAssetDataFromPath", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODAssetFunctions_eventGetAssetDataFromPath_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODAssetFunctions_eventGetAssetDataFromPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODAssetFunctions_GetAssetDataFromPath(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODAssetFunctions::execGetAssetDataFromPath)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FAssetData*)Z_Param__Result=UODAssetFunctions::GetAssetDataFromPath(Z_Param_AssetPath);
	P_NATIVE_END;
}
// ********** End Class UODAssetFunctions Function GetAssetDataFromPath ****************************

// ********** Begin Class UODAssetFunctions Function GetAssetPathFromObject ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODAssetFunctions_GetAssetPathFromObject_Statics
struct UHT_STATICS
{
	struct ODAssetFunctions_eventGetAssetPathFromObject_Parms
	{
		const UObject* Object;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "ModularBuilding|Asset" },
		{ "ModuleRelativePath", "Public/Library/ODAssetFunctions.h" },
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
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ODAssetFunctions_eventGetAssetPathFromObject_Parms, Object), Z_Construct_UClass_UObject, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Object_MetaData), NewProp_Object_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ODAssetFunctions_eventGetAssetPathFromObject_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Object,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAssetPathFromObject Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODAssetFunctions, nullptr, "GetAssetPathFromObject", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ODAssetFunctions_eventGetAssetPathFromObject_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ODAssetFunctions_eventGetAssetPathFromObject_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UODAssetFunctions_GetAssetPathFromObject(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODAssetFunctions::execGetAssetPathFromObject)
{
	P_GET_OBJECT(UObject,Z_Param_Object);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UODAssetFunctions::GetAssetPathFromObject(Z_Param_Object);
	P_NATIVE_END;
}
// ********** End Class UODAssetFunctions Function GetAssetPathFromObject **************************

// ********** Begin Class UODAssetFunctions ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODAssetFunctions_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Library/ODAssetFunctions.h" },
		{ "ModuleRelativePath", "Public/Library/ODAssetFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODAssetFunctions constinit property declarations ************************
// ********** End Class UODAssetFunctions constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GenerateThumbnailForSM"), .Pointer = &UODAssetFunctions::execGenerateThumbnailForSM },
		{ .NameUTF8 = UTF8TEXT("GetAssetDataFromObject"), .Pointer = &UODAssetFunctions::execGetAssetDataFromObject },
		{ .NameUTF8 = UTF8TEXT("GetAssetDataFromPath"), .Pointer = &UODAssetFunctions::execGetAssetDataFromPath },
		{ .NameUTF8 = UTF8TEXT("GetAssetPathFromObject"), .Pointer = &UODAssetFunctions::execGetAssetPathFromObject },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UODAssetFunctions_GenerateThumbnailForSM, "GenerateThumbnailForSM" }, // ead25afa9c9283b98ab1955bb5dda0aad45dd9fd
		{ &Z_Construct_UFunction_UODAssetFunctions_GetAssetDataFromObject, "GetAssetDataFromObject" }, // 2720e0e26b9ec9b3a97f4d944b18c925743b3b48
		{ &Z_Construct_UFunction_UODAssetFunctions_GetAssetDataFromPath, "GetAssetDataFromPath" }, // 66b16b76d898a8a2cf56c787becfbd0457b32669
		{ &Z_Construct_UFunction_UODAssetFunctions_GetAssetPathFromObject, "GetAssetPathFromObject" }, // 9772efa7dc116e171bd77b1c432e1762781a7cee
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODAssetFunctions>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UBlueprintFunctionLibrary,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODAssetFunctions,
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
static void UODAssetFunctions_StaticRegisterNativesUODAssetFunctions()
{
	UClass* Class = UODAssetFunctions::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UODAssetFunctions;
UClass* Z_Construct_UClass_UODAssetFunctions(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODAssetFunctions;
		if (!Z_Registration_Info_UClass_UODAssetFunctions.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODAssetFunctions"),
				Z_Registration_Info_UClass_UODAssetFunctions.InnerSingleton,
				UODAssetFunctions_StaticRegisterNativesUODAssetFunctions,
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
		return Z_Registration_Info_UClass_UODAssetFunctions.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODAssetFunctions.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODAssetFunctions.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODAssetFunctions.OuterSingleton;
}
#undef UHT_STATICS
UODAssetFunctions::UODAssetFunctions(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODAssetFunctions);
UODAssetFunctions::~UODAssetFunctions() {}
// ********** End Class UODAssetFunctions **********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Library_ODAssetFunctions_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODAssetFunctions, TEXT("UODAssetFunctions"), &Z_Registration_Info_UClass_UODAssetFunctions, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODAssetFunctions), 3519628780U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Library_ODAssetFunctions_h__Script_ObjectDistribution_8b7cfa4ef6d3af56265d030a9efcd5528d446992{
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
