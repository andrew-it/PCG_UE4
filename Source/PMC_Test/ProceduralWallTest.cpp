#include "ProceduralWallTest.h"

AProceduralWallTest::AProceduralWallTest()
{
	PrimaryActorTick.bCanEverTick = true;
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


void AProceduralWallTest::createHole()
{
    int rand_y = FMath::RandRange(0, YSizeBlocks-1);
    int rand_x = FMath::RandRange(0, XSizeBlocks - 1);
    int rand_rad = FMath::RandRange(1, FMath::Min(rand_y, rand_x));
    
    // For redusing complexity from NxM to 2Rx2R, where R is radius
    int _x = rand_x - rand_rad >= 0 ? rand_x - rand_rad : 0;
    int x_max = rand_x + rand_rad < XSizeBlocks ? rand_x + rand_rad : XSizeBlocks;

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
}

void AProceduralWallTest::createHoles(int number)
{
    for(int i = 0; i < number; i++)
        this->createHole();
}

void AProceduralWallTest::spawnObject()
{
    float half_brick = BlockWidth / 2.f;
    for (int x = 0; x < XSizeBlocks; ++x)
        for (int y = 0; y < YSizeBlocks; ++y)
            if (getMaskValue(x, y))
            {
                int is_odd = odd_offset ? 1 : 0;
                bool is_y_odd = (y + is_odd) % 2 ? true : false;
                float x_offset = offset && is_y_odd ? half_brick : 0;
                SMComponent->AddInstanceWorldSpace(FTransform(FVector(BlockWidth * x + x_offset,
                                                                      BlockDepth,
                                                                      BlockHeight * y))
                                                   );
            }
}

void AProceduralWallTest::cutTheWall()
{
    const double fx = XSizeBlocks / Frequency;
    const siv::PerlinNoise perlin(Seed);

    for(int x = 0; x < XSizeBlocks; x++)
    {
        int result_height = YSizeBlocks * perlin.octaveNoise0_1(x / fx, Octaves);
        for(int y = result_height; y < YSizeBlocks; y++)
            setMaskValue(x, y, false);
    }
}






















