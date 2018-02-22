#pragma once

#include "PerlinNoise.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "ProceduralBlockBase.generated.h"

UCLASS()
class PMC_TEST_API AProceduralBlockBase : public AActor
{
    GENERATED_BODY()
    
public:
    AProceduralBlockBase();
    
    int32 getXBlocksNumber() { return XSizeBlocks; }
    void setXBlocksNumber(int32 number) { XSizeBlocks = number; }
    
    float getBlockWidth() { return BlockWidth; }
    float getBlockDepth() { return BlockDepth; }
    float getBlockHeight() { return BlockHeight; }
    
    float getXSize() { return XSizeBlocks * BlockWidth; }
    
    virtual void Tick(float DeltaTime) override;
    
protected:
    virtual void BeginPlay() override;
    virtual void initMask(bool value);
    
    TArray<bool> mask_array;
    
public:
    virtual void spawnObject() PURE_VIRTUAL(AProceduralBlockBase::spawnObject, ;);
    virtual void Initialize();
    
    // Blocks number
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 XSizeBlocks = 5;
    
    
    // Blocks sizes (defaults for red brick)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    float BlockWidth = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    float BlockDepth = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    float BlockHeight = 0;
    
    
    // For Perlin Noise
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    int32 Seed = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    float Octaves = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    float Frequency = 3;
    
    // Model and Material
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UStaticMesh* StaticMesh;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UMaterialInstance* Material;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Content")
    UInstancedStaticMeshComponent* SMComponent;
};
