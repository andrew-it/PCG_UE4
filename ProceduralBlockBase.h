// Fill out your copyright notice in the Description page of Project Settings.

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
	// Sets default values for this actor's properties
	AProceduralBlockBase();
 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    TArray<bool> mask_array;
    
    virtual void initMask(bool value);
    virtual void spawnObject() PURE_VIRTUAL(AProceduralBlockBase::spawnObject, ;);
//    virtual bool getIthSellInMask(uint32 i);
//    virtual void setIthSellInMask(uint32 i, bool value);
    
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    
    // Dimensions size
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 XSizeBlocks = 5;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 YSizeBlocks = 10;
    
//    virtual uint32 getXSizeBlocks();
//    virtual uint32 getYSizeBlocks();
	
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
