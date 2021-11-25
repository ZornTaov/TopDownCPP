// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbook.h"
#include "Direction_Struct.h"
#include "Direction.h"
#include "CharacterState.h"
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
	UPROPERTY(EditAnywhere, Category = "Weapon")
	float weaponRange{1000};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	ECharacterState CharacterState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	FDirection_Struct IdleAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	FDirection_Struct WalkAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	FDirection_Struct JumpAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	FDirection_Struct AttackAnim;
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void setAnimDirection(FDirection_Struct anim, EDirection direction);
	UFUNCTION(BlueprintCallable, Category = "Animation")
	FDirection_Struct AnimationStateMachine(bool isFalling, bool isMoving);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Animation")
	EDirection RotationToDirection(float direction);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void fireWeapon();
	bool IsInAir() const
	{
		const FVector Velocity = GetVelocity();
		return FMath::Abs(Velocity.Z) >= KINDA_SMALL_NUMBER;
	}

	bool IsWalking() const
	{
		const FVector Velocity = GetVelocity();
		return (Velocity.Size() > 0);
	}

	bool IsIdle() const
	{
		const FVector Velocity = GetVelocity();
		return FMath::Abs(Velocity.X) <= KINDA_SMALL_NUMBER;
	}
protected:
	FHitResult instantHit();
};
