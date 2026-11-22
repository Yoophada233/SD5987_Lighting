# 《一夕》正式 P02 · 第一颗投石与绕行

## 部署

工程 `E:/Unreal Projects/Lighting/Lightning.uproject`，UE 5.8.4 CL58902052。运行入口为 `/Game/YIXI/Tests/P04/Maps/L_YIXI_P04_StreamingMaster`。以下三处标记和两个新实例均位于 `/Game/YIXI/Tests/P04/Day/L_YIXI_T00_Day`。

| 对象 | 世界位置 cm | 实际配置 |
| --- | --- | --- |
| `YIXI_D_03_RockStart` | `(-1195, 11901.34, 2990)` | 保留用户 TargetPoint，实际发射锚点取其位置 |
| `YIXI_D_03_RoadBlock` | `(-1175, 201.34, 40)` | 保留原 TargetPoint。正下方实测道路碰撞面为 Z≈28.75 |
| `YIXI_D_03_BypassTrigger` | `(-1825, 721.34, 40)` | 保留用户 TargetPoint，作为西侧触发区的水平位置 |
| `YIXI_P02_D03_RoadblockRock` | 根 `(-1175, 201.34, 40)`，落地网格中心 Z=130 | 复用 `BP_YIXI_ScriptedRock`。时长 4.0 秒，附加弧高 700 cm，沿约 117 m 的水平距离飞行。阻挡盒半尺寸 `(235, 83, 100)` cm，落地后的碰撞底部 Z=30 |
| `YIXI_P02_D03_BypassBox` | `(-1825, 721.34, 120)` | 复用 `BP_YIXI_StoryTriggerBox`。盒半尺寸 `(160, 110, 110)` cm，仅用于 Pawn 重叠 |

Day 关卡蓝图从现有长廊音效 Box 的 `OnTriggered` 进入，延迟 0.35 秒调用 `Launch(1)`。首启发现直接委托目标在 PIE 初始化时失效，改为按蓝图类和唯一 P02 标签在当前运行世界查找实例。女孩请求和解锁玩具的原链路保留。绕行 Box 收到玩家进入时先检查 `IsBlockageReady`，通过一次性门控后将 `P02BypassConfirmed` 置为 true。

飞行阶段阻挡关闭，由原生岩石逻辑在落点盒清空后启用 Pawn 阻挡。岩石使用蓝图原有白盒网格，飞行与撞击音效槽留空。飞行时长、弧高、锚点与阻挡盒可在岩石实例调整，触发延迟可在 Day 关卡蓝图中调整。

## PIE 路线

正式 Master + Day 使用默认 PlayerStart，未设置出生覆盖。实际从教室出生，按 E 开双开门并步行通过。长廊 Box 触发一次后，岩石进入 `InFlight`，阻挡为 `NoCollision`。落地后读回 `Blocking` 与 `QueryAndPhysics`，请求 ID 为 1。在原路持续按 W，Pawn 停在约 `(-1113.74, 87.6, 117.15)`，两次采样的位移约 0.03 cm。

同一回合中，从落石前退回至 Y≈−640 的横向通道，向西进入铺装路，北行经过绕行 Box，再从 Y≈1155 附近转回女孩方向。第一次确认后，返程确实退出并再次进入 Box，整回合 `YIXI_P02_BYPASS_CONFIRMED` 只记录一次，长廊触发计数与投石请求 ID 均保持 1。

到达女孩位置后实际按 E 进入 `Requested`，玩具由锁定变为可拾取。沿绕行返回并步行到后院，按 E 成功进入 `HELD_HAND`，同一 Pawn 的右手挂接点为 `palm_r_Socket`。走测未传送，最终有效回合没有 Blueprint Runtime Error。

走测结束后按默认出生重新打开第三人称预览，留在教室入口供用户体验。

本回合验证了飞行无阻挡、落地启用阻挡及原路实体阻挡。落地时恰好有角色占据阻挡盒的情况继续由现有原生清空检查处理，本回合未专门制造这一条件。

## 保护与恢复

只保存了 Day。前置 Dirty 现场先按原磁盘版本与含新标记的编辑器基线分别备份。备份目录为 `Saved/YIXI_Archive/FormalP02_20261122_144119/`。若要撤回本轮部署并保留用户新标记，参考其中的 `Day.UserMarkersAndEditorBaseline.umap` 和 `Manifest.json`，关闭该地图后仅恢复 Day。Master 和 Night 文件哈希与部署前一致。

实际按键轨迹见 `PIE_Route.jsonl`，事件计数与运行结果见 `PIE.Evidence.log`，站在落石前的运行画面见 `Blockage_PIE.png`。正式岩石模型、飞行声与撞击声待接入。T00 预热继续报告已有的配置不匹配，本轮仅交付 Day 封路与绕行。
