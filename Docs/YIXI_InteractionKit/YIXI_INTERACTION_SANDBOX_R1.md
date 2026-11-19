# 《一夕》交互测试场 R1

## 打开测试场

在内容浏览器打开 `/Game/YIXI_InteractionKit/Examples/L_YIXI_InteractionSandbox`，使用 **Play**。角色沿用工程现有的 Ragdoll/Mover Pawn 和相机。用 **WASD** 移动，鼠标转视角。朝门 A 靠近，看到小点变成圆环和 **E** 后，按 E 开门。开门后再靠近移动后的把手，重新按 E 关门。门 B 位于另一侧。穿过门 A，走入 `SOUND TRIGGER` 前的地面标记区，可触发一次音效事件。

## 配置与复用

| 需要做什么 | 编辑器操作 |
| --- | --- |
| 接入玩家 | 给本地 PlayerController 或其受控 Pawn 添加一个 `YIXI Interactor Component`，将 `HUDWidgetClass` 设为 `WBP_YIXI_InteractionHUD`。现有 Enhanced Input 若已有交互动作，可关闭 `Bind Interaction Key`，从该动作的 `Started` 调用 `Request Interact`。保留一种绑定方式即可。测试 Controller 的 E 映射优先消费原 Sandbox 的 E 演示动作。 |
| 放门 | 拖入 `BP_YIXI_InteractiveDoor`，将 Actor 原点放在门洞中心的地面。`DoorFrameMesh` 和 `DoorLeafMesh` 可独立替换。通过 `HingePivotOffset` 定门轴，`LeafCenterOffset` 定门扇相对门轴的位置，`HandleMarkerOffset` 定把手相对门扇挂点的位置。换模型后核对门扇轴心与碰撞。 |
| 调门 | `ClosedRotation` 是门轴的本地关闭旋转。`OpenAngleDegrees` 在其基础上绕本地 Z 转动，支持正负值。默认开门 2.5 秒、关门 2.0 秒，可指定各自缓动曲线。`Allow Mid Motion Reverse` 默认关闭。开门和关门各有独立音频、启用和音量字段，可共用衰减资产。剧情可绑定 `OnDoorOpenStarted`、`OnDoorOpened`、`OnDoorCloseStarted`、`OnDoorClosed`。 |
| 调提示 | 在门实例设置 `DetectionRange`、`InteractRange` 和 `PromptAnchorOffset`，默认 300 cm／150 cm。组件的 `DistanceHysteresisCm` 控制距离迟滞。在 `WBP_YIXI_InteractionHUD` 的类默认值调整 `DotSize`、`RingSize`、`RingThickness`、`PromptColor`、`PromptOpacity`、`ScreenOffset` 和 `UITransitionDuration`。默认过渡 0.15 秒，定位会应用玩家视口的 DPI 缩放。 |
| 放音效 Box | 拖入 `BP_YIXI_AudioTriggerBox`，选中 `BoxCollision`，通过 Details 的 `Box Extent` 调整半尺寸。可直接平移或旋转 Actor。人群惊慌、马匹、远钟各有声音、延迟和音量，`AdditionalSounds` 可追加。启用空间声音时，调整 `AudioLocation` 和衰减。`Trigger Once` 默认开启，可在 `OnTriggered` 接剧情。 |
| 扩展物体 | 在新的 Actor 蓝图上实现 `YIXI Interactable` 接口，定义交互条件、执行逻辑和世界空间提示锚点，测试图的玩家组件会使用相同的识别和提示逻辑。 |

## 交付资产

- `/Game/YIXI_InteractionKit/Blueprints/BP_YIXI_InteractiveDoor`
- `/Game/YIXI_InteractionKit/Blueprints/BP_YIXI_AudioTriggerBox`
- `/Game/YIXI_InteractionKit/Blueprints/BP_YIXI_InteractionController`、`BP_YIXI_InteractionGameMode`
- `/Game/YIXI_InteractionKit/UI/WBP_YIXI_InteractionHUD`
- `/Game/YIXI_InteractionKit/Examples/L_YIXI_InteractionSandbox`
- `Plugins/YIXIT00/Source/YIXIT00/Public/YIXI_Interaction` 与 `Private/YIXI_Interaction` 包含接口、组件、HUD、门和音效 Box 的源码。

## 实测结果

- UE 5.8.4 CL58902052 使用 UBT 和 VS2022 构建 Win64 Development Editor，退出码 0。构建使用同引擎的隔离宿主编译 `YIXIT00`，复制后核对 DLL 和 PDB 哈希，随后由《一夕》实际加载。
- `UltimateLevelArtTool` 工程副本原缺六个 Win64 模块。已从本机匹配的引擎副本补齐模块和清单。编辑器按原工程配置启动，成功加载六个模块，无需临时停用参数。随后复验第三人称 PIE、交互 HUD 和 E 键开门。
- 定点保存后正常退出并重开编辑器，从磁盘直接加载测试地图，确认专用 GameMode、原有角色和 UMG 正常。Map Check 为 0 错误、0 警告。多次重新进入 PIE 后，两扇门均恢复关闭，Box 的计数恢复为 0。
- 两扇门分别由 Enhanced Input 的 E 键路径完成开关。门 A 左轴、`+90°`、2.5／2.0 秒，门 B 右轴、`−110°`、1.6／1.4 秒。门 A 开启期间连按 E 未重复启动，长按 E 后门 B 在交互范围内保持开启。中途反向在 PIE 中单独启用后实测连续反转。关门时角色占据门扇路径，门暂停在部分开启位置，角色退开后关完。
- 在实际 PIE 画面观察到小点和圆环 E，门扇转动时提示随把手换位。走远、转移视线和隔墙时隐藏。进入两门的检测范围时只显示一个提示。
- Box 测试半尺寸为 `120 × 100 × 120 cm`。真实角色进入时计数从 0 到 1，离开后再进仍为 1。门的开／关声音开关分别用 UE 1 kHz 测试音和录音验证，关闭相应开关时只捕获到用于对照的 500 Hz 输入。Box 另以临时测试音验证了带延迟的播放。正式开关门、人群、马匹和远钟资源槽均留空，等待替换。

构建日志、验证录音和旧模块备份位于 `Saved/YIXI/InteractionSandbox_R1/20261119_120404`。只保存了交互套件的六个资产包。正式关卡和现有角色资产未被改动。
