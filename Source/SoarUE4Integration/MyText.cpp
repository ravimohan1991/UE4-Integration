// Fill out your copyright notice in the Description page of Project Settings.

#include "MyText.h"
<<<<<<< HEAD
#include "sml_Client.h"
=======

#include "Soar_Agent.h"
#include "Soar_Kernel.h"

>>>>>>> 025c40a427a729d20c45aa3fc18b189e3d8dc982

using namespace sml;

// Sets default values
AMyText::AMyText()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("RenderedText"));
	MyText->SetWorldSize(70.f);
	MyText->SetTextRenderColor(FColor::Blue);
	MyText->SetHorizontalAlignment(EHTA_Center);

}

// Called when the game starts or when spawned
void AMyText::BeginPlay()
{
<<<<<<< HEAD
	Kernel *k = Kernel::CreateKernelInNewThread();
	Agent *a = k->CreateAgent("soar");
	MyText->SetText(a->ExecuteCommandLine("echo Hello World"));
=======
  Soar_Kernel::Pointer kernel = Soar_Kernel::Create();
  Soar_Agent::Pointer agent = Soar_Agent::Create(kernel, "soar");
	//Kernel *k = Kernel::CreateKernelInNewThread();
	//Agent *a = k->CreateAgent("soar");

	MyText->SetText((*agent)->ExecuteCommandLine("echo Hello World"));
>>>>>>> 025c40a427a729d20c45aa3fc18b189e3d8dc982
	
	
	Super::BeginPlay();
	
}

// Called every frame
void AMyText::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

