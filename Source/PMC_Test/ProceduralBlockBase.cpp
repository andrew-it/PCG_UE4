#include "ProceduralBlockBase.h"


AProceduralBlockBase::AProceduralBlockBase()
{
	PrimaryActorTick.bCanEverTick = true;
    SMComponent = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("block"));
    RootComponent = SMComponent;
}

void AProceduralBlockBase::BeginPlay()
{
	Super::BeginPlay();
	
    initMask(true);
    
    if (StaticMesh)
    {
        SMComponent->SetStaticMesh(StaticMesh);
    }
    if (Material)
    {
        SMComponent->SetMaterial(0, Material);
    }
}

void AProceduralBlockBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProceduralBlockBase::initMask(bool value){
    mask_array.Init(value, XSizeBlocks * ZSizeBlocks);
}
