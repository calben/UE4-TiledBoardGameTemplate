// Fill out your copyright notice in the Description page of Project Settings.

#include "TiledGame.h"
#include "TGBoardCheckers.h"


// Sets default values
ATGBoardCheckers::ATGBoardCheckers()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATGBoardCheckers::BeginPlay()
{
	Super::BeginPlay();
	SpawnCheckersPieces();
}

// Called every frame
void ATGBoardCheckers::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATGBoardCheckers::SpawnCheckersPieces()
{
	for (auto i = 0; i < 2; ++i)
	{
		for (auto j = 0; j < 8; ++j)
		{
			const FVector Location = FVector(i * 100 + 50.0f, j * 100 + 50.0f, 30.f) + GetActorLocation() - GetActorRelativeScale3D() * 50;
			ATGPlayingPiece* Piece = GetWorld()->SpawnActor<ATGPlayingPiece>(Location, FRotator(0, 0, 0));
			Piece->Mesh->SetMaterial(0, PieceMaterialA);
		}
	}

	for (auto i = 6; i < 8; ++i)
	{
		for (auto j = 0; j < 8; ++j)
		{
			const FVector Location = FVector(i * 100 + 50.0f, j * 100 + 50.0f, 30.f) + GetActorLocation() - GetActorRelativeScale3D() * 50;
			ATGPlayingPiece* Piece = GetWorld()->SpawnActor<ATGPlayingPiece>(Location, FRotator(0, 0, 0));
			Piece->Mesh->SetMaterial(0, PieceMaterialB);
		}
	}
}