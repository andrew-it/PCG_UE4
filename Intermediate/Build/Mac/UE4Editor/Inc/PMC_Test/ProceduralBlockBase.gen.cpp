// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ProceduralBlockBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProceduralBlockBase() {}
// Cross Module References
	PMC_TEST_API UClass* Z_Construct_UClass_AProceduralBlockBase_NoRegister();
	PMC_TEST_API UClass* Z_Construct_UClass_AProceduralBlockBase();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_PMC_Test();
	ENGINE_API UClass* Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
	void AProceduralBlockBase::StaticRegisterNativesAProceduralBlockBase()
	{
	}
	UClass* Z_Construct_UClass_AProceduralBlockBase_NoRegister()
	{
		return AProceduralBlockBase::StaticClass();
	}
	UClass* Z_Construct_UClass_AProceduralBlockBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_PMC_Test,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "ProceduralBlockBase.h" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SMComponent_MetaData[] = {
				{ "Category", "Content" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SMComponent = { UE4CodeGen_Private::EPropertyClass::Object, "SMComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x001000000008000d, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, SMComponent), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_SMComponent_MetaData, ARRAY_COUNT(NewProp_SMComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Object, "Material", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, Material), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(NewProp_Material_MetaData, ARRAY_COUNT(NewProp_Material_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
				{ "ToolTip", "Model and Material" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StaticMesh = { UE4CodeGen_Private::EPropertyClass::Object, "StaticMesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, StaticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(NewProp_StaticMesh_MetaData, ARRAY_COUNT(NewProp_StaticMesh_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Frequency_MetaData[] = {
				{ "Category", "Perlin Noise" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Frequency = { UE4CodeGen_Private::EPropertyClass::Float, "Frequency", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, Frequency), METADATA_PARAMS(NewProp_Frequency_MetaData, ARRAY_COUNT(NewProp_Frequency_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Octaves_MetaData[] = {
				{ "Category", "Perlin Noise" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Octaves = { UE4CodeGen_Private::EPropertyClass::Float, "Octaves", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, Octaves), METADATA_PARAMS(NewProp_Octaves_MetaData, ARRAY_COUNT(NewProp_Octaves_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[] = {
				{ "Category", "Perlin Noise" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
				{ "ToolTip", "For Perlin Noise" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Seed = { UE4CodeGen_Private::EPropertyClass::Int, "Seed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, Seed), METADATA_PARAMS(NewProp_Seed_MetaData, ARRAY_COUNT(NewProp_Seed_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BlockHeight_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BlockHeight = { UE4CodeGen_Private::EPropertyClass::Float, "BlockHeight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, BlockHeight), METADATA_PARAMS(NewProp_BlockHeight_MetaData, ARRAY_COUNT(NewProp_BlockHeight_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BlockDepth_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BlockDepth = { UE4CodeGen_Private::EPropertyClass::Float, "BlockDepth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, BlockDepth), METADATA_PARAMS(NewProp_BlockDepth_MetaData, ARRAY_COUNT(NewProp_BlockDepth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BlockWidth_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
				{ "ToolTip", "Blocks sizes (defaults for red brick)" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BlockWidth = { UE4CodeGen_Private::EPropertyClass::Float, "BlockWidth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, BlockWidth), METADATA_PARAMS(NewProp_BlockWidth_MetaData, ARRAY_COUNT(NewProp_BlockWidth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_YSizeBlocks_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_YSizeBlocks = { UE4CodeGen_Private::EPropertyClass::Int, "YSizeBlocks", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, YSizeBlocks), METADATA_PARAMS(NewProp_YSizeBlocks_MetaData, ARRAY_COUNT(NewProp_YSizeBlocks_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_XSizeBlocks_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralBlockBase.h" },
				{ "ToolTip", "Dimensions size" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_XSizeBlocks = { UE4CodeGen_Private::EPropertyClass::Int, "XSizeBlocks", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralBlockBase, XSizeBlocks), METADATA_PARAMS(NewProp_XSizeBlocks_MetaData, ARRAY_COUNT(NewProp_XSizeBlocks_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SMComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Material,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_StaticMesh,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Frequency,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Octaves,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Seed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BlockHeight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BlockDepth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BlockWidth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_YSizeBlocks,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_XSizeBlocks,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AProceduralBlockBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AProceduralBlockBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProceduralBlockBase, 1217262481);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProceduralBlockBase(Z_Construct_UClass_AProceduralBlockBase, &AProceduralBlockBase::StaticClass, TEXT("/Script/PMC_Test"), TEXT("AProceduralBlockBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProceduralBlockBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
