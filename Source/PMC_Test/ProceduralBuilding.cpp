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
    float wallWidth = (Width * BlockWidth);
    
    wall_1 = ConstructWall(FVector(0, - BlockWidth + BlockDepth / 2, 0), FRotator(0, 0, 0), true);
    
    if(WithDoor)
        wall_2 = ConstructWallWithDoor(FVector(0, - BlockDepth / 2, 0), FRotator(0, 90, 0), false);
    else
        wall_2 = ConstructWall(FVector(0, - BlockDepth / 2, 0), FRotator(0, 90, 0), false);
    
    wall_3 = ConstructWall(FVector(- wallWidth + BlockWidth - BlockDepth,
                                   - wallWidth - BlockDepth / 2, 0), FRotator(0, 180, 0), true);
    wall_4 = ConstructWall(FVector(- wallWidth + BlockWidth - BlockDepth,
                                     wallWidth - BlockWidth / 2, 0), FRotator(0, 270, 0), false);
}

AProceduralWall* AProceduralBuilding::ConstructWall(FVector location, FRotator rotation, bool isOddOffset)
{
    AProceduralWall* wall = GetWorld()->SpawnActor<AProceduralWall>(AProceduralWall::StaticClass()) ;
    
    wall->setOffset(true);
    wall->setOffsetOdd(isOddOffset);
    wall->setCutWall(true);
    wall->SetValues(Height, Width, StaticMesh, Material);
    wall->Initialize();
    wall->spawnObject(location);
    wall->SetActorRotation(rotation);
    
    return wall;
}

AProceduralWall* AProceduralBuilding::ConstructWallWithDoor(FVector location, FRotator rotation, bool isOddOffset)
{
    AProceduralWallWithDoor* wall = GetWorld()->SpawnActor<AProceduralWallWithDoor>(AProceduralWallWithDoor::StaticClass()) ;
    
    wall->setOffset(true);
    wall->setOffsetOdd(isOddOffset);
    wall->setCutWall(true);
    wall->SetValues(Height, Width, StaticMesh, Material);
    wall->Initialize();
    wall->setDoor(Door);
    wall->CreateDoorway();
    wall->spawnObject(location);
    wall->SetActorRotation(rotation);
    
    return wall;
}

