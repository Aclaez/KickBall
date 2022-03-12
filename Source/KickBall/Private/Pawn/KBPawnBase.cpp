// Copyright Aclaez Games, Inc. All Rights Reserved.


#include "Pawn/KBPawnBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"

AKBPawnBase::AKBPawnBase()
{
	CapsuleCollisionComponent = CreateDefaultSubobject<UCapsuleComponent>("CapsuleCollision");
	CapsuleCollisionComponent->SetCapsuleSize(10, 10);
	SetRootComponent(CapsuleCollisionComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMeshComponent->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;
}

void AKBPawnBase::KickStart()
{
	IsKickStart = true;
}

void AKBPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKBPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Display, TEXT("Rotation:%f"), GetActorRotation().Pitch);

	if (IsKickStart)
	{
		float Modifier = 0.0f;
		float RotationOne = GetActorRotation().Pitch;

		if (IsRevertDirection)
		{
			Modifier -= KickerSpeed;

			if (RotationOne <= KickerSpeed)
			{
				IsKickStart = false;
				IsRevertDirection = false;
				Modifier = -RotationOne;
			}
		}
		else
		{
			Modifier += KickerSpeed;

			if (RotationOne >= 70.0f)
			{
				IsRevertDirection = true;
			}
		}

		SetActorRotation(GetActorRotation() + FRotator(Modifier, 0.0f, 0.0f));
	}
}
