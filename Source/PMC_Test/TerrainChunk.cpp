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

void ATerrainChunk::Initialize()
{
	Super::Initialize();
}

void ATerrainChunk::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
	spawnObject();
}
