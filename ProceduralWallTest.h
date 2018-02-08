// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PerlinNoise.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "ProceduralWallTest.generated.h"


UCLASS()
class PMC_TEST_API AProceduralWallTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralWallTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    TArray<bool> destroyed_mask;
    void setMaskValue(int row, int column, bool value);
    bool getMaskValue(int row, int column);
    void initMask(bool value);
    void createHole();
    void createHoles(int number);
    void spawnWall();
    void cutTheWall();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    // Dimensions size
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int WallHeight = 5;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int WallWidth = 10;
	
    // Brick sizes (defaults for red brick)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    float BrickWidth = 25;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    float BrickDepth = 12;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    float BrickHeight = 6.5;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int holes_number = 1;
    
    // Offset of bricks
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool offset = true;
    
    // For Perlin Noise
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    int Seed = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    float Octaves = 8;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin Noise")
    float Frequency = 8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UStaticMesh* SMesh;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UMaterial* Material;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Content")
    UInstancedStaticMeshComponent* SMComponent;

};






















