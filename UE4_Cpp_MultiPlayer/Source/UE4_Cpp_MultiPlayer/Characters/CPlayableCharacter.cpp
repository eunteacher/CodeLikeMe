#include "Characters/CPlayableCharacter.h"
#include "Utilities/Global.h"

#include "Camera/CameraComponent.h"

#include "GameFramework/Character.h"

#include "Animation/AnimInstance.h"

ACPlayableCharacter::ACPlayableCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Mesh 값 셋팅
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -0.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, 0.0f, 360.0f));

	// 카메라 생성 및 초기값 설정
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>("FirstPersonCamera");
	FirstPersonCamera->SetupAttachment(RootComponent);
	FirstPersonCamera->SetRelativeLocation(FVector(-40.0f, 0.0f, 70.0f));

	// 1인칭 메시 생성 
	Mesh2P = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh2P");
	Mesh2P->SetupAttachment(FirstPersonCamera);

	// 1인칭 메시 셋팅
	USkeletalMesh* mesh;
	ConstructorHelpers::FObjectFinder<USkeletalMesh> asset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/Asset/FirstPerson/Character/Mesh/SK_Mannequin_Arms.SK_Mannequin_Arms'"));
	if(asset.Succeeded() == true)
	{
		mesh = asset.Object;
		Mesh2P->SetSkeletalMesh(mesh);
	}
	Mesh2P->SetRelativeLocation(FVector(20.0f, 0.0f, -170.0f));
	Mesh2P->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	TSubclassOf<UAnimInstance> animInstance;
	ConstructorHelpers::FClassFinder<UAnimInstance> animAsset = ConstructorHelpers::FClassFinder<UAnimInstance>(TEXT("AnimBlueprint'/Game/PlayableCharacter/ABP_FirstPerson.ABP_FirstPerson_C'"));
	if(animAsset.Succeeded() == true)
	{
		//UE_LOG(LogTemp, Display, TEXT("animInstance Succeeded"));
		animInstance = animAsset.Class;
		Mesh2P->SetAnimInstanceClass(animInstance);
	}
}

void ACPlayableCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

