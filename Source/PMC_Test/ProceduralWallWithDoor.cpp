#include "ProceduralWallWithDoor.h"

AProceduralWallWithDoor::AProceduralWallWithDoor()
{
    SMCDoor = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("door"));
//    RootComponent = Door;
}

void AProceduralWallWithDoor::CreateDoorway()
{
    if (Door)
    {
        auto boundingBoxSize = Door->GetBoundingBox().GetSize();
        float doorWidth = boundingBoxSize.Y;
        float doorHeight = boundingBoxSize.Z;
        
        SMCDoor->SetStaticMesh(Door);
        
        doorWidthInBlocks = doorWidth / BlockWidth;
        doorHeightInBlocks = doorHeight / BlockHeight;
        
        if (doorWidthInBlocks >= XSizeBlocks || doorHeightInBlocks >= ZSizeBlocks)
        {
            UE_LOG(LogTemp, Error, TEXT("DOOR IS BIGGER THAN WALL"));
            return;
        }
        
        int xDoorOffset = FMath::RandRange(1, XSizeBlocks - doorWidthInBlocks - 1);
        
        for(int x = xDoorOffset; x < doorWidthInBlocks+xDoorOffset; x++)
            for(int y = 0; y < doorHeightInBlocks; y++)
            {
                setMaskValue(x, y, false);
            }
        
        UE_LOG(LogTemp, Warning, TEXT("%f"), doorWidthInBlocks*BlockWidth);
        SMCDoor->AddInstanceWorldSpace(FTransform(FVector(BlockDepth,
                                                          - 20 - xDoorOffset * BlockWidth - BlockWidth / 2,
                                                          - BlockHeight * 2)));
        SMCDoor->SetWorldRotation(FRotator(0, 180, 0));
        
    } else {
        UE_LOG(LogTemp, Error, TEXT("DOOR IS NULL"));
    }
}
