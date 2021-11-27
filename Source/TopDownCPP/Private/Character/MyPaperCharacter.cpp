// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/MyPaperCharacter.h"
#include "DrawDebugHelpers.h"
#include "PaperFlipbookComponent.h"
#include "CharacterState.h"
#include "Kismet/KismetMathLibrary.h"
#include "CharacterAnimationStruct.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/EngineTypes.h"

// Sets default values
AMyPaperCharacter::AMyPaperCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

FHitResult AMyPaperCharacter::instantHit()
{
	FVector rayLocation = GetActorLocation();
	FRotator rayRotation = GetActorRotation();
	FVector endTrace = FVector::ZeroVector;
	
	// APlayerController *const playerController = GetWorld()->GetFirstPlayerController();
	// if (playerController)
	// {
		
	// }
	
	endTrace = rayLocation + (rayRotation.Vector() * weaponRange);
	const FName TraceTag("MyTraceTag");

 	GetWorld()->DebugDrawTraceTag = TraceTag;
	FCollisionQueryParams traceParams(SCENE_QUERY_STAT(instanceHit), true, this);
 	traceParams.TraceTag = TraceTag;
	FHitResult hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(hit, rayLocation, endTrace, ECC_Visibility, traceParams);
	// DrawDebugLine(
    //          GetWorld(),
    //          rayLocation,
    //          hit.Location,
    //          FColor(255, 0, 0),
    //          false, -1, 0,
    //          12.333
    //      );
	return hit;
}

void AMyPaperCharacter::fireWeapon()
{
	this->instantHit();
}
EDirection AMyPaperCharacter::RotationToDirection(float direction)
{
	float angle = UKismetMathLibrary::ClampAxis(direction)/90.0f;
	int index = UKismetMathLibrary::Round(angle);
	//UE_LOG(LogTemp, Display, TEXT("direction: %f angle: %f index: %d"), direction, angle, index);
	switch (index)
	{
	case 0:
		return EDirection::DOWN;
	case 1:
		return EDirection::LEFT;
	case 2:
		return EDirection::UP;
	case 3:
		return EDirection::RIGHT;
	default:
		return EDirection::DOWN;
	}
}

void AMyPaperCharacter::setAnimAndDirection(FDirection_Struct anim, EDirection direction)
{
	switch (direction)
	{
	case EDirection::RIGHT:
		GetSprite()->SetFlipbook(anim.RightAnim);
		break;
	case EDirection::UP:
		GetSprite()->SetFlipbook(anim.UpAnim);
		break;
	case EDirection::LEFT:
		GetSprite()->SetFlipbook(anim.LeftAnim);
		break;
	case EDirection::DOWN:
		GetSprite()->SetFlipbook(anim.DownAnim);
		break;
	default:
		GetSprite()->SetFlipbook(anim.DownAnim);
		break;
	}
}

FString AMyPaperCharacter::GetMovementState()
{
	FString str = "";
	if (!(GetCharacterMovement()->IsFalling() || GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Custom))
	{
		FString str1 = (IsIdle() ? "idle" : "walking");
		FString str2 = (bIsCrouched ? "_crouched" : "");
		str = FString::Printf(TEXT("%s%s"), *str1, *str2);
	}
	if (GetCharacterMovement()->IsFalling())
	{
		/* jumping */
		str = GetVelocity().Z > 0 ? "jumping" : "falling";
	}
	
	if (GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Custom)
	{
		switch (GetCharacterMovement()->CustomMovementMode)
		{
		case 0:
			/* ATTACK 0 */
			str = "attack_0";
			break;
		
		default:
			break;
		}
	}
	
	return str;
}