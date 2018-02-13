// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ProceduralWallTest.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProceduralWallTest() {}
// Cross Module References
	PMC_TEST_API UClass* Z_Construct_UClass_AProceduralWallTest_NoRegister();
	PMC_TEST_API UClass* Z_Construct_UClass_AProceduralWallTest();
	PMC_TEST_API UClass* Z_Construct_UClass_AProceduralBlockBase2D();
	UPackage* Z_Construct_UPackage__Script_PMC_Test();
// End Cross Module References
	void AProceduralWallTest::StaticRegisterNativesAProceduralWallTest()
	{
	}
	UClass* Z_Construct_UClass_AProceduralWallTest_NoRegister()
	{
		return AProceduralWallTest::StaticClass();
	}
	UClass* Z_Construct_UClass_AProceduralWallTest()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AProceduralBlockBase2D,
				(UObject* (*)())Z_Construct_UPackage__Script_PMC_Test,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "ProceduralWallTest.h" },
				{ "ModuleRelativePath", "ProceduralWallTest.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cut_wall_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralWallTest.h" },
				{ "ToolTip", "Cut the wall" },
			};
#endif
			auto NewProp_cut_wall_SetBit = [](void* Obj){ ((AProceduralWallTest*)Obj)->cut_wall = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_cut_wall = { UE4CodeGen_Private::EPropertyClass::Bool, "cut_wall", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AProceduralWallTest), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_cut_wall_SetBit)>::SetBit, METADATA_PARAMS(NewProp_cut_wall_MetaData, ARRAY_COUNT(NewProp_cut_wall_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_odd_offset_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralWallTest.h" },
				{ "ToolTip", "Offset of odd rows of bricks" },
			};
#endif
			auto NewProp_odd_offset_SetBit = [](void* Obj){ ((AProceduralWallTest*)Obj)->odd_offset = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_odd_offset = { UE4CodeGen_Private::EPropertyClass::Bool, "odd_offset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AProceduralWallTest), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_odd_offset_SetBit)>::SetBit, METADATA_PARAMS(NewProp_odd_offset_MetaData, ARRAY_COUNT(NewProp_odd_offset_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_offset_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralWallTest.h" },
				{ "ToolTip", "Offset of bricks" },
			};
#endif
			auto NewProp_offset_SetBit = [](void* Obj){ ((AProceduralWallTest*)Obj)->offset = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_offset = { UE4CodeGen_Private::EPropertyClass::Bool, "offset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AProceduralWallTest), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_offset_SetBit)>::SetBit, METADATA_PARAMS(NewProp_offset_MetaData, ARRAY_COUNT(NewProp_offset_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_holes_number_MetaData[] = {
				{ "Category", "Config" },
				{ "ModuleRelativePath", "ProceduralWallTest.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_holes_number = { UE4CodeGen_Private::EPropertyClass::Int, "holes_number", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AProceduralWallTest, holes_number), METADATA_PARAMS(NewProp_holes_number_MetaData, ARRAY_COUNT(NewProp_holes_number_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_cut_wall,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_odd_offset,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_offset,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_holes_number,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AProceduralWallTest>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AProceduralWallTest::StaticClass,
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
	IMPLEMENT_CLASS(AProceduralWallTest, 2283373606);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProceduralWallTest(Z_Construct_UClass_AProceduralWallTest, &AProceduralWallTest::StaticClass, TEXT("/Script/PMC_Test"), TEXT("AProceduralWallTest"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProceduralWallTest);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
