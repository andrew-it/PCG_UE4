// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainChunk.h"

void ATerrainChunk::spawnObject()
{
	for (int x = 0; x < XSizeBlocks; ++x)
		for (int y = 0; y < YSizeBlocks; ++y)
			for (int z = 0; z < ZSizeBlocks; ++z)
				if(getMaskValue(x, y, z))
				{
					FVector current_location = this->GetActorLocation();
					SMComponent->AddInstance(FTransform(current_location + FVector(
						BlockWidth * x,
						BlockDepth * y,
						BlockHeight * z
					)));
				}
}

void ATerrainChunk::Initialize(int numberOfXBlocks, int numberOfYBlocks, int numberOfZBlocks,
                               UStaticMesh* StaticMesh, UMaterialInstance* Material)
{
	//Super::Initialize();

	XSizeBlocks = numberOfXBlocks;
	YSizeBlocks = numberOfYBlocks;
	ZSizeBlocks = numberOfZBlocks;
    
    this->Material = Material;
    this->StaticMesh = StaticMesh;

	Initialize();
}

void ATerrainChunk::Initialize()
{
	Super::Initialize();

	if (StaticMesh)
	{
		auto boundingBoxSize = StaticMesh->GetBoundingBox().GetSize();
		BlockWidth = boundingBoxSize.X;
		BlockDepth = boundingBoxSize.Y;
		BlockHeight = boundingBoxSize.Z;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("StaticMesh is null"));
	}

	//spawnObject();
}

void ATerrainChunk::BeginPlay()
{
	Super::BeginPlay();
	
}
