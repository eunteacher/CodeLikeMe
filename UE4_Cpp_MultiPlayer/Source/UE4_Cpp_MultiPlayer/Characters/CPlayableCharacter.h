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
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		float TurnRate; // ���� ����

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FRotator HorizontalSyncControlRotation; // ���� ����

public: // ���۳�Ʈ
	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera; // ī�޶�

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* FPMesh; // 1��Ī �޽�

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* FPGun; // 1��Ī �� �޽�

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* TPMesh; // 1��Ī �޽�

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* TPGun; // 3��Ī �� �޽�

	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Muzzle; // ����ü �߻�

	UPROPERTY(VisibleDefaultsOnly)
		class UCMontageComponent* Montage;

public:
	// BP�� ���ؼ� �Է�
	UPROPERTY(EditAnywhere, Category = "Widget")
		TSubclassOf<class UCUserWidget_CrossHair> WidgetCrossHairClass; // ���� Ŭ����


public:
	ACPlayableCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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

private:
	class UCUserWidget_CrossHair* Widget_CrossHair;
};
