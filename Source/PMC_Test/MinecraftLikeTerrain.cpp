// Fill out your copyright notice in the Description page of Project Settings.

#include "MinecraftLikeTerrain.h"


// Sets default values
AMinecraftLikeTerrain::AMinecraftLikeTerrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Init();
}

// Called when the game starts or when spawned
void AMinecraftLikeTerrain::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMinecraftLikeTerrain::Init()
{
	this->chunks_grid.Init(0, this->terrain_edge_length * this->terrain_edge_length);
}

void AMinecraftLikeTerrain::SpawnChunks()
{
	for (int x = 0; x < this->terrain_edge_length; x++)
	{
		for (int y = 0; y < this->terrain_edge_length; y++)
		{
			ATerrainChunk * chunk;
			chunk = GetWorld()->SpawnActor<ATerrainChunk>(ATerrainChunk::StaticClass());

			chunk->Initialize();
			FVector location = FVector(x * chunk->getXSize(), y *  chunk->getYSize(), 0);
			chunk->SetActorLocation(location);
			//chunk->SetActorRotation(rotation);
			chunk->spawnObject();

			this->chunks_grid[x + y * this->terrain_edge_length] = chunk;
		}
	}
}

void AMinecraftLikeTerrain::PerlinNoise2DTerrain(int number_of_passings)
{
}

void AMinecraftLikeTerrain::PerlinNoise3DTerrain(int number_of_passings)
{
}

void AMinecraftLikeTerrain::DiamondSqareTerrain()
{
}

void AMinecraftLikeTerrain::Mixed2DTerrain(int number_of_perlin_passings)
{
}

// Called every frame
void AMinecraftLikeTerrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

