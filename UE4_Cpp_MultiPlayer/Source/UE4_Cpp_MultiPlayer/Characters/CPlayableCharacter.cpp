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

	// 회전 비율
	TurnRate = 45.0f;
	// 상 하 본 방향 값
	HorizontalSyncControlRotation = FRotator(0.0f, 0.0f, 0.0f);
	// 값 설정
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 360.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;

	// 카메라 생성 및 초기값 설정
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(GetCapsuleComponent());
	Camera->SetRelativeLocation(FVector(-40.0f, 0.0f, 65.0f));
	Camera->bUsePawnControlRotation = true;

	// 1인칭 메시 생성 
	FPMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FPMesh");
	FPMesh->SetupAttachment(Camera);

	// 1인칭 메시 셋팅
	USkeletalMesh* mesh;
	ConstructorHelpers::FObjectFinder<USkeletalMesh> fpMeshAsset(TEXT("SkeletalMesh'/Game/Asset/FirstPerson/Character/Mesh/SK_Mannequin_Arms.SK_Mannequin_Arms'"));
	if (fpMeshAsset.Succeeded())
	{
		mesh = fpMeshAsset.Object;
		FPMesh->SetSkeletalMesh(mesh);
	}
	// 1인칭 메시 위치 값 설정
	FPMesh->SetRelativeLocation(FVector(3.0f, -5.0f, -160.0f));
	FPMesh->SetRelativeRotation(FRotator(2.0f, -20.0f, 5.0f));
	FPMesh->SetOnlyOwnerSee(true);
	FPMesh->bCastDynamicShadow = false;
	FPMesh->CastShadow = false;

	// 1인칭 애님인스턴스 셋팅
	TSubclassOf<UAnimInstance> animInstance;
	ConstructorHelpers::FClassFinder<UAnimInstance> fpAnimAsset(TEXT("AnimBlueprint'/Game/PlayableCharacter/ABP_FirstPerson.ABP_FirstPerson_C'"));
	if (fpAnimAsset.Succeeded())
	{
		//UE_LOG(LogTemp, Display, TEXT("fpAnimAsset Succeeded"));
		animInstance = fpAnimAsset.Class;
		FPMesh->SetAnimInstanceClass(animInstance);
	}

	// 1인칭 총 메시 생성
	FPGun = CreateDefaultSubobject<USkeletalMeshComponent>("FPGun");
	FPGun->SetupAttachment(FPMesh, FName("GripPoint"));
	FPGun->SetOnlyOwnerSee(true);
	FPGun->bCastDynamicShadow = false;
	FPGun->CastShadow = false;

	// 1인칭 총 메시 셋팅
	// SkeletalMesh'/Game/Asset/FirstPerson/FPWeapon/Mesh/SK_FPGun.SK_FPGun'
	ConstructorHelpers::FObjectFinder<USkeletalMesh> fpGunAsset(TEXT("SkeletalMesh'/Game/Asset/FirstPerson/FPWeapon/Mesh/SK_FPGun.SK_FPGun'"));
	if (fpGunAsset.Succeeded())
	{
		mesh = fpGunAsset.Object;
		FPGun->SetSkeletalMesh(mesh);
	}

	// 3인칭 메시 생성
	TPMesh = CreateDefaultSubobject<USkeletalMeshComponent>("TPMesh");
	TPMesh->SetupAttachment(GetCapsuleComponent());
	TPMesh->SetOwnerNoSee(true);
	// 3인칭 메시 셋팅
	ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("SkeletalMesh'/Game/Asset/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (meshAsset.Succeeded())
	{
		mesh = meshAsset.Object;
		TPMesh->SetSkeletalMesh(mesh);
	}
	// 메시 위치 값 설정
	TPMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	TPMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	// 3인칭 애님인스턴스 셋팅
	ConstructorHelpers::FClassFinder<UAnimInstance> animAsset(TEXT("AnimBlueprint'/Game/PlayableCharacter/ABP_CPlayableCharacter.ABP_CPlayableCharacter_C'"));
	if (animAsset.Succeeded())
	{
		animInstance = animAsset.Class;
		TPMesh->SetAnimInstanceClass(animInstance);
	}

	// 3인칭 총 메시 생성
	TPGun = CreateDefaultSubobject<USkeletalMeshComponent>("Gun");
	TPGun->SetupAttachment(TPMesh, FName("GunSocket"));
	TPGun->SetOwnerNoSee(true);

	// 3인칭 총 메시 셋팅
	ConstructorHelpers::FObjectFinder<USkeletalMesh> GunAsset(TEXT("SkeletalMesh'/Game/Asset/FirstPerson/FPWeapon/Mesh/SK_FPGun.SK_FPGun'"));
	if (GunAsset.Succeeded())
	{
		mesh = GunAsset.Object;
		TPGun->SetSkeletalMesh(mesh);
	}

	// 컴포넌트 생성
	Muzzle = CreateDefaultSubobject<USceneComponent>("Muzzle");
	Muzzle->SetupAttachment(FPGun, FName("Muzzle"));
	MuzzleParticle = CreateDefaultSubobject<UParticleSystemComponent>("MuzzleParticle");
	MuzzleParticle->SetupAttachment(FPGun, FName("Muzzle"));
	MuzzleParticle->SetIsReplicated(true);
	Montage = CreateDefaultSubobject<UCMontageComponent>("Montage"); // 몽타주

	// 파티클 생성
	static ConstructorHelpers::FObjectFinder<UParticleSystem> MuzzleParticleAsset(TEXT("ParticleSystem'/Game/Asset/WeaponEffects/ParticleSystems/Weapons/AssaultRifle/Muzzle/P_AssaultRifle_MF.P_AssaultRifle_MF'"));
	if (MuzzleParticleAsset.Succeeded())
	{
		MuzzleParticle->SetTemplate(MuzzleParticleAsset.Object);
	}
}

void ACPlayableCharacter::BeginPlay()
{
	Super::BeginPlay();

	// 머즐파티클 Off
	MuzzleParticle->Deactivate();
	// 위셋 생성
	if (WidgetCrossHairClass != nullptr)
	{
		// 위젯_CrossHair 생성
		Widget_CrossHair = CreateWidget<UCUserWidget_CrossHair>(GetController<APlayerController>(), WidgetCrossHairClass);
		if (Widget_CrossHair != nullptr)
		{
			// 위젯 띄우기
			Widget_CrossHair->AddToViewport();
		}
	}

}

void ACPlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// Axis와 Action 바인딩
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

// 마우스 X축 
void ACPlayableCharacter::OnHorizontalLook(float Axis)
{
	AddControllerYawInput(Axis * TurnRate * GetWorld()->GetDeltaSeconds());
}

// 마우스 Y축
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

// 정면 방향 
void ACPlayableCharacter::OnMoveForward(float Axis)
{
	FRotator r = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	FVector direction = FRotationMatrix(r).GetUnitAxis(EAxis::X);
	AddMovementInput(direction, Axis);
}

// 오른쪽 방향 
void ACPlayableCharacter::OnMoveRight(float Axis)
{
	FRotator r = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	FVector direction = FRotationMatrix(r).GetUnitAxis(EAxis::Y);
	AddMovementInput(direction, Axis);
}

// Jump() 호출
void ACPlayableCharacter::OnJump()
{
	Jump();
}
// StopJump() 호출
void ACPlayableCharacter::OffJump()
{
	StopJumping();
}

// 1. 몽타주 실행
// 2. 투사체 생성
// 3. 사운드 실행
void ACPlayableCharacter::OnFire()
{
	// 01. 몽타주 플레이
	Montage->OnFireMontage();
	// 02. 투사체 생성 및 설정
	APlayerController* playerController = Cast<APlayerController>(GetController());
	FRotator rotation = playerController->PlayerCameraManager->GetCameraRotation();
	FVector gunOffset = FVector(50.0f, 0.0f, 10.0f);
	FVector location = Muzzle->GetComponentLocation() + rotation.RotateVector(gunOffset);
	// 03. 액터 생성
	GetWorld()->SpawnActor<ACProjectile>(ACProjectile::StaticClass(), location, rotation);
	// 04. 사운드 플레이
	Montage->OnFireSound(GetActorLocation());

	// 파티클 On
	MuzzleParticle->Activate(true);
}

// 파티클 오프 
void ACPlayableCharacter::OffFire()
{
	MuzzleParticle->Deactivate();
}

// 서버만 리플레케이트
// 위, 아래로 움직였일 경우 방향 값 설정
void ACPlayableCharacter::ServerSyncControllRotation_Implementation(FRotator InHorizontalSyncControlRotation)
{
	HorizontalSyncControlRotation = InHorizontalSyncControlRotation;
	if (IsLocallyControlled() == false)
	{
		Camera->SetWorldRotation(HorizontalSyncControlRotation);
	}
}

// 서버와 클라이언트 모두 리플레케이트
// 위, 아래로 움직였일 경우 방향 값 설정
void ACPlayableCharacter::ServerSyncMulticastControllRotation_Implementation(FRotator InHorizontalSyncControlRotation)
{
	HorizontalSyncControlRotation = InHorizontalSyncControlRotation;
	if (IsLocallyControlled() == false)
	{
		Camera->SetWorldRotation(HorizontalSyncControlRotation);
	}
}
