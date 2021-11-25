// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbook.h"
#include "Direction_Struct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct TOPDOWNCPP_API FDirection_Struct
{
	GENERATED_USTRUCT_BODY()

 public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* RightAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* UpAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* LeftAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* DownAnim;
};
