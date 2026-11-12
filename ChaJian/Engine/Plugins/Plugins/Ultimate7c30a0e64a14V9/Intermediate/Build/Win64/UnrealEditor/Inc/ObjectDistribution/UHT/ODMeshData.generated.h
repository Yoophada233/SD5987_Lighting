// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Data/ODMeshData.h"

#ifdef OBJECTDISTRIBUTION_ODMeshData_generated_h
#error "ODMeshData.generated.h already included, missing '#pragma once' in ODMeshData.h"
#endif
#define OBJECTDISTRIBUTION_ODMeshData_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FDistObjectPropertyData *******************************************
struct Z_Construct_UScriptStruct_FDistObjectPropertyData_Statics;
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FDistObjectPropertyData(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODMeshData_h_64_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDistObjectPropertyData_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FDistObjectPropertyData(ETypeConstructPhase::Inner); }


struct FDistObjectPropertyData;
// ********** End ScriptStruct FDistObjectPropertyData *********************************************

// ********** Begin ScriptStruct FDistObjectData ***************************************************
struct Z_Construct_UScriptStruct_FDistObjectData_Statics;
OBJECTDISTRIBUTION_API UScriptStruct* Z_Construct_UScriptStruct_FDistObjectData(ETypeConstructPhase);

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODMeshData_h_103_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDistObjectData_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FDistObjectData(ETypeConstructPhase::Inner); }


struct FDistObjectData;
// ********** End ScriptStruct FDistObjectData *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ObjectDistribution_Public_Data_ODMeshData_h

// ********** Begin Enum EObjectDistributionType ***************************************************
#define FOREACH_ENUM_EOBJECTDISTRIBUTIONTYPE(op) \
	op(EObjectDistributionType::Cube) \
	op(EObjectDistributionType::Ring) \
	op(EObjectDistributionType::Disk) \
	op(EObjectDistributionType::Sphere) \
	op(EObjectDistributionType::Spiral) \
	op(EObjectDistributionType::Line) \
	op(EObjectDistributionType::Plane) \
	op(EObjectDistributionType::Grid) 

enum class EObjectDistributionType : uint8;
template<> struct TIsUEnumClass<EObjectDistributionType> { enum { Value = true }; };
template<> UE_NODEBUG OBJECTDISTRIBUTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EObjectDistributionType>();
// ********** End Enum EObjectDistributionType *****************************************************

// ********** Begin Enum EObjectOrientation ********************************************************
#define FOREACH_ENUM_EOBJECTORIENTATION(op) \
	op(EObjectOrientation::Keep) \
	op(EObjectOrientation::Inside) \
	op(EObjectOrientation::Outside) \
	op(EObjectOrientation::RandomZ) \
	op(EObjectOrientation::Random) 

enum class EObjectOrientation : uint8;
template<> struct TIsUEnumClass<EObjectOrientation> { enum { Value = true }; };
template<> UE_NODEBUG OBJECTDISTRIBUTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EObjectOrientation>();
// ********** End Enum EObjectOrientation **********************************************************

// ********** Begin Enum EODLineAxis ***************************************************************
#define FOREACH_ENUM_EODLINEAXIS(op) \
	op(EODLineAxis::None) \
	op(EODLineAxis::AxisX) \
	op(EODLineAxis::AxisY) \
	op(EODLineAxis::AxisZ) 

enum class EODLineAxis : uint8;
template<> struct TIsUEnumClass<EODLineAxis> { enum { Value = true }; };
template<> UE_NODEBUG OBJECTDISTRIBUTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EODLineAxis>();
// ********** End Enum EODLineAxis *****************************************************************

// ********** Begin Enum EODDistributionFinishType *************************************************
#define FOREACH_ENUM_EODDISTRIBUTIONFINISHTYPE(op) \
	op(EODDistributionFinishType::Keep) \
	op(EODDistributionFinishType::Batch) \
	op(EODDistributionFinishType::Merge) 

enum class EODDistributionFinishType : uint8;
template<> struct TIsUEnumClass<EODDistributionFinishType> { enum { Value = true }; };
template<> UE_NODEBUG OBJECTDISTRIBUTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EODDistributionFinishType>();
// ********** End Enum EODDistributionFinishType ***************************************************

// ********** Begin Enum EODMeshConversionType *****************************************************
#define FOREACH_ENUM_EODMESHCONVERSIONTYPE(op) \
	op(EODMeshConversionType::Sm) \
	op(EODMeshConversionType::Ism) \
	op(EODMeshConversionType::HIsm) 

enum class EODMeshConversionType : uint8;
template<> struct TIsUEnumClass<EODMeshConversionType> { enum { Value = true }; };
template<> UE_NODEBUG OBJECTDISTRIBUTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EODMeshConversionType>();
// ********** End Enum EODMeshConversionType *******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
