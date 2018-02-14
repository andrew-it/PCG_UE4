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
	AProceduralWallTest();
    

protected:
	virtual void BeginPlay() override;
    
    void createHole();
    void createHoles(int number);
    void spawnObject();
    void cutTheWall();

public:	
	virtual void Tick(float DeltaTime) override;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int holes_number = 1;
    
    // Offset of bricks
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool offset = true;

    // Offset of odd rows of bricks
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool odd_offset = true;
    // Cut the wall
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool cut_wall = true;
};






















