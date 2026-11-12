// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ASAutoSplineBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeASAutoSplineBase() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USceneComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AutoSpline(ETypeConstructPhase);
AUTOSPLINE_API UClass* Z_Construct_UClass_AASAutoSplineBase(ETypeConstructPhase);
AUTOSPLINE_API UEnum* Z_Construct_UEnum_AutoSpline_EASMeshAxis(ETypeConstructPhase);
AUTOSPLINE_API UEnum* Z_Construct_UEnum_AutoSpline_ESplineObjectRotationType(ETypeConstructPhase);
AUTOSPLINE_API UClass* Z_Construct_UClass_AASAutoSplineBase(ETypeConstructPhase);
AUTOSPLINE_API UClass* Z_Construct_UClass_UASSplineComponent(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum ESplineObjectRotationType *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_AutoSpline_ESplineObjectRotationType_Statics
template<> AUTOSPLINE_NON_ATTRIBUTED_API UEnum* StaticEnum<ESplineObjectRotationType>()
{
	return Z_Construct_UEnum_AutoSpline_ESplineObjectRotationType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Auto Plugin Tool Settings" },
		{ "FollowSpline.DisplayName", "Follow The Spline" },
		{ "FollowSpline.Name", "ESplineObjectRotationType::FollowSpline" },
		{ "FollowSplineAndSurface.DisplayName", "Follow The Spline & Surface" },
		{ "FollowSplineAndSurface.Name", "ESplineObjectRotationType::FollowSplineAndSurface" },
		{ "Keep.DisplayName", "Keep Rotation" },
		{ "Keep.Name", "ESplineObjectRotationType::Keep" },
		{ "ModuleRelativePath", "Public/Spline/ASAutoSplineBase.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESplineObjectRotationType::Keep", (int64)ESplineObjectRotationType::Keep },
		{ "ESplineObjectRotationType::FollowSpline", (int64)ESplineObjectRotationType::FollowSpline },
		{ "ESplineObjectRotationType::FollowSplineAndSurface", (int64)ESplineObjectRotationType::FollowSplineAndSurface },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AutoSpline,
	nullptr,
	"ESplineObjectRotationType",
	"ESplineObjectRotationType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_ESplineObjectRotationType;
UEnum* Z_Construct_UEnum_AutoSpline_ESplineObjectRotationType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_ESplineObjectRotationType.OuterSingleton)
		{
			ZRIE_ESplineObjectRotationType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AutoSpline_ESplineObjectRotationType, (UObject*)Z_Construct_UPackage__Script_AutoSpline(ETypeConstructPhase::Outer), TEXT("ESplineObjectRotationType"));
		}
		return ZRIE_ESplineObjectRotationType.OuterSingleton;
	}
	if (!ZRIE_ESplineObjectRotationType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_ESplineObjectRotationType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_ESplineObjectRotationType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum ESplineObjectRotationType ***************************************************

// ********** Begin Enum EASMeshAxis ***************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_AutoSpline_EASMeshAxis_Statics
template<> AUTOSPLINE_NON_ATTRIBUTED_API UEnum* StaticEnum<EASMeshAxis>()
{
	return Z_Construct_UEnum_AutoSpline_EASMeshAxis(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AxisX.DisplayName", "X" },
		{ "AxisX.Name", "EASMeshAxis::AxisX" },
		{ "AxisY.DisplayName", "Y" },
		{ "AxisY.Name", "EASMeshAxis::AxisY" },
		{ "AxisZ.DisplayName", "Z" },
		{ "AxisZ.Name", "EASMeshAxis::AxisZ" },
		{ "BlueprintType", "true" },
		{ "Category", "Auto Plugin Tool Settings" },
		{ "ModuleRelativePath", "Public/Spline/ASAutoSplineBase.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EASMeshAxis::AxisX", (int64)EASMeshAxis::AxisX },
		{ "EASMeshAxis::AxisY", (int64)EASMeshAxis::AxisY },
		{ "EASMeshAxis::AxisZ", (int64)EASMeshAxis::AxisZ },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AutoSpline,
	nullptr,
	"EASMeshAxis",
	"EASMeshAxis",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EASMeshAxis;
UEnum* Z_Construct_UEnum_AutoSpline_EASMeshAxis(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EASMeshAxis.OuterSingleton)
		{
			ZRIE_EASMeshAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AutoSpline_EASMeshAxis, (UObject*)Z_Construct_UPackage__Script_AutoSpline(ETypeConstructPhase::Outer), TEXT("EASMeshAxis"));
		}
		return ZRIE_EASMeshAxis.OuterSingleton;
	}
	if (!ZRIE_EASMeshAxis.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EASMeshAxis.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EASMeshAxis.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EASMeshAxis *****************************************************************

// ********** Begin Class AASAutoSplineBase ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AASAutoSplineBase_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Spline/ASAutoSplineBase.h" },
		{ "ModuleRelativePath", "Public/Spline/ASAutoSplineBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Spline/ASAutoSplineBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplineComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Spline/ASAutoSplineBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AASAutoSplineBase constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SplineComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AASAutoSplineBase constinit property declarations **************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AASAutoSplineBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class AASAutoSplineBase Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(AASAutoSplineBase, SceneRoot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SplineComponent = { "SplineComponent", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(AASAutoSplineBase, SplineComponent), Z_Construct_UClass_UASSplineComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplineComponent_MetaData), NewProp_SplineComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SplineComponent,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class AASAutoSplineBase Property Definitions *************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AutoSpline,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AASAutoSplineBase,
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
	0x009000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_AASAutoSplineBase;
UClass* Z_Construct_UClass_AASAutoSplineBase(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AASAutoSplineBase;
		if (!Z_Registration_Info_UClass_AASAutoSplineBase.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ASAutoSplineBase"),
				Z_Registration_Info_UClass_AASAutoSplineBase.InnerSingleton,
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
		return Z_Registration_Info_UClass_AASAutoSplineBase.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AASAutoSplineBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AASAutoSplineBase.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AASAutoSplineBase.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AASAutoSplineBase);
AASAutoSplineBase::~AASAutoSplineBase() {}
// ********** End Class AASAutoSplineBase **********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASAutoSplineBase_h__Script_AutoSpline_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_AutoSpline_ESplineObjectRotationType, TEXT("ESplineObjectRotationType"), &ZRIE_ESplineObjectRotationType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 401987926U) },
		{ Z_Construct_UEnum_AutoSpline_EASMeshAxis, TEXT("EASMeshAxis"), &ZRIE_EASMeshAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3861826374U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AASAutoSplineBase, TEXT("AASAutoSplineBase"), &Z_Registration_Info_UClass_AASAutoSplineBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AASAutoSplineBase), 4213544466U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASAutoSplineBase_h__Script_AutoSpline_4eb5dd3bb79172e95429367635fc95bf7bb8a213{
	TEXT("/Script/AutoSpline"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
