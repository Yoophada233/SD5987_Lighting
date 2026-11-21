#include "YIXI_Interaction/DialogueToy/YIXIStoryGirl.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Pawn.h"
#include "UObject/ConstructorHelpers.h"

#define LOCTEXT_NAMESPACE "YIXIStoryGirl"

AYIXIStoryGirl::AYIXIStoryGirl()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("StoryRoot")));

	GirlMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GirlMesh"));
	GirlMesh->SetupAttachment(GetRootComponent());
	GirlMesh->SetRelativeLocation(FVector(0.0, 0.0, 65.0));
	GirlMesh->SetRelativeScale3D(FVector(0.42, 0.42, 1.3));
	GirlMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	static const ConstructorHelpers::FObjectFinder<UStaticMesh> PlaceholderMesh(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	GirlMesh->SetStaticMesh(PlaceholderMesh.Object);

	InteractionAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("InteractionAnchor"));
	InteractionAnchor->SetupAttachment(GetRootComponent());
	InteractionAnchor->SetRelativeLocation(FVector(0.0, 0.0, 110.0));

	RequestDialogue = LOCTEXT("RequestDialogue", "Could you look for my toy in the back courtyard?");
}

void AYIXIStoryGirl::BeginPlay()
{
	Super::BeginPlay();
	if (!bRequestGateSet)
	{
		SetRequestAvailable(bStartRequestAvailable);
	}
}

void AYIXIStoryGirl::SetRequestAvailable(bool bAvailable)
{
	bRequestGateSet = true;
	if (RequestState == EYIXIStoryGirlState::Waiting || RequestState == EYIXIStoryGirlState::RequestReady)
	{
		RequestState = bAvailable ? EYIXIStoryGirlState::RequestReady : EYIXIStoryGirlState::Waiting;
	}
}

void AYIXIStoryGirl::SetUnavailable()
{
	bRequestGateSet = true;
	RequestState = EYIXIStoryGirlState::Unavailable;
}

bool AYIXIStoryGirl::CanInteract_Implementation(APawn* Interactor) const
{
	return RequestState == EYIXIStoryGirlState::RequestReady
		&& IsValid(Interactor)
		&& Interactor->IsPlayerControlled()
		&& Interactor->GetWorld() == GetWorld();
}

void AYIXIStoryGirl::Interact_Implementation(APawn* Interactor)
{
	if (RequestState != EYIXIStoryGirlState::RequestReady
		|| !IYIXIInteractable::Execute_CanInteract(this, Interactor))
	{
		return;
	}

	RequestState = EYIXIStoryGirlState::Requested;
	OnToyRequested.Broadcast(Interactor);
}

FYIXIInteractionPrompt AYIXIStoryGirl::GetInteractionPrompt_Implementation(APawn* Interactor) const
{
	FYIXIInteractionPrompt Prompt;
	Prompt.WorldLocation = InteractionAnchor->GetComponentLocation();
	Prompt.bShowPrompt = RequestState == EYIXIStoryGirlState::RequestReady;
	Prompt.DetectionRange = Prompt.bShowPrompt ? DetectionRange : 0.0f;
	Prompt.InteractRange = Prompt.bShowPrompt ? InteractRange : 0.0f;
	Prompt.ActionText = LOCTEXT("AskAboutToy", "Talk");
	return Prompt;
}

#undef LOCTEXT_NAMESPACE
