#include "YIXI_Interaction/Story/YIXIV3Cinematic.h"
#include "YIXI_Interaction/Story/YIXIInteractionStoryCoordinator.h"
#include "YIXI_Interaction/Story/YIXIV3AudioComponent.h"
#include "YIXI_Interaction/DialogueToy/YIXIToyCarryComponent.h"
#include "YIXI_Interaction/ScriptedProjectile/YIXIScriptedRock.h"
#include "YIXI_Interaction/YIXIInteractorComponent.h"
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
#include "Engine/World.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/GameplayCameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "InputCoreTypes.h"
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
    ShowNight(false);
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
    if (!IsValid(Sender) || !IsValid(Participant) || Sender->GetWorld()!=GetWorld() || Participant->GetWorld()!=GetWorld()) return;
    Audio->BeginDayMix();
    // The preview set lives in the persistent sandbox. T01 owns streaming in a formal map.
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

bool AYIXIV3Cinematic::ClearCameraPath(FVector Start, FVector End) const
{
    FCollisionQueryParams Q(SCENE_QUERY_STAT(YIXIV3Camera),false,this);
    Q.AddIgnoredActor(Pawn); Q.AddIgnoredActor(Toy);
    return !GetWorld()->SweepTestByChannel(Start,End,FQuat::Identity,ECC_Camera,FCollisionShape::MakeSphere(5.f),Q);
}

bool AYIXIV3Cinematic::ClearToySight(FVector Subject, FVector Eye) const
{
    // The story rock can intentionally have no camera collision. It still occludes the image.
    if (Story && Story->AttackCue && Story->AttackCue->RockMesh)
    {
        const FBox Rock=Story->AttackCue->RockMesh->Bounds.GetBox().ExpandBy(3.);
        if (Rock.IsInsideOrOn(Eye) || FMath::LineBoxIntersection(Rock,Subject,Eye,Eye-Subject)) return false;
    }
    return ClearCameraPath(Subject,Eye);
}

bool AYIXIV3Cinematic::PrepareHandRail()
{
    FVector Center, Extent;
    Toy->GetActorBounds(false,Center,Extent);
    FTransform Landing;
    if (!Carry->FindVerticalCinematicLanding(Landing)) return false;
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
    if (!ClearCameraPath(ShoulderView.Location,HandEye)) return false;
    const FVector FloorDelta=Landing.GetLocation()-Toy->GetActorLocation();
    if (!ClearCameraPath(HandEye,HandEye+FloorDelta)) return false;
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
        if (!ClearCameraPath(PreviousEye,View.Location) || !ClearToySight(Center,View.Location)) return false;
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
    if (Shot!=EYIXIV3Shot::Idle || bClosing || !IsValid(Sender) || !IsValid(Participant) ||
        Sender->GetWorld()!=GetWorld() || Participant->GetWorld()!=GetWorld() ||
        (bUseFixedStage && !CanEnterFixedStage(Participant))) return false;
    Story=Sender; Pawn=Participant; PC=Cast<APlayerController>(Pawn->GetController());
    Carry=UYIXIToyCarryComponent::FindForPawn(Pawn);
    Toy=Carry ? Carry->GetToyActor() : nullptr;
    PrepareNight(Sender,Participant);
    if (!PC || !PC->IsLocalController() || !PC->PlayerCameraManager || !IsValid(Toy) || !Carry->CanAttachToWaist() ||
        !IsValid(Story->AttackCue) || !ReadTimeline() || !NightDestination(GoalLocation))
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
    Sample(0);
    Camera(EntryView);
    Audio->BeginDayMix();
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

void AYIXIV3Cinematic::Tick(float Delta)
{
    Super::Tick(Delta);
    if (bClosing || Shot==EYIXIV3Shot::Idle) return;
    if (!IsValid(Story) || !IsValid(PC) || !IsValid(Pawn) || PC->GetPawn()!=Pawn || !IsValid(Toy)
        || !IsValid(Carry) || Carry->GetToyActor()!=Toy || !IsValid(Player) || !IsValid(CameraActor))
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
            if (!NightDestination(GoalLocation) || !Carry->FindVerticalCinematicLanding(FloorPose) || !PrepareDropCamera() ||
                !Carry->BeginSequencedVerticalDrop(FloorPose,LandedAt-ReleaseAt))
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
            if (!bNightPreviewReady || !Carry->CanAttachToWaist())
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
        }
        break;
    }
    case EYIXIV3Shot::Hold:
    {
        if (!bNightPreviewReady || !Carry->CanAttachToWaist() || Carry->GetCarryState()!=EYIXIToyCarryState::Dropped)
        { Close(false,TEXT("readiness lost during the floor hold")); return; }
        const float HoldDuration=CutAt-StableAt;
        const float HoldTime=GetWorld()->GetTimeSeconds()-HoldGameStart;
        const bool CutNow=HoldTime>=HoldDuration || (bSkip && HoldTime>=.15f);
        Sample(CutNow ? CutAt : StableAt+HoldTime);
        Camera(FloorView);
        const float Lead=FMath::Min(FMath::Max(EchoLeadSeconds,.05f),HoldDuration);
        Audio->SetDayEcho(bSkip ? 1.f : FMath::Clamp((HoldTime-HoldDuration+Lead)/Lead,0.f,1.f));
        if (!CutNow) break;
        // Relocate only after the full hold to keep the real feet and their shadows in the floor shot.
        if (!bMoved)
        {
            DayPawnPose=Pawn->GetActorTransform();
            const FRotator NightRotation=NightLanding->GetComponentRotation();
            if (CinematicInput)
            {
                CinematicInput->MoveVelocity=FVector::ZeroVector;
                CinematicInput->Facing=FRotator(0,NightRotation.Yaw,0).Vector();
            }
            if (!NightDestination(GoalLocation) || !MoveParticipant(FTransform(NightRotation,GoalLocation)))
            { Close(false,TEXT("night destination unavailable")); return; }
            bMoved=true;
        }
        if (FVector::Dist(Pawn->GetActorLocation(),GoalLocation)>10.f)
        {
            if ((Waiting+=Delta)>1.f) Close(false,TEXT("night relocation failed"));
            return;
        }
        const int32 Id=Story->RequestV3Cut(Pawn,Toy);
        if (Id<=0 || (Story->Stage!=EYIXIInteractionStoryStage::V3NightPresentation && !Story->CompleteMatchCut(Id,true))
            || Carry->GetToyActor()!=Toy || Carry->GetCarryState()!=EYIXIToyCarryState::AttachedAtWaist)
        { Close(false,TEXT("cut refused or waist attachment failed")); return; }
        bCut=true;
        ShowNight(true);
        CaptureWaistInsert();
        NightView=ToyView(true);
        Camera(NightView);
        PC->PlayerCameraManager->SetGameCameraCutThisFrame();
        Audio->CommitNightMix();
        SetShot(EYIXIV3Shot::Night);
        UE_LOG(LogYIXIV3,Display,TEXT("MATCH id=%d sameToy=%s waist=true holdGame=%.5f skip=%d"),Id,*Toy->GetPathName(),HoldTime,bSkip);
        break;
    }
    case EYIXIV3Shot::Night:
    {
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

void AYIXIV3Cinematic::Close(bool bCompleted, const TCHAR* Reason)
{
    if (bClosing) return;
    TGuardValue<bool> Guard(bClosing,true);
    SetActorTickEnabled(false);
    RestoreWaistAttachment();
    ReleaseParticipantPose();
    const bool bSamePawn=IsValid(Pawn) && IsValid(PC) && PC->GetPawn()==Pawn;
    if (!bCompleted)
    {
        if (IsValid(Story) && IsValid(Story->GirlAftermath)) Story->GirlAftermath->SetActorHiddenInGame(true);
        if (bMoved && bSamePawn) MoveParticipant(DayPawnPose);
        if (IsValid(Carry) && bSamePawn && IsValid(Toy) && Carry->GetToyActor()==Toy &&
            Carry->GetCarryState()!=EYIXIToyCarryState::HeldHand)
            Carry->RestoreToyToHand();
        ShowNight(false);
        Audio->RestoreDayMix();
    }
    if (bSamePawn)
    {
        if (!bCompleted) PC->SetControlRotation(DayControlRotation);
        if (auto* Gameplay=Pawn->FindComponentByClass<UGameplayCameraComponent>())
            Gameplay->ActivateCameraForPlayerController(PC,false);
        PC->SetViewTarget(bCompleted || !PreviousView.IsValid() ? Pawn.Get() : PreviousView.Get());
    }
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
    if (IsValid(CameraActor)) CameraActor->Destroy();
    CameraActor=nullptr;
    if (IsValid(Player)) Player->Stop();
    UE_LOG(LogYIXIV3,Display,TEXT("closed night=%d reason=%s view=%s controlRestored=%d"),bCompleted,Reason,
        IsValid(PC) ? *GetNameSafe(PC->GetViewTarget()) : TEXT("None"),bSamePawn);
    SetShot(EYIXIV3Shot::Idle);
    if (IsValid(Story) && !IsActorBeingDestroyed())
    {
        if (bCompleted) Story->FinishV3Presentation(Pawn);
        else Story->AbortV3Presentation(Pawn);
    }
    PreviousView.Reset();
    Story=nullptr; PC=nullptr; Pawn=nullptr; Toy=nullptr; Interactor=nullptr; Carry=nullptr;
}

void AYIXIV3Cinematic::EndPlay(EEndPlayReason::Type Reason)
{
    if (Shot!=EYIXIV3Shot::Idle) Close(bCut,TEXT("end play"));
    if (IsValid(PlayerActor)) PlayerActor->Destroy();
    Super::EndPlay(Reason);
}
