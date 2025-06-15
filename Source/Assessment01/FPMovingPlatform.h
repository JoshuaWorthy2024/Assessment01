// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPMovingPlatform.generated.h"

UCLASS()
class ASSESSMENT01_API AFPMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPMovingPlatform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector CurrentLocation =FVector3d::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementSpeed = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	TArray<FVector> NavigationLocations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	int CurrentNavigationIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool bIsReversing = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool bIsUpdatingNavigationLocation = false;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Movement")
	void MovePlatform(float DeltaTime);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Movement")
	void UpdateNavigationLocation();

	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
