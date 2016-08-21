// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Environment/TGTile.h"
#include "TGBoard.generated.h"

UCLASS()
class TILEDGAME_API ATGBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATGBoard();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		TArray<ATGTile*> Tiles;

	UPROPERTY(EditAnywhere)
		UMaterial* TileMaterialA;

	UPROPERTY(EditAnywhere)
		UMaterial* TileMaterialB;

};
