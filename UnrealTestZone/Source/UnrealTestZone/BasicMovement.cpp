// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicMovement.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UBasicMovement::UBasicMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//speed = FVector(1.0f, 0.0f, 0.0f);
	// ...
}


// Called when the game starts
void UBasicMovement::BeginPlay()
{
	Super::BeginPlay();
	speed = GetOwner()->GetActorForwardVector();
	// ...
	
}


// Called every frame
void UBasicMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	//FVector currentLocation = GetOwner()->GetActorLocation();
	//GetOwner()->SetActorLocation(currentLocation + speed);
	//UE_LOG(LogTemp, Warning, TEXT("Forward Vector is: %s"), *(GetOwner()->GetActorForwardVector().ToString()));
}

