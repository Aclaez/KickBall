// Copyright Aclaez Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KBBallBase.generated.h"

UCLASS()
class KICKBALL_API AKBBallBase : public AActor
{
	GENERATED_BODY()
	
public:
	AKBBallBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
