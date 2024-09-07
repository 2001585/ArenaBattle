// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	virtual void PostInitializeComponents() override;
	virtual void Possess(APawn* aPawn) override;



	// 플레이 눌러서 콘텐츠 테스트할 때 매번 언리얼 에디터 뷰포트 클릭하는 불편함 없애기
protected:
	virtual void BeginPlay() override;

};
