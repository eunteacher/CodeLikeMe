#include "UE4_Cpp_MultiPlayerGameModeBase.h"
#include "Utilities/Global.h"
#include "Characters/CPlayableCharacter.h"
#include "GameFramework/HUD.h"

AUE4_Cpp_MultiPlayerGameModeBase::AUE4_Cpp_MultiPlayerGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("Blueprint'/Game/PlayableCharacter/BP_CPlayableCharacter.BP_CPlayableCharacter_C'"));
	if(PlayerPawnClassFinder.Succeeded())
	{
		DefaultPawnClass = PlayerPawnClassFinder.Class;
	}
	
}
