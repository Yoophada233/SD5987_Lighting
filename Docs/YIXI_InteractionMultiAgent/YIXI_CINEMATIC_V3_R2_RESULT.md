# 《一夕》日夜转场 V3-R2 · 沙盒实测

[播放连续有声 PIE 录像](Media/YIXI_ToyMatch_V3_R2_Sandbox.mp4) · [查看关键画面](Media/YIXI_ToyMatch_V3_R2_Focus.png)

## 在 Sequencer 中调整

打开 `/Game/YIXI/Interaction/CinematicV3/LS_YIXI_ToyMatch_V3`。下表采用 30 fps 显示帧，时间从接管游戏相机起算。

| 画面 | 帧 | 设计时长 |
|---|---:|---:|
| 从游戏相机推到右后肩 | 0–75 | 2.5 秒 |
| 固定右后肩，焦点在落石残骸 | 75–105 | 1.0 秒 |
| 沿身体右侧下移，同时把焦点移向右手 | 105–174 | 2.3 秒 |
| 右手持物固定特写 | 174–189 | 0.5 秒 |
| 玩具竖直下降，相机随行 | 189–237 | 1.6 秒 |
| 地面特写，最后约 2 秒引入失真 | 237–327 | 3.0 秒 |
| 第 327 帧硬切，后腰固定特写 | 327–387 | 2.0 秒 |
| 缓慢后撤，再交回原角色相机 | 387–492、492–522 | 3.5 秒＋1.0 秒 |

`CameraTravel` 和 `FocusTravel` 分别控制位移与转焦缓动。越肩的前后、左右、高度由 `ShoulderBackDistance`、`ShoulderRightDistance`、`ShoulderHeight` 调节。近景可调 `ToyFOV`、`CloseupDistance`、`LensAperture`。本次用右侧 62 cm、后方 112 cm、上方 70 cm，近景 FOV 34°、光圈 f/1.4。改段长时一并移动对应标记和曲线端点。`Stable`、`Cut`、`Pullback` 分别控制地面停稳、转场请求和夜晚开始后撤；声音提前量在沙盒 `V3_ToyMatch` 上调节。

## 画面、时间与声音

- **右肩与转焦。** 最终录像约 7.3 秒可辨认残骸石纹和近处人物的虚焦轮廓。角色前景与岩石短暂相叠，继续下移后，右手护腕、手指和玩具边缘变清楚，女孩遇难模型在此段隐藏。右肩停稳采得 1.02 秒，下移与转焦同时进行 2.32 秒，沿用同一台相机。转移中段相机高度从 155.5 降到 120.8 cm，同时焦面距离从 242.7 拉到 105.1 cm。此前用相同姿态分别拍摄远焦与近焦对照，近焦时远处石纹高频细节降至远焦的 42%；手部机位上，实际选用焦面使玩具边缘细节达到强制远焦的 2.05 倍。该对照取自白天镜头，最后一次修正仅处理夜晚挂点。[实拍清晰度对照](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R2_1795251322343/AuthoredFocusCrops.png)
- **角色与掉落。** 持续按 W 实走 129.5 cm 进入发现区，接管后制动位移 0.19 cm，稳定后位移为零。右手持物实测 0.501 秒。31 个带时间戳的掉落样本覆盖 1.620 秒，玩具世界 XY 偏移和旋转变化均为零，跟随相机的横移和转角也为零。落地与构图稳定同帧。[正常播放、角色与玩具轨迹](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R2_1795251322343/PIE_normal_1795252970707384400/Timeline.json)
- **停留与硬切。** 正常播放从稳定到切镜请求 **3.053 秒**，从夜切到开始后撤 **2.015 秒**。两段相机均保持固定，夜景首帧 Roll 为 0°。实拍首版暴露出后腰骨骼会在相机静止时带玩具上移。最终仅在后腰特写期间补偿挂点位移，后撤时平滑交还。30 个采样点的玩具投影均为 (0.50, 0.50)，玩法恢复后仍在同一角色的 `pelvis`，原相对位置、旋转、缩放全部恢复。独立解码最终视频切后 0.13、0.41、1.71 秒三帧，玩具可见面中心最大位移 **0.20 像素**。[夜晚三帧并排](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R2_1795251322343/Final/NightHoldTriptych.png)
- **最终声音。** 成片约 **14.98 秒**硬切。切前人群声的高频相对低频再降 8.3 dB，成片中能测到 1732 Hz 耳鸣增强。切后直接声停止，独立混响从 +0.12 秒的 −34.2 dBFS 衰减至 +1.45 秒的 −60.7 dBFS；夜景声在约 +1.57 秒开始出现。成片音轨与同次 UE 主混音的近切段相关系数为 0.997。可从影片 12 秒开始连听，判断余声的感知长度及耳鸣舒适度。[解码后的成片与各声部实测](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R2_1795251322343/PIE_normal_1795252970707384400/MeasuredDeliveryAudio.json)
- **恢复。** 正常结束后原角色相机接手，验证 W 再走 130.6 cm。长按空格跳过时仅发出一次转场请求；中断后恢复、再次进入可正常完成一次；夜景未准备好时请求为零，玩具回到手中并恢复角色操作。三个异常用例均检查了声音及相机的恢复。[跳过](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R2_1795251322343/PIE_skip_1795253041626525400/Timeline.json) · [中断与重入](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R2_1795251322343/PIE_interrupt_1795253008208726500/Timeline.json) · [夜景未就绪](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R2_1795251322343/PIE_notready_1795253062146753400/Timeline.json)

## 复看与修改范围

在 `/Game/YIXI_InteractionKit/Examples/L_YIXI_InteractionSandbox` 启动第三人称 PIE。教室双门前按 **E** 开始，使用 **WASD＋鼠标**行走和观察，演出中长按**空格**跳过。正式关卡的残骸造型与环境仍需在后续接入时校构图。本轮请重点观看右肩是否留足辨认时间、转焦中段是否过软，以及硬切两侧玩具轮廓角差与余音强度。

修改了 `LS_YIXI_ToyMatch_V3`、`YIXIV3Cinematic.h/.cpp` 与 `YIXIT00.Build.cs` 的电影摄影机模块依赖。用原沙盒实例驱动，磁盘地图与改前 SHA-256 相同。保留原玩具、音频、交互及正式日夜资产。[改前备份](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R2_1795251322343/Before/) · [正常 Editor 构建记录](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R2_1795251322343/UBT_R2_Waist.txt)
