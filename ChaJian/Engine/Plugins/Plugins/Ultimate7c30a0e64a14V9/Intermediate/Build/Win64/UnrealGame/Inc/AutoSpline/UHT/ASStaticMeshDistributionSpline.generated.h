// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Spline/ASStaticMeshDistributionSpline.h"

#ifdef AUTOSPLINE_ASStaticMeshDistributionSpline_generated_h
#error "ASStaticMeshDistributionSpline.generated.h already included, missing '#pragma once' in ASStaticMeshDistributionSpline.h"
#endif
#define AUTOSPLINE_ASStaticMeshDistributionSpline_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AASStaticMeshDistributionSpline ******************************************
struct Z_Construct_UClass_AASStaticMeshDistributionSpline_Statics;
AUTOSPLINE_API UClass* Z_Construct_UClass_AASStaticMeshDistributionSpline(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASStaticMeshDistributionSpline_h_24_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AASStaticMeshDistributionSpline_Statics; \
	friend AUTOSPLINE_API UClass* ::Z_Construct_UClass_AASStaticMeshDistributionSpline(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AASStaticMeshDistributionSpline, AASAutoSplineBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AutoSpline"), Z_Construct_UClass_AASStaticMeshDistributionSpline) \
	DECLARE_SERIALIZER(AASStaticMeshDistributionSpline)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASStaticMeshDistributionSpline_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AASStaticMeshDistributionSpline(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AASStaticMeshDistributionSpline(AASStaticMeshDistributionSpline&&) = delete; \
	AASStaticMeshDistributionSpline(const AASStaticMeshDistributionSpline&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AASStaticMeshDistributionSpline); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AASStaticMeshDistributionSpline); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AASStaticMeshDistributionSpline) \
	NO_API virtual ~AASStaticMeshDistributionSpline();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASStaticMeshDistributionSpline_h_21_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASStaticMeshDistributionSpline_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASStaticMeshDistributionSpline_h_24_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASStaticMeshDistributionSpline_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AASStaticMeshDistributionSpline;

// ********** End Class AASStaticMeshDistributionSpline ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASStaticMeshDistributionSpline_h

// ********** Begin Enum ENonDeformInstanceType ****************************************************
#define FOREACH_ENUM_ENONDEFORMINSTANCETYPE(op) \
	op(ENonDeformInstanceType::Sm) \
	op(ENonDeformInstanceType::Ism) \
	op(ENonDeformInstanceType::HIsm) 

enum class ENonDeformInstanceType : uint8;
template<> struct TIsUEnumClass<ENonDeformInstanceType> { enum { Value = true }; };
template<> UE_NODEBUG AUTOSPLINE_NON_ATTRIBUTED_API UEnum* StaticEnum<ENonDeformInstanceType>();
// ********** End Enum ENonDeformInstanceType ******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
