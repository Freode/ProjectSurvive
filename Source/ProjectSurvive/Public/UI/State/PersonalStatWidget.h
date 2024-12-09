// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#pragma once

#include "../../../ProjectSurvive.h"
#include "Blueprint/UserWidget.h"
#include "PersonalStatWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSURVIVE_API UPersonalStatWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// Initialization
	UFUNCTION(BlueprintCallable, Category = "UI")
	void Initialization();

	// Stat UI display
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetStatVisibility(bool bInVisible);
	
protected:

	// Native construct
	virtual void NativeConstruct() override;

	// Cancel button pressed event
	UFUNCTION()
	void OnCnacelButtonClicked();

	// Attack value
	UPROPERTY(meta = (BindWidget))
	class UPersonalStatText* WG_Attack;

	// Defense value
	UPROPERTY(meta = (BindWidget))
	class UPersonalStatText* WG_Defense_Value;

	// Sight range value
	UPROPERTY(meta = (BindWidget))
	class UPersonalStatText* WG_Sight_Range;

	// Attack period value
	UPROPERTY(meta = (BindWidget))
	class UPersonalStatText* WG_Attack_Period;

	// Attack range value
	UPROPERTY(meta = (BindWidget))
	class UPersonalStatText* WG_Attack_Range;

	// Move velocity value
	UPROPERTY(meta = (BindWidget))
	class UPersonalStatText* WG_Move_Velocity;

	// Cancel button
	UPROPERTY(meta = (BindWidget))
	class UButton* Btn_Cancel;

	// Cancel text block
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_Cancel;

	// Background
	UPROPERTY(meta = (BindWidget))
	class UBorder* BG_Stat;

private:

	// Collection of personal stat widgets
	TArray<class UPersonalStatText*> EachWidgets;

	// Is stat ui closed?
	bool bIsClosed = true;
};
