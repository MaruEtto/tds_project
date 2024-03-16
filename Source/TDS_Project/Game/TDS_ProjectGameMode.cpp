// Copyright Epic Games, Inc. All Rights Reserved.

#include "TDS_ProjectGameMode.h"
#include "TDS_ProjectPlayerController.h"
#include "TDS_Project/Character/TDS_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATDS_ProjectGameMode::ATDS_ProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATDS_ProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprint/Character/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
