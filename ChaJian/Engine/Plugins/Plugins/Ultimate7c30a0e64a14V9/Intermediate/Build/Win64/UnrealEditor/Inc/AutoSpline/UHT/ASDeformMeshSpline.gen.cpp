// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASDeformMeshSpline.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeASDeformMeshSpline() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRandomStream(ETypeConstructPhase);
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionEnabled(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USplineMeshComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AutoSpline(ETypeConstructPhase);
AUTOSPLINE_API UClass* Z_Construct_UClass_AASAutoSplineBase(ETypeConstructPhase);
AUTOSPLINE_API UClass* Z_Construct_UClass_AASDeformMeshSpline(ETypeConstructPhase);
AUTOSPLINE_API UEnum* Z_Construct_UEnum_AutoSpline_EASMeshAxis(ETypeConstructPhase);
AUTOSPLINE_API UClass* Z_Construct_UClass_AASAutoSplineBase(ETypeConstructPhase);
AUTOSPLINE_API UClass* Z_Construct_UClass_AASDeformMeshSpline(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class AASDeformMeshSpline ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AASDeformMeshSpline_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Spline/ASDeformMeshSpline.h" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplineMeshComponents_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomStream_MetaData[] = {
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticMeshes_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSelectRandom_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "DisplayName", "Random Placement" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetOnSpline_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ForwardAxis_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ForwardScale_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ClampMin", "0.010000" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionEnabled_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoCloseTheSpline_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "DisplayName", "Auto Close The Spline" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AutoCloseTheSpline_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "EditCondition", "bAutoCloseTheSpline" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
		{ "ToolTip", "The spline closes automatically when the first and last point are close enough" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
		{ "ToolTip", "Stream value for random actions" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCopyASpline_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CopyASpline_MetaData[] = {
		{ "Category", "Tool Settings" },
		{ "EditCondition", "bCopyASpline" },
		{ "ModuleRelativePath", "Public/Spline/ASDeformMeshSpline.h" },
	};
#endif // WITH_EDITORONLY_DATA
#endif // WITH_METADATA

// ********** Begin Class AASDeformMeshSpline constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SplineMeshComponents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SplineMeshComponents;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomStream;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMeshes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StaticMeshes;
	static void NewProp_bSelectRandom_SetBit(void* Obj)
	{
		((AASDeformMeshSpline*)Obj)->bSelectRandom = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSelectRandom;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OffsetOnSpline;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ForwardAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ForwardAxis;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ForwardScale;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CollisionEnabled;
	static void NewProp_bAutoCloseTheSpline_SetBit(void* Obj)
	{
		((AASDeformMeshSpline*)Obj)->bAutoCloseTheSpline = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoCloseTheSpline;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AutoCloseTheSpline;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
#if WITH_EDITORONLY_DATA
	static void NewProp_bCopyASpline_SetBit(void* Obj)
	{
		((AASDeformMeshSpline*)Obj)->bCopyASpline = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCopyASpline;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CopyASpline;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AASDeformMeshSpline constinit property declarations ************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AASDeformMeshSpline>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class AASDeformMeshSpline Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SplineMeshComponents_Inner = { "SplineMeshComponents", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_USplineMeshComponent, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_SplineMeshComponents = { "SplineMeshComponents", nullptr, (EPropertyFlags)0x0144008000000008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(AASDeformMeshSpline, SplineMeshComponents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplineMeshComponents_MetaData), NewProp_SplineMeshComponents_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RandomStream = { "RandomStream", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(AASDeformMeshSpline, RandomStream), Z_Construct_UScriptStruct_FRandomStream, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomStream_MetaData), NewProp_RandomStream_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_StaticMeshes_Inner = { "StaticMeshes", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_StaticMeshes = { "StaticMeshes", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(AASDeformMeshSpline, StaticMeshes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticMeshes_MetaData), NewProp_StaticMeshes_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSelectRandom = { "bSelectRandom", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AASDeformMeshSpline), &UHT_STATICS::NewProp_bSelectRandom_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSelectRandom_MetaData), NewProp_bSelectRandom_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_OffsetOnSpline = { "OffsetOnSpline", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AASDeformMeshSpline, OffsetOnSpline), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetOnSpline_MetaData), NewProp_OffsetOnSpline_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ForwardAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ForwardAxis = { "ForwardAxis", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(AASDeformMeshSpline, ForwardAxis), Z_Construct_UEnum_AutoSpline_EASMeshAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ForwardAxis_MetaData), NewProp_ForwardAxis_MetaData) }; // e62ecb468e040c9b167256deff50ec1b966aec3d
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ForwardScale = { "ForwardScale", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AASDeformMeshSpline, ForwardScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ForwardScale_MetaData), NewProp_ForwardScale_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CollisionEnabled = { "CollisionEnabled", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(AASDeformMeshSpline, CollisionEnabled), Z_Construct_UEnum_Engine_ECollisionEnabled, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionEnabled_MetaData), NewProp_CollisionEnabled_MetaData) }; // c8a7ab99d1a880814023560b6b0d1971eef51d4c
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAutoCloseTheSpline = { "bAutoCloseTheSpline", nullptr, (EPropertyFlags)0x0010040000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AASDeformMeshSpline), &UHT_STATICS::NewProp_bAutoCloseTheSpline_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoCloseTheSpline_MetaData), NewProp_bAutoCloseTheSpline_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_AutoCloseTheSpline = { "AutoCloseTheSpline", nullptr, (EPropertyFlags)0x0010040000000001, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AASDeformMeshSpline, AutoCloseTheSpline), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AutoCloseTheSpline_MetaData), NewProp_AutoCloseTheSpline_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010040000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AASDeformMeshSpline, Seed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Seed_MetaData), NewProp_Seed_MetaData) };
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCopyASpline = { "bCopyASpline", nullptr, (EPropertyFlags)0x0010040800000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AASDeformMeshSpline), &UHT_STATICS::NewProp_bCopyASpline_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCopyASpline_MetaData), NewProp_bCopyASpline_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CopyASpline = { "CopyASpline", nullptr, (EPropertyFlags)0x0114040800000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(AASDeformMeshSpline, CopyASpline), Z_Construct_UClass_AASAutoSplineBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CopyASpline_MetaData), NewProp_CopyASpline_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SplineMeshComponents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SplineMeshComponents,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RandomStream,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StaticMeshes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StaticMeshes,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSelectRandom,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OffsetOnSpline,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ForwardAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ForwardAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ForwardScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CollisionEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAutoCloseTheSpline,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AutoCloseTheSpline,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Seed,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCopyASpline,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CopyASpline,
#endif // WITH_EDITORONLY_DATA
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class AASDeformMeshSpline Property Definitions ***********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AASAutoSplineBase,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AutoSpline,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AASDeformMeshSpline,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_AASDeformMeshSpline;
UClass* Z_Construct_UClass_AASDeformMeshSpline(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AASDeformMeshSpline;
		if (!Z_Registration_Info_UClass_AASDeformMeshSpline.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ASDeformMeshSpline"),
				Z_Registration_Info_UClass_AASDeformMeshSpline.InnerSingleton,
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
		return Z_Registration_Info_UClass_AASDeformMeshSpline.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AASDeformMeshSpline.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AASDeformMeshSpline.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AASDeformMeshSpline.OuterSingleton;
}
#undef UHT_STATICS
AASDeformMeshSpline::AASDeformMeshSpline() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AASDeformMeshSpline);
AASDeformMeshSpline::~AASDeformMeshSpline() {}
// ********** End Class AASDeformMeshSpline ********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASDeformMeshSpline_h__Script_AutoSpline_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AASDeformMeshSpline, TEXT("AASDeformMeshSpline"), &Z_Registration_Info_UClass_AASDeformMeshSpline, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AASDeformMeshSpline), 3926240580U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASDeformMeshSpline_h__Script_AutoSpline_78755c56e2a7ff634e76c807215bda74947c97ce{
	TEXT("/Script/AutoSpline"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
