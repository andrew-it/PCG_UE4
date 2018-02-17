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
    void cutTheWall();
    
public:
    void spawnObject(FVector location);
    virtual void Tick(float DeltaTime) override;
    void setHolesNumber(int number) { holes_number = number; }
    void setCutWall(bool value) { cut_wall = value; }
    void Initialize();
    
    
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    int holes_number = 0;
    
    
    // Cut the wall
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool cut_wall = false;
};
