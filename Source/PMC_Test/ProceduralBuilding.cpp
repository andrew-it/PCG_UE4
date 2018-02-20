#include "ProceduralBuilding.h"


AProceduralBuilding::AProceduralBuilding()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AProceduralBuilding::BeginPlay()
{
    walls.Init(0, numberOfWalls);
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
    
    auto _doorsNumber = DoorsNumber;
    auto _windowsNumber = WindowsNumber;
    int _sign[4] = {1, -1, 1, -1};
    
    for(int i = 0; i < numberOfWalls; i++) {
        auto _rotation = FRotator(0, i * 90, 0);
        auto _isOdd = i % 2;
        auto _position = FVector(0,
//                                 !_isOdd * wallWidth * _sign[i],
                                 _isOdd * wallWidth * _sign[i],
                                 0);
        
        if (_doorsNumber-- > 0) {
            walls[i] = ConstructWall(_position, _rotation, _isOdd, Door, doorSillHeight);
        } else if (_windowsNumber-- > 0) {
            walls[i] = ConstructWall(_position, _rotation, _isOdd, Window, doorSillHeight);
        } else {
            walls[i] = ConstructWall(_position, _rotation, _isOdd);
        }
    }
    
//    /// wall 1
//    walls[0] = ConstructWall(FVector(0, 0, 0), FRotator(0, 0, 0), true);
//
//    /// wall 2
//    if(WithDoor)
//        walls[1] = ConstructWallWithObject(FVector(BlockDepth / 2,
//                                                 BlockWidth - BlockDepth / 2,
//                                                 0),
//                                         FRotator(0, 90, 0), false, Door, doorSillHeight);
//    else
//        walls[1] = ConstructWall(FVector(0, 0, 0), FRotator(0, 90, 0), false);
//
//    /// wall 3
//    walls[2] = ConstructWall(FVector(wallWidth - BlockDepth,
//                                   wallWidth + BlockWidth,
//                                   0),
//                           FRotator(0, 180, 0), true);
//    /// wall 4
//    if(WithWindow)
//        walls[3] = ConstructWallWithObject(FVector(wallWidth - BlockWidth / 2,
//                                                 wallWidth + BlockDepth / 2,
//                                                 0),
//                                         FRotator(0, 270, 0), true, Window, windowSillHeight);
//    else
//        walls[3] = ConstructWall(FVector(wallWidth - BlockWidth / 2,
//                                       wallWidth + BlockDepth / 2,
//                                       0),
//                               FRotator(0, 270, 0), false);
}

AProceduralWall* AProceduralBuilding::ConstructWall(FVector location, FRotator rotation, bool isOddOffset,
                                                              UStaticMesh* Object, int32 sillHeight)
{
    AProceduralWall* wall;
    if(Object)
    {
        wall = GetWorld()->SpawnActor<AProceduralWallWithObject>(AProceduralWallWithObject::StaticClass());
        dynamic_cast <AProceduralWallWithObject*> (wall)->setObject(Object);
        dynamic_cast <AProceduralWallWithObject*> (wall)->setObjectSillHeight(sillHeight);
    }
    else
        wall = GetWorld()->SpawnActor<AProceduralWall>(AProceduralWall::StaticClass());
    
    wall->setOffset(true);
    wall->setOffsetOdd(isOddOffset);
    wall->setCutWall(Destroyed);
    wall->SetValues(Height, Width, StaticMesh, Material);
    wall->Initialize();
    wall->SetActorLocation(location);
    wall->SetActorRotation(rotation);
    wall->spawnObject();
    
    return wall;
}

