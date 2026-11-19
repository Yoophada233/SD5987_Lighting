import unreal,math,json,pathlib,datetime,traceback
try:
 source=unreal.LevelSequenceEditorBlueprintLibrary.get_current_level_sequence()
 if not source or not source.get_name().startswith('LS_YIXI_Opening_WaterToNight'):source=unreal.load_asset('/Game/YIXI/Sequences/Trailer/LS_YIXI_Opening_WaterToNight_v04')
 base='/Game/YIXI/Sequences/Trailer';name='LS_YIXI_Opening_WaterToCastle_v05'
 if unreal.EditorAssetLibrary.does_asset_exist(base+'/'+name):name+='_'+datetime.datetime.now().strftime('%H%M%S')
 seq=unreal.AssetToolsHelpers.get_asset_tools().duplicate_asset(name,base,source)
 for b in seq.get_bindings():
  label=str(b.get_display_name())
  if label.startswith('03_NIGHT'):
   b.set_display_name('03_NIGHT_Burning_CityWall_Grand_Wide')
   template=b.get_object_template()
   if template and template.get_cine_camera_component():template.get_cine_camera_component().set_editor_property('current_focal_length',24.)
   for tr in b.get_tracks():
    if isinstance(tr,unreal.MovieScene3DTransformTrack):
     chs=tr.get_sections()[0].get_all_channels()
     for ch in chs:
      for k in ch.get_keys():ch.remove_key(k)
     target=[-3500,207500,5000]
     for f,p in [(240,[-22000,232000,8500]),(264,[-22000,232000,8500]),(431,[-23200,233600,9000])]:
      d=[target[i]-p[i] for i in range(3)];pitch=math.degrees(math.atan2(d[2],math.hypot(d[0],d[1])));yaw=math.degrees(math.atan2(d[1],d[0]))
      for ch,v in zip(chs,p+[0,pitch,yaw]+[1,1,1]):ch.add_key(unreal.FrameNumber(f),float(v),interpolation=unreal.MovieSceneKeyInterpolation.LINEAR)
  if label in ['NIGHT_Courtyard_Flame','NIGHT_Fire_Glow']:
   for tr in b.get_tracks():
    if isinstance(tr,unreal.MovieSceneSpawnTrack):
     for s in tr.get_sections():
      ch=s.get_all_channels()[0]
      for k in ch.get_keys():ch.remove_key(k)
      ch.set_default(False)
 unreal.EditorAssetLibrary.save_loaded_asset(seq)
 unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(seq)
 unreal.LevelSequenceEditorBlueprintLibrary.set_lock_camera_cut_to_viewport(True)
 unreal.LevelSequenceEditorBlueprintLibrary.set_current_time(300)
 unreal.EditorLevelLibrary.editor_set_game_view(True)
 pathlib.Path('/tmp/castleresult.json').write_text(json.dumps({'saved':True,'asset':base+'/'+name,'focal_mm':24,'position':[-22000,232000,8500],'target':[-3500,207500,5000]},indent=2))
except Exception:
 pathlib.Path('/tmp/castleresult.json').write_text(json.dumps({'saved':False,'error':traceback.format_exc()}));unreal.log_error(traceback.format_exc())
