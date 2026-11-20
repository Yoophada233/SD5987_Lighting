# 教室桌凳布置 — 2026-11-20

工程：`SD5987_Lighting/Lightning.uproject`。
保存关卡：`/Game/YIXI/Tests/P04/Maps/L_YIXI_P04_StreamingMaster`。
大纲文件夹：`YIXI/Classroom/Furniture`。

使用现有 `Content/3DAssets/mesh` 内的 `SM_table1_1_1005_mesh` 与 `SM_chair2_1_1023_hd_p_prefab`，新增六组学生桌凳（两排三列）及一组先生桌凳，共14个 Actor。学生面朝世界 +X，先生桌位于教室后端；保持门口与桌间通道。桌凳底部 Z=129.25，与地面相接。

原有441个 Actor 的关卡、位置、旋转、缩放已核对一致。未修改原门窗、建筑、灯光、摄影机或 Sequence。只保存上述主关卡；保存后没有未保存的地图。

修改前地图备份：`Saved/YIXI_Archive/2026-11-20/Before_ClassroomFurniture/L_YIXI_P04_StreamingMaster.umap`。备份和检查截图位于 Saved，仅本地保留，不随 Git 上传。
检查截图：`Saved/YIXI_Classroom/classroom_overview.png`。

本次交付包含关卡、布置脚本与此说明；本地备份和检查截图不上传。以后打开本工程和该关卡即可看到桌凳，无需再次运行脚本。
