#include "ProceduralWallWithObject.h"

AProceduralWallWithObject::AProceduralWallWithObject()
{
    SMCObject = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("Object"));
}

void AProceduralWallWithObject::spawnObject()
{
    CreateObjectway();
    Super::spawnObject();
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
        
        int xObjectOffset = 10;//FMath::RandRange(1, XSizeBlocks - ObjectWidthInBlocks - 1);
        int yObjectOffset = 0;
        
        if(objectSillHeight + ObjectHeightInBlocks < ZSizeBlocks)
            yObjectOffset = objectSillHeight;
        else
            UE_LOG(LogTemp, Error, TEXT("SillHeight+windowHeight IS BIGGER THAN WALL HEIGHT"));
        
        
        for(int x = xObjectOffset; x < ObjectWidthInBlocks + xObjectOffset; x++)
        {
            for(int y = 0; y < yObjectOffset; y++)
                setMaskValue(x, y, true);
            
            for(int y = yObjectOffset; y < ObjectHeightInBlocks + yObjectOffset; y++)
                setMaskValue(x, y, false);
        }
        
        auto _loc = GetActorLocation();
        auto _rot = GetActorRotation();
        
        auto _objectPlace = (xObjectOffset + ObjectWidthInBlocks) * BlockWidth;
        
        auto _x = 0;
        auto _y = _objectPlace;
        if((int)(_rot.Yaw) % 180 == 0)
        {
            _x = _objectPlace;
            _y = 0;
        }
        
        SMCObject->AddInstance(FTransform(_rot + FRotator(0, 90, 0),
                                          _loc + FVector(_x, _y, objectSillHeight * BlockHeight))
                               );
    } else {
        UE_LOG(LogTemp, Error, TEXT("Object IS NULL"));
    }
}
