// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB01_API ANaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()
private:
	int cantidadBombas;
	float TimeSinceLastShot;
	float ShotInterval;
public:
	ANaveEnemigaCaza();
	FORCEINLINE int GetCantidadBombas() const { return cantidadBombas; }
	FORCEINLINE void SetCantidadBombas(int _cantidadBombas) { cantidadBombas = _cantidadBombas; }
public:
	 virtual void Disparar();
public: 
	virtual void Tick(float DeltaTime) override;
};