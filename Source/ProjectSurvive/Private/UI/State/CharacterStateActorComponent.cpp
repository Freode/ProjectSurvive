// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#include "UI/State/CharacterStateActorComponent.h"
#include "Components/WidgetComponent.h"
#include "UI/State/PersonalStateWidget.h"
#include "MainSurviveGame/MainSurviveGamePlayerState.h"

// Sets default values for this component's properties
UCharacterStateActorComponent::UCharacterStateActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	// Create state widget component

}


// Called when the game starts
void UCharacterStateActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UCharacterStateActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Set binding functions
void UCharacterStateActorComponent::SetBindingFunctions()
{
	// Get owner character
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter == nullptr)
	{
		return;
	}

	// Binding functions on player state when character is locally controlled
	if (OwnerCharacter->IsLocallyControlled())
	{
		AMainSurviveGamePlayerState* PlayerState = OwnerCharacter->GetPlayerState<AMainSurviveGamePlayerState>();

		if (!PlayerState)
		{
			return;
		}

		// Set binding functions
		PlayerState->OnChangeCurrentHP.AddUObject(StateWidget, &UPersonalStateWidget::UpdateCurrentHP);
		PlayerState->OnChangeMaxHP.AddUObject(StateWidget, &UPersonalStateWidget::UpdateMaxHP);
		PlayerState->OnChangeCurrentMP.AddUObject(StateWidget, &UPersonalStateWidget::UpdateCurrentMP);
		PlayerState->OnChangeMaxMP.AddUObject(StateWidget, &UPersonalStateWidget::UpdateMaxMP);
		PlayerState->OnChangeExp.AddUObject(StateWidget, &UPersonalStateWidget::UpdateExp);
		PlayerState->OnChangeMaxExp.AddUObject(StateWidget, &UPersonalStateWidget::UpdateMaxExp);
	}
}

