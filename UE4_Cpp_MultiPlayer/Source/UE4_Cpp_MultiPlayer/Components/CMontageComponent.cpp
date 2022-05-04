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

	// OwnerCharacter �ʱ�ȭ
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	// ������ ���̺� �б�
	ReadDataTable(FirstPersonTable, EDateTableType::FirstPerson);

}

// �Է¹��� Type�� �����͸� �о�´�.
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
// ��Ÿ�� ���� �Լ�
void UCMontageComponent::PlayFireAnimMontage(EFirstPersonType InType)
{
	const FFirstPersonData* data = FirstPersonData[(int32)InType];
	if (data != NULL && data->AnimMontage != NULL)
		Cast<ACPlayableCharacter>(OwnerCharacter)->FPMesh->GetAnimInstance()->Montage_Play(data->AnimMontage, data->PlayRatio);

}
// ���� ���� �Լ�
void UCMontageComponent::PlayFireSound(EFirstPersonType InType, FVector InLocation)
{
	const FFirstPersonData* data = FirstPersonData[(int32)InType];
	if (data != NULL && data->Sound != NULL)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), data->Sound, InLocation);
}

// Character���� ������ �Լ�
void UCMontageComponent::OnFireMontage()
{
	PlayFireAnimMontage(EFirstPersonType::Fire);
}

void UCMontageComponent::OnFireSound(FVector InLocation)
{
	PlayFireSound(EFirstPersonType::Fire, InLocation);
}

