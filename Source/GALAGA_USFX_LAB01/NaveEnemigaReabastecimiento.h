// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "MovimientoNaves.h"
#include "NaveEnemigaReabastecimiento.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB01_API ANaveEnemigaReabastecimiento : public ANaveEnemiga
{
	GENERATED_BODY()
private:
	UMovimientoNaves* MovimientoNaves;
	float TiempoDeDisparo;
	float Intervalo;
public:
	ANaveEnemigaReabastecimiento();
	virtual void Disparar();
	virtual void Tick(float DeltaTime) override;
	
};
