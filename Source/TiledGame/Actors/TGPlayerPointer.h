// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TGPlayerPointer.generated.h"

UCLASS()
class TILEDGAME_API ATGPlayerPointer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATGPlayerPointer();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		class UPointLightComponent* Light;

	UPROPERTY(EditAnywhere)
		class URotatingMovementComponent* RotatingMovement;

	UPROPERTY(EditAnywhere)
		bool bUseSnappingMovement = false;

	UPROPERTY(EditAnywhere)
		class ATGTile* LastTileHovered;

	UPROPERTY(EditAnywhere)
		class ATGTile* LastTileSelected;

	UPROPERTY(EditAnywhere)
		class ATGTile* CurrentTile;

	void UpdateCurrentTile(class ATGTile* Tile);

	void MoveRight(float Val);

	void MoveForward(float Val);

	void SnapForward();

	void SnapBackward();

	void SnapLeft();

	void SnapRight();

	void ResetToGrid();

	void OnSelectAction();
};
