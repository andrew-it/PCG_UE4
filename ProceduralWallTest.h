// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProceduralBlockBase2D.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "ProceduralWallTest.generated.h"


UCLASS()
class PMC_TEST_API AProceduralWallTest : public AProceduralBlockBase2D
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralWallTest();
    

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    void createHole();
    void createHoles(int number);
    void spawnObject();
    void cutTheWall();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int holes_number = 1;
    
    // Offset of bricks
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool offset = true;
};






















