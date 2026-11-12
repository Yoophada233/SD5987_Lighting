// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBMActionSettingsObj.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBMActionSettingsObj() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBAxis(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBMActionSettingsObj(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBMActionSettingsObj(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UMBMActionSettingsObj Function Duplicate *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBMActionSettingsObj_Duplicate_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Multiple Modular Duplication" },
		{ "ModuleRelativePath", "Public/Data/MBMActionSettingsObj.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Duplicate constinit property declarations *****************************
// ********** End Function Duplicate constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBMActionSettingsObj, nullptr, "Duplicate", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBMActionSettingsObj_Duplicate(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBMActionSettingsObj::execDuplicate)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Duplicate();
	P_NATIVE_END;
}
// ********** End Class UMBMActionSettingsObj Function Duplicate ***********************************

// ********** Begin Class UMBMActionSettingsObj ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBMActionSettingsObj_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Data/MBMActionSettingsObj.h" },
		{ "ModuleRelativePath", "Public/Data/MBMActionSettingsObj.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfDuplications_MetaData[] = {
		{ "Category", "Multiple Modular Duplication" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Data/MBMActionSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DuplicationAxis_MetaData[] = {
		{ "Category", "Multiple Modular Duplication" },
		{ "ModuleRelativePath", "Public/Data/MBMActionSettingsObj.h" },
		{ "NoResetToDefault", "" },
		{ "ValidEnumValues", "AxisX,AxisY,AxisZ" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "Category", "Multiple Modular Duplication" },
		{ "ModuleRelativePath", "Public/Data/MBMActionSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPositiveDirection_MetaData[] = {
		{ "Category", "Multiple Modular Duplication" },
		{ "DisplayName", "Positive Direction" },
		{ "ModuleRelativePath", "Public/Data/MBMActionSettingsObj.h" },
		{ "NoResetToDefault", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBMActionSettingsObj constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfDuplications;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DuplicationAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DuplicationAxis;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Offset;
	static void NewProp_bPositiveDirection_SetBit(void* Obj)
	{
		((UMBMActionSettingsObj*)Obj)->bPositiveDirection = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPositiveDirection;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBMActionSettingsObj constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Duplicate"), .Pointer = &UMBMActionSettingsObj::execDuplicate },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBMActionSettingsObj_Duplicate, "Duplicate" }, // 1c18b92a455b14e7758c03c6d79794f0da1f3791
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBMActionSettingsObj>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBMActionSettingsObj Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NumberOfDuplications = { "NumberOfDuplications", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UMBMActionSettingsObj, NumberOfDuplications), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumberOfDuplications_MetaData), NewProp_NumberOfDuplications_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_DuplicationAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_DuplicationAxis = { "DuplicationAxis", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBMActionSettingsObj, DuplicationAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DuplicationAxis_MetaData), NewProp_DuplicationAxis_MetaData) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBMActionSettingsObj, Offset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPositiveDirection = { "bPositiveDirection", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UMBMActionSettingsObj), &UHT_STATICS::NewProp_bPositiveDirection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPositiveDirection_MetaData), NewProp_bPositiveDirection_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NumberOfDuplications,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DuplicationAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DuplicationAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPositiveDirection,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBMActionSettingsObj Property Definitions *********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UObject,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBMActionSettingsObj,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UMBMActionSettingsObj_StaticRegisterNativesUMBMActionSettingsObj()
{
	UClass* Class = UMBMActionSettingsObj::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBMActionSettingsObj;
UClass* Z_Construct_UClass_UMBMActionSettingsObj(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBMActionSettingsObj;
		if (!Z_Registration_Info_UClass_UMBMActionSettingsObj.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBMActionSettingsObj"),
				Z_Registration_Info_UClass_UMBMActionSettingsObj.InnerSingleton,
				UMBMActionSettingsObj_StaticRegisterNativesUMBMActionSettingsObj,
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
		return Z_Registration_Info_UClass_UMBMActionSettingsObj.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBMActionSettingsObj.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBMActionSettingsObj.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBMActionSettingsObj.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBMActionSettingsObj);
UMBMActionSettingsObj::~UMBMActionSettingsObj() {}
// ********** End Class UMBMActionSettingsObj ******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBMActionSettingsObj_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBMActionSettingsObj, TEXT("UMBMActionSettingsObj"), &Z_Registration_Info_UClass_UMBMActionSettingsObj, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBMActionSettingsObj), 500584901U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Data_MBMActionSettingsObj_h__Script_ModularBuilding_64afd4214822f0f0ea7f3d379f9b6d08d8b5c2b5{
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
