// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "MovimientoNaves.h"
#include "NaveEnemigaCaza.generated.h"



/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB01_API ANaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()
private: 
	//UPROPERTY (EditAnywhere, Category = "Nave Enemiga Caza")
	//UStaticMeshComponent* VisualMesh;
	//UPROPERTY(EditAnywhere, Category = "Nave Enemiga Caza")
	//UStaticMeshComponent* CollisionMesh;
	//UPROPERTY(VisibleAnywhere, Category = "Componentes")
	UMovimientoNaves* MovimientoNaves;
private:
	int cantidadBombas;
	float TiempoDeDisparo;
	float Intervalo;
	float PosicionInicialX;
	float Limite;

public:
	ANaveEnemigaCaza();
	FORCEINLINE int GetCantidadBombas() const { return cantidadBombas; }
	FORCEINLINE void SetCantidadBombas(int _cantidadBombas) { cantidadBombas = _cantidadBombas; }
public:

	 virtual void Disparar();
	 virtual void Mover(float DeltaTime);
public: 
	virtual void Tick(float DeltaTime) override;
};
