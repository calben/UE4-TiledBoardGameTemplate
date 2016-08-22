// Fill out your copyright notice in the Description page of Project Settings.

#include "TiledGame.h"
#include "TGBoard.h"


// Sets default values
ATGBoard::ATGBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("/Game/StarterContent/Shapes/Shape_Cube"));
	const ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialObj(TEXT("/Game/StarterContent/Materials/M_Wood_Oak"));
	if (MeshObj.Object && MaterialObj.Object)
	{
		Mesh->SetStaticMesh(MeshObj.Object);
		Mesh->SetMaterial(0, MaterialObj.Object);
	}
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ATGBoard::BeginPlay()
{
	Super::BeginPlay();
	SpawnBoardTiles();
}

// Called every frame
void ATGBoard::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATGBoard::SpawnBoardTiles()
{
	for (auto i = 0; i < this->GetActorScale3D().X; ++i)
	{
		for (auto j = 0; j < this->GetActorScale3D().Y; ++j)
		{
			const FVector TileLocation = FVector(i * 100 + 50.0f, j * 100 + 50.0f, 30.f) + GetActorLocation() - GetActorRelativeScale3D() * 50;
			ATGTile* Tile = GetWorld()->SpawnActor<ATGTile>(TileLocation, FRotator(0, 0, 0));
			Tiles.Add(Tile);

			if ((i + j) % 2 == 0)
			{
				Tile->Mesh->SetMaterial(0, TileMaterialA);
			}
			else
			{
				Tile->Mesh->SetMaterial(0, TileMaterialB);
			}
		}
	}
}

