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
	virtual void Initialize();
	
protected:
	virtual void BeginPlay() override;
};
