#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

UCLASS()
class UE4_CPP_MULTIPLAYER_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACPlayerController();

private:
	//class ACharacter* OwnerCharacter;
	
};
