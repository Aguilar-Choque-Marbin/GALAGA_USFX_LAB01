// Fill out your copyright notice in the Description page of Project Settings.


#include "Jugador2.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

const FName AJugador2::MovimientoVerticalBinding("MovimientoVertical");
const FName AJugador2::MovimientoHorizontalBinding("MovimientoHorizontal");
// Sets default values
AJugador2::AJugador2()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	// Create the mesh component
	MallaNave2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = MallaNave2;
	MallaNave2->SetStaticMesh(ShipMesh.Object);
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void AJugador2::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MovimientoVerticalBinding);
	PlayerInputComponent->BindAxis(MovimientoHorizontalBinding);
}
// Called when the game starts or when spawned
void AJugador2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJugador2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float Velocidad = 1000.0f;
	FVector PosicionActual = GetActorLocation();

	const float ValorVertical = GetInputAxisValue(MovimientoVerticalBinding);
	const float Valorhorizontal = GetInputAxisValue(MovimientoHorizontalBinding);
	FString MensajeVertical = FString::Printf(TEXT("Valor Vertical: %f"), ValorVertical);
	FString MensajeHorizontal = FString::Printf(TEXT("Valor Horizontal: %f"), Valorhorizontal);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, MensajeVertical);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, MensajeHorizontal);
	FVector MoverDireccion = FVector(ValorVertical, Valorhorizontal, 0.f).GetClampedToMaxSize(1.0f);
	FVector Movimiento = MoverDireccion * Velocidad * DeltaTime;
	FVector NuevaPosicion = PosicionActual + Movimiento;

	FString MensajeActual = FString::Printf(TEXT("Posicion Actual: X=%f, Y=%f, Z=%f"), NuevaPosicion.X, NuevaPosicion.Y, NuevaPosicion.Z);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, MensajeActual);
	//PosicionActual = FVector(PosicionActual.X +( ValorVertical * Velocidad * DeltaTime), PosicionActual.Y +( ValorVertical * Velocidad * DeltaTime), PosicionActual.Z);
	SetActorLocation(NuevaPosicion);
	//const FVector DireccionMovimiento = FVector(ValorVertical, Valorhorizontal, 0.f).GetClampedToMaxSize(1.0f);
	//const FVector Movimiento = DireccionMovimiento * Velocidad * DeltaTime;

	//if (Movimiento.SizeSquared() > 0.0f)
	//{
		 //FRotator NuevaRotacion = Movimiento.Rotation();
		// FHitResult Hit(1.f);
		 //RootComponent->MoveComponent(Movimiento, NuevaRotacion, true, &Hit);
		// SetActorLocation(PosicionActual);
	//}
}

// Called to bind functionality to input
//void AJugador2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

//}

