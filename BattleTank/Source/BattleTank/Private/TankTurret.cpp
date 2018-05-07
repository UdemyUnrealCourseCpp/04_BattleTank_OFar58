// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"



void UTankTurret::Turn(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	float TurnRot = (RelativeSpeed*MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds) + RelativeRotation.Yaw;

	SetRelativeRotation(FRotator(RelativeRotation.Pitch, TurnRot, 0.0f));
}
