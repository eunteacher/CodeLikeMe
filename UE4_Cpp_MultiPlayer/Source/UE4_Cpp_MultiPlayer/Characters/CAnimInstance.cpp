#include "Characters/CAnimInstance.h"
#include "Utilities/Global.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Characters/ICharacter.h"

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();


}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (OwnerCharacter != nullptr)
	{
		Speed = OwnerCharacter->GetVelocity().Size2D();
		Direction = CalculateDirection(OwnerCharacter->GetVelocity(), OwnerCharacter->GetControlRotation());
		IsAir = OwnerCharacter->GetCharacterMovement()->IsFalling();
		if(OwnerCharacter->GetVelocity().Size() > 0.0f)
			IsMoving = true;

		LookUp();
	}

}

void UCAnimInstance::LookUp()
{
	FRotator r = Cast<IICharacter>(OwnerCharacter)->GetHorizontalControlRotation();

	if (r.Pitch > 270.0f)
		r.Pitch = 360 - r.Pitch;
	else
		r.Pitch *= -1.0f;

	ControlRotation.Roll = r.Pitch;
}
