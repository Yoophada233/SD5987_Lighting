// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Slate/MBAssetBorder.h"

#ifdef MODULARBUILDING_MBAssetBorder_generated_h
#error "MBAssetBorder.generated.h already included, missing '#pragma once' in MBAssetBorder.h"
#endif
#define MODULARBUILDING_MBAssetBorder_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMaterialInstanceDynamic;
class UMaterialInterface;
class USlateBrushAsset;
class UTexture2D;
struct FLinearColor;
struct FMargin;
struct FSlateBrush;

// ********** Begin Class UMBAssetBorder ***********************************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h_32_RPC_WRAPPERS \
	DECLARE_FUNCTION(execSetDesiredSizeScale); \
	DECLARE_FUNCTION(execGetDynamicMaterial); \
	DECLARE_FUNCTION(execSetBrushFromMaterial); \
	DECLARE_FUNCTION(execSetBrushFromTexture); \
	DECLARE_FUNCTION(execSetBrushFromAsset); \
	DECLARE_FUNCTION(execSetBrush); \
	DECLARE_FUNCTION(execSetBrushColor); \
	DECLARE_FUNCTION(execSetVerticalAlignment); \
	DECLARE_FUNCTION(execSetHorizontalAlignment); \
	DECLARE_FUNCTION(execSetPadding); \
	DECLARE_FUNCTION(execSetContentColorAndOpacity);


struct Z_Construct_UClass_UMBAssetBorder_Statics;
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBAssetBorder(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h_32_INCLASS \
private: \
	friend struct ::Z_Construct_UClass_UMBAssetBorder_Statics; \
	friend MODULARBUILDING_API UClass* ::Z_Construct_UClass_UMBAssetBorder(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UMBAssetBorder, UContentWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModularBuilding"), Z_Construct_UClass_UMBAssetBorder) \
	DECLARE_SERIALIZER(UMBAssetBorder)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMBAssetBorder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMBAssetBorder) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMBAssetBorder); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMBAssetBorder); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMBAssetBorder(UMBAssetBorder&&) = delete; \
	UMBAssetBorder(const UMBAssetBorder&) = delete; \
	NO_API virtual ~UMBAssetBorder();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h_29_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h_32_RPC_WRAPPERS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h_32_INCLASS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMBAssetBorder;

// ********** End Class UMBAssetBorder *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Slate_MBAssetBorder_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
