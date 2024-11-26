// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogProjectSurvive, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(Project_S, Log, All);

// 호출 지점 출력
#define PS_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

// 간단한 로그 출력
#define PS_SIMPLE(Verbosity) UE_LOG(K_YG, Verbosity, TEXT("%s"), *PS_CALLINFO)

// 텍스트 형식을 추가한 로그 출력
#define PS_UELOG(Verbosity, Format, ...) UE_LOG(K_YG, Verbosity, TEXT("%s %s"), *PS_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

// Assertion : 확인
#define PS_CHECK(Expr, ...) {if(!(Expr)) { PS_UELOG(Error, TEXT("Assertion : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; }}

// Simple Check : Not Assertion : 단순 조건문 확인 - return 코드 줄이는 매크로
#define PS_SIMPLE_CHECK(Expr, ...) {if(!(Expr)) { PS_UELOG(Warning, TEXT("The function is pre-termination : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; }}

// Print text on viewport
#define PS_PRINT(Time, Color, Format, ...) {if(GEngine){GEngine->AddOnScreenDebugMessage(-1, Time, Color, FString::Printf(Format, ##__VA_ARGS__));}}

// Print text on viewport during a frame
#define PS_PRINT_A_FRAME(Color, Format, ...){if(GEngine){GEngine->AddOnScreenDebugMessage(-1, FApp::GetDeltaTime(), Color, FString::Printf(Format, ##__VA_ARGS__));}}