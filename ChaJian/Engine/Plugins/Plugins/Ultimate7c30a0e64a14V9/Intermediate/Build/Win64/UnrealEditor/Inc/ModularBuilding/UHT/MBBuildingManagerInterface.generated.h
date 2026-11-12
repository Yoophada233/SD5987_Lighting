// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/MBBuildingManagerInterface.h"

#ifdef MODULARBUILDING_MBBuildingManagerInterface_generated_h
#error "MBBuildingManagerInterface.generated.h already included, missing '#pragma once' in MBBuildingManagerInterface.h"
#endif
#define MODULARBUILDING_MBBuildingManagerInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Interface UMBBuildingManagerInterface ******************************************
struct Z_Construct_UClass_UMBBuildingManagerInterface_Statics;
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBBuildingManagerInterface(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Interfaces_MBBuildingManagerInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODULARBUILDING_API UMBBuildingManagerInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMBBuildingManagerInterface(UMBBuildingManagerInterface&&) = delete; \
	UMBBuildingManagerInterface(const UMBBuildingManagerInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODULARBUILDING_API, UMBBuildingManagerInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMBBuildingManagerInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMBBuildingManagerInterface) \
	virtual ~UMBBuildingManagerInterface() = default;


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Interfaces_MBBuildingManagerInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	friend struct ::Z_Construct_UClass_UMBBuildingManagerInterface_Statics; \
	friend MODULARBUILDING_API UClass* ::Z_Construct_UClass_UMBBuildingManagerInterface(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UMBBuildingManagerInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/ModularBuilding"), Z_Construct_UClass_UMBBuildingManagerInterface) \
	DECLARE_SERIALIZER(UMBBuildingManagerInterface)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Interfaces_MBBuildingManagerInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Interfaces_MBBuildingManagerInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Interfaces_MBBuildingManagerInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Interfaces_MBBuildingManagerInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IMBBuildingManagerInterface() {} \
public: \
	typedef UMBBuildingManagerInterface UClassType; \
	typedef IMBBuildingManagerInterface ThisClass; \
	[[deprecated("Do not call _getUObject(), use Cast.")]] virtual UObject* _getUObject() const { return nullptr; }


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Interfaces_MBBuildingManagerInterface_h_11_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Interfaces_MBBuildingManagerInterface_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Interfaces_MBBuildingManagerInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMBBuildingManagerInterface;

// ********** End Interface UMBBuildingManagerInterface ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Interfaces_MBBuildingManagerInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
