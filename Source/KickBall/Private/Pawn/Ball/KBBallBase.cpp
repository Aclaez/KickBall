// Copyright Aclaez Games, Inc. All Rights Reserved.


#include "Pawn/Ball/KBBallBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

AKBBallBase::AKBBallBase()
{
	PrimaryActorTick.bCanEverTick = true;	

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMeshComponent);
	StaticMeshComponent->SetSimulatePhysics(true);
	StaticMeshComponent->SetLinearDamping(-1.0f);
}

void AKBBallBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKBBallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

