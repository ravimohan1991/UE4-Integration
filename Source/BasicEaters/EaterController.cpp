// Fill out your copyright notice in the Description page of Project Settings.

#include "EaterController.h"


// Sets default values
AEaterController::AEaterController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AEaterController::generateX()
{
	int initialX = 0.f;
	initialX = FMath::RandRange(-7, 7);
	// we have a 3000px x 3000px playing field. since we want it to be 15x15, we must divide the field into 255 200px x 200px squares. -7 to 7 allows 15 squares (including 0). this function generates the x coordinate
	initialX = 200 * initialX;
	return initialX;
}

int AEaterController::generateY()
{
	int initialY = 0.f;
	initialY = FMath::RandRange(-7, 7);
	initialY = 200 * initialY;
	return initialY;
}

void AEaterController::eaterSpawnerFunction(int xLocation, int yLocation)
{
	//begins by getting GameInstance so that the location can be added
	UFieldData* FDGI = Cast<UFieldData>(GetGameInstance());

	//generates vector for spawning
	spawnLocation.X = xLocation;
	spawnLocation.Y = yLocation;
	spawnLocation.Z = 0.f;

	//adds the location of the wall to a global array found in GameInstance in the format of "[object identifier][xlocation][ylocation]". Z location is superfluous because it is constant for all actors
	//"w" identifier is for wall, "e" for eater, "n" for normal food pellet, "b" for bonus food pellet

	//FString arrayLocation = FString(TEXT("w") + FString::FromInt(xLocation) + FString::FromInt(yLocation));
	//FDGI->FieldData.Add(arrayLocation);

	int arrayLocationX = spawnLocation.X / 200 + 7;
	int arrayLocationY = spawnLocation.Y / 200 + 7;
	int arrayIndex = 15 * arrayLocationX + arrayLocationY;
	UE_LOG(LogTemp, Log, TEXT("Made it to while"));
	/*while (FDGI->FieldData[arrayIndex] != "n") {

		spawnLocation.X = generateX();
		spawnLocation.Y = generateY();
		arrayLocationX = spawnLocation.X / 200 + 7;
		arrayLocationY = spawnLocation.Y / 200 + 7;
		arrayIndex = 15 * arrayLocationX + arrayLocationY;
	}*/
	FString arrayObject = FString(TEXT("e"));
	FDGI->FieldData[arrayIndex] = arrayObject;

	//creates the parameters for spawning based off of Unreal Documentation guidelines
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = Instigator;
	//AEater* newEater = GetWorld()->SpawnPawn<AEater>(spawningObject, spawnLocation, FRotator::ZeroRotator, spawnParams);
}

// Called when the game starts or when spawned
void AEaterController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("Eater working"));
	eaterSpawnerFunction(generateX(), generateY());
}

// Called every frame
void AEaterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

