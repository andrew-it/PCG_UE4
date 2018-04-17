// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainChunk.h"
#include "TerrainTypes.h"

ATerrainChunk::ATerrainChunk()
{
    Water_SMComponent = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("water block"));
    Dirt_SMComponent = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("dirt block"));
    Stone_SMComponent = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("stone block"));
    Grass_SMComponent = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("grass block"));
}

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
                
                    switch(maskValue) {
                        case GRASS:
                            Grass_SMComponent->AddInstance(FTransform(current_location +
                                                                FVector(BlockWidth * x,
                                                                        BlockDepth * y,
                                                                        BlockHeight * z)));
                            break;
                     
                        case DIRT:
                            Dirt_SMComponent->AddInstance(FTransform(current_location +
                                                                FVector(BlockWidth * x,
                                                                        BlockDepth * y,
                                                                        BlockHeight * z)));
                            break;
                            
                        case STONE:
                            Stone_SMComponent->AddInstance(FTransform(current_location +
                                                                FVector(BlockWidth * x,
                                                                        BlockDepth * y,
                                                                        BlockHeight * z)));
                            break;
                            
                        case WATER:
                            Water_SMComponent->AddInstance(FTransform(current_location +
                                                                FVector(BlockWidth * x,
                                                                        BlockDepth * y,
                                                                        BlockHeight * z)));
                            break;
                     
                    }
				}
            }
}

void ATerrainChunk::Initialize(int numberOfXBlocks, int numberOfYBlocks, int numberOfZBlocks,
                               UStaticMesh* StaticMesh)
{
	XSizeBlocks = numberOfXBlocks;
	YSizeBlocks = numberOfYBlocks;
    ZSizeBlocks = numberOfZBlocks;
    
    this->StaticMesh = StaticMesh;
    
    
    Water_SMComponent->AttachToComponent(sceneComponent, FAttachmentTransformRules::KeepWorldTransform);
    Dirt_SMComponent->AttachToComponent(sceneComponent, FAttachmentTransformRules::KeepWorldTransform);
    Stone_SMComponent->AttachToComponent(sceneComponent, FAttachmentTransformRules::KeepWorldTransform);
    Grass_SMComponent->AttachToComponent(sceneComponent, FAttachmentTransformRules::KeepWorldTransform);
    
    Water_SMComponent->SetStaticMesh(StaticMesh);
    Dirt_SMComponent->SetStaticMesh(StaticMesh);
    Stone_SMComponent->SetStaticMesh(StaticMesh);
    Grass_SMComponent->SetStaticMesh(StaticMesh);
    
    Water_SMComponent->SetMaterial(0, Water_Material);
    Dirt_SMComponent->SetMaterial(0, Dirt_Material);
    Stone_SMComponent->SetMaterial(0, Stone_Material);
    Grass_SMComponent->SetMaterial(0, Grass_Material);
    
    
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
