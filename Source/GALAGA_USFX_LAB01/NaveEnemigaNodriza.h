// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaNodriza.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB01_API ANaveEnemigaNodriza : public ANaveEnemiga
{
	GENERATED_BODY()
private:
	float TiempoDeDisparo;
	float Intervalo;
public:
	ANaveEnemigaNodriza();
	virtual void Disparar();
	virtual void Tick(float DeltaTime) override;
	
};
