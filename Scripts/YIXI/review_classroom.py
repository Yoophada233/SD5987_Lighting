import unreal,pathlib,json,re
root=pathlib.Path(unreal.Paths.project_dir()).resolve();q=root/'Saved/YIXI_Classroom'
sub=unreal.get_editor_subsystem(unreal.EditorActorSubsystem);le=unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
actors=sub.get_all_level_actors();old=json.loads((q/'original_actors.json').read_text());now={(a.get_level().get_path_name(),a.get_name()):a for a in actors}
def values(s):
 if isinstance(s,list):return s
 s=re.sub(r'0x[0-9a-fA-F]+','PTR',s)
 return [float(x) for x in re.findall(r'[xyzw]: (-?\d+\.\d+)',s)]
diff=[]
for x in old:
 a=now.get((x['level'],x['name']))
 v=values(x['transform']);w=values(str(a.get_actor_transform())) if a else []
 if len(v)!=len(w) or any(abs(i-j)>0.0001 for i,j in zip(v,w)):diff.append({'name':x['name'],'old':v,'new':w})
f=[a for a in actors if 'YIXI_ClassroomFurniture_20261120' in [str(t) for t in a.tags]]
mode=json.loads((q/'action.json').read_text()).get('mode','review') if (q/'action.json').exists() else 'review'
if mode=='finalize':
 teacher=next(a for a in f if a.get_actor_label()=='YIXI_Class_TeacherDesk')
 mesh=unreal.load_asset('/Game/3DAssets/mesh/SM_table1_1_1005_mesh')
 teacher.get_component_by_class(unreal.StaticMeshComponent).set_static_mesh(mesh)
 teacher.set_actor_scale3d(unreal.Vector(1.1,1.1,1.1))
 teacher.set_actor_location(unreal.Vector(2350,120,129.25-mesh.get_bounding_box().min.z*1.1),False,False)
report={'source_count':len(old),'source_actor_changes':diff,'new_count':len(f),'new_actors':[{'label':a.get_actor_label(),'transform':str(a.get_actor_transform()),'bounds':str(a.get_actor_bounds(False))} for a in f]}
(q/'review.json').write_text(json.dumps(report,ensure_ascii=False,indent=2))
assert not diff,str(diff)
assert len(f)==14,len(f)
unreal.EditorLevelLibrary.set_level_viewport_camera_info(unreal.Vector(1390,-170,400),unreal.Rotator(pitch=-12,yaw=18,roll=0))
sub.set_selected_level_actors([])
for a in f:
 c,e=a.get_actor_bounds(False)
 assert abs(c.z-e.z-129.25)<.1,a.get_actor_label()
if mode in {'finalize','save'}:
 assert 'L_YIXI_P04_StreamingMaster' in le.get_current_level().get_path_name()
 assert le.save_current_level(),'Saving classroom map failed'
 report['saved']=True
 report['dirty_maps_after_save']=[x.get_path_name() for x in unreal.EditorLoadingAndSavingUtils.get_dirty_map_packages()]
 (q/'review.json').write_text(json.dumps(report,ensure_ascii=False,indent=2))
unreal.AutomationLibrary.take_high_res_screenshot(1280,720,str(q/'classroom_overview.png'))
