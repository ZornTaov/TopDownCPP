// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Direction_Struct.h"
#include "Engine/DataTable.h"
#include "CharacterAnimationStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct TOPDOWNCPP_API FCharacterAnimationStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

 public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDirection_Struct animation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool looping = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool jumping = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool attacking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int notifyFrame = -1;
};
