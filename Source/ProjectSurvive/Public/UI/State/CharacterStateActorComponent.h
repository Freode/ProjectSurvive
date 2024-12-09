// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#pragma once

#include "../../../ProjectSurvive.h"
#include "Components/ActorComponent.h"
#include "CharacterStateActorComponent.generated.h"

class UPersonalStateWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSURVIVE_API UCharacterStateActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterStateActorComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Set binding functions
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetBindingFunctions();

	// Setter

	UFUNCTION(BlueprintCallable, Category = "UI")
	FORCEINLINE void SetPersonalStateWidget(class UPersonalStateWidget* InStateWidget){ StateWidget = InStateWidget; }

	// Getter

	UFUNCTION(BlueprintCallable, Category = "UI")
	FORCEINLINE UPersonalStateWidget* GetPersonalStateWidget() const { return StateWidget; }

	// Owner character
	UPROPERTY()
	ACharacter* OwnerCharacter;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	// State UI class
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", Meta = (AllowPrivateAccess = true))
	class UPersonalStateWidget* StateWidget;
	
};
