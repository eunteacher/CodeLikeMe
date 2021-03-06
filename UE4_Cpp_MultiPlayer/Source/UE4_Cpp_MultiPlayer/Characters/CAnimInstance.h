#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

UCLASS()
class UE4_CPP_MULTIPLAYER_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float Speed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		bool IsAir;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		bool IsMoving;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float Direction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		bool EnableJump;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		bool Jumping;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		bool Crouching;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FRotator ControlRotation;

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	void LookUp();

private:
	class ACharacter* OwnerCharacter;

};
