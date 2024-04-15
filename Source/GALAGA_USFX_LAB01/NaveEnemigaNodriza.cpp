// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"
#include "GALAGA_USFX_LAB01Projectile.h"

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	MovimientoNaves = CreateDefaultSubobject<UMovimientoNaves>(TEXT("MovimeintoNaves"));
	//MovimientoNaves->Velocidad = 100.0f;
	TiempoDeDisparo = 0.0f; // Inicializa el tiempo desde el último disparo
	Intervalo = 1.0f; // Intervalo de tiempo entre disparos
}
void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Incrementar el tiempo transcurrido desde el último disparo
	TiempoDeDisparo += DeltaTime;

	// Verificar si ha pasado el tiempo suficiente para disparar
	if (TiempoDeDisparo >= Intervalo)
	{
		// Reiniciar el contador de tiempo
		TiempoDeDisparo = 0.0f;

		// Llamar a la función para disparar
		Disparar();
	}
}
void ANaveEnemigaNodriza::Disparar()
{
	FVector PosicionActualNaveEnemigaNodriza = GetActorLocation();
	FRotator RotacionActualNaveEnemigaNodriza = GetActorRotation();

	FVector DireccionDisparoNodriza = RotacionActualNaveEnemigaNodriza.Vector();
	PosicionActualNaveEnemigaNodriza += DireccionDisparoNodriza * 100;
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		World->SpawnActor<AGALAGA_USFX_LAB01Projectile>(PosicionActualNaveEnemigaNodriza, RotacionActualNaveEnemigaNodriza);
	}
}