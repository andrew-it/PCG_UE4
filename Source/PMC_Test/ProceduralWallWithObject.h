#pragma once

#include "CoreMinimal.h"
#include "ProceduralWall.h"
#include "ProceduralWallWithObject.generated.h"


UCLASS()
class PMC_TEST_API AProceduralWallWithObject : public AProceduralWall
{
	GENERATED_BODY()
    
public:
    AProceduralWallWithObject();
    void setObject(UStaticMesh* Object) { this->Object = Object; }
    void setRotation(FRotator rotator) { this->SMCObject->SetWorldRotation(rotator); }
    void setWindowSillHeight(int32 heightInBlocks) { this->windowSillHeight = heightInBlocks; }
	void CreateObjectway();

protected:
    int32 ObjectHeightInBlocks = 0;
    int32 ObjectWidthInBlocks = 0;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UStaticMesh* Object;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 windowSillHeight = 0;
    
    UInstancedStaticMeshComponent* SMCObject;
};
