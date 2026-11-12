// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Library/MAFunctions.h"

#ifdef MATERIALASSIGNMENT_MAFunctions_generated_h
#error "MAFunctions.generated.h already included, missing '#pragma once' in MAFunctions.h"
#endif
#define MATERIALASSIGNMENT_MAFunctions_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UStaticMesh;
struct FAssetData;

// ********** Begin Class UMAFunctions *************************************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsMaterialInUsed); \
	DECLARE_FUNCTION(execGetAllMaterialInstances); \
	DECLARE_FUNCTION(execFindTheMostSuitableMaterialForTheNameSlot);


struct Z_Construct_UClass_UMAFunctions_Statics;
MATERIALASSIGNMENT_API UClass* Z_Construct_UClass_UMAFunctions(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h_18_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UMAFunctions_Statics; \
	friend MATERIALASSIGNMENT_API UClass* ::Z_Construct_UClass_UMAFunctions(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UMAFunctions, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MaterialAssignment"), Z_Construct_UClass_UMAFunctions) \
	DECLARE_SERIALIZER(UMAFunctions)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMAFunctions(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMAFunctions(UMAFunctions&&) = delete; \
	UMAFunctions(const UMAFunctions&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMAFunctions); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMAFunctions); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMAFunctions) \
	NO_API virtual ~UMAFunctions();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h_15_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h_18_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMAFunctions;

// ********** End Class UMAFunctions ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_MaterialAssignment_Public_Library_MAFunctions_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
