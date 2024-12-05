// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com


#include "MainSurviveGame/MainSurviveGamePlayerState.h"

AMainSurviveGamePlayerState::AMainSurviveGamePlayerState()
{
	// Initialization
	CurrentCharacterState.Level = 1;
}

// To Server - Execute to change current hp amount
void AMainSurviveGamePlayerState::ServerChangedCurrentHP_Implementation(const float InAmountHP)
{
	MulticastChangedCurrentHP(InAmountHP);
}

// To Server - Execute to change max hp amount
void AMainSurviveGamePlayerState::ServerChangedMaxHP_Implementation(const float InMaxHP)
{
	MulticastChangedMaxHP(InMaxHP);
}

// To Server - Execute to change exp amount
void AMainSurviveGamePlayerState::ServerChangedExp_Implementation(const float InAmountExp)
{
	MulticastChangedExp(InAmountExp);
}

// Multicast - Execute to change current HP amount
void AMainSurviveGamePlayerState::MulticastChangedCurrentHP_Implementation(const float InCurrentHP)
{
	// Current hp update
	CurrentCharacterState.MaxHP = InCurrentHP;
	if (OnChangeCurrentHP.IsBound())
	{
		OnChangeCurrentHP.Broadcast(InCurrentHP);
	}
}

// Multicast - Execute to change max HP amount
void AMainSurviveGamePlayerState::MulticastChangedMaxHP_Implementation(const float InMaxHP)
{
	// Max hp update
	CharacterMaxState.MaxHP = InMaxHP;
	if (OnChangeMaxHP.IsBound())
	{
		OnChangeMaxHP.Broadcast(InMaxHP);
	}
}

// Multicast - Execute to change exp amount
void AMainSurviveGamePlayerState::MulticastChangedExp_Implementation(const float InAmountExp)
{
	// Exp update
	CurrentCharacterState.MaxExp = InAmountExp;
	if (OnChangeExp.IsBound())
	{
		OnChangeExp.Broadcast(InAmountExp);
	}
}

// Multicast - Execute to change level
void AMainSurviveGamePlayerState::MulticastChangedLevel_Implementation(const float InNewLevel)
{
	// Level update
	CurrentCharacterState.Level = InNewLevel;
	CharacterMaxState.Level = InNewLevel;
	if (OnChangeExp.IsBound())
	{
		OnChangeExp.Broadcast(InNewLevel);
	}
}
