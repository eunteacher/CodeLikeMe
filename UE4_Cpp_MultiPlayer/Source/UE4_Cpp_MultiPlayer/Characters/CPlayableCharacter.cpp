#include "Characters/CPlayableCharacter.h"
#include "Utilities/Global.h"

#include "Camera/CameraComponent.h"

#include "GameFramework/Character.h"

#include "Animation/AnimInstance.h"

ACPlayableCharacter::ACPlayableCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// 카메라 생성 및 초기값 설정
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocation(FVector(-40.0f, 0.0f, 65.0f));
	Camera->bUsePawnControlRotation = true;

	// 1인칭 메시 생성 
	FPMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FPMesh");
	FPMesh->SetupAttachment(Camera);

	// 1인칭 메시 셋팅
	USkeletalMesh* mesh;
	ConstructorHelpers::FObjectFinder<USkeletalMesh> fpMeshAsset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/Asset/FirstPerson/Character/Mesh/SK_Mannequin_Arms.SK_Mannequin_Arms'"));
	if(fpMeshAsset.Succeeded() == true)
	{
		mesh = fpMeshAsset.Object;
		FPMesh->SetSkeletalMesh(mesh);
	}
	FPMesh->SetRelativeLocation(FVector(3.0f, -5.0f, -160.0f));
	FPMesh->SetRelativeRotation(FRotator(2.0f, -20.0f, 5.0f));

	// 1인칭 애님인스턴스 셋팅
	TSubclassOf<UAnimInstance> animInstance;
	ConstructorHelpers::FClassFinder<UAnimInstance> fpAnimAsset = ConstructorHelpers::FClassFinder<UAnimInstance>(TEXT("AnimBlueprint'/Game/PlayableCharacter/ABP_FirstPerson.ABP_FirstPerson_C'"));
	if(fpAnimAsset.Succeeded() == true)
	{
		//UE_LOG(LogTemp, Display, TEXT("fpAnimAsset Succeeded"));
		animInstance = fpAnimAsset.Class;
		FPMesh->SetAnimInstanceClass(animInstance);
	}

	// 1인칭 총 메시 생성
	FPGun = CreateDefaultSubobject<USkeletalMeshComponent>("FPGun");
	FPGun->SetupAttachment(FPMesh, FName("GripPoint"));
	//AttachToComponent(FPMesh, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), "GripPoint");

	// 1인칭 총 메시 셋팅
	// SkeletalMesh'/Game/Asset/FirstPerson/FPWeapon/Mesh/SK_FPGun.SK_FPGun'
	ConstructorHelpers::FObjectFinder<USkeletalMesh> fpGunAsset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/Asset/FirstPerson/FPWeapon/Mesh/SK_FPGun.SK_FPGun'"));
	if(fpGunAsset.Succeeded() == true)
	{
		mesh = fpGunAsset.Object;
		FPGun->SetSkeletalMesh(mesh);
	}

	// 3인칭 메시 셋팅
	ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/Asset/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (meshAsset.Succeeded() == true)
	{
		mesh = meshAsset.Object;
		GetMesh()->SetSkeletalMesh(mesh);
	}

	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	// 3인칭 애님인스턴스 셋팅
	ConstructorHelpers::FClassFinder<UAnimInstance> animAsset = ConstructorHelpers::FClassFinder<UAnimInstance>(TEXT("AnimBlueprint'/Game/PlayableCharacter/ABP_CPlayableCharacter.ABP_CPlayableCharacter_C'"));
	if (animAsset.Succeeded() == true)
	{
		UE_LOG(LogTemp, Display, TEXT("animAsset Succeeded"));
		animInstance = animAsset.Class;
		GetMesh()->SetAnimInstanceClass(animInstance);
	}

	// 3인칭 총 메시 생성
	Gun = CreateDefaultSubobject<USkeletalMeshComponent>("Gun");
	Gun->SetupAttachment(GetMesh(), FName("GunSocket"));
	//AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), "GunSocket");

	// 3인칭 총 메시 셋팅
	ConstructorHelpers::FObjectFinder<USkeletalMesh> GunAsset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/Asset/FirstPerson/FPWeapon/Mesh/SK_FPGun.SK_FPGun'"));
	if (fpGunAsset.Succeeded() == true)
	{
		mesh = fpGunAsset.Object;
		Gun->SetSkeletalMesh(mesh);
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

	// Movement Action
	// Bind Axis
	PlayerInputComponent->BindAxis("HorizontalLook", this, &ACPlayableCharacter::OnHorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook", this, &ACPlayableCharacter::OnVerticalLook);
	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayableCharacter::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayableCharacter::OnMoveRight);

	// Bind Action
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACPlayableCharacter::OnJump);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &ACPlayableCharacter::OffJump);

}

FRotator ACPlayableCharacter::GetHorizontalControlRotation()
{
	return HorizontalControlRotation;
}

void ACPlayableCharacter::OnHorizontalLook(float Axis)
{
	float HorizontalLookRate = 45.0f;
	AddControllerYawInput(Axis * HorizontalLookRate * GetWorld()->GetDeltaSeconds());
}

void ACPlayableCharacter::OnVerticalLook(float Axis)
{
	float VerticalLookRate = 45.0f;
	AddControllerYawInput(Axis * VerticalLookRate * GetWorld()->GetDeltaSeconds());
}

void ACPlayableCharacter::OnMoveForward(float Axis)
{
	FRotator r = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	FVector direction = FQuat(r).GetForwardVector();
	AddMovementInput(direction, Axis);
}

void ACPlayableCharacter::OnMoveRight(float Axis)
{
	FRotator r = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	FVector direction = FQuat(r).GetRightVector();
	AddMovementInput(direction, Axis);
}

void ACPlayableCharacter::OnJump()
{
	Jump();
}

void ACPlayableCharacter::OffJump()
{
	StopJumping();
}

