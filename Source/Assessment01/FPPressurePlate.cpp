// Fill out your copyright notice in the Description page of Project Settings.


#include "FPPressurePlate.h"

// Sets default values
AFPPressurePlate::AFPPressurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFPPressurePlate::RemoveActor(AActor* Actor)
{
	CurrentActors.Remove(Actor);

	if (!bDoorHasBeenActivated && CurrentActors.IsEmpty())
	{
		bIsCurrentlyActive = false;
	}
}

void AFPPressurePlate::AddActor(AActor* Actor)
{
	if (!CurrentActors.Contains(Actor))
	{
		CurrentActors.Add(Actor);
	}

	if (CurrentActors.Num() > 0)
	{
		bIsCurrentlyActive = true;
	}
}

// Called when the game starts or when spawned
void AFPPressurePlate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPPressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

