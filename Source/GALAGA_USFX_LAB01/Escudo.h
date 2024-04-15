// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GALAGA_USFX_LAB01Pawn.h"
#include "Escudo.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_LAB01_API UEscudo : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEscudo();

	


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//void InitShield(UStaticMeshComponent* ParentMesh, FVector RelativeLocation);
private:
	UPROPERTY(VisibleAnywhere, Category ="Components")
	USceneComponent* RootScene;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* ShieldMesh;

};
