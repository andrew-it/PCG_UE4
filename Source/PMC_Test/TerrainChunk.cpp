// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainChunk.h"

void ATerrainChunk::spawnObject()
{
	for (int x = 0; x < XSizeBlocks; ++x)
		for (int y = 0; y < YSizeBlocks; ++y)
			for (int z = 0; z < ZSizeBlocks; ++z)
				if(getMaskValue(x, y, z))
				{
					SMComponent->AddInstance(FTransform(FVector(
						BlockWidth * x,
						BlockDepth * y,
						BlockHeight * z
					)));
				}
}
