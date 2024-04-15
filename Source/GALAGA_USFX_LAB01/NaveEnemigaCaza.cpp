// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "GALAGA_USFX_LAB01Projectile.h"


ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	MovimientoNaves = CreateDefaultSubobject<UMovimientoNaves>(TEXT("MovimientoNaves"));
	//MovimientoNaves->Velocidad = 100.0f;
	//VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	//RootComponent = VisualMesh;

	// Crea y configura la malla de colisión
	//CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollisionMesh"));
	//CollisionMesh->SetupAttachment(RootComponent);

	// Configura la malla de colisión para que sea invisible en el juego
	//CollisionMesh->SetVisibility(false);
	//CollisionMesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));

	TiempoDeDisparo = 0.0f; // Inicializa el tiempo desde el último disparo
	Intervalo = 1.0f; // Intervalo de tiempo entre disparos
	PosicionInicialX = -500.0f;
	Limite = 0.0f;


}
void ANaveEnemigaCaza::Mover(float DeltaTime)
{

	FVector PosicionActual = GetActorLocation();
	
	float NuevaX = DeltaTime * velocidad;

	PosicionActual = FVector(PosicionActual.X + NuevaX, PosicionActual.Y, PosicionActual.Z);
	if (PosicionActual.X >= 0)
	{
		PosicionActual.X=PosicionInicialX;
	}
	SetActorLocation(PosicionActual);

	
}
void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//MovimientoNaves;
	//Mover(DeltaTime);
	
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
void ANaveEnemigaCaza::Disparar()
{
	FVector PosicionActualNaveEnemigaCaza = GetActorLocation();
	FRotator RotacionActualNaveEnemigaCaza = GetActorRotation();

	FVector DireccionDisparo = RotacionActualNaveEnemigaCaza.Vector();
	PosicionActualNaveEnemigaCaza += DireccionDisparo * 100;
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		World->SpawnActor<AGALAGA_USFX_LAB01Projectile>(PosicionActualNaveEnemigaCaza, RotacionActualNaveEnemigaCaza);
	}
}
