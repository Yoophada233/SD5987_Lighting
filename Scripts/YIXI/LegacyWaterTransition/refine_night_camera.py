import unreal,math,pathlib,json
seq=unreal.LevelSequenceEditorBlueprintLibrary.get_current_level_sequence();assert seq.get_name().startswith('LS_YIXI_Opening_WaterToNight')
for b in seq.get_bindings():
 if str(b.get_display_name()).startswith('03_NIGHT'):
  for t in b.get_tracks():
   if isinstance(t,unreal.MovieScene3DTransformTrack):
    chs=t.get_sections()[0].get_all_channels()
    for ch in chs:
     for k in ch.get_keys():ch.remove_key(k)
    for f,p in [(240,[-34700,219000,250]),(264,[-34700,219000,250]),(431,[-34600,218900,280])]:
     target=[-35600,220400,450];d=[target[i]-p[i] for i in range(3)];pitch=math.degrees(math.atan2(d[2],math.hypot(d[0],d[1])));yaw=math.degrees(math.atan2(d[1],d[0]))
     for ch,v in zip(chs,p+[0,pitch,yaw]+[1,1,1]):ch.add_key(unreal.FrameNumber(f),float(v),interpolation=unreal.MovieSceneKeyInterpolation.LINEAR)
sub=unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
def spawnsection(b):
 t=next((x for x in b.get_tracks() if isinstance(x,unreal.MovieSceneSpawnTrack)),None)
 if t is None:t=b.add_track(unreal.MovieSceneSpawnTrack)
 s=t.get_sections()[0] if t.get_sections() else t.add_section();s.set_range(240,432);s.get_all_channels()[0].set_default(True)
a=sub.spawn_actor_from_class(unreal.PointLight,unreal.Vector(-35500,220200,300),unreal.Rotator(),True)
c=a.get_component_by_class(unreal.PointLightComponent);c.set_editor_property('intensity',18000.);c.set_editor_property('attenuation_radius',2500.);c.set_editor_property('light_color',unreal.Color(255,110,35,255))
b=seq.add_spawnable_from_instance(a);b.set_display_name('NIGHT_Fire_Glow');sub.destroy_actor(a);spawnsection(b)
system=unreal.load_asset('/Game/F_FreeFlameFx_Pack/FX/NS_Flame_4')
if system:
 a=sub.spawn_actor_from_class(unreal.NiagaraActor,unreal.Vector(-35500,220200,-60),unreal.Rotator(),True)
 a.get_component_by_class(unreal.NiagaraComponent).set_asset(system)
 b=seq.add_spawnable_from_instance(a);b.set_display_name('NIGHT_Courtyard_Flame');sub.destroy_actor(a);spawnsection(b)
unreal.EditorAssetLibrary.save_loaded_asset(seq);unreal.LevelSequenceEditorBlueprintLibrary.set_current_time(300)
pathlib.Path('/tmp/nightwide.json').write_text(json.dumps({'saved':True}))
