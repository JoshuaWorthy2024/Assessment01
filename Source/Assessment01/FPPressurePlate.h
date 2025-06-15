// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPPressurePlate.generated.h"

class AFPDoor;

UCLASS()
class ASSESSMENT01_API AFPPressurePlate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPPressurePlate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plate")
	bool bIsCurrentlyActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plate")
	bool bDoorHasBeenActivated = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plate")
	AFPDoor* Door;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plate")
	TArray<AActor*> CurrentActors;

	UFUNCTION(BlueprintCallable, Category = "Plate")
	void RemoveActor(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "Plate")
	void AddActor(AActor* Actor);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
