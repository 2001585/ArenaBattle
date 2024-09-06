// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ArenaBattle.h"
// #include "EngineMinimal.h"  
// 분수대 구조물의 비주얼과 충돌을 담당하는 스태틱메시 컴포넌트와 물의 비주얼을 담당할 스태틱메시 컴포넌트로                             
//구성 이 두 개의 스태틱메시 컴포넌트를 가지려면 분수대 액터의 멤버 변수로 두 개의 UStaticMeshComponent 클래스의 포인터선언

#include "GameFramework/Actor.h"

// RotateSpeed라는 변수를 만들어서 회전 시켰다면 이거는 RotatingMovement 컴포넌트를 써서 같은 움직임 구현
#include "GameFramework/RotatingMovementComponent.h"
// .generated.h 는 맨 마지막에 있어야함.
#include "Fountain.generated.h"

UCLASS()
class ARENABATTLE_API AFountain : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	URotatingMovementComponent *Movement;
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned

	/*
	준비된 액터가 게임에 참여, 액터는 자신에게 주어진 역할을 수행
	언리얼 엔진은 액터가 게임에 참여할 때 액터의 BeginPlay함수를 호출하고, 매 프레임마다 액터의 Tick 함수를 호출
	게임에서 더 이상 액터의 역할이 없어지면, 액터는 게임에서 퇴장하고 메모리에서 소멸.
	액터가 게임에서 퇴장할 때 언리얼 엔진은 액터의 EndPlay를 호출
	*/
	virtual void BeginPlay() override;

	/*
	virtual?
	언리얼 엔진이 제공하는 액터 클래스에는 액터 동작의 뼈대를 이루는 이벤트 함수들이 선언돼 있고,
	이들을 상속 받을 수 있도록 가상 함수(virtual function)로 선언돼 있다.
	*/
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// 액터의 속한 모든 컴포넌트의 세팅이 완료되면 언리얼 엔진은 액터의 PostInitializeCompents 함수 호출
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// EngineMinial.h로 포인터 선언했으므로 참조하기 위한 클래스 그리고 컴포넌트 선언
	

	// UPROPERTY()는 객체 소멸 후 메모리 관리 문제 안되게 선언해줘야 한다. 
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Body;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Water;

	UPROPERTY(VisibleAnywhere)
	UPointLightComponent *Light;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent *Splash;

	UPROPERTY(EditAnywhere, Category = ID)
	int32 ID;


	// 움직이는 액터의 설계
	// 회전시키고자 할 각속도의 값을 변수로 지정 'RotateSpeed'
	// 정보 값 유형이라 에디터에서 수정할 수 있게 UPROPERTY 매크로에 EditAnywhere 키워드
	// 근데 변수 생성할 때 데이터 은닉도 고려해야함
	// 그래서 private 로 했는데 이걸로 하면 편집 못해 그래서
	// AllowPrivateAccess 라는 META키워드 추가하면 에디터에서 이를 편집함과 동시에 변수 데이터 은닉
	// 고로 캡슐화 가능.
	/*
	Meta는 언리얼 엔진에서 UPROPERTY나 UFUNCTION 같은 매크로에 추가적인 **메타데이터(정보)**를 제공할 수 있는 옵션. 
	이 메타데이터는 에디터에서 변수나 함수의 동작을 제어하거나 특정 조건을 부여하는 데 사용
	*/
private:
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
		float RotateSpeed;
};
