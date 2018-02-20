#pragma once

#include "ProceduralWall.h"
#include "ProceduralWallWithObject.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralBuilding.generated.h"

UCLASS()
class PMC_TEST_API AProceduralBuilding : public AActor
{
    GENERATED_BODY()
    
public:	
    AProceduralBuilding();
    virtual AProceduralWall* ConstructWall(FVector position, FRotator rotation, bool isOddOffset,
                                           UStaticMesh* Object = NULL, int32 sillHeight = 0);
    
protected:
    virtual void BeginPlay() override;
    virtual void ConstructBuild();
    
public:
    virtual void Tick(float DeltaTime) override;
    void Initialize();
    
protected:
    const int numberOfWalls = 4;
    TArray<AProceduralWall*> walls;
    
    float BlockWidth = 0;
    float BlockDepth = 0;
    float BlockHeight = 0;
    
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 WindowsNumber = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 windowSillHeight = 10;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 DoorsNumber = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int32 doorSillHeight = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool Destroyed = false;
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
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UStaticMesh* Door;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UStaticMesh* Window;
    
    
};
