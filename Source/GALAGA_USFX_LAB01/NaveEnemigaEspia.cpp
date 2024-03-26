// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"
#include "GALAGA_USFX_LAB01Projectile.h"

ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	TiempoDeDisparo = 0.0f; // Inicializa el tiempo desde el �ltimo disparo
	Intervalo = 1.0f; // Intervalo de tiempo entre disparos
}
void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Incrementar el tiempo transcurrido desde el �ltimo disparo
	TiempoDeDisparo += DeltaTime;

	// Verificar si ha pasado el tiempo suficiente para disparar
	if (TiempoDeDisparo >= Intervalo)
	{
		// Reiniciar el contador de tiempo
		TiempoDeDisparo = 0.0f;

		// Llamar a la funci�n para disparar
		Dispare();
	}
}
void ANaveEnemigaEspia::Dispare()
{
	FVector PosicionActualNaveEnemigaEspia = GetActorLocation();
	FRotator RotacionActualNaveEnemigaEspia = GetActorRotation();

	FVector DireccionDisparoEspia = RotacionActualNaveEnemigaEspia.Vector();
	PosicionActualNaveEnemigaEspia += DireccionDisparoEspia * 100;
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		World->SpawnActor<AGALAGA_USFX_LAB01Projectile>(PosicionActualNaveEnemigaEspia, RotacionActualNaveEnemigaEspia);
	}
}