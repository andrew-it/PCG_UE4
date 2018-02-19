#include "ProceduralWallWithObject.h"

AProceduralWallWithObject::AProceduralWallWithObject()
{
    SMCObject = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("Object"));
}

void AProceduralWallWithObject::CreateObjectway()
{
    if (Object)
    {
        auto boundingBoxSize = Object->GetBoundingBox().GetSize();
        float ObjectWidth = boundingBoxSize.Y;
        float ObjectHeight = boundingBoxSize.Z;
        
        SMCObject->SetStaticMesh(Object);
        
        ObjectWidthInBlocks = ObjectWidth / BlockWidth;
        ObjectHeightInBlocks = ObjectHeight / BlockHeight;
        
        if (ObjectWidthInBlocks >= XSizeBlocks || ObjectHeightInBlocks >= ZSizeBlocks)
        {
            UE_LOG(LogTemp, Error, TEXT("Object IS BIGGER THAN WALL"));
            return;
        }
        
        int xObjectOffset = FMath::RandRange(1, XSizeBlocks - ObjectWidthInBlocks - 1);
        int yObjectOffset = 0;
        if(windowSillHeight + ObjectHeightInBlocks < ZSizeBlocks)
            yObjectOffset = windowSillHeight;
        else
            UE_LOG(LogTemp, Error, TEXT("SillHeight+windowHeight IS BIGGER THAN WALL HEIGHT"));
        
        
        for(int x = xObjectOffset; x < ObjectWidthInBlocks + xObjectOffset; x++)
        {
            for(int y = 0; y < yObjectOffset; y++)
                setMaskValue(x, y, true);
            
            for(int y = yObjectOffset; y < ObjectHeightInBlocks + yObjectOffset; y++)
                setMaskValue(x, y, false);
        }
        

        UE_LOG(LogTemp, Warning, TEXT("%d %d"), yObjectOffset, windowSillHeight);
        SMCObject->AddInstanceWorldSpace(FTransform(FVector(BlockDepth,
                                                          - 20 - xObjectOffset * BlockWidth - BlockWidth / 2,
                                                          - BlockHeight * 2)));
        SMCObject->SetWorldRotation(FRotator(0, 180, 0));
        
    } else {
        UE_LOG(LogTemp, Error, TEXT("Object IS NULL"));
    }
}
