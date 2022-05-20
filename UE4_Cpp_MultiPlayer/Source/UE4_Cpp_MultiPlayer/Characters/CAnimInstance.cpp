#include "Characters/CAnimInstance.h"
#include "Utilities/Global.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/ICharacter.h"

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (OwnerCharacter != nullptr)
	{
		Speed = OwnerCharacter->GetVelocity().Size2D(); // 스피드 값 설정
		Direction = CalculateDirection(OwnerCharacter->GetVelocity(), OwnerCharacter->GetActorRotation()); // 방향 설정
		IsAir = OwnerCharacter->GetCharacterMovement()->IsFalling(); // 공중 여부 판단

		// 속도를 통해 움직임 여부 판단
		if (OwnerCharacter->GetVelocity().Size() > 0.0f)
		{
			IsMoving = true;
		}
		else
		{
			IsMoving = false;
		}

		LookUp();
	}

}

// spine이 움직일 방향 값 설정 
void UCAnimInstance::LookUp()
{
	FRotator r = Cast<IICharacter>(OwnerCharacter)->GetHorizontalSyncControlRotation();

	if (r.Pitch > 270.0f)
	{
		r.Pitch = 360.0f - r.Pitch;
	}
	else
	{
		r.Pitch *= -1.0f;
	}

	ControlRotation = FRotator(0.0f, 0.0f, r.Pitch);
}
