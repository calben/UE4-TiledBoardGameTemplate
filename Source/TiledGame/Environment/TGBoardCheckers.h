// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Environment/TGBoard.h"
#include "Actors/TGPlayingPiece.h"
#include "TGBoardCheckers.generated.h"

/**
 * 
 */
UCLASS()
class TILEDGAME_API ATGBoardCheckers : public ATGBoard
{
	GENERATED_BODY()
	
	ATGBoardCheckers();

	UPROPERTY(EditAnywhere)
		UMaterial* PieceMaterialA;

	UPROPERTY(EditAnywhere)
		UMaterial* PieceMaterialB;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
	void SpawnCheckersPieces();

};
