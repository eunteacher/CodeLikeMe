#include "CGameMode.h"
#include "Utilities/Global.h"
#include "Characters/CPlayableCharacter.h"

ACGameMode::ACGameMode()
{
	DefaultPawnClass = ACPlayableCharacter::StaticClass();
}

void ACGameMode::BeginPlay()
{
	Super::BeginPlay();

}

