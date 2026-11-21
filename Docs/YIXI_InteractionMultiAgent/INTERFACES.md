# 《一夕》多 Agent 公共接口规范

## 统一交互 HUD

门、双开门、NPC、玩具及其他 E 键交互对象统一接入 `UYIXIInteractorComponent` 和 `/Game/YIXI_InteractionKit/UI/WBP_YIXI_InteractionHUD`。沿用 R1 的提示样式、尺寸、颜色、过渡动画和屏幕定位。公共提示由现有 HUD 统一绘制，新交互对象仅提供自己的交互数据和行为。

已只读核对 `IYIXI_Interactable`、Interactor、HUD 源码及已保存的蓝图引用。单开门、E 键和 HUD 已有历史运行证据。本次核对未运行 Editor 或 PIE。 [R1 验收记录](../YIXI_InteractionKit/YIXI_INTERACTION_SANDBOX_R1.md)

### 对象接口与状态

- 交互 Actor 实现 `CanInteract`、`Interact`、`GetInteractionPrompt`。返回的 `FYIXIInteractionPrompt` 提供锚点世界坐标 `WorldLocation`、以厘米为单位的 `DetectionRange` 和 `InteractRange`，以及 `ActionText` 和 `bShowPrompt`。锚点和距离由对象或实例配置，统一筛选与投影由 Interactor 处理。
- 每个本地玩家允许同时存在多个候选。Interactor 按距离、相机方向、视口范围及从相机和 Pawn 到锚点的遮挡结果，选出一个当前目标。投影使用现有玩家视口及 DPI 感知转换，切换和迟滞沿用 R1。
- E 键沿用现有按下事件。派发前，Interactor 重新检查当前目标的可见性、交互距离和 `CanInteract`。`bShowPrompt` 只控制显示。剧情或运动状态暂时禁用交互时，使用 `CanInteract` 阻止执行。

| 状态 | 显示条件与表现 |
| --- | --- |
| 0 · `Hidden` | 无有效目标、超出检测范围、不可见、被外部几何遮挡、在屏幕外，或目标关闭提示时隐藏。 |
| 1 · `Dot` | 当前目标可见、处于检测范围且启用提示，但尚未满足交互条件。在锚点处显示一个小实心点。进入交互距离后目标仍暂不可操作，也保持此状态。 |
| 2 · `Ready` | 当前目标可见、处于交互距离、允许提示且 `CanInteract` 为真。实心点按现有动画过渡为细线圆环与 E。 |

## 双开门中央锚点 · `B-DD-01`

- `BP_YIXI_DoubleDoor` 以整门 Actor 实现一次交互接口。门框和两扇门组件归属同一 Actor。一次 E 请求提交给整门，左右门扇按同一个开关状态同步动作。
- 选择 `CenterInteractionAnchor` 下的 `InteractionAnchor` 直接拖动提示点。父组件继续使用原中心偏移。默认位置在门框中央、接近把手高度，左右门扇转动时位置固定。`GetInteractionPrompt` 返回正反两侧共用的子锚点世界位置。
- 正反两侧使用相同的范围与遮挡规则。现有可见性检测接受首先命中目标 Actor 自身的射线，关闭的自有门扇可以参与正常选中。门外的墙体等遮挡物仍按公共规则处理。
- 开关过程中仍由同一个目标更新同一个提示。同场有多个双门，或者双门与单门相邻时，每个本地玩家仍只显示当前目标的提示。原单门的 `InteractionAnchor` 跟随 `HandleMarker` 和门扇，继续应用现有的提示偏移。

## 任务卡继承与审核

规格 Agent 为每张涉及玩家交互的任务卡继承本章，发卡前核对现有接口、HUD 和相关对象实现，并填写下表字段。

| 必填字段 | 内容 |
| --- | --- |
| 复用基线 | 核对过的实现与证据、沿用 `Hidden → Dot → Ready` 的条件、其他 UI 需求及独立用途。 |
| 目标与锚点 | 逻辑 Actor、锚点名称、挂接对象、默认位置、坐标来源，以及可操作的侧面。 |
| 距离与资格 | `DetectionRange`、`InteractRange` 的配置归属，启用提示与 `CanInteract` 的限制。 |
| 多目标行为 | 可同时出现的候选，当前目标归属，以及每个本地玩家最多一个提示的验收用例。 |
| 验收与证据 | 三阶段、视口与遮挡、切换和 E 路由的 PIE 步骤，记录地图、对象实例、配置和实际结果。 |

- **开发 Agent** 按任务卡提供锚点和接口数据，使用已完成的 Interactor 与 HUD。
- **技术审核 Agent** 核对接口、组件归属、状态条件及单一输入路由。双开门重点检查 `CenterInteractionAnchor` 固定在门框和每次按键只派发一次整门交互。
- **体验审核 Agent** 在 PIE 中验证位置、尺寸与风格一致性，跑测进入和退出距离、遮挡、离开视野及多目标切换。记录实际画面与结果。

### 双开门的必验用例

1. 从正面和背面分别靠近关闭的大门，实际观察隐藏、中央单点、中央单环＋E。离开范围或隔墙后提示隐藏。
2. 近处按一次 E，两扇门同步动作。开关途中观察锚点仍在门框中央、无重复提示。再次按 E 验证整门关合。
3. 放置两个双门实例并与原单门同场。跨不同实例的检测区和视角时只显示当前有效目标，E 只发给该目标。
4. 同场复验原单门提示随把手移动，点到圆环的时机、交互与遮挡表现符合 R1。

## 剧情模块交接

| 模块 | 接口与保证 |
| --- | --- |
| 双开门 | `OnDoorOpenStarted`、`OnDoorOpened`、`OnDoorCloseStarted`、`OnDoorClosed` 每次整门动作只广播一次。剧情以 `OnDoorOpened` 推进。 |
| 长廊音效 | `OnTriggered(Pawn)` 表示触发已被接受。原生顺序会在回调返回后排入音频。仅对已启用的一次性 Box，协调器可调用 `TryTriggerFirstOverlappingPlayer` 补查已经在区内的玩家。 |
| 落石与封路 | `Launch(RequestId)` 接受一次正整数请求。`OnImpact` 报告落地，`OnBlockageReady` 报告阻挡真正生效。协调器对照同一请求并回读状态。 |
| NPC 与玩具 | `OnToyRequested(Pawn)` 开放指定拾取物。`OnToyPickedUp(Pawn)` 表示手部挂接已成功。玩家 Carry Component 引用同一个玩具，提供 `TryDrop`、`TryAttachToWaist` 及状态事件。对白通过剧情委托展示。 |
| 场景触发器 | `OnPlayerEntered`、`OnPlayerExited` 以受控 Pawn 为单位，`ContainsPawn` 用于阶段切换时补查已有重叠。 |
| Match Cut | `OnMatchCutRequested(RequestId, Pawn, DroppedToy)` 暴露已落地的同一个道具。对应的 `CompleteMatchCut(RequestId, bSucceeded)` 验证当前请求、同一受控 Pawn 及后腰挂接结果。失败保留恢复入口。隔离替身按延时返回结果，正式转场接口接入另行授权。 |

### V3 镜头与剧情交接

沙盒协调器通过实例引用 `V3Cinematic` 选择正式请求的发出时机。拾取玩具后准备夜景，返程撞击后女孩从现场消失。发现区域将相机、移动和交互提示交给演出。玩具由原 Carry 组件从手上释放。落稳且机位稳定以后，正常播放保持 5.0 秒，再以同一 Pawn、同一玩具和有效 RequestId 请求挂到后腰。成功后立即硬切。夜景展开结束时交回相机、角色输入和 HUD。空格跳过可缩短停留，仍需完成掉落、挂接及夜景首镜。

夜景在持久白盒中提前准备。独立混响总线和夜声由演出实例持有。正式流送接入时，演出及跨切音频应位于不会随白天子关卡一起卸载的宿主。现有地图没有配置演出实例时仍使用原交互流程。
