# YIXI Grass System 使用说明

正式资源根目录：`/Game/YIXI_GrassSystem`。主入口默认64×64m、四个32m Tile；**`/Game/YIXI_GrassSystem/Examples/L_YIXI_GrassSystem64`**当前展示两个独立32m Area，用于复制和隔离操作，地图名称不变。保留增密、六模型及Tall派生LOD、最终Scale与Tall半高、风1.30/3.0/0.80、玩家20/35m范围；不要再次放大或减半。

## 第一次使用

1. 从内容浏览器拖入 **`/Game/YIXI_GrassSystem/BP_YIXI_GrassArea`**，放到需要覆盖区域的中心。区域保持轴对齐，Actor Scale保持1；覆盖范围用下表参数设置，不缩放Actor。
2. **不需要手放Wind。** 第一个运行的Area自动建立本世界唯一的`Core/BP_YIXI_GrassWind`，之后的Area共享它。不要再手放重复Wind，也不要同时启用写同一MPC的旧GrassBench入口。
3. 将 GrassArea 中心放在已加载的地形上，在 Details 点击 **BindLandscape**。在 **Landscape Binding → Landscape Binding Status** 查看成功绑定的地形路径或未命中原因。遇到多块地形时，可先在 **Target Landscape** 明确选择目标，再点击按钮。`LandscapePath` 保存实际绑定，按钮成功后会清空临时选框。未命中时保留上次绑定。
4. 将 **RVTVolume** 指向已有、实际覆盖草区的 Volume。保存所在关卡后进入游戏或 PIE，`AutoGenerate` 会生成并管理 Tile。对尚在流送的已绑定地形，启动时会等待最多约 12 秒。超过该时间后，地形加载完成时可对该草区手动执行 `Generate`。场景流送仍由关卡管理。

| GrassArea参数 | 默认值与用途 |
|---|---|
| `TargetLandscape` / `LandscapePath` | `BindLandscape`优先使用手动选择，否则按草区中心探测地形碰撞，并保存实际命中的地形软路径 |
| `RVTVolume` | 指定已有RVT Volume，模块检查草区是否在其XY覆盖内 |
| `TilesX` / `TilesY` | 主入口默认2 / 2；当前双区示例各1 / 1。配置允许每区总数1–64，不代表已作全范围性能验收 |
| `TileSizeCm` | 3200；覆盖尺寸=格数×格距，与模型Scale分开 |
| `DensityMultiplier` | 1，代表本轮已增密基线；调大增加种植候选，坡度/禁种过滤仍生效 |
| `LowSharePercent` | 95；当前支持60–99.5，属于包含既有补矮草分支的近似数量比例 |
| `BaseSeed` | 20261117；固定配置和Seed保持稳定选择，不随玩家移动重新抽签 |
| `AutoGenerate` | 自动建立本区域Tile并按玩家距离生成/清理 |

95:5是模型簇数量目标，不是面积或屏幕覆盖比例；每格允许地形及固定随机偏差，不将PISM预留容量当作实际数量。当前源配置保持LowSharePercent=95、DensityMultiplier=1；改变密度/Seed/区域后不保证相同总量。

## 生成、清理、平移与复制

游戏/PIE启动后，从输出日志的 **`AreaPath`** 取得目标Area的本次完整对象路径；按反引号／`~`打开游戏控制台，将下面的`<AreaPath>`替换为该路径：

- 仅该区生成／重建：`ke "<AreaPath>" Generate`
- 仅该区清理：`ke "<AreaPath>" Clear`
- Natural：`ke BP_YIXI_GrassWind_C ApplyMode 1`
- Gusty：`ke BP_YIXI_GrassWind_C ApplyMode 2`，当前交付默认强风

不要用`ke BP_YIXI_GrassArea_C Clear/Generate`操作单区：类名会广播给所有Area。完整路径只对本次运行有效，PIE重开后重新取日志；Outliner显示标签不等于对象路径。这是运行时入口，**Editor只配置参数、BindLandscape并Play，不提供编辑期生成按钮**。清理完成会释放本区Tile和植被，过程中不要反复发送命令。

风模式是全局设置，影响本世界所有Area，不能给每个区各放一个控制器。既有两档读回为Natural Gust约0.54、Gusty0.80，Sway1.30／Lateral3.0保持；默认Gusty。**Natural不等于完全关闭阵风。**

可靠的换位步骤：Clear并等待资源释放→停止PIE→在Editor中移动同一GrassArea中心并定点保存→确认地形软绑定和RVT覆盖→再次PIE自动生成。不改Tile白名单、名称或固定世界坐标。沿用64m预加载／80m卸载、1.5秒迟滞及生成/清理并发各1，风时钟不随Tile重置。

复制GrassArea后，为每个实例分别设置位置、地形绑定、RVTVolume、范围、密度/比例和Seed，避免区域意外重叠。每区只管理自己的Tile，共享Wind聚合范围、增量登记组件；已实测清理、重建、换位或删除A时B不重生且风时钟连续。**删除A已测，未另做流送卸载压力测试。**

## 更换六模型及材质

模型池入口：**`/Game/YIXI_GrassSystem/PCG/G_YIXI_Grass`**。`Spawner`是四款矮草池，`TallSpawner`是两款羽穗草池。每个Entry设置Static Mesh、每槽OverrideMaterials和池内Weight；共享图的池修改会影响使用该图的Area，各区总Low/Tall比例在各自GrassArea设置。修改在清理后、重新生成前生效，不对已有GPU PISM运行时SetMaterial。

正式MI在 **`/Game/YIXI_GrassSystem/Materials/Instances/`**。换模型需核对Pivot、高度、贴图UV/材质槽、LOD、根部与风形变，更新对应MI的`TopLocalZ`、`RootFixedZ`及局部响应；不是只换Mesh便自动适配。当前根部固定带1cm，最终Scale关系已在PCG链中实现。

## Landscape与RVT

地形软绑定负责生成目标，RVT负责颜色融合。保留 **`/Game/RVTDecals/Textures/VirtualTextures/T_Landscape_BRN_RVT`**、地形材质RVT输出、Landscape的Draw in Virtual Textures及已有Volume；GrassArea的`RVTVolume`应指定这个Volume。草只读不写，Low染色0.25、Tall0.12，采样排除WPO位移。

改用其他RVT需同步检查正式材质采样及地形生产者，不是只换Volume。不要重复添加Volume；平移后核对实际Bounds，域外颜色不保证。现环境Volume曾读回X[-61425.6866,55546.6712]、Y[-51500,256460.2377]cm，以当前实例为准。跨地表颜色渐变延期。

## 资产与依赖清单

| 类别 | 路径／内容 |
|---|---|
| 主要入口 | `/Game/YIXI_GrassSystem/BP_YIXI_GrassArea` |
| 示例 | `Examples/L_YIXI_GrassSystem64`；仅示例引用外部`/Game/YIXI/Tests/P04/Night/L_YIXI_T00_Night`、`/Game/LS_YIXI_Master_LightStates`及`GM_Sandbox_Ragdoll`。Night在示例图中Always Loaded，正式Day/Night流送不变 |
| 必要内部Core | `Core/BP_YIXI_GrassWind`自动建立、每世界共享；`Core/BP_YIXI_GrassTile`由各Area管理 |
| 生成规则 | `PCG/G_YIXI_Grass`、`PCG/BP_YIXI_ProjectGrassToLandscape` 和种植域纹理。投射使用 WorldStatic 查询，只接受当前绑定的 Landscape |
| 正式材质 | `Materials/M_YIXI_PN`、`M_YIXI_Miscanthus`；10个Instances；`Functions/MF_YIXI_Field`、`MF_YIXI_Bend`；`MPC_YIXI_Wind`、`MPC_YIXI_Quality` |
| Tall派生网格 | 正式`Meshes/`内两款Miscanthus LOD副本 |
| 外部源素材 | `/Game/PN_GrassLibrary`四款Low网格及必要表面纹理；`/Game/Project_FW`实际使用纹理和源素材依赖，不复制整包 |
| 环境依赖 | 已加载Landscape、有效地形碰撞、上述RVT生产者/资产/Volume，以及有受控Pawn的游戏环境 |
| 引擎依赖 | 当前UE5.8.4的PCG及GPU生成支持；MCP/PCGToolset和审计工具用于开发，不是持续驱动模块的运行入口 |
| 保留历史 | `/Game/YIXI_GrassBench`全部原实验资产及Saved历史数据；正式Day/Night、Landscape、Spline、GASP不因本次封装被替换 |

20个有依赖的正式运行资产经Asset Registry复核，无`/Game/YIXI_GrassBench`依赖。Core不含示例灯光/初始化、测试相机/传送、六株诊断标本或审计/抓帧脚本。外部ResourceGuard是编辑工具，不是模块自带的运行时内存保护，不依赖旧PID或固定停止文件。普通生成草保持无阻挡碰撞。

## 当前验证范围与限制

**双区实测：**原生复制A→B后，地形软路径/RVT/范围/95/Density1正确复制，运行缓存为空；A/B种子分别20261117/20261118，GraphInstance、offset与组件各自独立。移除示例手放Wind后，启动自动建立唯一`PersistentLevel.BP_YIXI_GrassWind_C_0`，两区共12个PISM；已兼容原先手放唯一正式Wind的场景。

用A的完整路径Clear后，A的Owners/States为空，仅B的6组件登记；再改A运行种子并Generate、清理后平移32m再生，B的组件引用、Seed、生成1次/清理0次始终不变。运行时删除A后B仍Active，风事件序号2→67且相位连续，无重置或登记累积。此为删除隔离验证，不冒充流送卸载压力测试。

示例保存、真正重新加载并新开PIE已通过：A/B地形软绑定和配置持久，Editor缓存空、无手放Wind；新PIE两区均Active、FailureCount=0、各生成1次/清理0次、Seed20261117/20261118，SharedWind指向同一个PersistentLevel自动实例，登记12、HistoryReady=true，风1.30/3.0/0.80。主蓝图新放置默认仍2×2=64m，当前示例为两个32m区，不是新扩量测试。

本轮只改Area/Wind/Tile三个正式蓝图、原示例地图及本说明；20个未修改的模型/材质/PCG/MPC等正式资产SHA256逐项一致。[备份清单](<E:/Unreal Projects/Lighting/Saved/YIXI/GrassSystem_Final/MultiArea_20261119T005700/backup_manifest.json>)；恢复须先停PIE、正常关闭Editor，再按清单定点处理，勿覆盖打开着的资产。

**既有冷启动情况：**母材质重编译后曾有PCG生成被取消；等待编译完成，Clear→Generate可恢复，之后新PIE自动通过。遇到同类情况先等待编译和加载结束，不反复并发生成。

不将已验证范围扩写为256m全视角性能通过，不新增Cook/打包结论。强风最终美术、跨地表RVT、CPU ISM颜色兼容及大面积性能仍未确认，本轮不再开启优化循环。
