// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/*
**CoreMinimal.h**�� ������ �ٽ� ��ɰ� �����͸� ��� �����ϴ� �ݸ�,
**EngineMinimal.h**�� ���� ������ �ʿ��� �ּ����� ��ɸ��� �����մϴ�
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

// ABLOG_S: �ڵ尡 ����ִ� ���� �̸��� �Լ�, �׸��� ���� ������ �߰��� ArenaBattle ī�װ��� �α׸� �����.
// �α׸� ����� �Լ��� ���� ������ �ľ��� �� �����ϴ�.
#define ABLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

// ABLOG_S ������ ���� ���ڿ��� �߰� ������ ������ �α׸� �����.
// Verbosity �ɰ��� ����
#define ABLOG_S(Verbosity) UE_LOG(ArenaBattle, Verbosity, TEXT("%s"), *ABLOG_CALLINFO)



// ���� ���´� ������ ����. ������ 3���� ���� �̸�, ID, ��ġ�� �������� ������. �Լ� �̸��� ���ι�ȣ�� ����� %s �� �Ѿ�ͼ� ����� �ٵ�
// #define ABLOG(Verbosity, Format, ...) UE_LOG(ArenaBattle, Verbosity, TEXT("%s"), *ABLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
// �߰����� ���� *FString::Printf(Format, ##__VA_ARGS__) ������ ���� ���ڿ��� �߸� ó���ؼ� ����� ��� X
// �׷��� �Լ� �̸��� ���ι�ȣ�� ����� �Ŀ� �ٷ� �ڿ� �߰� ���� ���˿� ���� ���
// �߰� �������� ���˿� ���� �ڵ����� ����
// ó������ ��ũ�ΰ� ������ ������ ó���ϴٰ�, �߰� ������ ����� �������� ���߾��.
// ��ũ�θ� �ܼ��ϰ� �ٲ� ��, �Լ� �̸��� ���� ��ȣ, �߰� ������ ��� ����� ����Ǿ� ��µǾ����.
#define ABLOG(Verbosity, Format, ...) UE_LOG(ArenaBattle, Verbosity, TEXT("%s: ") Format, *ABLOG_CALLINFO, ##__VA_ARGS__)