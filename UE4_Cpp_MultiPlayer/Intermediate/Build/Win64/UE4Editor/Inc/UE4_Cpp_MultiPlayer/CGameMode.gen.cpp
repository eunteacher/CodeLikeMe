// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE4_Cpp_MultiPlayer/CGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCGameMode() {}
// Cross Module References
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_ACGameMode_NoRegister();
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_ACGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_UE4_Cpp_MultiPlayer();
// End Cross Module References
	void ACGameMode::StaticRegisterNativesACGameMode()
	{
	}
	UClass* Z_Construct_UClass_ACGameMode_NoRegister()
	{
		return ACGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UE4_Cpp_MultiPlayer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "CGameMode.h" },
		{ "ModuleRelativePath", "CGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACGameMode_Statics::ClassParams = {
		&ACGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ACGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACGameMode, 3286516933);
	template<> UE4_CPP_MULTIPLAYER_API UClass* StaticClass<ACGameMode>()
	{
		return ACGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACGameMode(Z_Construct_UClass_ACGameMode, &ACGameMode::StaticClass, TEXT("/Script/UE4_Cpp_MultiPlayer"), TEXT("ACGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
