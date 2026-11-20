"""Project-local furniture inspection/task runner. Expires after 30 minutes."""
import unreal,pathlib,time,json,traceback,runpy
unreal.EditorPythonScripting.set_keep_python_script_alive(True)
project=pathlib.Path(unreal.Paths.project_dir()).resolve()
assert project.name=='SD5987_Lighting',str(project)
queue=project/'Saved/YIXI_Classroom';queue.mkdir(parents=True,exist_ok=True)
allowed={'inspect_classroom.py','place_classroom_furniture.py','review_classroom.py'}
state={'start':time.monotonic(),'last':None,'handle':None}
def tick(dt):
 if time.monotonic()-state['start']>1800:
  unreal.unregister_slate_post_tick_callback(state['handle']);return
 if time.monotonic()-state['start']<12:return
 try:
  job=json.loads((queue/'job.json').read_text())
  if job['id']==state['last']:return
  state['last']=job['id'];assert job['script'] in allowed
  runpy.run_path(str(project/'Scripts/YIXI'/job['script']))
  result={'id':job['id'],'status':'complete'}
 except Exception:result={'id':state['last'],'status':'error','trace':traceback.format_exc()}
 (queue/'job_result.json').write_text(json.dumps(result,indent=2))
state['handle']=unreal.register_slate_post_tick_callback(tick)
(queue/'job.json').write_text(json.dumps({'id':'inspect_'+str(time.time_ns()),'script':'inspect_classroom.py'}))
(queue/'connection.json').write_text(json.dumps({'status':'active','started':time.time()}))
