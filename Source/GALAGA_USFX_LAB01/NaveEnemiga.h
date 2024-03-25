// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.generated.h"

UCLASS(abstract)
class GALAGA_USFX_LAB01_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaNaveEnemiga;
protected:
	float velocidad;
	float resistencia; //Numero de disparos que puede recibir antes de ser destruido
	FString nombre;
	float danioProducido; //Potencia de cada proyectil
	float tiempoDisparo; //Tiempo entre disparos
	FVector posicion;
	int trayectoria; //cada valor numerico representa a una funcio que la nace debe asumir para moverse
	int capacidadPasajeros; //Numero de naves que puede transportar
	int capacidadMunicion; //Numero de disparos que puede realizar
	int tipoNave; //Cada valor numerico representa un tipo de nave
	float experiencia;
	float energia;

	float peso;
	float volumen;

public:
	FORCEINLINE float getVelocidad() { return velocidad; }
	FORCEINLINE float getResistencia() { return resistencia; }
	FORCEINLINE FString getNombre() { return nombre; }
	FORCEINLINE float getDanioProducido() { return danioProducido; }
	FORCEINLINE float getTiempoDisparo() { return tiempoDisparo; }
	FORCEINLINE FVector getPosicion() { return posicion; }
	FORCEINLINE int getTrayectoria() { return trayectoria; }
	FORCEINLINE int getCapacidadPasajeros() { return capacidadPasajeros; }
	FORCEINLINE int getCapacidadMunicion() { return capacidadMunicion; }
	FORCEINLINE int getTipoNave() { return tipoNave; }
	FORCEINLINE float getExperiencia() { return experiencia; }
	FORCEINLINE float getEnergia() { return energia; }
	FORCEINLINE float getPeso() { return peso; }
	FORCEINLINE float getVolumen() { return volumen; }

	FORCEINLINE void setVelocidad(float _velocidad) { velocidad = _velocidad; }
	FORCEINLINE void setResistencia(float _resistencia) { resistencia = _resistencia; }
	FORCEINLINE void setNombre(FString _nombre) { nombre = _nombre; }
	FORCEINLINE void setDanioProducido(float _danioProducido) { danioProducido = _danioProducido; }
	FORCEINLINE void setTiempoDisparo(float _tiempoDisparo) { tiempoDisparo = _tiempoDisparo; }
	FORCEINLINE void setPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void setTrayectoria(int _trayectoria) { trayectoria = _trayectoria; }
	FORCEINLINE void setCapacidadPasajeros(int _capacidadPasajeros) { capacidadPasajeros = _capacidadPasajeros; }
	FORCEINLINE void setCapacidadMunicion(int _capacidadMunicion) { capacidadMunicion = _capacidadMunicion; }
	FORCEINLINE void setTipoNave(int _tipoNave) { tipoNave = _tipoNave; }
	FORCEINLINE void setExperiencia(float _experiencia) { experiencia = _experiencia; }
	FORCEINLINE void setEnergia(float _energia) { energia = _energia; }
	FORCEINLINE void setPeso(float _peso) { peso = _peso; }
	FORCEINLINE void setVolumen(float _volumen) { volumen = _volumen; }


public:	
	// Sets default values for this actor's properties
	ANaveEnemiga();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
