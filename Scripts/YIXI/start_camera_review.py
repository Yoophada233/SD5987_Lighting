"""Temporary, project-local camera review connection. No network or startup changes.
Allows only named camera task scripts from this project's Scripts/YIXI directory.
Ends after 30 minutes, on editor exit, or when stop_review is created below.
"""
import unreal,pathlib,time,json,traceback,runpy
project=pathlib.Path(unreal.Paths.project_dir()).resolve()
if project.name!='SD5987_Lighting':raise RuntimeError('Unexpected project; review not started')
queue=project/'Saved/YIXI_CameraReview';queue.mkdir(parents=True,exist_ok=True)
allowed={'survey_layout.py','organize_cameras.py','rebuild_cameras.py','capture_review.py'}
bridge={'start':time.monotonic(),'last':None,'handle':None,'namespace':None}
def review_tick(dt):
 if time.monotonic()-bridge['start']>1800 or (queue/'stop_review').exists():
  unreal.unregister_slate_post_tick_callback(bridge['handle']);(queue/'connection.json').write_text(json.dumps({'status':'stopped'}));return
 p=queue/'job.json'
 if not p.exists():return
 try:
  job=json.loads(p.read_text());token=job['id']
  if token==bridge['last']:return
  bridge['last']=token;name=job['script']
  if name not in allowed:raise RuntimeError('Script not allowed')
  bridge['namespace']=runpy.run_path(str(project/'Scripts/YIXI'/name))
  result={'id':token,'status':'started','script':name}
 except Exception:result={'status':'error','trace':traceback.format_exc()}
 (queue/'job_result.json').write_text(json.dumps(result,ensure_ascii=False,indent=2))
bridge['handle']=unreal.register_slate_post_tick_callback(review_tick)
(queue/'connection.json').write_text(json.dumps({'status':'active','expires_in_minutes':30,'project':str(project)}))
(queue/'job.json').write_text(json.dumps({'id':'initial_survey_'+str(time.time_ns()),'script':'rebuild_cameras.py'}))
unreal.log('YIXI: temporary camera survey started. No models, source cameras or maps will be saved.')
