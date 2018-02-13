// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralWallTest.h"



// Sets default values
AProceduralWallTest::AProceduralWallTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    SMComponent = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("brick"));
//    RootComponent = SMComponent;
}

// Called when the game starts or when spawned
void AProceduralWallTest::BeginPlay()
{
    Super::BeginPlay();
    

    createHoles(holes_number);
    if(cut_wall) cutTheWall();

    spawnObject();
}

// Called every frame
void AProceduralWallTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AProceduralWallTest::createHole(){
    int rand_y = FMath::RandRange(0, YSizeBlocks-1);
    int rand_x = FMath::RandRange(0, XSizeBlocks - 1);
    int rand_rad = FMath::RandRange(1, FMath::Min(rand_y, rand_x));
    
    // For redusing complexity from NxM to 2Rx2R, where R is radius
    int _x = rand_x - rand_rad >= 0 ? rand_x - rand_rad : 0;
    int x_max = rand_x + rand_rad < XSizeBlocks ? rand_x + rand_rad : XSizeBlocks;
    UE_LOG(LogTemp, Warning, TEXT("x: %d, x_max: %d"), _x, x_max);
    int _y = rand_y - rand_rad >= 0 ? rand_y - rand_rad : 0;
    int y_max = rand_y + rand_rad < YSizeBlocks ? rand_y + rand_rad : YSizeBlocks;
    
    
    int deleted_bricks_counter = 0;
    for(int y = _y; y < y_max; y++)
        for(int x = _x; x < x_max; x++)
            if((y - rand_y)*(y - rand_y) + (x-rand_x)*(x-rand_x) <= rand_rad*rand_rad)
            {
                deleted_bricks_counter++;
                setMaskValue(x, y, false);
            }
    UE_LOG(LogTemp, Warning, TEXT("Hole coord: y: %d x: %d, r: %d; Deleted bricks number: x%d"), rand_y, rand_x, rand_rad, deleted_bricks_counter);
}

void AProceduralWallTest::createHoles(int number){
    for(int i = 0; i < number; i++)
        this->createHole();
}

void AProceduralWallTest::spawnObject(){
    auto initialPosition = GetActorLocation();
    auto pos = SMComponent->GetComponentLocation();
//    if(initialPosition.X != pos.X)
        UE_LOG(LogTemp, Warning, TEXT("SHIT %d %d"), initialPosition.X, pos.X)
    UE_LOG(LogTemp, Warning, TEXT("Actor location: x = %d; y = %d; z = %d;\nSMC location: x = %d; y = %d; z = %d;"), initialPosition.X, initialPosition.Y, initialPosition.Z, pos.X, pos.Y, pos.Z);
    
    float half_brick = BlockWidth / 2.f;
    for (int x = 0; x < XSizeBlocks; ++x)
        for (int y = 0; y < YSizeBlocks; ++y)
            if (getMaskValue(x, y))
            {
                int is_odd = odd_offset ? 1 : 0;
                bool is_y_odd = (y + is_odd) % 2 ? true : false;
                float x_offset = offset && is_y_odd ? half_brick : 0;
                FTransform NewTransf;
                NewTransf.SetLocation(pos + FVector(BlockWidth * x + x_offset,
                                              BlockDepth, BlockHeight * y));
                SMComponent->AddInstance(NewTransf);
            }
}

void AProceduralWallTest::cutTheWall(){
    const double fx = XSizeBlocks / Frequency;
    const siv::PerlinNoise perlin(Seed);

    for(int x = 0; x < XSizeBlocks; x++)
    {
        int result_height = YSizeBlocks * perlin.octaveNoise0_1(x / fx, Octaves);
        for(int y = result_height; y < YSizeBlocks; y++)
            setMaskValue(x, y, false);
	
//        UE_LOG(LogTemp, Warning, TEXT("height: %d"), result_height);
    }
}






















