// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPGroundItem.generated.h"

UCLASS()
class ASSESSMENT01_API AFPGroundItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPGroundItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GroundItem")
	bool bIsCurrentlyPickedUp = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
