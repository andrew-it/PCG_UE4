// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TerrainChunk.h"

#include "MinecraftLikeTerrain.generated.h"

UCLASS()
class PMC_TEST_API AMinecraftLikeTerrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMinecraftLikeTerrain();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Initialize();

	virtual void SpawnChunks();
	virtual void PerlinNoise2DTerrain(int number_of_passings);
	virtual void PerlinNoise3DTerrain(int number_of_passings);
	virtual void DiamondSqareTerrain();
	virtual void Mixed2DTerrain(int number_of_perlin_passings);

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UStaticMesh* StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UMaterialInstance* Material;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int terrain_edge_length = 64;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int chunk_length = 64;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int chunk_height = 8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int chunk_depth = 64;

	int BlockWidth = 0;
	int BlockDepth = 0;
	int BlockHeight = 0;

protected:
	TArray<ATerrainChunk*> chunks_grid;
};
