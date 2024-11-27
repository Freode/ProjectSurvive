// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com


#include "MainSurviveGame/MainSurviveGameMode.h"
#include "MainSurviveGame/MainSurviveGamePlayerState.h"
#include "MainSurviveGame/MainSurviveGameState.h"

AMainSurviveGameMode::AMainSurviveGameMode()
{
	// Connect classes

	static ConstructorHelpers::FClassFinder<ACharacter> CHARACTER_CLASS(TEXT("/Game/ProjectS/TopDown/Blueprints/BP_TopDownCharacter.BP_TopDownCharacter_C"));

	if (CHARACTER_CLASS.Succeeded())
	{
		DefaultPawnClass = CHARACTER_CLASS.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PLAYERCONTROLLER_CLASS(TEXT("/Game/ProjectS/TopDown/Blueprints/BP_TopDownPlayerController.BP_TopDownPlayerController_C"));

	if (PLAYERCONTROLLER_CLASS.Succeeded())
	{
		PlayerControllerClass = PLAYERCONTROLLER_CLASS.Class;
	}

	GameStateClass = AMainSurviveGameState::StaticClass();
	PlayerStateClass = AMainSurviveGamePlayerState::StaticClass();

}