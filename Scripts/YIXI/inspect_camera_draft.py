import unreal,json,pathlib,traceback
out=pathlib.Path(unreal.Paths.project_dir())/'Saved/YIXI_CameraDraft/inspection.json'
try:
 seq=unreal.load_asset('/Game/YIXI/Sequences/Trailer/LS_YIXI_60s_v03a_Day_F_Night')
 data=[]
 for b in seq.get_bindings():
  t=b.get_object_template()
  item={'name':b.get_display_name(),'template':str(t),'tracks':[]}
  if t and isinstance(t,unreal.CineCameraActor):
   cc=t.get_cine_camera_component();item['focal']=cc.current_focal_length
  for tr in b.get_tracks():
   if isinstance(tr,unreal.MovieScene3DTransformTrack):
    for sc in tr.get_sections():
     item['tracks'].append([[{'frame':k.get_time().frame_number.value,'v':k.get_value()} for k in ch.get_keys()] for ch in sc.get_all_channels()])
  data.append(item)
 out.write_text(json.dumps({'status':'ok','bindings':data},ensure_ascii=False,indent=2))
except Exception:out.write_text(json.dumps({'error':traceback.format_exc()}))
