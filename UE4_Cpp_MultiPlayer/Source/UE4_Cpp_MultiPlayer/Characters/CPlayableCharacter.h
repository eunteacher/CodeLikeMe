#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Characters/ICharacter.h"
#include "CPlayableCharacter.generated.h"

class UCMontageComponent;
class UCameraComponent;
class USkeletalMeshComponent;
class ACProjectile;
class UInputComponent;

UCLASS()
class UE4_CPP_MULTIPLAYER_API ACPlayableCharacter : public ACharacter, public IICharacter
{
	GENERATED_BODY()

public: // ����
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FRotator HorizontalSyncControlRotation; // ���� ����

public: // ���۳�Ʈ
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* Camera; // ī�޶�

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* FPMesh; // 1��Ī �޽�

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* FPGun; // 1��Ī �� �޽�

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Gun; // 3��Ī �� �޽�

	UPROPERTY(VisibleDefaultsOnly)
		UCMontageComponent* Montage;


public:
	ACPlayableCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	// HorizontalControlRotation �����ϴ� �Լ� 
	virtual FRotator GetHorizontalSyncControlRotation() override;

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

public:
	UFUNCTION(Server, Unreliable)
		void ServerSyncControllRotation(FRotator InHorizontalSyncControlRotation);

	UFUNCTION(NetMulticast, Unreliable)
		void ServerSyncMulticastControllRotation(FRotator InHorizontalSyncControlRotation);

};
