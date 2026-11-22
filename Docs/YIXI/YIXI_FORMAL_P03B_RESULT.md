# 《一夕》正式 P03-B · D07 发现与白天预演

## 正式部署

入口为 `/Game/YIXI/Tests/P04/Maps/L_YIXI_P04_StreamingMaster`，UE 5.8.4 CL58902052。新增的 `YIXI_P03B_D07_CinematicStage` 属于 `/Game/YIXI/Tests/P04/Day/L_YIXI_T00_Day`。D07 标记实读为 `(-1169.563, 1033.913, 90)`，Yaw 120°。对应静态碰撞地面 `BlockingVolume_5` 顶面为 Z=29 cm，以此作为站位脚底，既有 Mover 使用实际 Pawn 胶囊与地面检测对齐。

| 编辑器组件 | 世界位置 cm | 设置 |
| --- | --- | --- |
| `StageRoot` / `PlayerStandMarker` | (−1169.56, 1033.91, 29.00) | 朝向 120° |
| `StageTrigger` | (−1175.00, 1090.00, 115.00) | 半尺寸 76 × 60 × 110 cm，Yaw 120° |
| `ShoulderCamera` | (−1148.63, 901.66, 188.00) | Pitch −7.8°，Yaw 113.5°，Roll 0°，FOV 60°，f/3.2 |
| `RockFocusMarker` | (−1389.39, 1396.69, 104.00) | 对准 D06 实际落地残骸 |
| `HandCameraMarker` | (−1148.63, 901.66, 151.00) | 与右肩机位同 XY |

这个实例直接绑定 Day 的 `BP_YIXI_StoryToyPickup_C_0`、`YIXI_P03A_D06_AttackRock`、`BP_YIXI_StoryGirl_C_0`。正式 Day Level Blueprint 继续独立管理请求、拾取解锁、两次投石和女孩状态。V3 只观察原玩具的拾取，在当前本地受控 Pawn、同一原玩具 `HeldHand`、第二颗投石请求 2 已落地且女孩 `Unavailable` 时等待入区并尝试已有固定站位。条件和重叠定期重查。成功后消耗本次预演，失败或中断后可退到 Box 外再次进入。

初次实走到位后触发了已有安全恢复。检测显示 `BlockingVolume_5` 和 `BlockingVolume_6` 的 Camera 阻挡面在 Z=29 cm，玩具正下方的可见碰撞网格约为 Z=−36 cm。正式实例通过 `Toy Camera Floor Volumes` 引用这两个同层隐形体积，仅在手部与落地特写的摄影机扫掠和视线检测中排除。普通玩家相机、肩镜接管路线、世界碰撞、玩具落地检测及衣摆避让仍沿用原流程。

## 预演和编辑入口

沿用 `LS_YIXI_ToyMatch_V3` 的现有时间标记和缓动。白天预演在 `Cut` 前走既有恢复路径，交还第三人称相机、输入、音频状态和手中的原玩具。正式实例仅挂接独立测试耳鸣资源 `R1_RingingPreview`。正式声景低通过渡、混响跨流送的承载和 Night 声轨留待后续接入。

交付时已从默认教室出生点重新打开第三人称 PIE，可直接游玩。需要编辑时退出 PIE，在 World Outliner 搜索 `YIXI_P03B_D07_CinematicStage`，在视口中移动上述组件。改肩构图用 `ShoulderCamera`，改焦距目标用 `RockFocusMarker`，调整下落后最终机位用 `Floor Camera Offset`。站位要留在与入口同层的碰撞面上，走位上限 180 cm，允许位置误差 5 cm、朝向误差 3°。[UE 5.8 Mover 输入接口](https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/Mover/FCharacterDefaultInputs?application_version=5.8)

## 正式 Master + Day 实走

- **门控**。从默认教室出生，实际走过双开门、第一颗落石后的绕行，向女孩接取请求并拾取后院原玩具。此前两次空手穿过 D07 确认 Box 实际重叠，电影状态保持 `Idle`。持物返程的第二颗投石完成一次，女孩不可交互，随后步行回到 D07。
- **自动站位**。正常重试的 Mover 实测用时约 2.52 秒，站位误差 0.89 cm，朝向误差约 0.59°。走位过程使用游戏相机，到位停稳后接管。预设肩镜中残骸和角色均入画，残骸中心与六个外缘视线均畅通。手部镜头保留右手与玩具，护甲占据画面左侧。最终地面特写的玩具轮廓完整，衣摆退出画面。正式玩具和残骸仍为白盒，落点附近现有水面高光使道具贴地感偏弱，构图与落点的最终美术判断留待用户。
- **时序与下落**。实走使用 `Hand` 6.30 秒、`Release` 6.80 秒、`Landed` 8.40 秒、`Stable` 9.40 秒和 `Cut` 14.40 秒。正常预演的 26 个下落样本中 XY 和旋转变化均为 0，总 Z 行程约 130.15 cm。镜头重新构图完成后白天固定特写实测 **5.011 秒**。
- **中断与重复**。最终部署版在地面特写主动中断后恢复相机、移动、视角和同一原玩具。退出再进入可完整跑完预演。正常结束与主动中断后分别实测按 W 移动约 43 cm、46 cm。两次均检测到预演耳鸣源正在播放，恢复后无活动演出音源。完整结束后再次进入触发区，状态保持 `Idle`，最终测试只有一次 `DAY_PREVIEW_COMPLETE` 和零次 Match Cut。

| 正式 PIE 关键构图 | 截图 |
| --- | --- |
| 预设右后肩与正式残骸 | [Shoulder.png](Media/P03B/Shoulder.png) |
| 右手玩具 | [Hand.png](Media/P03B/Hand.png) |
| 无衣摆遮挡的地面定帧 | [Ground.png](Media/P03B/Ground.png) |

可复核的 [程序采样](../../Saved/YIXI_Archive/FormalP03B_20261122_161601/PIE_Route.jsonl) 和 [引擎日志](../../Saved/YIXI_Archive/FormalP03B_20261122_161601/PIE.FinalEvidence.log) 保留在工程本地。

## 构建与恢复

普通用户环境下的 Win64 Development Editor `YIXIT00` 构建成功。桥接源码只涉及 `YIXIV3Cinematic.h/.cpp`。定点保存后，正式 Master、Night 和共享 Sequence 的磁盘 SHA-256 与部署前一致。本地备份和 [最终构建日志](../../Saved/YIXI_Archive/FormalP03B_20261122_161601/UBT_P03B_Final.txt) 位于 `Saved/YIXI_Archive/FormalP03B_20261122_161601`，其中 `Day.BeforeAfterUserSave.umap` 保存了部署前用户最新保存的 Day。演出相关的两份源码原件在同目录。

正式 Master 启动仍记录 T00 的 `Effective configuration mismatch`，实际使用 `BP_YIXI_StorySandboxGameMode_C` 和 `BP_YIXI_StorySandboxController_C`。下一阶段仍需核对正式 Night 预加载、同一 Pawn 与玩具的跨关卡交接、音频生命周期及实际 Match Cut。P03-B 的验收范围为正式 Day 预演。
