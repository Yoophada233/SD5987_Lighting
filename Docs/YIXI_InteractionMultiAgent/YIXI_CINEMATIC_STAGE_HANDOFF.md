# YIXI 固定演出站位与摄影机

打开 `/Game/YIXI_InteractionKit/Examples/L_YIXI_InteractionSandbox`。退出 PIE 后，在 World Outliner 搜索 `V3_ToyMatch`，在 Details 的组件树选择要调整的组件，在视口移动或旋转。该实例的 `Use Fixed Stage` 已启用。

| 组件 | 用途 | 当前世界位置（cm） |
| --- | --- | --- |
| `StageRoot` | 带动下方五个演出组件 | (1952.7, −1054.7, 0) |
| `PlayerStandMarker` | 角色脚底位置，箭头指向角色面向，当前 Yaw 128.33° | (1952.7, −1054.7, 0) |
| `ShoulderCamera` | 直接编辑右肩机位和镜头，当前 Pitch −4°、Yaw 145°、Roll 0°、水平 FOV 64°、f/3.2 | (2005.9, −1171.0, 159.1) |
| `RockFocusMarker` | 设置落石焦平面深度 | (1759.7, −983.6, 66.7) |
| `HandCameraMarker` | 设置镜头下降的终点位置，终点取景对准实拍玩具 | (2005.9, −1171.0, 121.5) |
| `StageTrigger` | 设置发现触发区，Box Extent 为 (86, 80, 110) cm | (1960.7, −1057.7, 88) |

把站位箭头放在地面，给角色到站位的直达路线和摄影机过渡留出空间。剧情进入发现阶段后，玩家进盒即待执行。路径暂不安全时，玩家继续自由操作，留在盒内也会复查。路线可达时才接管移动和转头。Mover 在游戏相机下走到目标，达到位置与朝向容差、停稳且手部镜头及落地轨道可用后，才接入预设摄影机。入盒时的角色朝向和相机方向均可不同。

| `V3 | Stage` 参数 | 当前值 |
| --- | ---: |
| `Max Stage Entry Distance` | 180 cm |
| `Stage Position Tolerance` | 5 cm |
| `Stage Facing Tolerance` | 3° |
| `Stage Move Speed` | 100 cm/s |
| `Stage Move Timeout` | 7 s |

自动走位需要同层地面和短直达路线。已接管后途中受阻、超时或收到取消时，恢复移动与视角，退出触发区再进即可重试。镜头优先直线过渡，必要时走经碰撞检查的抬高过渡点。移动整套锚点后，核对实景落石、地面落点和夜晚布景。

现有 `LS_YIXI_ToyMatch_V3` 继续提供镜头时序和过渡曲线。肩部机位的取景由 `ShoulderCamera` 决定，移动 `RockFocusMarker` 只会改变对焦。角色和玩具仍取自当前 PIE 的剧情实例。此次修改落在 Sandbox、`YIXIV3Cinematic` 和 `YIXIInteractionStoryCoordinator`。任务前副本及 SHA-256 位于 `Saved/YIXI_Archive/InteractionMultiAgent/V3_Stage_Auto/Before/Manifest.json`。

## 自动站位回归

UE 5.8.4 Win64 Development Editor 编译通过。重启后在实际 Sandbox 读回触发区、五项参数及原来的摄影机和站位。下表为持续按键进入同一触发区的 PIE 结果，背面用例先绕到北侧再步行进入。

| 入口 | 接管时角色朝向误差 | 接管时游戏相机偏航差 | 到位用时 | 最终位置／朝向误差 |
| --- | ---: | ---: | ---: | ---: |
| 正面，按住 W | 6.0° | 0° | 1.53 s | 0.80 cm／0.60° |
| 侧面，按住 W | 54.9° | 52° | 1.56 s | 1.01 cm／0.18° |
| 背面，按住 W | 134.2° | 125° | 1.53 s | 1.42 cm／0.55° |
| 镜头朝反向，按住 S | 6.6° | 180° | 1.26 s | 0.90 cm／0.66° |

四组的右肩摄像机都回到预设变换，落石可见。头肩细节随实际停步姿态有少量差别。[四组实际定帧](Media/YIXI_CinematicStage_AutoEntries.png)

- 进场前有障碍时，保留发现待执行状态和玩家控制。在盒内移开障碍后，系统自动接管。
- 行走中插入障碍、手动中断、把超时设为 1 秒，这三项分别恢复了移动和视角，保留手中原玩具，退出再进均可重试。
- 一次调试传送曾使模拟骨骼落后于胶囊，截图中缺少头肩。背面复测采用实际连续步行，查验了真实头像和头肩入画。

受控走位使用 Mover 的世界速度及朝向意图输入。[UE 5.8 Mover 输入参考](https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/Mover/FCharacterDefaultInputs?application_version=5.8)

完整 V3 回归依次测得手部停留 **0.51 秒**、竖直下落 **1.62 秒**、触地重新构图 **1.01 秒**、白天定帧 **5.03 秒**、夜晚定帧 **2.01 秒**。下落的 XY 位移和旋转变化为零。同一 Pawn 与同一玩具完成一次 Match Cut，切后约 2 秒仍录到 Wet Return 信号，交还操作后按 W 移动约 120 cm。长按空格的跳过回归另行通过。

已知限制是近屋檐的某些停步姿势仍可能使玩具轨道失去净空。本轮有一次晚期校验因此安全退回发现阶段。若遇到，可退到盒外换一个入口再走。保留原站位和摄影机摆放。

[最终构建](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_Stage_Auto/UBT_AutoStage_Ready.txt) · [完整演出采样](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_Stage_Auto/PIE_normal_1795271191289861300/Timeline.json) · [主混音试听](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_Stage_Auto/PIE_normal_1795271191289861300/Master.wav) · [跳过采样](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_Stage_Auto/PIE_skip_1795271227008539500/Timeline.json)

交接时，Sandbox PIE 已停在角色持玩具、面朝触发区的正常游戏视角。按住 W 进场。退出 PIE 后可手动调整 `V3_ToyMatch` 的组件和参数。

## 首版固定站位记录

测试脚本把 Pawn 放在触发区外三个不同的起点，再持续按 W 走入触发区。站位校准由运行中的 Mover 完成，期间保持游戏相机。三张定帧均取自 Sequencer 约 3.4 秒。

| 起步视角 Yaw | 对齐用时 | 最终站位误差 | 最终朝向误差 |
| --- | ---: | ---: | ---: |
| 132° | 1.93 s | 1.14 cm | 0.65° |
| 145° | 1.24 s | 0.99 cm | 0.90° |
| 160° | 1.02 s | 3.30 cm | 0.06° |

三次实拍相机均与预设机位一致，头肩保留在左侧，落石主体可辨。手臂、衣摆和头发随角色停步姿态有轻微差异。三次定帧后中断演出，确认操控交还、玩具仍在手上且未发出转场请求。

[三张 PIE 定帧对照](Media/YIXI_CinematicStage_ThreeEntrances.png)

## 首版演出回归

- Win64 Development Editor 编译通过。重新打开 Sandbox 后，六个组件的存盘变换与固定站位开关读回一致。额外实测以 100° 视角走进触发区，未接管相机和输入。
- 完整回归实测右肩定帧 1.01 秒，下移和拉焦 2.31 秒，手部停留 0.51 秒，玩具竖直落下 1.61 秒。玩具下落的 XY 位移和旋转变化为零。随后镜头避开衣摆的滑动约 1.01 秒。
- 白天、夜晚固定特写分别实测 5.03 秒、2.02 秒。一次 Match Cut 使用了同一角色与玩具。硬切时将受控朝向切至夜晚站位，后腰玩具稳定居中且首帧 Roll 为 0°。交还原相机与输入后，实测按 W 继续移动约 119 cm。
- 28.1 秒成片使用同一次 PIE 的实际画面与主混音。切点后约 2 秒，独立 Wet Return 仍有信号。新肩镜前景比例及实际听感留待用户观看。

[播放连续有声 PIE](Media/YIXI_ToyMatch_FixedStage_Sandbox.mp4) · [完整回归采样](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_Stage/PIE_normal_1795267356134179700/Timeline.json) · [最终构建日志](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_Stage/UBT_Stage_NightFacing.txt)

