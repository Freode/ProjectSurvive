// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com


#include "UI/State/PersonalStatWidget.h"
#include "UI/State/PersonalStatText.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Engine/DataTable.h"

// Initialization
void UPersonalStatWidget::Initialization()
{
	FText TempText = FText::FromString(TEXT("공격력"));
	WG_Attack->Initialization(TempText, 50.0f);
}	

// Stat UI display
void UPersonalStatWidget::SetStatVisibility(bool bInVisible)
{
	bIsClosed = bInVisible;
	// Visible
	if (bInVisible)
	{
		Text_Cancel->SetText(FText::FromString("X"));
		BG_Stat->SetVisibility(ESlateVisibility::HitTestInvisible);
		for (auto& each : EachWidgets)
		{
			each->SetVisibility(ESlateVisibility::HitTestInvisible);
		}
	}
	// Invisible
	else
	{
		Text_Cancel->SetText(FText::FromString("<"));
		BG_Stat->SetVisibility(ESlateVisibility::Hidden);
		for (auto& each : EachWidgets)
		{
			each->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

// Native construct
void UPersonalStatWidget::NativeConstruct()
{
	// Add stat ui
	EachWidgets.Add(WG_Attack);
	EachWidgets.Add(WG_Defense_Value);
	EachWidgets.Add(WG_Sight_Range);
	EachWidgets.Add(WG_Attack_Period);
	EachWidgets.Add(WG_Attack_Range);
	EachWidgets.Add(WG_Move_Velocity);

	// Connect button function
	Btn_Cancel->OnPressed.AddDynamic(this, &UPersonalStatWidget::OnCnacelButtonClicked);

	// Initialization
	Initialization();
}

// Cancel button pressed event
void UPersonalStatWidget::OnCnacelButtonClicked()
{
	SetStatVisibility(!bIsClosed);
}
