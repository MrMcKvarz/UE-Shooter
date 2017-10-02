// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FP_ShooterGameMode.h"
#include "FP_ShooterHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFP_ShooterGameMode::AFP_ShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFP_ShooterHUD::StaticClass();
}
