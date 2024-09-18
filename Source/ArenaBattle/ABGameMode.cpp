// Fill out your copyright notice in the Description page of Project Settings.

#include "ABGameMode.h"
#include "ABCharacter.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode()
{
	DefaultPawnClass = AABCharacter::StaticClass();

	// 새로운 플레이어 컨트롤러의 코드가 생성되면 게임 모드의 생성자에서 PlayerController 속성을 ABPlayerController
	// 의 클래스 값으로 변경한다.
	PlayerControllerClass = AABPlayerController::StaticClass();
}



void AABGameMode::PostLogin(APlayerController* NewPlayer)
{
	ABLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	ABLOG(Warning, TEXT("PostLogin End"));
}

