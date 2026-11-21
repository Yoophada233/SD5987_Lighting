# V3 玩具下落镜头连续性

[观看 3.9 秒有声 PIE 短片](Media/YIXI_ToyDrop_Continuity.mp4)

玩具离手时开始一条连续的相机缓动。镜头同时跟随玩具高度、缓慢改变 Yaw 和 Pitch，并逐步移到避开衣摆的地面机位。相机以实际玩具中心保持构图，Roll 为 0。触地事件继续控制玩具的落地状态，相机进度跨过该事件继续运行。

## 相机关键时刻

| V3 标记 | 30 fps 帧 | Sequence 时间 | 相机动作 |
| --- | ---: | ---: | --- |
| `Hand` | 189 | 6.30 s | 进入手部特写，停留 0.5 秒 |
| `Release` | 204 | 6.80 s | 从当前手部机位开始缓动，下落、转向和横移同步开始 |
| `Landed` | 252 | 8.40 s | 玩具触地，镜头转向完成约 67%，沿同一条曲线继续 |
| `Stable` | 282 | 9.40 s | 到达无遮挡的地面机位，开始白天 5 秒定帧 |
| `Cut` | 432 | 14.40 s | 硬切到夜晚后腰玩具 |
| `Pullback` | 492 | 16.40 s | 夜晚 2 秒定帧结束，开始后撤 |

相机对 `Release → Stable` 使用同一条 `SmoothStep` 曲线，对 Yaw 和 Pitch 取连续角差。沿用现有 Sequence 标记和单一相机，代码改动位于 `YIXIV3Cinematic.cpp/.h`。Sandbox 中 `V3_ToyMatch > Floor Camera Offset` 的旧值为 `(-118, 69, 51)` cm，新值为 `(-118, 96, 30)` cm，按角色朝向坐标相对于玩具中心向右移 27 cm、降 21 cm。

## 局部回归

- 离手后 0.30 秒已转向约 1.37°。触地完成总转向的 67%，触地前后各 0.1 秒的平均角速度约为 20.6°/s 和 19.8°/s。实测 Roll 为 0°。
- 玩具下落实测 1.61 秒，世界 XY 和旋转变化均为零。下落途中衣摆仍短暂遮到玩具一侧，稳定特写中玩具完整可见。
- 白天从 `Stable` 起实测 5.02 秒，夜晚 2.03 秒。一次 Match Cut 后，同一玩具挂到后腰，操作正常交还。切后约 2 秒的独立 Wet Return 信号约为 −48.2 dBFS。

UE 5.8.4 Win64 Development Editor 构建通过，Sandbox 机位保存后读回，Sequence 资产 SHA-256 与任务前一致。[实拍时间采样](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_FallContinuity/PIE_normal_1795273000057504000/Timeline.json) · [构建日志](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_FallContinuity/UBT_FallContinuity.txt) · [恢复清单](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_FallContinuity/Before/Manifest.json)
