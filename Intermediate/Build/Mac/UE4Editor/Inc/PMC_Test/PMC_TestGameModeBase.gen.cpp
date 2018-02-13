// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "PMC_TestGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePMC_TestGameModeBase() {}
// Cross Module References
	PMC_TEST_API UClass* Z_Construct_UClass_APMC_TestGameModeBase_NoRegister();
	PMC_TEST_API UClass* Z_Construct_UClass_APMC_TestGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_PMC_Test();
// End Cross Module References
	void APMC_TestGameModeBase::StaticRegisterNativesAPMC_TestGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_APMC_TestGameModeBase_NoRegister()
	{
		return APMC_TestGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_APMC_TestGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_PMC_Test,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "PMC_TestGameModeBase.h" },
				{ "ModuleRelativePath", "PMC_TestGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<APMC_TestGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&APMC_TestGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APMC_TestGameModeBase, 1655367114);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APMC_TestGameModeBase(Z_Construct_UClass_APMC_TestGameModeBase, &APMC_TestGameModeBase::StaticClass, TEXT("/Script/PMC_Test"), TEXT("APMC_TestGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APMC_TestGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
