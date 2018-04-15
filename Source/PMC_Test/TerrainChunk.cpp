// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainChunk.h"
#include "TerrainTypes.h"

void ATerrainChunk::spawnObject()
{
	for (int x = 0; x < XSizeBlocks; ++x)
		for (int y = 0; y < YSizeBlocks; ++y)
			for (int z = 0; z < ZSizeBlocks; ++z)
            {
                int maskValue = getMaskValue(x, y, z);
				if(maskValue)
				{
					FVector current_location = this->GetActorLocation();
                    
                    auto comp = SMComponent->AddInstance(FTransform(current_location +
                                                                    FVector(BlockWidth * x,
                                                                            BlockDepth * y,
                                                                            BlockHeight * z)));
                    UE_LOG(LogTemp, Warning, TEXT("Component address: %d"), comp);
                
                    /*switch(maskValue) {
                        case GRASS:
                            SMComponent->AddInstance(FTransform(current_location +
                                                                FVector(BlockWidth * x,
                                                                        BlockDepth * y,
                                                                        BlockHeight * z)));
                            break;
                            
                        case DIRT:
                            SMComponent->AddInstance(FTransform(current_location +
                                                                FVector(BlockWidth * x,
                                                                        BlockDepth * y,
                                                                        BlockHeight * z)));
                            break;
                            
                        case STONE:
                            SMComponent->AddInstance(FTransform(current_location +
                                                                FVector(BlockWidth * x,
                                                                        BlockDepth * y,
                                                                        BlockHeight * z)));
                            break;
                            
                        case WATER:
                            SMComponent->AddInstance(FTransform(current_location +
                                                                FVector(BlockWidth * x,
                                                                        BlockDepth * y,
                                                                        BlockHeight * z)));
                            break;
                            
                    }*/
				}
            }
}

void ATerrainChunk::Initialize(int numberOfXBlocks, int numberOfYBlocks, int numberOfZBlocks,
                               UStaticMesh* StaticMesh)
{
	//Super::Initialize();

	XSizeBlocks = numberOfXBlocks;
	YSizeBlocks = numberOfYBlocks;
    ZSizeBlocks = numberOfZBlocks;
    
    this->StaticMesh = StaticMesh;

	Initialize();
}

void ATerrainChunk::InitMaterials(UMaterialInstance* Material, UMaterialInstance* Water_Material,
                                  UMaterialInstance* Dirt_Material, UMaterialInstance* Stone_Material,
                                  UMaterialInstance* Grass_Material)
{
    this->Material = Material;
    this->Water_Material = Water_Material;
    this->Dirt_Material = Dirt_Material;
    this->Stone_Material = Stone_Material;
    this->Grass_Material = Grass_Material;
}

void ATerrainChunk::Initialize()
{
	Super::Initialize();

	if (StaticMesh)
	{
		auto boundingBoxSize = StaticMesh->GetBoundingBox().GetSize();
		BlockWidth = boundingBoxSize.X;
		BlockDepth = boundingBoxSize.Y;
		BlockHeight = boundingBoxSize.Z;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("StaticMesh is null"));
	}

	//spawnObject();
}

void ATerrainChunk::BeginPlay()
{
	Super::BeginPlay();
	
}
