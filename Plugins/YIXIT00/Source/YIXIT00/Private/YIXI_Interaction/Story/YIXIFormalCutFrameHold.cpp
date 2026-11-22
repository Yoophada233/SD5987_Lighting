#include "YIXIFormalCutFrameHold.h"

#include "Engine/GameInstance.h"
#include "Engine/GameViewportClient.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "PooledRenderTarget.h"
#include "PostProcess/PostProcessMaterialInputs.h"
#include "RenderingThread.h"
#include "SceneView.h"
#include "SceneViewExtension.h"

class FYIXIFormalDayViewExtension final : public FWorldSceneViewExtension
{
public:
    FYIXIFormalDayViewExtension(const FAutoRegister& Register, UWorld* World, FViewport* InViewport)
        : FWorldSceneViewExtension(Register, World), Viewport(InViewport) {}

    ~FYIXIFormalDayViewExtension() override
    {
        if (HeldTexture && !IsInRenderingThread())
        {
            ENQUEUE_RENDER_COMMAND(YIXIReleaseFormalDayFrame)(
                [Texture = MoveTemp(HeldTexture)](FRHICommandListImmediate&) mutable { Texture.SafeRelease(); });
        }
    }

    // A submitted Day-view family keeps its extension until render completion. Unregister
    // only from future families so render-thread lag cannot reveal a partly moved Pawn.
    void EndOnGameThread() { bAcceptViews = false; }
    bool HasCaptured() const { return bCaptured.Load(); }

protected:
    bool IsActiveThisFrame_Internal(const FSceneViewExtensionContext& Context) const override
    {
        return bAcceptViews && Context.Viewport == Viewport && !Context.IsStereoSupported() &&
            FWorldSceneViewExtension::IsActiveThisFrame_Internal(Context);
    }

    void SubscribeToPostProcessingPass(EPostProcessingPass Pass, const FSceneView& SceneView,
        FPostProcessingPassDelegateArray& Callbacks, bool bEnabled) override
    {
        if (Pass == EPostProcessingPass::Tonemap && bEnabled && SceneView.bIsGameView &&
            !SceneView.bIsSceneCapture && !SceneView.bIsPlanarReflection && !SceneView.bIsReflectionCapture &&
            SceneView.Family->Views.Num() == 1)
        {
            Callbacks.Add(FPostProcessingPassDelegate::CreateRaw(this, &FYIXIFormalDayViewExtension::Hold));
        }
    }

private:
    FScreenPassTexture Hold(FRDGBuilder& Graph, const FSceneView& SceneView, const FPostProcessMaterialInputs& Inputs)
    {
        const FScreenPassTexture Source = FScreenPassTexture::CopyFromSlice(Graph,
            Inputs.GetInput(EPostProcessMaterialInput::SceneColor));
        if (!HeldTexture)
        {
            const FScreenPassRenderTarget Copy = FScreenPassRenderTarget::CreateFromInput(
                Graph, Source, ERenderTargetLoadAction::ENoAction, TEXT("YIXI.FormalDayInsert"));
            AddDrawTexturePass(Graph, SceneView, Source, Copy);
            CapturedRect = Source.ViewRect;
            Graph.QueueTextureExtraction(Copy.Texture, &HeldTexture);
            Graph.AddPostExecuteCallback([Owner = SharedThis(this)]
            {
                // RDG publishes extracted resources before its post-execute callbacks.
                Owner->bCaptured.Store(Owner->HeldTexture.IsValid());
            });
            return Inputs.ReturnUntouchedSceneColorForPostProcessing(Graph);
        }

        const FScreenPassTexture Frozen(Graph.RegisterExternalTexture(HeldTexture), CapturedRect);
        FScreenPassRenderTarget Output = Inputs.OverrideOutput;
        if (!Output.IsValid())
        {
            Output = FScreenPassRenderTarget::CreateFromInput(Graph, Source,
                ERenderTargetLoadAction::ENoAction, TEXT("YIXI.FormalDayInsertOutput"));
        }
        // Keep the retained texture immutable even if a later pass modifies its input in place.
        AddDrawTexturePass(Graph, SceneView, Frozen, Output);
        return Output;
    }

    FViewport* const Viewport;
    bool bAcceptViews = true;                    // Only accessed on the game thread.
    TAtomic<bool> bCaptured{false};               // Render graph -> game thread acknowledgement.
    TRefCountPtr<IPooledRenderTarget> HeldTexture;
    FIntRect CapturedRect;
};

FYIXIFormalCutFrameHold::FYIXIFormalCutFrameHold(TSharedRef<FYIXIFormalDayViewExtension> InView)
    : View(MoveTemp(InView)) {}

TSharedPtr<FYIXIFormalCutFrameHold> FYIXIFormalCutFrameHold::Begin(APlayerController* Controller)
{
    ULocalPlayer* Player = IsValid(Controller) ? Controller->GetLocalPlayer() : nullptr;
    UWorld* World = Player ? Controller->GetWorld() : nullptr;
    UGameInstance* Game = World ? World->GetGameInstance() : nullptr;
    UGameViewportClient* Client = Game ? Game->GetGameViewportClient() : nullptr;
    if (!Client || !Client->Viewport || !World->IsGameWorld() || Client != Player->ViewportClient ||
        Game->GetLocalPlayers().Num() != 1 || Game->GetLocalPlayers()[0] != Player)
        return {};
    return MakeShareable(new FYIXIFormalCutFrameHold(
        FSceneViewExtensions::NewExtension<FYIXIFormalDayViewExtension>(World, Client->Viewport)));
}

bool FYIXIFormalCutFrameHold::IsCaptured() const { return View->HasCaptured(); }

FYIXIFormalCutFrameHold::~FYIXIFormalCutFrameHold()
{
    View->EndOnGameThread();
}
