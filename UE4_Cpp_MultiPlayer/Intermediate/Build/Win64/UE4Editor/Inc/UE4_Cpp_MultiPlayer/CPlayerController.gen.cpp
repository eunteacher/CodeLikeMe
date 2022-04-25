// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE4_Cpp_MultiPlayer/Characters/CPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPlayerController() {}
// Cross Module References
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_ACPlayerController_NoRegister();
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_ACPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_UE4_Cpp_MultiPlayer();
// End Cross Module References
	void ACPlayerController::StaticRegisterNativesACPlayerController()
	{
	}
	UClass* Z_Construct_UClass_ACPlayerController_NoRegister()
	{
		return ACPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ACPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_UE4_Cpp_MultiPlayer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Characters/CPlayerController.h" },
		{ "ModuleRelativePath", "Characters/CPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACPlayerController_Statics::ClassParams = {
		&ACPlayerController::StaticClass,
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
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACPlayerController, 768910723);
	template<> UE4_CPP_MULTIPLAYER_API UClass* StaticClass<ACPlayerController>()
	{
		return ACPlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACPlayerController(Z_Construct_UClass_ACPlayerController, &ACPlayerController::StaticClass, TEXT("/Script/UE4_Cpp_MultiPlayer"), TEXT("ACPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
