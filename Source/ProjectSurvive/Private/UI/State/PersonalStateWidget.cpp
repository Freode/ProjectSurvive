// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com


#include "UI/State/PersonalStateWidget.h"
#include "UI/State/PersonalStateBar.h"

// Initialization
void UPersonalStateWidget::Initialization()
{
	WG_HP->Initialization(FText::FromString("HP"), 1.0f, 1.0f, 1.0f, FLinearColor::Red);
	WG_Mana->Initialization(FText::FromString("MP"), 1.0f, 1.0f, 0.8f, FLinearColor(0.0f, 0.5f, 1.0f, 1.0f));
	WG_Exp->Initialization(FText::FromString("EXP"), 0.5f, 1.0f, 0.0f, FLinearColor::Green);
}

void UPersonalStateWidget::NativeConstruct()
{
	Initialization();
}
