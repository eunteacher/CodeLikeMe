#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "CMontageComponent.generated.h"

UENUM(BlueprintType)
enum class EFirstPersonType : uint8
{
	Fire, Max
};

USTRUCT(BlueprintType)
struct FFirstPersonData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		EFirstPersonType Type;

	UPROPERTY(EditAnywhere)
		class UAnimMontage* AnimMontage;

	UPROPERTY(EditAnywhere)
		float PlayRatio = 1.0f;

	UPROPERTY(EditAnywhere)
		FName StartSection;

	UPROPERTY(EditAnywhere)
		USoundBase* Sound;
};

UENUM(BlueprintType)
enum class EDateTableType : uint8
{
	FirstPerson, Max
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4_CPP_MULTIPLAYER_API UCMontageComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "DataTable")
		UDataTable* FirstPersonTable;

public:	
	UCMontageComponent();

protected:
	virtual void BeginPlay() override;
	// ���������̺��� �о���� �Լ�
	void ReadDataTable(UDataTable* InDataTable, EDateTableType InType);
	// Fire ���������̺��� ������ �о ��Ÿ�ָ� �����ϴ� �Լ�
	void PlayFireAnimMontage(EFirstPersonType InType);
	void PlayFireSound(EFirstPersonType InType, FVector InLocation);

public:	
	// Fire
	void OnFireMontage();
	void OnFireSound(FVector InLocation);

private:
	// ������Ʈ ���� ĳ���� 
	class ACharacter* OwnerCharacter;

	// ��Ÿ�� ������
	FFirstPersonData* FirstPersonData[(int32)EFirstPersonType::Max];
};
