// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralWallTest.h"



// Sets default values
AProceduralWallTest::AProceduralWallTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    SMComponent = CreateDefaultSubobject < UInstancedStaticMeshComponent >(TEXT("brick"));

}

// Called when the game starts or when spawned
void AProceduralWallTest::BeginPlay()
{
	Super::BeginPlay();
    
    destroyed_mask.Init(true, WallHeight*WallWidth);
    
    createHoles(holes_number);
    
    cutTheWall();
    
    if (SMesh)
    {
        SMComponent->SetStaticMesh(SMesh);
    }
    
    spawnWall();
}

// Called every frame
void AProceduralWallTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProceduralWallTest::setMaskValue(int x, int y, bool value){
    destroyed_mask[WallWidth*y+x] = value;
}

bool AProceduralWallTest::getMaskValue(int x, int y){
    return destroyed_mask[WallWidth*y+x];
}

void AProceduralWallTest::initMask(bool value){
    for(int i = 0; i < WallWidth*WallHeight; i++)
            this->destroyed_mask[i] = value;
}

void AProceduralWallTest::createHole(){
    int rand_y = FMath::RandRange(0, WallHeight-1);
    int rand_x = FMath::RandRange(0, WallWidth - 1);
    int rand_rad = FMath::RandRange(1, FMath::Min(rand_y, rand_x));
    
    // For redusing complexity from NxM to 2Rx2R, where R is radius
    int _x = rand_x - rand_rad >= 0 ? rand_x - rand_rad : 0;
    int x_max = rand_x + rand_rad < WallWidth ? rand_x + rand_rad : WallWidth;
    UE_LOG(LogTemp, Warning, TEXT("x: %d, x_max: %d"), _x, x_max);
    int _y = rand_y - rand_rad >= 0 ? rand_y - rand_rad : 0;
    int y_max = rand_y + rand_rad < WallHeight ? rand_y + rand_rad : WallHeight;
    
    
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

void AProceduralWallTest::spawnWall(){
    auto half_brick = BrickWidth / 2;
    for(int i = 0; i < WallWidth; i++){
        for(int j = 0; j < WallHeight; j++){
            if(getMaskValue(i, j))
            {
                float f_offset = offset && j % 2 ? half_brick : 0;
                FTransform NewTransf;
                NewTransf.SetLocation(FVector(BrickWidth * i + f_offset, BrickDepth, BrickHeight*j));
                SMComponent->AddInstance(NewTransf);
            }
        }
    }
}

void AProceduralWallTest::cutTheWall(){
    const double fx = WallWidth / Frequency;
    const siv::PerlinNoise perlin(Seed);
    for(int w_index = 0; w_index < WallWidth; w_index++){
        int result_height = WallHeight * perlin.octaveNoise0_1(w_index / fx, Octaves);
        for(int h_index = result_height; h_index < WallHeight; h_index++)
            setMaskValue(w_index, h_index, false);
        UE_LOG(LogTemp, Warning, TEXT("height: %d"), result_height);
    }
}























