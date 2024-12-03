// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#pragma once

#include "../../ProjectSurvive.h"
#include "Components/ActorComponent.h"
#include "TotalWidgetActorComponent.generated.h"

// Forward Declare
class UCharacterStatComponent;
class UCharacterStateActorComponent;
class UTotalWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSURVIVE_API UTotalWidgetActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTotalWidgetActorComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	// Character's stat component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", Meta = (AllowPrivateAccess = true))
	TObjectPtr<UCharacterStatComponent> StatComponent;

	// Character's state component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", Meta = (AllowPrivateAccess = true))
	TObjectPtr<UCharacterStateActorComponent> StateComponent;

	// Total UI class
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", Meta = (AllowPrivateAccess = true))
	TSubclassOf<UTotalWidget> TotalUIclass;

	// Total UI widget object
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", Meta = (AllowPrivateAccess = true))
	class UTotalWidget* TotalUI;
};
