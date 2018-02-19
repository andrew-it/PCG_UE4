#pragma once

#include "ProceduralBlockBase2D.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "ProceduralWall.generated.h"


UCLASS()
class PMC_TEST_API AProceduralWall : public AProceduralBlockBase2D
{
    GENERATED_BODY()
    
public:
    AProceduralWall();
    
    
protected:
    virtual void BeginPlay() override;
    
    void createHole();
    void createHoles(int number);
    void cutTheWall();
    
public:
    virtual void spawnObject();
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
