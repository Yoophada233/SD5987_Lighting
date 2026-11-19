import unreal, math, json, pathlib, traceback, datetime
report=pathlib.Path('/tmp/waterresult.json')
try:
 actors=unreal.get_editor_subsystem(unreal.EditorActorSubsystem).get_all_level_actors(); live={a.get_actor_label():a for a in actors}
 world=unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem).get_editor_world()
 if 'L_YIXI_P04_StreamingMaster' not in world.get_name():raise RuntimeError('Open the YIXI P04 StreamingMaster map first')
 base='/Game/YIXI/Sequences/Trailer';name='LS_YIXI_Opening_WaterToNight_v04'
 if unreal.EditorAssetLibrary.does_asset_exist(base+'/'+name):name+='_'+datetime.datetime.now().strftime('%H%M%S')
 seq=unreal.AssetToolsHelpers.get_asset_tools().create_asset(name,base,unreal.LevelSequence,unreal.LevelSequenceFactoryNew())
 seq.set_display_rate(unreal.FrameRate(24,1));seq.set_playback_start(0);seq.set_playback_end(432)
 seq.set_view_range_start(0);seq.set_view_range_end(18);seq.set_work_range_start(0);seq.set_work_range_end(18)
 cuts=seq.add_track(unreal.MovieSceneCameraCutTrack);F=unreal.FrameNumber
 sub=unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
 def spawnrange(binding,start,end):
  tr=next((t for t in binding.get_tracks() if isinstance(t,unreal.MovieSceneSpawnTrack)),None)
  if tr is None:tr=binding.add_track(unreal.MovieSceneSpawnTrack)
  sections=tr.get_sections();sc=sections[0] if sections else tr.add_section();sc.set_range(start,end);sc.get_all_channels()[0].set_default(True)
 def camera(label,start,end,samples,focal=28,tint=False):
  temp=sub.spawn_actor_from_class(unreal.CineCameraActor,unreal.Vector(*samples[0][1]),unreal.Rotator(),True)
  cc=temp.get_cine_camera_component();fb=cc.filmback;fb.sensor_width=36.;fb.sensor_height=20.25;cc.filmback=fb
  cc.current_focal_length=float(focal);cc.current_aperture=8.
  focus=cc.focus_settings;focus.focus_method=unreal.CameraFocusMethod.DISABLE;cc.focus_settings=focus
  if tint:
   pp=cc.post_process_settings
   pp.set_editor_property('override_scene_color_tint',True);pp.set_editor_property('scene_color_tint',unreal.LinearColor(.25,.55,.62,1))
   pp.set_editor_property('override_vignette_intensity',True);pp.set_editor_property('vignette_intensity',.65)
   cc.post_process_settings=pp;cc.post_process_blend_weight=1.
  b=seq.add_spawnable_from_instance(temp);b.set_display_name(label);sub.destroy_actor(temp)
  spawnrange(b,start,end)
  sc=b.add_track(unreal.MovieScene3DTransformTrack).add_section();sc.set_range(start,end);chs=sc.get_all_channels()
  for frame,p,rot in samples:
   for ch,v in zip(chs,p+[rot[2],rot[0],rot[1]]+[1,1,1]):ch.add_key(F(frame),float(v),interpolation=unreal.MovieSceneKeyInterpolation.LINEAR)
  cut=cuts.add_section();cut.set_range(start,end);cut.set_camera_binding_id(seq.get_binding_id(b))
  return b
 # Constant yaw and no roll preserve the frontal composition throughout the descent.
 # The path lies above the existing large day pond (Plane2, surface Z=-60).
 p0=[-350,170,300];rot=[1.4,0,0]
 samples=[]
 for frame in [0,24,48,72,96,120,144,156,168,180,192,204,215]:
  t=max(0,min(1,(frame-48)/167));u=t*t*(3-2*t)
  z=300-480*u
  samples.append((frame,[-350,170,z],rot))
 t=119/167; z167=300-480*(t*t*(3-2*t))
 camera('01_DAY_Front_House_Descend_Into_Pond',0,168,[s for s in samples if s[0]<168]+[(167,[-350,170,z167],rot)],28)
 # Continue the identical path below water with a simple camera-only underwater grade.
 underwater=[s for s in samples if s[0]>=168]
 underwater.append((239,[-350,170,-180],rot))
 camera('02_UNDERWATER_Continue_Descent',168,240,underwater,28,True)
 night=live.get('NIGHT_DollMatchCamera')
 if night is None:raise RuntimeError('Night match camera missing')
 p=night.get_actor_location();rr=night.get_actor_rotation();nr=[rr.pitch,rr.yaw,rr.roll]
 fwd=[math.cos(math.radians(rr.pitch))*math.cos(math.radians(rr.yaw)),math.cos(math.radians(rr.pitch))*math.sin(math.radians(rr.yaw)),math.sin(math.radians(rr.pitch))]
 n0=[p.x,p.y,p.z];n1=[n0[i]-140*fwd[i]+(30 if i==2 else 0) for i in range(3)]
 camera('03_NIGHT_Reveal_After_Water_Cut',240,432,[(240,n0,nr),(264,n0,nr),(431,n1,nr)],28)
 for label,cls,dayv,nightv in [('YIXI_Seq_DirectionalLight',unreal.DirectionalLightComponent,6,.45),('YIXI_Seq_SkyLight',unreal.SkyLightComponent,.25,.12)]:
  a=live.get(label)
  if a is None:continue
  comp=a.get_component_by_class(cls);b=seq.add_possessable(comp);b.set_display_name('Lighting_'+label)
  tr=b.add_track(unreal.MovieSceneFloatTrack);tr.set_property_name_and_path('Intensity','Intensity');s=tr.add_section();s.set_range(0,432)
  for f,v in [(0,dayv),(239,dayv),(240,nightv),(431,nightv)]:s.get_all_channels()[0].add_key(F(f),float(v),interpolation=unreal.MovieSceneKeyInterpolation.CONSTANT)
  tr=b.add_track(unreal.MovieSceneColorTrack);tr.set_property_name_and_path('LightColor','LightColor');s=tr.add_section();s.set_range(0,432)
  for ch,d,n in zip(s.get_all_channels(),[1,.9,.76,1],[.3,.45,.8,1]):
   for f,v in [(0,d),(239,d),(240,n),(431,n)]:ch.add_key(F(f),float(v),interpolation=unreal.MovieSceneKeyInterpolation.CONSTANT)
 fade=seq.add_track(unreal.MovieSceneFadeTrack).add_section();fade.set_range(0,432)
 for f,v in [(0,0),(192,0),(224,1),(244,1),(264,0),(431,0)]:fade.get_all_channels()[0].add_key(F(f),float(v),interpolation=unreal.MovieSceneKeyInterpolation.LINEAR)
 for frame,label in [(0,'正对主屋'),(48,'开始下沉'),(168,'入水 / 水下调色'),(224,'水下遮蔽'),(240,'切入夜景'),(264,'夜景显现')]:
  m=unreal.MovieSceneMarkedFrame(frame_number=F(frame),label=label);seq.add_marked_frame(m)
 assert len(cuts.get_sections())==3
 assert seq.get_playback_end()==432
 if not unreal.EditorAssetLibrary.save_loaded_asset(seq):raise RuntimeError('Save failed')
 report.write_text(json.dumps({'status':'saved','asset':base+'/'+name,'duration':18,'water_surface_z':-60,'camera_start':p0,'camera_end':[-350,170,-180],'cuts':[[0,168],[168,240],[240,432]],'limitations':['Camera underwater grade and dark transition; no fluid simulation or sound added.','Night uses existing match camera; original 60-second sequence and maps not overwritten.']},ensure_ascii=False,indent=2))
 unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(seq)
 unreal.LevelSequenceEditorBlueprintLibrary.set_lock_camera_cut_to_viewport(True)
 unreal.LevelSequenceEditorBlueprintLibrary.set_current_time(0)
except Exception:
 report.write_text(json.dumps({'status':'error','trace':traceback.format_exc()},ensure_ascii=False,indent=2));unreal.log_error(traceback.format_exc())
