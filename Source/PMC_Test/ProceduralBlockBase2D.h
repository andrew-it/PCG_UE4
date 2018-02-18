#pragma once

#include "ProceduralBlockBase.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralBlockBase2D.generated.h"

UCLASS()
class PMC_TEST_API AProceduralBlockBase2D : public AProceduralBlockBase
{
    GENERATED_BODY()
    
public:
    AProceduralBlockBase2D();
    
    virtual void Initialize();
    virtual void SetValues(int32 blocksHeight, int32 blocksLength,
                            UStaticMesh* StaticMesh, UMaterial* Material);
    
protected:
    virtual void BeginPlay() override;
    virtual void setMaskValue(int32 x, int32 y, bool value);
    virtual bool getMaskValue(int32 x, int32 y);
    
public:
    virtual void Tick(float DeltaTime) override;
    
    void setOffsetOdd(bool value) { odd_offset = value; }
    void setOffset(bool value) { offset = value; }
    
    // Offset of bricks
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool offset = true;
    
    // Offset of odd rows of bricks
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    bool odd_offset = false;
};
