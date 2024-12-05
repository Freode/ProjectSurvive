// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#pragma once

#include "../../../ProjectSurvive.h"
#include "Blueprint/UserWidget.h"
#include "PersonalStateBar.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSURVIVE_API UPersonalStateBar : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// Initialization
	UFUNCTION(BlueprintCallable, Category = "UI")
	void Initialization(FText InBarTitle, float InCurValue, float InMaxValue, float InAdditional, FLinearColor InColor);

	// Update additonal value
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateAdditional(float InAdditional);

	// Update current value
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateCurrentValue(float InValue);

	// Update max value
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateMaxValue(float InValue);

	// Update progress bar color
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateProgressBarColor(FLinearColor InColor);
	
protected:

	// Indicate current value
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* ProgressBar_Main;

	// Current value
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_Value;

	// Recover value by a second
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_Additional;

	// Function name which is related personal state
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_Bar_Title;
	
private:

	// Add plus signal in front of value
	FString AdditionalValue(float InAdditional);

	// Set current value & max value to string & progress bar
	void UpdateValue();

	// Current value
	float CurrentValue = 0.0f;

	// Max value
	float MaxValue = 1.0f;
};
