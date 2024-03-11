// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StateGoTestControl.hpp"
#include "StateGoTestActor.generated.h"

UCLASS()
class UPROJECT_API AStateGoTestActor : public AActor
{
	GENERATED_BODY()
	
	StateGoData m_data;
	StateGoTestControl *m_control;

public:	
	// Sets default values for this actor's properties
	AStateGoTestActor();
	~AStateGoTestActor()
	{
		if (m_control!=nullptr) delete m_control;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
