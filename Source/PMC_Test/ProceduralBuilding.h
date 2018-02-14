#pragma once

#include "ProceduralBlockBase2D.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralBuilding.generated.h"

UCLASS()
class PMC_TEST_API AProceduralBuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	AProceduralBuilding();
    
protected:
	virtual void BeginPlay() override;

    virtual void ConstructBuild();
    
public:
	virtual void Tick(float DeltaTime) override;

protected:
    
    AProceduralBlockBase2D* wall_1;
    AProceduralBlockBase2D* wall_2;
    AProceduralBlockBase2D* wall_3;
    AProceduralBlockBase2D* wall_4;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool WithWindow = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool WithDoor = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 Width = 100;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 Depth = 70;
	
};
