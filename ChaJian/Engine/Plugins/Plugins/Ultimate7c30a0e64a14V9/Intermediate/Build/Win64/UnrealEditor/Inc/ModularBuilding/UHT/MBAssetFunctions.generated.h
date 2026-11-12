// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Libraries/MBAssetFunctions.h"

#ifdef MODULARBUILDING_MBAssetFunctions_generated_h
#error "MBAssetFunctions.generated.h already included, missing '#pragma once' in MBAssetFunctions.h"
#endif
#define MODULARBUILDING_MBAssetFunctions_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UTexture2D;
enum class EMBAssetThumbnailFormant : uint8;
struct FAssetData;

// ********** Begin Class UMBAssetFunctions ********************************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGenerateThumbnailForAsset); \
	DECLARE_FUNCTION(execGetAssetDataFromPath); \
	DECLARE_FUNCTION(execGetAssetPathFromObject); \
	DECLARE_FUNCTION(execGetAssetDataFromObject);


struct Z_Construct_UClass_UMBAssetFunctions_Statics;
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBAssetFunctions(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h_27_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UMBAssetFunctions_Statics; \
	friend MODULARBUILDING_API UClass* ::Z_Construct_UClass_UMBAssetFunctions(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UMBAssetFunctions, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModularBuilding"), Z_Construct_UClass_UMBAssetFunctions) \
	DECLARE_SERIALIZER(UMBAssetFunctions)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h_27_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMBAssetFunctions(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMBAssetFunctions(UMBAssetFunctions&&) = delete; \
	UMBAssetFunctions(const UMBAssetFunctions&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMBAssetFunctions); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMBAssetFunctions); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMBAssetFunctions) \
	NO_API virtual ~UMBAssetFunctions();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h_24_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h_27_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMBAssetFunctions;

// ********** End Class UMBAssetFunctions **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Libraries_MBAssetFunctions_h

// ********** Begin Enum EMBAssetThumbnailFormant **************************************************
#define FOREACH_ENUM_EMBASSETTHUMBNAILFORMANT(op) \
	op(EMBAssetThumbnailFormant::JPEG) \
	op(EMBAssetThumbnailFormant::PNG) 

enum class EMBAssetThumbnailFormant : uint8;
template<> struct TIsUEnumClass<EMBAssetThumbnailFormant> { enum { Value = true }; };
template<> UE_NODEBUG MODULARBUILDING_NON_ATTRIBUTED_API UEnum* StaticEnum<EMBAssetThumbnailFormant>();
// ********** End Enum EMBAssetThumbnailFormant ****************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
