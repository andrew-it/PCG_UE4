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
	// Sets default values for this actor's properties
	AProceduralBlockBase2D();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
    virtual void setMaskValue(int32 row, int32 column, bool value);
    virtual bool getMaskValue(int32 row, int32 column);
	
};
