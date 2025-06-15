// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPButton.generated.h"

class AFPDoor;

UCLASS()
class ASSESSMENT01_API AFPButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Button")
	int ButtonId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button")
	bool IsUsing = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button")
	bool IsDisplayingError = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Button")
	float ErrorDurationTimer = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button")
	AFPDoor* AssignedDoor;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Button")
	void ActivateButton();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Button")
	void DisplayError();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Button")
	void DisplaySuccess();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Button")
	void DisplayCompleted();
	
	UFUNCTION(BlueprintCallable, Category = "Button")
	bool CanInteractWith();
};
