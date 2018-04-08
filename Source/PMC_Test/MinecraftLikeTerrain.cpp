// Fill out your copyright notice in the Description page of Project Settings.

#include "MinecraftLikeTerrain.h"
#include "DimondSquareAlghorithm.h"


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
	this->chunks_grid.Init(0, terrain_edge_length * terrain_edge_length);

	if (StaticMesh)
	{
		auto boundingBoxSize = StaticMesh->GetBoundingBox().GetSize();
		BlockWidth = boundingBoxSize.X;
		BlockDepth = boundingBoxSize.Y;
		BlockHeight = boundingBoxSize.Z;
	}

	DiamondSquareTerrain();

	SpawnChunks();
}

void AMinecraftLikeTerrain::SpawnChunks()
{
	for (int x = 0; x < this->terrain_edge_length; x++)
	{
		for (int y = 0; y < this->terrain_edge_length; y++)
		{
			ATerrainChunk * chunk;
			chunk = GetWorld()->SpawnActor<ATerrainChunk>(ATerrainChunk::StaticClass());

			chunk->StaticMesh = this->StaticMesh;
			chunk->Material = this->Material;

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
	int max_h = GetHeigthInBlocks();
	int x_len = GetLengthInBlocks();
	int y_len = GetDepthInBlocks();
	int water_level = max_h / 2;

	DimondSquareAlghorithm* DS_Alg = new DimondSquareAlghorithm(x_len, y_len);

	DS_Alg->generateDS(1);

	for (int x = 0; x < x_len; x++)
		for (int y = 0; y < y_len; y++)
		{
			double h_value = DS_Alg->getValue(x, y);
			int height = (int)((double)max_h * h_value);
			ChangeColumnHeight(x, y, height);
		}
	UE_LOG(LogTemp, Log, TEXT("Diamond-Square alghorithm finished"));
}

void AMinecraftLikeTerrain::Mixed2DTerrain(int number_of_perlin_passings)
{
}

bool AMinecraftLikeTerrain::ChangeBlockValue(int x, int y, int z, int value)
{
	int l = GetLengthInBlocks();
	int d = GetDepthInBlocks();
	int h = GetHeigthInBlocks();
	if (x < 0 || x >= l)
		UE_LOG(LogTemp, Error, TEXT("AMinecraftLikeTerrain::ChangeBlockValue: x"));
	if (y < 0 || y >= d)
		UE_LOG(LogTemp, Error, TEXT("AMinecraftLikeTerrain::ChangeBlockValue: y"));
	if (z < 0 || z >= h)
		UE_LOG(LogTemp, Error, TEXT("AMinecraftLikeTerrain::ChangeBlockValue: z"));
	if (x < 0 || x >= l  || 
		y < 0 || y >= d   || 
		z < 0 || z >= h  )
	{ 
		UE_LOG(LogTemp, Error, 
			TEXT("AMinecraftLikeTerrain::ChangeBlockValue: coordinates are outside the bound.\nx:%d; y:%d; z:%d"), 
			x, y, z);
		return false;
	}
	else
	{
		int chunk_x_coord = x / chunk_length;
		int chunk_y_coord = y / chunk_depth;

		int coord_x_in_chunk = x % chunk_length;
		int coord_y_in_chunk = y % chunk_depth;

		ATerrainChunk * chunk = GetChunkByCoord((int)(x / chunk_length), (int)(y / chunk_depth));

		if (!chunk) return false;

		chunk->setMaskValue(x % chunk_length, y % chunk_depth, z, value);

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
	if (x < 0 || x >= chunk_length ||
		y < 0 || y >= chunk_depth  )
	{
		UE_LOG(LogTemp, Error, 
			TEXT("AMinecraftLikeTerrain::GetChunkByCoord: coordinates are outside the bound.\nx:%d; y:%d;"), 
			x, y);
		return nullptr;
	}
	else
		return chunks_grid[x + y * terrain_edge_length];
}

bool AMinecraftLikeTerrain::SetChunkByCoord(int x, int y, ATerrainChunk * value)
{
	if (x < 0 || x >= chunk_length ||
		y < 0 || y >= chunk_depth  )
	{
		UE_LOG(LogTemp, Error, 
			TEXT("AMinecraftLikeTerrain::SetChunkByCoord: coordinates are outside the bound.\nx:%d; y:%d;"), 
			x, y);
		return false;
	}
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

