#pragma once

#include "CoreMinimal.h"
#include "ProceduralWall.h"
#include "ProceduralWallWithDoor.generated.h"


UCLASS()
class PMC_TEST_API AProceduralWallWithDoor : public AProceduralWall
{
	GENERATED_BODY()
    
public:
    AProceduralWallWithDoor();
    void setDoor(UStaticMesh* Door) { this->Door = Door; }
	void CreateDoorway();

protected:
    int32 doorHeightInBlocks = 0;
    int32 doorWidthInBlocks = 0;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UStaticMesh* Door;
    
    UInstancedStaticMeshComponent* SMCDoor;
};
