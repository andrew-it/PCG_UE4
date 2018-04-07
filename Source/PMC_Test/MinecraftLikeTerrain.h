// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MinecraftLikeTerrain.generated.h"
#include "TerrainChunk.h"

UCLASS()
class PMC_TEST_API AMinecraftLikeTerrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMinecraftLikeTerrain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SpawnChunks();
	virtual void PerlinNoise2DTerrain(int number_of_passings);
	virtual void PerlinNoise3DTerrain(int number_of_passings);
	virtual void DiamondSqareTerrain();
	virtual void Mixed2DTerrain(int number_of_perlin_passings);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	ATerrainChunk * * chunks_grid;
	
};
