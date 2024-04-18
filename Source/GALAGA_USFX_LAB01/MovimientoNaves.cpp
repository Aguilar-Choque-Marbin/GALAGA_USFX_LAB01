// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoNaves.h"

// Sets default values for this component's properties
UMovimientoNaves::UMovimientoNaves()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Velocidad = 200.0f;

	// ...
}


// Called when the game starts
void UMovimientoNaves::BeginPlay()
{
	Super::BeginPlay();
	//FVector PosicionInicial=GetOwner()->GetActorLocation();
	// ...
	
}


// Called every frame
void UMovimientoNaves::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
	AActor* Mover = GetOwner();
	if (Mover)
	{
		static float tiempo = 0.0f;
		tiempo += DeltaTime;
		if (tiempo <= 20.0f)
		{
			float LimiteMaximo = 100.0f;
			float LimiteMinimo = -100.0f;
			FVector PosicionActual = Mover->GetActorLocation();
			auto NuevaPosicion = PosicionActual + FVector(0.0f, DeltaTime * Velocidad, 0.0f);
			if (NuevaPosicion.Y >= LimiteMaximo)
			{
				Velocidad *= -1;
			}
			if (NuevaPosicion.Y <= LimiteMinimo)
			{
				Velocidad *= -1;
			}
			Mover->SetActorLocation(NuevaPosicion);
		}
		else if (tiempo <=30.0f)
		{
			FVector PosicionActual = Mover->GetActorLocation();
			auto NuevaPosicion = PosicionActual + FVector(FMath::FRandRange(-1, 1)*5, FMath::FRandRange(-1, 1) *5, FMath::FRandRange(-1, 1) *1);
			Mover->SetActorLocation(NuevaPosicion);
		}
		else
		{
			tiempo = 0.0f;
		}
	}
}

