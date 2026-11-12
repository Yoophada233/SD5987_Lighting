// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Spline/ASAutoSplineBase.h"

#ifdef AUTOSPLINE_ASAutoSplineBase_generated_h
#error "ASAutoSplineBase.generated.h already included, missing '#pragma once' in ASAutoSplineBase.h"
#endif
#define AUTOSPLINE_ASAutoSplineBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AASAutoSplineBase ********************************************************
struct Z_Construct_UClass_AASAutoSplineBase_Statics;
AUTOSPLINE_API UClass* Z_Construct_UClass_AASAutoSplineBase(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASAutoSplineBase_h_31_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AASAutoSplineBase_Statics; \
	friend AUTOSPLINE_API UClass* ::Z_Construct_UClass_AASAutoSplineBase(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AASAutoSplineBase, AActor, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/AutoSpline"), Z_Construct_UClass_AASAutoSplineBase) \
	DECLARE_SERIALIZER(AASAutoSplineBase)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASAutoSplineBase_h_31_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AASAutoSplineBase(AASAutoSplineBase&&) = delete; \
	AASAutoSplineBase(const AASAutoSplineBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AASAutoSplineBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AASAutoSplineBase); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AASAutoSplineBase) \
	NO_API virtual ~AASAutoSplineBase();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASAutoSplineBase_h_28_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASAutoSplineBase_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASAutoSplineBase_h_31_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASAutoSplineBase_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AASAutoSplineBase;

// ********** End Class AASAutoSplineBase **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASAutoSplineBase_h

// ********** Begin Enum ESplineObjectRotationType *************************************************
#define FOREACH_ENUM_ESPLINEOBJECTROTATIONTYPE(op) \
	op(ESplineObjectRotationType::Keep) \
	op(ESplineObjectRotationType::FollowSpline) \
	op(ESplineObjectRotationType::FollowSplineAndSurface) 

enum class ESplineObjectRotationType : uint8;
template<> struct TIsUEnumClass<ESplineObjectRotationType> { enum { Value = true }; };
template<> UE_NODEBUG AUTOSPLINE_NON_ATTRIBUTED_API UEnum* StaticEnum<ESplineObjectRotationType>();
// ********** End Enum ESplineObjectRotationType ***************************************************

// ********** Begin Enum EASMeshAxis ***************************************************************
#define FOREACH_ENUM_EASMESHAXIS(op) \
	op(EASMeshAxis::AxisX) \
	op(EASMeshAxis::AxisY) \
	op(EASMeshAxis::AxisZ) 

enum class EASMeshAxis : uint8;
template<> struct TIsUEnumClass<EASMeshAxis> { enum { Value = true }; };
template<> UE_NODEBUG AUTOSPLINE_NON_ATTRIBUTED_API UEnum* StaticEnum<EASMeshAxis>();
// ********** End Enum EASMeshAxis *****************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
