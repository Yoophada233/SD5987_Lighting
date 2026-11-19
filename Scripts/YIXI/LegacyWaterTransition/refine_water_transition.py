import unreal,json,pathlib
seq=unreal.LevelSequenceEditorBlueprintLibrary.get_current_level_sequence()
assert seq and seq.get_name().startswith('LS_YIXI_Opening_WaterToNight_v04')
for t in seq.get_tracks():
 if isinstance(t,unreal.MovieSceneFadeTrack):
  ch=t.get_sections()[0].get_all_channels()[0]
  for k in ch.get_keys():ch.remove_key(k)
  for f,v in [(0,0),(140,0),(160,.55),(168,.85),(180,1),(244,1),(264,0),(431,0)]:ch.add_key(unreal.FrameNumber(f),float(v),interpolation=unreal.MovieSceneKeyInterpolation.LINEAR)
if hasattr(unreal.EditorLevelLibrary,'editor_set_game_view'):unreal.EditorLevelLibrary.editor_set_game_view(True)
unreal.EditorAssetLibrary.save_loaded_asset(seq)
unreal.LevelSequenceEditorBlueprintLibrary.set_current_time(300)
pathlib.Path('/tmp/refined.json').write_text(json.dumps({'saved':True,'gameview_supported':hasattr(unreal.EditorLevelLibrary,'editor_set_game_view')}))
