// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_LAB01GameMode.h"
#include "GALAGA_USFX_LAB01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"

AGALAGA_USFX_LAB01GameMode::AGALAGA_USFX_LAB01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGALAGA_USFX_LAB01Pawn::StaticClass();
}
void AGALAGA_USFX_LAB01GameMode::BeginPlay()
{
	Super::BeginPlay();
	UWorld* const World = GetWorld();
	ANaveEnemigaCaza* naveEnemigaCaza = World->SpawnActor<ANaveEnemigaCaza>(FVector(-500.0f, 500.0f, 250.0f), FRotator(0.0f, 0.0f, 0.0f));
}
