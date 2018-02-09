// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralBlockBase2D.h"


// Sets default values
AProceduralBlockBase2D::AProceduralBlockBase2D()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProceduralBlockBase2D::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProceduralBlockBase2D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProceduralBlockBase2D::setMaskValue(int32 x, int32 y, bool value){
    mask_array[XSizeBlocks * y + x] = value;
//    mask_array[XSizeBlocks*y+x] = value;
}

bool AProceduralBlockBase2D::getMaskValue(int32 x, int32 y){
    return mask_array[XSizeBlocks * y + x];
//    return mask_array[XSizeBlocks*y+x];
}
