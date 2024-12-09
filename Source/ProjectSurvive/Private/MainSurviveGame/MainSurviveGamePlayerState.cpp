// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com


#include "MainSurviveGame/MainSurviveGamePlayerState.h"
#include "Engine/DataTable.h"
#include "Net/UnrealNetwork.h"

AMainSurviveGamePlayerState::AMainSurviveGamePlayerState()
{
	// Initialization
	CurrentCharacterState.Level = 1;

	// Get personal state table
	static ConstructorHelpers::FObjectFinder<UDataTable> STATEDATATABLE(TEXT("/Game/ProjectS/Data/State/DT_BaseCharacterState.DT_BaseCharacterState"));
	if (STATEDATATABLE.Succeeded())
	{
		PersonalStateTable = STATEDATATABLE.Object;
	}

	// Get personal stat table
	static ConstructorHelpers::FObjectFinder<UDataTable> STATDATATABLE(TEXT("/Game/ProjectS/Data/State/DT_BaseCharacterStat.DT_BaseCharacterStat"));
	if (STATDATATABLE.Succeeded())
	{
		PersonalStatTable = STATDATATABLE.Object;
	}

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

void AMainSurviveGamePlayerState::ServerChangedCurrentMP_Implementation(const float InCurrentMP)
{
	
}

void AMainSurviveGamePlayerState::ServerChangedMaxMP_Implementation(const float InMaxMP)
{
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

void AMainSurviveGamePlayerState::MulticastChangedCurrentMP_Implementation(const float InCurrentMP)
{
}

void AMainSurviveGamePlayerState::MulticastChangedMaxMP_Implementation(const float InMaxMP)
{
}

// Multicast - Execute to change exp amount
void AMainSurviveGamePlayerState::MulticastChangedExp_Implementation(const float InAmountExp)
{
	// Exp update
	CurrentCharacterState.MaxExp += InAmountExp;

	// Need to level up
	if (CurrentCharacterState.MaxExp > CharacterMaxState.MaxExp)
	{
		LevelUp(CurrentCharacterState.Level + 1);
	}
	// Boradcast to update exp
	if (OnChangeExp.IsBound())
	{
		OnChangeExp.Broadcast(CurrentCharacterState.MaxExp);
	}
}


// Get personal state information by specific level
FCharacterState* AMainSurviveGamePlayerState::GetCharacterStateByLevel(int32 InLevel)
{
	return PersonalStateTable->FindRow<FCharacterState>(*FString::FromInt(InLevel), TEXT(""));
}

// Get personal stat information by specific level
FCharacterStat* AMainSurviveGamePlayerState::GetCharacterStatByLevel(int32 InLevel)
{
	return PersonalStatTable->FindRow<FCharacterStat>(*FString::FromInt(InLevel), TEXT(""));
}

// Level Up
void AMainSurviveGamePlayerState::LevelUp(int32 InLevel)
{
	// Level update
	CurrentCharacterState.Level = InLevel;
	CharacterMaxState.Level = InLevel;

	FCharacterState* NextLevelState = GetCharacterStateByLevel(InLevel);
	FCharacterStat* NextLevelStat = GetCharacterStatByLevel(InLevel);
	// // Add as much as the addition increase value when max value is increased. But, it isn't work at level 1.
	if (InLevel != 1)
	{
		// Modify Exp
		CurrentCharacterState.MaxExp -= CharacterMaxState.MaxExp;

		CharacterMaxState.MaxExp = NextLevelState->MaxExp;

		// Increse Current HP
		CurrentCharacterState.MaxHP += (NextLevelState->MaxHP - CurrentCharacterState.MaxHP);
		// Increse Current MP
		CurrentCharacterState.MaxMP += (NextLevelState->MaxMP - CurrentCharacterState.MaxMP);
		// Increse Max HP
		CharacterMaxState.MaxHP += (NextLevelState->MaxHP - CurrentCharacterState.MaxHP);
		// Increse Max MP
		CharacterMaxState.MaxMP += (NextLevelState->MaxMP - CurrentCharacterState.MaxMP);
	}
	// Level 1.
	else
	{
		// Current HP
		CurrentCharacterState.MaxHP = NextLevelState->MaxHP;
		// Current MP
		CurrentCharacterState.MaxMP = NextLevelState->MaxMP;
		// Current Exp
		CurrentCharacterState.MaxExp = 0;
		// Max HP
		CharacterMaxState.MaxHP = NextLevelState->MaxHP;
		// Max MP
		CharacterMaxState.MaxMP = NextLevelState->MaxMP;
		// Max Exp
		CharacterMaxState.MaxExp = NextLevelState->MaxExp;
	}
	// Notify to change
	if (OnChangeCurrentHP.IsBound())
	{
		OnChangeCurrentHP.Broadcast(CurrentCharacterState.MaxHP);
	}
	if (OnChangeMaxHP.IsBound())
	{
		OnChangeMaxHP.Broadcast(CharacterMaxState.MaxHP);
	}
	if (OnChangeCurrentMP.IsBound())
	{
		OnChangeCurrentMP.Broadcast(CurrentCharacterState.MaxMP);
	}
	if (OnChangeMaxMP.IsBound())
	{
		OnChangeMaxMP.Broadcast(CharacterMaxState.MaxMP);
	}
	if (OnChangeExp.IsBound())
	{
		OnChangeExp.Broadcast(CurrentCharacterState.MaxExp);
	}
}
