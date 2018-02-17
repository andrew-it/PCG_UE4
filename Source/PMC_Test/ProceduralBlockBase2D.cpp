#include "ProceduralBlockBase2D.h"


AProceduralBlockBase2D::AProceduralBlockBase2D()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AProceduralBlockBase2D::BeginPlay()
{
    Super::BeginPlay();
}

void AProceduralBlockBase2D::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AProceduralBlockBase2D::setMaskValue(int32 x, int32 y, bool value)
{
    mask_array[XSizeBlocks * y + x] = value;
}

bool AProceduralBlockBase2D::getMaskValue(int32 x, int32 y)
{
    return mask_array[XSizeBlocks * y + x];
}

void AProceduralBlockBase2D::SetValues(int32 blocksHeight,
                                       int32 blocksLength,
                                       UStaticMesh *StaticMesh,
                                       UMaterial *Material)
{
    this->ZSizeBlocks = blocksHeight;
    this->ZSizeBlocks = blocksLength;
    this->StaticMesh = StaticMesh;
    this->Material = Material;
}

void AProceduralBlockBase2D::Initialize()
{ 
    Super::Initialize();
}


