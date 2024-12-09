// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com
#pragma once

#include "../../../ProjectSurvive.h"
#include "Blueprint/UserWidget.h"
#include "PersonalStatText.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSURVIVE_API UPersonalStatText : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// Initialization
	UFUNCTION(BlueprintCallable, Category = "UI")
	void Initialization(const FText &InTitle, float InValue);

	// Update value
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateValue(float InValue);
	
protected:

	// Stat title
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_Stat_Title;

	// Stat value
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_Stat_Value;
	
};
