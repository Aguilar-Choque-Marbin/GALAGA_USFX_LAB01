// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Jugador2.generated.h"

UCLASS()
class GALAGA_USFX_LAB01_API AJugador2 : public APawn
{
	GENERATED_BODY()
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MallaNave2;

public:
	// Sets default values for this pawn's properties
	AJugador2();
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	static const FName MovimientoVerticalBinding;
	static const FName MovimientoHorizontalBinding;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
