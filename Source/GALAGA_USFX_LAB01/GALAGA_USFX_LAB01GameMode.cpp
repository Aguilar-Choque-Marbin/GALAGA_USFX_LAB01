// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_LAB01GameMode.h"
#include "GALAGA_USFX_LAB01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"

AGALAGA_USFX_LAB01GameMode::AGALAGA_USFX_LAB01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGALAGA_USFX_LAB01Pawn::StaticClass();

}
void AGALAGA_USFX_LAB01GameMode::BeginPlay()
{
	Super::BeginPlay();
	FVector PosicionActualNaveEnemigaCaza = FVector(-500.0f, 500.0f, 250.0f);
	FVector PosicionActualNaveEnemigaEspia = FVector(500.0f, 500.0f, 250.0f);
	FRotator Rotacion = FRotator(0.0f, 180.0f, 0.0f);
	FRotator RotacionEspia = FRotator(0.0f, 180.0f, 0.0f);
	UWorld* const World = GetWorld();
	for (int i = 0; i<3; i++)
	{
		FVector PosicionNaveActualCaza = FVector(PosicionActualNaveEnemigaCaza.X, PosicionActualNaveEnemigaCaza.Y + i * 200, PosicionActualNaveEnemigaCaza.Z);
		ANaveEnemigaCaza* NaveEnemigaCaza = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActualCaza, Rotacion);
	}
	for (int i = 0; i < 3; i++)
	{
		FVector PosicionNaveActualEspia = FVector(PosicionActualNaveEnemigaEspia.X, PosicionActualNaveEnemigaEspia.Y + i * 200, PosicionActualNaveEnemigaEspia.Z);
		ANaveEnemigaEspia* NaveEnemigaEspia = World->SpawnActor<ANaveEnemigaEspia>(PosicionNaveActualEspia, RotacionEspia);
	}

}
