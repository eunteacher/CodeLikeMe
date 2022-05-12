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
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");

	// Sphere �� ����
	Sphere->SetCollisionProfileName(TEXT("Projectile"));
	SetRootComponent(Sphere);

	// Projectile �� ����
	Projectile->InitialSpeed = 2000.0f;
	Projectile->MaxSpeed = 3000.0f;
	Projectile->bShouldBounce = true;
	Projectile->ProjectileGravityScale = 1.0f;
	Projectile->Velocity = FVector(3000.0f, 0.0f, 0.0f);

	// ����ƽ �޽� �� ����
	StaticMesh->SetupAttachment(Sphere);
	StaticMesh->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));

	// ����ƽ �޽� ���� 
	UStaticMesh* staticMesh;
	ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Asset/FirstPerson/Meshes/FirstPersonProjectileMesh.FirstPersonProjectileMesh'"));
	if (staticMeshAsset.Succeeded() == true)
	{
		UE_LOG(LogTemp, Display, TEXT("staticMeshObject Succeeded"));
		staticMesh = staticMeshAsset.Object;
		StaticMesh->SetStaticMesh(staticMesh);
		StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	// ���ø�����Ʈ ����
	SetReplicates(true);
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
	{
		if (shape != NULL) shape->OnComponentHit.AddDynamic(this, &ACProjectile::OnComponentHit);
	}
}

void ACProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Hit �̺�Ʈ
// �浹 �� ���� ��ü�� �а� �ڽ��� �ı��ȴ�.
void ACProjectile::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Display, TEXT("Projectile Hit"));

	// IsSimulatingPhysics() ������ �ٵ� ���� ���� �ùķ��̼��� ����ϰ� �ִ��� ���θ� ��ȯ
	if (OtherComp->IsSimulatingPhysics() == true)
	{
		//UE_LOG(LogTemp, Display, TEXT("Projectile Hit"));
		OtherComp->AddImpulseAtLocation(FVector(GetVelocity() * 100.0f), FVector(GetActorLocation()));
		Destroyed();
	}

}

