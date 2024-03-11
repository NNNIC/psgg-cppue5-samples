// Fill out your copyright notice in the Description page of Project Settings.


#include "StateGoTestActor.h"
#include "StateGoTestControl.hpp"

// Sets default values
AStateGoTestActor::AStateGoTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_control = new StateGoTestControl(this);

}

// Called when the game starts or when spawned
void AStateGoTestActor::BeginPlay()
{
	Super::BeginPlay();
	m_control->PreemptiveInit(m_data);	
}

// Called every frame
void AStateGoTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_control != nullptr) {
		int  r = m_control->PreemptiveCallUpdate(m_data);
		if (r < 0 )
		{
			delete m_control;
			m_control = nullptr;	
		}
	}
}

