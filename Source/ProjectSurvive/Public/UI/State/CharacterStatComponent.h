// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#pragma once

#include "../../../ProjectSurvive.h"
#include "Components/ActorComponent.h"
#include "CharacterStatComponent.generated.h"

class UPersonalStatWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSURVIVE_API UCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterStatComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Setter

	UFUNCTION(BlueprintCallable, Category = "UI")
	FORCEINLINE void SetPersonalStatWidget(class UPersonalStatWidget* InStatWidget) { StatWidget = InStatWidget; }

	// Getter

	UFUNCTION(BlueprintCallable, Category = "UI")
	FORCEINLINE UPersonalStatWidget* GetPersonalStatWidget() const { return StatWidget; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	// Stat UI class
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", Meta = (AllowPrivateAccess = true))
	class UPersonalStatWidget* StatWidget;

		
};
