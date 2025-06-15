// Fill out your copyright notice in the Description page of Project Settings.


#include "FPMovingPlatform.h"

// Sets default values
AFPMovingPlatform::AFPMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFPMovingPlatform::UpdateNavigationLocation_Implementation()
{
	if (bIsUpdatingNavigationLocation)
	{
		return;
	}

	bIsUpdatingNavigationLocation = true;
	
	if (bIsReversing)
	{
		if (CurrentNavigationIndex == 0)
		{
			bIsReversing = false;
			CurrentNavigationIndex = 1;
		}
		else
		{
			CurrentNavigationIndex--;
		}
	}
	else
	{
		if (NavigationLocations.Num() == (CurrentNavigationIndex + 1))
		{
			bIsReversing = true;
			CurrentNavigationIndex -= 1;
		}
		else
		{
			CurrentNavigationIndex += 1;
		}
	}

	bIsUpdatingNavigationLocation = false;
}

// Called when the game starts or when spawned
void AFPMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	CurrentLocation = GetActorLocation();
}

// Called every frame
void AFPMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

