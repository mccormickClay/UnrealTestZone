// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	reachDistance = 100.0f;
	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();


	UE_LOG(LogTemp, Warning, TEXT("Grabber-> BeginPlay()"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UWorld* world = GetWorld();

	FVector playerViewPointLocation;
	FRotator playerViewPointRot;


	world->GetFirstPlayerController()->GetPlayerViewPoint(playerViewPointLocation, playerViewPointRot);
	FVector lineTraceEnd = playerViewPointLocation + playerViewPointRot.Vector() * reachDistance;

	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	FHitResult hit;

	GetWorld()->LineTraceSingleByObjectType(
		hit, 
		playerViewPointLocation, 
		lineTraceEnd, 
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), 
		TraceParameters
	);

	DrawDebugLine(GetWorld(), playerViewPointLocation, lineTraceEnd, FColor(255, 0, 0),false, 0.0f,0, 5.0f);
	
	AActor* actorHit = hit.GetActor();
	if (actorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("The object is: %s"), *(actorHit->GetName()));
	}
}

