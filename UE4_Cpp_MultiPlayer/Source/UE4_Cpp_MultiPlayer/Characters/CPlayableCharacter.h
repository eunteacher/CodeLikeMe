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
		class UCameraComponent* Camera; // ī�޶�

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* FPMesh; // 1��Ī �޽�

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* FPGun; // 1��Ī �� �޽�

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* Gun; // 3��Ī �� �޽�


public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FRotator HorizontalControlRotation; // ���� ����

public:
	ACPlayableCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	virtual FRotator GetHorizontalControlRotation() override;

private:
	// Bind Axis
	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);

public:
	void OnJump();
	void OffJump();
};
