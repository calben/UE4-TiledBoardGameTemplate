// Fill out your copyright notice in the Description page of Project Settings.

#include "TiledGame.h"
#include "TGPlayingPiece.h"


// Sets default values
ATGPlayingPiece::ATGPlayingPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("/Game/StarterContent/Shapes/Shape_WideCapsule"));
	if (MeshObj.Object)
	{
		Mesh->SetStaticMesh(MeshObj.Object);
	}
	Mesh->RelativeScale3D = FVector::FVector(0.8f, 0.8f, 0.2f);
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ATGPlayingPiece::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATGPlayingPiece::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

