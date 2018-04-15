#include "ProceduralBlockBase3D.h"

AProceduralBlockBase3D::AProceduralBlockBase3D()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AProceduralBlockBase3D::Initialize()
{
	Super::Initialize();
	initMask(true);
}

void AProceduralBlockBase3D::SetValues(int32 blocksHeight, int32 blocksLength, int32 blocksDepth, UStaticMesh * StaticMesh)
{
	this->ZSizeBlocks = blocksHeight;
	this->XSizeBlocks = blocksLength;
	this->YSizeBlocks = blocksDepth;
	this->StaticMesh = StaticMesh;

}

void AProceduralBlockBase3D::SetMaterial(UMaterialInstance * Material)
{
    if(Material)
        this->Material = Material;
}

void AProceduralBlockBase3D::BeginPlay()
{
	Super::BeginPlay();
}

void AProceduralBlockBase3D::setMaskValue(int32 x, int32 y, int32 z, bool value)
{
	mask_array[x + y * XSizeBlocks + z * XSizeBlocks * YSizeBlocks] = value;
}

int32 AProceduralBlockBase3D::getMaskValue(int32 x, int32 y, int32 z)
{
	return mask_array[x + y * XSizeBlocks + z * XSizeBlocks * YSizeBlocks];
}

void AProceduralBlockBase3D::initMask(bool value)
{
	mask_array.Init(value, XSizeBlocks * ZSizeBlocks * YSizeBlocks);
}
