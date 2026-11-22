# 《一夕》正式 P04 夜晚 Match Cut 摄影机修复

## 定位

用户的 PIE 日志里，Night 就绪、同一玩具后腰挂接、硬切及后续交还均发生。旧路径只检查 Pawn 根节点到达，随后从仍处于白天冻结状态的骨骼取样，直接锁住首次玩具变换两秒。Mover 可以在根节点移交之外更新视觉组件。旧代码缺少对这个机位与实际角色距离的校验，后撤又从 Pawn 根节点另算一个终点。这个缺口能产生用户看到的高处定镜和后续下移。旧日志缺少骨骼、玩具和机位坐标，具体哪一个组件在硬切帧滞后仍缺少运行时证据。

正式 T00 从已经应用流送变换的世界中探测承托面。Master 的 `NightDestination` 为 `(-35006.879418, 219217.624860, -5585.823577) cm`，Yaw `31.871941°`。Night 流送平移为 `(0, 100000, 0) cm`。Pawn 的落脚位置来自世界碰撞查询，玩具及摄影机也使用实际组件的世界坐标，流送偏移只由关卡流送系统应用一次。

## 改动

- `YIXIV3Cinematic.h/.cpp` 的正式 Night 路径在 Pawn 到位后释放白天姿态冻结，等实际后腰骨骼更新。挂接网格和动画驱动网格允许不同，同时检查可见角色网格、骨盆和挂点都在同一 Pawn 附近。
- `YIXIToyCarryComponent.h/.cpp` 添加可撤销的准备挂接。用同一个玩具的实际挂接组件变换计算模型中心。检查角色背侧方向、机位与角色的距离、玩具近裁剪余量及场景视线后，才允许原 RequestId 提交硬切。切前失败恢复玩具和 Day 控制。切后发现活动画面异常时，交回 Night 的正常游戏相机。
- 正式 V3 持有电影 ViewTarget，Sequence 保持关闭 Camera Cut 接管。Night 两秒从有效机位开始。后撤从该固定机位发起 UE 原生 3.5 秒混合，目标是同一 Pawn 的实际第三人称相机。T00 继续负责流送与灯光，从现有交接回执恢复 Day 卸载。
- 镜头修复修改上述四个源码文件。新的 Night 出生点、后腰方向偏移、104 cm 特写距离、34° Toy FOV 及白天和音频时间标记沿用当前设置。Night 地图仅按用户授权单独保存其原有编辑。

## 验证与人工验收

- UE 5.8.4 CL58902052 下，`UnrealEditor Win64 Development` 的 `YIXIT00` 正常 UBT 构建成功。重开正式 Master 后，已核对进程载入新 DLL、地图无 Dirty 包，并通过官方 Unreal MCP 回读。
- 静态回读的 `CharacterCapsule` 半径为 30 cm、半高 86 cm，沿正式路径在 Night Landscape 的 `Z=-5588.824 cm` 命中地面，查询无初始穿透，计算出的 Pawn 中心为 `Z=-5499.824 cm`。V3 的 `V3Host` 绑定可解析，Sequence 无全局 Camera Cut 轨。标记仍为白天 5 秒、夜晚定镜 2 秒、后撤 3.5 秒。核对了 Master、Day 和 Sequence 的哈希，Night 的哈希与用户授权保存后的版本一致。
- 备份、静态读回和 UBT 日志位于 `Saved/YIXI_Archive/FormalP04_NightCamera_20261122_185324`。

从已打开的 `L_YIXI_P04_StreamingMaster` 正常进入 PIE。到 D07 后重点观看硬切首帧是否在角色后腰、玩具及背部是否可辨、两秒定镜是否稳定，以及后撤是否平滑接入第三人称。此次没有启动 PIE，实际构图与动态连续性待用户确认。

在 Output Log 搜索 `P04_NIGHT_CAMERA`。正常流程各记录一次 `ready`、`cut-first-frame`、`insert-midpoint`、`pullback-start`、`gameplay-restored`。首帧记录读取的是 PlayerCameraManager 已评估的镜头，与准备阶段的拟用机位可直接对照。若提前恢复操控，`refused` 或 `invalid-insert` 会标明失败阶段。
