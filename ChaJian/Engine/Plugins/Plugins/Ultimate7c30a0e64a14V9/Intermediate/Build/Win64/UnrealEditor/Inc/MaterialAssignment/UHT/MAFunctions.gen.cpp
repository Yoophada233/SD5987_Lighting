// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MAFunctions.h"
#include "AssetRegistry/AssetData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMAFunctions() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FAssetData(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_MaterialAssignment(ETypeConstructPhase);
MATERIALASSIGNMENT_API UClass* Z_Construct_UClass_UMAFunctions(ETypeConstructPhase);
MATERIALASSIGNMENT_API UClass* Z_Construct_UClass_UMAFunctions(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMAFunctions Function FindTheMostSuitableMaterialForTheNameSlot **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMAFunctions_FindTheMostSuitableMaterialForTheNameSlot_Statics
struct UHT_STATICS
{
	struct MAFunctions_eventFindTheMostSuitableMaterialForTheNameSlot_Parms
	{
		FString InSlotName;
		TArray<FAssetData> MaterialList;
		FAssetData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Material Assignment" },
		{ "ModuleRelativePath", "Public/Library/MAFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSlotName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialList_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FindTheMostSuitableMaterialForTheNameSlot constinit property declarations 
	static const UECodeGen_Private::FStrPropertyParams NewProp_InSlotName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaterialList_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MaterialList;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindTheMostSuitableMaterialForTheNameSlot constinit property declarations 
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindTheMostSuitableMaterialForTheNameSlot Property Definitions ********
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_InSlotName = { "InSlotName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(MAFunctions_eventFindTheMostSuitableMaterialForTheNameSlot_Parms, InSlotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSlotName_MetaData), NewProp_InSlotName_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_MaterialList_Inner = { "MaterialList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(0, nullptr) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_MaterialList = { "MaterialList", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(MAFunctions_eventFindTheMostSuitableMaterialForTheNameSlot_Parms, MaterialList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialList_MetaData), NewProp_MaterialList_MetaData) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(MAFunctions_eventFindTheMostSuitableMaterialForTheNameSlot_Parms, ReturnValue), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(0, nullptr) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InSlotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialList_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function FindTheMostSuitableMaterialForTheNameSlot Property Definitions **********
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMAFunctions, nullptr, "FindTheMostSuitableMaterialForTheNameSlot", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MAFunctions_eventFindTheMostSuitableMaterialForTheNameSlot_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MAFunctions_eventFindTheMostSuitableMaterialForTheNameSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMAFunctions_FindTheMostSuitableMaterialForTheNameSlot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMAFunctions::execFindTheMostSuitableMaterialForTheNameSlot)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InSlotName);
	P_GET_TARRAY_REF(FAssetData,Z_Param_Out_MaterialList);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FAssetData*)Z_Param__Result=UMAFunctions::FindTheMostSuitableMaterialForTheNameSlot(Z_Param_InSlotName,Z_Param_Out_MaterialList);
	P_NATIVE_END;
}
// ********** End Class UMAFunctions Function FindTheMostSuitableMaterialForTheNameSlot ************

// ********** Begin Class UMAFunctions Function GetAllMaterialInstances ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMAFunctions_GetAllMaterialInstances_Statics
struct UHT_STATICS
{
	struct MAFunctions_eventGetAllMaterialInstances_Parms
	{
		TArray<FAssetData> OutAssets;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Material Assignment" },
		{ "ModuleRelativePath", "Public/Library/MAFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllMaterialInstances constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutAssets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutAssets;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllMaterialInstances constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllMaterialInstances Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OutAssets_Inner = { "OutAssets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(0, nullptr) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_OutAssets = { "OutAssets", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(MAFunctions_eventGetAllMaterialInstances_Parms, OutAssets), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 660989d449755afe3ad4fca49ba0318de0603d9e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutAssets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutAssets,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAllMaterialInstances Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMAFunctions, nullptr, "GetAllMaterialInstances", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MAFunctions_eventGetAllMaterialInstances_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MAFunctions_eventGetAllMaterialInstances_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMAFunctions_GetAllMaterialInstances(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMAFunctions::execGetAllMaterialInstances)
{
	P_GET_TARRAY_REF(FAssetData,Z_Param_Out_OutAssets);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMAFunctions::GetAllMaterialInstances(Z_Param_Out_OutAssets);
	P_NATIVE_END;
}
// ********** End Class UMAFunctions Function GetAllMaterialInstances ******************************

// ********** Begin Class UMAFunctions Function IsMaterialInUsed ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMAFunctions_IsMaterialInUsed_Statics
struct UHT_STATICS
{
	struct MAFunctions_eventIsMaterialInUsed_Parms
	{
		UStaticMesh* InStaticMesh;
		int32 InMaterialIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Material Assignment" },
		{ "ModuleRelativePath", "Public/Library/MAFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsMaterialInUsed constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InStaticMesh;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InMaterialIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MAFunctions_eventIsMaterialInUsed_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsMaterialInUsed constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsMaterialInUsed Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InStaticMesh = { "InStaticMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(MAFunctions_eventIsMaterialInUsed_Parms, InStaticMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_InMaterialIndex = { "InMaterialIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(MAFunctions_eventIsMaterialInUsed_Parms, InMaterialIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(MAFunctions_eventIsMaterialInUsed_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InStaticMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InMaterialIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsMaterialInUsed Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMAFunctions, nullptr, "IsMaterialInUsed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::MAFunctions_eventIsMaterialInUsed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::MAFunctions_eventIsMaterialInUsed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMAFunctions_IsMaterialInUsed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMAFunctions::execIsMaterialInUsed)
{
	P_GET_OBJECT(UStaticMesh,Z_Param_InStaticMesh);
	P_GET_PROPERTY(FIntProperty,Z_Param_InMaterialIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UMAFunctions::IsMaterialInUsed(Z_Param_InStaticMesh,Z_Param_InMaterialIndex);
	P_NATIVE_END;
}
// ********** End Class UMAFunctions Function IsMaterialInUsed *************************************

// ********** Begin Class UMAFunctions *************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMAFunctions_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Library/MAFunctions.h" },
		{ "ModuleRelativePath", "Public/Library/MAFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMAFunctions constinit property declarations *****************************
// ********** End Class UMAFunctions constinit property declarations *******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("FindTheMostSuitableMaterialForTheNameSlot"), .Pointer = &UMAFunctions::execFindTheMostSuitableMaterialForTheNameSlot },
		{ .NameUTF8 = UTF8TEXT("GetAllMaterialInstances"), .Pointer = &UMAFunctions::execGetAllMaterialInstances },
		{ .NameUTF8 = UTF8TEXT("IsMaterialInUsed"), .Pointer = &UMAFunctions::execIsMaterialInUsed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMAFunctions_FindTheMostSuitableMaterialForTheNameSlot, "FindTheMostSuitableMaterialForTheNameSlot" }, // a227d7a2c6395afc56f3dae72eedcaccaa091057
		{ &Z_Construct_UFunction_UMAFunctions_GetAllMaterialInstances, "GetAllMaterialInstances" }, // be1755c1a454c09db3fe5868065c5dbc2130aa73
		{ &Z_Construct_UFunction_UMAFunctions_IsMaterialInUsed, "IsMaterialInUsed" }, // 4ea52ca2181872f64653a8d684f08fa9899aa88f
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMAFunctions>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UBlueprintFunctionLibrary,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_MaterialAssignment,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMAFunctions,
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
static void UMAFunctions_StaticRegisterNativesUMAFunctions()
{
	UClass* Class = UMAFunctions::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMAFunctions;
UClass* Z_Construct_UClass_UMAFunctions(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMAFunctions;
		if (!Z_Registration_Info_UClass_UMAFunctions.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MAFunctions"),
				Z_Registration_Info_UClass_UMAFunctions.InnerSingleton,
				UMAFunctions_StaticRegisterNativesUMAFunctions,
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
		return Z_Registration_Info_UClass_UMAFunctions.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMAFunctions.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMAFunctions.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMAFunctions.OuterSingleton;
}
#undef UHT_STATICS
UMAFunctions::UMAFunctions(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMAFunctions);
UMAFunctions::~UMAFunctions() {}
// ********** End Class UMAFunctions ***************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h__Script_MaterialAssignment_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMAFunctions, TEXT("UMAFunctions"), &Z_Registration_Info_UClass_UMAFunctions, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMAFunctions), 495513383U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h__Script_MaterialAssignment_cddbfc9fe4c2698e680db23db0a7f981f6dbdc75{
	TEXT("/Script/MaterialAssignment"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
