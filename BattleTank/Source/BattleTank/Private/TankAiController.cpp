// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAiController::BeginPlay() 
{
	Super::BeginPlay();

	if (GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI found the Player Tank: %s"), *GetPlayerTank()->GetName());
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Tank AI Did not find the Player Tank "));
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//TODO move towards player

		//Aim To player
		//GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire if ready
	}
}


ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
