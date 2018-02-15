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
    
    int32 getZBlocksNumber() { return ZSizeBlocks; }
    int32 getXBlocksNumber() { return XSizeBlocks; }
    void setZBlocksNumber(int32 number) { ZSizeBlocks = number; }
    void setXBlocksNumber(int32 number) { XSizeBlocks = number; }
    
    float getBlockWidth() { return BlockWidth; }
    float getBlockDepth() { return BlockDepth; }
    float getBlockHeight() { return BlockHeight; }
    
    float getZSize() { return ZSizeBlocks * BlockHeight; }
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 ZSizeBlocks = 10;
    
    // Blocks sizes (defaults for red brick)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    float BlockWidth = 25;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    float BlockDepth = 12;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    float BlockHeight = 6.5;
    
    
    // For Perlin Noise
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    int32 Seed = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    float Octaves = 8;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    float Frequency = 8;
    
    // Model and Material
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UStaticMesh* StaticMesh;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UMaterial* Material;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Content")
    UInstancedStaticMeshComponent* SMComponent;
};
