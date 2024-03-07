#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "CubeLineSpawner.generated.h"

UCLASS(Blueprintable)
class ACubeLineSpawner : public AActor
{
    GENERATED_BODY()
    
public:    
    // Sets default values for this actor's properties
    ACubeLineSpawner();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Number of cubes to spawn
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
    int32 NumberOfCubes = 10;

    // Distance between cubes
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
    float DistanceBetweenCubes = 100.0f;

    // Cube size
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
    FVector CubeSize = FVector(100.0f, 100.0f, 100.0f);
};
