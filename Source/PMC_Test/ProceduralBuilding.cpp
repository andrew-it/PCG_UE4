#include "ProceduralBuilding.h"


AProceduralBuilding::AProceduralBuilding()
{
    PrimaryActorTick.bCanEverTick = true;
    
}

void AProceduralBuilding::BeginPlay()
{
    Super::BeginPlay();
    
    if(!isInitialized){
        Initialize();
        isInitialized = true;
    }
}

void AProceduralBuilding::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AProceduralBuilding::Initialize()
{
    if (StaticMesh)
    {
        auto boundingBoxSize = StaticMesh->GetBoundingBox().GetSize();
        BlockWidth = boundingBoxSize.X;
        BlockDepth = boundingBoxSize.Y;
        BlockHeight = boundingBoxSize.Z;
    }
    
    ConstructBuild();
}

void AProceduralBuilding::ConstructBuild()
{
    float width = Width * BlockWidth;
    
    wall_1 = CunstructWall(FVector(0, 0, 0), FRotator(0, 0, 0));
    wall_2 = CunstructWall(FVector(0, 0, 0), FRotator(0, 90, 0));
    wall_3 = CunstructWall(FVector(100, 100, 0), FRotator(0, 0, 0));
    wall_4 = CunstructWall(FVector(100, 100, 0), FRotator(0, 90, 0));
//    this->wall_1->setOffsetOdd(true);
//    this->wall_3->setOffsetOdd(true);
}

AProceduralWallTest* AProceduralBuilding::CunstructWall(FVector position, FRotator rotation)
{
    AProceduralWallTest* wall = GetWorld()->SpawnActor<AProceduralWallTest>(AProceduralWallTest::StaticClass()) ;
    
    wall->setOffset(true);
    wall->SetActorRotation(rotation);
    wall->SetActorLocation(position);
    wall->SetValues(Height, Width, StaticMesh, Material);
    wall->Initialize();
    return wall;
}

