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

void ATerrainChunk::Initialize(int numberOfXBlocks, int numberOfYBlocks, int numberOfZBlocks)
{
	Super::Initialize();
	XSizeBlocks = numberOfXBlocks;
	YSizeBlocks = numberOfYBlocks;
	ZSizeBlocks = numberOfZBlocks;
}

void ATerrainChunk::Initialize()
{
	Super::Initialize();
	XSizeBlocks = 64;
	YSizeBlocks = 64;
	ZSizeBlocks = 8;
}

void ATerrainChunk::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
	spawnObject();
}
