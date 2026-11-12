// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Building/MBBuildingManager.h"

#ifdef MODULARBUILDING_MBBuildingManager_generated_h
#error "MBBuildingManager.generated.h already included, missing '#pragma once' in MBBuildingManager.h"
#endif
#define MODULARBUILDING_MBBuildingManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FMultiPlacementData ***********************************************
struct Z_Construct_UScriptStruct_FMultiPlacementData_Statics;
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FMultiPlacementData(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h_29_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FMultiPlacementData_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FMultiPlacementData(ETypeConstructPhase::Inner); }


struct FMultiPlacementData;
// ********** End ScriptStruct FMultiPlacementData *************************************************

// ********** Begin Class UMBBuildingManager *******************************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h_47_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnPlacementTypeChanged);


struct Z_Construct_UClass_UMBBuildingManager_Statics;
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBBuildingManager(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h_47_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UMBBuildingManager_Statics; \
	friend MODULARBUILDING_API UClass* ::Z_Construct_UClass_UMBBuildingManager(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UMBBuildingManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModularBuilding"), Z_Construct_UClass_UMBBuildingManager) \
	DECLARE_SERIALIZER(UMBBuildingManager) \
	[[deprecated("Do not call _getUObject(), use Cast.")]] virtual UObject* _getUObject() const override { return const_cast<UMBBuildingManager*>(this); }


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h_47_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMBBuildingManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMBBuildingManager(UMBBuildingManager&&) = delete; \
	UMBBuildingManager(const UMBBuildingManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMBBuildingManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMBBuildingManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMBBuildingManager) \
	NO_API virtual ~UMBBuildingManager();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h_44_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h_47_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h_47_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h_47_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h_47_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMBBuildingManager;

// ********** End Class UMBBuildingManager *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
