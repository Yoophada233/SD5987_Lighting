// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Libraries/MBActorFunctions.h"

#ifdef MODULARBUILDING_MBActorFunctions_generated_h
#error "MBActorFunctions.generated.h already included, missing '#pragma once' in MBActorFunctions.h"
#endif
#define MODULARBUILDING_MBActorFunctions_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
enum class EBuildingCategory : uint8;

// ********** Begin Class UMBActorFunctions ********************************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetBuildingCategory); \
	DECLARE_FUNCTION(execGetAllActorsWithGivenObjectNames); \
	DECLARE_FUNCTION(execGetActorWithObjectName); \
	DECLARE_FUNCTION(execIsActorFromTool); \
	DECLARE_FUNCTION(execGetAllModularActorsInWorld); \
	DECLARE_FUNCTION(execFilterModularActors); \
	DECLARE_FUNCTION(execGetAllActorsTransportPointWithExtents); \
	DECLARE_FUNCTION(execGetAllActorsTransportPoint); \
	DECLARE_FUNCTION(execGetAllActorsUnderTheFolderPath); \
	DECLARE_FUNCTION(execFilterForCategory);


struct Z_Construct_UClass_UMBActorFunctions_Statics;
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBActorFunctions(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h_15_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UMBActorFunctions_Statics; \
	friend MODULARBUILDING_API UClass* ::Z_Construct_UClass_UMBActorFunctions(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UMBActorFunctions, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModularBuilding"), Z_Construct_UClass_UMBActorFunctions) \
	DECLARE_SERIALIZER(UMBActorFunctions)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMBActorFunctions(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMBActorFunctions(UMBActorFunctions&&) = delete; \
	UMBActorFunctions(const UMBActorFunctions&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMBActorFunctions); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMBActorFunctions); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMBActorFunctions) \
	NO_API virtual ~UMBActorFunctions();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h_12_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h_15_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMBActorFunctions;

// ********** End Class UMBActorFunctions **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBActorFunctions_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
