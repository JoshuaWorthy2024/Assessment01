// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPDoor.generated.h"

class AFPButton;
class AFPPuzzleManager;
class AFPPressurePlate;

UCLASS()
class ASSESSMENT01_API AFPDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Door")
	AFPPuzzleManager* PuzzleManager;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door")
	int DoorType = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door | Button Sequence Mechanic")
	TArray<AFPButton*> CorrectButtonSequence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door | Button Sequence Mechanic")
	TArray<AFPButton*> CurrentButtonSequence;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Door")
	void OpenDoor();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Door | Button Sequence Mechanic")
	bool ProcessButton(AFPButton* Button);

	UFUNCTION(BlueprintCallable, Category = "Door | Button Sequence Mechanic")
	bool CheckCurrentValues();

	UFUNCTION(BlueprintCallable, Category = "Door | Button Sequence Mechanic")
	bool CheckForIdenticalSequenceLengths();
	
	UFUNCTION(BlueprintCallable, Category = "Door | Button Sequence Mechanic")
	bool CompareSequences();

	UFUNCTION(BlueprintCallable, Category = "Door | Button Sequence Mechanic")
	void AddButton(AFPButton* Button);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door | Pressure Plate Mechanic")
	TArray<AFPPressurePlate*> PressurePlatesRequired;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Door | Pressure Plate Mechanic")
	bool ProcessPressurePlate(AFPPressurePlate* PressurePlate, bool IsAdding);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Plate")
	bool CheckIfAllPressurePlatesAreActive();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
