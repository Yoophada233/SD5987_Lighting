# 《一夕》V3-R5 · 右肩与落地特写

[播放 25.6 秒连续有声 PIE](Media/YIXI_ToyMatch_V3_R5_Sandbox.mp4) · [构图前后对照与日夜切点](Media/YIXI_ToyMatch_V3_R5_Compositions.png) · [关闭景深的两张实拍](Media/YIXI_ToyMatch_V3_R5_NoDOF.png)

## 右肩定帧

以 Sandbox 中角色朝向的水平轴布置相机，参考实际右上臂高度，并根据头部投影在原相机横轴上做有限平移。Sequence 的肩部轨设置为后移 **124 cm**、右侧偏移 **11 cm**、抬高 **10 cm**、FOV **64°**。结合真实肩宽，正常运行时相机距右肩骨约 **1.27 m**，R4 为 **0.59 m**。推进保持实际游戏相机的 **Yaw 145°、Pitch −4°、Roll 0°**，实测三轴角度变化均为 **0°**。

关闭景深检查时，主要头肩轮廓约占中段画宽 **15%–22%**，靠下的前臂较宽。落石主体在水平中央附近，头肩与落石之间有明显缝隙。连续成片的定帧里，落石的最底缘略被画框裁切。恢复景深后完成连续录制。前后图取自 R4 和 R5 的原生 PIE 记录，本轮消息中没有可读取的两张用户截图。

## 触地后的滑动

相机沿原轨道竖直跟随下落 **1.606 秒**，玩具下落的 XY 和旋转变化均为零。触地后，相机在 **1.002 秒**内滑行 **74.4 cm**，按角色方向分解约为向右 **70.2 cm**、向前 **20.7 cm**、抬高 **13.6 cm**。这一范围给衣摆和靴子留出间隔。焦距随相机距离补偿画面大小，滑动中持续对准固定玩具，两端之间的最大转角约 **30.8°**。玩具在滑动期间平移与旋转均为零。冻结姿态下分别保留及隐藏角色进行检查，最终取景中的衣摆与靴子留在轮廓之外，两个圆形标记可见。[轨迹与构图采样](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R5/PIE_normal_1795263599862169500/ShotMetrics.json)

## 30 fps Sequence 时间轴

| 阶段 | 显示帧 | 设定时长 |
| --- | --- | ---: |
| 游戏相机推进，含接管与制动 | 0–90 | 3.0 秒 |
| 右肩定帧 | 90–120 | 1.0 秒 |
| 下移与拉焦 | 120–189 | 2.3 秒 |
| 手部停留 | 189–204 | 0.5 秒 |
| 世界 Z 轴竖直下落 | 204–252 | 1.6 秒 |
| 触地后滑动重新构图 | 252–282 | 1.0 秒 |
| 白天地面固定特写 | 282–432 | **5.0 秒** |
| 夜晚后腰固定特写 | 432–492 | **2.0 秒** |
| 后撤与交还操控 | 492–627 | 4.5 秒 |

Landed 在第 **252** 帧，Stable 在第 **282** 帧。到达最终机位后计时，白天固定实测 **5.030 秒**，夜晚固定实测 **2.020 秒**。完整运行只有一次 Match Cut 请求，角色与玩具身份相同。切点两端玩具的投影中心均为 **(0.50, 0.50)**，实拍轮廓约占画宽 **45% / 44%**。地面玩具仍有斜角，后腰玩具保持正立，夜景首帧 Roll 为 **0°**。沿用夜景机位和后撤路线。[运行采样](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R5/PIE_normal_1795263599862169500/Timeline.json)

## 音频、保存与验收

白天耳鸣约在切前 **3.96 秒**开始，夜晚尾音在切后约 **2.50 秒**退净，夜景环境声约 **2.27 秒**开始进入。引擎同帧发出硬切与白天直达声停止指令。解码成片中，直达声停止到首个可见夜景画面相差 **36.5 毫秒**，约一个录制帧。成片音轨与同次 PIE 主混音相关系数 **0.9983**。[成片音频实测](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R5/PIE_normal_1795263599862169500/MeasuredDeliveryAudio.json) · [切后余响测量](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R5/PIE_normal_1795263599862169500/CenteredTailAudio.json)

UE **5.8.4 CL58902052** 的 Lighting Win64 Development Editor 构建通过。修改为 YIXIV3Cinematic.h/.cpp、LS_YIXI_ToyMatch_V3，以及 Sandbox 中 V3_ToyMatch 的地面相机偏移。Sequence 可编辑肩镜参数、Landed 和 Stable 等时标。地面终点可在 V3_ToyMatch 的 FloorCameraOffset 调整，当前以玩具中心为基准，在角色方向坐标下为 **(-118, 69, 51) cm**。混响资产哈希与 R4 相同。[存盘值](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R5/AuthoredR5_save.json) · [构建日志](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R5/UBT_Integrated_R5_Final.txt) · [改前备份](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R5/Before/)

正常回放覆盖按住 W 进入、接管期间的侧向与视角输入，以及交还后继续移动。白天耳鸣已启动时中断，游戏相机、输入、日间声源和玩具手持状态均恢复，转场请求为零。落地滑动期间长按空格，正常完成一次转场并恢复控制。[中断回归](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R5/PIE_audiointerrupt_1795264021783468700/Timeline.json) · [跳过回归](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R5/PIE_skip_1795264153720641200/Timeline.json)

最终视觉验收留给用户，重点是肩部留量、落石在画面下方的位置，以及约一秒横滑和日夜玩具轮廓的衔接。实拍覆盖 Sandbox 的本轮路线与停步样本。
