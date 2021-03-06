#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CProjectile.generated.h"


// 투사체 기본 클래스
// 이 클래스를 상속받아서 자식 클래스를 가지고 사용
UCLASS()
class UE4_CPP_MULTIPLAYER_API ACProjectile : public AActor
{
	GENERATED_BODY()

public:	
	ACProjectile();

protected:
	virtual void BeginPlay() override;
	
public:	
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION()
		void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class USphereComponent* Sphere;

	UPROPERTY(VisibleDefaultsOnly)
		class UProjectileMovementComponent* Projectile;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* StaticMesh;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		class UParticleSystem* ImpactEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		class UParticleSystem* TrailEffect;

};
