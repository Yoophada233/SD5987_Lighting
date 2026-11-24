#include "YIXI_Interaction/Story/YIXIV3Cinematic.h"
#include "YIXIFormalCutFrameHold.h"
#include "YIXI_Interaction/Story/YIXIInteractionStoryCoordinator.h"
#include "YIXI_Interaction/Story/YIXIV3AudioComponent.h"
#include "YIXI_Interaction/DialogueToy/YIXIStoryGirl.h"
#include "YIXI_Interaction/DialogueToy/YIXIStoryToyPickup.h"
#include "YIXI_Interaction/DialogueToy/YIXIToyCarryComponent.h"
#include "YIXI_Interaction/ScriptedProjectile/YIXIScriptedRock.h"
#include "YIXI_Interaction/YIXIInteractorComponent.h"
#include "YIXIT00TransitionController.h"
#include "CineCameraActor.h"
#include "CineCameraComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DefaultMovementSet/InstantMovementEffects/BasicInstantMovementEffects.h"
#include "Engine/BlockingVolume.h"
#include "Engine/LevelStreaming.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/GameplayCameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "MovieScene.h"
#include "MovieSceneMarkedFrame.h"
#include "MoverComponent.h"
#include "MoverDataModelTypes.h"
#include "YIXI_Interaction/Story/YIXIV3NeutralInput.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogYIXIV3, Log, All);

void UYIXIV3NeutralInput::ProduceInput_Implementation(int32 SimTimeMs, FMoverInputCmdContext& Command)
{
    auto& Inputs=Command.InputCollection.FindOrAddMutableDataByType<FCharacterDefaultInputs>();
    Inputs.SetMoveInput(EMoveInputType::Velocity,MoveVelocity);
    Inputs.OrientationIntent=Facing;
}

namespace
{
FMinimalViewInfo LookAt(FVector Eye, FVector Target, float Fov)
{
    FMinimalViewInfo View;
    View.Location=Eye;
    View.Rotation=(Target-Eye).Rotation();
    View.FOV=Fov;
    return View;
}

FMinimalViewInfo Between(const FMinimalViewInfo& A, const FMinimalViewInfo& B, float Alpha)
{
    FMinimalViewInfo Result=A;
    Result.Location=FMath::Lerp(A.Location,B.Location,Alpha);
    Result.Rotation=FQuat::Slerp(A.Rotation.Quaternion(),B.Rotation.Quaternion(),Alpha).Rotator();
    Result.FOV=FMath::Lerp(A.FOV,B.FOV,Alpha);
    return Result;
}

void SetMoverVelocity(UMoverComponent& Mover, FVector Velocity)
{
    auto Effect=MakeShared<FApplyVelocityEffect>();
    Effect->VelocityToApply=Velocity;
    Effect->bAdditiveVelocity=false;
    Effect->ForceMovementMode=Mover.GetMovementModeName();
    Mover.QueueInstantMovementEffect(Effect);
}

// Focus on the visible face rather than the object's pivot deep inside its mesh.
float SurfaceFocus(const UStaticMeshComponent& Mesh, const FMinimalViewInfo& View, double FaceFraction)
{
    const FTransform& Frame=Mesh.GetComponentTransform();
    const FBox Box=Mesh.GetStaticMesh()->GetBoundingBox();
    const FVector LocalEye=Frame.InverseTransformPosition(View.Location);
    const FVector Ray=LocalEye-Box.GetCenter(), Extent=Box.GetExtent();
    double Fraction=1.;
    for (int32 Axis=0; Axis<3; ++Axis)
        if (FMath::Abs(Ray[Axis])>UE_SMALL_NUMBER)
            Fraction=FMath::Min(Fraction,Extent[Axis]/FMath::Abs(Ray[Axis]));
    const FVector Surface=Frame.TransformPosition(Box.GetCenter()+Ray*(Fraction*FaceFraction));
    return FMath::Max(5.f,float(FVector::DotProduct(Surface-View.Location,View.Rotation.Vector())));
}
}

AYIXIV3Cinematic::AYIXIV3Cinematic()
{
    PrimaryActorTick.bCanEverTick=true;
    PrimaryActorTick.bStartWithTickEnabled=false;
    PrimaryActorTick.TickGroup=TG_PostPhysics;
    SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("PresentationRoot")));
    StageRoot=CreateDefaultSubobject<USceneComponent>(TEXT("StageRoot"));
    StageRoot->SetupAttachment(GetRootComponent());
    PlayerStandMarker=CreateDefaultSubobject<UArrowComponent>(TEXT("PlayerStandMarker"));
    PlayerStandMarker->SetupAttachment(StageRoot);
    ShoulderCamera=CreateDefaultSubobject<UCineCameraComponent>(TEXT("ShoulderCamera"));
    ShoulderCamera->SetupAttachment(StageRoot);
    ShoulderCamera->bConstrainAspectRatio=false;
    ShoulderCamera->SetFieldOfView(64.f);
    ShoulderCamera->SetCurrentAperture(3.2f);
    RockFocusMarker=CreateDefaultSubobject<USceneComponent>(TEXT("RockFocusMarker"));
    RockFocusMarker->SetupAttachment(StageRoot);
    HandCameraMarker=CreateDefaultSubobject<USceneComponent>(TEXT("HandCameraMarker"));
    HandCameraMarker->SetupAttachment(StageRoot);
    ToyLandingMarker=CreateDefaultSubobject<UArrowComponent>(TEXT("ToyLandingMarker"));
    ToyLandingMarker->SetupAttachment(StageRoot);
    StageTrigger=CreateDefaultSubobject<UBoxComponent>(TEXT("StageTrigger"));
    StageTrigger->SetupAttachment(StageRoot);
    StageTrigger->InitBoxExtent(FVector(30,30,110));
    StageTrigger->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    StageTrigger->SetCollisionObjectType(ECC_WorldDynamic);
    StageTrigger->SetCollisionResponseToAllChannels(ECR_Ignore);
    StageTrigger->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
    StageTrigger->SetGenerateOverlapEvents(true);
    StageTrigger->SetCanEverAffectNavigation(false);
    StageTrigger->SetHiddenInGame(true);
    auto Anchor=[this](FName Name,FVector Location)
    {
        auto* Node=CreateDefaultSubobject<USceneComponent>(Name);
        Node->SetupAttachment(GetRootComponent());
        Node->SetRelativeLocation(Location);
        return Node;
    };
    Shoulder=Anchor(TEXT("Shoulder"),FVector(50,-100,160));
    AlternateShoulder=Anchor(TEXT("AlternateShoulder"),FVector(-60,-115,155));
    NightLanding=Anchor(TEXT("NightLanding"),FVector(2360,80,0));
    DropLanding=Anchor(TEXT("DropLanding"),FVector(0,55,10));
    AlternateDropLanding=Anchor(TEXT("AlternateDropLanding"),FVector(35,40,10));
    Audio=CreateDefaultSubobject<UYIXIV3AudioComponent>(TEXT("PresentationAudio"));
}

void AYIXIV3Cinematic::BeginPlay()
{
    Super::BeginPlay();
    if (bUseFixedStage) StageTrigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    if (!UsesDayBindings())
    {
        ShowNight(false);
        return;
    }
    if (!bUseFixedStage || !IsValid(DayPreviewPickup) || !IsValid(DayPreviewRock) || !IsValid(DayPreviewGirl) ||
        DayPreviewPickup->GetWorld()!=GetWorld() || DayPreviewRock->GetWorld()!=GetWorld() ||
        DayPreviewGirl->GetWorld()!=GetWorld())
    {
        UE_LOG(LogYIXIV3,Warning,TEXT("DAY_PREVIEW needs a fixed stage and the formal pickup, rock and girl in the same world."));
        return;
    }
    DayPreviewPickup->OnToyPickedUp.AddUniqueDynamic(this,&AYIXIV3Cinematic::HandleDayPreviewPickup);
}

AYIXIT00TransitionController* AYIXIV3Cinematic::FindFormalTransition() const
{
    AYIXIT00TransitionController* Found=nullptr;
    for (TActorIterator<AYIXIT00TransitionController> It(GetWorld()); It; ++It)
    {
        if (!It->bUseFormalStoryTransition || It->GetLevel()!=GetWorld()->PersistentLevel) continue;
        if (Found) return nullptr;
        Found=*It;
    }
    return Found;
}

UYIXIV3AudioComponent* AYIXIV3Cinematic::PresentationAudio() const
{
    const auto* Transition=FormalTransition.Get();
    return FormalStory ? (Transition ? Transition->FormalAudio.Get() : nullptr) : Audio.Get();
}

void AYIXIV3Cinematic::HandleDayPreviewPickup(APawn* PickingPawn)
{
    if (bDayPreviewConsumed || DayPreviewPawn.IsValid() || !IsValid(PickingPawn) ||
        PickingPawn->GetWorld()!=GetWorld()) return;
    const auto* Controller=Cast<APlayerController>(PickingPawn->GetController());
    const auto* PickupCarry=UYIXIToyCarryComponent::FindForPawn(PickingPawn);
    if (!IsValid(Controller) || !Controller->IsLocalController() || Controller->GetPawn()!=PickingPawn ||
        !IsValid(PickupCarry) || PickupCarry->GetCarryState()!=EYIXIToyCarryState::HeldHand) return;
    AActor* PickedToy=PickupCarry->GetToyActor();
    if (!IsValid(PickedToy) || PickedToy->GetAttachParentActor()!=PickingPawn) return;

    DayPreviewPawn=PickingPawn;
    DayPreviewToy=PickedToy;
    GetWorldTimerManager().SetTimer(DayPreviewRetryTimer,this,&AYIXIV3Cinematic::TryPendingDayPreview,.15f,true);
}

void AYIXIV3Cinematic::TryPendingDayPreview()
{
    APawn* Participant=DayPreviewPawn.Get();
    AActor* PickedToy=DayPreviewToy.Get();
    if (bDayPreviewConsumed || !IsValid(Participant) || !IsValid(PickedToy) ||
        !IsValid(DayPreviewRock) || !IsValid(DayPreviewGirl))
    {
        GetWorldTimerManager().ClearTimer(DayPreviewRetryTimer);
        return;
    }
    if (Shot!=EYIXIV3Shot::Idle || bClosing) return;

    const bool bOverlapping=StageTrigger->IsOverlappingActor(Participant);
    if (bDayPreviewRequiresExit)
    {
        // Mover can transiently drop overlap pairs while restoring the same position.
        const FVector Local=StageTrigger->GetComponentTransform().InverseTransformPosition(Participant->GetActorLocation());
        if (!bOverlapping && !FBox::BuildAABB(FVector::ZeroVector,StageTrigger->GetUnscaledBoxExtent()).IsInsideOrOn(Local))
            bDayPreviewRequiresExit=false;
        return;
    }
    if (!DayPreviewRock->HasImpacted() || DayPreviewRock->GetActiveRequestId()!=2 ||
        DayPreviewGirl->GetRequestState()!=EYIXIStoryGirlState::Unavailable) return;

    const auto* Controller=Cast<APlayerController>(Participant->GetController());
    const auto* PickupCarry=UYIXIToyCarryComponent::FindForPawn(Participant);
    if (!IsValid(Controller) || !Controller->IsLocalController() || Controller->GetPawn()!=Participant ||
        !IsValid(PickupCarry) || PickupCarry->GetToyActor()!=PickedToy ||
        PickupCarry->GetCarryState()!=EYIXIToyCarryState::HeldHand || PickedToy->GetAttachParentActor()!=Participant) return;

    if (FormalStory)
    {
        if (!FormalTransition.IsValid()) FormalTransition=FindFormalTransition();
        auto* Transition=FormalTransition.Get();
        if (!Transition || !Transition->RequestFormalNight(Participant))
        {
            if (bOverlapping && Transition && Transition->HasFormalNightFailed())
            {
                Transition->CancelFormalNight(Participant,true);
                bDayPreviewRequiresExit=true;
            }
            return;
        }
    }
    if (!bOverlapping || !CanEnterFixedStage(Participant)) return;
    if (FormalStory && !FormalStory->BeginExternalV3Presentation(this,Participant,PickedToy)) return;
    if (!BeginPresentation(FormalStory.Get(),Participant))
    {
        if (FormalStory)
        {
            FormalStory->AbortV3Presentation(Participant);
            if (auto* Transition=FormalTransition.Get()) Transition->CancelFormalNight(Participant,true);
        }
        bDayPreviewRequiresExit=true;
    }
}

void AYIXIV3Cinematic::ShowNight(bool bVisible)
{
    for (AActor* Piece : NightSet)
    {
        if (IsValid(Piece) && Piece->GetWorld()==GetWorld())
        {
            Piece->SetActorHiddenInGame(!bVisible);
        }
    }
}

void AYIXIV3Cinematic::PrepareNight(AYIXIInteractionStoryCoordinator* Sender, APawn* Participant)
{
    if (UsesDayBindings() || !IsValid(Sender) || !IsValid(Participant) ||
        Sender->GetWorld()!=GetWorld() || Participant->GetWorld()!=GetWorld()) return;
    Audio->BeginDayMix();
    // The preview set lives in the persistent sandbox. T01 owns streaming in a formal map.
    PrepareSequence();
}

void AYIXIV3Cinematic::PrepareSequence()
{
    if (Sequence && !Player)
    {
        FMovieSceneSequencePlaybackSettings Settings;
        Settings.bDisableCameraCuts=true;
        ALevelSequenceActor* Created=nullptr;
        Player=ULevelSequencePlayer::CreateLevelSequencePlayer(this,Sequence,Settings,Created);
        PlayerActor=Created;
        if (PlayerActor) PlayerActor->SetBindingByTag(TEXT("V3Host"),{this});
        if (Player) Player->OnStop.AddUniqueDynamic(this,&AYIXIV3Cinematic::InterruptPresentation);
    }
}

bool AYIXIV3Cinematic::ReadTimeline()
{
    const UMovieScene* Scene=Sequence ? Sequence->GetMovieScene() : nullptr;
    if (!Scene || !Player || !Sequence->FindBindingByTag(TEXT("V3Host")).IsValid()) return false;
    auto Read=[Scene](const TCHAR* Label)
    {
        for (const auto& Marker : Scene->GetMarkedFrames())
            if (Marker.Label==Label) return float(Scene->GetTickResolution().AsSeconds(Marker.FrameNumber));
        return -1.f;
    };
    ShoulderSetAt=Read(TEXT("ShoulderSet")); HandBlendAt=Read(TEXT("HandBlend"));
    HandAt=Read(TEXT("Hand")); ReleaseAt=Read(TEXT("Release")); StableAt=Read(TEXT("Stable"));
    LandedAt=Read(TEXT("Landed"));
    if (LandedAt<0.f) LandedAt=StableAt; // Existing sequences use one marker for landing and the start of the hold.
    CutAt=Read(TEXT("Cut")); PullAt=Read(TEXT("Pullback")); ReturnAt=Read(TEXT("Return")); EndAt=Read(TEXT("End"));
    return ShoulderSetAt>0 && HandBlendAt>ShoulderSetAt && HandAt>HandBlendAt && ReleaseAt>HandAt &&
        LandedAt>ReleaseAt+.05f && StableAt>=LandedAt &&
        CutAt>StableAt && PullAt>CutAt &&
        ReturnAt>PullAt && EndAt>ReturnAt;
}

void AYIXIV3Cinematic::HandleAttackImpact(AYIXIScriptedRock* Rock)
{
    if (IsValid(Rock) && Rock->GetWorld()==GetWorld() && Rock->HasImpacted() && DustEffect)
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(this,DustEffect,Rock->RockMesh->GetComponentLocation());
}

bool AYIXIV3Cinematic::ClearCameraPath(FVector Start, FVector End, bool bToyRail) const
{
    FCollisionQueryParams Q(SCENE_QUERY_STAT(YIXIV3Camera),false,this);
    Q.AddIgnoredActor(Pawn); Q.AddIgnoredActor(Toy);
    if (bToyRail)
    {
        for (const ABlockingVolume* Volume : ToyCameraFloorVolumes)
        {
            if (IsValid(Volume) && Volume->GetLevel()==GetLevel()) Q.AddIgnoredActor(Volume);
        }
    }
    return !GetWorld()->SweepTestByChannel(Start,End,FQuat::Identity,ECC_Camera,FCollisionShape::MakeSphere(5.f),Q);
}

bool AYIXIV3Cinematic::ClearToySight(FVector Subject, FVector Eye) const
{
    // A visible story rock can occlude the image even with camera collision disabled.
    const AYIXIScriptedRock* RockActor=UsesDayBindings() ? DayPreviewRock.Get() : (Story ? Story->AttackCue.Get() : nullptr);
    if (IsValid(RockActor) && !RockActor->IsHidden() && RockActor->RockMesh && RockActor->RockMesh->IsVisible())
    {
        const FBox Rock=RockActor->RockMesh->Bounds.GetBox().ExpandBy(3.);
        if (Rock.IsInsideOrOn(Eye) || FMath::LineBoxIntersection(Rock,Subject,Eye,Eye-Subject)) return false;
    }
    return ClearCameraPath(Subject,Eye,true);
}

bool AYIXIV3Cinematic::ResolveToyLanding(FTransform& Landing)
{
    auto Reject = [this](const TCHAR* Reason)
    {
        if (!bReportedToyLandingIssue)
        {
            UE_LOG(LogYIXIV3, Warning, TEXT("TOY_LANDING_REJECTED %s: %s"), *GetName(), Reason);
            bReportedToyLandingIssue=true;
        }
        return false;
    };
    if ((UsesDayBindings() || bUseToyLandingMarker) && !IsValid(ToyLandingSurface))
        return Reject(TEXT("assign the courtyard floor to Toy Landing Surface"));

    double SupportZ=0.0;
    if (!Carry->FindVerticalCinematicLanding(Landing,ToyLandingSurface.Get(),&SupportZ))
        return Reject(TEXT("the vertical drop has no clear path to the assigned floor"));

    if (bUseToyLandingMarker)
    {
        const FVector Marker=ToyLandingMarker->GetComponentLocation();
        if (FVector::Dist2D(Marker,Landing.GetLocation())>30.0 || FMath::Abs(Marker.Z-SupportZ)>3.0)
            return Reject(TEXT("Toy Landing Marker conflicts with the toy's vertical projection or the floor height"));
    }
    return true;
}

bool AYIXIV3Cinematic::PrepareHandRail()
{
    FVector Center, Extent;
    Toy->GetActorBounds(false,Center,Extent);
    FTransform Landing;
    if (!ResolveToyLanding(Landing)) return false;
    // Keep the camera on the same vertical rail from the shoulder to the floor insert.
    const double Lateral=FVector::Dist2D(ShoulderView.Location,Center);
    const double Slope=DayToyCameraOffset.Z/FMath::Max(1.,DayToyCameraOffset.Size2D());
    const double AvailableHeight=ShoulderView.Location.Z-Center.Z-1.;
    if (Lateral<15. || AvailableHeight<5.) return false;
    const double HandHeight=FMath::Min(Lateral*Slope,DayToyCameraOffset.Z);
    HandRailHeight=FMath::Clamp(HandHeight,5.,AvailableHeight);
    HandToyCenter=Center;
    HandEye=bUseFixedStage ? HandCameraMarker->GetComponentLocation() :
        FVector(ShoulderView.Location.X,ShoulderView.Location.Y,Center.Z+HandRailHeight);
    if (!ClearCameraPath(ShoulderView.Location,HandEye,true)) return false;
    const FVector FloorDelta=Landing.GetLocation()-Toy->GetActorLocation();
    if (!ClearCameraPath(HandEye,HandEye+FloorDelta,true)) return false;
    for (int32 Step=0; Step<=4; ++Step)
    {
        const FVector Delta=FloorDelta*(Step*.25);
        if (!ClearToySight(Center+Delta,HandEye+Delta)) return false;
    }
    return true;
}

bool AYIXIV3Cinematic::PrepareDropCamera()
{
    FVector Center,Extent;
    Toy->GetActorBounds(false,Center,Extent);
    DropStartView=ToyView(false);
    const FVector StartOffset=DropStartView.Location-Center;
    DropStartDistance=StartOffset.Size();
    FloorToyCenter=Center+(FloorPose.GetLocation()-Toy->GetActorLocation());
    const FRotator PawnYaw(0,Pawn->GetActorRotation().Yaw,0);
    const FVector FloorOffset=StableAt>LandedAt ? PawnYaw.RotateVector(FloorCameraOffset) : StartOffset;
    FloorViewDistance=FloorOffset.Size();
    FloorView=DayToyView(FloorToyCenter+FloorOffset,FloorToyCenter);
    return bSkip || ClearToySight(FloorToyCenter,FloorView.Location);
}

bool AYIXIV3Cinematic::UpdateDropCamera()
{
    FVector Center,Extent;
    Toy->GetActorBounds(false,Center,Extent);
    // Use one clock for both phases, so neither the aim nor the lateral motion stops at Landed.
    const double Blend=StableAt>LandedAt ? FMath::SmoothStep(ReleaseAt,StableAt,SequenceSeconds) : 0.;
    const FRotator Aim(FMath::Lerp(DropStartView.Rotation.Pitch,FloorView.Rotation.Pitch,Blend),
        DropStartView.Rotation.Yaw+Blend*FMath::FindDeltaAngleDegrees(DropStartView.Rotation.Yaw,FloorView.Rotation.Yaw),0.);
    const double Distance=FMath::Lerp(DropStartDistance,FloorViewDistance,Blend);
    FMinimalViewInfo View=SequenceSeconds>=StableAt ? FloorView : DropStartView;
    if (SequenceSeconds<StableAt)
    {
        View.Location=Center-Aim.Vector()*Distance;
        View.Rotation=Aim;
        View.FOV=DayToyFOV(Distance);
    }
    if (!bSkip)
    {
        const FVector PreviousEye=CameraActor->GetActorLocation();
        if (!ClearCameraPath(PreviousEye,View.Location,true) || !ClearToySight(Center,View.Location)) return false;
        // The scene sweep ignores the pawn, so check its capsule separately.
        if (const UCapsuleComponent* Capsule=Pawn->FindComponentByClass<UCapsuleComponent>())
        {
            const FVector Root=Capsule->GetComponentLocation();
            const FVector Axis=Capsule->GetUpVector()*(Capsule->GetScaledCapsuleHalfHeight()-Capsule->GetScaledCapsuleRadius());
            FVector PathPoint,CapsulePoint;
            FMath::SegmentDistToSegmentSafe(PreviousEye,View.Location,Root-Axis,Root+Axis,PathPoint,CapsulePoint);
            if (FVector::DistSquared(PathPoint,CapsulePoint)<FMath::Square(Capsule->GetScaledCapsuleRadius()+5.)) return false;
        }
    }
    Camera(View);
    return true;
}

bool AYIXIV3Cinematic::NightDestination(FVector& Location) const
{
    const UCapsuleComponent* Capsule=Pawn ? Pawn->FindComponentByClass<UCapsuleComponent>() : nullptr;
    if (!bNightPreviewReady || !Capsule) return false;
    const FVector Ground=NightLanding->GetComponentLocation();
    FCollisionQueryParams Q(SCENE_QUERY_STAT(YIXIV3NightFloor),false,this);
    Q.AddIgnoredActor(Pawn);
    FHitResult Floor;
    if (!GetWorld()->LineTraceSingleByChannel(Floor,Ground+FVector(0,0,120),Ground-FVector(0,0,160),ECC_Visibility,Q)
        || Floor.ImpactNormal.Z<.65f) return false;
    Location=Floor.ImpactPoint+FVector(0,0,Capsule->GetScaledCapsuleHalfHeight()+3);
    return !GetWorld()->OverlapBlockingTestByChannel(Location,FQuat::Identity,ECC_Pawn,Capsule->GetCollisionShape(),Q);
}

bool AYIXIV3Cinematic::ChooseShoulderView()
{
    const UStaticMeshComponent* Rock=Story->AttackCue->RockMesh;
    if (!Rock || !Rock->GetStaticMesh()) return false;
    // Prefer the visible character body. The Mover rig also has a hidden simulation skeleton.
    const USkeletalMeshComponent* Body=nullptr;
    TInlineComponentArray<USkeletalMeshComponent*> Meshes(Pawn.Get());
    for (const USkeletalMeshComponent* Mesh : Meshes)
    {
        if (!Mesh->IsVisible() || Mesh->bHiddenInGame || !Mesh->DoesSocketExist(TEXT("upperarm_r")) ||
            !Mesh->DoesSocketExist(TEXT("upperarm_l")) || !Mesh->DoesSocketExist(TEXT("head"))) continue;
        Body=Mesh;
        break;
    }
    if (!Body) return false;
    const FVector Arm=Body->GetSocketLocation(TEXT("upperarm_r"));
    const FRotationMatrix PawnAxes(FRotator(0,Pawn->GetActorRotation().Yaw,0));
    const FVector PawnForward=PawnAxes.GetUnitAxis(EAxis::X);
    const FVector PawnRight=PawnAxes.GetUnitAxis(EAxis::Y);
    const double HalfShoulders=FVector::Dist2D(Arm,Body->GetSocketLocation(TEXT("upperarm_l")))*.5;
    const FVector Root=Pawn->GetActorLocation();
    // Use the arm's height but keep chest animation from rotating the camera offset.
    const FVector Reference=FVector(Root.X,Root.Y,Arm.Z)+PawnRight*HalfShoulders;
    FVector Eye=Reference-PawnForward*ShoulderBackDistance+PawnRight*ShoulderRightDistance+FVector::UpVector*ShoulderHeight;

    const FRotationMatrix EntryAxes(EntryView.Rotation);
    const FVector ViewForward=EntryAxes.GetUnitAxis(EAxis::X);
    const FVector ViewRight=EntryAxes.GetUnitAxis(EAxis::Y);
    const FVector Head=Body->GetSocketLocation(TEXT("head"));
    // Keep the head at the left edge with a small dolly correction. The view rotation stays locked.
    const double Backoff=FMath::Clamp(108.-FVector::DotProduct(Head-Eye,ViewForward),0.,35.);
    Eye-=ViewForward.GetSafeNormal2D()*Backoff;
    const double HeadDepth=FVector::DotProduct(Head-Eye,ViewForward);
    if (HeadDepth>0.)
    {
        const double LeftEdge=-.96*HeadDepth*FMath::Tan(FMath::DegreesToRadians(ShoulderFOV*.5));
        const double Offset=FVector::DotProduct(Head-Eye,ViewRight)-LeftEdge;
        Eye+=ViewRight*FMath::Clamp(Offset,-18.,18.);
    }

    const FVector Travel=Eye-EntryView.Location;
    const double ForwardTravel=FVector::DotProduct(Travel,ViewForward);
    const double RightTravel=FVector::DotProduct(Travel,ViewRight);
    const double UpTravel=FVector::DotProduct(Travel,EntryAxes.GetUnitAxis(EAxis::Z));
    if (ForwardTravel<=FMath::Abs(RightTravel) || ForwardTravel<=FMath::Abs(UpTravel) ||
        !ClearCameraPath(EntryView.Location,Eye) || Rock->Bounds.GetBox().IsInsideOrOn(Eye)) return false;

    ShoulderView=EntryView;
    ShoulderView.Location=Eye;
    ShoulderView.FOV=ShoulderFOV;
    UE_LOG(LogYIXIV3,Display,TEXT("Right shoulder %s: joint=%s eye=%s entry=%s rotation=%s forward=%.2f right=%.2f up=%.2f"),
        *Body->GetName(),*Arm.ToCompactString(),*Eye.ToCompactString(),*EntryView.Location.ToCompactString(),
        *EntryView.Rotation.ToCompactString(),ForwardTravel,RightTravel,UpTravel);
    return true;
}

bool AYIXIV3Cinematic::CanEnterFixedStage(APawn* Participant) const
{
    if (!IsValid(Participant) || !StageTrigger->IsOverlappingActor(Participant)) return false;
    const auto* Controller=Cast<APlayerController>(Participant->GetController());
    const auto* Capsule=Participant->FindComponentByClass<UCapsuleComponent>();
    const auto* Mover=Participant->FindComponentByClass<UMoverComponent>();
    if (!Controller || !Controller->IsLocalController() || !Controller->PlayerCameraManager || !Capsule || !Mover) return false;

    FHitResult Floor;
    return Mover->TryGetFloorCheckHitResult(Floor) && Floor.bBlockingHit && Floor.ImpactNormal.Z>=.65f &&
        ClearStageWalk(*Participant,*Capsule);
}

bool AYIXIV3Cinematic::ClearStageWalk(const APawn& Participant, const UCapsuleComponent& Capsule) const
{
    const FVector Start=Capsule.GetComponentLocation();
    const FVector Stand=PlayerStandMarker->GetComponentLocation();
    const float Radius=Capsule.GetScaledCapsuleRadius();
    const float HalfHeight=Capsule.GetScaledCapsuleHalfHeight();
    if (FVector::Dist2D(Start,Stand)>MaxStageEntryDistance || FMath::Abs(Start.Z-Stand.Z-HalfHeight)>12.) return false;

    FCollisionQueryParams Query(SCENE_QUERY_STAT(YIXIStageEntry),false,this);
    Query.AddIgnoredActor(&Participant);
    const FVector End(Stand.X,Stand.Y,Start.Z);
    const FCollisionShape Shape=FCollisionShape::MakeCapsule(Radius,FMath::Max(Radius,HalfHeight-2.f));
    return !GetWorld()->SweepTestByChannel(Start,End,FQuat::Identity,ECC_Pawn,Shape,Query);
}

bool AYIXIV3Cinematic::PrepareStageCameraRoute(const UCapsuleComponent& Capsule)
{
    StageCameraBend.Reset();
    const FVector Start=EntryView.Location, End=ShoulderView.Location;
    const FVector Center=Capsule.GetComponentLocation();
    const double Radius=Capsule.GetScaledCapsuleRadius();
    const double HalfHeight=Capsule.GetScaledCapsuleHalfHeight();
    const FVector Axis=Capsule.GetUpVector()*(HalfHeight-Radius);
    const auto SegmentClear=[&](FVector A,FVector B)
    {
        FVector Eye,CapsulePoint;
        FMath::SegmentDistToSegmentSafe(A,B,Center-Axis,Center+Axis,Eye,CapsulePoint);
        return FVector::DistSquared(Eye,CapsulePoint)>FMath::Square(Radius+5.) && ClearCameraPath(A,B);
    };
    if (SegmentClear(Start,End)) return true;

    // An opposing gameplay view may need a clearance waypoint. The authored destination is fixed.
    FVector Side=FVector::CrossProduct(FVector::UpVector,(End-Start).GetSafeNormal2D());
    if (Side.IsNearlyZero()) Side=ShoulderView.Rotation.Quaternion().GetRightVector().GetSafeNormal2D();
    const FVector HighCenter(Center.X,Center.Y,FMath::Max3(Start.Z,End.Z,Center.Z+HalfHeight+20.));
    const double Offset=FMath::Max(90.,Radius+45.);
    for (const FVector& Point : {HighCenter,HighCenter+Side*Offset,HighCenter-Side*Offset})
    {
        if (SegmentClear(Start,Point) && SegmentClear(Point,End))
        {
            StageCameraBend=Point;
            return true;
        }
    }
    return false;
}

void AYIXIV3Cinematic::UpdateStageAlignment(float Delta)
{
    StageAlignmentTime+=Delta;
    if (!CinematicInput || StageAlignmentTime>StageMoveTimeout)
    {
        Close(false,TEXT("stage alignment or hand rail did not become ready"));
        return;
    }
    const auto* Mover=Pawn->FindComponentByClass<UMoverComponent>();
    const auto* Capsule=Pawn->FindComponentByClass<UCapsuleComponent>();
    FHitResult Floor;
    if (!Mover || !Capsule || !Mover->TryGetFloorCheckHitResult(Floor) || !Floor.bBlockingHit ||
        Floor.ImpactNormal.Z<.65f || !ClearStageWalk(*Pawn,*Capsule))
    {
        Close(false,TEXT("stage walk lost its clear, grounded route"));
        return;
    }
    FVector ToStand=PlayerStandMarker->GetComponentLocation()-Capsule->GetComponentLocation();
    ToStand.Z=0;
    const double Distance=ToStand.Size();
    const double Facing=PlayerStandMarker->GetComponentRotation().Yaw;
    const double PawnYaw=Pawn->GetActorRotation().Yaw;
    const double TravelWeight=FMath::SmoothStep(12.,60.,Distance);
    const double DesiredYaw=Facing+TravelWeight*FMath::FindDeltaAngleDegrees(Facing,ToStand.Rotation().Yaw);
    // Advance the command independently so Mover's own turn smoothing can catch up.
    const double CommandYaw=CinematicInput->Facing.IsNearlyZero() ? PawnYaw : CinematicInput->Facing.Rotation().Yaw;
    const double Turn=FMath::FixedTurn(CommandYaw,DesiredYaw,150.*FMath::Min(Delta,.1f));
    CinematicInput->Facing=FRotator(0,Turn,0).Vector();
    CinematicInput->MoveVelocity=Distance>StagePositionTolerance*.6
        ? ToStand.GetSafeNormal()*FMath::Min(double(StageMoveSpeed),3.5*Distance) : FVector::ZeroVector;
    if (Distance>StagePositionTolerance || FMath::Abs(FMath::FindDeltaAngleDegrees(PawnYaw,Facing))>StageFacingTolerance ||
        Mover->GetVelocity().Size()>5.)
    {
        StageSettleTime=0.f;
        return;
    }
    CinematicInput->MoveVelocity=FVector::ZeroVector;
    StageSettleTime+=FMath::Min(Delta,.1f);
    if (StageSettleTime<.25f) return;

    EntryView=PC->PlayerCameraManager->GetCameraCacheView();
    ShoulderView=EntryView;
    ShoulderView.Location=ShoulderCamera->GetComponentLocation();
    ShoulderView.Rotation=ShoulderCamera->GetComponentRotation();
    ShoulderView.FOV=ShoulderCamera->GetHorizontalFieldOfView();
    const double HeldToyReach=Capsule->GetScaledCapsuleRadius()+80.;
    // The animated hand can lag behind the capsule while the pawn is settling.
    // Verify the existing hand and drop rail before freezing the pose and taking the camera.
    if (FVector::DistSquared2D(Toy->GetActorLocation(),Capsule->GetComponentLocation())>FMath::Square(HeldToyReach) ||
        !PrepareHandRail()) return;
    if (!PrepareStageCameraRoute(*Capsule))
    {
        Close(false,TEXT("no clear transition to the authored shoulder camera"));
        return;
    }

    // The gameplay view remains live through the short walk; only the camera blends after the pawn stops.
    HoldParticipantPose();
    bShoulderFramed=true;
    ApproachStartTravel=0.f;
    UE_LOG(LogYIXIV3,Display,TEXT("STAGE_READY location=%s yaw=%.3f error=%.3f yawError=%.3f walkSeconds=%.3f eye=%s clearanceBend=%d"),
        *Pawn->GetActorLocation().ToCompactString(),PawnYaw,Distance,
        FMath::Abs(FMath::FindDeltaAngleDegrees(PawnYaw,Facing)),StageAlignmentTime,*ShoulderView.Location.ToCompactString(),
        StageCameraBend.IsSet());
    Camera(EntryView);
    PC->SetViewTarget(CameraActor);
    SetShot(EYIXIV3Shot::Shoulder);
}

bool AYIXIV3Cinematic::BeginDiscovery(AYIXIInteractionStoryCoordinator* Sender, APawn* Participant)
{
    return !UsesDayBindings() && BeginPresentation(Sender,Participant);
}

bool AYIXIV3Cinematic::BeginPresentation(AYIXIInteractionStoryCoordinator* Sender, APawn* Participant)
{
    if (Shot!=EYIXIV3Shot::Idle || bClosing || !IsValid(Participant) || Participant->GetWorld()!=GetWorld() ||
        (!bDayOnlyPreview && (!IsValid(Sender) || Sender->GetWorld()!=GetWorld())) ||
        (bUseFixedStage && !CanEnterFixedStage(Participant))) return false;
    Story=Sender; Pawn=Participant; PC=Cast<APlayerController>(Pawn->GetController());
    Carry=UYIXIToyCarryComponent::FindForPawn(Pawn);
    Toy=Carry ? Carry->GetToyActor() : nullptr;
    if (UsesDayBindings()) PrepareSequence();
    else PrepareNight(Sender,Participant);
    auto* Mix=PresentationAudio();
    if (!PC || !PC->IsLocalController() || !PC->PlayerCameraManager || !IsValid(Toy) || !Mix || !ReadTimeline() ||
        (!bDayOnlyPreview && !Carry->CanAttachToWaist()) ||
        (!UsesDayBindings() && (!IsValid(Story->AttackCue) || !NightDestination(GoalLocation))))
    {
        UE_LOG(LogYIXIV3,Warning,TEXT("Cannot start: check sequence markers/binding, night floor, carry sockets and drop path."));
        return false;
    }
    EntryView=PC->PlayerCameraManager->GetCameraCacheView();
    // Resolve the authored destination once so a stationary shoulder hold cannot drift.
    Player->Play();
    Player->Pause();
    Sample(ShoulderSetAt);
    bShoulderFramed=false;
    FActorSpawnParameters Params;
    Params.Owner=this; Params.ObjectFlags|=RF_Transient;
    CameraActor=GetWorld()->SpawnActor<ACineCameraActor>(ACineCameraActor::StaticClass(),EntryView.Location,EntryView.Rotation,Params);
    if (!CameraActor) { Player->Stop(); return false; }
    CameraActor->LookatTrackingSettings.bEnableLookAtTracking=false;
    auto* Lens=CameraActor->GetCineCameraComponent();
    Lens->bConstrainAspectRatio=false;
    Lens->ExposureMethod=ECameraExposureMethod::DoNotOverride;
    auto Filmback=Lens->Filmback;
    Filmback.SensorWidth=36.f;
    Filmback.SensorHeight=24.f;
    Lens->SetFilmback(Filmback);
    auto Limits=Lens->LensSettings;
    Limits.MinFocalLength=4.f;
    Limits.MaxFocalLength=200.f;
    Limits.MinimumFocusDistance=50.f; // Lens metadata uses mm.
    Limits.MinFStop=1.f;
    Lens->SetLensSettings(Limits);
    Lens->FocusSettings.FocusMethod=ECameraFocusMethod::Manual;
    Lens->FocusSettings.bSmoothFocusChanges=false;
    Lens->PostProcessSettings.bOverride_DepthOfFieldEnabled=true;
    Lens->PostProcessSettings.DepthOfFieldEnabled=true;
    PreviousView=PC->GetViewTarget(); DayControlRotation=PC->GetControlRotation(); DayPawnPose=Pawn->GetActorTransform();
    Interactor=PC->FindComponentByClass<UYIXIInteractorComponent>();
    if (!Interactor) Interactor=Pawn->FindComponentByClass<UYIXIInteractorComponent>();
    if (Interactor) { bWasSuppressed=Interactor->IsCinematicSuppressed(); Interactor->SetCinematicSuppressed(true); }
    PC->SetIgnoreMoveInput(true); PC->SetIgnoreLookInput(true); bInputHeld=true;
    bPawnInputWasEnabled=Pawn->InputEnabled();
    Pawn->DisableInput(PC);
    Pawn->ConsumeMovementInputVector();
    if (auto* Mover=Pawn->FindComponentByClass<UMoverComponent>())
    {
        SavedMoverInputs=Mover->InputProducers;
        Mover->InputProducers.Reset();
        CinematicInput=NewObject<UYIXIV3NeutralInput>(this);
        Mover->InputProducers.Add(CinematicInput);
        UE_LOG(LogYIXIV3,Display,TEXT("Takeover: speed %.1f cm/s; %d producers replaced by stationary input."),Mover->GetVelocity().Size2D(),SavedMoverInputs.Num());
        SetMoverVelocity(*Mover,FVector::ZeroVector);
    }
    bMoved=false; bCut=false; bSkip=false; SkipHeld=0; Waiting=0;
    FormalPoseDeadline=0;
    StableWaistPose.Reset();
    bLoggedDayRemaining=false;
    bLoggedFormalFirstFrame=false;
    bLoggedFormalMidpoint=false;
    bReportedToyLandingIssue=false;
    Sample(0);
    Camera(EntryView);
    Mix->BeginDayMix();
    SetActorTickEnabled(true);
    if (bUseFixedStage)
    {
        StageCameraBend.Reset();
        StageAlignmentTime=0.f;
        StageSettleTime=0.f;
        SetShot(EYIXIV3Shot::StageAlign);
    }
    else
    {
        PC->SetViewTarget(CameraActor);
        SetShot(EYIXIV3Shot::Shoulder);
    }
    return true;
}

void AYIXIV3Cinematic::SetShot(EYIXIV3Shot Next)
{
    Shot=Next;
    UE_LOG(LogYIXIV3,Display,TEXT("shot=%s seq=%.4f game=%.5f frame=%llu pawn=%s toy=%s"),
        *UEnum::GetValueAsString(Shot),SequenceSeconds,GetWorld()->GetTimeSeconds(),GFrameCounter,*GetNameSafe(Pawn),*GetNameSafe(Toy));
}

void AYIXIV3Cinematic::Sample(float Time)
{
    SequenceSeconds=Time;
    Player->SetPlaybackPosition(FMovieSceneSequencePlaybackParams(Time,EUpdatePositionMethod::Jump));
}

void AYIXIV3Cinematic::Camera(const FMinimalViewInfo& V)
{
    CameraActor->SetActorLocationAndRotation(V.Location,V.Rotation);
    UCineCameraComponent* Lens=CameraActor->GetCineCameraComponent();
    Lens->SetFieldOfView(V.FOV);
    Lens->SetCurrentAperture(LensAperture);
    const UStaticMeshComponent* Mesh=Toy->FindComponentByClass<UStaticMeshComponent>();
    if (!Mesh || !Mesh->GetStaticMesh()) return;
    const float Near=SurfaceFocus(*Mesh,V,1.);
    float Distance=Near;
    if (!bCut)
    {
        const float Far=bUseFixedStage
            ? FMath::Max(5.f,float(FVector::DotProduct(RockFocusMarker->GetComponentLocation()-V.Location,V.Rotation.Vector())))
            : SurfaceFocus(*Story->AttackCue->RockMesh,V,.75);
        Distance=1.f/FMath::Lerp(1.f/Far,1.f/Near,FMath::Clamp(FocusTravel,0.f,1.f));
        if (bUseFixedStage)
        {
            Lens->SetCurrentAperture(FMath::Lerp(ShoulderCamera->CurrentAperture,LensAperture,FMath::Clamp(FocusTravel,0.f,1.f)));
        }
    }
    Lens->FocusSettings.ManualFocusDistance=Distance;
    Lens->PostProcessBlendWeight=SequenceSeconds<ShoulderSetAt
        ? FMath::SmoothStep(0.f,ShoulderSetAt,SequenceSeconds) : 1.f;
}

void AYIXIV3Cinematic::HoldParticipantPose()
{
    // Socket animation continues while movement input is locked. Hold the pose for the two inserts.
    TInlineComponentArray<USkeletalMeshComponent*> Meshes(Pawn.Get());
    for (USkeletalMeshComponent* Mesh : Meshes)
        if (!Mesh->bPauseAnims)
        {
            Mesh->bPauseAnims=true;
            FrozenMeshes.Add(Mesh);
        }
}

void AYIXIV3Cinematic::ReleaseParticipantPose()
{
    for (const auto& Weak : FrozenMeshes)
        if (auto* Mesh=Weak.Get()) Mesh->bPauseAnims=false;
    FrozenMeshes.Reset();
}

void AYIXIV3Cinematic::CaptureWaistInsert()
{
    USceneComponent* Root=Toy->GetRootComponent();
    USceneComponent* Parent=Root ? Root->GetAttachParent() : nullptr;
    if (!IsValid(Parent) || Parent->GetOwner()!=Pawn) return;
    WaistParent=Parent;
    WaistSocket=Root->GetAttachSocketName();
    AuthoredWaistRelative=Root->GetRelativeTransform();
    InsertInPawn=Root->GetComponentTransform().GetRelativeTransform(Pawn->GetActorTransform());
    AddTickPrerequisiteComponent(Parent);
}

void AYIXIV3Cinematic::UpdateWaistInsert(float FollowSocket)
{
    USceneComponent* Parent=WaistParent.Get();
    USceneComponent* Root=IsValid(Toy) ? Toy->GetRootComponent() : nullptr;
    if (!IsValid(Parent) || !IsValid(Root) || !IsValid(Pawn) ||
        Parent->GetOwner()!=Pawn || Root->GetAttachParent()!=Parent || Root->GetAttachSocketName()!=WaistSocket) return;
    // Physics-driven pelvis motion can continue after animation has paused. Compensate
    // in socket space relative to this moving Pawn, then yield back to the original mount.
    const FTransform Insert=InsertInPawn*Pawn->GetActorTransform();
    const FTransform InSocket=Insert.GetRelativeTransform(Parent->GetSocketTransform(WaistSocket));
    Root->SetRelativeLocationAndRotation(
        FMath::Lerp(InSocket.GetLocation(),AuthoredWaistRelative.GetLocation(),FollowSocket),
        FQuat::Slerp(InSocket.GetRotation(),AuthoredWaistRelative.GetRotation(),FollowSocket));
}

void AYIXIV3Cinematic::RestoreWaistAttachment()
{
    if (USceneComponent* Parent=WaistParent.Get())
    {
        USceneComponent* Root=IsValid(Toy) ? Toy->GetRootComponent() : nullptr;
        if (IsValid(Root) && Root->GetAttachParent()==Parent && Root->GetAttachSocketName()==WaistSocket)
            Root->SetRelativeLocationAndRotation(AuthoredWaistRelative.GetLocation(),AuthoredWaistRelative.GetRotation());
        RemoveTickPrerequisiteComponent(Parent);
    }
    WaistParent.Reset();
    WaistSocket=NAME_None;
}

FMinimalViewInfo AYIXIV3Cinematic::ToyView(bool bNight) const
{
    FVector Center,Extents;
    Toy->GetActorBounds(false,Center,Extents);
    if (bNight)
    {
        FVector Rear=NightCloseupDirection;
        Rear.X=FMath::Min(-0.25,Rear.X);
        const FVector Offset=FRotator(0,Pawn->GetActorRotation().Yaw,0).RotateVector(Rear.GetSafeNormal())*CloseupDistance;
        return LookAt(Center+Offset,Center,LockedToyFOV);
    }
    const FVector Eye=bUseFixedStage ? HandEye+(Center-HandToyCenter) :
        FVector(ShoulderView.Location.X,ShoulderView.Location.Y,Center.Z+HandRailHeight);
    return DayToyView(Eye,Center);
}

FMinimalViewInfo AYIXIV3Cinematic::DayToyView(FVector Eye, FVector Center) const
{
    return LookAt(Eye,Center,DayToyFOV(FVector::Distance(Eye,Center)));
}

float AYIXIV3Cinematic::DayToyFOV(double Distance) const
{
    // Preserve the close-up scale as the rail and the floor slide change camera distance.
    const double HalfWidth=CloseupDistance*FMath::Tan(FMath::DegreesToRadians(LockedToyFOV*.5));
    const double RailFOV=FMath::RadiansToDegrees(2.*FMath::Atan(HalfWidth/FMath::Max(1.,Distance)));
    return FMath::Clamp(RailFOV,5.,120.);
}

bool AYIXIV3Cinematic::MoveParticipant(const FTransform& Pose)
{
    if (!IsValid(Pawn) || !PC || PC->GetPawn()!=Pawn) return false;
    if (UMoverComponent* Mover=Pawn->FindComponentByClass<UMoverComponent>())
    {
        auto Move=MakeShared<FTeleportEffect>();
        Move->TargetLocation=Pose.GetLocation(); Move->TargetRotation=Pose.Rotator(); Move->bUseActorRotation=false;
        Mover->QueueInstantMovementEffect(Move);
    }
    else if (!Pawn->TeleportTo(Pose.GetLocation(),Pose.Rotator())) return false;
    PC->SetControlRotation(Pose.Rotator());
    return true;
}

void AYIXIV3Cinematic::RequestSkip()
{
    if (Shot!=EYIXIV3Shot::Idle) bSkip=true;
}

void AYIXIV3Cinematic::InterruptPresentation()
{
    if (Shot!=EYIXIV3Shot::Idle) Close(bCut,TEXT("interrupted"));
}

USkeletalMeshComponent* AYIXIV3Cinematic::FindVisibleBody() const
{
    if (!IsValid(Pawn) || Pawn->IsHidden()) return nullptr;
    const AActor* ViewActor=IsValid(PC) ? PC->GetViewTarget() : nullptr;
    USkeletalMeshComponent* Body=nullptr;
    for (auto* Part : TInlineComponentArray<USkeletalMeshComponent*>(Pawn.Get()))
    {
        const bool bOwnerView=ViewActor && ViewActor->IsOwnedBy(Part->GetOwner());
        if (Part->IsRegistered() && Part->ShouldRender() && Part->GetSkeletalMeshAsset() &&
            !(bOwnerView && Part->bOwnerNoSee) && !(!bOwnerView && Part->bOnlyOwnerSee) &&
            Part->DoesSocketExist(TEXT("pelvis")) && (!Body || Part->Bounds.SphereRadius>Body->Bounds.SphereRadius))
            Body=Part;
    }
    return Body;
}

bool AYIXIV3Cinematic::UpdateFormalNightPose(FString& Reason)
{
    USceneComponent* Mount=nullptr;
    FName Socket;
    if (!Carry->GetWaistMount(Mount,Socket))
    { Reason=TEXT("waist attachment is unavailable"); return false; }
    auto* Mesh=Cast<USkeletalMeshComponent>(Mount);
    if (!Mesh)
        if (const auto* Mover=Pawn->FindComponentByClass<UMoverComponent>())
            Mesh=Mover->GetPrimaryVisualComponent<USkeletalMeshComponent>();
    if (!IsValid(Mesh) || Mesh->GetOwner()!=Pawn || !Mesh->IsRegistered() || !Mesh->DoesSocketExist(TEXT("pelvis")))
    { Reason=TEXT("the actual Pawn has no registered pelvis mesh"); return false; }

    if (!PriorFormalMeshTick.IsSet())
    {
        // The Day insert paused pose evaluation. The root can arrive before Mover's visual
        // component and the post-physics skeleton finish the move.
        ReleaseParticipantPose();
        for (auto* Part : TInlineComponentArray<USkeletalMeshComponent*>(Pawn.Get()))
        {
            Part->ResetAnimInstanceDynamics(ETeleportType::TeleportPhysics);
            Part->ForceClothNextUpdateTeleportAndReset();
        }
        FormalPoseMesh=Mesh;
        auto* Source=Cast<USkeletalMeshComponent>(Mesh->LeaderPoseComponent.Get());
        if (!Source) Source=Mesh;
        FormalBoneSource=Source;
        PriorFormalMeshTick=Source->VisibilityBasedAnimTickOption;
        bFormalMeshWasPaused=Source->bPauseAnims;
        Source->bPauseAnims=false;
        Source->VisibilityBasedAnimTickOption=EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
        FormalArrivalBoneRevision=Mesh->GetBoneTransformRevisionNumber();
        AddTickPrerequisiteComponent(Mesh);
        if (Source!=Mesh) AddTickPrerequisiteComponent(Source);
    }
    if (FormalPoseMesh.Get()!=Mesh || Mesh->GetBoneTransformRevisionNumber()==FormalArrivalBoneRevision)
    { Reason=TEXT("waiting for an updated Night skeletal pose"); return false; }

    const auto* Capsule=Cast<UCapsuleComponent>(Pawn->GetRootComponent());
    const FVector Root=Pawn->GetActorLocation();
    const FVector Pelvis=Mesh->GetSocketLocation(TEXT("pelvis"));
    const FTransform SocketPose=Mount->GetSocketTransform(Socket);
    auto* Body=FindVisibleBody();
    FormalVisibleMesh=Body;
    const auto InTorso=[Capsule,Root](const FVector& Point)
    {
        return Capsule && !Point.ContainsNaN() &&
            FMath::Abs(Point.Z-Root.Z)<Capsule->GetScaledCapsuleHalfHeight()*.72 &&
            FVector::DistSquared2D(Point,Root)<FMath::Square(Capsule->GetScaledCapsuleRadius()+12.);
    };
    if (!Body || SocketPose.ContainsNaN() || !InTorso(Pelvis) || !InTorso(SocketPose.GetLocation()) ||
        !InTorso(Body->GetSocketLocation(TEXT("pelvis"))) ||
        FVector::Dist(Body->GetSocketLocation(TEXT("pelvis")),Pelvis)>Capsule->GetScaledCapsuleRadius())
    {
        StableWaistPose.Reset();
        Reason=TEXT("visible torso and waist socket are not inside the arrived Pawn capsule");
        return false;
    }
    // A newly evaluated bone revision can still be in the middle of a ragdoll/Mover correction.
    const double Now=GetWorld()->GetTimeSeconds();
    if (!StableWaistPose || !SocketPose.GetLocation().Equals(StableWaistPose->GetLocation(),2.) ||
        SocketPose.GetRotation().AngularDistance(StableWaistPose->GetRotation())>FMath::DegreesToRadians(5.))
    {
        StableWaistPose=SocketPose;
        StableWaistSince=Now;
    }
    if (Now-StableWaistSince<.12)
    { Reason=TEXT("waiting for the actual waist socket to settle"); return false; }
    return true;
}

void AYIXIV3Cinematic::RestoreFormalNightPose()
{
    if (!PriorFormalMeshTick.IsSet()) return;
    if (auto* Source=FormalBoneSource.Get())
    {
        Source->VisibilityBasedAnimTickOption=*PriorFormalMeshTick;
        Source->bPauseAnims=bFormalMeshWasPaused;
        if (Source!=FormalPoseMesh.Get()) RemoveTickPrerequisiteComponent(Source);
    }
    if (auto* Mesh=FormalPoseMesh.Get()) RemoveTickPrerequisiteComponent(Mesh);
    PriorFormalMeshTick.Reset();
}

bool AYIXIV3Cinematic::BuildFormalNightView(FMinimalViewInfo& View, FString& Reason) const
{
    const auto* Mesh=Toy->FindComponentByClass<UStaticMeshComponent>();
    const auto* Root=Toy->GetRootComponent();
    const auto* Parent=Root ? Root->GetAttachParent() : nullptr;
    if (!Parent || Parent->GetOwner()!=Pawn || !Mesh || !Mesh->GetStaticMesh() || !Mesh->ShouldRender() || Toy->IsHidden())
    { Reason=TEXT("the real toy is not visibly attached to the Night Pawn"); return false; }

    const FTransform& ToyFrame=Mesh->GetComponentTransform();
    const FBox WorldBox=Mesh->GetStaticMesh()->GetBoundingBox().TransformBy(ToyFrame);
    const FVector Center=ToyFrame.TransformPosition(Mesh->GetStaticMesh()->GetBounds().Origin);
    const FRotator Yaw(0,Pawn->GetActorRotation().Yaw,0);
    const auto* Capsule=Cast<UCapsuleComponent>(Pawn->GetRootComponent());
    const auto* PawnMesh=FormalPoseMesh.Get();
    const FVector Pelvis=PawnMesh ? PawnMesh->GetSocketLocation(TEXT("pelvis")) : Pawn->GetActorLocation();
    const FVector PawnCenter=Pawn->GetActorLocation();
    if (!Capsule || Center.ContainsNaN() || !WorldBox.IsValid ||
        FMath::Abs(Center.Z-PawnCenter.Z)>Capsule->GetScaledCapsuleHalfHeight() ||
        FVector::DistSquared(Center,Pelvis)>FMath::Square(120.))
    { Reason=TEXT("the attached toy is outside its local framing range"); return false; }

    const auto TryEye=[&](const FVector& Eye)
    {
        if (Eye.ContainsNaN() || Eye.Z<=PawnCenter.Z-Capsule->GetScaledCapsuleHalfHeight()+12. ||
            FVector::DistSquared2D(Eye,PawnCenter)<FMath::Square(Capsule->GetScaledCapsuleRadius()+12.) ||
            FVector::DistSquared(Eye,PawnCenter)>FMath::Square(600.) ||
            FVector::DotProduct(Eye-PawnCenter,Yaw.Vector())>=-15. ||
            WorldBox.ComputeSquaredDistanceToPoint(Eye)<FMath::Square(12.))
        { Reason=TEXT("the Night close-up camera is outside its local framing or near-clip safety range"); return false; }

        FCollisionQueryParams Query(SCENE_QUERY_STAT(YIXIFormalWaistSight),false,this);
        Query.AddIgnoredActor(Pawn);
        Query.AddIgnoredActor(Toy);
        FHitResult Hit;
        if (!ClearCameraPath(Center,Eye) || GetWorld()->LineTraceSingleByChannel(Hit,Eye,Center,ECC_Visibility,Query))
        { Reason=TEXT("the Night waist camera has an obstructed sightline"); return false; }
        // The world sweep ignores the participant. Stop the costume trace at the near toy surface.
        const FVector ToToy=(Center-Eye).GetSafeNormal();
        const FVector ToyFront=Eye+ToToy*FMath::Max(0.,FMath::Sqrt(WorldBox.ComputeSquaredDistanceToPoint(Eye))-1.);
        FCollisionQueryParams BodySight(SCENE_QUERY_STAT(YIXIFormalCostumeSight),false);
        for (auto* Part : TInlineComponentArray<USkeletalMeshComponent*>(Pawn.Get()))
        {
            if (Part->IsRegistered() && Part->ShouldRender() && Part->GetPhysicsAsset() &&
                Part->LineTraceComponent(Hit,Eye,ToyFront,BodySight))
            { Reason=FString::Printf(TEXT("costume %s obscures the waist toy"),*Part->GetName()); return false; }
        }
        View=LookAt(Eye,Center,LockedToyFOV);
        View.Rotation.Roll=0.f;
        Reason.Reset();
        return true;
    };

    if (bMatchNightViewToFloor && FloorPose.IsValid())
    {
        const FVector DayLocal=FloorPose.InverseTransformVectorNoScale(FloorView.Location-FloorToyCenter);
        const FVector NightDirection=ToyFrame.TransformVectorNoScale(DayLocal).GetSafeNormal();
        if (!NightDirection.IsNearlyZero() && TryEye(Center+NightDirection*CloseupDistance)) return true;
    }
    FVector Rear=NightCloseupDirection;
    Rear.X=FMath::Min(-.25,Rear.X);
    return TryEye(Center+Yaw.RotateVector(Rear.GetSafeNormal())*CloseupDistance);
}

void AYIXIV3Cinematic::LogFormalNightCamera(const TCHAR* Phase, const FMinimalViewInfo* Intended) const
{
    const auto* Transition=FormalTransition.Get();
    if (!Transition || !IsValid(Pawn) || !IsValid(Toy) || !IsValid(PC) || !PC->PlayerCameraManager) return;
    const auto* Stream=UGameplayStatics::GetStreamingLevel(this,Transition->NightStreamingLevel);
    const auto* Mesh=FindVisibleBody();
    USceneComponent* Mount=nullptr; FName Socket;
    if (IsValid(Carry)) Carry->GetWaistMount(Mount,Socket);
    const auto* MountMesh=Cast<USkeletalMeshComponent>(Mount);
    const auto* Root=Toy->GetRootComponent();
    const auto* Parent=Root ? Root->GetAttachParent() : nullptr;
    const FMinimalViewInfo& Live=PC->PlayerCameraManager->GetCameraCacheView();
    const FMinimalViewInfo& View=Intended ? *Intended : Live;
    const auto* Day=UGameplayStatics::GetStreamingLevel(this,Transition->DayStreamingLevel);
    auto* Lights=Transition->LightStateSequence.Get();
    auto* LightPlayer=Lights ? Lights->GetSequencePlayer() : nullptr;
    UE_LOG(LogYIXIV3,Display,TEXT("YIXI_P04_REGRESSION %s frame=%llu mode=%s viewTarget=%s cine=%s pos=%s rot=%s fov=%.2f distancePawn=%.1f distanceToy=%.1f pawn=%s pawnRot=%s pawnVisible=%d mesh=%s meshPos=%s meshVisible=%d pelvis=%s toy=%s mount=%s socket=%s level=%s destWorld=%s world=%s dayLoadedVisible=%d/%d nightLoadedVisible=%d/%d shot=%s inputHeld=%d ignoredMoveLook=%d/%d dayFrameHeld=%d lights=%s checkedFrame=%d liveFrame=%d meshTransform=%s meshHiddenInGame=%d ownerNoSee=%d onlyOwnerSee=%d bodyPelvis=%s"),
        Phase,GFrameCounter,Intended ? TEXT("proposed") : TEXT("camera-cache"),*GetNameSafe(PC->GetViewTarget()),
        *GetNameSafe(CameraActor),*View.Location.ToCompactString(),*View.Rotation.ToCompactString(),View.FOV,
        FVector::Dist(View.Location,Pawn->GetActorLocation()),FVector::Dist(View.Location,Toy->GetActorLocation()),
        *Pawn->GetActorLocation().ToCompactString(),*Pawn->GetActorRotation().ToCompactString(),!Pawn->IsHidden(),
        *GetNameSafe(Mesh),Mesh ? *Mesh->GetComponentLocation().ToCompactString() : TEXT("missing"),Mesh && Mesh->ShouldRender(),
        MountMesh ? *MountMesh->GetSocketLocation(TEXT("pelvis")).ToCompactString() : TEXT("missing"),
        *Toy->GetActorLocation().ToCompactString(),*GetNameSafe(Parent),Root ? *Root->GetAttachSocketName().ToString() : TEXT("None"),
        Stream ? *Stream->LevelTransform.ToString() : TEXT("missing"),*FormalNightPose.GetLocation().ToCompactString(),
        *GetWorld()->GetName(),Day && Day->IsLevelLoaded(),Day && Day->IsLevelVisible(),
        Stream && Stream->IsLevelLoaded(),Stream && Stream->IsLevelVisible(),*UEnum::GetValueAsString(Shot),bInputHeld,
        PC->IsMoveInputIgnored(),PC->IsLookInputIgnored(),FormalDayFrame && FormalDayFrame->IsCaptured(),
        *GetPathNameSafe(Lights ? Lights->GetSequence() : nullptr),Transition->LightingSequenceFrame,
        LightPlayer ? LightPlayer->GetCurrentTime().Time.FrameNumber.Value : -1, Mesh ? *Mesh->GetComponentTransform().ToString() : TEXT("missing"),
        Mesh && Mesh->bHiddenInGame,Mesh && Mesh->bOwnerNoSee,Mesh && Mesh->bOnlyOwnerSee,
        Mesh ? *Mesh->GetSocketLocation(TEXT("pelvis")).ToCompactString() : TEXT("missing"));
}

void AYIXIV3Cinematic::Tick(float Delta)
{
    Super::Tick(Delta);
    if (bClosing || Shot==EYIXIV3Shot::Idle) return;
    if (Shot==EYIXIV3Shot::ReturningToDay)
    {
        if (!IsValid(Pawn) || !IsValid(PC) || PC->GetPawn()!=Pawn ||
            Pawn->GetActorLocation().Equals(DayPawnPose.GetLocation(),10.) || (Waiting+=Delta)>2.f)
            Close(false,TEXT("formal cut rollback"));
        return;
    }
    auto* Mix=PresentationAudio();
    if ((!bDayOnlyPreview && !IsValid(Story)) || !IsValid(PC) || !IsValid(Pawn) || PC->GetPawn()!=Pawn || !IsValid(Toy)
        || !IsValid(Carry) || Carry->GetToyActor()!=Toy || !IsValid(Player) || !IsValid(CameraActor) || !Mix)
    { Close(bCut,TEXT("presentation participant or owned resource changed")); return; }
    SkipHeld=PC->IsInputKeyDown(EKeys::SpaceBar) ? SkipHeld+Delta : 0;
    if (SkipHeld>=.65f) RequestSkip();
    const float Next=SequenceSeconds+Delta;
    switch (Shot)
    {
    case EYIXIV3Shot::StageAlign:
        UpdateStageAlignment(Delta);
        break;
    case EYIXIV3Shot::Shoulder:
    {
        Sample(bSkip ? HandBlendAt : FMath::Min(Next,HandBlendAt));
        // Let braking settle the shoulder before establishing a single straight approach from the actual gameplay eye.
        if (!bShoulderFramed)
        {
            if (SequenceSeconds<FMath::Min(.75f,ShoulderSetAt*.25f)) { Camera(EntryView); break; }
            HoldParticipantPose();
            if (!ChooseShoulderView()) { Close(false,TEXT("right shoulder sightline or approach obstructed")); return; }
            bShoulderFramed=true;
            ApproachStartTravel=CameraTravel;
        }
        const float Alpha=SequenceSeconds>=ShoulderSetAt ? 1.f :
            FMath::Clamp((CameraTravel-ApproachStartTravel)/FMath::Max(.001f,1.f-ApproachStartTravel),0.f,1.f);
        FMinimalViewInfo View=Between(EntryView,ShoulderView,Alpha);
        if (bUseFixedStage && StageCameraBend.IsSet())
        {
            const float FirstHalf=FMath::SmoothStep(0.f,.5f,Alpha);
            const float SecondHalf=FMath::SmoothStep(.5f,1.f,Alpha);
            View.Location=Alpha<.5f ? FMath::Lerp(EntryView.Location,*StageCameraBend,FirstHalf)
                : FMath::Lerp(*StageCameraBend,ShoulderView.Location,SecondHalf);
        }
        Camera(View);
        if (SequenceSeconds>=HandBlendAt)
        {
            if (!PrepareHandRail()) { Close(false,TEXT("right-side hand or floor rail obstructed")); return; }
            LockedToyFOV=ToyFOV;
            SetShot(EYIXIV3Shot::HandBlend);
        }
        break;
    }
    case EYIXIV3Shot::HandBlend:
    {
        Sample(bSkip ? HandAt : FMath::Min(Next,HandAt));
        LockedToyFOV=ToyFOV;
        Camera(Between(ShoulderView,ToyView(false),1.f-FMath::Clamp(CameraTravel,0.f,1.f)));
        if (SequenceSeconds>=HandAt)
        {
            SetShot(EYIXIV3Shot::Hand);
        }
        break;
    }
    case EYIXIV3Shot::Hand:
        Sample(bSkip ? ReleaseAt : FMath::Min(Next,ReleaseAt));
        Camera(ToyView(false));
        if (SequenceSeconds>=ReleaseAt)
        {
            if ((!UsesDayBindings() && !NightDestination(GoalLocation)) ||
                !ResolveToyLanding(FloorPose) || !PrepareDropCamera() ||
                !Carry->BeginSequencedVerticalDrop(FloorPose,LandedAt-ReleaseAt,ToyLandingSurface.Get()))
            { Close(false,TEXT("drop path or night landing invalid")); return; }
            SetShot(EYIXIV3Shot::Fall);
        }
        break;
    case EYIXIV3Shot::Fall:
    case EYIXIV3Shot::FloorReframe:
    {
        const bool bFalling=Shot==EYIXIV3Shot::Fall;
        const float CameraTime=bSkip ? (bFalling ? LandedAt : StableAt) : FMath::Min(Next,StableAt);
        if (bFalling)
        {
            Sample(FMath::Min(CameraTime,LandedAt));
            if (Carry->GetCarryState()==EYIXIToyCarryState::Falling &&
                !Carry->ApplySequencedDropProgress(bSkip ? 1.f : DropProgress))
            { Close(false,TEXT("vertical drop obstructed")); return; }
            if (Carry->GetCarryState()==EYIXIToyCarryState::HeldHand)
            { Close(false,TEXT("vertical drop rolled back")); return; }
            if (SequenceSeconds>=LandedAt)
            {
                if (Carry->GetCarryState()!=EYIXIToyCarryState::Dropped ||
                    !Toy->GetActorLocation().Equals(FloorPose.GetLocation(),.2))
                { Close(false,TEXT("toy did not reach the landing frame")); return; }
                if (StableAt>LandedAt) SetShot(EYIXIV3Shot::FloorReframe);
            }
        }
        else
        {
            if (!bDayOnlyPreview && ((!FormalStory && !bNightPreviewReady) || !Carry->CanAttachToWaist()))
            { Close(false,TEXT("night readiness lost during the floor slide")); return; }
            if (Carry->GetCarryState()!=EYIXIToyCarryState::Dropped ||
                !Toy->GetActorLocation().Equals(FloorPose.GetLocation(),.2) ||
                !Toy->GetActorQuat().Equals(FloorPose.GetRotation(),1.e-4))
            { Close(false,TEXT("toy moved during the floor slide")); return; }
        }
        // Use any remainder of this tick after touchdown without advancing the toy past Landed.
        if (SequenceSeconds<CameraTime) Sample(CameraTime);
        if (!UpdateDropCamera()) { Close(false,TEXT("continuous drop camera path obstructed")); return; }
        if (SequenceSeconds>=StableAt)
        {
            HoldGameStart=GetWorld()->GetTimeSeconds();
            SetShot(EYIXIV3Shot::Hold);
            if (FormalStory)
            {
                DayPawnPose=Pawn->GetActorTransform();
                LogFormalNightCamera(TEXT("day-hold-start"));
            }
        }
        break;
    }
    case EYIXIV3Shot::Hold:
    {
        if ((!bDayOnlyPreview && ((!FormalStory && !bNightPreviewReady) || !Carry->CanAttachToWaist())) ||
            Carry->GetCarryState()!=EYIXIToyCarryState::Dropped)
        { Close(false,TEXT("readiness lost during the floor hold")); return; }
        const float HoldDuration=CutAt-StableAt;
        const float HoldTime=GetWorld()->GetTimeSeconds()-HoldGameStart;
        const bool CutNow=HoldTime>=HoldDuration || (bSkip && HoldTime>=.15f);
        if (FormalStory && !bMoved)
        {
            if (!FindVisibleBody() || !Pawn->GetActorLocation().Equals(DayPawnPose.GetLocation(),10.f) ||
                PC->GetViewTarget()!=CameraActor)
            {
                LogFormalNightCamera(TEXT("day-presentation-invalid"));
                Close(false,TEXT("Day body or movie camera lost before cut"));
                return;
            }
            if (!bLoggedDayRemaining && HoldTime>=HoldDuration-2.f)
            {
                bLoggedDayRemaining=true;
                LogFormalNightCamera(TEXT("day-two-seconds-left"));
            }
        }
        Sample(CutNow ? CutAt : StableAt+HoldTime);
        Camera(FloorView);
        const float Lead=FMath::Min(FMath::Max(EchoLeadSeconds,.05f),HoldDuration);
        Mix->SetDayEcho(bSkip ? 1.f : FMath::Clamp((HoldTime-HoldDuration+Lead)/Lead,0.f,1.f));
        if (!CutNow) break;
        if (bDayOnlyPreview)
        {
            bDayPreviewConsumed=true;
            GetWorldTimerManager().ClearTimer(DayPreviewRetryTimer);
            UE_LOG(LogYIXIV3,Display,TEXT("DAY_PREVIEW_COMPLETE hold=%.3f skipped=%d"),HoldTime,bSkip);
            Close(false,TEXT("day preview complete"));
            return;
        }
        auto* Transition=FormalTransition.Get();
        if (FormalStory && (!Transition || Transition->HasFormalNightFailed()))
        { Close(false,TEXT("formal Night preparation failed")); return; }
        // Relocate only after the full hold to keep the real feet and their shadows in the floor shot.
        if (!bMoved)
        {
            if (Transition)
            {
                if (!Transition->GetFormalLanding(Pawn,FormalNightPose))
                {
                    if (HoldTime>HoldDuration+Transition->StreamingTimeoutSeconds)
                        Close(false,TEXT("formal Night landing never became ready"));
                    return;
                }
                GoalLocation=FormalNightPose.GetLocation();
                if (!FormalDayFrame)
                {
                    FormalDayFrame=FYIXIFormalCutFrameHold::Begin(PC);
                    if (!FormalDayFrame) { Close(false,TEXT("formal Day viewport unavailable")); return; }
                    FormalPoseDeadline=GetWorld()->GetTimeSeconds()+2.;
                }
                if (!FormalDayFrame->IsCaptured())
                {
                    if (GetWorld()->GetTimeSeconds()>=FormalPoseDeadline)
                        Close(false,TEXT("no rendered Day frame acknowledged; Pawn retained in Day"));
                    return;
                }
                FormalPoseDeadline=0;
            }
            else if (!NightDestination(GoalLocation))
            { Close(false,TEXT("night destination unavailable")); return; }
            DayPawnPose=Pawn->GetActorTransform();
            const FRotator NightRotation=Transition ? FormalNightPose.Rotator() : NightLanding->GetComponentRotation();
            if (CinematicInput)
            {
                CinematicInput->MoveVelocity=FVector::ZeroVector;
                CinematicInput->Facing=FRotator(0,NightRotation.Yaw,0).Vector();
            }
            if (!MoveParticipant(FTransform(NightRotation,GoalLocation)))
            { Close(false,TEXT("night destination unavailable")); return; }
            bMoved=true;
        }
        if (FVector::Dist(Pawn->GetActorLocation(),GoalLocation)>10.f ||
            (Transition && FMath::Abs(FMath::FindDeltaAngleDegrees(Pawn->GetActorRotation().Yaw,FormalNightPose.Rotator().Yaw))>3.f))
        {
            if ((Waiting+=Delta)>1.f) Close(false,TEXT("night relocation failed"));
            return;
        }
        if (Transition)
        {
            const double Now=GetWorld()->GetTimeSeconds();
            if (FormalPoseDeadline==0) FormalPoseDeadline=Now+3.;
            FString Reason;
            if (!UpdateFormalNightPose(Reason))
            {
                if (Now>=FormalPoseDeadline)
                {
                    UE_LOG(LogYIXIV3,Warning,TEXT("YIXI_P04_REGRESSION refused: %s"),*Reason);
                    LogFormalNightCamera(TEXT("night-pose-timeout"));
                    Close(false,TEXT("Night pose synchronization failed"));
                }
                return;
            }
            // The Day image is already held on the render thread. Prepare the actual Night
            // mesh and its attachment now, so the candidate view measures the visible prop.
            if (!Carry->PrepareWaistAttachment())
            { Close(false,TEXT("Night waist attachment or toy appearance preparation failed")); return; }
            if (!BuildFormalNightView(NightView,Reason))
            {
                UE_LOG(LogYIXIV3,Warning,TEXT("YIXI_P04_REGRESSION refused: %s"),*Reason);
                Close(false,TEXT("Night close-up is unsafe"));
                return;
            }
            LogFormalNightCamera(TEXT("pre-cut"),&NightView);
            if (!Transition->ApplyFormalCutLighting(Pawn))
            { Close(false,TEXT("formal Night lighting is unsafe")); return; }
        }
        const int32 Id=Story->RequestV3Cut(Pawn,Toy);
        // Blueprint listeners can synchronously interrupt during either story notification.
        if (Shot!=EYIXIV3Shot::Hold || !IsValid(Story) || !IsValid(Carry) || !IsValid(Toy)) return;
        const bool bStoryCommitted=Id>0 && (Story->Stage==EYIXIInteractionStoryStage::V3NightPresentation ||
            Story->CompleteMatchCut(Id,true));
        if (Shot!=EYIXIV3Shot::Hold || !IsValid(Story) || !IsValid(Carry) || !IsValid(Toy)) return;
        if (!bStoryCommitted || Carry->GetToyActor()!=Toy || Carry->GetCarryState()!=EYIXIToyCarryState::AttachedAtWaist)
        { Close(false,TEXT("cut refused or waist attachment failed")); return; }
        bCut=true;
        if (Transition)
        {
            Carry->CommitPreparedWaistAttachment();
            Transition->CommitFormalCut(Pawn);
        }
        else ShowNight(true);
        if (!Transition)
        {
            CaptureWaistInsert();
            NightView=ToyView(true);
        }
        Camera(NightView);
        if (Transition && PC->GetViewTarget()!=CameraActor) PC->SetViewTarget(CameraActor);
        PC->PlayerCameraManager->SetGameCameraCutThisFrame();
        // V3 ticks in PostPhysics, before this world's camera-manager update and viewport draw.
        // Previously submitted Day families keep the captured image until their render completes.
        FormalDayFrame.Reset();
        Mix->CommitNightMix();
        SetShot(EYIXIV3Shot::Night);
        UE_LOG(LogYIXIV3,Display,TEXT("MATCH id=%d sameToy=%s waist=true holdGame=%.5f skip=%d"),Id,*Toy->GetPathName(),HoldTime,bSkip);
        break;
    }
    case EYIXIV3Shot::Night:
    {
        if (FormalStory)
        {
            const FMinimalViewInfo& Live=PC->PlayerCameraManager->GetCameraCacheView();
            const FVector LiveEye=Live.Location;
            const FVector PawnPosition=Pawn->GetActorLocation();
            if (!bLoggedFormalFirstFrame)
            {
                LogFormalNightCamera(TEXT("cut-first-frame"));
                bLoggedFormalFirstFrame=true;
            }
            const auto* ToyMesh=Toy->FindComponentByClass<UStaticMeshComponent>();
            const auto* Capsule=Cast<UCapsuleComponent>(Pawn->GetRootComponent());
            const FVector Center=ToyMesh ? ToyMesh->Bounds.Origin : Toy->GetActorLocation();
            const FVector ToToy=Center-LiveEye;
            const auto* Root=Toy->GetRootComponent();
            if (PC->GetViewTarget()!=CameraActor || !LiveEye.Equals(NightView.Location,2.) ||
                !Live.Rotation.Equals(NightView.Rotation,1.f) || !Capsule || Center.ContainsNaN() ||
                !Root || Root->GetAttachParent()!=FormalPoseMesh.Get() || !ToyMesh || !ToyMesh->ShouldRender() ||
                FMath::Abs(Center.Z-PawnPosition.Z)>Capsule->GetScaledCapsuleHalfHeight() ||
                FVector::DotProduct(ToToy.GetSafeNormal(),Live.Rotation.Vector())<FMath::Cos(FMath::DegreesToRadians(Live.FOV*.28f)) ||
                !FindVisibleBody())
            {
                UE_LOG(LogYIXIV3,Warning,TEXT("YIXI_P04_REGRESSION invalid Night framing or attachment; ending insert with gameplay recovery"));
                LogFormalNightCamera(TEXT("invalid-insert"));
                Close(true,TEXT("unsafe Night close-up"));
                return;
            }
            Sample(FMath::Min(Next,PullAt));
            if (!bLoggedFormalMidpoint && SequenceSeconds>=.5f*(CutAt+PullAt))
            {
                LogFormalNightCamera(TEXT("insert-midpoint"));
                bLoggedFormalMidpoint=true;
            }
            if (SequenceSeconds>=PullAt)
            {
                BeginFormalNightPullback();
                break;
            }
            Camera(NightView);
            break;
        }
        Sample(FMath::Min(Next,ReturnAt));
        if (SequenceSeconds<PullAt)
        {
            UpdateWaistInsert(0.f);
            Camera(NightView);
            break;
        }
        ReleaseParticipantPose();
        if (WaistParent.IsValid())
        {
            const float BlendSeconds=FMath::Min(.45f, ReturnAt-PullAt);
            const float Progress=SequenceSeconds-PullAt;
            if (Progress>=BlendSeconds) RestoreWaistAttachment();
            else UpdateWaistInsert(FMath::SmoothStep(0.f,BlendSeconds,Progress));
        }
        const FRotator Yaw(0,NightLanding->GetComponentRotation().Yaw,0);
        const FVector Position=Pawn->GetActorLocation();
        const FMinimalViewInfo Back=LookAt(Position+Yaw.RotateVector(PullbackOffset),Position+FVector(0,0,45),EntryView.FOV);
        FMinimalViewInfo V=Between(NightView,Back,FMath::Clamp(CameraTravel,0.f,1.f));
        FHitResult Hit;
        FCollisionQueryParams Q(SCENE_QUERY_STAT(YIXIV3NightCamera),false,this);
        Q.AddIgnoredActor(Pawn); Q.AddIgnoredActor(Toy);
        if (GetWorld()->SweepSingleByChannel(Hit,NightView.Location,V.Location,FQuat::Identity,ECC_Camera,FCollisionShape::MakeSphere(5),Q))
            V.Location=Hit.Location;
        V.Rotation.Roll=0.f;
        Camera(V);
        if (SequenceSeconds>=ReturnAt || (bSkip && SequenceSeconds>=PullAt)) BeginHandoff();
        break;
    }
    case EYIXIV3Shot::Handoff:
        Sample(FMath::Min(Next,EndAt));
        if (SequenceSeconds>=EndAt)
        {
            if (PC->GetViewTarget()==Pawn || (Waiting+=Delta)>.5f)
                Close(true,TEXT("gameplay handoff"));
        }
        break;
    default: break;
    }
}

void AYIXIV3Cinematic::BeginHandoff()
{
    RestoreWaistAttachment();
    if (auto* Gameplay=Pawn->FindComponentByClass<UGameplayCameraComponent>())
        Gameplay->ActivateCameraForPlayerController(PC,false);
    PC->SetViewTargetWithBlend(Pawn,EndAt-ReturnAt,VTBlend_Cubic,0,true);
    Waiting=0; Sample(ReturnAt); SetShot(EYIXIV3Shot::Handoff);
}

void AYIXIV3Cinematic::BeginFormalNightPullback()
{
    LogFormalNightCamera(TEXT("pullback-start"));
    RestoreWaistAttachment();
    ReleaseParticipantPose();
    RestoreFormalNightPose();
    if (auto* Gameplay=Pawn->FindComponentByClass<UGameplayCameraComponent>())
        Gameplay->ActivateCameraForPlayerController(PC,false);
    // The frozen Cine view is the outgoing target. The camera manager evaluates the
    // actual third-person Pawn camera as the destination of the 3.5-second blend.
    const float BlendSeconds=bSkip ? EndAt-ReturnAt : ReturnAt-PullAt;
    PC->SetViewTargetWithBlend(Pawn,BlendSeconds,VTBlend_Cubic,0,true);
    Waiting=0;
    if (bSkip) Sample(ReturnAt);
    SetShot(EYIXIV3Shot::Handoff);
}

void AYIXIV3Cinematic::Close(bool bCompleted, const TCHAR* Reason)
{
    if (bClosing) return;
    TGuardValue<bool> Guard(bClosing,true);
    if (!bCompleted && FormalStory && IsValid(Carry)) Carry->CancelPreparedWaistAttachment();
    const bool bSamePawn=IsValid(Pawn) && IsValid(PC) && PC->GetPawn()==Pawn;
    if (!bCompleted && FormalStory && bMoved && bSamePawn && !bEndingPresentationPlay && Shot!=EYIXIV3Shot::ReturningToDay)
    {
        if (CinematicInput)
        {
            CinematicInput->MoveVelocity=FVector::ZeroVector;
            CinematicInput->Facing=DayPawnPose.Rotator().Vector();
        }
        if (MoveParticipant(DayPawnPose))
        {
            Waiting=0.f;
            SetShot(EYIXIV3Shot::ReturningToDay);
            return;
        }
    }
    SetActorTickEnabled(false);
    RestoreWaistAttachment();
    ReleaseParticipantPose();
    RestoreFormalNightPose();
    if (!bCompleted)
    {
        if (IsValid(Story) && IsValid(Story->GirlAftermath)) Story->GirlAftermath->SetActorHiddenInGame(true);
        if (bMoved && bSamePawn && !FormalStory) MoveParticipant(DayPawnPose);
        if (IsValid(Carry) && bSamePawn && IsValid(Toy) && Carry->GetToyActor()==Toy &&
            Carry->GetCarryState()!=EYIXIToyCarryState::HeldHand)
            Carry->RestoreToyToHand();
        if (!UsesDayBindings()) ShowNight(false);
        if (auto* Mix=PresentationAudio())
        {
            if (FormalStory) Mix->CancelDayMix();
            else Mix->RestoreDayMix();
        }
    }
    if (bSamePawn)
    {
        if (!bCompleted) PC->SetControlRotation(DayControlRotation);
        if (auto* Gameplay=Pawn->FindComponentByClass<UGameplayCameraComponent>())
            Gameplay->ActivateCameraForPlayerController(PC,false);
        AActor* Target=bCompleted || !PreviousView.IsValid() ? Pawn.Get() : PreviousView.Get();
        if (!FormalStory || PC->GetViewTarget()!=Target) PC->SetViewTarget(Target);
    }
    FormalDayFrame.Reset();
    if (IsValid(PC) && bInputHeld)
    {
        PC->SetIgnoreMoveInput(false); PC->SetIgnoreLookInput(false);
    }
    if (IsValid(Pawn) && bInputHeld)
    {
        if (bPawnInputWasEnabled) Pawn->EnableInput(bSamePawn ? PC.Get() : nullptr);
        if (auto* Mover=Pawn->FindComponentByClass<UMoverComponent>())
        {
            SetMoverVelocity(*Mover,FVector::ZeroVector);
            Mover->InputProducers=SavedMoverInputs;
        }
    }
    SavedMoverInputs.Reset();
    CinematicInput=nullptr;
    bInputHeld=false;
    if (IsValid(Interactor)) Interactor->SetCinematicSuppressed(bWasSuppressed);
    if (FormalStory && bCompleted) LogFormalNightCamera(TEXT("gameplay-restored"));
    if (IsValid(CameraActor)) CameraActor->Destroy();
    CameraActor=nullptr;
    if (IsValid(Player)) Player->Stop();
    UE_LOG(LogYIXIV3,Display,TEXT("closed night=%d reason=%s view=%s controlRestored=%d"),bCompleted,Reason,
        IsValid(PC) ? *GetNameSafe(PC->GetViewTarget()) : TEXT("None"),bSamePawn);
    if (UsesDayBindings())
    {
        bDayPreviewRequiresExit=!bDayPreviewConsumed;
        const bool bToyRestored=IsValid(Carry) && Carry->GetToyActor()==Toy &&
            Carry->GetCarryState()==EYIXIToyCarryState::HeldHand && IsValid(Toy) && Toy->GetAttachParentActor()==Pawn;
        UE_LOG(LogYIXIV3,Display,TEXT("DAY_PREVIEW_CLOSED reason=%s toyRestored=%d"),Reason,bToyRestored);
    }
    SetShot(EYIXIV3Shot::Idle);
    if (IsValid(Story) && !IsActorBeingDestroyed())
    {
        if (bCompleted) Story->FinishV3Presentation(Pawn);
        else Story->AbortV3Presentation(Pawn);
    }
    if (auto* Transition=FormalTransition.Get(); FormalStory && Transition && !bEndingPresentationPlay)
    {
        if (bCompleted)
        {
            bDayPreviewConsumed=true;
            GetWorldTimerManager().ClearTimer(DayPreviewRetryTimer);
            Transition->FinishFormalPresentation(Pawn);
        }
        else
        {
            const bool bSafeToUnload=!bMoved || (bSamePawn && Pawn->GetActorLocation().Equals(DayPawnPose.GetLocation(),10.));
            Transition->CancelFormalNight(Pawn,bSafeToUnload);
        }
    }
    PreviousView.Reset();
    FormalPoseMesh.Reset();
    FormalBoneSource.Reset();
    FormalVisibleMesh.Reset();
    Story=nullptr; PC=nullptr; Pawn=nullptr; Toy=nullptr; Interactor=nullptr; Carry=nullptr;
}

void AYIXIV3Cinematic::EndPlay(EEndPlayReason::Type Reason)
{
    bEndingPresentationPlay=true;
    if (UsesDayBindings())
    {
        GetWorldTimerManager().ClearTimer(DayPreviewRetryTimer);
        if (IsValid(DayPreviewPickup))
            DayPreviewPickup->OnToyPickedUp.RemoveDynamic(this,&AYIXIV3Cinematic::HandleDayPreviewPickup);
    }
    if (Shot!=EYIXIV3Shot::Idle) Close(bCut,TEXT("end play"));
    if (IsValid(PlayerActor)) PlayerActor->Destroy();
    Super::EndPlay(Reason);
}
