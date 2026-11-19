"""Capture current draft framing without editing/saving cameras, models or maps.
Run in Unreal's Cmd: py <absolute path to this file>.
"""
import unreal,pathlib,json,time,traceback,datetime
root=pathlib.Path(unreal.Paths.project_dir()).resolve()
report=json.loads((root/'Saved/YIXI_CameraDraft'/globals().get('YIXI_CAPTURE_REPORT','build_result.json')).read_text())
folder=root/'Saved/YIXI_CameraDraft'/('Frames_'+datetime.datetime.now().strftime('%Y%m%d_%H%M%S'))
folder.mkdir(parents=True,exist_ok=False)
previous=unreal.LevelSequenceEditorBlueprintLibrary.get_current_level_sequence()
work=[]
for item in report['shots']:
 name=item['asset'].split('.')[-1]
 for label,frame in [('start',0),('middle',int(item['duration']*12)),('end',int(item['duration']*24)-1)]:
  work.append({'asset':item['asset'],'frame':frame,'image':str(folder/(name+'_'+label+'.png'))})
state={'index':0,'phase':'open','since':time.monotonic(),'completed':[],'task':None,'handle':None}
def finish(error=None):
 unreal.unregister_slate_post_tick_callback(state['handle'])
 if previous:
  unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(previous)
  unreal.LevelSequenceEditorBlueprintLibrary.set_current_time(0)
 (root/'Saved/YIXI_CameraDraft/capture_result.json').write_text(json.dumps({'status':'error' if error else 'complete','error':error,'folder':str(folder),'images':state['completed']},ensure_ascii=False,indent=2))
 unreal.log('YIXI framing capture finished: '+str(folder))
def tick(dt):
 try:
  now=time.monotonic()
  if state['index']>=len(work):finish();return
  item=work[state['index']]
  if state['phase']=='open':
   sq=unreal.load_asset(item['asset'])
   unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(sq)
   unreal.LevelSequenceEditorBlueprintLibrary.set_lock_camera_cut_to_viewport(True)
   unreal.LevelSequenceEditorBlueprintLibrary.set_current_time(item['frame'])
   state['since']=now;state['phase']='settle'
  elif state['phase']=='settle' and now-state['since']>1.2:
   state['task']=unreal.AutomationLibrary.take_high_res_screenshot(1280,720,item['image'])
   state['since']=now;state['phase']='capture'
  elif state['phase']=='capture':
   p=pathlib.Path(item['image'])
   if p.exists() and p.stat().st_size>0 and now-state['since']>.5:
    state['completed'].append(item);state['index']+=1;state['phase']='open';state['task']=None
   elif now-state['since']>25:raise RuntimeError('Screenshot timed out: '+str(p))
 except Exception:finish(traceback.format_exc())
state['handle']=unreal.register_slate_post_tick_callback(tick)
unreal.log('YIXI: capturing 21 reference frames; wait until finished before operating the timeline. No assets will be saved.')
