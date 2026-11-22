# 《一夕》正式关卡 P01.1

## 本轮修改

- 正式入口为 `/Game/YIXI/Tests/P04/Maps/L_YIXI_P04_StreamingMaster`。将该 Master 的原有 `PlayerStart_0` 从后院移入教室，世界坐标为 `(1718.978, 224.445, 225) cm`，Yaw 为 `180°`。使用现有玩家胶囊与教室碰撞面校准。夜晚落脚点读回一致，Night 地图文件的 SHA-256 与修改前一致。
- `/Game/YIXI/Tests/P04/Day/L_YIXI_T00_Day` 保留原有女孩请求解锁玩具的事件、首次请求文字及原绑定对象。把会生成空回调的 `Assign On Toy Requested` 换成显式 `Bind Event`，清除三个经核对无连线的空回调。仅定点保存 Day 和 Master。
- `YIXIStoryGirl.cpp` 允许处于 `Requested` 的女孩继续响应交互。重复按 E 显示约 3 秒字幕「我把玩具落在后院了。」，有语音时播放 `ReminderVoice`，空槽时保持静音。首次请求仍是唯一广播 `OnToyRequested` 的分支，遇难或不可交互状态依旧禁用提示和交互。

## 构建与验证记录

- UE 5.8.4 的普通 UBT 构建成功编译并链接 `YIXIT00`（Win64 Development）。当前工程关闭后使用 `-NoHotReload -NoHotReloadFromIDE -NoEngineChanges`，以避免共享引擎的其他编辑器会话触发 Live Coding 检查。完整构建日志见备份目录中的 `UBT_P011_Cold.log`。
- 关闭并重新打开编辑器后，Master 的教室出生点、Day 的单一请求绑定和玩具解锁链路均读回正确，空回调未重现。Master 和 Night 的编辑器状态为干净。Day 在读图检查后被标为 Dirty，磁盘版已验证；这次检查后的内存状态没有再次保存。
- 正常 PIE 未设置临时出生点。角色从教室 `(1718.98, 224.44, 225.00)` 出生，用 E 完全打开双门并步行穿过。同一回合沿原路走到女孩处，首次 E 让状态变为 `Requested` 并解锁玩具，再按 E 仍可交互，首次请求只出现一次。随后步行至后院拾取，同一 Pawn 的 `palm_r_Socket` 读回 `HELD_HAND`。未重跑手持返回。
- 另外在女孩附近短测字幕，等首次对白结束后再按 E。开启字幕的 PIE 截图实见圆环 E 和「我把玩具落在后院了。」，`ReminderVoice` 为空。截图见备份目录中的 `SilentReminder_UI.png`，按键与状态记录见 `PIE_Route.jsonl`。最后停止 PIE 并按默认位置再开一次，仍从教室出生，玩具恢复锁定。已将这次第三人称预览留给用户。
- 工作区仍在 `main`（`28788ba`），本轮改动保留为未提交修改。

## P02 就绪情况

D03 有候选落点 `YIXI_D_03_RoadBlock`，靠近 P01 已走通的女孩路线。部署前需要确认发射点与可见弧线、岩石最终封路范围，以及 D03B 西侧绕行的实际可通行路线和触发 Box。D03B 当前只有参考点。封路可用事件应在障碍确实落地、且与玩家胶囊无冲突后发出。

当前 Day 的请求绑定继续保留。后续接入 StoryCoordinator 前应明确请求事件由谁接管，并补齐其依赖的返程、袭击和发现现场引用，避免重复订阅。D06 返程与第二块岩石的标记用途、D07 正式站位和机位，以及 T00 的正式日夜交接仍待决定。P02 暂无完整部署条件。

现有 T00 仍在 PIE 预热阶段报告 GameMode／Controller 配置不匹配。白天基础交互走测通过，正式日夜交接留待后续独立核对。

正式长廊音效、女孩请求与提醒配音、正式人物和道具模型仍待接入。

## 恢复

备份在 `Saved/YIXI_Archive/FormalP011_20261122_135138/Before/`，对应路径和原始 SHA-256 见同目录上一级的 `Manifest.json`。需要撤回时先关闭目标关卡和编辑器，再仅恢复相应的 Master、Day 或 `YIXIStoryGirl.cpp`，恢复源码后重新构建 `YIXIT00`。Day 的备份是本轮开始时的工作副本，包含此前已保存的 P01 部署。
