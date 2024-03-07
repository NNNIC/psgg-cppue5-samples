#include "CubeLineSpawner.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
ACubeLineSpawner::ACubeLineSpawner()
{
    // Set this actor to call Tick() if required
    PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ACubeLineSpawner::BeginPlay()
{
    Super::BeginPlay();

    UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (!CubeMesh) return;

    for(int32 i = 0; i < NumberOfCubes; ++i)
    {
        // Calculate the location for the current cube
        FVector Location(0, 0, i * DistanceBetweenCubes);
        Location += GetActorLocation(); // Offset by the spawner's location

        // Create a new StaticMeshComponent dynamically
        UStaticMeshComponent* CubeComponent = NewObject<UStaticMeshComponent>(this);
        if (CubeComponent)
        {
            CubeComponent->RegisterComponent(); // Register the component with the engine
            CubeComponent->SetStaticMesh(CubeMesh); // Set the cube mesh
            CubeComponent->SetWorldLocation(Location); // Set the location of the cube
            CubeComponent->SetRelativeScale3D(CubeSize / 100.0f); // Set the size of the cube
            CubeComponent->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform); // Attach the cube to the spawner
        }
    }
}
