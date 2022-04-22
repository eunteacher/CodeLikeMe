#include "CGameMode.h"
#include "Utilities/Global.h"

ACGameMode::ACGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> asset = ConstructorHelpers::FClassFinder<APawn>(TEXT("Blueprint'/Game/PlayableCharacter/BP_CPlayableCharacter.BP_CPlayableCharacter_C'"));
	if(asset.Succeeded() == true)
	{
		DefaultPawnClass = asset.Class;
	}
}
