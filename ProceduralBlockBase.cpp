// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralBlockBase.h"


// Sets default values
AProceduralBlockBase::AProceduralBlockBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    SMComponent = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("block"));
    RootComponent = SMComponent;
}

// Called when the game starts or when spawned
void AProceduralBlockBase::BeginPlay()
{
	Super::BeginPlay();
	
    initMask(true);
    
    if (StaticMesh)
    {
        SMComponent->SetStaticMesh(StaticMesh);
    }
}

// Called every frame
void AProceduralBlockBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProceduralBlockBase::initMask(bool value){
    mask_array.Init(value, XSizeBlocks*YSizeBlocks);
}

