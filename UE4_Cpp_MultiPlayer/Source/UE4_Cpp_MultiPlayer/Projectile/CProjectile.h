#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CProjectile.generated.h"

UCLASS()
class UE4_CPP_MULTIPLAYER_API ACProjectile : public AActor
{
	GENERATED_BODY()

	// TODO : ����ü Ŭ���� �ۼ�

public:	
	ACProjectile();

protected:
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
