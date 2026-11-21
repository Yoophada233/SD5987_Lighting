# 《一夕》交互系统白盒交接

## 进入并游玩

当前第三人称 PIE 停在关闭的双门前，画面已经显示一个圆环和 **E**。点击游戏视口，使用 **WASD**、鼠标和 **E**。重新打开时，在内容浏览器进入 `/Game/YIXI_InteractionKit/Examples/L_YIXI_InteractionSandbox` 并点 Play。默认出生点仍在原两扇单门区域，从出生点右后方的缺口可以走到新增双门。

开双门后直走进入长廊。主路被落石封住时，从近侧左边缺口下到绕行道，从另一端的缺口回到主路。对女孩的圆柱占位按 E，再去后院捡起方块玩具。沿绕行道原路返回，触发返程袭击、发现和掉落。隔离 Match Cut 回执会把同一玩具挂到后腰。

## 可复用资产

新蓝图位于 `/Game/YIXI/Interaction/Blueprints`。双开门 `BP_YIXI_DoubleDoor` 可独立放置。左右门扇网格、门轴偏移、角度和关闭姿态在 Details 分别设置。开关时长、缓动、声音和中央锚点由整门共享。

`BP_YIXI_StoryGirl`、`BP_YIXI_StoryToyPickup`、`BP_YIXI_ScriptedRock`、`BP_YIXI_StoryTriggerBox` 为可分别放置的组件。布置完整剧情时，给 `BP_YIXI_StoryCoordinator` 设置指定实例引用。路障落石启用封路，返程袭击落石使用可配置的独立起落点和仅演出模式。女孩请求、拾取及转场事件接口见 [公共接口](INTERFACES.md)。

测试 GameMode 和 Controller 留在同一目录。Controller 使用现有 `WBP_YIXI_InteractionHUD` 和一个 Interactor，再附加一个 `YIXIStoryToyCarry`。其他角色可配置自己的手部和后腰插槽、偏移与玩具资源。当前 Ragdoll/Mover 测试角色使用 `palm_r_Socket` 和 `pelvis`，后腰偏移为骨骼局部坐标 `(1,-33,4) cm`。

## 实际验证

| 项目 | 结果 |
| --- | --- |
| 正常构建与保存 | UE 5.8.4 CL58902052，VS2022。从真实工作副本的 `Lightning.uproject` 构建 Win64 Development Editor，52 个动作完成，退出码 0。沿用共享 PCH，直接编译及链接项目插件。源码只在 `YIXIFireflyScatter.cpp`、`YIXIInteractFire.cpp`、`YIXISenseFire.cpp` 各补一条 `Engine/World.h`。用新模块重开后，沙盒与八个蓝图均为已保存状态，10 个剧情引用和测试 GameMode 完整，地图、蓝图和工程文件哈希与构建前一致。 |
| 门、HUD 和旧功能 | E 从正面打开、从背面关闭并重新打开整门。开启后两轴约为 +90°／−90°。分别站在左右门扇路径，整门停在约 0.70／0.71 开度，离开后关合。公共 HUD 读回 `Hidden → Dot → Ready` 并获取原生画面。原单门 A 实际可开启且未联动 B 或双门。原一次性 Box 离开再进后仍为 1 次。 |
| 封路及剧情 | 落石处于 `Blocking`，玩家从 X=1520 cm 持续前进，在 X≈1675 cm 被实体挡住。第二轮由同一 Pawn 使用原生游戏移动输入走完整条绕行路线，实际 E 接受请求和拾取，记录按顺序进入返程、发现、Match Cut 和 `Completed`。第二轮没有在路线中传送。 |
| 玩具 | 原生画面显示同一方块道具手持。掉落后请求 3 成功返回，Carry 进入 `AttachedAtWaist`。体验 Reviewer 独立回读相同运行时 Actor、骨骼网格父组件及角色后方约 32 cm 的实测位置，并检查了原生画面。 |
| 定向边界回归 | 可关闭的开态双门在对照中先抢得 `Ready`。将同一 PIE 实例切为不可关闭后，原单门取代它并正常开始开门。剧情回归在掉落委托内同步重复进入发现回调，随后在转场等待及完成阶段再次调用，只观察到 1 次 Match Cut 请求。同一玩具最终挂到后腰。测试用诊断定位和临时委托仅作用于 PIE 副本。 |

本轮证据见 [真实工程 UBT 日志](../../Saved/YIXI_Archive/InteractionMultiAgent/Closeout_20261121_035125/UBT_Project.txt)、[边界回归日志](../../Saved/YIXI_Archive/InteractionMultiAgent/Closeout_20261121_035125/Editor_Closeout.log)（`YIXI_CLOSEOUT_DOOR_PASS`、`YIXI_CLOSEOUT_STORY_PASS`）和[当前验收画面](../../Saved/YIXI_Archive/InteractionMultiAgent/Closeout_20261121_035125/PIE_Handoff.png)。此前整条白盒路线的 [PIE 顺序记录](../../Saved/YIXI_Archive/InteractionMultiAgent/Build_20261121_022229/PIE_Evidence/PIE_Event_Timeline.txt)、[手持](../../Saved/YIXI_Archive/InteractionMultiAgent/Build_20261121_022229/PIE_Evidence/Toy_In_Hand.png)及[后腰挂接](../../Saved/YIXI_Archive/InteractionMultiAgent/Build_20261121_022229/PIE_Evidence/Toy_At_BackWaist.png)仍可查阅。技术和体验审核记录见 [REVIEWS.md](REVIEWS.md)。

关闭编辑器后，在工程根目录用普通 Windows PowerShell 复现构建。

```powershell
$project = (Resolve-Path -LiteralPath 'Lightning.uproject').Path
& 'D:/UE_5.8/Engine/Build/BatchFiles/Build.bat' UnrealEditor Win64 Development "-Project=$project" -NoHotReload -NoEngineChanges -NoUBA -MaxParallelActions=1
```

## 当前验收边界

白盒用 Match Cut 请求和回执替身。正式转场镜头、最终音效、临时中文对白观感、美术及玩家体验由后续验收决定。沙盒音效资源为占位示例，功能记录主要依据触发次数及阶段证据。

本地分支 `codex/yixi-interaction-integration`，HEAD 为 `f73a4e2`。本轮结束时有 6 个受 Git 跟踪的修改文件和 27 个未跟踪文件，涵盖此前沙盒、蓝图、源码和文档，以及本轮三条头文件修复。暂存区为空。原沙盒地图、初始模块文件和校准前 Controller 的备份可在 `Saved/YIXI_Archive/InteractionMultiAgent/Build_20261121_022229/Before/` 找到。本轮构建前的模块副本和项目资产清单位于 `Saved/YIXI_Archive/InteractionMultiAgent/Closeout_20261121_035125/Before/`。
