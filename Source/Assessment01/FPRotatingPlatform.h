// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPRotatingPlatform.generated.h"

UCLASS()
class ASSESSMENT01_API AFPRotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPRotatingPlatform();

	// How fast to rotate (degrees per second)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPRotatingPlatform")
	float RotationSpeed = 90.f;  // default to 90 deg/sec

	// Axis of rotation (local space)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPRotatingPlatform")
	FVector RotationAxis = FVector(0.f, 0.f, 1.f);  // default Z

	// Should it be rotating right now?
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FPRotatingPlatform")
	bool bIsRotating = false;

	// Optional: limit angle (useful for back-and-forth rotation)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPRotatingPlatform")
	bool bLimitRotation = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPRotatingPlatform", meta = (EditCondition = "bLimitRotation"))
	float MaxRotationAngle = 90.f;  // degrees

	// Internal tracking
	float AccumulatedRotation = 0.f;

	UFUNCTION(BlueprintCallable, Category = "FPRotatingPlatform")
	void StartRotating();
	
	UFUNCTION(BlueprintCallable, Category = "FPRotatingPlatform")
	void StopRotating();

	UFUNCTION(BlueprintCallable, Category = "FPRotatingPlatform")
	void SetRotationSpeed(float NewSpeed);

	UFUNCTION(BlueprintCallable, Category = "FPRotatingPlatform")
	void SetRotationAxis(FVector NewAxis);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "FPRotatingPlatform")
	void TickRotate(float DeltaTime);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
