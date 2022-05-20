#include "Characters/CPlayableCharacter.h"
#include "Utilities/Global.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimInstance.h"
#include "Components/CMontageComponent.h"
#include "Projectile/CProjectile.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystem.h"
#include "Widgets/CUserWidget_CrossHair.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

ACPlayableCharacter::ACPlayableCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// ȸ�� ����
	TurnRate = 45.0f;
	// �� �� �� ���� ��
	HorizontalSyncControlRotation = FRotator(0.0f, 0.0f, 0.0f);
	// �� ����
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 360.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;

	// ī�޶� ���� �� �ʱⰪ ����
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(GetCapsuleComponent());
	Camera->SetRelativeLocation(FVector(-40.0f, 0.0f, 65.0f));
	Camera->bUsePawnControlRotation = true;

	// 1��Ī �޽� ���� 
	FPMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FPMesh");
	FPMesh->SetupAttachment(Camera);

	// 1��Ī �޽� ����
	USkeletalMesh* mesh;
	ConstructorHelpers::FObjectFinder<USkeletalMesh> fpMeshAsset(TEXT("SkeletalMesh'/Game/Asset/FirstPerson/Character/Mesh/SK_Mannequin_Arms.SK_Mannequin_Arms'"));
	if (fpMeshAsset.Succeeded())
	{
		mesh = fpMeshAsset.Object;
		FPMesh->SetSkeletalMesh(mesh);
	}
	// 1��Ī �޽� ��ġ �� ����
	FPMesh->SetRelativeLocation(FVector(3.0f, -5.0f, -160.0f));
	FPMesh->SetRelativeRotation(FRotator(2.0f, -20.0f, 5.0f));
	FPMesh->SetOnlyOwnerSee(true);
	FPMesh->bCastDynamicShadow = false;
	FPMesh->CastShadow = false;

	// 1��Ī �ִ��ν��Ͻ� ����
	TSubclassOf<UAnimInstance> animInstance;
	ConstructorHelpers::FClassFinder<UAnimInstance> fpAnimAsset(TEXT("AnimBlueprint'/Game/PlayableCharacter/ABP_FirstPerson.ABP_FirstPerson_C'"));
	if (fpAnimAsset.Succeeded())
	{
		//UE_LOG(LogTemp, Display, TEXT("fpAnimAsset Succeeded"));
		animInstance = fpAnimAsset.Class;
		FPMesh->SetAnimInstanceClass(animInstance);
	}

	// 1��Ī �� �޽� ����
	FPGun = CreateDefaultSubobject<USkeletalMeshComponent>("FPGun");
	FPGun->SetupAttachment(FPMesh, FName("GripPoint"));
	FPGun->SetOnlyOwnerSee(true);
	FPGun->bCastDynamicShadow = false;
	FPGun->CastShadow = false;

	// 1��Ī �� �޽� ����
	// SkeletalMesh'/Game/Asset/FirstPerson/FPWeapon/Mesh/SK_FPGun.SK_FPGun'
	ConstructorHelpers::FObjectFinder<USkeletalMesh> fpGunAsset(TEXT("SkeletalMesh'/Game/Asset/FirstPerson/FPWeapon/Mesh/SK_FPGun.SK_FPGun'"));
	if (fpGunAsset.Succeeded())
	{
		mesh = fpGunAsset.Object;
		FPGun->SetSkeletalMesh(mesh);
	}

	// 3��Ī �޽� ����
	TPMesh = CreateDefaultSubobject<USkeletalMeshComponent>("TPMesh");
	TPMesh->SetupAttachment(GetCapsuleComponent());
	TPMesh->SetOwnerNoSee(true);
	// 3��Ī �޽� ����
	ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("SkeletalMesh'/Game/Asset/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (meshAsset.Succeeded())
	{
		mesh = meshAsset.Object;
		TPMesh->SetSkeletalMesh(mesh);
	}
	// �޽� ��ġ �� ����
	TPMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	TPMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	// 3��Ī �ִ��ν��Ͻ� ����
	ConstructorHelpers::FClassFinder<UAnimInstance> animAsset(TEXT("AnimBlueprint'/Game/PlayableCharacter/ABP_CPlayableCharacter.ABP_CPlayableCharacter_C'"));
	if (animAsset.Succeeded())
	{
		animInstance = animAsset.Class;
		TPMesh->SetAnimInstanceClass(animInstance);
	}

	// 3��Ī �� �޽� ����
	TPGun = CreateDefaultSubobject<USkeletalMeshComponent>("Gun");
	TPGun->SetupAttachment(TPMesh, FName("GunSocket"));
	TPGun->SetOwnerNoSee(true);

	// 3��Ī �� �޽� ����
	ConstructorHelpers::FObjectFinder<USkeletalMesh> GunAsset(TEXT("SkeletalMesh'/Game/Asset/FirstPerson/FPWeapon/Mesh/SK_FPGun.SK_FPGun'"));
	if (GunAsset.Succeeded())
	{
		mesh = GunAsset.Object;
		TPGun->SetSkeletalMesh(mesh);
	}

	// ������Ʈ ����
	Muzzle = CreateDefaultSubobject<USceneComponent>("Muzzle");
	Muzzle->SetupAttachment(FPGun, FName("Muzzle"));
	MuzzleParticle = CreateDefaultSubobject<UParticleSystemComponent>("MuzzleParticle");
	MuzzleParticle->SetupAttachment(FPGun, FName("Muzzle"));
	MuzzleParticle->SetIsReplicated(true);
	Montage = CreateDefaultSubobject<UCMontageComponent>("Montage"); // ��Ÿ��

	// ��ƼŬ ����
	static ConstructorHelpers::FObjectFinder<UParticleSystem> MuzzleParticleAsset(TEXT("ParticleSystem'/Game/Asset/WeaponEffects/ParticleSystems/Weapons/AssaultRifle/Muzzle/P_AssaultRifle_MF.P_AssaultRifle_MF'"));
	if (MuzzleParticleAsset.Succeeded())
	{
		MuzzleParticle->SetTemplate(MuzzleParticleAsset.Object);
	}
}

void ACPlayableCharacter::BeginPlay()
{
	Super::BeginPlay();

	// ������ƼŬ Off
	MuzzleParticle->Deactivate();
	// ���� ����
	if (WidgetCrossHairClass != nullptr)
	{
		// ����_CrossHair ����
		Widget_CrossHair = CreateWidget<UCUserWidget_CrossHair>(GetController<APlayerController>(), WidgetCrossHairClass);
		if (Widget_CrossHair != nullptr)
		{
			// ���� ����
			Widget_CrossHair->AddToViewport();
		}
	}

}

void ACPlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// Axis�� Action ���ε�
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
	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ACPlayableCharacter::OnFire);
	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Released, this, &ACPlayableCharacter::OffFire);

}

FRotator ACPlayableCharacter::GetHorizontalSyncControlRotation()
{
	return HorizontalSyncControlRotation;
}

// ���콺 X�� 
void ACPlayableCharacter::OnHorizontalLook(float Axis)
{
	AddControllerYawInput(Axis * TurnRate * GetWorld()->GetDeltaSeconds());
}

// ���콺 Y��
void ACPlayableCharacter::OnVerticalLook(float Axis)
{
	AddControllerPitchInput(Axis * TurnRate * GetWorld()->GetDeltaSeconds());

	if (IsLocallyControlled())
	{
		if (HasAuthority())
		{
			ServerSyncMulticastControllRotation(GetControlRotation());
		}
		else
		{
			ServerSyncControllRotation(GetControlRotation());
		}
	}
}

// ���� ���� 
void ACPlayableCharacter::OnMoveForward(float Axis)
{
	FRotator r = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	FVector direction = FRotationMatrix(r).GetUnitAxis(EAxis::X);
	AddMovementInput(direction, Axis);
}

// ������ ���� 
void ACPlayableCharacter::OnMoveRight(float Axis)
{
	FRotator r = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	FVector direction = FRotationMatrix(r).GetUnitAxis(EAxis::Y);
	AddMovementInput(direction, Axis);
}

// Jump() ȣ��
void ACPlayableCharacter::OnJump()
{
	Jump();
}
// StopJump() ȣ��
void ACPlayableCharacter::OffJump()
{
	StopJumping();
}

// 1. ��Ÿ�� ����
// 2. ����ü ����
// 3. ���� ����
void ACPlayableCharacter::OnFire()
{
	// 01. ��Ÿ�� �÷���
	Montage->OnFireMontage();
	// 02. ����ü ���� �� ����
	APlayerController* playerController = Cast<APlayerController>(GetController());
	FRotator rotation = playerController->PlayerCameraManager->GetCameraRotation();
	FVector gunOffset = FVector(50.0f, 0.0f, 10.0f);
	FVector location = Muzzle->GetComponentLocation() + rotation.RotateVector(gunOffset);
	// 03. ���� ����
	GetWorld()->SpawnActor<ACProjectile>(ACProjectile::StaticClass(), location, rotation);
	// 04. ���� �÷���
	Montage->OnFireSound(GetActorLocation());

	// ��ƼŬ On
	MuzzleParticle->Activate(true);
}

// ��ƼŬ ���� 
void ACPlayableCharacter::OffFire()
{
	MuzzleParticle->Deactivate();
}

// ������ ���÷�����Ʈ
// ��, �Ʒ��� �������� ��� ���� �� ����
void ACPlayableCharacter::ServerSyncControllRotation_Implementation(FRotator InHorizontalSyncControlRotation)
{
	HorizontalSyncControlRotation = InHorizontalSyncControlRotation;
	if (IsLocallyControlled() == false)
	{
		Camera->SetWorldRotation(HorizontalSyncControlRotation);
	}
}

// ������ Ŭ���̾�Ʈ ��� ���÷�����Ʈ
// ��, �Ʒ��� �������� ��� ���� �� ����
void ACPlayableCharacter::ServerSyncMulticastControllRotation_Implementation(FRotator InHorizontalSyncControlRotation)
{
	HorizontalSyncControlRotation = InHorizontalSyncControlRotation;
	if (IsLocallyControlled() == false)
	{
		Camera->SetWorldRotation(HorizontalSyncControlRotation);
	}
}
