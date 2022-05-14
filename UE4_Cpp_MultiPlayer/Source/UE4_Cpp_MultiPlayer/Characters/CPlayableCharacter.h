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
		float TurnRate; // 방향 비율

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FRotator HorizontalSyncControlRotation; // 수직 방향

public: // 컴퍼넌트
	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera; // 카메라

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* FPMesh; // 1인칭 메시

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* FPGun; // 1인칭 총 메시

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* TPMesh; // 1인칭 메시

	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* TPGun; // 3인칭 총 메시

	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Muzzle; // 투사체 발사

	UPROPERTY(VisibleDefaultsOnly)
		class UCMontageComponent* Montage;

public:
	// BP를 통해서 입력
	UPROPERTY(EditAnywhere, Category = "Widget")
		TSubclassOf<class UCUserWidget_CrossHair> WidgetCrossHairClass; // 위젯 클래스


public:
	ACPlayableCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// HorizontalControlRotation 리턴하는 함수 
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
