#include "MyActor.h"
#include "ProceduralMeshComponent.h"


// Sets default values
AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;

    mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("mesh"));
    RootComponent = mesh;
    
    TArray<FVector> vertices;
    vertices.Add(FVector(0, 0, 0));     //  0th vertice
    vertices.Add(FVector(0, 100, 0));   //  1th vertice
    vertices.Add(FVector(0, 0, 100));   //  2nd vertice
    vertices.Add(FVector(0, 100, 100)); //  3rd vertice
    
    TArray<int32> Triangle;
    
    //I have created 4 triangle because we need to make sure it is rendered from behind as well. Otherwise, the object will be seen from front only and not from behind.
    Triangle.Add(0);
    Triangle.Add(1);       // for front face - clockwise direction
    Triangle.Add(2);
    
    Triangle.Add(1);
    Triangle.Add(2);      // for front face - clockwise direction
    Triangle.Add(3);
    
    Triangle.Add(2);
    Triangle.Add(1);      // for back face - anti-clockwise direction
    Triangle.Add(0);
    
    Triangle.Add(3);
    Triangle.Add(2);      // for back face - anti-clockwise direction
    Triangle.Add(1);
    
    TArray<FVector> normals;
    normals.Add(FVector(1, 0, 0));
    normals.Add(FVector(1, 0, 0));
    normals.Add(FVector(1, 0, 0));                    // you need to calculate the direction of normals, using 3d vectors.
    normals.Add(FVector(1, 0, 0));
    
    TArray<FVector2D> UV0;
    UV0.Add(FVector2D(1, 1));
    UV0.Add(FVector2D(0, 1));
    UV0.Add(FVector2D(1, 0));
    UV0.Add(FVector2D(0, 0));
    
    TArray<FLinearColor> vertexColors;
    vertexColors.Add(FLinearColor(0.75, 0.00, 0.00, 1.0));
    vertexColors.Add(FLinearColor(0.75, 0.00, 0.00, 1.0));
    vertexColors.Add(FLinearColor(0.75, 0.00, 0.75, 1.0));                              // the 4th argument determines alpha value (0,1)
    vertexColors.Add(FLinearColor(0.75, 0.00, 0.75, 1.0));
    
    TArray<FProcMeshTangent> tangents;
    tangents.Add(FProcMeshTangent(0, 1, 0));
    tangents.Add(FProcMeshTangent(0, 1, 0));
    tangents.Add(FProcMeshTangent(0, 1, 0));
    tangents.Add(FProcMeshTangent(0, 1, 0));
    
    mesh->CreateMeshSection_LinearColor(1, vertices, Triangle, normals, UV0, vertexColors, tangents, false);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

