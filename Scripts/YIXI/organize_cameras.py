"""Move obsolete camera drafts using Unreal asset tools (references preserved).
No deletions, redirector cleanup, map saving or source opening-sequence edits.
"""
import unreal,pathlib,json,traceback
root=pathlib.Path(unreal.Paths.project_dir()).resolve();out=root/'Saved/YIXI_CameraReview/organization.json'
try:
 unreal.LevelSequenceEditorBlueprintLibrary.close_level_sequence()
 base='/Game/YIXI/Sequences/Trailer'
 # Include the partially generated v02 asset if it remains in the asset registry.
 assets=unreal.EditorAssetLibrary.list_assets(base,True,False)
 folders=sorted(set(p[len(base)+1:].split('/')[0] for p in assets if p.startswith(base+'/CameraDraft')))
 moved=[]
 for name in folders:
  src=base+'/'+name;dst=base+'/_Archive/'+name
  if not (root/'Content/YIXI/Sequences/Trailer'/name).exists():continue
  if unreal.EditorAssetLibrary.does_directory_exist(dst):continue
  if not unreal.EditorAssetLibrary.rename_directory(src,dst):
   moved.append({'source':src,'status':'not_moved','note':'Editor-only failed draft; no files removed'});continue
  moved.append({'source':src,'destination':dst})
 out.write_text(json.dumps({'status':'complete','moved':moved,'note':'Unreal redirectors retained to preserve references. No assets deleted.'},ensure_ascii=False,indent=2))
except Exception:out.write_text(json.dumps({'status':'error','trace':traceback.format_exc()},ensure_ascii=False,indent=2));unreal.log_error(traceback.format_exc())
