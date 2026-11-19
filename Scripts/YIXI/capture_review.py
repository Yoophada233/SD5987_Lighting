"""Pose a single Working shot for direct editor inspection; no asset edits."""
import unreal,pathlib,json,__main__
root=pathlib.Path(unreal.Paths.project_dir()).resolve();q=root/'Saved/YIXI_CameraReview'
main_bridge=getattr(__main__,'bridge',None)
cancelled=False
if main_bridge:
 prior=main_bridge.get('namespace') or {};old=prior.get('state')
 if isinstance(old,dict) and old.get('handle'):
  unreal.unregister_slate_post_tick_callback(old['handle']);cancelled=True
spec=json.loads((q/'pose.json').read_text())
report=json.loads((root/'Saved/YIXI_CameraDraft/working_result.json').read_text())
if spec['shot']=='PREVIEW':
 seq=unreal.load_asset(report['preview']);shot_asset=report['preview']
else:
 shot=next(s for s in report['shots'] if spec['shot'] in s['asset'])
 seq=unreal.load_asset(shot['asset']);shot_asset=shot['asset']
unreal.LevelSequenceEditorBlueprintLibrary.close_level_sequence()
unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(seq)
unreal.LevelSequenceEditorBlueprintLibrary.set_lock_camera_cut_to_viewport(True)
unreal.LevelSequenceEditorBlueprintLibrary.set_current_time(int(spec.get('frame',0)))
master=unreal.load_asset(report['preview'])
tracks=[t for t in master.get_tracks() if isinstance(t,unreal.MovieSceneCinematicShotTrack)]
assert len(tracks)==1 and len(tracks[0].get_sections())==7,'Expected seven shots in preview'
assert master.get_playback_end()==912,'Expected 38-second preview at 24 fps'
for item in report['shots']:
 sq=unreal.load_asset(item['asset'])
 cuts=[t for t in sq.get_tracks() if isinstance(t,unreal.MovieSceneCameraCutTrack)]
 assert len(cuts)==1 and len(cuts[0].get_sections())==1,'Expected one camera cut per shot'
assert unreal.EditorAssetLibrary.does_asset_exist('/Game/YIXI/Sequences/Trailer/LS_YIXI_Opening_WaterToCastle_v05')
(q/'pose_result.json').write_text(json.dumps({'status':'ready','shot':shot_asset,'structural_checks':'passed: seven shots, 38 seconds, camera cuts present, original opening exists','last_toy_visual_check':'pending: Mac locked'},ensure_ascii=False,indent=2))
