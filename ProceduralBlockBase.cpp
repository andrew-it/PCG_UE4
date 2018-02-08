// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralBlockBase.h"


// Sets default values
AProceduralBlockBase::AProceduralBlockBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    SMComponent = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("block"));
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
    
    spawnObject();
}

// Called every frame
void AProceduralBlockBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProceduralBlockBase::initMask(bool value){
    mask_array.Init(value, XSizeBlocks*YSizeBlocks);
}

void AProceduralBlockBase::setMaskValue(int x, int y, bool value){
    mask_array[XSizeBlocks*y+x] = value;
}

bool AProceduralBlockBase::getMaskValue(int x, int y){
    return mask_array[XSizeBlocks*y+x];
}

void AProceduralBlockBase::spawnObject(){
    for(int x = 0; x < XSizeBlocks; x++){
        for(int y = 0; y < YSizeBlocks; y++){
            if(getMaskValue(x, y))
            {
                FTransform NewTransf;
                NewTransf.SetLocation(FVector(BlockWidth * x, BlockDepth * y, BlockHeight));
                SMComponent->AddInstance(NewTransf);
            }
        }
    }
}
