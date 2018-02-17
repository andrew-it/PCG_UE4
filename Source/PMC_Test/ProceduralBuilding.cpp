#include "ProceduralBuilding.h"


AProceduralBuilding::AProceduralBuilding()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AProceduralBuilding::BeginPlay()
{
    Super::BeginPlay();
    Initialize();
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
    float width = (Width * BlockWidth);
    wall_1 = CunstructWall(FVector(0, - BlockWidth + BlockDepth / 2, 0), FRotator(0, 0, 0));
    wall_2 = CunstructWall(FVector(0, - BlockDepth / 2, 0), FRotator(0, 90, 0));
    wall_3 = CunstructWall(FVector(- width + BlockWidth,
                                   - width + BlockDepth / 2, 0), FRotator(0, 180, 0));
    wall_4 = CunstructWall(FVector(- width + BlockWidth + 0,
                                     width - BlockWidth - BlockDepth / 2, 0), FRotator(0, 270, 0));
//    this->wall_1->setOffsetOdd(true);
//    this->wall_4->setOffsetOdd(true);
}

AProceduralWallTest* AProceduralBuilding::CunstructWall(FVector location, FRotator rotation)
{
    AProceduralWallTest* wall = GetWorld()->SpawnActor<AProceduralWallTest>(AProceduralWallTest::StaticClass()) ;
    
    wall->setOffset(false);
//    wall->SetActorLocation(location);
    wall->SetValues(Height, Width, StaticMesh, Material);
    wall->Initialize();
    wall->spawnObject(location);
    wall->SetActorRotation(rotation);
    return wall;
}

