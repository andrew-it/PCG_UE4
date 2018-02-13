// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "MyActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyActor() {}
// Cross Module References
	PMC_TEST_API UClass* Z_Construct_UClass_AMyActor_NoRegister();
	PMC_TEST_API UClass* Z_Construct_UClass_AMyActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_PMC_Test();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
// End Cross Module References
	void AMyActor::StaticRegisterNativesAMyActor()
	{
	}
	UClass* Z_Construct_UClass_AMyActor_NoRegister()
	{
		return AMyActor::StaticClass();
	}
	UClass* Z_Construct_UClass_AMyActor()
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
				{ "IncludePath", "MyActor.h" },
				{ "ModuleRelativePath", "MyActor.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mesh_MetaData[] = {
				{ "Category", "Materials" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "MyActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mesh = { UE4CodeGen_Private::EPropertyClass::Object, "mesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a0009, 1, nullptr, STRUCT_OFFSET(AMyActor, mesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(NewProp_mesh_MetaData, ARRAY_COUNT(NewProp_mesh_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_mesh,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AMyActor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AMyActor::StaticClass,
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
	IMPLEMENT_CLASS(AMyActor, 3816307013);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyActor(Z_Construct_UClass_AMyActor, &AMyActor::StaticClass, TEXT("/Script/PMC_Test"), TEXT("AMyActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
