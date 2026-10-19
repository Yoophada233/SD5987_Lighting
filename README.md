# 《一夕》YIXI

Unreal Engine **5.8.3** 环境叙事与灯光课程项目。工程入口为根目录的 `Lightning.uproject`。

本项目仅面向 **Windows PC 开发与游戏演示**；不进行 Android 打包或设备调试，不使用 AndroidFileServer 文件服务。

计划团队仓库：`Yoophada233/SD5987_Lighting`，**Private**。当前仅完成本地准备，尚未提交或发布；以下 Clone 步骤在维护者发布后才可使用。

## 开发环境

- Windows、Unreal Engine **5.8.3**（描述文件的 EngineAssociation 为 5.8，不能据此混用其他补丁版本）。
- Git。本项目使用 **纯 Git + GitHub Private，不使用 Git LFS**。
- 项目包含源码插件 **YIXIT00**。首次打开缺失模块时，需要正常 Windows 用户环境中的 Unreal C++ 工具链；不能仅安装编辑器便保证打开成功。
- 编译环境参照 [Epic UE 5.8 官方说明](https://dev.epicgames.com/documentation/en-us/unreal-engine/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine)：VS 2026 18.0+，或兼容的 VS 2022 17.14+，C++ 游戏开发工作负载及 Windows SDK。

## 首次获取工程（仓库发布后）

选择自己的普通开发目录，不要求与维护者使用相同磁盘或用户名：

~~~powershell
git clone https://github.com/Yoophada233/SD5987_Lighting.git
cd SD5987_Lighting
~~~

确认 Clone 完整结束后，用 **UE 5.8.3** 打开 `Lightning.uproject`。首次生成 Derived Data Cache、编译着色器需要时间，这是正常现象；这些本机生成数据不在仓库中。

- 插件启用状态由 `.uproject` 及 `.uplugin` 依赖声明控制；详见 [实际插件依赖](Docs/PluginDependencies.md)，无需逐个手动开启已经随同版本 UE 安装的插件。
- Git 不会安装 Unreal Engine 或 Fab/Marketplace 插件。出现插件缺失提示时，核对准确插件名和 UE 版本，联系维护者，不要直接禁用或保存受影响资产。
- 若提示缺少或需要重编 `YIXIT00`，先关闭该工程，用正常 Windows 用户的工具链生成项目文件并编译 Editor Development。**本轮未验证干净 Clone 的自动编译路径**；根目录目前没有 Source/Target 文件，若无法生成可构建目标，应由维护者提供经验证的源码构建步骤或合法的匹配版本插件包。不要猜测目标名、禁用插件或通过保存地图消除报错。
- 不在 CodexSandboxOffline 中直接启动 UBT/UAT。编译失败保留日志、准确退出码及运行环境，不盲目重试或删除缓存。

## 日常协作

开始修改前确认自己的工作区状态，再拉取更新：

~~~powershell
git status
git pull --ff-only
git switch -c your-name/task-name
~~~

有未提交修改时先妥善保留，不要用 reset、clean 或强制覆盖解决拉取问题。

- 提前约定地图、蓝图和动画资源的负责人；`.umap/.uasset` 通常不能像文本一样合并，避免多人同时修改同一资产。
- 只提交核对过的具体文件；提交前检查 Git 状态、暂存清单和单文件大小。新增资产后也要保留配套资源及引用。
- 不提交 Saved、Intermediate、DDC、本机 Binaries、个人编辑器设置、日志、备份或凭据；不要忽略整个 Content、Config、Plugins 或 Build。
- 不强制推送覆盖他人历史。Pull 或插件加载失败时先报告，不删除正式资源。
- Clone 完整结束只说明资源已获取，不等于地图、玩法、PIE 或打包已通过验收。

## 提交前仍需确认

- 已在 `Config/DefaultEngine.ini` 禁用 AndroidFileServer、网络连接与 Shipping 包含/外部启动，并移除真实 Token。保留空 `SecurityToken=` 覆盖项，避免 UE 缺省初始化自动生成并写回新凭据；不要把个人凭据写回共享配置。
- 已有内容来源和团队共享许可需由资源持有人确认；Private 不等于自动获得所有第三方分发权。不得将资源单独再分发或将仓库改为 Public。
- 普通 Git 单文件不超过 50 MiB 为本项目正常范围；大于 50 MiB 且不超过 100 MiB 需提示性能风险；超过 100 MiB 必须停止并商议处理。二进制历史版本会扩大仓库和完整 Clone 体积，不能像文本一样合并。 GitHub 单次 Push 上限为 2 GiB；原始目录体积不等于压缩上传包大小，首次提交和推送前需单独评估，必要时由维护者批准分批提交和上传方案。
- 首次独立 Clone、源码插件编译及实际打开项目尚待验证。

## 官方参考

- [GitHub Unreal 忽略模板](https://github.com/github/gitignore/blob/main/UnrealEngine.gitignore)（本项目保留 BuiltData 和必要 Build 资源）
- [GitHub 普通 Git 文件与仓库大小说明](https://docs.github.com/en/repositories/working-with-files/managing-large-files/about-large-files-on-github)
- [Epic GASP 项目说明](https://dev.epicgames.com/documentation/en-us/unreal-engine/game-animation-sample-project-in-unreal-engine)
- [Fab 标准许可](https://www.fab.com/eula) 与 [Epic 内容许可](https://www.unrealengine.com/eula/content)；具体以资源获取时适用条款为准。
