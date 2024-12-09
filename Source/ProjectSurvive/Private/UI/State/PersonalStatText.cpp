// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#include "UI/State/PersonalStatText.h"
#include "Components/TextBlock.h"

// Initialization
void UPersonalStatText::Initialization(const FText &InTitle, float InValue)
{
	Text_Stat_Title->SetText(InTitle);
	UpdateValue(InValue);
}

// Update value
void UPersonalStatText::UpdateValue(float InValue)
{
	Text_Stat_Value->SetText(FText::FromString(FString::SanitizeFloat(InValue)));
}
