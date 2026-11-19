"""Temporary camera location survey. Saves images/actor metadata, never assets/maps."""
import unreal,pathlib,json,math,time,datetime,traceback
root=pathlib.Path(unreal.Paths.project_dir()).resolve();folder=root/'Saved/YIXI_CameraReview'/datetime.datetime.now().strftime('%Y%m%d_%H%M%S');folder.mkdir(parents=True)
sub=unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
seq=unreal.LevelSequenceEditorBlueprintLibrary.get_current_level_sequence()
if seq:unreal.LevelSequenceEditorBlueprintLibrary.close_level_sequence()
data=[]
for a in sub.get_all_level_actors():
 try:
  p=a.get_actor_location();r=a.get_actor_rotation();o,e=a.get_actor_bounds(False)
  if -3000<p.x<3500 and -2500<p.y<4000:
   data.append({'name':a.get_actor_label(),'class':a.get_class().get_name(),'p':[p.x,p.y,p.z],'r':[r.pitch,r.yaw,r.roll],'bounds':[[o.x,o.y,o.z],[e.x,e.y,e.z]]})
 except Exception:pass
(folder/'actors.json').write_text(json.dumps(data,ensure_ascii=False,indent=2))
views=[
 ('Hut_approach',[-850,900,260],[-1250,1550,240]),
 ('Hut_front',[-1300,950,270],[-1300,1700,250]),
 ('Hut_inside_south',[-1210,1850,250],[-1210,1400,170]),
 ('Hut_inside_north',[-1210,1850,250],[-1210,2200,160]),
 ('Hut_inside_east',[-1210,1850,250],[-650,1850,150]),
 ('Hut_inside_west',[-1210,1850,250],[-1750,1850,150]),
 ('Hut_westbay',[-1750,1800,240],[-1750,2150,150]),
 ('Hut_eastbay',[-750,1800,240],[-750,2150,150]),
 ('Hut_east_back',[-750,2100,240],[-750,1600,150]),
 ('Girl_near_hut',[-650,900,250],[-1040,1130,150]),
 ('Bridge_start',[170,1398,270],[-830,932,250]),
 ('Bridge_center',[-329,1166,310],[-830,932,250]),
 ('Bridge_end',[-830,932,250],[-1200,1350,230]),
 ('Porch_gate',[1120,700,280],[-2195,430,280])]
survey={'i':0,'phase':'open','since':time.monotonic(),'camera':None,'images':[],'task':None,'handle':None}
def done(error=None):
 unreal.unregister_slate_post_tick_callback(survey['handle'])
 if survey['camera']:sub.destroy_actor(survey['camera'])
 if seq:unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(seq)
 result={'status':'error' if error else 'complete','error':error,'folder':str(folder),'images':survey['images']}
 (root/'Saved/YIXI_CameraReview/survey_result.json').write_text(json.dumps(result,ensure_ascii=False,indent=2))
def tick(dt):
 try:
  now=time.monotonic()
  if survey['i']>=len(views):done();return
  label,p,t=views[survey['i']];image=folder/(label+'.png')
  if survey['phase']=='open':
   d=[t[j]-p[j] for j in range(3)];rot=unreal.Rotator(pitch=math.degrees(math.atan2(d[2],math.hypot(d[0],d[1]))),yaw=math.degrees(math.atan2(d[1],d[0])),roll=0.)
   a=sub.spawn_actor_from_class(unreal.CineCameraActor,unreal.Vector(*p),rot,True);survey['camera']=a
   cc=a.get_cine_camera_component();fb=cc.filmback;fb.sensor_width=36.;fb.sensor_height=20.25;cc.filmback=fb;cc.current_focal_length=24.
   focus=cc.focus_settings;focus.focus_method=unreal.CameraFocusMethod.DISABLE;cc.focus_settings=focus
   survey['task']=unreal.AutomationLibrary.take_high_res_screenshot(1280,720,str(image),a,delay=1.)
   survey['since']=now;survey['phase']='capture'
  elif survey['phase']=='capture':
   if image.exists() and image.stat().st_size>0 and now-survey['since']>1.5:
    sub.destroy_actor(survey['camera']);survey['camera']=None;survey['images'].append(str(image));survey['i']+=1;survey['phase']='open'
   elif now-survey['since']>35:raise RuntimeError('Capture timeout '+label)
 except Exception:done(traceback.format_exc())
survey['handle']=unreal.register_slate_post_tick_callback(tick)
