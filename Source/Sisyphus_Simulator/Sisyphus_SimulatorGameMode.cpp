// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Sisyphus_SimulatorGameMode.h"
#include "Sisyphus_SimulatorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASisyphus_SimulatorGameMode::ASisyphus_SimulatorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
