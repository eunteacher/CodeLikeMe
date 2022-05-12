#include "Projectile/CProjectile.h"
#include "Utilities/Global.h"

#include "GameFramework/ProjectileMovementComponent.h"

#include "Components/SphereComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/StaticMeshComponent.h"

ACProjectile::ACProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	// 컴포넌트 생성
	Sphere = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");

	// Sphere 값 설정
	Sphere->SetCollisionProfileName(TEXT("Projectile"));
	SetRootComponent(Sphere);

	// Projectile 값 설정
	Projectile->InitialSpeed = 2000.0f;
	Projectile->MaxSpeed = 3000.0f;
	Projectile->bShouldBounce = true;
	Projectile->ProjectileGravityScale = 1.0f;
	Projectile->Velocity = FVector(3000.0f, 0.0f, 0.0f);

	// 스태틱 메시 값 설정
	StaticMesh->SetupAttachment(Sphere);
	StaticMesh->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));

	// 스태틱 메시 설정 
	UStaticMesh* staticMesh;
	ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Asset/FirstPerson/Meshes/FirstPersonProjectileMesh.FirstPersonProjectileMesh'"));
	if (staticMeshAsset.Succeeded() == true)
	{
		UE_LOG(LogTemp, Display, TEXT("staticMeshObject Succeeded"));
		staticMesh = staticMeshAsset.Object;
		StaticMesh->SetStaticMesh(staticMesh);
		StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	// 리플리케이트 설정
	SetReplicates(true);
}

// 가지고 있는 충돌체를 전부 가져와서 바인딩
void ACProjectile::BeginPlay()
{
	Super::BeginPlay();

	TArray<UShapeComponent*> shapes;
	// GetComponents<자료형>() 가지고 있는 자료형을 모두 가져온다.
	GetComponents<UShapeComponent>(shapes); 
	// OnComponentHit 바인딩
	for(UShapeComponent* shape : shapes)
	{
		if (shape != NULL) shape->OnComponentHit.AddDynamic(this, &ACProjectile::OnComponentHit);
	}
}

void ACProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Hit 이벤트
// 충돌 시 맞은 객체를 밀고 자신은 파괴된다.
void ACProjectile::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Display, TEXT("Projectile Hit"));

	// IsSimulatingPhysics() 지정된 바디가 현재 물리 시뮬레이션을 사용하고 있는지 여부를 반환
	if (OtherComp->IsSimulatingPhysics() == true)
	{
		//UE_LOG(LogTemp, Display, TEXT("Projectile Hit"));
		OtherComp->AddImpulseAtLocation(FVector(GetVelocity() * 100.0f), FVector(GetActorLocation()));
		Destroyed();
	}

}

