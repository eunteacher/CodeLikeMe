// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UE4_CPP_MULTIPLAYER_ICharacter_generated_h
#error "ICharacter.generated.h already included, missing '#pragma once' in ICharacter.h"
#endif
#define UE4_CPP_MULTIPLAYER_ICharacter_generated_h

#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_SPARSE_DATA
#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_RPC_WRAPPERS
#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_RPC_WRAPPERS_NO_PURE_DECLS
#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	UE4_CPP_MULTIPLAYER_API UICharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UICharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(UE4_CPP_MULTIPLAYER_API, UICharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UICharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UE4_CPP_MULTIPLAYER_API UICharacter(UICharacter&&); \
	UE4_CPP_MULTIPLAYER_API UICharacter(const UICharacter&); \
public:


#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	UE4_CPP_MULTIPLAYER_API UICharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UE4_CPP_MULTIPLAYER_API UICharacter(UICharacter&&); \
	UE4_CPP_MULTIPLAYER_API UICharacter(const UICharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(UE4_CPP_MULTIPLAYER_API, UICharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UICharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UICharacter)


#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUICharacter(); \
	friend struct Z_Construct_UClass_UICharacter_Statics; \
public: \
	DECLARE_CLASS(UICharacter, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/UE4_Cpp_MultiPlayer"), UE4_CPP_MULTIPLAYER_API) \
	DECLARE_SERIALIZER(UICharacter)


#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_GENERATED_UINTERFACE_BODY() \
	UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_GENERATED_UINTERFACE_BODY() \
	UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IICharacter() {} \
public: \
	typedef UICharacter UClassType; \
	typedef IICharacter ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_INCLASS_IINTERFACE \
protected: \
	virtual ~IICharacter() {} \
public: \
	typedef UICharacter UClassType; \
	typedef IICharacter ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_7_PROLOG
#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_SPARSE_DATA \
	UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_RPC_WRAPPERS \
	UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_SPARSE_DATA \
	UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h_10_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UE4_CPP_MULTIPLAYER_API UClass* StaticClass<class UICharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UE4_Cpp_MultiPlayer_Source_UE4_Cpp_MultiPlayer_Characters_ICharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
