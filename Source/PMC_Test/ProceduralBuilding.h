#pragma once

#include "ProceduralWallTest.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralBuilding.generated.h"

UCLASS()
class PMC_TEST_API AProceduralBuilding : public AActor
{
    GENERATED_BODY()
    
public:	
    AProceduralBuilding();
    virtual AProceduralWallTest* CunstructWall(FVector position, FRotator rotation);
    
protected:
    virtual void BeginPlay() override;
    
    virtual void ConstructBuild();
    
public:
    virtual void Tick(float DeltaTime) override;
    virtual void Initialize();
    
protected:
    
    AProceduralWallTest* wall_1;
    AProceduralWallTest* wall_2;
    AProceduralWallTest* wall_3;
    AProceduralWallTest* wall_4;
    
    bool isInitialized = false;
    
    float BlockWidth = 0;
    float BlockDepth = 0;
    float BlockHeight = 0;
    
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool WithWindow = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool WithDoor = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 Width = 100;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 Depth = 70;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 Height = 70;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UStaticMesh* StaticMesh;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UMaterial* Material;
};
