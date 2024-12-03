// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#pragma once

#include "../../ProjectSurvive.h"
#include "Blueprint/UserWidget.h"
#include "TotalWidget.generated.h"

// Forward Declare
class UPersonalStateWidget;
class UPersonalStatWidget;

/**
 * 
 */
UCLASS()
class PROJECTSURVIVE_API UTotalWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// Getter

	UFUNCTION(BlueprintCallable, Category = "UI")
	FORCEINLINE UPersonalStatWidget* GetPersonalStat() { return WG_PersonalStat; }

	UFUNCTION(BlueprintCallable, Category = "UI")
	FORCEINLINE UPersonalStateWidget* GetPersonalState() { return WG_PersonalState; }
	
protected:

	// State UI
	UPROPERTY(meta = (BindWidget))
	class UPersonalStateWidget* WG_PersonalState;

	// Stat UI
	UPROPERTY(meta = (BindWidget))
	class UPersonalStatWidget* WG_PersonalStat;
	
};
