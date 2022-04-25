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

	// TODO :: 총 붙이기 

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
	virtual FRotator GetHorizontalControlRotation() override;
};
