// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPFallingPlatform.generated.h"

UCLASS()
class ASSESSMENT01_API AFPFallingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPFallingPlatform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPFalling")
	float FallTimer = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPFalling")
	float WarningBlinkTimer = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPFalling")
	float FallSpeed = 1000.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPFalling")
	bool bIsFalling = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPFalling")
	bool bIsWarning = false;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable,  Category = "FPFalling")
	void PlayFalling();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable,  Category = "FPFalling")
	void EndFalling();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable,  Category = "FPFalling")
	void PlayWarning();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable,  Category = "FPFalling")
	void EndWarning();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
