// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com


#include "UI/State/PersonalStateWidget.h"
#include "UI/State/PersonalStateBar.h"
#include "Components/TextBlock.h"

// Initialization
void UPersonalStateWidget::Initialization()
{
	// Base widget setting
	WG_HP->Initialization(FText::FromString("HP"), 1.0f, 1.0f, 1.0f, FLinearColor::Red);
	WG_Mana->Initialization(FText::FromString("MP"), 1.0f, 1.0f, 0.8f, FLinearColor(0.0f, 0.5f, 1.0f, 1.0f));
	WG_Exp->Initialization(FText::FromString("EXP"), 0.5f, 1.0f, 0.0f, FLinearColor::Green);

}

// Level up
void UPersonalStateWidget::LevelUp(float InNewLevel)
{
	Text_Level->SetText(FText::FromString(FString::FromInt(static_cast<int32>(InNewLevel))));
}

// Update current hp
void UPersonalStateWidget::UpdateCurrentHP(float InNewHP)
{
	WG_HP->UpdateCurrentValue(InNewHP);
}

// Update max hp
void UPersonalStateWidget::UpdateMaxHP(float InNewHP)
{
	WG_HP->UpdateMaxValue(InNewHP);
}

// Update current mp
void UPersonalStateWidget::UpdateCurrentMP(float InNewMP)
{
	WG_Mana->UpdateCurrentValue(InNewMP);
}

// Update max mp
void UPersonalStateWidget::UpdateMaxMP(float InNewMP)
{
	WG_Mana->UpdateMaxValue(InNewMP);
}

// Update current exp
void UPersonalStateWidget::UpdateExp(float InNewExp)
{
	WG_Exp->UpdateCurrentValue(InNewExp);
}

// Update max exp
void UPersonalStateWidget::UpdateMaxExp(float InNewExp)
{
	WG_Exp->UpdateMaxValue(InNewExp);
}

void UPersonalStateWidget::NativeConstruct()
{
	Initialization();
}
