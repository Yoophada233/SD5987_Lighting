# 《一夕》V3-R4 · 右后肩镜头与听觉失真

[播放 24.6 秒连续有声 PIE](Media/YIXI_ToyMatch_V3_R4_Sandbox.mp4) · [看同次实拍 A/B](Media/YIXI_ToyMatch_V3_R4_AB.png) · [单听硬切前后 7.5 秒](Media/YIXI_ToyMatch_V3_R4_CutAudio.wav)

## 右肩构图与连续运镜

A 为游戏自己的第三人称相机，B 为沿原视线收拢后的右肩定帧。B 左缘有半头和右肩，前景失焦，落石在画面下方可辨，石块左缘有少量肩部遮挡。两张原参考图未随本轮消息传入，因此本轮以文字构图要求检查实拍，逐图比对及最终观感待用户确认。

从实际游戏相机到右肩共采样 61 次。Yaw **145°**、Pitch **−4°**、Roll **0°** 全段保持，最大转角 **0.000°**。沿原相机 Forward 推进 **210.95 cm**，相机局部 Right **−10.68 cm**，局部 Up **24.59 cm**。落点距右肩骨 **58.8 cm**，距落石 **3.36 m**。落石仅供手动对焦，Cine Camera Look At Tracking 已关闭。沙盒走测从南墙内侧较开阔处斜向进入，以免南墙挤压游戏相机。落石位置及投石路线沿用用户保存的沙盒。[本次相机与时序采样](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R4/PIE_normal_1795260565574957100/ShotMetrics.json) · [UE 5.8 电影景深文档](https://dev.epicgames.com/documentation/en-us/unreal-engine/cinematic-depth-of-field-in-unreal-engine?lang=en-US)

右肩保持实测约 **0.98 秒**。随后用同一台相机下滑 **47.6 cm**，世界 XY 变化 **0 cm**，焦点同步收至手中玩具。手部停留 **0.502 秒**，玩具竖直下落 **1.612 秒**，全段 XY 与旋转变化均为零。白天落地后定镜 **5.025 秒**，硬切一次。夜晚首帧 Roll 为 0°，定镜实测 **2.029 秒**后开始后撤。同一角色与玩具在夜晚完成后腰挂接，操控恢复后持 W 实走约 **1.31 m**。[完整运行轨迹](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R4/PIE_normal_1795260565574957100/Timeline.json)

成片约 **6.8 秒**可看右肩定帧，约 **8.1 秒**可看下移拉焦，约 **16.57 秒**硬切夜晚。Sequence 30 fps 时间标记为 ShoulderSet 90、HandBlend 120、Hand 189、Release 204、Stable 252、Cut 402、Pullback 462、Return 567、End 597，保留 5 秒 / 2 秒的编辑器时长。

## 最终混音实测

耳鸣在切前 **3.98 秒**出现，湿声在切前约 **3.88 秒**出现。白天直达声的高频与低频电平差由失真前 **−8.79 dB** 降至切前 **−16.55 dB**。最终 MP4 解码后，白天直达声在约 **16.574 秒**停止，与画面采样硬切相差约 **4 毫秒**。成片音轨与同一次 PIE 主混音的相关系数为 **0.9987**。[成片音轨测量](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R4/PIE_normal_1795260565574957100/MeasuredDeliveryAudio.json)

切后第 **1 秒**湿声 **−38.7 dBFS**，到第 **2 秒**湿声 **−49.1 dBFS**、耳鸣 **−43.5 dBFS**。切后 **2.20 秒**的成片混音仍为 **−46.1 dBFS**，该窗内夜景声尚未进入。夜景声约 **2.27 秒**开始淡入。切后 **2.35 秒**，耳鸣主频仍高于夜景同频约 **34 dB**，约 **2.50 秒**衰减至接近底噪。耳鸣强度与残响观感可用成片或独立音频摘录现场判断。另做了一次耳鸣已开始时的中断测试，已恢复操控、日间声源和玩具手持状态，转场请求为零。[切后包络实测](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R4/PIE_normal_1795260565574957100/CenteredTailAudio.json) · [中断回归](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R4/PIE_audiointerrupt_1795260639672473600/Timeline.json)

## 保存与观看

普通用户完成当前 Lighting 的 Win64 Development Editor 构建，退出码 0。保存了既有 Sequence 的右肩偏移轨、Sandbox 的 V3 音频实例值及专用混响预设。最终右肩相对右上臂向后 **58 cm**、向右 **7 cm**、向上 **7 cm**。镜头参数可在 Sequence 调整。失真提前量在 V3_ToyMatch 的 V3 Timing 设置，耳鸣音量、衰减曲线及夜景淡入在 PresentationAudio，室内衰减在 FX_V3_WetReverb。最终三份资产定点保存后均为干净状态。[实际写入值](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R4/AuthoredFinal.json) · [当前工程构建](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R4/UBT_Integrated_R4.txt) · [含用户定点保存的改前备份](../../Saved/YIXI_Archive/InteractionMultiAgent/V3_R4/Before/)

Sandbox 已停在教室双门前。按 **E** 开门后可从头体验。镜头和混音技术检查已完成，构图留量及声音感受由用户确认。
