// Fill out your copyright notice in the Description page of Project Settings.

#include "TiledGame.h"
#include "TGPlayerPointer.h"


// Sets default values
ATGPlayerPointer::ATGPlayerPointer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Light->SetIntensity(1000.f);
	Light->SetLightColor(FLinearColor::FLinearColor(160.f, 250.f, 160.f), true);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("/Game/StarterContent/Shapes/Shape_TriPyramid"));
	const ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialObj(TEXT("/Game/Materials/PointerMaterial"));
	if (MeshObj.Object && MaterialObj.Object)
	{
		Mesh->SetStaticMesh(MeshObj.Object);
		Mesh->SetMaterial(0, MaterialObj.Object);
	}
	Mesh->RelativeScale3D = FVector::FVector(0.25f, 0.25f, 0.5f);
	Mesh->RelativeRotation = FRotator::FRotator(180.f, 0.0f, 0.0f);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetLinearDamping(0.95f);
	Mesh->SetEnableGravity(false);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->bDoCollisionTest = true;
	SpringArm->bAbsoluteRotation = true;
	SpringArm->RelativeRotation = FRotator(-70.f, 0.f, 0.f);
	SpringArm->TargetArmLength = 800.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 5.0f;
	SpringArm->CameraLagSpeed = 3.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation = false;

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	RotatingMovement->RotationRate = FRotator::FRotator(0.0f, 40.0f, 0.0f);

	RootComponent = Mesh;
	Light->SetupAttachment(Mesh);
	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void ATGPlayerPointer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATGPlayerPointer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATGPlayerPointer::MoveRight(float Val)
{
	Mesh->AddForce(FVector(0.f, Val * 1500, 0.f));
}

void ATGPlayerPointer::MoveForward(float Val)
{
	Mesh->AddForce(FVector(Val * 1500, 0.f, 0.f));
}

void ATGPlayerPointer::SnapForward()
{
	ResetToGrid();
	this->SetActorLocation(this->GetActorLocation() + FVector::FVector(100.0f, 0.0f, 0.0f));
}

void ATGPlayerPointer::SnapBackward()
{
	ResetToGrid();
	this->SetActorLocation(this->GetActorLocation() - FVector::FVector(100.0f, 0.0f, 0.0f));
}

void ATGPlayerPointer::SnapLeft()
{
	ResetToGrid();
	this->SetActorLocation(this->GetActorLocation() - FVector::FVector(0.0f, 100.0f, 0.0f));
}

void ATGPlayerPointer::SnapRight()
{
	ResetToGrid();
	this->SetActorLocation(this->GetActorLocation() + FVector::FVector(0.0f, 100.0f, 0.0f));
}

void ATGPlayerPointer::ResetToGrid()
{
	this->SetActorLocation(FVector::FVector(
		FMath::FloorToInt(this->GetActorLocation().X) / 100 * 100,
		FMath::FloorToInt(this->GetActorLocation().Y) / 100 * 100,
		FMath::FloorToInt(this->GetActorLocation().Z) / 100 * 100) + FVector::FVector(75.f, 50.f, 0.f));
	this->Mesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
}

void ATGPlayerPointer::OnSelectAction()
{

}


void ATGPlayerPointer::UpdateCurrentTile(class ATGTile* Tile)
{
	this->LastTile = this->CurrentTile;
	this->CurrentTile = Tile;
}

// Called to bind functionality to input
void ATGPlayerPointer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveRight", this, &ATGPlayerPointer::MoveRight);
	InputComponent->BindAxis("MoveForward", this, &ATGPlayerPointer::MoveForward);
	InputComponent->BindAction("SnapForward", IE_Pressed, this, &ATGPlayerPointer::SnapForward);
	InputComponent->BindAction("SnapBackward", IE_Pressed, this, &ATGPlayerPointer::SnapBackward);
	InputComponent->BindAction("SnapLeft", IE_Pressed, this, &ATGPlayerPointer::SnapLeft);
	InputComponent->BindAction("SnapRight", IE_Pressed, this, &ATGPlayerPointer::SnapRight);
	InputComponent->BindAction("Select", IE_Pressed, this, &ATGPlayerPointer::OnSelectAction);
}
