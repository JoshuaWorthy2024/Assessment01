// Fill out your copyright notice in the Description page of Project Settings.


#include "FPDoor.h"

#include "Chaos/ChaosPerfTest.h"

// Sets default values
AFPDoor::AFPDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFPDoor::OpenDoor_Implementation()
{
}

bool AFPDoor::CheckCurrentValues()
{
	for (int i = 0; i < CurrentButtonSequence.Num(); i++)
	{
		if (CurrentButtonSequence[i] != CorrectButtonSequence[i])
		{
			return false;
		}
	}
	return true;
}

bool AFPDoor::CheckForIdenticalSequenceLengths()
{
	return CurrentButtonSequence.Num() == CorrectButtonSequence.Num();
}

bool AFPDoor::CompareSequences()
{
	for (int i = 0; i < CorrectButtonSequence.Num(); i++)
	{
		if (CurrentButtonSequence[i] != CorrectButtonSequence[i])
		{
			return false;
		}
	}
	return true;
}

void AFPDoor::AddButton(AFPButton* Button)
{
	CurrentButtonSequence.Add(Button);
}

// Called when the game starts or when spawned
void AFPDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

