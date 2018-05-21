// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;

	UTankAimingComponent* AimingComponent;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptableRadius = 8000; //i hope in cm

private:
	UFUNCTION()
	void OnPossedTankDeath();
};
