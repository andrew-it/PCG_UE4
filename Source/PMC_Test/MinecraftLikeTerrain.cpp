// Fill out your copyright notice in the Description page of Project Settings.

#include "MinecraftLikeTerrain.h"


// Sets default values
AMinecraftLikeTerrain::AMinecraftLikeTerrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMinecraftLikeTerrain::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
}

void AMinecraftLikeTerrain::Initialize()
{
	this->chunks_grid.Init(0, this->terrain_edge_length * this->terrain_edge_length);

	if (StaticMesh)
	{
		auto boundingBoxSize = StaticMesh->GetBoundingBox().GetSize();
		BlockWidth = boundingBoxSize.X;
		BlockDepth = boundingBoxSize.Y;
		BlockHeight = boundingBoxSize.Z;
	}
}

void AMinecraftLikeTerrain::SpawnChunks()
{
	for (int x = 0; x < this->terrain_edge_length; x++)
	{
		for (int y = 0; y < this->terrain_edge_length; y++)
		{
			ATerrainChunk * chunk;
			chunk = GetWorld()->SpawnActor<ATerrainChunk>(ATerrainChunk::StaticClass());

			chunk->Initialize(chunk_length, chunk_depth, chunk_height);
			FVector location = FVector(x * chunk->getXSize(), y *  chunk->getYSize(), 0);
			chunk->SetActorLocation(location);
			//chunk->SetActorRotation(rotation);
			chunk->spawnObject();

			SetChunkByCoord(x, y, chunk);
		}
	}
}

void AMinecraftLikeTerrain::PerlinNoise2DTerrain(int number_of_passings)
{
}

void AMinecraftLikeTerrain::PerlinNoise3DTerrain(int number_of_passings)
{
}

void AMinecraftLikeTerrain::DiamondSquareTerrain()
{
	int min_h = 0;
	int max_h = GetHeigthInBlocks();
	int water_level = max_h / 2;




}

void AMinecraftLikeTerrain::Mixed2DTerrain(int number_of_perlin_passings)
{
}

bool AMinecraftLikeTerrain::ChangeBlockValue(int x, int y, int z, int value)
{
	if (x < 0 || x > GetLengthInBlocks() - 1 || 
		y < 0 || y > GetDepthInBlocks()  - 1 || 
		z < 0 || z > GetHeigthInBlocks() - 1 )
		return false;
	else
	{
		int chunk_x_coord = x / chunk_length;
		int chunk_y_coord = y / chunk_depth;

		int coord_x_in_chunk = x % chunk_length;
		int coord_y_in_chunk = y % chunk_depth;

		auto chunk = GetChunkByCoord(chunk_x_coord, chunk_y_coord);

		if (!chunk) return false;

		chunk->setMaskValue(coord_x_in_chunk, coord_y_in_chunk, z, value);

		return true;
	}
}

void AMinecraftLikeTerrain::ChangeColumnHeight(int x, int y, int height)
{
	for (int h = 0; h < height; h++)
		ChangeBlockValue(x, y, h, 1);
}

ATerrainChunk * AMinecraftLikeTerrain::GetChunkByCoord(int x, int y)
{
	if (x < 0 || x > chunk_length - 1 ||
		y < 0 || y > chunk_depth  - 1)
		return nullptr;
	else
		return chunks_grid[x + y * terrain_edge_length];
}

bool AMinecraftLikeTerrain::SetChunkByCoord(int x, int y, ATerrainChunk * value)
{
	if (x < 0 || x > chunk_length - 1 ||
		y < 0 || y > chunk_depth - 1)
		return false;
	else
	{
		chunks_grid[x + y * terrain_edge_length] = value;
		return true;
	}
}

// Called every frame
void AMinecraftLikeTerrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

