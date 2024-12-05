// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#include "UI/State/PersonalStateBar.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

// Initialization
void UPersonalStateBar::Initialization(FText InBarTitle, float InCurValue, float InMaxValue, float InAdditional, FLinearColor InColor)
{
	// 
	Text_Bar_Title->SetText(InBarTitle);
	UpdateCurrentValue(InCurValue);
	UpdateMaxValue(InMaxValue);
	UpdateAdditional(InAdditional);
	UpdateProgressBarColor(InColor);
}

// Update additonal value
void UPersonalStateBar::UpdateAdditional(float InAdditional)
{
	// Addtional text is invisible when additional float value is 0.0f;
	if (InAdditional == KINDA_SMALL_NUMBER)
	{
		Text_Additional->SetVisibility(ESlateVisibility::Hidden);
	}
	// else
	else
	{
		Text_Additional->SetVisibility(ESlateVisibility::HitTestInvisible);
		Text_Additional->SetText(FText::FromString(AdditionalValue(InAdditional)));
	}
}

// Update current value
void UPersonalStateBar::UpdateCurrentValue(float InValue)
{
	CurrentValue = InValue;
	UpdateValue();
}

// Update max value
void UPersonalStateBar::UpdateMaxValue(float InValue)
{
	MaxValue = InValue;
	UpdateValue();
}

// Update progress bar color
void UPersonalStateBar::UpdateProgressBarColor(FLinearColor InColor)
{
	ProgressBar_Main->SetFillColorAndOpacity(InColor);
}

// Add plus signal in front of value
FString UPersonalStateBar::AdditionalValue(float InAdditional)
{
	// Round to one decimal
	FString Additional = FString::SanitizeFloat(FMath::RoundToFloat(InAdditional * 10.0f) / 10.0f);
	Additional = "+" + Additional;
	return Additional;
}

// Set current value & max value to string & progress bar
void UPersonalStateBar::UpdateValue()
{
	// Set value
	FString TempValue = FString::SanitizeFloat(CurrentValue) + "/" + FString::SanitizeFloat(MaxValue);
	Text_Value->SetText(FText::FromString(TempValue));

	// Set percent
	float percent = CurrentValue / MaxValue;
	ProgressBar_Main->SetPercent(percent);
}

