// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_LAB01GameMode.h"
#include "GALAGA_USFX_LAB01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaTransporte.h"


AGALAGA_USFX_LAB01GameMode::AGALAGA_USFX_LAB01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGALAGA_USFX_LAB01Pawn::StaticClass();

}
void AGALAGA_USFX_LAB01GameMode::BeginPlay()
{
	Super::BeginPlay();
	FVector PosicionActualNaveEnemigaCaza = FVector(-500.0f, 600.0f, 250.0f);
	FVector PosicionActualNaveEnemigaEspia = FVector(-300.0f, 600.0f, 250.0f);
	FVector PosicionActualNaveEnemigaNodriza = FVector(-500.0f, 100.0f, 250.0f);
	FVector PosicionActualNaveEnemigaReabastecimiento = FVector(-300.0f, 100.0f, 250.0f);
	FVector PosicionActualNaveEnemigaTransporte = FVector(-500.0f,-500.0f, 250.0f);
	FRotator RotacionCaza = FRotator(0.0f, 180.0f, 0.0f);
	FRotator RotacionEspia = FRotator(0.0f, 0.0f, 0.0f);
	FRotator RotacionNodriza = FRotator(0.0f, 180.0f, 0.0f);
	FRotator RotacionReabastecimiento = FRotator(0.0f, 0.0f, 0.0f);
	FRotator RotacionTransporte = FRotator(0.0f, 180.0f, 0.0f);
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		for (int i = 0; i < 2; i++)
		{
			FVector PosicionNaveActualCaza = FVector(PosicionActualNaveEnemigaCaza.X, PosicionActualNaveEnemigaCaza.Y + i * 200, PosicionActualNaveEnemigaCaza.Z);
			ANaveEnemigaCaza* NaveEnemigaCaza = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActualCaza, RotacionCaza);
		}
		for (int i = 0; i < 2; i++)
		{
			FVector PosicionNaveActualEspia = FVector(PosicionActualNaveEnemigaEspia.X, PosicionActualNaveEnemigaEspia.Y + i * 200, PosicionActualNaveEnemigaEspia.Z);
			ANaveEnemigaEspia* NaveEnemigaEspia = World->SpawnActor<ANaveEnemigaEspia>(PosicionNaveActualEspia, RotacionEspia);
		}
		for (int i = 0; i < 2; i++)
		{
			FVector PosicionNaveActualNodriza = FVector(PosicionActualNaveEnemigaNodriza.X, PosicionActualNaveEnemigaNodriza.Y + i * 200, PosicionActualNaveEnemigaNodriza.Z);
			ANaveEnemigaNodriza* NaveEnemigaNodriza = World->SpawnActor<ANaveEnemigaNodriza>(PosicionNaveActualNodriza, RotacionNodriza);
		}
		for (int i = 0; i < 2; i++)
		{
			FVector PosicionNaveActualReabastecimiento = FVector(PosicionActualNaveEnemigaReabastecimiento.X, PosicionActualNaveEnemigaReabastecimiento.Y + i * 200, PosicionActualNaveEnemigaReabastecimiento.Z);
			ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimiento = World->SpawnActor<ANaveEnemigaReabastecimiento>(PosicionNaveActualReabastecimiento, RotacionReabastecimiento);
		}
		for (int i = 0; i < 2; i++)
		{
			FVector PosicionNaveActualTransporte = FVector(PosicionActualNaveEnemigaTransporte.X, PosicionActualNaveEnemigaTransporte.Y + i * 200, PosicionActualNaveEnemigaTransporte.Z);
			ANaveEnemigaTransporte* NaveEnemigaTransporte = World->SpawnActor<ANaveEnemigaTransporte>(PosicionNaveActualTransporte, RotacionTransporte);
		}
	}
}
