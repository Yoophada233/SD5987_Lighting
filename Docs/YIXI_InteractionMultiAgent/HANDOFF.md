# 《一夕》交互系统白盒交接

## 进入并游玩

当前第三人称 PIE 停在关闭的双门前，画面已经显示一个圆环和 **E**。点击游戏视口，使用 **WASD**、鼠标和 **E**。重新打开时，在内容浏览器进入 `/Game/YIXI_InteractionKit/Examples/L_YIXI_InteractionSandbox` 并点 Play。默认出生点仍在原两扇单门区域，从出生点右后方的缺口可以走到新增双门。

开双门后直走进入长廊。主路被落石封住时，从近侧缺口下到绕行道，对女孩按 **E**，再去后院对带标记的玩具按 **E**。沿原路朝女孩的位置返回。先保持自由视角看石头飞过屋檐，再走近女孩原先站的位置。此处接管相机，依次播放越肩、手中玩具、掉落和落地特写。从构图稳定起停留 5 秒，随后硬切到同一道具挂在角色后腰的夜景。镜头拉开后即可继续用 WASD 和鼠标。演出中长按空格约 0.65 秒可跳过停留，仍会看到玩具硬切。

### 调整 V3 白盒演出

- 在沙盒大纲中选中 `V3_ToyMatch`。可移动越肩、备用机位、落点和夜景落脚点。玩具近景距离、FOV 和夜景后撤分别可调。返程投石的飞行声绑定石头，撞击声绑定落点，在该石头实例上替换两个声音及各自的衰减。
- 打开 `/Game/YIXI/Interaction/CinematicV3/LS_YIXI_ToyMatch_V3`。序列按 30 fps 编辑，`V3Host.CameraTravel` 控制镜头运动。保留 Stable 至 Cut 的 150 帧，以及 Cut 至 Pullback 的 30 帧。实际开始计时还会等待道具落稳、构图锁定。最后约 1.5 秒逐步增加混响发送量。
- `V3_ToyMatch → Audio` 提供日间人群、环境、音乐和夜间竹林声槽。白天直达声在硬切时停止，独立湿声总线保留衰减，夜景声默认在切点后 1 秒进入。当前声音、玩具标记和竹林均为白盒素材。

### V3 本次运行证据

[连续有声回放，约 17 秒](Media/YIXI_ToyMatch_V3_Sandbox.mp4) · [成片硬切前一帧](Media/V3_Day_Last.png) · [后一帧](Media/V3_Night_First.png)

| 实测 | 结果 |
| --- | --- |
| 正常演出 | 重新启动编辑器并从磁盘加载沙盒。稳定特写至切换为 5.021 秒游戏时间，在满 5 秒后的首个更新帧请求一次。落地与后腰使用同一道具和同一玩家。成片相邻帧保留了玩具外轮廓和圆形标记。恢复控制后按 W，角色实际走出 130.7 cm。 |
| 声音 | 白天人群、环境、音乐在硬切的同一游戏帧停止。独立录音中直达声停止后湿声仍延续约 1.04 秒。夜声在切后 1.014 秒游戏时间启动，本次录音的可测起音约在切后 1.20 秒。 |
| 跳过和恢复 | 通过原生按键路径长按空格，保留夜景首镜，地面停留缩短至 0.166 秒。演出中断后在发现区内等待不会重播，出区再进入可重试。模拟夜景未就绪和后腰挂点失效时，均未发出切换请求，原玩具留在或恢复到玩家手中。 |
| 自由视角 | 正向返程中取得飞石在屏内、飞石视线畅通且落点被挡的同帧采样。另一轮玩家低头背向飞石，15 个飞行采样均未见无遮挡飞石，剧情仍完成。 |

回放取自游戏视口的连续帧和本次 PIE 的实际总输出。自动测试用定位命令到达前置交互点，再由原门、女孩、拾取和区域事件驱动镜头。地面白盒、女孩消失的叙事可读性、玩具握姿、夜景色调与声音表演仍需玩家观看。原始分轨、时间轴和构建记录分别见[正常运行](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_1795240290820/PIE_normal_1795243117345929900/Timeline.json)与[构建日志](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_1795240290820/UBT_V3_Final.txt)。

## 可复用资产

新蓝图位于 `/Game/YIXI/Interaction/Blueprints`。双开门 `BP_YIXI_DoubleDoor` 可独立放置。左右门扇网格、门轴偏移、角度和关闭姿态在 Details 分别设置。开关时长、缓动、声音和中央锚点由整门共享。

`BP_YIXI_StoryGirl`、`BP_YIXI_StoryToyPickup`、`BP_YIXI_ScriptedRock`、`BP_YIXI_StoryTriggerBox` 为可分别放置的组件。布置完整剧情时，给 `BP_YIXI_StoryCoordinator` 设置指定实例引用。路障落石启用封路，返程袭击落石使用可配置的独立起落点和仅演出模式。女孩请求、拾取及转场事件接口见 [公共接口](INTERFACES.md)。

测试 GameMode 和 Controller 留在同一目录。Controller 使用现有 `WBP_YIXI_InteractionHUD` 和一个 Interactor，再附加一个 `YIXIStoryToyCarry`。其他角色可配置自己的手部和后腰插槽、偏移与玩具资源。当前 Ragdoll/Mover 测试角色使用 `palm_r_Socket` 和 `pelvis`，后腰偏移为骨骼局部坐标 `(1,-33,4) cm`。

## 提示点与女孩语音

- 在蓝图的 **Components** 中选中 `InteractionAnchor`，在视口拖动或修改 **Transform → Location**。女孩和玩具沿用原锚点。单门的新锚点随 `HandleMarker` 转动，双门的新锚点挂在固定的 `CenterInteractionAnchor` 下。两个门的原偏移参数仍可用，`DetectionRange` 和 `InteractRange` 单独设置。
- 音效 Box 选中 `BoxCollision`，剧情 Box 选中 `TriggerBox`，在 **Shape → Box Extent** 调整触发范围。
- 在 `BP_YIXI_StoryGirl` 的 **Class Defaults → Story → Voice** 设置 `RequestVoice`、`ReminderVoice`、`VoiceVolume` 和 `VoiceAttenuation`。选中 `VoiceAnchor` 调整发声位置。请求仍推进一次剧情。配置提醒音后，可在请求完成后再次交互，正在播放的语音会先播完。语音槽可留空。

本次补充的 `YIXIT00` 模块通过 Win64 Development Editor 构建。重开编辑器后查到四个蓝图的锚点都允许在子类中编辑。在沙盒 PIE 临时抬高每个锚点 28 cm，单一提示对应移动，检测距离和交互距离保留。单门提示随门扇移动，双门在开启时仍固定在中央。两个 Box 调整范围后均可读回新值。重新开始 PIE 后，用两段引擎测试音验证请求、提醒、空间发声位置跟随和连按防叠音。切到不可交互状态会停止语音，两个音槽留空时请求仍推进到拾取玩具。正式配音待导入。沙盒地图和蓝图文件与本轮开始时的哈希一致。见[构建日志](../../Saved/YIXI_Archive/InteractionMultiAgent/AnchorVoice_20261121_121917/UBT_YIXIT00.txt)和[沙盒运行日志](../../Saved/YIXI_Archive/InteractionMultiAgent/AnchorVoice_20261121_121917/Editor_AnchorVoice.log)。

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

当前 V3 在同一沙盒内从白天布景切到独立夜景布景，使用同一玩家和玩具。上表的延时回执记录对应较早的交互白盒。正式 T01 流送、正式场景机位和最终音效另行接入，艺术效果由用户验收。

早期交互白盒交接记录的分支是 `codex/yixi-interaction-integration`，当时 HEAD 为 `f73a4e2`。V3 在 `main` 的 `c05ce4c` 工作副本上制作。V3 开始前的沙盒地图和编辑器模块副本保留于 `Saved/YIXI_Archive/InteractionMultiAgent/V3_1795240290820/Before/`。早期白盒备份仍在 `Saved/YIXI_Archive/InteractionMultiAgent/Build_20261121_022229/Before/` 和 `Saved/YIXI_Archive/InteractionMultiAgent/Closeout_20261121_035125/Before/`。
