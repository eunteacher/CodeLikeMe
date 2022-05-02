#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CProjectile.generated.h"

UCLASS()
class UE4_CPP_MULTIPLAYER_API ACProjectile : public AActor
{
	GENERATED_BODY()

	// TODO : 투사체 클래스 작성

public:	
	ACProjectile();

protected:
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
