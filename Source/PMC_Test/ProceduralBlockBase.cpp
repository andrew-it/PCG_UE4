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
    
    static bool isInitialized = false;
    if(!isInitialized)
    {
        Initialize();
        isInitialized = true;
    }
}

void AProceduralBlockBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AProceduralBlockBase::initMask(bool value)
{
    mask_array.Init(value, XSizeBlocks * ZSizeBlocks);
}

void AProceduralBlockBase::Initialize()
{
    initMask(true);
    
    if (StaticMesh)
    {
        SMComponent->SetStaticMesh(StaticMesh);
   
        auto boundingBoxSize = StaticMesh->GetBoundingBox().GetSize();
        BlockWidth = boundingBoxSize.X;
        BlockDepth = boundingBoxSize.Y;
        BlockHeight = boundingBoxSize.Z;
    }
    if (Material)
    {
        SMComponent->SetMaterial(0, Material);
    }
}
