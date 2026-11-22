# 《一夕》正式 P04 日夜转场

## 接入

- **Master** 使用现有 `YIXI_N02_T00_Controller`。正式实例按当前的 `BP_YIXI_StorySandboxGameMode`、`BP_YIXI_StorySandboxController` 和 `SandboxCharacter_Mover_Ragdoll` 校验实际占有关系、角色胶囊、Mover、游戏相机、交互及 ToyCarry。旧 T00 测试入口和相机仍走各自原路径。Master 的灯光实例清除了旧太阳的冲突覆盖，SkyLight 与 Post Process 指向现有正式对象，日夜沿用原灯光 Sequence 的第 0、30 帧。两边的 Post Process Volume 均为有界体积。
- **Day** 由现有 Day Level Blueprint 继续负责前置剧情。`YIXI_P03B_D07_CinematicStage` 关闭 Day-only 预演，绑定只处理 V3 请求及回执的 `YIXI_P04_D07_StoryMatchCut`。玩家持有同一玩具、第二颗投石已完成、女孩已退出交互后开始准备 Night。进入 StageTrigger 后沿用已有的自动走位和白天镜头。
- **Night** 使用 Master 中现有的流送实例及 `T00_Destination`。流送偏移为 `(0, 100000, 0) cm`。目标标记保留原世界坐标 `(-34969.213347, 219005.536984, -5579.727802) cm`，Yaw `31.871941°`。编辑器静态探测在该点下方约 9 cm 命中 Night Landscape。

## 交接与失败恢复

1. T00 提前异步加载 Night，确认指定子关卡已加载并可见、实际玩家胶囊在目标位置获得 Night 承托且无阻挡，连续满足 30 帧并等待渲染栅栏。超时保留 Day。白天定帧完成时，Night 仍未就绪则维持白天地面镜头。
2. V3 在白天稳定特写完成后通过 Mover 移交同一 Pawn，并检查实际落地位置、朝向和预期后腰机位的碰撞视线。既有 StoryCoordinator 验证唯一 RequestId 与同一件玩具，通过 ToyCarry 将其挂到后腰。V3 硬切到正立的夜晚后腰镜头，停留后后撤，并交还游戏相机与输入。
3. 音频组件由 Master 中的 T00 持有。设置为切前 4 秒渐入听觉失真，硬切停止白天直接声，耳鸣和湿声衰减 2.5 秒，夜晚环境声在切后 1.8 秒开始淡入。音源沿用 V3 现有测试素材。
4. T00 是 Day 卸载的唯一负责人。V3 已还原游戏相机和输入、同一玩家的游戏相机生效、音频尾段结束后，才异步卸载 Day。切前失败走恢复流程。已请求角色移交时，先尝试确认返回 Day，再释放 Night；返回尚未确认时保留两个子关卡。

## 验证与试玩

- UE 5.8.4 的正常 UBT 构建通过，目标为 `UnrealEditor Win64 Development` 的 `YIXIT00` 模块。源码改动涉及 T00 流送、V3、StoryCoordinator、ToyCarry 的后腰姿态预检及 V3 音频组件。
- 使用官方 Unreal MCP 定点保存了 Master 和 Day，并重新打开正式 Master 回读。已核对玩家类、流送实例、落脚点、D07 绑定、灯光覆盖、音频资产及时间参数。SHA-256 校验显示 Night、D06 曲线、V3 镜头 Sequence 和 Master 灯光 Sequence 的资产文件保持原样。
- V3 的 Sequence 标记为 `Stable 9.4 s`、`Cut 14.4 s`、`Pullback 16.4 s`，配置对应白天固定 5 秒、夜晚固定 2 秒。正常播放可能在白天地面镜头等待 Night 就绪。实际硬切首帧、后腰构图、尾音、输入恢复、跳过与异步卸载仍待真人 PIE 验收。
- 前置备份和构建日志保存在 `Saved/YIXI_Archive/FormalP04_Transition_20261122_172824`。内含修改前的 Master、Day 地图及本轮源码副本。

**试玩入口**　在已打开的 `L_YIXI_P04_StreamingMaster` 使用默认 Player Start 进入 PIE。从教室正常推进，拾取玩具后返程，第二颗投石结束后走到 D07。重点观察硬切、后腰玩具、余音及镜头后撤后的移动和鼠标视角。输出日志中可用 `P04_FORMAL_NIGHT_COLLISION_AND_RENDER_READY`、`MATCH id=` 和 `P04_FORMAL_DAY_UNLOADED` 定位几个交接阶段。
