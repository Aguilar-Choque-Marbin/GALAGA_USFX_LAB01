// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GALAGA_USFX_LAB01GameMode.generated.h"

UCLASS(MinimalAPI)
class AGALAGA_USFX_LAB01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGALAGA_USFX_LAB01GameMode();
protected:
	virtual void BeginPlay() override;
	
};



