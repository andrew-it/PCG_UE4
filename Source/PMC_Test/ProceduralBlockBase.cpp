#include "ProceduralBlockBase.h"
#include "DateTime.h"

AProceduralBlockBase::AProceduralBlockBase()
{
    PrimaryActorTick.bCanEverTick = true;
    SMComponent = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("block"));
    RootComponent = SMComponent;
    auto datetime = new FDateTime();
    Seed = datetime->GetMillisecond();
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
    mask_array.Init(value, XSizeBlocks);
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

		// UE_LOG(LogTemp, Log, TEXT("StaticMesh was setted"))
    }
	else
		UE_LOG(LogTemp, Error, TEXT("StaticMesh is NULL"))

    if (Material)
    {
        SMComponent->SetMaterial(0, Material);

		// UE_LOG(LogTemp, Log, TEXT("Material was setted"))
    }
	else
		UE_LOG(LogTemp, Warning, TEXT("Material is NULL"))
}
