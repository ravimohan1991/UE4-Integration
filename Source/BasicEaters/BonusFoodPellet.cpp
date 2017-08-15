// Fill out your copyright notice in the Description page of Project Settings.

#include "BonusFoodPellet.h"
#include "FieldData.h"

// Sets default values
ABonusFoodPellet::ABonusFoodPellet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABonusFoodPellet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABonusFoodPellet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABonusFoodPellet::Destroyed()
{
	UE_LOG(LogTemp, Log, TEXT("Delete"));

	FieldData &fieldData = FieldData::get();
	fieldData.increaseScore(5);

	UE_LOG(LogTemp, Log, TEXT("%d"), fieldData.getScore());
}

