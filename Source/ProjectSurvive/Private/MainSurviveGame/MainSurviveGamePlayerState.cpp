// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com


#include "MainSurviveGame/MainSurviveGamePlayerState.h"

AMainSurviveGamePlayerState::AMainSurviveGamePlayerState()
{
	// Initialization
	CurrentCharacterState.Level = 1;
}

// To Server - Execute to change hp amount
void AMainSurviveGamePlayerState::ServerChangedHP_Implementation(const float InAmountHP)
{

}

// To Server - Execute to change exp amount
void AMainSurviveGamePlayerState::ServerChangedExp_Implementation(const float InAmountExp)
{

}

// Multicast - Execute to change HP amount
void AMainSurviveGamePlayerState::MulticastChangedHP_Implementation(const float InAmountHP)
{

}

// Multicast - Execute to change exp amount
void AMainSurviveGamePlayerState::MulticastChangedExp_Implementation(const float InAmountExp)
{

}

// Multicast - Execute to change level
void AMainSurviveGamePlayerState::MulticastChangedLevel_Implementation(const float InNewLevel)
{

}
