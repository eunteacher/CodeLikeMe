#include "Components/CMontageComponent.h"
#include "Utilities/Global.h"
#include "Characters/CPlayableCharacter.h"
#include "GameFramework/Character.h"

UCMontageComponent::UCMontageComponent()
{

}

void UCMontageComponent::BeginPlay()
{
	Super::BeginPlay();

	// OwnerCharacter 초기화
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	// 데이터 테이블 읽기
	ReadDataTable(FirstPersonTable, EDateTableType::FirstPerson);

}

// 입력받은 Type의 데이터를 읽어온다.
void UCMontageComponent::ReadDataTable(UDataTable* InDataTable, EDateTableType InType)
{
	switch (InType)
	{
	case EDateTableType::FirstPerson:
	{
		TArray<FFirstPersonData*> FirstPersonDatas;
		InDataTable->GetAllRows<FFirstPersonData>("", FirstPersonDatas);
		for (int32 i = 0; i < (int32)EFirstPersonType::Max; i++)
		{
			for (FFirstPersonData* data : FirstPersonDatas)
				if ((EFirstPersonType)i == data->Type) FirstPersonData[i] = data;
		}
	}
	break;

	case EDateTableType::Max: break;

	default:
		break;
	}
}
// 몽타주 실행 함수
void UCMontageComponent::PlayFireAnimMontage(EFirstPersonType InType)
{
	const FFirstPersonData* data = FirstPersonData[(int32)InType];
	if (data != NULL && data->AnimMontage != NULL)
		Cast<ACPlayableCharacter>(OwnerCharacter)->FPMesh->GetAnimInstance()->Montage_Play(data->AnimMontage, data->PlayRatio);

}
// 사운드 실행 함수
void UCMontageComponent::PlayFireSound(EFirstPersonType InType, FVector InLocation)
{
	const FFirstPersonData* data = FirstPersonData[(int32)InType];
	if (data != NULL && data->Sound != NULL)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), data->Sound, InLocation);
}

// Character에서 실행할 함수
void UCMontageComponent::OnFireMontage()
{
	PlayFireAnimMontage(EFirstPersonType::Fire);
}

void UCMontageComponent::OnFireSound(FVector InLocation)
{
	PlayFireSound(EFirstPersonType::Fire, InLocation);
}

