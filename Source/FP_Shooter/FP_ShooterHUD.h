// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FP_ShooterHUD.generated.h"

UCLASS()
class AFP_ShooterHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFP_ShooterHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

