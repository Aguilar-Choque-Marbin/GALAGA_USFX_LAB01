// Fill out your copyright notice in the Description page of Project Settings.


#include "Escudo.h"

// Sets default values for this component's properties
UEscudo::UEscudo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;
	//RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
//	RootComponent=RootScene;

	//ShieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShieldMesh"));
	//ShieldMesh->SetupAttachment(RootComponent);

	// ...
}


// Called when the game starts
void UEscudo::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEscudo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...	
}
//void UEscudo::InitShield(UStaticMeshComponent* ParentMesh, FVector RelativeLocation)
//{
	//FVector SetActorLocation=ParentMesh->GetComponentLocation() + ParentMesh->GetForwardVector() * RelativeLocation.X;
	//FRotator SetActorRotation=ParentMesh->GetForwardVector().Rotation();

	//ShieldMesh->SetRelativeLocation(FVector(0.f, 0.f, RelativeLocation.Z));
//}
