"""Add classroom furniture only; leave original actors unchanged. Does not save maps."""
import unreal,pathlib,json,shutil,datetime,re
root=pathlib.Path(unreal.Paths.project_dir()).resolve();q=root/'Saved/YIXI_Classroom'
sub=unreal.get_editor_subsystem(unreal.EditorActorSubsystem);le=unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
actors=sub.get_all_level_actors();tag='YIXI_ClassroomFurniture_20261120'
assert not any(tag in [str(t) for t in a.tags] for a in actors),'Furniture already exists; inspect before rerunning'
assert not unreal.EditorLoadingAndSavingUtils.get_dirty_map_packages(),'Map has existing unsaved changes; stop to protect them'
level=le.get_current_level();assert 'L_YIXI_P04_StreamingMaster' in level.get_path_name()
backup=root/'Saved/YIXI_Archive'/datetime.datetime.now().strftime('%Y-%m-%d')/'Before_ClassroomFurniture'
backup.mkdir(parents=True,exist_ok=True)
src=root/'Content/YIXI/Tests/P04/Maps/L_YIXI_P04_StreamingMaster.umap'
assert not (backup/src.name).exists(),'Backup exists; do not replace'
shutil.copy2(src,backup/src.name)
def snapshot(a):
 t=re.sub(r'0x[0-9a-fA-F]+','PTR',str(a.get_actor_transform()))
 return {'name':a.get_name(),'transform':[float(x) for x in re.findall(r'[xyzw]: (-?\d+\.\d+)',t)],'level':a.get_level().get_path_name()}
(q/'original_actors.json').write_text(json.dumps([snapshot(a) for a in actors],ensure_ascii=False,indent=2))
created=[];floor=129.25
meshes={k:unreal.load_asset('/Game/3DAssets/mesh/'+v) for k,v in {'desk':'SM_table1_1_1005_mesh','teacher':'SM_table2_1_1014_mesh','stool':'SM_chair2_1_1023_hd_p_prefab'}.items()}
assert all(meshes.values())
def add(kind,label,x,y,scale,yaw=0):
 m=meshes[kind];z=floor-m.get_bounding_box().min.z*scale
 a=sub.spawn_actor_from_object(m,unreal.Vector(x,y,z),unreal.Rotator(pitch=0,yaw=yaw,roll=0),False)
 assert a and a.get_level()==level
 a.set_actor_scale3d(unreal.Vector(scale,scale,scale));a.set_actor_label(label)
 a.set_folder_path('YIXI/Classroom/Furniture');a.tags=[unreal.Name(tag)]
 created.append(a)
for row,x in enumerate([1780,2070],1):
 for col,y in enumerate([-330,120,570],1):
  add('desk',f'YIXI_Class_Desk_R{row}_C{col}',x,y,.8,90)
  add('stool',f'YIXI_Class_Stool_R{row}_C{col}',x-100,y,.7)
add('desk','YIXI_Class_TeacherDesk',2350,120,1.1,90)
add('stool','YIXI_Class_TeacherStool',2440,120,1)
# Verify source actors are present and their transforms are unchanged.
old=json.loads((q/'original_actors.json').read_text());now={(a.get_level().get_path_name(),a.get_name()):snapshot(a) for a in sub.get_all_level_actors()}
assert all(now.get((a['level'],a['name']))==a for a in old),'Source actor verification failed; map not saved'
for a in created:
 c,e=a.get_actor_bounds(False);assert abs(c.z-e.z-floor)<.1,(a.get_actor_label(),c,e)
unreal.EditorLevelLibrary.set_level_viewport_camera_info(unreal.Vector(1390,-170,400),unreal.Rotator(pitch=-12,yaw=18,roll=0))
sub.set_selected_level_actors([])
(q/'placement.json').write_text(json.dumps({'status':'placed_unsaved','level':level.get_path_name(),'backup':str(backup/src.name),'source_actor_count':len(old),'source_actors_unchanged':True,'furniture':[{'name':a.get_name(),'label':a.get_actor_label(),'p':[a.get_actor_location().x,a.get_actor_location().y,a.get_actor_location().z]} for a in created]},ensure_ascii=False,indent=2))
