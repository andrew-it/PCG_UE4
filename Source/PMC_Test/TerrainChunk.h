#pragma once

#include "CoreMinimal.h"
#include "ProceduralBlockBase3D.h"
#include "TerrainChunk.generated.h"

/**
 * 
 */
UCLASS()
class PMC_TEST_API ATerrainChunk : public AProceduralBlockBase3D
{
	GENERATED_BODY()

public:
	virtual void spawnObject();
	virtual void Initialize(int numberOfXBlocks, int numberOfYBlocks, int numberOfZBlocks,
                            UStaticMesh* StaticMesh);
    virtual void InitMaterials(UMaterialInstance* Material, UMaterialInstance* Water_Material,
                               UMaterialInstance* Dirt_Material, UMaterialInstance* Stone_Material,
                               UMaterialInstance* Grass_Material);
	virtual void Initialize();
	
protected:
	virtual void BeginPlay() override;
    
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    UMaterialInstance* Water_Material;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    UMaterialInstance* Dirt_Material;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    UMaterialInstance* Stone_Material;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    UMaterialInstance* Grass_Material;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Content")
    UInstancedStaticMeshComponent* Water_SMComponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Content")
    UInstancedStaticMeshComponent* Dirt_SMComponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Content")
    UInstancedStaticMeshComponent* Stone_SMComponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Content")
    UInstancedStaticMeshComponent* Grass_SMComponent;
};
