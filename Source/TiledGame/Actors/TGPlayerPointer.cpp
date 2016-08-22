// Fill out your copyright notice in the Description page of Project Settings.

#include "TiledGame.h"
#include "TGPlayerPointer.h"


// Sets default values
ATGPlayerPointer::ATGPlayerPointer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Light->SetIntensity(2000.0f);
	Light->SetLightColor(FLinearColor::FLinearColor(20.0, 0.0, 200.0), true);
	RootComponent = Light;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("/Game/StarterContent/Shapes/Shape_TriPyramid"));
	const ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialObj(TEXT("/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished"));
	if (MeshObj.Object && MaterialObj.Object)
	{
		Mesh->SetStaticMesh(MeshObj.Object);
		Mesh->SetMaterial(0, MaterialObj.Object);
	}
	Mesh->RelativeScale3D = FVector::FVector(0.5f, 0.5f, 1.0f);
	Mesh->RelativeRotation = FRotator::FRotator(180.f, 0.0f, 0.0f);
	Mesh->SetupAttachment(Light);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = true;
	SpringArm->bAbsoluteRotation = true;
	SpringArm->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	SpringArm->TargetArmLength = 600.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 5.0f;
	SpringArm->CameraLagSpeed = 3.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	RotatingMovement->RotationRate = FRotator::FRotator(0.0f, 20.0f, 0.0f);
}

// Called when the game starts or when spawned
void ATGPlayerPointer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATGPlayerPointer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATGPlayerPointer::MoveRight(float Val)
{
	AddMovementInput(FVector(1.0f, 0.f, 0.f), Val);
}

void ATGPlayerPointer::MoveForward(float Val)
{
	AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Val);
}

// Called to bind functionality to input
void ATGPlayerPointer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveRight", this, &ATGPlayerPointer::MoveRight);
	InputComponent->BindAxis("MoveForward", this, &ATGPlayerPointer::MoveForward);
}

