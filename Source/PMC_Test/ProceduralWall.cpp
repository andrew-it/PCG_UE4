#include "ProceduralWall.h"

AProceduralWall::AProceduralWall()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AProceduralWall::BeginPlay()
{
    Super::BeginPlay();
}

void AProceduralWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProceduralWall::createHole()
{
    int rand_y = FMath::RandRange(0, ZSizeBlocks-1);
    int rand_x = FMath::RandRange(0, XSizeBlocks - 1);
    int rand_rad = FMath::RandRange(1, FMath::Min(rand_y, rand_x));
    
    // For redusing complexity from NxM to DxD, where D is diameter (D == R*R)
    int _x = rand_x - rand_rad >= 0 ? rand_x - rand_rad : 0;
    int x_max = rand_x + rand_rad < XSizeBlocks ? rand_x + rand_rad : XSizeBlocks;

    int _y = rand_y - rand_rad >= 0 ? rand_y - rand_rad : 0;
    int y_max = rand_y + rand_rad < ZSizeBlocks ? rand_y + rand_rad : ZSizeBlocks;
    
    
    int deleted_bricks_counter = 0;
    for(int y = _y; y < y_max; y++)
        for(int x = _x; x < x_max; x++)
            if((y - rand_y)*(y - rand_y) + (x-rand_x)*(x-rand_x) <= rand_rad*rand_rad)
            {
                deleted_bricks_counter++;
                setMaskValue(x, y, false);
            }
}

void AProceduralWall::createHoles(int number)
{
    for(int i = 0; i < number; i++)
        this->createHole();
}

void AProceduralWall::spawnObject()
{
    float half_brick = BlockWidth / 2.f;
    for (int x = 0; x < XSizeBlocks; ++x)
        for (int y = 0; y < ZSizeBlocks; ++y)
            if (getMaskValue(x, y))
            {
                int is_odd = odd_offset ? 1 : 0;
                bool is_y_odd = (y + is_odd) % 2 ? true : false;
                float x_offset = offset && is_y_odd ? half_brick : 0;
                SMComponent->AddInstance(FTransform(FVector(BlockWidth * x + x_offset + BlockDepth / 2,
                                                            0,
                                                            BlockHeight * y))
                                         );
            }
}

void AProceduralWall::cutTheWall()
{
    const double fx = XSizeBlocks / Frequency;
    const siv::PerlinNoise perlin(Seed);

    for(int x = 0; x < XSizeBlocks; x++)
    {
        int result_height = ZSizeBlocks * perlin.octaveNoise0_1(x / fx, Octaves);
        for(int y = result_height; y < ZSizeBlocks; y++)
            setMaskValue(x, y, false);
    }
}

void AProceduralWall::Initialize()
{
    Super::Initialize();
    createHoles(holes_number);
    if(cut_wall) cutTheWall();
}
