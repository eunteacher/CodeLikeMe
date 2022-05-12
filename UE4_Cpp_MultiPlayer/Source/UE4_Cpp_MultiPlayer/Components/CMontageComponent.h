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
	// 데이터테이블을 읽어오는 함수
	void ReadDataTable(UDataTable* InDataTable, EDateTableType InType);
	// Fire 데이터테이블의 정보를 읽어서 몽타주를 실행하는 함수
	void PlayFireAnimMontage(EFirstPersonType InType);
	void PlayFireSound(EFirstPersonType InType, FVector InLocation);

public:	
	// Fire
	void OnFireMontage();
	void OnFireSound(FVector InLocation);

private:
	// 컴포넌트 소유 캐릭터 
	class ACharacter* OwnerCharacter;

	// 몽타주 데이터
	FFirstPersonData* FirstPersonData[(int32)EFirstPersonType::Max];
};
