// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class TOPDOWNCPP_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
	UPROPERTY(EditAnywhere, Category = "Weapon")
	float weaponRange{1000};

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void fireWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FHitResult instantHit();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
