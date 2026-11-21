#include "YIXI_Interaction/DialogueToy/YIXIStoryToyPickup.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Pawn.h"
#include "UObject/ConstructorHelpers.h"
#include "YIXI_Interaction/DialogueToy/YIXIToyCarryComponent.h"

#define LOCTEXT_NAMESPACE "YIXIStoryToyPickup"

AYIXIStoryToyPickup::AYIXIStoryToyPickup()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("ToyPickupRoot")));

	ToyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ToyMesh"));
	ToyMesh->SetupAttachment(GetRootComponent());
	ToyMesh->SetRelativeLocation(FVector(0.0, 0.0, 10.0));
	ToyMesh->SetRelativeScale3D(FVector(0.2));
	ToyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	static const ConstructorHelpers::FObjectFinder<UStaticMesh> PlaceholderMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	ToyMesh->SetStaticMesh(PlaceholderMesh.Object);

	InteractionAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("InteractionAnchor"));
	InteractionAnchor->SetupAttachment(GetRootComponent());
	InteractionAnchor->SetRelativeLocation(FVector(0.0, 0.0, 16.0));
}

void AYIXIStoryToyPickup::BeginPlay()
{
	Super::BeginPlay();
	if (!bPickupGateSet)
	{
		SetPickupAvailable(bStartPickupAvailable);
	}
}

void AYIXIStoryToyPickup::SetPickupAvailable(bool bAvailable)
{
	bPickupGateSet = true;
	bPickupAvailable = bAvailable && !bClaimed;
}

bool AYIXIStoryToyPickup::IsPickupAvailable() const
{
	return bPickupAvailable && !bClaimed && IsValid(ToyMesh.Get()) && ToyMesh->GetStaticMesh();
}

void AYIXIStoryToyPickup::CommitPickup()
{
	bClaimed = true;
	bPickupAvailable = false;
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
}

bool AYIXIStoryToyPickup::CanInteract_Implementation(APawn* Interactor) const
{
	const UYIXIToyCarryComponent* Carry = UYIXIToyCarryComponent::FindForPawn(Interactor);
	UYIXIToyCarryComponent::FAttachment Attachment;
	return IsPickupAvailable() && IsValid(Interactor) && Interactor->GetWorld() == GetWorld()
		&& Carry && Carry->CanTakeToy(Interactor) && Carry->FindAttachment(*Interactor, false, Attachment);
}

void AYIXIStoryToyPickup::Interact_Implementation(APawn* Interactor)
{
	if (IYIXIInteractable::Execute_CanInteract(this, Interactor))
	{
		if (UYIXIToyCarryComponent* Carry = UYIXIToyCarryComponent::FindForPawn(Interactor))
		{
			Carry->TryPickup(Interactor, *this);
		}
	}
}

FYIXIInteractionPrompt AYIXIStoryToyPickup::GetInteractionPrompt_Implementation(APawn* Interactor) const
{
	FYIXIInteractionPrompt Prompt;
	Prompt.WorldLocation = InteractionAnchor->GetComponentLocation();
	Prompt.bShowPrompt = IsPickupAvailable();
	Prompt.DetectionRange = Prompt.bShowPrompt ? DetectionRange : 0.0f;
	Prompt.InteractRange = Prompt.bShowPrompt ? InteractRange : 0.0f;
	Prompt.ActionText = LOCTEXT("PickupToy", "Pick up toy");
	return Prompt;
}

#undef LOCTEXT_NAMESPACE
