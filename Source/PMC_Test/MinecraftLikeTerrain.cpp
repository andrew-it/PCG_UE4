// Fill out your copyright notice in the Description page of Project Settings.

#include "MinecraftLikeTerrain.h"
#include "DimondSquareAlghorithm.h"
#include "TerrainTypes.h"


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
	if (StaticMesh)
	{
		auto boundingBoxSize = StaticMesh->GetBoundingBox().GetSize();
		BlockWidth = boundingBoxSize.X;
		BlockDepth = boundingBoxSize.Y;
		BlockHeight = boundingBoxSize.Z;
	}

	InitChunks();
    
    if (Perlin2D)
        PerlinNoise2DTerrain(this->PassingNumbers);
    if (Perlin3D)
        PerlinNoise3DTerrain(this->PassingNumbers);
    if (DimondSquare)
        DiamondSquareTerrain();
    if (Mixed2D)
        Mixed2DTerrain(this->PassingNumbers);

	SpawnChunks();
}

void AMinecraftLikeTerrain::SpawnChunks()
{
	for (int x = 0; x < this->terrain_edge_length; x++)
	{
		for (int y = 0; y < this->terrain_edge_length; y++)
		{
			auto chunk = GetChunkByCoord(x, y);
			chunk->spawnObject();
		}
	}
}

void AMinecraftLikeTerrain::InitChunks()
{
	this->chunks_grid.Init(0, terrain_edge_length * terrain_edge_length);

	for (int x = 0; x < this->terrain_edge_length; x++)
	{
		for (int y = 0; y < this->terrain_edge_length; y++)
		{
			ATerrainChunk * chunk;
			chunk = GetWorld()->SpawnActor<ATerrainChunk>(ATerrainChunk::StaticClass());

			chunk->StaticMesh = this->StaticMesh;
            chunk->InitMaterials(Material, Water_Material, Dirt_Material, Stone_Material, Grass_Material);
			chunk->Initialize(chunk_length, chunk_depth, chunk_height, StaticMesh);
			auto currentLoc = this->GetActorLocation();
			FVector location = FVector(x * chunk->getXSize() / 2, y *  chunk->getYSize() / 2, -chunk->getZSize());
			chunk->SetActorLocation(location + currentLoc);

			SetChunkByCoord(x, y, chunk);
		}
	}
}

void AMinecraftLikeTerrain::PerlinNoise2DTerrain(int number_of_passings)
{
    int x_len = GetLengthInBlocks();
    int y_len = GetDepthInBlocks();
    int z_len = GetHeigthInBlocks();
    
    const double fx = x_len / Frequency;
    const double fy = y_len / Frequency;
    const siv::PerlinNoise perlin(Seed);
    
    for (int x = 0; x < x_len; x++)
        for (int y = 0; y < y_len; y++)
        {
            double h_value = perlin.octaveNoise0_1(x / fx, y / fy, Octaves);
            int height = (int)((double)z_len * h_value) + 1;
            ChangeColumnHeight(x, y, height);
        }
}

void AMinecraftLikeTerrain::PerlinNoise3DTerrain(int number_of_passings)
{
    int x_len = GetLengthInBlocks();
    int y_len = GetDepthInBlocks();
    int z_len = GetHeigthInBlocks();
    
    const double fx = x_len / Frequency;
    const double fy = y_len / Frequency;
    const double fz = z_len / Frequency;
    const siv::PerlinNoise perlin(Seed);
    
    for (int x = 0; x < x_len; x++)
        for (int y = 0; y < y_len; y++)
            for (int z = 0; z < z_len; z++)
            {
                bool isBlock = perlin.octaveNoise0_1(x / fx, y / fy, z / fz, Octaves) > 0.5;
                ChangeBlock(x, y, z, isBlock);
            }
}

void AMinecraftLikeTerrain::DiamondSquareTerrain()
{
	int x_len = GetLengthInBlocks();
	int y_len = GetDepthInBlocks();
    int z_len = GetHeigthInBlocks();

	DimondSquareAlghorithm* DS_Alg = new DimondSquareAlghorithm(x_len, y_len);

	DS_Alg->generateDS(1);

	for (int x = 0; x < x_len; x++)
		for (int y = 0; y < y_len; y++)
		{
			double h_value = DS_Alg->getValue(x, y);
			int height = (int)((double)z_len * h_value) + 1;
			ChangeColumnHeight(x, y, height);
		}
	UE_LOG(LogTemp, Warning, TEXT("Diamond-Square alghorithm finished"));
}

void AMinecraftLikeTerrain::Mixed2DTerrain(int number_of_perlin_passings)
{
    int x_len = GetLengthInBlocks();
    int y_len = GetDepthInBlocks();
    int z_len = GetHeigthInBlocks();
    
    const double fx = x_len / Frequency;
    const double fy = y_len / Frequency;
    const double fz = z_len / Frequency;
    const siv::PerlinNoise perlin(Seed);
    
    for (int x = 0; x < x_len; x++)
        for (int y = 0; y < y_len; y++)
        {
            double h_value = perlin.octaveNoise0_1(x / fx, y / fy, Octaves);
            int height = (int)((double)z_len * h_value) + 1;
            ChangeColumnHeight(x, y, height);
        }
    
    for (int x = x_len*.4; x < x_len*.6; x++)
        for (int y = y_len*.4; y < y_len*.6; y++)
        {
            for (int z = 0; z < z_len - z_len*0.6; z++)
            {
                bool isBlock = perlin.octaveNoise0_1(x / fx, y / fy, z / fz, OctavesMultiplyer*Octaves) > 0.45;
                ChangeBlock(x, y, z, isBlock);
            }
        }
}

bool AMinecraftLikeTerrain::ChangeBlockValue(int x, int y, int z, int value)
{
	if (x < 0 || x >= GetLengthInBlocks() ||
		y < 0 || y >= GetDepthInBlocks()  ||
		z < 0 || z >= GetHeigthInBlocks() )
	{ 
		UE_LOG(LogTemp, Error, 
			TEXT("AMinecraftLikeTerrain::ChangeBlockValue: coordinates are outside the bound. x:%d; y:%d; z:%d"), 
			x, y, z);
		return false;
	}
	else
	{
		int chunk_x_coord = x / chunk_length;
		int chunk_y_coord = y / chunk_depth;

		int coord_x_in_chunk = x % chunk_length;
		int coord_y_in_chunk = y % chunk_depth;

		ATerrainChunk * chunk = GetChunkByCoord(chunk_x_coord, chunk_y_coord);

		if (!chunk) return false;

		chunk->setMaskValue(coord_x_in_chunk, coord_y_in_chunk, z, value);

		return true;
	}
}

void AMinecraftLikeTerrain::ChangeColumnHeight(int x, int y, int height)
{
    int water_level = GetHeigthInBlocks() / 3;
    int ground_level = GetHeigthInBlocks() / 2;
	for (int h = 0; h < GetHeigthInBlocks(); h++)
    {
        if (h == height)
            ChangeBlockValue(x, y, h, GRASS);
        else if (h < height)
        {
            if (h < ground_level)
                ChangeBlockValue(x, y, h, GRASS);
            else
                ChangeBlockValue(x, y, h, STONE);
        }
        else
        {
            if (h < water_level)
                ChangeBlockValue(x, y, h, WATER);
            else
                ChangeBlockValue(x, y, h, NONE);
        }
    }
}

void AMinecraftLikeTerrain::ChangeBlock(int x, int y, int z, int value)
{
    int water_level = GetHeigthInBlocks() / 4;
    int stone_level = GetHeigthInBlocks() / 3;
    int ground_level = GetHeigthInBlocks() / 2;
    
    if (z < ground_level)
    {
        if (value)
        {
            if (z < stone_level)
                ChangeBlockValue(x, y, z, STONE);
            else
                ChangeBlockValue(x, y, z, GRASS);
        }
        else if (z < water_level)
            ChangeBlockValue(x, y, z, WATER);
        else
            ChangeBlockValue(x, y, z, NONE);
    }
    else
    {
        if (value)
            ChangeBlockValue(x, y, z, DIRT);
        else
            ChangeBlockValue(x, y, z, NONE);
    }
}

ATerrainChunk * AMinecraftLikeTerrain::GetChunkByCoord(int x, int y)
{
	if (x < 0 || x >= terrain_edge_length ||
		y < 0 || y >= terrain_edge_length  )
	{
		UE_LOG(LogTemp, Error, 
			TEXT("AMinecraftLikeTerrain::GetChunkByCoord: coordinates are outside the bound. x:%d; y:%d;"), x, y);
		return NULL;
	}
	else
		return chunks_grid[x + y * terrain_edge_length];
}

bool AMinecraftLikeTerrain::SetChunkByCoord(int x, int y, ATerrainChunk * value)
{
	if (x < 0 || x >= terrain_edge_length ||
		y < 0 || y >= terrain_edge_length  )
	{
		UE_LOG(LogTemp, Error, 
			TEXT("AMinecraftLikeTerrain::SetChunkByCoord: coordinates are outside the bound. x:%d; y:%d;"), x, y);
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

