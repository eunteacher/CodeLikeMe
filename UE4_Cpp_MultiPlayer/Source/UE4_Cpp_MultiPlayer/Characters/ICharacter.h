#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ICharacter.generated.h"

UINTERFACE(MinimalAPI)
class UICharacter : public UInterface
{
	GENERATED_BODY()
};

class UE4_CPP_MULTIPLAYER_API IICharacter
{
	GENERATED_BODY()

public:
	virtual FRotator GetHorizontalControlRotation() = 0;
};
