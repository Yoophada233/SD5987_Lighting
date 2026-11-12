// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODPaletteDataObject.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeODPaletteDataObject() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ObjectDistribution(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UEnum* Z_Construct_UEnum_ObjectDistribution_EObjectOrientation(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODPaletteDataObject(ETypeConstructPhase);
OBJECTDISTRIBUTION_API UClass* Z_Construct_UClass_UODPaletteDataObject(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UODPaletteDataObject Function OnPresetLoaded *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UODPaletteDataObject_OnPresetLoaded_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnPresetLoaded constinit property declarations ************************
// ********** End Function OnPresetLoaded constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UODPaletteDataObject, nullptr, "OnPresetLoaded", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UODPaletteDataObject_OnPresetLoaded(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UODPaletteDataObject::execOnPresetLoaded)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPresetLoaded();
	P_NATIVE_END;
}
// ********** End Class UODPaletteDataObject Function OnPresetLoaded *******************************

// ********** Begin Class UODPaletteDataObject *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UODPaletteDataObject_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Data/ODPaletteDataObject.h" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Object Data" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSelectRandomMaterial_MetaData[] = {
		{ "Category", "Object Data" },
		{ "DisplayName", "Override Material" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
		{ "NoResetToDefault", "" },
		{ "ToolTip", "Assign new material for first material slot" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SecondRandomMaterial_MetaData[] = {
		{ "Category", "Object Data" },
		{ "DisplayName", "New Material" },
		{ "EditCondition", "bSelectRandomMaterial" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSelectMaterialRandomly_MetaData[] = {
		{ "Category", "Object Data" },
		{ "DisplayName", "Select Material Randomly" },
		{ "EditCondition", "bSelectRandomMaterial" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
		{ "NoResetToDefault", "" },
		{ "ToolTip", "It randomly changes the assigned material or doesn't change it at all." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnCount_MetaData[] = {
		{ "Category", "Object Data" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleRange_MetaData[] = {
		{ "Category", "Object Data" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinearDamping_MetaData[] = {
		{ "Category", "Object Data" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AngularDamping_MetaData[] = {
		{ "Category", "Object Data" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[] = {
		{ "Category", "Object Data" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
		{ "NoResetToDefault", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrientationType_MetaData[] = {
		{ "Category", "Object Data" },
		{ "ModuleRelativePath", "Public/Data/ODPaletteDataObject.h" },
		{ "NoResetToDefault", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class UODPaletteDataObject constinit property declarations *********************
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_StaticMesh;
	static void NewProp_bSelectRandomMaterial_SetBit(void* Obj)
	{
		((UODPaletteDataObject*)Obj)->bSelectRandomMaterial = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSelectRandomMaterial;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SecondRandomMaterial;
	static void NewProp_bSelectMaterialRandomly_SetBit(void* Obj)
	{
		((UODPaletteDataObject*)Obj)->bSelectMaterialRandomly = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSelectMaterialRandomly;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SpawnCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ScaleRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LinearDamping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AngularDamping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Mass;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OrientationType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OrientationType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UODPaletteDataObject constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnPresetLoaded"), .Pointer = &UODPaletteDataObject::execOnPresetLoaded },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UODPaletteDataObject_OnPresetLoaded, "OnPresetLoaded" }, // 2492452d4028c1237eb789c03c8c8d449a82586d
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UODPaletteDataObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UODPaletteDataObject Property Definitions ********************************
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x0014000002000001, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteDataObject, StaticMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticMesh_MetaData), NewProp_StaticMesh_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSelectRandomMaterial = { "bSelectRandomMaterial", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODPaletteDataObject), &UHT_STATICS::NewProp_bSelectRandomMaterial_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSelectRandomMaterial_MetaData), NewProp_bSelectRandomMaterial_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_SecondRandomMaterial = { "SecondRandomMaterial", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteDataObject, SecondRandomMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SecondRandomMaterial_MetaData), NewProp_SecondRandomMaterial_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSelectMaterialRandomly = { "bSelectMaterialRandomly", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UODPaletteDataObject), &UHT_STATICS::NewProp_bSelectMaterialRandomly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSelectMaterialRandomly_MetaData), NewProp_bSelectMaterialRandomly_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SpawnCount = { "SpawnCount", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteDataObject, SpawnCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnCount_MetaData), NewProp_SpawnCount_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ScaleRange = { "ScaleRange", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteDataObject, ScaleRange), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleRange_MetaData), NewProp_ScaleRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LinearDamping = { "LinearDamping", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteDataObject, LinearDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinearDamping_MetaData), NewProp_LinearDamping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AngularDamping = { "AngularDamping", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteDataObject, AngularDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AngularDamping_MetaData), NewProp_AngularDamping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteDataObject, Mass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mass_MetaData), NewProp_Mass_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_OrientationType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_OrientationType = { "OrientationType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UODPaletteDataObject, OrientationType), Z_Construct_UEnum_ObjectDistribution_EObjectOrientation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrientationType_MetaData), NewProp_OrientationType_MetaData) }; // 6776627ad0cc7a6f37b91a7cdb5f9110a452040e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StaticMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSelectRandomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SecondRandomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSelectMaterialRandomly,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScaleRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LinearDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AngularDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Mass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OrientationType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OrientationType,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UODPaletteDataObject Property Definitions **********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UObject,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ObjectDistribution,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UODPaletteDataObject,
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
static void UODPaletteDataObject_StaticRegisterNativesUODPaletteDataObject()
{
	UClass* Class = UODPaletteDataObject::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UODPaletteDataObject;
UClass* Z_Construct_UClass_UODPaletteDataObject(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UODPaletteDataObject;
		if (!Z_Registration_Info_UClass_UODPaletteDataObject.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ODPaletteDataObject"),
				Z_Registration_Info_UClass_UODPaletteDataObject.InnerSingleton,
				UODPaletteDataObject_StaticRegisterNativesUODPaletteDataObject,
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
		return Z_Registration_Info_UClass_UODPaletteDataObject.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UODPaletteDataObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UODPaletteDataObject.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UODPaletteDataObject.OuterSingleton;
}
#undef UHT_STATICS
UODPaletteDataObject::UODPaletteDataObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UODPaletteDataObject);
UODPaletteDataObject::~UODPaletteDataObject() {}
// ********** End Class UODPaletteDataObject *******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODPaletteDataObject_h__Script_ObjectDistribution_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UODPaletteDataObject, TEXT("UODPaletteDataObject"), &Z_Registration_Info_UClass_UODPaletteDataObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UODPaletteDataObject), 3599644887U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODPaletteDataObject_h__Script_ObjectDistribution_183ef81ef7e7dd82e38c933e3ca6da1628358d31{
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
