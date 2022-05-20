#include "CLog.h"
#include "Engine.h"

// �𸮾� �������� �����ϴ� �α� ī�װ� �̿ܿ� �����ڰ� �ʿ��� ī�װ��� ���� ���� ����� �� �ִ�.
// �α� ī�װ�
DEFINE_LOG_CATEGORY_STATIC(GameProject, Display, All)

// Print

void CLog::Print(int32 InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, FString::FromInt(InValue));
}

void CLog::Print(float InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, FString::SanitizeFloat(InValue));
}

void CLog::Print(const FString & InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, InValue);
}

void CLog::Print(const FVector & InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, InValue.ToString());
}

void CLog::Print(const FRotator & InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, InValue.ToString());
}

// Log 

void CLog::Log(int32 InValue)
{
	UE_LOG(GameProject, Display, L"%d", InValue);
}

void CLog::Log(float InValue)
{
	UE_LOG(GameProject, Display, L"%f", InValue);
}

void CLog::Log(const FString & InValue)
{
	UE_LOG(GameProject, Display, L"%s", *InValue);
}

void CLog::Log(const FVector & InValue)
{
	UE_LOG(GameProject, Display, L"%s", *InValue.ToString());
}

void CLog::Log(const FRotator & InValue)
{
	UE_LOG(GameProject, Display, L"%s", *InValue.ToString());
}
