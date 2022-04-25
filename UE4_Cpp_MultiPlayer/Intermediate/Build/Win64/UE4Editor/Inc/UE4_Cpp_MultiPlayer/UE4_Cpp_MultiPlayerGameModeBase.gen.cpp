// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE4_Cpp_MultiPlayer/UE4_Cpp_MultiPlayerGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUE4_Cpp_MultiPlayerGameModeBase() {}
// Cross Module References
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase_NoRegister();
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_UE4_Cpp_MultiPlayer();
// End Cross Module References
	void AUE4_Cpp_MultiPlayerGameModeBase::StaticRegisterNativesAUE4_Cpp_MultiPlayerGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase_NoRegister()
	{
		return AUE4_Cpp_MultiPlayerGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UE4_Cpp_MultiPlayer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "UE4_Cpp_MultiPlayerGameModeBase.h" },
		{ "ModuleRelativePath", "UE4_Cpp_MultiPlayerGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUE4_Cpp_MultiPlayerGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase_Statics::ClassParams = {
		&AUE4_Cpp_MultiPlayerGameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AUE4_Cpp_MultiPlayerGameModeBase, 1327257958);
	template<> UE4_CPP_MULTIPLAYER_API UClass* StaticClass<AUE4_Cpp_MultiPlayerGameModeBase>()
	{
		return AUE4_Cpp_MultiPlayerGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUE4_Cpp_MultiPlayerGameModeBase(Z_Construct_UClass_AUE4_Cpp_MultiPlayerGameModeBase, &AUE4_Cpp_MultiPlayerGameModeBase::StaticClass, TEXT("/Script/UE4_Cpp_MultiPlayer"), TEXT("AUE4_Cpp_MultiPlayerGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUE4_Cpp_MultiPlayerGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
