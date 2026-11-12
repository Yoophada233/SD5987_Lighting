// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MBBuildingManager.h"
#include "MBDataStructs.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeMBBuildingManager() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UInstancedStaticMeshComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FDuplicationData(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FDuplicationFilters(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EBuildingCategory(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EMBAxis(ETypeConstructPhase);
MODULARBUILDING_API UEnum* Z_Construct_UEnum_ModularBuilding_EPlacementStatus(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBBuildingManager(ETypeConstructPhase);
MODULARBUILDING_API UScriptStruct* Z_Construct_UScriptStruct_FMultiPlacementData(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBBuildingManager(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_IMBBuildingManagerInterface(ETypeConstructPhase);
MODULARBUILDING_API UClass* Z_Construct_UClass_UMBToolSubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FMultiPlacementData ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FMultiPlacementData_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FMultiPlacementData>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FMultiPlacementData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Axis_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HalfLength_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnCount_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FMultiPlacementData constinit property declarations ***************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Axis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Axis;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HalfLength;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SpawnCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FMultiPlacementData constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMultiPlacementData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FMultiPlacementData Property Definitions **************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Axis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Axis = { "Axis", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FMultiPlacementData, Axis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Axis_MetaData), NewProp_Axis_MetaData) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HalfLength = { "HalfLength", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FMultiPlacementData, HalfLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HalfLength_MetaData), NewProp_HalfLength_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SpawnCount = { "SpawnCount", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FMultiPlacementData, SpawnCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnCount_MetaData), NewProp_SpawnCount_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FMultiPlacementData, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Direction_MetaData), NewProp_Direction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Axis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Axis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HalfLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Direction,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FMultiPlacementData Property Definitions ****************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
	nullptr,
	&NewStructOps,
	"MultiPlacementData",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FMultiPlacementData>(),
	alignof(FMultiPlacementData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMultiPlacementData;
UScriptStruct* Z_Construct_UScriptStruct_FMultiPlacementData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FMultiPlacementData.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FMultiPlacementData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMultiPlacementData, (UObject*)Z_Construct_UPackage__Script_ModularBuilding(ETypeConstructPhase::Outer), TEXT("MultiPlacementData"));
		}
		return Z_Registration_Info_UScriptStruct_FMultiPlacementData.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FMultiPlacementData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMultiPlacementData.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FMultiPlacementData.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FMultiPlacementData *************************************************

// ********** Begin Class UMBBuildingManager Function OnPlacementTypeChanged ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UMBBuildingManager_OnPlacementTypeChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnPlacementTypeChanged constinit property declarations ****************
// ********** End Function OnPlacementTypeChanged constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UMBBuildingManager, nullptr, "OnPlacementTypeChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UMBBuildingManager_OnPlacementTypeChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UMBBuildingManager::execOnPlacementTypeChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPlacementTypeChanged();
	P_NATIVE_END;
}
// ********** End Class UMBBuildingManager Function OnPlacementTypeChanged *************************

// ********** Begin Class UMBBuildingManager *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UMBBuildingManager_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Building/MBBuildingManager.h" },
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolSettings_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovedActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitCategory_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetLocation_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetRotation_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropTargetRotation_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlacementStatus_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockedAxis_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockedAxisValue_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CancelledWorldAxis_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CancelledValue_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlacementDynamicMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlacementDynamicMaterialForNanite_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedDupActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Placeholders_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DuplicatedFreePool_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XDupData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YDupData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZDupData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DuplicationFilters_MetaData[] = {
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MultiPlacementBaseComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Building/MBBuildingManager.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMBBuildingManager constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToolSettings;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MovedActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedActor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_HitCategory_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_HitCategory;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PropTargetRotation;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PlacementStatus_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PlacementStatus;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LockedAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LockedAxis;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LockedAxisValue;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CancelledWorldAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CancelledWorldAxis;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CancelledValue;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlacementDynamicMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlacementDynamicMaterialForNanite;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedDupActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Placeholders_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Placeholders;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DuplicatedFreePool_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DuplicatedFreePool;
	static const UECodeGen_Private::FStructPropertyParams NewProp_XDupData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_YDupData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ZDupData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DuplicationFilters;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MultiPlacementBaseComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMBBuildingManager constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnPlacementTypeChanged"), .Pointer = &UMBBuildingManager::execOnPlacementTypeChanged },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMBBuildingManager_OnPlacementTypeChanged, "OnPlacementTypeChanged" }, // 2c0fdb05b340d1a25aae6f3b74cea900efac1565
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMBBuildingManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UMBBuildingManager Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ToolSettings = { "ToolSettings", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, ToolSettings), Z_Construct_UClass_UMBToolSubsystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolSettings_MetaData), NewProp_ToolSettings_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MovedActor = { "MovedActor", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, MovedActor), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovedActor_MetaData), NewProp_MovedActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HitActor = { "HitActor", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, HitActor), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitActor_MetaData), NewProp_HitActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_OverlappedActor = { "OverlappedActor", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, OverlappedActor), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedActor_MetaData), NewProp_OverlappedActor_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_HitCategory_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_HitCategory = { "HitCategory", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, HitCategory), Z_Construct_UEnum_ModularBuilding_EBuildingCategory, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitCategory_MetaData), NewProp_HitCategory_MetaData) }; // 07cf8117a6e577cac6ce1c747d6b11cc85196fdc
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetLocation_MetaData), NewProp_TargetLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_TargetRotation = { "TargetRotation", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, TargetRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetRotation_MetaData), NewProp_TargetRotation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PropTargetRotation = { "PropTargetRotation", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, PropTargetRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropTargetRotation_MetaData), NewProp_PropTargetRotation_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_PlacementStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_PlacementStatus = { "PlacementStatus", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, PlacementStatus), Z_Construct_UEnum_ModularBuilding_EPlacementStatus, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlacementStatus_MetaData), NewProp_PlacementStatus_MetaData) }; // 323ec8441a74bb7572fcbb1a0466b3bfe2bc275d
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_LockedAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_LockedAxis = { "LockedAxis", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, LockedAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockedAxis_MetaData), NewProp_LockedAxis_MetaData) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LockedAxisValue = { "LockedAxisValue", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, LockedAxisValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockedAxisValue_MetaData), NewProp_LockedAxisValue_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CancelledWorldAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_CancelledWorldAxis = { "CancelledWorldAxis", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, CancelledWorldAxis), Z_Construct_UEnum_ModularBuilding_EMBAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CancelledWorldAxis_MetaData), NewProp_CancelledWorldAxis_MetaData) }; // 974235c7f535db90615054a2f46a7fbc26776297
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CancelledValue = { "CancelledValue", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, CancelledValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CancelledValue_MetaData), NewProp_CancelledValue_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlacementDynamicMaterial = { "PlacementDynamicMaterial", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, PlacementDynamicMaterial), Z_Construct_UClass_UMaterialInstanceDynamic, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlacementDynamicMaterial_MetaData), NewProp_PlacementDynamicMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlacementDynamicMaterialForNanite = { "PlacementDynamicMaterialForNanite", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, PlacementDynamicMaterialForNanite), Z_Construct_UClass_UMaterialInstanceDynamic, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlacementDynamicMaterialForNanite_MetaData), NewProp_PlacementDynamicMaterialForNanite_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedDupActor = { "SelectedDupActor", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, SelectedDupActor), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedDupActor_MetaData), NewProp_SelectedDupActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Placeholders_Inner = { "Placeholders", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Placeholders = { "Placeholders", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, Placeholders), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Placeholders_MetaData), NewProp_Placeholders_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DuplicatedFreePool_Inner = { "DuplicatedFreePool", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_DuplicatedFreePool = { "DuplicatedFreePool", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, DuplicatedFreePool), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DuplicatedFreePool_MetaData), NewProp_DuplicatedFreePool_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_XDupData = { "XDupData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, XDupData), Z_Construct_UScriptStruct_FDuplicationData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XDupData_MetaData), NewProp_XDupData_MetaData) }; // 62603a81de64ad7f08375f6aaa5834b14e33f1e6
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_YDupData = { "YDupData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, YDupData), Z_Construct_UScriptStruct_FDuplicationData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YDupData_MetaData), NewProp_YDupData_MetaData) }; // 62603a81de64ad7f08375f6aaa5834b14e33f1e6
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ZDupData = { "ZDupData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, ZDupData), Z_Construct_UScriptStruct_FDuplicationData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZDupData_MetaData), NewProp_ZDupData_MetaData) }; // 62603a81de64ad7f08375f6aaa5834b14e33f1e6
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DuplicationFilters = { "DuplicationFilters", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, DuplicationFilters), Z_Construct_UScriptStruct_FDuplicationFilters, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DuplicationFilters_MetaData), NewProp_DuplicationFilters_MetaData) }; // 27c40ea3047e349dd8e589d1afd1c0d727fa8df7
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MultiPlacementBaseComponent = { "MultiPlacementBaseComponent", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UMBBuildingManager, MultiPlacementBaseComponent), Z_Construct_UClass_UInstancedStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MultiPlacementBaseComponent_MetaData), NewProp_MultiPlacementBaseComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ToolSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MovedActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HitActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OverlappedActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HitCategory_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HitCategory,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PropTargetRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlacementStatus_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlacementStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LockedAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LockedAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LockedAxisValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CancelledWorldAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CancelledWorldAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CancelledValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlacementDynamicMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlacementDynamicMaterialForNanite,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedDupActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Placeholders_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Placeholders,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DuplicatedFreePool_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DuplicatedFreePool,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_XDupData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_YDupData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ZDupData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DuplicationFilters,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MultiPlacementBaseComponent,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UMBBuildingManager Property Definitions ************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UObject,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModularBuilding,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams UHT_STATICS::InterfaceParams[] = {
	{ Z_Construct_UClass_UMBBuildingManagerInterface, (int32)VTABLE_OFFSET(UMBBuildingManager, IMBBuildingManagerInterface), false },  // ccccda46fad6df4dcb220d407179c3bc6c2d4b56
};
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UMBBuildingManager,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UMBBuildingManager_StaticRegisterNativesUMBBuildingManager()
{
	UClass* Class = UMBBuildingManager::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMBBuildingManager;
UClass* Z_Construct_UClass_UMBBuildingManager(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UMBBuildingManager;
		if (!Z_Registration_Info_UClass_UMBBuildingManager.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("MBBuildingManager"),
				Z_Registration_Info_UClass_UMBBuildingManager.InnerSingleton,
				UMBBuildingManager_StaticRegisterNativesUMBBuildingManager,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_UMBBuildingManager.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UMBBuildingManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMBBuildingManager.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UMBBuildingManager.OuterSingleton;
}
#undef UHT_STATICS
UMBBuildingManager::UMBBuildingManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMBBuildingManager);
UMBBuildingManager::~UMBBuildingManager() {}
// ********** End Class UMBBuildingManager *********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h__Script_ModularBuilding_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FMultiPlacementData, Z_Construct_UScriptStruct_FMultiPlacementData_Statics::NewStructOps, TEXT("MultiPlacementData"),&Z_Registration_Info_UScriptStruct_FMultiPlacementData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMultiPlacementData), 1010867468U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMBBuildingManager, TEXT("UMBBuildingManager"), &Z_Registration_Info_UClass_UMBBuildingManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMBBuildingManager), 3535302280U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UltimateLevelArtTool_Source_ModularBuilding_Public_Building_MBBuildingManager_h__Script_ModularBuilding_f955ef867f5e24b128e9f315ecedbb213b3ad5e6{
	TEXT("/Script/ModularBuilding"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
