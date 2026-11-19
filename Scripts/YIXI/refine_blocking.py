"""YIXI SH03-09 camera blocking. Run inside the open P04 editor, not system Python.
Creates independent spawnable cameras/sequences only. Does not save maps.
Characters/toy are intentionally absent; positions below are provisional blocking.
"""
import unreal,math,json,pathlib,datetime,traceback
ROOT=pathlib.Path(unreal.Paths.project_dir())
REPORT=ROOT/'Saved/YIXI_CameraDraft/refine_result.json'
REPORT.parent.mkdir(parents=True,exist_ok=True)
FPS=24
F=unreal.FrameNumber

def look(p,t):
 d=[t[i]-p[i] for i in range(3)]
 return [math.degrees(math.atan2(d[2],math.hypot(d[0],d[1]))),math.degrees(math.atan2(d[1],d[0])),0.]

def run():
 world=unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem).get_editor_world()
 if world.get_name()!='L_YIXI_P04_StreamingMaster':raise RuntimeError('Open L_YIXI_P04_StreamingMaster; no maps will be loaded or saved by this script.')
 sub=unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
 live={a.get_actor_label():a for a in sub.get_all_level_actors()}
 if 'DAY_DollMatchCamera' not in live:raise RuntimeError('Day reference camera missing; check loaded sublevels.')
 # World-space blocking from the previous actor survey. The editor preview must be
 # reviewed for doorway clearance and bridge deck height before calling this final.
 girl=[-1040.,1130.,190.]
 specs=[
 ('SH03_Classroom',6,[1100,-65,280],[1180,-30,280],[1900,150,220],[1900,150,220],35,0.,'学生预留在主屋内；门外观看课堂'),
 ('SH04_Gate',5,[1120,500,280],[1120,850,280],[-2195,430,280],[-2195,430,280],28,1.,'第一人称离开课堂；朝院门方向；路径待预览核对'),
 ('SH05_Student',6,[100,1330,350],[60,1305,350],girl,girl,45,0.,'小女孩预留在桥后小屋外；结尾看向小屋门'),
 ('SH06_Bridge',5,[170,1398,250],[-830,932,250],[-1100,1000,260],[-1515,1450,270],28,1.,'过桥轻微步伐；桥面高度与净空待预览'),
 ('SH07_Toy',6,[-1515,1550,240],[-1515,1670,220],[-1515,1900,150],[-1515,1900,150],55,0.,'小屋内桌面玩具预留位置；尚无实际玩具'),
 ('SH08_Return',5,[60,1305,350],[60,1305,350],girl,[-1210,1230,110],35,0.,'回到看见女孩的位置；空位停顿后寻找'),
 ('SH09_StudentReveal',5,[-720,1050,220],[-825,1060,220],[-1040,1130,65],[-1040,1130,65],40,0.,'倒地女孩预留位置；先缓移再停住；遮挡待预览')]
 stamp=datetime.datetime.now().strftime('%Y%m%d_%H%M%S')
 base='/Game/YIXI/Sequences/Trailer/CameraDraft_v03_'+stamp
 tools=unreal.AssetToolsHelpers.get_asset_tools()
 created=[]
 def sequence(name,duration):
  sq=tools.create_asset(name,base,unreal.LevelSequence,unreal.LevelSequenceFactoryNew())
  if not sq:raise RuntimeError('Could not create '+name)
  sq.set_display_rate(unreal.FrameRate(FPS,1));sq.set_playback_start(0);sq.set_playback_end(round(duration*FPS))
  sq.set_view_range_start(0);sq.set_view_range_end(duration);sq.set_work_range_start(0);sq.set_work_range_end(duration)
  created.append(sq)
  return sq
 def lighting(sq,n):
  for label,cls,value in [('YIXI_Seq_DirectionalLight',unreal.DirectionalLightComponent,6.),('YIXI_Seq_SkyLight',unreal.SkyLightComponent,.25)]:
   a=live.get(label)
   if not a:continue
   c=a.get_component_by_class(cls)
   if not c:continue
   b=sq.add_possessable(c);b.set_display_name('DAY preview '+label)
   tr=b.add_track(unreal.MovieSceneFloatTrack);tr.set_property_name_and_path('Intensity','Intensity')
   sec=tr.add_section();sec.set_range(0,n);sec.get_all_channels()[0].set_default(value)
   tr=b.add_track(unreal.MovieSceneColorTrack);tr.set_property_name_and_path('LightColor','LightColor')
   sec=tr.add_section();sec.set_range(0,n)
   for ch,v in zip(sec.get_all_channels(),[1.,.9,.76,1.]):ch.set_default(v)
 def camera(sq,spec):
  name,dur,p0,p1,t0,t1,focal,walk,note=spec;n=round(dur*FPS)
  tmp=sub.spawn_actor_from_class(unreal.CineCameraActor,unreal.Vector(*p0),unreal.Rotator(),True)
  if tmp is None:raise RuntimeError('Could not create temporary camera')
  try:
   cc=tmp.get_cine_camera_component();fb=cc.filmback;fb.sensor_width=36.;fb.sensor_height=20.25;cc.filmback=fb
   cc.current_focal_length=float(focal);cc.current_aperture=8.
   focus=cc.focus_settings;focus.focus_method=unreal.CameraFocusMethod.DISABLE;cc.focus_settings=focus
   b=sq.add_spawnable_from_instance(tmp);b.set_display_name(name+' | '+note)
  finally:sub.destroy_actor(tmp)
  tr=next((x for x in b.get_tracks() if isinstance(x,unreal.MovieSceneSpawnTrack)),None)
  if tr is None:tr=b.add_track(unreal.MovieSceneSpawnTrack)
  ss=tr.get_sections()[0] if tr.get_sections() else tr.add_section();ss.set_range(0,n);ss.get_all_channels()[0].set_default(True)
  sc=b.add_track(unreal.MovieScene3DTransformTrack).add_section();sc.set_range(0,n);chs=sc.get_all_channels()
  frames=sorted(set(list(range(0,n,3))+[n-1]))
  for f in frames:
   t=f/(n-1);u=t
   if name.startswith('SH08'):u=max(0.,(t-.30)/.70);u=u*u*(3-2*u)
   if name.startswith('SH09'):u=min(1.,t/.60);u=u*u*(3-2*u)
   p=[p0[i]+(p1[i]-p0[i])*u for i in range(3)]
   target=[t0[i]+(t1[i]-t0[i])*u for i in range(3)]
   if name.startswith('SH05') and t>.75:
    v=(t-.75)/.25;target=[girl[i]+([-1515,1450,270][i]-girl[i])*v for i in range(3)]
   if name.startswith('SH06'):p[2]+=80*math.sin(math.pi*u)
   rot=look(p,target)
   if walk:
    phase=2*math.pi*1.6*f/FPS;env=math.sin(math.pi*t)**.5
    yaw=math.radians(rot[1]);sway=.65*math.sin(phase/2)*env
    p[0]+=-math.sin(yaw)*sway;p[1]+=math.cos(yaw)*sway;p[2]+=.9*math.sin(phase)*env
    rot[0]+=.12*math.sin(phase)*env;rot[2]=.22*math.sin(phase/2)*env
   for ch,v in zip(chs,p+[rot[2],rot[0],rot[1]]+[1.,1.,1.]):ch.add_key(F(f),float(v),interpolation=unreal.MovieSceneKeyInterpolation.LINEAR)
  cut=sq.add_track(unreal.MovieSceneCameraCutTrack).add_section();cut.set_range(0,n);cut.set_camera_binding_id(sq.get_binding_id(b))
  lighting(sq,n)
  for frame,label in [(0,note),(n-1,'草稿：人物、道具、遮挡与碰撞待核对')]:sq.add_marked_frame(unreal.MovieSceneMarkedFrame(frame_number=F(frame),label=label))
  if not unreal.EditorAssetLibrary.save_loaded_asset(sq):raise RuntimeError('Failed to save '+name)
  return {'asset':sq.get_path_name(),'duration':dur,'focal_mm':focal,'walk':bool(walk),'note':note,'start':p0,'end':p1}
 results=[]
 for spec in specs:
  sq=sequence('SEQ_YIXI_'+spec[0],spec[1]);results.append(camera(sq,spec))
 master=sequence('SEQ_YIXI_SH03_09_Blocking_Preview',38)
 track=master.add_track(unreal.MovieSceneCinematicShotTrack);offset=0
 for sq,spec in zip(created[:-1],specs):
  sec=track.add_section();sec.set_sequence(sq);sec.set_range(offset,offset+spec[1]*FPS);offset+=spec[1]*FPS
 master.add_marked_frame(unreal.MovieSceneMarkedFrame(frame_number=F(0),label='接在现有开场之后；本预览不含开场、闪回及片名'))
 if not unreal.EditorAssetLibrary.save_loaded_asset(master):raise RuntimeError('Master save failed')
 REPORT.write_text(json.dumps({'status':'saved','folder':base,'preview':master.get_path_name(),'shots':results,'limitations':['Camera blocking only; no character or toy assets added.','No maps or existing assets saved.','SH10-11 need day/night framing survey; not generated here.','Doorway clearance, bridge height, hut interior and reveal occluder require visual verification.']},ensure_ascii=False,indent=2))
 unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(master)
 unreal.LevelSequenceEditorBlueprintLibrary.set_lock_camera_cut_to_viewport(True)
 unreal.LevelSequenceEditorBlueprintLibrary.set_current_time(0)
try:
 run()
 YIXI_CAPTURE_REPORT='refine_result.json'
 capture=ROOT/'Scripts/YIXI/capture_draft.py'
 exec(compile(capture.read_text(),str(capture),'exec'),globals())
except Exception:
 REPORT.write_text(json.dumps({'status':'error','trace':traceback.format_exc()},ensure_ascii=False,indent=2));unreal.log_error(traceback.format_exc())
