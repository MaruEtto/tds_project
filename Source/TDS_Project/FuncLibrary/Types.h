// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h" // библиотека позволит общаться с данным файлом в контексте блупринтов
#include "Types.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Aim_State			UMETA(DisplayName = "Aim_State"),
	AimWalk_State		UMETA(DisplayName = "AimWalk_State"),
	Walk_State			UMETA(DisplayName = "Walk_State"),
	Run_State			UMETA(DisplayName = "Run_State"),
	SprintRun_State		UMETA(DisplayName = "SprintRun_State")
};

USTRUCT(BlueprintType)
struct FCharacterSpeed
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float AimSpeedNormal = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float AimSpeedWalk = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float WalkSpeedNormal = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float RunSpeedNormal = 600.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float RunSpeedSprint = 800.0f;
};

UCLASS()
class TDS_PROJECT_API UTypes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};