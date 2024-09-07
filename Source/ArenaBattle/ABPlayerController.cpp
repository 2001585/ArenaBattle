// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPlayerController.h"



void AABPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPlayerController::Possess(APawn* aPawn)
{
	ABLOG_S(Warning);
	Super::Possess(aPawn);
}


// ABPlayerController.h에 선언한 BeginPlay 구현
// 플레이어 컨트롤러에게 UI를 배제하고 게임에게만 입력을 전달하도록 명령
void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);

}