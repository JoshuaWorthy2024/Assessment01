// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPLaserBeam.generated.h"

UCLASS()
class ASSESSMENT01_API AFPLaserBeam : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPLaserBeam();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LaserBeam")
	float Timer = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LaserBeam")
	bool bIsActive = true;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LaserBeam")
	void ToggleLaserBeam();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
