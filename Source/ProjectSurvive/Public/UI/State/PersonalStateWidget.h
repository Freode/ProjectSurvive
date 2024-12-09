// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#pragma once

#include "../../../ProjectSurvive.h"
#include "Blueprint/UserWidget.h"
#include "../../Data/PerosnalCharacterData.h"
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

	// Level up
	UFUNCTION(BlueprintCallable, Category = "UI")
	void LevelUp(float InNewLevel);

	// Update current hp
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateCurrentHP(float InNewHP);

	// Update max hp
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateMaxHP(float InNewHP);

	// Update current mp
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateCurrentMP(float InNewMP);

	// Update max mp
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateMaxMP(float InNewMP);

	// Update current exp
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateExp(float InNewExp);

	// Update max exp
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateMaxExp(float InNewExp);
	
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
	
private:

	// Personal state table which has information about each level 
	UPROPERTY()
	class UDataTable* PersonalStateTable;
};
