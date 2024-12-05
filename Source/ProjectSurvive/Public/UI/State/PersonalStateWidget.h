// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#pragma once

#include "../../../ProjectSurvive.h"
#include "Blueprint/UserWidget.h"
#include "PersonalStateWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSURVIVE_API UPersonalStateWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// Initialization
	UFUNCTION(BlueprintCallable, Category = "UI")
	void Initialization();
	
protected:

	// 
	virtual void NativeConstruct() override;

	// Level
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_Level;

	// HP Progress bar
	UPROPERTY(meta = (BindWidget))
	class UPersonalStateBar* WG_HP;

	// Mana Progress bar
	UPROPERTY(meta = (BindWidget))
	class UPersonalStateBar* WG_Mana;

	// Exp progress bar
	UPROPERTY(meta = (BindWidget))
	class UPersonalStateBar* WG_Exp;
	
};
