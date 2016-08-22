// Fill out your copyright notice in the Description page of Project Settings.

#include "TiledGame.h"
#include "TGTile.h"


// Sets default values
ATGTile::ATGTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("/Game/StarterContent/Shapes/Shape_Cube"));
	if (MeshObj.Object)
	{
		Mesh->SetStaticMesh(MeshObj.Object);
	}
	RootComponent = Mesh;
	this->SetActorScale3D(FVector::FVector(0.95f, 0.95f, 0.1f));

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetBoxExtent(FVector::FVector(50.f, 50.f, 300.f));
	Collision->SetRelativeLocation(FVector::FVector(0.f, 0.f, 300.f));
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ATGTile::TriggerEnter);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ATGTile::TriggerExit);
	Collision->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ATGTile::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATGTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATGTile::TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ATGPlayerPointer* PlayerPointer = Cast<ATGPlayerPointer>(OtherActor);
	if (PlayerPointer)
	{
		PlayerPointer->UpdateCurrentTile(this);
	}
}

UFUNCTION()
void ATGTile::TriggerExit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
