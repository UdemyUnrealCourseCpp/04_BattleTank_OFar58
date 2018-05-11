// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAiController::BeginPlay() 
{
	Super::BeginPlay();

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI found the Player Tank: %s"), *PlayerTank->GetName());
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Tank AI Did not find the Player Tank "));
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* ControlledTank = Cast<ATank>(GetPawn());
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ensure(PlayerTank))
	{
		//move towards player
		MoveToActor(PlayerTank,AcceptableRadius);

		//Aim To player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//Fire if ready
		ControlledTank->Fire();
	
		/*float Time = GetWorld()->DeltaTimeSeconds;
		double FplatformShit = FPlatformTime::Seconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: FPlatformTime::Seconds() value is: %f"), Time, FplatformShit)*/
	}

}