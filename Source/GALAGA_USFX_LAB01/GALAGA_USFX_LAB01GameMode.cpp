// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_LAB01GameMode.h"
#include "GALAGA_USFX_LAB01Pawn.h"
#include "Jugador2.h"
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
	//DefaultPawnClass = AJugador2::StaticClass();

}
void AGALAGA_USFX_LAB01GameMode::BeginPlay()
{
	Super::BeginPlay();
	FRotator NaveJugador2R = FRotator(60.0f, 160.0f, 0.0f);
	FVector NaveJugador2= FVector(-1200.0f, -100.f, 250.f);
	//AJugador2* Nave = GetWorld()->SpawnActor<AJugador2>(NaveJugador2, NaveJugador2R);AJugador2* Nave = GetWorld()->SpawnActor<AJugador2>(NaveJugador2, NaveJugador2R);

	FVector PosicionActualNaveEnemigaCaza = FVector(-800.0f, 0.0f, 250.0f);
	FVector PosicionActualNaveEnemigaEspia = FVector(-400.0f, 0.0f, 250.0f);
	FVector PosicionActualNaveEnemigaNodriza = FVector(0.0f, 0.0f, 250.0f);
	FVector PosicionActualNaveEnemigaReabastecimiento = FVector(400.0f, 0.0f, 250.0f);
	FVector PosicionActualNaveEnemigaTransporte = FVector(800.0f,0.0f, 250.0f);
	FRotator RotacionCaza = FRotator(60.0f, 160.0f, 0.0f);
	FRotator RotacionEspia = FRotator(0.0f, 0.0f, 0.0f);
	FRotator RotacionNodriza = FRotator(0.0f, 180.0f, 0.0f);
	FRotator RotacionReabastecimiento = FRotator(0.0f, 0.0f, 0.0f);
	FRotator RotacionTransporte = FRotator(0.0f, 180.0f, 0.0f);
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		AJugador2* Nave = World->SpawnActor<AJugador2>(NaveJugador2, NaveJugador2R);
		for (int i = 0; i < 0; i++)
		{
			FVector PosicionNaveActualCaza = FVector(PosicionActualNaveEnemigaCaza.X, PosicionActualNaveEnemigaCaza.Y + i * 200, PosicionActualNaveEnemigaCaza.Z);
			ANaveEnemigaCaza* NaveEnemigaCaza = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActualCaza, RotacionCaza);
		}
		for (int i = 0; i < 0; i++)
		{
			FVector PosicionNaveActualEspia = FVector(PosicionActualNaveEnemigaEspia.X, PosicionActualNaveEnemigaEspia.Y + i * 200, PosicionActualNaveEnemigaEspia.Z);
			ANaveEnemigaEspia* NaveEnemigaEspia = World->SpawnActor<ANaveEnemigaEspia>(PosicionNaveActualEspia, RotacionEspia);
		}
		for (int i = 0; i < 0; i++)
		{
			FVector PosicionNaveActualNodriza = FVector(PosicionActualNaveEnemigaNodriza.X, PosicionActualNaveEnemigaNodriza.Y + i * 200, PosicionActualNaveEnemigaNodriza.Z);
			ANaveEnemigaNodriza* NaveEnemigaNodriza = World->SpawnActor<ANaveEnemigaNodriza>(PosicionNaveActualNodriza, RotacionNodriza);
		}
		for (int i = 0; i < 0; i++)
		{
			FVector PosicionNaveActualReabastecimiento = FVector(PosicionActualNaveEnemigaReabastecimiento.X, PosicionActualNaveEnemigaReabastecimiento.Y + i * 200, PosicionActualNaveEnemigaReabastecimiento.Z);
			ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimiento = World->SpawnActor<ANaveEnemigaReabastecimiento>(PosicionNaveActualReabastecimiento, RotacionReabastecimiento);
		}
		for (int i = 0; i < 0; i++)
		{
			FVector PosicionNaveActualTransporte = FVector(PosicionActualNaveEnemigaTransporte.X, PosicionActualNaveEnemigaTransporte.Y + i * 200, PosicionActualNaveEnemigaTransporte.Z);
			ANaveEnemigaTransporte* NaveEnemigaTransporte = World->SpawnActor<ANaveEnemigaTransporte>(PosicionNaveActualTransporte, RotacionTransporte);
		}
	}
}
