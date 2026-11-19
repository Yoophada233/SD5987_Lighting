"""YIXI SH03-09 camera blocking. Run inside the open P04 editor, not system Python.
Creates independent spawnable cameras/sequences only. Does not save maps.
Characters/toy are intentionally absent; positions below are provisional blocking.
"""
import unreal,math,json,pathlib,datetime,traceback
ROOT=pathlib.Path(unreal.Paths.project_dir()).resolve()
REPORT=ROOT/'Saved/YIXI_CameraDraft/working_result.json'
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
 girl=[-1040.,1130.,165.]
 specs=[
 ('SH03_Classroom',6,[1100,-65,280],[1180,-30,280],[1900,150,220],[1900,150,220],35,0.,'课堂：保留原门窗遮挡，只露局部学生'),
 ('SH04_Gate',5,[1100,700,280],[1100,700,280],[-2195,430,280],[-2100,360,280],32,0.,'战争预兆：廊下停住听远处声音；不悬空跨池塘'),
 ('SH05_Student',6,[-650,900,230],[-680,930,230],girl,girl,35,0.,'小屋外女孩预留位置；静看，再看向小屋'),
 ('SH06_Bridge',5,[0,1319,275],[-680,1002,255],[-1100,806,265],[-1780,489,245],28,1.,'沿桥轴线行走；不向门板急转头'),
 ('SH07_Toy',6,[-1210,1840,240],[-1210,1910,220],[-1210,2100,145],[-1210,2100,145],40,0.,'屋内玩具预留空地；尚无玩具或桌面资产'),
 ('SH08_Return',5,[-680,930,230],[-680,930,230],girl,[-1120,1160,90],35,0.,'回到同一女孩机位：先看空位，再缓慢寻找'),
 ('SH09_StudentReveal',5,[-650,900,230],[-750,900,220],[-1040,1130,70],[-1040,1130,70],35,0.,'女孩倒地预留位置；缓移后停住，不添加人物')]
 stamp=datetime.datetime.now().strftime('%Y%m%d_%H%M%S')
 base='/Game/YIXI/Sequences/Trailer/Working/Shots'
 if unreal.EditorAssetLibrary.does_asset_exist(base+'/SEQ_YIXI_SH03_Classroom'):raise RuntimeError('Working shots already exist; refusing duplicate generation')
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
    v=(t-.75)/.25;target=[girl[i]+([-1300,1700,230][i]-girl[i])*v for i in range(3)]
   if name.startswith('SH06'):p[2]+=35*math.sin(math.pi*u)
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
  unreal.LevelSequenceEditorBlueprintLibrary.refresh_current_level_sequence()
  if not unreal.EditorAssetLibrary.save_loaded_asset(sq):raise RuntimeError('Failed to save '+name)
  return {'asset':sq.get_path_name(),'duration':dur,'focal_mm':focal,'walk':bool(walk),'note':note,'start':p0,'end':p1}
 results=[]
 for spec in specs:
  sq=sequence('SEQ_YIXI_'+spec[0],spec[1]);results.append(camera(sq,spec))
 master=sequence('SEQ_YIXI_00_PlayThis',38)
 track=master.add_track(unreal.MovieSceneCinematicShotTrack);offset=0
 for sq,spec in zip(created[:-1],specs):
  sec=track.add_section();sec.set_sequence(sq);sec.set_range(offset,offset+spec[1]*FPS);sec.set_shot_display_name(spec[0]);offset+=spec[1]*FPS
 master.add_marked_frame(unreal.MovieSceneMarkedFrame(frame_number=F(0),label='接在现有开场之后；本预览不含开场、闪回及片名'))
 if not unreal.EditorAssetLibrary.save_loaded_asset(master):raise RuntimeError('Master save failed')
 if not unreal.EditorAssetLibrary.rename_asset(master.get_path_name().split('.')[0],'/Game/YIXI/Sequences/Trailer/Working/SEQ_YIXI_00_PlayThis'):raise RuntimeError('Preview organization failed')
 REPORT.write_text(json.dumps({'status':'saved','folder':base,'preview':master.get_path_name(),'shots':results,'limitations':['Camera blocking only; no character or toy assets added.','No maps or existing assets saved.','SH10-11 need day/night framing survey; not generated here.','Doorway clearance, bridge height, hut interior and reveal occluder require visual verification.']},ensure_ascii=False,indent=2))
 unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(master)
 unreal.LevelSequenceEditorBlueprintLibrary.set_lock_camera_cut_to_viewport(True)
 unreal.LevelSequenceEditorBlueprintLibrary.set_current_time(0)
try:
 saved=json.loads(REPORT.read_text())
 item=next(x for x in saved['shots'] if 'SH07_Toy.' in x['asset'])
 sq=unreal.load_asset(item['asset'])
 b=next(b for b in sq.get_bindings() if str(b.get_display_name()).startswith('SH07_Toy'))
 sec=next(t for t in b.get_tracks() if isinstance(t,unreal.MovieScene3DTransformTrack)).get_sections()[0]
 p0=[-900,1800,310];p1=[-950,1820,300];target=[-1350,1990,180]
 for ci,ch in enumerate(sec.get_all_channels()):
  for k in ch.get_keys():
   u=k.get_time().frame_number.value/143
   p=[p0[j]+(p1[j]-p0[j])*u for j in range(3)]
   r=look(p,target)
   k.set_value(float((p+[r[2],r[0],r[1]]+[1,1,1])[ci]))
 unreal.LevelSequenceEditorBlueprintLibrary.refresh_current_level_sequence()
 if not unreal.EditorAssetLibrary.save_loaded_asset(sq):raise RuntimeError('Toy camera save failed')
 item.update(start=p0,end=p1,target=target)
 REPORT.write_text(json.dumps(saved,ensure_ascii=False,indent=2))
 (ROOT/'Saved/YIXI_CameraReview/toy_patch.json').write_text(json.dumps({'status':'saved','asset':sq.get_path_name(),'target':target}))
except Exception:
 (ROOT/'Saved/YIXI_CameraReview/toy_patch.json').write_text(json.dumps({'status':'error','trace':traceback.format_exc()}))
 unreal.log_error(traceback.format_exc())
