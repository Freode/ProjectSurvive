// Copyright 2024. Jeonghoe22(Freode) All rights reserved.
// Github : https://github.com/Freode/ProjectSurvive
// Email : jeonghoe22@gmail.com

#pragma once

#include "../../ProjectSurvive.h"
#include "GameFramework/PlayerState.h"
#include "Data/PerosnalCharacterData.h"
#include "MainSurviveGamePlayerState.generated.h"

// Declare delegate
DECLARE_MULTICAST_DELEGATE_OneParam(FOnFloatMulticastDelegate, float);

/**
 * 
 */
UCLASS()
class PROJECTSURVIVE_API AMainSurviveGamePlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:

	AMainSurviveGamePlayerState();

	// ==============================
	// ====== RPC - To Server =======

	// To Server - Change Current HP amount
	UFUNCTION(Server, Reliable)
	void ServerChangedCurrentHP(const float InCurrentHP);

	// To Server - Change Max HP amount
	UFUNCTION(Server, Reliable)
	void ServerChangedMaxHP(const float InMaxHP);

	// To Server - Change Current MP amount
	UFUNCTION(Server, Reliable)
	void ServerChangedCurrentMP(const float InCurrentMP);

	// To Server - Change Max MP amount
	UFUNCTION(Server, Reliable)
	void ServerChangedMaxMP(const float InMaxMP);

	// To Server - Change exp amount
	UFUNCTION(Server, Reliable)
	void ServerChangedExp(const float InAmountExp);

	// ==============================
	// ====== RPC - Multicast =======

	// Multicast - Change current HP amount
	UFUNCTION(NetMulticast, Reliable)
	void MulticastChangedCurrentHP(const float InCurrentHP);

	// Multicast - Change max MP amount
	UFUNCTION(NetMulticast, Reliable)
	void MulticastChangedMaxHP(const float InMaxHP);

	// Multicast - Change current MP amount
	UFUNCTION(NetMulticast, Reliable)
	void MulticastChangedCurrentMP(const float InCurrentMP);

	// Multicast - Change max MP amount
	UFUNCTION(NetMulticast, Reliable)
	void MulticastChangedMaxMP(const float InMaxMP);

	// Multicast - Change exp amount
	UFUNCTION(NetMulticast, Reliable)
	void MulticastChangedExp(const float InAmountExp);

	// ==============================
	// ========== Getter ============

	UFUNCTION(BlueprintCallable, Category = "Character|Value")
	FORCEINLINE FCharacterStat GetCharacterBaseStat() const { return CharacterBaseStat; }

	UFUNCTION(BlueprintCallable, Category = "Character|Value")
	FORCEINLINE FCharacterStat GetCurrentCharacterStat() const { return CurrentCharacterStat; }

	UFUNCTION(BlueprintCallable, Category = "Character|Value")
	FORCEINLINE FCharacterState GetCharacterMaxState() const { return CharacterMaxState; }

	UFUNCTION(BlueprintCallable, Category = "Character|Value")
	FORCEINLINE FCharacterState GetCurrentCharacterState() const { return CurrentCharacterState; }

	// ==============================
	// ========== Setter ============

	UFUNCTION(BlueprintCallable, Category = "Character|Value")
	FORCEINLINE void SetCharacterBaseStat(const FCharacterStat InCharacterBaseStat) { CharacterBaseStat = InCharacterBaseStat; }

	UFUNCTION(BlueprintCallable, Category = "Character|Value")
	FORCEINLINE void SetCurrentCharacterStat(const FCharacterStat InCurrentCharacterBaseStat) { CurrentCharacterStat = InCurrentCharacterBaseStat; }

	UFUNCTION(BlueprintCallable, Category = "Character|Value")
	FORCEINLINE void SetCharacterMaxState(const FCharacterState InCharacterMaxState) { CharacterMaxState = InCharacterMaxState; }

	UFUNCTION(BlueprintCallable, Category = "Character|Value")
	FORCEINLINE void SetCurrentCharacterState(const FCharacterState InCurrentCharacterState) { CurrentCharacterState = InCurrentCharacterState; }

	// ==============================
	// ========= Delegate ===========

	FOnFloatMulticastDelegate OnChangeCurrentHP;
	FOnFloatMulticastDelegate OnChangeMaxHP;
	FOnFloatMulticastDelegate OnChangeCurrentMP;
	FOnFloatMulticastDelegate OnChangeMaxMP;
	FOnFloatMulticastDelegate OnChangeExp;
	FOnFloatMulticastDelegate OnChangeMaxExp;

protected:

	// ==============================
	// ====== RPC - To Server =======

	// To Server - Execute to change current hp amount
	void ServerChangedCurrentHP_Implementation(const float InCurrentHP);

	// To Server - Execute to change max hp amount
	void ServerChangedMaxHP_Implementation(const float InMaxHP);

	// To Server - Execute to change current mp amount
	void ServerChangedCurrentMP_Implementation(const float InCurrentMP);

	// To Server - Execute to change max mp amount
	void ServerChangedMaxMP_Implementation(const float InMaxMP);

	// To Server - Execute to change exp amount
	void ServerChangedExp_Implementation(const float InAmountExp);

	// ==============================
	// ====== RPC - Multicast =======

	// Multicast - Execute to change current HP amount
	void MulticastChangedCurrentHP_Implementation(const float InCurrentHP);

	// Multicast - Execute to change max HP amount
	void MulticastChangedMaxHP_Implementation(const float InMaxHP);

	// Multicast - Execute to change current MP amount
	void MulticastChangedCurrentMP_Implementation(const float InCurrentMP);

	// Multicast - Execute to change max MP amount
	void MulticastChangedMaxMP_Implementation(const float InMaxMP);

	// Multicast - Execute to change exp amount
	void MulticastChangedExp_Implementation(const float InAmountExp);

private:

	// Get personal state information by specific level
	FCharacterState* GetCharacterStateByLevel(int32 InLevel);

	// Get personal stat information by specific level
	FCharacterStat* GetCharacterStatByLevel(int32 InLevel);

	// Level Up
	void LevelUp(int32 InLevel);

	// Current character's base stat
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Value", Meta = (AllowPrivateAccess = true))
	FCharacterStat CharacterBaseStat;

	// Current character's stat which is reflexed by anything like item, weapon etc..
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Value", Meta = (AllowPrivateAccess = true))
	FCharacterStat CurrentCharacterStat;

	// Current character's max state
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Value", Meta = (AllowPrivateAccess = true))
	FCharacterState CharacterMaxState;

	// Current character's current state
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Value", Meta = (AllowPrivateAccess = true))
	FCharacterState CurrentCharacterState;
	
	// State table
	UPROPERTY()
	class UDataTable* PersonalStateTable;

	// Stat Table
	UPROPERTY()
	class UDataTable* PersonalStatTable;
};
