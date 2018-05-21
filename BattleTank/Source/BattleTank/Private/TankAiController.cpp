// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"

void ATankAiController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		ATank* PossesedTank = Cast<ATank>(InPawn);
		if (!(PossesedTank)) { return; }

		//Subsicribe Received
		PossesedTank->OnDeath.AddUniqueDynamic(this, &ATankAiController::OnPossedTankDeath);

	}
}

void ATankAiController::BeginPlay() 
{
	Super::BeginPlay();
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
}

void ATankAiController::OnPossedTankDeath()
{
	if (!GetPawn()) { return; }
	UE_LOG(LogTemp, Warning, TEXT("AI IS DEAD!"));

	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!(PlayerTank && ControlledTank)) { return; }
	
	//move towards player
	MoveToActor(PlayerTank,AcceptableRadius);
	//Aim To player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	//Fire if ready
	//if(AimingComponent->GetFiringState()==EFiringState::Locked)
	AimingComponent->Fire();
	
}