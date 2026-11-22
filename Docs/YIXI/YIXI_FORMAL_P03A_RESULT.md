# 《一夕》正式 P03-A · 返程投石

## 正式接入

工程为 `E:/Unreal Projects/Lighting/Lightning.uproject`，UE 5.8.4 CL58902052。运行入口 `/Game/YIXI/Tests/P04/Maps/L_YIXI_P04_StreamingMaster`。以下标记及新实例全部属于 `/Game/YIXI/Tests/P04/Day/L_YIXI_T00_Day`。三个 TargetPoint 均为无碰撞定位标记。

| 对象 | 世界坐标 cm / Yaw | 部署 |
| --- | --- | --- |
| `YIXI_D_06_ReturnTrigger` | (790.19, 1849.98, 50) / −140° | `YIXI_P03A_D06_ReturnBox` 复用 `BP_YIXI_StoryTriggerBox`，中心 Z=125，半尺寸 (92, 110, 110) cm。路面 Z≈28.75 |
| `YIXI_D_06_RockStart` | (383.92, 1587.40, 50) / −140° | `YIXI_P03A_D06_AttackRock` 复用 `BP_YIXI_ScriptedRock`，白盒岩石中心起飞 Z=95 |
| `YIXI_D_06_RockImpact` | (−1389.39, 1396.69, 90) / −110° | 落地中心 Z=104，静态探测落地面 Z=64。白盒网格直径约 80 cm，第二颗石头的封路碰撞关闭 |

保留用户三个标记原位。旧 `YIXI_D_06_ReturnAttack` 仅作历史参考。多组基础抛物线在 Day 前景和落点前的屋檐范围有碰撞。新曲线 `/Game/YIXI/Interaction/CF_YIXI_D06_AttackArc` 沿同一 XY 轴线调节高度。候选中心峰值约 Z=773 cm，64 段中心和偏移阵列射线未命中；这是碰撞预检。实际实例飞行时长为 2.4 秒，`VerticalLift` 为 700 cm，曲线资产保持可编辑。飞行声与撞击声槽和衰减可替换，`OnImpact` 可接入后续扬尘和碎屑。

Day 关卡蓝图保留 P01、P02 的事件归属。初始化时按类和唯一标签查找一次返程 Box、第二颗石头及原玩具实例，后续使用保存的对象引用。拾取成功事件记住 Pawn，并用 `ContainsPawn` 补查拾取时已在区内的情况。走入返程 Box 与拾取回调共用 `TryP03AAttack`。它核对同一受控 Pawn、`HeldHand`、同一玩具的实际挂接及区域状态。第二颗石头使用请求 2，原生 `Launch` 只接受一次。有效撞击后调用原女孩的 `SetUnavailable`、隐藏模型并关闭其碰撞。Day 记录 `P03AAttackComplete`。

## PIE

- **空手门控**。单独从返程区外的临时起点步行入区。Box 确认 Pawn 重叠，石头保持 `Idle`、请求 0，女孩保持 `RequestReady` 且可交互。
- **默认出生完整走测**。重新启动 PIE，从教室正常出生，以第三人称输入开门、通过长廊、确认第一颗石头挡路、走西侧绕行、与女孩交互并到后院拾取。步行返程进入 D06 时，原玩具仍在同一 Pawn 的 `palm_r_Socket`，第二颗石头发出请求 2。正向路线全程使用游戏内移动。
- **飞行及撞击视线**。从返程第三人称相机取得 13 个飞行时点样本，飞石中心均在画幅内，其中 7 个样本中心视线无遮挡，实拍可见半空中的飞石。撞击点的中心和六个外缘追踪均被 Day 建筑 `StaticMeshActor_24` 遮挡，撞击帧也从该返程机位实拍。结论适用于本次实走路线和视角。
- **撞击后状态**。女孩切到 `Unavailable`，模型隐藏且退出交互。请求 2 和完成事件各出现一次，走出 Box 再进入时仍为 `Impacted`。同一 Pawn 持有原玩具。随后沿现有通道走到 D04 落点附近，七条视线均无遮挡，画面可见留在地面的白盒残骸。
- **边界与待验收**。实际拾取点在 Box 外。区内拾取的次序由拾取回调重新查询 Box 的实现覆盖，当前正式点位下没有单独复现这项特殊条件。正式岩石外观、飞行声、撞击声、扬尘和碎屑留作资源接入，飞石可读性留待用户体验确认。

本地证据位于 [P03-A 现场归档](../../../Saved/YIXI_Archive/FormalP03A_20261122_153714)。三张 PIE 截图分别为 [返程飞石](../../../Saved/YIXI_Archive/FormalP03A_20261122_153714/Return_Flight_PIE.png)、[建筑遮挡撞击](../../../Saved/YIXI_Archive/FormalP03A_20261122_153714/Return_Impact_Occluded_PIE.png) 和 [走近后看到残骸](../../../Saved/YIXI_Archive/FormalP03A_20261122_153714/Residue_Visit_PIE.png)。路线实读与事件记录见同目录的 `PIE_Route.jsonl` 和 `PIE.Evidence.log`。

## 保存与恢复

完成 Day 关卡蓝图编译，定点保存 Day 和新曲线。Master 和 Night 的磁盘哈希与本轮部署前一致。备份 `Saved/YIXI_Archive/FormalP03A_20261122_153714/Day.BeforeWithD06Markers.umap` 包含用户新放的三个标记，可用于撤回本轮绑定。原磁盘副本、哈希及蓝图读回也在同目录。交接时已从默认出生重新打开第三人称 PIE。D07、V3 与正式 Match Cut 仍属后续阶段。

启动日志另有一条 T00 的 `Effective configuration mismatch`，当前运行使用 `BP_YIXI_StorySandboxGameMode_C`。本轮 Day 走测已跑通，正式日夜转场的配置仍需在其接入阶段核对。
