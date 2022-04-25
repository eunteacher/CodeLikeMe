// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE4_Cpp_MultiPlayer/Characters/CAnimInstance.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAnimInstance() {}
// Cross Module References
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_UCAnimInstance_NoRegister();
	UE4_CPP_MULTIPLAYER_API UClass* Z_Construct_UClass_UCAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_UE4_Cpp_MultiPlayer();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
// End Cross Module References
	void UCAnimInstance::StaticRegisterNativesUCAnimInstance()
	{
	}
	UClass* Z_Construct_UClass_UCAnimInstance_NoRegister()
	{
		return UCAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UCAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Speed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsAir_MetaData[];
#endif
		static void NewProp_IsAir_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsAir;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsMoving_MetaData[];
#endif
		static void NewProp_IsMoving_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsMoving;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Direction;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnableJump_MetaData[];
#endif
		static void NewProp_EnableJump_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EnableJump;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Jumping_MetaData[];
#endif
		static void NewProp_Jumping_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Jumping;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Crouching_MetaData[];
#endif
		static void NewProp_Crouching_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Crouching;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ControlRotation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ControlRotation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_UE4_Cpp_MultiPlayer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "Characters/CAnimInstance.h" },
		{ "ModuleRelativePath", "Characters/CAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Speed_MetaData[] = {
		{ "Category", "CAnimInstance" },
		{ "ModuleRelativePath", "Characters/CAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCAnimInstance, Speed), METADATA_PARAMS(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Speed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsAir_MetaData[] = {
		{ "Category", "CAnimInstance" },
		{ "ModuleRelativePath", "Characters/CAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsAir_SetBit(void* Obj)
	{
		((UCAnimInstance*)Obj)->IsAir = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsAir = { "IsAir", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCAnimInstance), &Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsAir_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsAir_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsAir_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsMoving_MetaData[] = {
		{ "Category", "CAnimInstance" },
		{ "ModuleRelativePath", "Characters/CAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsMoving_SetBit(void* Obj)
	{
		((UCAnimInstance*)Obj)->IsMoving = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsMoving = { "IsMoving", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCAnimInstance), &Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsMoving_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsMoving_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsMoving_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Direction_MetaData[] = {
		{ "Category", "CAnimInstance" },
		{ "ModuleRelativePath", "Characters/CAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCAnimInstance, Direction), METADATA_PARAMS(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Direction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Direction_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimInstance_Statics::NewProp_EnableJump_MetaData[] = {
		{ "Category", "CAnimInstance" },
		{ "ModuleRelativePath", "Characters/CAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UCAnimInstance_Statics::NewProp_EnableJump_SetBit(void* Obj)
	{
		((UCAnimInstance*)Obj)->EnableJump = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCAnimInstance_Statics::NewProp_EnableJump = { "EnableJump", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCAnimInstance), &Z_Construct_UClass_UCAnimInstance_Statics::NewProp_EnableJump_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_EnableJump_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_EnableJump_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Jumping_MetaData[] = {
		{ "Category", "CAnimInstance" },
		{ "ModuleRelativePath", "Characters/CAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Jumping_SetBit(void* Obj)
	{
		((UCAnimInstance*)Obj)->Jumping = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Jumping = { "Jumping", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCAnimInstance), &Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Jumping_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Jumping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Jumping_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Crouching_MetaData[] = {
		{ "Category", "CAnimInstance" },
		{ "ModuleRelativePath", "Characters/CAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Crouching_SetBit(void* Obj)
	{
		((UCAnimInstance*)Obj)->Crouching = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Crouching = { "Crouching", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCAnimInstance), &Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Crouching_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Crouching_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Crouching_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCAnimInstance_Statics::NewProp_ControlRotation_MetaData[] = {
		{ "Category", "CAnimInstance" },
		{ "ModuleRelativePath", "Characters/CAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCAnimInstance_Statics::NewProp_ControlRotation = { "ControlRotation", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCAnimInstance, ControlRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_ControlRotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCAnimInstance_Statics::NewProp_ControlRotation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCAnimInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Speed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsAir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAnimInstance_Statics::NewProp_IsMoving,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Direction,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAnimInstance_Statics::NewProp_EnableJump,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Jumping,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAnimInstance_Statics::NewProp_Crouching,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAnimInstance_Statics::NewProp_ControlRotation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCAnimInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCAnimInstance_Statics::ClassParams = {
		&UCAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UCAnimInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCAnimInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCAnimInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCAnimInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCAnimInstance, 3483622110);
	template<> UE4_CPP_MULTIPLAYER_API UClass* StaticClass<UCAnimInstance>()
	{
		return UCAnimInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCAnimInstance(Z_Construct_UClass_UCAnimInstance, &UCAnimInstance::StaticClass, TEXT("/Script/UE4_Cpp_MultiPlayer"), TEXT("UCAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
