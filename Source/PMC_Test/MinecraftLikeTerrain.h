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

	virtual void InitChunks();
	virtual void SpawnChunks();
	virtual void PerlinNoise2DTerrain(int number_of_passings);
	virtual void PerlinNoise3DTerrain(int number_of_passings);
	virtual void DiamondSquareTerrain();
	virtual void Mixed2DTerrain(int number_of_perlin_passings);
    
    virtual void ChangeBlock(int x, int y, int z, int value);

	virtual int GetLengthInBlocks() { return terrain_edge_length * chunk_length; }
	virtual int GetDepthInBlocks() { return terrain_edge_length * chunk_depth; }
	virtual int GetHeigthInBlocks() { return chunk_height; }

	virtual bool ChangeBlockValue(int x, int y, int z, int value);
	virtual void ChangeColumnHeight(int x, int y, int height);

	virtual ATerrainChunk* GetChunkByCoord(int x, int y);
	virtual bool SetChunkByCoord(int x, int y, ATerrainChunk* value);

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UStaticMesh* StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInstance* Material;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    UMaterialInstance* Water_Material;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    UMaterialInstance* Dirt_Material;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    UMaterialInstance* Stone_Material;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    UMaterialInstance* Grass_Material;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int terrain_edge_length = 8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int chunk_length = 4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int chunk_height = 8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int chunk_depth = 4;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain heights")
    int water_level;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain heights")
    int dirt_level;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain heights")
    int stone_level;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain")
    bool Perlin2D = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain")
    bool Perlin3D = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain")
    bool DimondSquare = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain")
    bool Mixed2D = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    int PassingNumbers = 1;
    
    // For Perlin Noise
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    int32 Seed = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    float Octaves = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    float OctavesMultiplyer = 2;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    float Frequency = 8;
    
    float BlockWidth = 0;
    float BlockDepth = 0;
    float BlockHeight = 0;

protected:
	TArray<ATerrainChunk*> chunks_grid;
};
