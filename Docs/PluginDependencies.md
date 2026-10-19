# 插件与源码依赖

检查日期：2026-10-19；UE 5.8.3。依据实际 .uproject、项目/引擎 .uplugin、YIXIT00.Build.cs、GASP 角色/动画资产模块引用和既有启动日志。未修改或重新加载 Editor。

## 项目直接声明

| 插件 | 来源 | 已声明启用 | 既有启动日志挂载 | 组员额外安装 | 组员源码编译 | 共享许可 |
|---|---|---|---|---|---|---|
| ModelingToolsEditorMode | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| ModelContextProtocol | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| MCPClientToolset | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| EditorToolset | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| MotionTrajectory | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| PoseSearch | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| MotionWarping | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| AnimationWarping | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| Chooser | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| AnimationLocomotionLibrary | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| Mover | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| DrawDebugLibrary | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| LiveLinkControlRig | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| GameplayInteractions | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| GameplayBehaviorSmartObjects | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| SmartObjects | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| CurveExpression | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| AIModuleToolset | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| MovieSceneAnimMixer | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| YIXIT00 | 项目源码 | 是 | 是 | 源码随仓库 | 首次干净环境需要验证编译 | 项目自研，权属由维护者确认 |
| GameplayCameras | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| EnhancedInput | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| ControlRig | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |
| PhysicsControl | UE 5.8.3 内置 | 是 | 是 | 同版引擎须包含此插件 | 不编译引擎自带插件 | UE 许可；不复制引擎安装文件 |

本轮仅补充 GameplayCameras、EnhancedInput、ControlRig、PhysicsControl 四个明确的直接资产依赖；保留全部原有插件声明。其余必要依赖由插件描述文件递归启用，不要求每个组员在管理器逐一操作。

## 描述文件递归依赖

以下列表不等于本项目自研插件，也不代表需要另行安装 Fab 内容：

AnimationModifierLibrary, BlendStack, BlueprintMaterialTextureNodes, ChaosVD, ContentBrowserAssetDataSource, ContentBrowserFileDataSource, ContextualAnimation, DataRegistry, DataValidation, EditorDataStorage, EditorDataStorageFeatures, EditorScriptingUtilities, EngineAssetDefinitions, FileSandbox, FullBodyIK, GameplayAbilities, GameplayBehaviors, GameplayInsights, GameplayStateTree, GameplayTagsEditor, GeometryCache, GeometryFlow, GeometryProcessing, HierarchyTable, HierarchyTableAnimation, IKRig, Landmass, LevelSequenceEditor, MeshLODToolset, MeshModelingToolset, MeshModelingToolsetExp, NavCorridor, NetworkPrediction, Niagara, PlanarCut, PropertyAccessEditor, PropertyBindingUtils, ProxyLODPlugin, PythonScriptPlugin, RigVM, Scribble, SequencerAnimTools, SequencerScripting, StateTree, StylusInput, TargetingSystem, TemplateSequence, ToolPresets, ToolsetRegistry, TweeningUtils, UAF, UAFAnimGraph, UAFMirroring, Water, Workspace, WorldConditions.

描述文件解析失败数：0；未找到的非可选依赖：无。

## YIXIT00

- 保留 YIXIT00.uplugin、Source 下 Build.cs、5 个 .cpp 和 3 个 .h；CanContainContent=false，不需要另造 Content。
- Build.cs 模块依赖为 Core、CoreUObject、Engine、RenderCore、InputCore、Mover、GameplayCameras、RHI、Json、Slate、SlateCore。
- .uplugin 声明依赖 Mover 与 GameplayCameras；VersionName=0.1-T00，EngineVersion=5.8.0，实际本机环境为 5.8.3。
- 现有 Binaries、Intermediate 是本机生成文件，将忽略。插件不是只有二进制的交付；干净克隆仍需要编译可用性验证。
- 根目录没有 Source/Target，插件标记 Installed=true；本轮未测试首次生成目标或编译，不保证 UE 自动 Rebuild 路径成功，不擅自增加主模块或修改插件逻辑。

## 许可与安装边界

未发现被项目直接或递归依赖的 Marketplace/仅二进制插件；这不等于所有 Content 来源和许可已确认。GASP 及其他导入资源需按获取时适用许可和团队关系核对；保持 Private，不单独再分发。个人额外安装的编辑工具不因存在于本机而自动成为团队必须依赖。

官方依据：[GASP](https://dev.epicgames.com/documentation/en-us/unreal-engine/game-animation-sample-project-in-unreal-engine)、[Fab 许可](https://www.fab.com/eula)、[Epic 内容许可](https://www.unrealengine.com/eula/content)。
