// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogProjectSurvive, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(Project_S, Log, All);

// ȣ�� ���� ���
#define PS_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

// ������ �α� ���
#define PS_SIMPLE(Verbosity) UE_LOG(K_YG, Verbosity, TEXT("%s"), *PS_CALLINFO)

// �ؽ�Ʈ ������ �߰��� �α� ���
#define PS_UELOG(Verbosity, Format, ...) UE_LOG(K_YG, Verbosity, TEXT("%s %s"), *PS_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

// Assertion : Ȯ��
#define PS_CHECK(Expr, ...) {if(!(Expr)) { PS_UELOG(Error, TEXT("Assertion : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; }}

// Simple Check : Not Assertion : �ܼ� ���ǹ� Ȯ�� - return �ڵ� ���̴� ��ũ��
#define PS_SIMPLE_CHECK(Expr, ...) {if(!(Expr)) { PS_UELOG(Warning, TEXT("The function is pre-termination : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; }}

// Print text on viewport
#define PS_PRINT(Time, Color, Format, ...) {if(GEngine){GEngine->AddOnScreenDebugMessage(-1, Time, Color, FString::Printf(Format, ##__VA_ARGS__));}}

// Print text on viewport during a frame
#define PS_PRINT_A_FRAME(Color, Format, ...){if(GEngine){GEngine->AddOnScreenDebugMessage(-1, FApp::GetDeltaTime(), Color, FString::Printf(Format, ##__VA_ARGS__));}}