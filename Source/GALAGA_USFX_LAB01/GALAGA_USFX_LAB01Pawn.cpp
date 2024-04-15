// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_LAB01Pawn.h"
#include "GALAGA_USFX_LAB01Projectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

const FName AGALAGA_USFX_LAB01Pawn::MoveForwardBinding("MoveForward");
const FName AGALAGA_USFX_LAB01Pawn::MoveRightBinding("MoveRight");
const FName AGALAGA_USFX_LAB01Pawn::FireForwardBinding("FireForward");
const FName AGALAGA_USFX_LAB01Pawn::FireRightBinding("FireRight");
const FName AGALAGA_USFX_LAB01Pawn::DobleDisparoBinding("DobleDisparo");
const FName AGALAGA_USFX_LAB01Pawn::VolverInicioBinding("VolverInicio");
const FName AGALAGA_USFX_LAB01Pawn::DisparoParabolicoBinding("DisparoParabolico");
const FName AGALAGA_USFX_LAB01Pawn::SaltarBinding("Saltar");
const FName	AGALAGA_USFX_LAB01Pawn::TeletransportacionBinding("Teletransportacion");
const FName AGALAGA_USFX_LAB01Pawn::EscudoBinding("Escudo");
const FName AGALAGA_USFX_LAB01Pawn::DisparoBoomerangBinding("DisparoBoomerang");
//const FName AGALAGA_USFX_LAB01Pawn::ArribaDerechaBinding("ArribaDerecha");
//const FName AGALAGA_USFX_LAB01Pawn::ArribaIzquierdaBinding("ArribaIzquierda");
//const FName AGALAGA_USFX_LAB01Pawn::AbajoDerechaBinding("AbajoDerecha");
//const FName AGALAGA_USFX_LAB01Pawn::AbajoIzquierdaBinding("AbajoIzquierda");

AGALAGA_USFX_LAB01Pawn::AGALAGA_USFX_LAB01Pawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	GunOffset2 = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;
	PosicionInicial=GetActorLocation();

}

void AGALAGA_USFX_LAB01Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
	PlayerInputComponent->BindAxis(DobleDisparoBinding);
	PlayerInputComponent->BindAxis(VolverInicioBinding);
	PlayerInputComponent->BindAxis(DisparoParabolicoBinding);
	PlayerInputComponent->BindAxis(SaltarBinding);
	PlayerInputComponent->BindAxis(TeletransportacionBinding);
	PlayerInputComponent->BindAxis(EscudoBinding);
	PlayerInputComponent->BindAxis(DisparoBoomerangBinding);

	//PlayerInputComponent->BindAxis(ArribaDerechaBinding);
	//PlayerInputComponent->BindAxis(ArribaIzquierdaBinding);
	//PlayerInputComponent->BindAxis(AbajoDerechaBinding);
	//PlayerInputComponent->BindAxis(AbajoIzquierdaBinding);
}

void AGALAGA_USFX_LAB01Pawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);
	const float DobleDisparoValue = GetInputAxisValue(DobleDisparoBinding);
	const float VolverInicioValue = GetInputAxisValue(VolverInicioBinding);
	const float DisparoParabolicoValue = GetInputAxisValue(DisparoParabolicoBinding);
	const float SaltarValue = GetInputAxisValue(SaltarBinding);
	const float TeletransportacionValue = GetInputAxisValue(TeletransportacionBinding);
	const float EscudoValue = GetInputAxisValue(EscudoBinding);
	const float DisparoBoomerangValue = GetInputAxisValue(DisparoBoomerangBinding);
	//const float ArribaDerechaValue = GetInputAxisValue(ArribaDerechaBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
	if (DobleDisparoValue > 0.0f)
	{
		DobleDisparo();
	}
	if (VolverInicioValue > 0.0f)
	{
		VolverInicio();
	}
	if (DisparoParabolicoValue > 0.0f)
	{
		DisparoParabolico();
	}
	if (SaltarValue > 0.0f)
	{
		Saltar();
	}
	if (TeletransportacionValue > 0.0f)
	{
		Teletransportacion(DeltaSeconds);
	}
}

void AGALAGA_USFX_LAB01Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AGALAGA_USFX_LAB01Projectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGALAGA_USFX_LAB01Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AGALAGA_USFX_LAB01Pawn::ShotTimerExpired()
{
	bCanFire = true;
}

void AGALAGA_USFX_LAB01Pawn::DobleDisparo()
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		const FRotator FireRotation = GetActorRotation();
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
		const FVector SpawnLocation2 = GetActorLocation() + FireRotation.RotateVector(GunOffset2)*100;



		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			World->SpawnActor<AGALAGA_USFX_LAB01Projectile>(SpawnLocation, FireRotation);
			World->SpawnActor<AGALAGA_USFX_LAB01Projectile>(SpawnLocation2, FireRotation);
		}

		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGALAGA_USFX_LAB01Pawn::ShotTimerExpired, FireRate);


		//try and play the sound if specified
		if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}
		bCanFire = false;
	}
}

void AGALAGA_USFX_LAB01Pawn::VolverInicio() 
{
	float Velocidad = 100.0f;
	FVector PosicionActual = GetActorLocation();
	FVector Direccion = PosicionInicial - PosicionActual;
	Direccion.Normalize();
	FVector NuevaPosicion = PosicionActual + Direccion * Velocidad * GetWorld()->DeltaTimeSeconds;
	SetActorLocation(NuevaPosicion);
}

void AGALAGA_USFX_LAB01Pawn::DisparoParabolico()
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		const FRotator FireRotation = GetActorRotation();
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			AGALAGA_USFX_LAB01Projectile* Proyectil = World->SpawnActor<AGALAGA_USFX_LAB01Projectile>(SpawnLocation, FireRotation);
			if (Proyectil)
			{
				float Velocidad = 100.0f;
				float VelocidadYInicial = 500.0f;
				//float velocidadMaxima = FVector(Velocidad, 0.0f, VelocidadYInicial);
				Proyectil->GetProjectileMovement()->InitialSpeed = Velocidad;
				Proyectil->GetProjectileMovement()->MaxSpeed = VelocidadYInicial;
				Proyectil->GetProjectileMovement()->ProjectileGravityScale = 10.0f;
			}
		}
	}
}
void AGALAGA_USFX_LAB01Pawn::Saltar()
{
	float Velocidad = 100.0f;
	FVector PosicionActual = GetActorLocation();
	FVector Direccion = FVector(0.0f, 0.0f, 1.0f);
	FVector NuevaPosicion = PosicionActual + Direccion * Velocidad * GetWorld()->DeltaTimeSeconds;
	SetActorLocation(NuevaPosicion);
}
void AGALAGA_USFX_LAB01Pawn::Teletransportacion(float DeltaTime)
{
	//float Velocidad = 100.0f;
	FVector PosicionActual = GetActorLocation();
	float NuevaX = FMath::RandRange(-900.0f, 900.0f);
	float NuevaY = FMath::RandRange(-900.0f, 900.0f);
	FVector NuevaPosicion = FVector(NuevaX,NuevaY,PosicionActual.Z);
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		SetActorLocation(NuevaPosicion,false,nullptr,ETeleportType::TeleportPhysics);
	}
}
void AGALAGA_USFX_LAB01Pawn::Escudo()
{
	float Velocidad = 100.0f;
	FVector PosicionActual = GetActorLocation();
	FVector Direccion = FVector(0.0f, 0.0f, 1.0f);
	FVector NuevaPosicion = PosicionActual + Direccion * Velocidad * GetWorld()->DeltaTimeSeconds;
	SetActorLocation(NuevaPosicion);
}
void AGALAGA_USFX_LAB01Pawn::DisparoBoomerang()
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		const FRotator FireRotation = GetActorRotation();
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			AGALAGA_USFX_LAB01Projectile* Proyectil = World->SpawnActor<AGALAGA_USFX_LAB01Projectile>(SpawnLocation, FireRotation);
			if (Proyectil)
			{
				float Velocidad = 100.0f;
				float VelocidadYInicial = 500.0f;
				//float velocidadMaxima = FVector(Velocidad, 0.0f, VelocidadYInicial);
				Proyectil->GetProjectileMovement()->InitialSpeed = Velocidad;
				Proyectil->GetProjectileMovement()->MaxSpeed = VelocidadYInicial;
				Proyectil->GetProjectileMovement()->ProjectileGravityScale = 10.0f;
				Proyectil->GetProjectileMovement()->bShouldBounce = true;
			}
		}
	}
}