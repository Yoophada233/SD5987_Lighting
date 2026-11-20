"""Read-only classroom and existing furniture resource survey."""
import unreal,pathlib,json
root=pathlib.Path(unreal.Paths.project_dir()).resolve();q=root/'Saved/YIXI_Classroom'
def vec(v):return [v.x,v.y,v.z]
actors=unreal.get_editor_subsystem(unreal.EditorActorSubsystem).get_all_level_actors()
items=[]
for a in actors:
 p=a.get_actor_location()
 if 1100<p.x<2700 and -1200<p.y<1400:
  c,e=a.get_actor_bounds(False)
  comps=a.get_components_by_class(unreal.StaticMeshComponent)
  items.append({'name':a.get_name(),'label':a.get_actor_label(),'p':vec(p),'rot':str(a.get_actor_rotation()),'center':vec(c),'extent':vec(e),'level':a.get_level().get_path_name(),'meshes':[x.static_mesh.get_path_name() for x in comps if x.static_mesh]})
meshes=[]
reg=unreal.AssetRegistryHelpers.get_asset_registry()
for d in reg.get_assets_by_path('/Game/3DAssets/mesh',True):
 if any(k in str(d.asset_name).lower() for k in ['table','chair','桌','椅','凳']):
  m=d.get_asset()
  if not isinstance(m,unreal.StaticMesh):continue
  b=m.get_bounding_box()
  meshes.append({'asset':m.get_path_name(),'min':vec(b.min),'max':vec(b.max),'materials':[str(x.material_interface.get_path_name()) if x.material_interface else None for x in m.static_materials]})
world=unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem).get_editor_world()
report={'world':world.get_path_name(),'actors':items,'meshes':meshes,'level_api':[x for x in dir(unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)) if 'level' in x.lower()],'dirty_maps':[x.get_path_name() for x in unreal.EditorLoadingAndSavingUtils.get_dirty_map_packages()]}
(q/'inspection.json').write_text(json.dumps(report,ensure_ascii=False,indent=2))
