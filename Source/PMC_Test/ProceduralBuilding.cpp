#include "ProceduralBuilding.h"


AProceduralBuilding::AProceduralBuilding()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AProceduralBuilding::BeginPlay()
{
	Super::BeginPlay();
    
    ConstructBuild();
}

void AProceduralBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProceduralBuilding::ConstructBuild()
{
//    float wallLength = 
    
    
    
    this->wall_1 = GetWorld()->SpawnActor<AProceduralBlockBase2D>(AProceduralBlockBase2D::StaticClass());
    this->wall_2 = GetWorld()->SpawnActor<AProceduralBlockBase2D>(AProceduralBlockBase2D::StaticClass());
    this->wall_3 = GetWorld()->SpawnActor<AProceduralBlockBase2D>(AProceduralBlockBase2D::StaticClass());
    this->wall_4 = GetWorld()->SpawnActor<AProceduralBlockBase2D>(AProceduralBlockBase2D::StaticClass());
    
    
}
