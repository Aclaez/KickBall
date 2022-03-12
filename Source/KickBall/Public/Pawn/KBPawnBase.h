// Copyright Aclaez Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KBPawnBase.generated.h"

UCLASS()
class KICKBALL_API AKBPawnBase : public APawn
{
	GENERATED_BODY()

public:
	AKBPawnBase();

	UFUNCTION(BlueprintCallable)
	virtual void KickStart();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StaticMesh)
	class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
	class UCapsuleComponent* CapsuleCollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float KickerSpeed = 0.5f;

public:
	virtual void Tick(float DeltaTime) override;

private:
	bool IsKickStart = false;
	bool IsRevertDirection = false;

};
