// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/GameModeBase.h"
#include "ABGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	// 앞으로 게임의 DefaultPawn 속성에 우리가 제작한 ABPawn을 지정한다.\
	// 주의할 점은 ABPawn 액터를 생서하고 이를 지정하는 것이 아니라 ABPawn의 클래스 정보를 지정함
	// 멀티플레이까지 고려한다면 게임에 몇 명의 플레이어가 들어올지 모르기 때문에 미리 폰 X
public:
	AABGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;
	
};
