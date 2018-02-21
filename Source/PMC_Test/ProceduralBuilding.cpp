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
    float wallDepth = (Depth * BlockWidth);
    
    auto _doorsNumber = DoorsNumber;
    auto _windowsNumber = WindowsNumber;
    int _w[4] = {0, 1, 1, 0};
    int _d[4] = {0, 0, 1, 1};
    
    for(int i = 0; i < numberOfWalls; i++)
    {
        auto _isOdd = i % 2;
        auto _rotation = FRotator(0, i * 90, 0);
        auto _position = FVector(wallWidth * _w[i],
                                 wallDepth * _d[i],
                                 0);
        auto _length = _isOdd ? Depth : Width;
        auto _sillHeight = 0;
        UStaticMesh* _object = NULL;
        
        if (_doorsNumber-- > 0) {
            _sillHeight = doorSillHeight;
            _object = Door;
        } else if (_windowsNumber-- > 0) {
            _sillHeight = windowSillHeight;
            _object = Window;
        }
        
        walls[i] = ConstructWall(_position, _rotation, true, _length, _object, _sillHeight);
    }
}

AProceduralWall* AProceduralBuilding::ConstructWall(FVector location, FRotator rotation, bool isOddOffset,
                                                    int32 WallLength, UStaticMesh* Object, int32 sillHeight)
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
    wall->SetValues(Height, WallLength, StaticMesh, Material);
    wall->Initialize();
    wall->SetActorLocation(location);
    wall->SetActorRotation(rotation);
    wall->spawnObject();
    
    return wall;
}

