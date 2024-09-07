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

void AABPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis(TEXT("LeftRight"), this, &AABPlayerController::LeftRight);
}

void AABPlayerController::LeftRight(float NewAxisValue)
{
	// Do Nothing!
}