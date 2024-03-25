// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_LAB01GameMode.h"
#include "GALAGA_USFX_LAB01Pawn.h"

AGALAGA_USFX_LAB01GameMode::AGALAGA_USFX_LAB01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGALAGA_USFX_LAB01Pawn::StaticClass();
}

