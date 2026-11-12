// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Libraries/MBExtendedMath.h"

#ifdef MODULARBUILDING_MBExtendedMath_generated_h
#error "MBExtendedMath.generated.h already included, missing '#pragma once' in MBExtendedMath.h"
#endif
#define MODULARBUILDING_MBExtendedMath_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EMBAxis : uint8;

// ********** Begin Class UMBExtendedMath **********************************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetNearestAxisOfVector); \
	DECLARE_FUNCTION(execGetAxisEnumOfDirectionVector); \
	DECLARE_FUNCTION(execGetAxisVectorWithEnumValue); \
	DECLARE_FUNCTION(execGetSecAxis); \
	DECLARE_FUNCTION(execGetHighestAxisAndDirectionOfVector); \
	DECLARE_FUNCTION(execSetAxisOfVector); \
	DECLARE_FUNCTION(execGetAxisOfVector);


struct Z_Construct_UClass_UMBExtendedMath_Statics;
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBExtendedMath(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h_16_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UMBExtendedMath_Statics; \
	friend MODULARBUILDING_API UClass* ::Z_Construct_UClass_UMBExtendedMath(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UMBExtendedMath, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModularBuilding"), Z_Construct_UClass_UMBExtendedMath) \
	DECLARE_SERIALIZER(UMBExtendedMath)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMBExtendedMath(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMBExtendedMath(UMBExtendedMath&&) = delete; \
	UMBExtendedMath(const UMBExtendedMath&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMBExtendedMath); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMBExtendedMath); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMBExtendedMath) \
	NO_API virtual ~UMBExtendedMath();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h_13_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h_16_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMBExtendedMath;

// ********** End Class UMBExtendedMath ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBExtendedMath_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
