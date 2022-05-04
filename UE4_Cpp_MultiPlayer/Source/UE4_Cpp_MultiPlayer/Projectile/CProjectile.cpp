#include "Projectile/CProjectile.h"
#include "Utilities/Global.h"

#include "GameFramework/ProjectileMovementComponent.h"

#include "Components/SphereComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/StaticMeshComponent.h"


ACProjectile::ACProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	// ������Ʈ ����
	Sphere = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	SetRootComponent(Sphere);

	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(Sphere);

}

// ������ �ִ� �浹ü�� ���� �����ͼ� ���ε�
void ACProjectile::BeginPlay()
{
	Super::BeginPlay();

	TArray<UShapeComponent*> shapes;
	// GetComponents<�ڷ���>() ������ �ִ� �ڷ����� ��� �����´�.
	GetComponents<UShapeComponent>(shapes); 
	// OnComponentHit ���ε�
	for(UShapeComponent* shape : shapes)
		if (shape != NULL) shape->OnComponentHit.AddDynamic(this, &ACProjectile::OnComponentHit);
	
}

void ACProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Hit �̺�Ʈ
// �浹 �� ���� ��ü�� �а� �ڽ��� �ı��ȴ�.
void ACProjectile::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// IsSimulatingPhysics() ������ �ٵ� ���� ���� �ùķ��̼��� ����ϰ� �ִ��� ���θ� ��ȯ
	if (OtherComp->IsSimulatingPhysics() == true)
	{
		OtherComp->AddImpulseAtLocation(FVector(GetVelocity() * 100.0f), FVector(GetActorLocation()));
		//Destroy();
	}
}

