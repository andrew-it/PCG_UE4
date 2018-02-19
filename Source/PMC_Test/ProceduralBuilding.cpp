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
    
    /// wall 1
    wall_1 = ConstructWall(FVector(0, - BlockWidth + BlockDepth / 2, 0), FRotator(0, 0, 0), true);
    /// wall 2
    if(WithDoor)
        wall_2 = ConstructWallWithObject(FVector(0, - BlockDepth / 2, 0), FRotator(0, 90, 0), false, Door, doorSillHeight);
    else
        wall_2 = ConstructWall(FVector(0, - BlockDepth / 2, 0), FRotator(0, 90, 0), false);
    /// wall 3
    wall_3 = ConstructWall(FVector(- wallWidth + BlockWidth - BlockDepth,
                                   - wallWidth - BlockDepth / 2, 0), FRotator(0, 180, 0), true);
    /// wall 4
    if(WithWindow)
        wall_4 = ConstructWallWithObject(FVector(- wallWidth + BlockWidth - BlockDepth,
                                                 wallWidth - BlockWidth / 2, 0), FRotator(0, 270, 0), true, Window, windowSillHeight);
    else
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

AProceduralWall* AProceduralBuilding::ConstructWallWithObject(FVector location, FRotator rotation, bool isOddOffset,
                                                              UStaticMesh* Object, int32 sillHeight)
{
    AProceduralWallWithObject* wall = GetWorld()->SpawnActor<AProceduralWallWithObject>(AProceduralWallWithObject::StaticClass()) ;
    
    wall->setOffset(true);
    wall->setOffsetOdd(isOddOffset);
    wall->setCutWall(true);
    wall->SetValues(Height, Width, StaticMesh, Material);
    wall->Initialize();
    wall->setObject(Object);
    wall->setObjectSillHeight(sillHeight);
    wall->spawnObject(location);
    wall->SetActorRotation(rotation);
    
    return wall;
}

