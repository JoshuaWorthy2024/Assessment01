// Fill out your copyright notice in the Description page of Project Settings.


#include "FPRotatingPlatform.h"

// Sets default values
AFPRotatingPlatform::AFPRotatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFPRotatingPlatform::TickRotate_Implementation(float DeltaTime)
{
	FRotator DeltaRot = FRotator::ZeroRotator;
	FVector LocalAxis = RotationAxis.GetSafeNormal();

	float DeltaAngle = RotationSpeed * DeltaTime;

	DeltaRot += FQuat(LocalAxis, FMath::DegreesToRadians(DeltaAngle)).Rotator();

	AddActorLocalRotation(DeltaRot);

	if (bLimitRotation)
	{
		AccumulatedRotation += DeltaAngle;
		if (AccumulatedRotation >= MaxRotationAngle)
		{
			StopRotating();
		}
	}
}

void AFPRotatingPlatform::StartRotating()
{
	bIsRotating = true;
}

void AFPRotatingPlatform::StopRotating()
{
	bIsRotating = false;
}

void AFPRotatingPlatform::SetRotationSpeed(float NewSpeed)
{
	RotationSpeed = NewSpeed;
}

void AFPRotatingPlatform::SetRotationAxis(FVector NewAxis)
{
	RotationAxis = NewAxis;
}

// Called when the game starts or when spawned
void AFPRotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPRotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsRotating)
	{
		TickRotate(DeltaTime);
	}
}

