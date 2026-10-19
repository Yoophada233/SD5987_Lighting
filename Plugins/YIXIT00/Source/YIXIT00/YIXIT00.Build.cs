using UnrealBuildTool;
public class YIXIT00 : ModuleRules
{
    public YIXIT00(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "RenderCore" });
        PrivateDependencyModuleNames.AddRange(new[] { "InputCore", "Mover", "GameplayCameras", "RHI", "Json", "Slate", "SlateCore", "LevelSequence", "MovieScene" });
    }
}
