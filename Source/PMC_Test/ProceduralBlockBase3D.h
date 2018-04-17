#pragma once

#include "CoreMinimal.h"
#include "ProceduralBlockBase.h"
#include "ProceduralBlockBase3D.generated.h"

/**
 * 
 */
UCLASS()
class PMC_TEST_API AProceduralBlockBase3D : public AProceduralBlockBase
{
	GENERATED_BODY()
	
public:
	AProceduralBlockBase3D();

	virtual void Initialize();
	virtual void SetValues(int32 blocksHeight, int32 blocksLength, int32 blocksDepth,
		UStaticMesh* StaticMesh);
    virtual void SetMaterial(UMaterialInstance * Material);

	float getZSize() { return ZSizeBlocks * BlockHeight; }
	float getYSize() { return YSizeBlocks * BlockDepth; }

protected:
	virtual void BeginPlay() override;
public:
	virtual void setMaskValue(int32 x, int32 y, int32 z, int value);
	virtual int32 getMaskValue(int32 x, int32 y, int32 z);
protected:
	void initMask(bool value);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int32 ZSizeBlocks = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int32 YSizeBlocks = 10;
};
