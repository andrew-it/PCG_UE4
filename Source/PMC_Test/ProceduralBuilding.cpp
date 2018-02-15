#include "ProceduralBuilding.h"


AProceduralBuilding::AProceduralBuilding()
{
    PrimaryActorTick.bCanEverTick = true;
    
}

void AProceduralBuilding::BeginPlay()
{
    Super::BeginPlay();
    
    static bool isInitialized = false;
    if(!isInitialized){
        Initialize();
        isInitialized = true;
    }
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
    this->wall_1 = GetWorld()->SpawnActor<AProceduralWallTest>(AProceduralWallTest::StaticClass());
    this->wall_2 = GetWorld()->SpawnActor<AProceduralWallTest>(AProceduralWallTest::StaticClass());
    this->wall_3 = GetWorld()->SpawnActor<AProceduralWallTest>(AProceduralWallTest::StaticClass());
    this->wall_4 = GetWorld()->SpawnActor<AProceduralWallTest>(AProceduralWallTest::StaticClass());
    
    this->wall_1->SetValues(Height, Width, StaticMesh, Material);
    this->wall_2->SetValues(Height, Width, StaticMesh, Material);
    this->wall_3->SetValues(Height, Width, StaticMesh, Material);
    this->wall_4->SetValues(Height, Width, StaticMesh, Material);

    this->wall_1->setOffset(true);
    this->wall_2->setOffset(true);
    this->wall_3->setOffset(true);
    this->wall_4->setOffset(true);
    
    this->wall_1->SetActorRotation(this->wall_1->GetActorRotation() + FRotator(0, 45, 0));
    this->wall_3->SetActorRotation(this->wall_3->GetActorRotation() + FRotator(0, 90, 0));
    
    this->wall_1->setOffsetOdd(true);
    this->wall_3->setOffsetOdd(true);

    this->wall_1->SetActorLocation(FVector(-100, -100, 0));
    this->wall_2->SetActorLocation(FVector(200, 200, 0));
    this->wall_3->SetActorLocation(FVector(400, 400, 0));
    this->wall_4->SetActorLocation(FVector(600, 600, 0));

    this->wall_1->Initialize();
    this->wall_2->Initialize();
    this->wall_3->Initialize();
    this->wall_4->Initialize();


    

}
