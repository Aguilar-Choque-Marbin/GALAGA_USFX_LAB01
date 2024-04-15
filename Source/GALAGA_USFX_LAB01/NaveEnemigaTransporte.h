// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "MovimientoNaves.h"
#include "NaveEnemigaTransporte.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB01_API ANaveEnemigaTransporte : public ANaveEnemiga
{
	GENERATED_BODY()
private:
	UMovimientoNaves* MovimientoNaves;
		float TiempoDeDisparo;
		float Intervalo;
public:
	ANaveEnemigaTransporte();
	virtual void Disparar();
	virtual void Tick(float DeltaTime) override;
};
