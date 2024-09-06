// Fill out your copyright notice in the Description page of Project Settings.

#include "Fountain.h"


// Sets default values
AFountain::AFountain()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// Tick 기능을 제거했지만 무브먼트 컴포넌트가 이를 대신 해 틱마다 액터를 회전.
	PrimaryActorTick.bCanEverTick = false;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY")); // C.D.S 클래스를 사용 USMC로 설정하는데 텍스트는 중복 피하기 위해 설정(자세히 잘 모르겠음)
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("LIGHT"));
	Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SPLASH"));
	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));

	RootComponent = Body; // 루트 컴포넌트
	Water->SetupAttachment(Body); // 물이 바디에 붙게 설정
	Light->SetupAttachment(Body);
	Splash->SetupAttachment(Body);
	// 전부 body 컴포넌트에 붙어있음

	Water->SetRelativeLocation(FVector(0.0f, 0.0f, 135.0f));
	Light->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));
	Splash->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));
	// 고정 높이 위치 setrelativelocation 함수 사용

	// 원래 컨퍼런스 복사하면 -> StaticMesh'/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01'
	// ConstructorHelpers 클래스의 FObjectFinder를 사용해 변수 선언 변수에 경로 값 전달
	// 다소 복잡한 규칙을 가지고 있음
	// {오브젝트 타입}'{폴더명}/{파일명}.{애셋명}'
	// 위 경로는 좀 쉽게 적은거임 이걸로 바꿀려고함 이책에서
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_BODY(TEXT("/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01"));
	// 애셋의경로가 변경되어 에러가 날수있음 허나 경로가 일정하면 그럴일이 없기 때문에 static을 붙임



	/** 그러고 나서 변수의 Object멤버 값을 사용하면 애셋에 대한 포인터를 가져올 수 있다.
	선언한 변수는 스태틱메시 애셋의 포인터고, 이를 스태틱메시 컴포넌트의 setStaticMesh 함수에 전달하면 C++ 코드로 애셋을 로딩하는 기능이 비로서 완성된다.
	*/
	if (SM_BODY.Succeeded()) {
		Body->SetStaticMesh(SM_BODY.Object);
	}
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_WATER(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Meshes/Env/SM_Plains_Fountain_02.SM_Plains_Fountain_02"));

	if (SM_WATER.Succeeded()) {
		Water->SetStaticMesh(SM_WATER.Object);
	}

	// 위에 2개는 staticmesh로 취급되는데 이건 파티클시스템에 template을 변경하는거라 이와 같이 변경
	// 이건 이펙트라 U파티클시스템 이어서 PS = ParticleSystem
	static ConstructorHelpers::FObjectFinder<UParticleSystem>PS_SPLASH(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Ambient/Water/P_Water_Fountain_Splash_Base_01.P_Water_Fountain_Splash_Base_01"));

	if (PS_SPLASH.Succeeded()) {
		Splash->SetTemplate(PS_SPLASH.Object);
	}

	// 속성의 기본값을 생성자에서 초기화
	RotateSpeed = 30.0f;
	// 무브먼트 컴포넌트는 액터의 현재 위치와 관계없이 액터에 지정된 움직임 기능을 제공하기에 독립적으로 부착.
	Movement->RotationRate = FRotator(0.0f, RotateSpeed, 0.0f);
}


// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	Super::BeginPlay();
	
	ABLOG_S(Warning);
	ABLOG(Warning, TEXT("Actor Name : %s, ID : %d, Location X : %.3f"), *GetName(), ID, GetActorLocation().X);
	// UE_LOG(ArenaBattle, Warning, TEXT("Actor Name : %s, ID : %d, Location X : %.3f"), *GetName(), ID, GetActorLocation().X);
}

// Called every frame
void AFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// AddActorLocalRotation 함수를 사용해 분수대가 틱마다 회전하도록 코드를 제작.
	AddActorLocalRotation(FRotator(0.0f, RotateSpeed*DeltaTime, 0.0f));
	// FRotator 는 (pitch , Yaw , Roll ) 로 돌아간다.
}

void AFountain::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	ABLOG_S(Warning);
}

void AFountain::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}