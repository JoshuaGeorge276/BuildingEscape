// Copyright Joshua George 2017

#pragma once
#include "Engine.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h" 
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	float Reach = 100.f;

	FString OwnerName;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;


	// Raycast and grab what is in reach.
	void Grab();

	void Release();

	void FindPhysicsHandleComponent();

	void SetupInputComponent();

	FHitResult GetFirstPhysicsBodyInReach();

	FVector GetLineTraceEnd();

	FVector GetLineTraceStart();
};

