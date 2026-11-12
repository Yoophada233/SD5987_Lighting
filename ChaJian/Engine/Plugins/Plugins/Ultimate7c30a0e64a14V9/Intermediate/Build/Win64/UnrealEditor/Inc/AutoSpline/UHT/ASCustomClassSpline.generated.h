// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Spline/ASCustomClassSpline.h"

#ifdef AUTOSPLINE_ASCustomClassSpline_generated_h
#error "ASCustomClassSpline.generated.h already included, missing '#pragma once' in ASCustomClassSpline.h"
#endif
#define AUTOSPLINE_ASCustomClassSpline_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AASCustomClassSpline *****************************************************
struct Z_Construct_UClass_AASCustomClassSpline_Statics;
AUTOSPLINE_API UClass* Z_Construct_UClass_AASCustomClassSpline(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASCustomClassSpline_h_23_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AASCustomClassSpline_Statics; \
	friend AUTOSPLINE_API UClass* ::Z_Construct_UClass_AASCustomClassSpline(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AASCustomClassSpline, AASAutoSplineBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AutoSpline"), Z_Construct_UClass_AASCustomClassSpline) \
	DECLARE_SERIALIZER(AASCustomClassSpline)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASCustomClassSpline_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AASCustomClassSpline(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AASCustomClassSpline(AASCustomClassSpline&&) = delete; \
	AASCustomClassSpline(const AASCustomClassSpline&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AASCustomClassSpline); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AASCustomClassSpline); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AASCustomClassSpline) \
	NO_API virtual ~AASCustomClassSpline();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASCustomClassSpline_h_20_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASCustomClassSpline_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASCustomClassSpline_h_23_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASCustomClassSpline_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AASCustomClassSpline;

// ********** End Class AASCustomClassSpline *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_AutoSpline_Public_Spline_ASCustomClassSpline_h

// ********** Begin Enum ESplineClassInstType ******************************************************
#define FOREACH_ENUM_ESPLINECLASSINSTTYPE(op) \
	op(ESplineClassInstType::Component) \
	op(ESplineClassInstType::Actor) 

enum class ESplineClassInstType : uint8;
template<> struct TIsUEnumClass<ESplineClassInstType> { enum { Value = true }; };
template<> UE_NODEBUG AUTOSPLINE_NON_ATTRIBUTED_API UEnum* StaticEnum<ESplineClassInstType>();
// ********** End Enum ESplineClassInstType ********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
