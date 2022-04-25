// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE4_Cpp_MultiPlayer/Characters/CPlayableCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPlayableCharacter() {}
// Cross Module References
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_ACPlayableCharacter_NoRegister();
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_ACPlayableCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_UE4_Cpp_MultiPlayer();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_UICharacter_NoRegister();
// End Cross Module References
	void ACPlayableCharacter::StaticRegisterNativesACPlayableCharacter()
	{
	}
	UClass* Z_Construct_UClass_ACPlayableCharacter_NoRegister()
	{
		return ACPlayableCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ACPlayableCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FPMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FPMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HorizontalControlRotation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HorizontalControlRotation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPlayableCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_UE4_Cpp_MultiPlayer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPlayableCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/CPlayableCharacter.h" },
		{ "ModuleRelativePath", "Characters/CPlayableCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_Camera_MetaData[] = {
		{ "Category", "CPlayableCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Characters/CPlayableCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACPlayableCharacter, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_Camera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_Camera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_FPMesh_MetaData[] = {
		{ "Category", "CPlayableCharacter" },
		{ "Comment", "// \xc4\xab?\xde\xb6?\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Characters/CPlayableCharacter.h" },
		{ "ToolTip", "\xc4\xab?\xde\xb6?" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_FPMesh = { "FPMesh", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACPlayableCharacter, FPMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_FPMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_FPMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_HorizontalControlRotation_MetaData[] = {
		{ "Category", "CPlayableCharacter" },
		{ "ModuleRelativePath", "Characters/CPlayableCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_HorizontalControlRotation = { "HorizontalControlRotation", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACPlayableCharacter, HorizontalControlRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_HorizontalControlRotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_HorizontalControlRotation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPlayableCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_Camera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_FPMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayableCharacter_Statics::NewProp_HorizontalControlRotation,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ACPlayableCharacter_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UICharacter_NoRegister, (int32)VTABLE_OFFSET(ACPlayableCharacter, IICharacter), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPlayableCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPlayableCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACPlayableCharacter_Statics::ClassParams = {
		&ACPlayableCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACPlayableCharacter_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACPlayableCharacter_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACPlayableCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACPlayableCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACPlayableCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACPlayableCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACPlayableCharacter, 3843210806);
	template<> UE4_CPP_MULTIPLAYER_API UClass* StaticClass<ACPlayableCharacter>()
	{
		return ACPlayableCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACPlayableCharacter(Z_Construct_UClass_ACPlayableCharacter, &ACPlayableCharacter::StaticClass, TEXT("/Script/UE4_Cpp_MultiPlayer"), TEXT("ACPlayableCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPlayableCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
