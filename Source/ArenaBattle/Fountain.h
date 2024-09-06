// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ArenaBattle.h"
// #include "EngineMinimal.h"  
// �м��� �������� ���־�� �浹�� ����ϴ� ����ƽ�޽� ������Ʈ�� ���� ���־��� ����� ����ƽ�޽� ������Ʈ��                             
//���� �� �� ���� ����ƽ�޽� ������Ʈ�� �������� �м��� ������ ��� ������ �� ���� UStaticMeshComponent Ŭ������ �����ͼ���

#include "GameFramework/Actor.h"

// RotateSpeed��� ������ ���� ȸ�� ���״ٸ� �̰Ŵ� RotatingMovement ������Ʈ�� �Ἥ ���� ������ ����
#include "GameFramework/RotatingMovementComponent.h"
// .generated.h �� �� �������� �־����.
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
	�غ�� ���Ͱ� ���ӿ� ����, ���ʹ� �ڽſ��� �־��� ������ ����
	�𸮾� ������ ���Ͱ� ���ӿ� ������ �� ������ BeginPlay�Լ��� ȣ���ϰ�, �� �����Ӹ��� ������ Tick �Լ��� ȣ��
	���ӿ��� �� �̻� ������ ������ ��������, ���ʹ� ���ӿ��� �����ϰ� �޸𸮿��� �Ҹ�.
	���Ͱ� ���ӿ��� ������ �� �𸮾� ������ ������ EndPlay�� ȣ��
	*/
	virtual void BeginPlay() override;

	/*
	virtual?
	�𸮾� ������ �����ϴ� ���� Ŭ�������� ���� ������ ���븦 �̷�� �̺�Ʈ �Լ����� ����� �ְ�,
	�̵��� ��� ���� �� �ֵ��� ���� �Լ�(virtual function)�� ����� �ִ�.
	*/
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// ������ ���� ��� ������Ʈ�� ������ �Ϸ�Ǹ� �𸮾� ������ ������ PostInitializeCompents �Լ� ȣ��
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// EngineMinial.h�� ������ ���������Ƿ� �����ϱ� ���� Ŭ���� �׸��� ������Ʈ ����
	

	// UPROPERTY()�� ��ü �Ҹ� �� �޸� ���� ���� �ȵǰ� ��������� �Ѵ�. 
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


	// �����̴� ������ ����
	// ȸ����Ű���� �� ���ӵ��� ���� ������ ���� 'RotateSpeed'
	// ���� �� �����̶� �����Ϳ��� ������ �� �ְ� UPROPERTY ��ũ�ο� EditAnywhere Ű����
	// �ٵ� ���� ������ �� ������ ���е� ����ؾ���
	// �׷��� private �� �ߴµ� �̰ɷ� �ϸ� ���� ���� �׷���
	// AllowPrivateAccess ��� METAŰ���� �߰��ϸ� �����Ϳ��� �̸� �����԰� ���ÿ� ���� ������ ����
	// ��� ĸ��ȭ ����.
	/*
	Meta�� �𸮾� �������� UPROPERTY�� UFUNCTION ���� ��ũ�ο� �߰����� **��Ÿ������(����)**�� ������ �� �ִ� �ɼ�. 
	�� ��Ÿ�����ʹ� �����Ϳ��� ������ �Լ��� ������ �����ϰų� Ư�� ������ �ο��ϴ� �� ���
	*/
private:
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
		float RotateSpeed;
};
