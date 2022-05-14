#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUserWidget_CrossHair.generated.h"

UCLASS()
class UE4_CPP_MULTIPLAYER_API UCUserWidget_CrossHair : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
		class UImage* CrossHair;

public:
	virtual void NativeConstruct() override;

};
