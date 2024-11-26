// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#pragma once

#include "../../ProjectSurvive.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "PerosnalCharacterData.generated.h"

/**
 * 
 */

// The structure which is related about health, mana, etc..
USTRUCT(BlueprintType)
struct FCharacterState : public FTableRowBase
{
	GENERATED_BODY()
	
	// Character's current level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|State")
	float Level;
	
	// Character's max health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|State")
	float MaxHP;

	// Character's max mana amonut
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|State")
	float MaxMP;

	// Amount of character's level up
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|State")
	int32 MaxExp;

	// Character's recovery health for a second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|State")
	float RecoveryHP;

	// Character's recovery mana for a second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|State")
	float RecoveryMP;
};

// The struct which is related about attack amount, range, etc..
USTRUCT(BlueprintType)
struct FCharacterStat : public FTableRowBase
{
	GENERATED_BODY()
	
	// Character's attack min amount
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Stat")
	float MinAttackAmount;

	// Character's attack max amount
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Stat")
	float MaxAttackAmount;

	// Character's valid attack range
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Stat")
	float AttackRange;

	// Character's max movement 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Stat")
	float MoveVelocity;

	// Character's defense value which reduces any attack amount
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Stat")
	float DefenseValue;

	// Character's default attack period
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Stat")
	float BaseAttackPeriod;

	// Character's default sight range
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Stat")
	float SightRange;
};

UCLASS()
class PROJECTSURVIVE_API UPerosnalCharacterData : public UObject
{
	GENERATED_BODY()
	
};
