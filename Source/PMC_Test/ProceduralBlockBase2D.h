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

protected:
	virtual void BeginPlay() override;
    virtual void setMaskValue(int32 row, int32 column, bool value);
    virtual bool getMaskValue(int32 row, int32 column);

public:
	virtual void Tick(float DeltaTime) override;
};
