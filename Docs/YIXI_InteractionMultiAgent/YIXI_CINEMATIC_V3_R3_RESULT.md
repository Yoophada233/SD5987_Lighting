# 《一夕》日夜转场 V3-R3 · 越肩构图与停留实测

[播放连续有声 PIE 录像（约 24.6 秒）](Media/YIXI_ToyMatch_V3_R3_Sandbox.mp4) · [查看同次录像抽帧](Media/YIXI_ToyMatch_V3_R3_Framing.png)。影片约 **6.4 秒**处于右后肩定镜，**8.1 秒**正在下移转焦，**16.52 秒**硬切夜晚。

## 越肩与手部构图

R2 会围绕角色选择越肩位置，再从玩具附近单独寻找手部机位。R3 在接管输入并制动后，从可见角色骨架的右上臂根部确定一个机位。最终 Sequence 的偏移为向后 **14 cm**、向右 **49 cm**、向上 **25 cm**，越肩 FOV 为 **56°**。成片左上保留半头、左侧保留右肩甲，石纹在人物前方清晰可辨，女孩遇难占位保持隐藏。换一条入口路线，又在同一停帧上分别临时隐藏残骸和头部，核对了两者各自在画面中的位置。[同机位可见性对照](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R3_1795253881783/PIE_coverage_1795255732452384000/Visible.png)

**实测轨迹已消除绕行。** 从实际游戏相机到越肩机位，60 次采样相对直线的最大偏离为 **0.001 cm**，全程沿同一方向推进。越肩机位距右肩骨 **56.8 cm**，距残骸中心 **2.84 m**。机位收拢时仍单向转向残骸约 49°。随后共用同一台相机及同一组世界 X、Y，沿身体右侧下降 **74.3 cm**，横移为 **0 cm**。下移与转焦实测 **2.303 秒**，中段焦面距离随相机下降由 161 cm 收至 46 cm。武器柄短暂叠在残骸下部，最终手与玩具清楚入画。转向的主观感受、前景留量和焦点节奏留给用户判断。[逐段轨迹与构图数据](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R3_1795253881783/PIE_normal_1795255673265481400/ShotMetrics.json)

## Sequence 时间轴

以下为从接管游戏相机起算的 30 fps 显示帧。白天与夜晚的固定特写分别计时。

| 画面 | 显示帧 | 设定时长 |
|---|---:|---:|
| 游戏相机收拢至右肩，含开头刹停取姿约 0.75 秒 | 0–90 | 3.0 秒 |
| 越肩看残骸 | 90–120 | 1.0 秒 |
| 沿右侧下移，同时拉焦至手中玩具 | 120–189 | 2.3 秒 |
| 右手持物停留、竖直掉落 | 189–204、204–252 | 0.5 秒、1.6 秒 |
| 落地构图固定，至硬切 | 252–402 | **5.0 秒** |
| 夜晚后腰保持固定 | 402–462 | **2.0 秒** |
| 后撤、交回第三人称相机 | 462–567、567–597 | 3.5 秒、1.0 秒 |

## 同次 PIE 验证

- 持续按 W 实走 130.4 cm 进入发现区。接管后制动约 14.8 cm，机位取姿前角色已停稳。越肩固定实测 **1.004 秒**，手部停留 **0.516 秒**。玩具下落 **1.605 秒**，31 个样本的世界 XY 和旋转变化均为零。落地与镜头稳定同帧，白天固定 **5.019 秒**后发出唯一请求。夜晚首帧 Roll 为 0°，后腰固定 **2.065 秒**后才后撤。交回控制后 W 实走 129.9 cm。[正常播放记录](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R3_1795253881783/PIE_normal_1795255673265481400/Timeline.json)
- 失真沿用最后 2 秒的包络。切后白天直接声停止，独立混响在切后 0.12 秒仍为 −35.2 dBFS，0.85 秒降至 −48.3 dBFS。夜景声约在切后 1.42 秒进入。成片音轨与同次 UE 主混音的近切段相关系数为 0.9991。[混音实测](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R3_1795253881783/PIE_normal_1795255673265481400/MeasuredDeliveryAudio.json)
- 长按空格跳过只请求一次；中断后恢复并可重入；夜景未就绪时请求为零、玩具回手、操作恢复。三项均在最终配置下另开 PIE 验证。[跳过](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R3_1795253881783/PIE_skip_1795255756321029100/Timeline.json) · [中断](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R3_1795253881783/PIE_interrupt_1795255777486047500/Timeline.json) · [夜景未就绪](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R3_1795253881783/PIE_notready_1795255807754934700/Timeline.json)

修改了 `LS_YIXI_ToyMatch_V3` 和 `YIXIV3Cinematic.h/.cpp`，已通过正常 Editor 构建及 Sequence 保存重载。沙盒磁盘地图与改前哈希一致，继续由原 `V3_ToyMatch` 实例驱动。本轮验证范围为白盒沙盒。打开 `/Game/YIXI_InteractionKit/Examples/L_YIXI_InteractionSandbox`，在教室双门前按 **E** 可从头体验。[改前备份](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R3_1795253881783/Before/) · [构建记录](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R3_1795253881783/UBT_R3_Framing.txt)
