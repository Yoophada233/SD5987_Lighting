using UnrealBuildTool;
public class YIXIT00 : ModuleRules
{
    public YIXIT00(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "RenderCore", "InputCore", "UMG" });
        PrivateDependencyModuleNames.AddRange(new[] { "EnhancedInput", "Mover", "GameplayCameras", "CinematicCamera", "RHI", "Json", "Slate", "SlateCore", "LevelSequence", "MovieScene", "Niagara" });
        if (Target.bBuildEditor) PrivateDependencyModuleNames.Add("Landscape");
    }
}
