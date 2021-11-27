// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbook.h"
#include "Direction_Struct.h"
#include "Direction.h"
#include "CharacterState.h"
#include "CharacterAnimationStruct.h"
#include "MyPaperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNCPP_API AMyPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	AMyPaperCharacter();
	
	// ================================================================================================================
    //   ANIMATION
    // ================================================================================================================
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	ECharacterState CharacterState;

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void setAnimAndDirection(FDirection_Struct anim, EDirection direction);
	UFUNCTION(BlueprintCallable, Category = "Animation")
	FString GetMovementState();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Animation")
	EDirection RotationToDirection(float direction);

	bool IsInAir() const
	{
		const FVector Velocity = GetVelocity();
		return FMath::Abs(Velocity.Z) >= KINDA_SMALL_NUMBER;
	}

	bool IsWalking() const
	{
		const FVector Velocity = GetVelocity();
		return (Velocity.Size2D() > 0);
	}

	bool IsIdle() const
	{
		const FVector Velocity = GetVelocity();
		return Velocity.Size2D() <= KINDA_SMALL_NUMBER;
	}

	// ================================================================================================================
    //   Weapons
    // ================================================================================================================
    UPROPERTY(EditAnywhere, Category = "Weapon")
	float weaponRange{1000};

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void fireWeapon();
	
protected:
	FHitResult instantHit();
};
