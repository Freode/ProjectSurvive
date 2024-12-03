// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com


#include "UI/TotalWidgetActorComponent.h"
#include "UI/State/CharacterStatComponent.h"
#include "UI/State/CharacterStateActorComponent.h"
#include "UI/TotalWidget.h"

// Sets default values for this component's properties
UTotalWidgetActorComponent::UTotalWidgetActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...


	// Connect widget class
	ConstructorHelpers::FClassFinder<UTotalWidget> TOTALWIDGET(TEXT("/Game/ProjectS/UI/WG_Total.WG_Total_C"));

	if (TOTALWIDGET.Succeeded())
	{
		TotalUIclass = TOTALWIDGET.Class;
	}

	// Construct child ui components
	StatComponent = CreateDefaultSubobject<UCharacterStatComponent>(TEXT("StatComponent"));
	StateComponent = CreateDefaultSubobject<UCharacterStateActorComponent>(TEXT("StateComponent"));

}


// Called when the game starts
void UTotalWidgetActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	// Add to viewport the total ui class
	TotalUI = CreateWidget<UTotalWidget>(GetWorld(), TotalUIclass);

	if (TotalUI)
	{
		TotalUI->AddToViewport();
	}

	// Connect child ui class
	StateComponent->SetPersonalStateWidget(TotalUI->GetPersonalState());
	StatComponent->SetPersonalStatWidget(TotalUI->GetPersonalStat());
	
}


// Called every frame
void UTotalWidgetActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

