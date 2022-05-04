#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Characters/ICharacter.h"
#include "CPlayableCharacter.generated.h"

UCLASS()
class UE4_CPP_MULTIPLAYER_API ACPlayableCharacter : public ACharacter, public IICharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera; // 카메라

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* FPMesh; // 1인칭 메시

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* FPGun; // 1인칭 총 메시

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* Gun; // 3인칭 총 메시

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UCMontageComponent* Montage;

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FRotator HorizontalControlRotation; // 수직 방향

public:
	ACPlayableCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// HorizontalControlRotation 리턴하는 함수 
	virtual FRotator GetHorizontalControlRotation() override;

private:
	// Bind Axis
	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);

public:
	// Bind Action
	void OnJump();
	void OffJump();

	void OnFire();
};
