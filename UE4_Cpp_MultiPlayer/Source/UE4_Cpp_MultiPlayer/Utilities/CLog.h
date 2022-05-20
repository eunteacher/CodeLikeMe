#pragma once

#include "CoreMinimal.h"

class UE4_CPP_MULTIPLAYER_API CLog
{
public:
	// Print �Լ�
	// int��
	static void Print(int32 InValue, int32 InKey = -1, float InDuration = 10, FColor InColor = FColor::Blue);
	// float��
	static void Print(float InValue, int32 InKey = -1, float InDuration = 10, FColor InColor = FColor::Blue);
	// FString��
	static void Print(const FString& InValue, int32 InKey = -1, float InDuration = 10.0f, FColor InColor = FColor::Blue);
	// FVector��
	static void Print(const FVector& InValue, int32 InKey = -1, float InDuration = 10.0f, FColor InColor = FColor::Blue);
	// FRoator��
	static void Print(const FRotator& InValue, int32 InKey = -1, float InDuration = 10.0f, FColor InColor = FColor::Blue);

public: // Log �Լ�
	
	// int��
	static void Log(int32 InValue); 
	// float��
	static void Log(float InValue);
	// FString��
	static void Log(const FString& InValue);
	// FVector��
	static void Log(const FVector& InValue);
	// FRotator��
	static void Log(const FRotator& InValue);
};
