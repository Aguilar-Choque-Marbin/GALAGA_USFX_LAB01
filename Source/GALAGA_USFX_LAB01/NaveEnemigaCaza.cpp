// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "GALAGA_USFX_LAB01Projectile.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	TimeSinceLastShot = 0.0f; // Inicializa el tiempo desde el último disparo
	ShotInterval = 1.0f; // Intervalo de tiempo entre disparos
}
void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Incrementar el tiempo transcurrido desde el último disparo
	TimeSinceLastShot += DeltaTime;

	// Verificar si ha pasado el tiempo suficiente para disparar
	if (TimeSinceLastShot >= ShotInterval)
	{
		// Reiniciar el contador de tiempo
		TimeSinceLastShot = 0.0f;

		// Llamar a la función para disparar
		Disparar();
	}
}
void ANaveEnemigaCaza::Disparar()
{
	FVector PosicionActualNaveEnemigaCaza = GetActorLocation();
	FRotator RotacionActualNaveEnemigaCaza = GetActorRotation();

	FVector DireccionDisparo = RotacionActualNaveEnemigaCaza.Vector();
	PosicionActualNaveEnemigaCaza += DireccionDisparo * 100;
	UWorld* const World = GetWorld();
	if (World)
	{
		World->SpawnActor<AGALAGA_USFX_LAB01Projectile>(PosicionActualNaveEnemigaCaza, RotacionActualNaveEnemigaCaza);
	}
}
