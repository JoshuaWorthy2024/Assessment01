// Fill out your copyright notice in the Description page of Project Settings.


#include "FPButton.h"

// Sets default values
AFPButton::AFPButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFPButton::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFPButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPButton::DisplayCompleted_Implementation()
{
}

bool AFPButton::CanInteractWith()
{
	if (IsUsing || IsDisplayingError)
	{
		return false;
	}

	return true;
}

void AFPButton::DisplaySuccess_Implementation()
{
}

void AFPButton::DisplayError_Implementation()
{
}

void AFPButton::ActivateButton_Implementation()
{
}
