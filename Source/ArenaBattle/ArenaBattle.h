// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/*
**CoreMinimal.h**는 엔진의 핵심 기능과 데이터를 모두 포함하는 반면,
**EngineMinimal.h**는 게임 엔진에 필요한 최소한의 기능만을 제공합니다
*/
#include "EngineMinimal.h"

/*
#define DECLARE_LOG_CATEGORY_EXTERN(CategoryName, DefaultVerbosity, CompileTimeVerbosity) \
		extern struct FLogCategory##CategoryName : public FLogCategory<ELogVerbosity::DefaultVerbosity, ELogVerbosity::CompileTimeVerbosity> \
		{ \
			FORCEINLINE FLogCategory##CategoryName() : FLogCategory(TEXT(#CategoryName)) {} \
		} CategoryName;
*/
DECLARE_LOG_CATEGORY_EXTERN(ArenaBattle, Log, All);

// ABLOG_S: 코드가 들어있는 파일 이름과 함수, 그리고 라인 정보를 추가해 ArenaBattle 카테고리로 로그를 남긴다.
// 로그를 사용한 함수의 실행 시점을 파악할 때 유용하다.
#define ABLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

// ABLOG_S 정보에 형식 문자열로 추가 정보를 지정해 로그를 남긴다.
// Verbosity 심각도 수준
#define ABLOG_S(Verbosity) UE_LOG(ArenaBattle, Verbosity, TEXT("%s"), *ABLOG_CALLINFO)



// 원래 형태는 다음과 같다. 문제는 3가지 정보 이름, ID, 위치를 전달하지 못했음. 함수 이름과 라인번호는 제대로 %s 로 넘어와서 출력함 근데
// #define ABLOG(Verbosity, Format, ...) UE_LOG(ArenaBattle, Verbosity, TEXT("%s"), *ABLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
// 추가적인 정보 *FString::Printf(Format, ##__VA_ARGS__) 에서는 포맷 문자열을 잘못 처리해서 제대로 출력 X
// 그래서 함수 이름과 라인번호를 출력한 후에 바로 뒤에 추가 정보 포맷에 맞춰 출력
// 추가 정보들이 포맷에 맞춰 자동으로 전달
// 처음에는 매크로가 정보를 나눠서 처리하다가, 추가 정보를 제대로 전달하지 못했어요.
// 매크로를 단순하게 바꾼 후, 함수 이름과 라인 번호, 추가 정보가 모두 제대로 연결되어 출력되었어요.
#define ABLOG(Verbosity, Format, ...) UE_LOG(ArenaBattle, Verbosity, TEXT("%s: ") Format, *ABLOG_CALLINFO, ##__VA_ARGS__)