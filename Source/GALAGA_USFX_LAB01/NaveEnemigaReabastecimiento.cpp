// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimiento.h"
#include "GALAGA_USFX_LAB01Projectile.h"

ANaveEnemigaReabastecimiento::ANaveEnemigaReabastecimiento()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	MovimientoNaves = CreateDefaultSubobject<UMovimientoNaves>(TEXT("MoviemientoNaves"));
	//MovimientoNaves->Velocidad = 200.0f;
	TiempoDeDisparo = 0.0f; // Inicializa el tiempo desde el �ltimo disparo
	Intervalo = 1.0f; // Intervalo de tiempo entre disparos
}
void ANaveEnemigaReabastecimiento::Tick(float DeltaTime)
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
		Disparar();
	}
}
void ANaveEnemigaReabastecimiento::Disparar()
{
	 FVector PosicionActualNaveEnemigaReabastecimiento = GetActorLocation();
	 FRotator RotacionActualNaveEnemigaReabastecimiento = GetActorRotation();

	 FVector DireccionDisparoReabastecimiento = RotacionActualNaveEnemigaReabastecimiento.Vector();
	 PosicionActualNaveEnemigaReabastecimiento += DireccionDisparoReabastecimiento * 100;
	 UWorld* const World = GetWorld();
	 if (World != nullptr)
	 {
		 World->SpawnActor<AGALAGA_USFX_LAB01Projectile>(PosicionActualNaveEnemigaReabastecimiento, RotacionActualNaveEnemigaReabastecimiento);
	 }
 }

