# 《一夕》日夜转场 V3-R1 修正结果

**InteractionSandbox 已完成正常构建、保存重载及五项 PIE 回归，等待用户观看。** [播放连续有声演出 · 23.81 秒](Media/YIXI_ToyMatch_V3_R1_Sandbox.mp4)。影片约 3.90 秒进入接管，16.78 秒硬切夜晚。可用耳机从 14 秒听至 19 秒。现场使用 UE 5.8.4 CL 58902052 的第三人称角色，游戏时间倍率为 1.0。

## 六项修正与实测

| 用户反馈 | 修改与最终实测 |
|---|---|
| 按住 W 会跑出画面 | 接受发现事件时锁定该玩家的移动与视角，保存 Mover 原输入源，立即制动，并在演出中为模拟提供静止输入。空格由 Controller 独立读取。测试用 W 实走 122.913 cm 进入触发区，接管速度 364.2 cm/s。整段制动位移 0.222 cm，稳定后采样位移 0。持续按 W 并叠加侧移和转视角输入，镜头仍完成。交还后 W 实走 125.285 cm。 |
| 越肩进入太快、到位即切 | 从实际游玩相机用缓入缓出进入越肩，停留后再平滑接到手部。在首次实拍发现画面只有石头后，改以已停住的 Pawn 和现场女孩白盒标记构图，并检查岩石和墙体遮挡。最终录像中角色在前景，倒下标记在岩石旁。 |
| 玩具斜飞、旋转、下落太快 | 手部特写停稳 1.5 秒再离手。离手时保存世界姿态，由一条 Sequence 曲线单独驱动 Z，按实际网格朝向、尺寸和地面算支撑高度。26 个带时标的样本中，X/Y 最大偏移 0 cm、旋转变化 0°、向上回弹 0 cm。Z 从 79.872 降到 16.065 cm，实测 1.623 秒。 |
| 跟拍突停、前后节奏失衡 | 镜头随玩具同步竖直平移，预检下降沿途视线。下落时镜头横移、转角均为 0。到地与锁定构图同帧，保持期间镜头位移 0 cm。正常播放在 5.03494 秒发出唯一 Match Cut，5.0 秒门限后的差值来自游戏帧调度。 |
| 切前听觉变化弱、切后像静音 | 最后 2 秒降低直接声高频，同时推入独立混响和耳鸣。硬切时停止三路白天直接声，独立混响和耳鸣过渡延续 1.5 秒。为了让余音有空间，夜声从切后 1.4 秒开始，淡入 1.25 秒。实录结果见下表。 |
| 夜景横画面再转正 | 夜景由角色身后、世界竖直方向建立首个后腰构图。首帧与夜景采样 Roll 均为 0°。白天落地及夜晚特写的玩具中心都投影在画面 (0.50, 0.50)，FOV 均为 34°。后撤后进入原角色相机的混合，最后交还控制的相邻样本位置、角度和 FOV 差均为 0。 |

轨迹记录含世界位置、四元数、相机、角色、事件身份和游戏时间。采样目标为 20 Hz，实际以记录时间戳为准。测试用定位缩短门、女孩和玩具之间的前置步行；发现区入口通过持续按 W 真实跨入。[正常轨迹与事件原始记录](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/PIE_normal_1795249032730351800/Timeline.json)

## 在编辑器里调节

打开 `/Game/YIXI/Interaction/CinematicV3/LS_YIXI_ToyMatch_V3`。以下均为 30 fps 下的显示帧。

| 时段 | 帧 | 默认时长 |
|---|---|---:|
| 进入越肩、构图停留 | 0–75、75–111 | 2.5 秒、1.2 秒 |
| 越肩过渡到手部、手中停留 | 111–144、144–189 | 1.1 秒、1.5 秒 |
| 竖直下落、地面固定特写 | 189–237、237–387 | 1.6 秒、5.0 秒 |
| 夜晚后腰近景、后撤、交还相机 | 387–417、417–522、522–552 | 1.0 秒、3.5 秒、1.0 秒 |

时长在 Sequence 的命名标记调整，同步移动相应曲线键。保留 `Stable` 到 `Cut` 的 150 帧。用 `CameraTravel` 调整过渡，用 `DropProgress` 调下落缓动，用 `CloseupDistance` 和 `ToyFOV` 调特写。沙盒内选 `V3_ToyMatch` 可调越肩偏移、夜景方向和后撤位置。声音开始时间在 `EchoLeadSeconds`，其 Audio 组件提供 `HearingCurve`、低通、直接声电平、混响发送、耳鸣、尾长及夜声延时。[保存重载后的参数](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/ReloadR1.json)

## 实际声音与画面

影片由同一次编辑器窗口连续采集与 UE 最终立体声输出对齐而成。导出后重新解码 AAC，与 PIE 主混音的波形相关系数为 **0.9994**，成片峰值 **−10.75 dBFS**。切点前 2.35 秒至前 0.25 秒，直接声高低频能量比由 −8.12 降为 −16.03 dB；同期主混音 1732 Hz 耳鸣频点由 −66.29 上升至 −39.63 dBFS。

| 相对硬切 | 白天直接声 | 独立混响 | 夜环境 | 成片 |
|---|---:|---:|---:|---:|
| +0.45 秒 | 静音 | −42.52 | 静音 | −41.79 |
| +0.85 秒 | 静音 | −48.77 | 静音 | −46.31 |
| +1.05 秒 | 静音 | −53.82 | 静音 | −49.96 |
| +1.25 秒 | 静音 | −57.46 | 静音 | −61.77 |
| +1.80 秒 | 静音 | −67.79 | −45.20 | −45.35 |

表中是 160 ms 窗口的立体声 RMS，单位 dBFS。接近尾段时电平已很低，实际可辨时长随播放设备与音量而变。此次已复看成片画面，并检查分轨和导出音频；当前工具无法提供人耳听感判断。[原音量切点前后三秒试听](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/R1_Final_Listen.wav) · [分轨与成片测量](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/PIE_normal_1795249032730351800/MeasuredDeliveryAudio.json) · [成片抽帧](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/VerifiedFilmReview.png)

## 恢复与交接

| 同一最终构建的 PIE 用例 | 结果 |
|---|---|
| 正常播放 | 一次请求、一次成功回执，同一玩具挂到后腰，恢复原 Pawn、相机及移动。 |
| [长按空格](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/PIE_skip_1795249098024961700/Timeline.json) | 仍可跳过并进入夜景，后腰玩具和输入正确，唯一请求。 |
| [落地后中断](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/PIE_interrupt_1795249070826848900/Timeline.json) | 同一玩具回到手中，恢复游玩相机及白天声音。停在触发区内未重播，先离开再重入可完成，一次请求。 |
| [夜景未就绪](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/PIE_notready_1795249116152421100/Timeline.json) / [后腰挂接失效](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/PIE_badwaist_1795249130883440500/Timeline.json) | 两例均无 Match Cut 请求，保留同一手中玩具和玩家控制。回退后白天三路各一份，耳鸣、夜环境均停止。 |

首轮中断测试暴露末帧极小位移可能被误判为受阻。最终实现按实际到位姿态校验，同时检查剩余路径、终点占位和承托面；同一入口复测通过。[最终 UBT 构建](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/UBT_R1_Final.txt) · [最终编辑器及 PIE 日志](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/Editor_R1_Verified.log)

实际修改集中在插件模块 `YIXIT00` 的 `YIXIV3Cinematic`、`YIXIV3AudioComponent`、`YIXIToyCarryComponent` 头文件与实现，新增私有 `YIXIV3NeutralInput.h`。UE 资产是上述 Sequence、`L_YIXI_InteractionSandbox`、混响预设 `FX_V3_WetReverb`，以及新建的 `SM_R1_Ringing`、`R1_RingingPreview`。沙盒定点保存了演出实例的调音设置及原女孩倒地占位的位置和外形。沿用现有蓝图、StoryCoordinator、角色和转场接口。

已按用户选择使用上次磁盘地图为基线。改前的[磁盘地图及资产、源码备份](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/Before/)与[原未保存内存地图](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R1_1795247048485/BeforeLive/L_YIXI_InteractionSandbox.umap)分别保留。编辑器重新打开沙盒后已读取时间轴和音频配置。

**观看入口**为 `/Game/YIXI_InteractionKit/Examples/L_YIXI_InteractionSandbox`。当前第三人称 PIE 已从教室双门前重新开始，按 **E** 进入流程，**WASD＋鼠标**操控，演出中长按**空格**可跳过。女孩倒下后仍用横卧的白盒模型表达，玩具仍是带标记的占位体。白天倾斜的落地姿态与后腰挂姿在硬切处仍有轮廓角差。镜头节奏、耳鸣舒适度及余音强弱留给用户观看判断；正式 Day/Night 和 T01 尚未接入。
