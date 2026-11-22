"""Inspect and build the independent SH02 classroom sequence in UE 5.8."""
import hashlib
import json
from pathlib import Path
import unreal

root = Path(unreal.Paths.project_dir()).resolve()
queue = root / 'Saved/YIXI_SH02'
job = json.loads((queue / 'job.json').read_text())
base = '/Game/YIXI/Sequences/Trailer/'
preview_map = '/Game/YIXI/Maps/Cinematics/L_YIXI_SH01_Pond_DayPreview'
destination = base + 'LS_YIXI_SH02_Classroom_Day'
editor = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)
actors = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
levels = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
sequencer = unreal.LevelSequenceEditorBlueprintLibrary
world = editor.get_editor_world()
assert world.get_path_name().startswith(preview_map + '.'), world.get_path_name()

def xyz(vector):
    return [vector.x, vector.y, vector.z]

def snapshot(actor):
    center, extent = actor.get_actor_bounds(False)
    return {'name': actor.get_name(), 'label': actor.get_actor_label(),
            'center': xyz(center), 'extent': xyz(extent),
            'level': actor.get_level().get_path_name()}

all_actors = actors.get_all_level_actors()
desks = [snapshot(actor) for actor in all_actors if 'YIXI_Class_Desk_' in actor.get_actor_label()]
stools = [snapshot(actor) for actor in all_actors if 'YIXI_Class_Stool_' in actor.get_actor_label()]
doors = [snapshot(actor) for actor in all_actors if 'door_open' in actor.get_actor_label().lower()
         and 1200 < actor.get_actor_bounds(False)[0].x < 1500
         and abs(actor.get_actor_bounds(False)[0].y - 120) < 400]
template = unreal.load_asset(base + 'DayScreeningTemplate')
day_reference = unreal.load_asset(base + 'LS_YIXI_SH01_Pond_Day_WithTeacher')
assert template and day_reference
if job['mode'] == 'inspect':
    old_sequences = []
    registry = unreal.AssetRegistryHelpers.get_asset_registry()
    for asset in registry.get_assets_by_path(base.rstrip('/'), True):
        if 'Classroom' in str(asset.asset_name) and str(asset.asset_class_path.asset_name) == 'LevelSequence':
            seq = asset.get_asset()
            old_sequences.append({'package': str(asset.package_name),
                                  'range': [seq.get_playback_start(), seq.get_playback_end()],
                                  'bindings': [str(b.get_display_name()) for b in seq.get_bindings()]})
    (queue / 'survey.json').write_text(json.dumps({
        'world': world.get_path_name(), 'desks': desks, 'stools': stools,
        'doors': doors, 'prior_classroom_sequences': old_sequences,
        'template_bindings': [str(b.get_display_name()) for b in template.get_bindings()],
        'light_reference_bindings': [str(b.get_display_name()) for b in day_reference.get_bindings()],
    }, indent=2))

def bindings(sequence):
    return {str(binding.get_display_name()): binding for binding in sequence.get_bindings()}

def position(sequence, frame):
    sequencer.close_level_sequence()
    actors.set_selected_level_actors([])
    sequencer.open_level_sequence(sequence)
    levels.eject_pilot_level_actor()
    levels.set_allows_cinematic_control(True)
    levels.editor_set_game_view(True)
    sequencer.set_lock_camera_cut_to_viewport(True)
    sequencer.set_current_time(frame)
    levels.editor_invalidate_viewports()

if job['mode'] == 'build':
    assert len(desks) == len(stools) == 6 and len(doors) == 1
    assert not unreal.EditorAssetLibrary.does_asset_exist(destination)
    middle = next(d for d in desks if d['label'].endswith('R1_C2'))
    door = doors[0]
    floor = middle['center'][2] - middle['extent'][2]
    door_x, door_y, _ = door['center']
    # Travel along the doorway's inward normal, moving 20 cm to camera right.
    start = unreal.Vector(door_x - 90, door_y + 50, floor + 149)
    end = unreal.Vector(middle['center'][0] - 225, door_y + 70, floor + 149)
    hit = unreal.SystemLibrary.line_trace_single(
        world, start, end, unreal.TraceTypeQuery.TRACE_TYPE_QUERY1,
        True, [], unreal.DrawDebugTrace.NONE, True)
    assert not hit or not hit.to_dict()['blocking_hit'], str(hit)
    rear = next(d for d in desks if d['label'].endswith('R2_C2'))
    tabletop = middle['center'][2] + middle['extent'][2]
    start_aim = unreal.Vector(rear['center'][0], door_y + 65, tabletop + 24)
    end_aim = unreal.Vector(rear['center'][0], door_y + 52, tabletop - 12)
    poses = [(0, start, unreal.MathLibrary.find_look_at_rotation(start, start_aim)),
             (263, end, unreal.MathLibrary.find_look_at_rotation(end, end_aim))]
    protected_paths = [root / 'Content/YIXI/Sequences/Trailer/DayScreeningTemplate.uasset',
                       root / 'Content/YIXI/Maps/Cinematics/L_YIXI_SH01_Pond_DayPreview.umap']
    def originals():
        return [hashlib.sha256(p.read_bytes()).hexdigest() for p in protected_paths]
    source_hashes = originals()
    ref_bindings = bindings(day_reference)
    targets = {}
    for name in bindings(template):
        objects = unreal.MovieSceneSequenceExtensions.locate_bound_objects(
            day_reference, ref_bindings[name], world)
        assert len(objects) == 1 and objects[0].get_path_name().startswith(preview_map + '.'), name
        targets[name] = objects[0]
    folder, asset_name = destination.rsplit('/', 1)
    shot = unreal.AssetToolsHelpers.get_asset_tools().duplicate_asset(asset_name, folder, template)
    assert shot
    shot.set_display_rate(unreal.FrameRate(24, 1))
    shot.set_playback_start(0)
    shot.set_playback_end(264)
    shot.set_view_range_start(0.0)
    shot.set_view_range_end(11.0)
    shot.set_work_range_start(0.0)
    shot.set_work_range_end(11.0)
    position(shot, 0)
    binding_editor = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
    for name, binding in bindings(shot).items():
        if isinstance(targets[name], unreal.Actor):
            binding_editor.replace_binding_with_actors([targets[name]], binding)
    for name, binding in bindings(shot).items():
        target = targets[name]
        if isinstance(target, unreal.ActorComponent):
            binding_editor.rebind_component([binding], unreal.Name(target.get_name()))
    for name, binding in bindings(shot).items():
        objects = unreal.MovieSceneSequenceExtensions.locate_bound_objects(shot, binding, world)
        assert len(objects) == 1 and objects[0].get_path_name() == targets[name].get_path_name(), name
        for track in binding.get_tracks():
            for section in track.get_sections():
                section.set_completion_mode(unreal.MovieSceneCompletionMode.RESTORE_STATE)
                if section.has_end_frame() and section.get_end_frame() < 264:
                    section.set_end_frame(264)
    temporary = actors.spawn_actor_from_class(unreal.CineCameraActor, start, poses[0][2], True)
    assert temporary
    try:
        component = temporary.get_cine_camera_component()
        filmback = component.filmback
        filmback.sensor_width = 36.0
        filmback.sensor_height = 20.25
        component.filmback = filmback
        component.current_focal_length = 35.0
        component.current_aperture = 8.0
        focus = component.focus_settings
        focus.focus_method = unreal.CameraFocusMethod.DISABLE
        component.focus_settings = focus
        camera = shot.add_spawnable_from_instance(temporary)
        camera.set_display_name('SH02 · Classroom Dolly In · 35mm')
    finally:
        actors.destroy_actor(temporary)
    spawn = next((t for t in camera.get_tracks() if isinstance(t, unreal.MovieSceneSpawnTrack)), None)
    if spawn is None:
        spawn = camera.add_track(unreal.MovieSceneSpawnTrack)
    spawn_section = spawn.get_sections()[0] if spawn.get_sections() else spawn.add_section()
    spawn_section.set_range(0, 264)
    spawn_section.get_all_channels()[0].set_default(True)
    motion = camera.add_track(unreal.MovieScene3DTransformTrack).add_section()
    motion.set_range(0, 264)
    channels = motion.get_all_channels()
    # Auto cubic tangents ease continuously between the two endpoints.
    for frame, point, rotation in poses:
        values = xyz(point) + [rotation.roll, rotation.pitch, rotation.yaw, 1.0, 1.0, 1.0]
        for channel, value in zip(channels, values):
            channel.add_key(unreal.FrameNumber(frame), value,
                            interpolation=unreal.MovieSceneKeyInterpolation.AUTO)
    cut = shot.add_track(unreal.MovieSceneCameraCutTrack).add_section()
    cut.set_range(0, 264)
    cut.set_camera_binding_id(shot.get_binding_id(camera))
    assert unreal.EditorAssetLibrary.save_loaded_asset(shot, False)
    assert originals() == source_hashes
    (queue / 'build.json').write_text(json.dumps({
        'sequence': destination, 'preview_map': preview_map, 'range': [0, 264],
        'fps': 24, 'focal_mm': 35, 'start': xyz(start), 'end': xyz(end),
        'camera_height_cm': 149, 'light_bindings_checked': len(targets),
        'collision_clear': True, 'source_files_unchanged': True,
    }, indent=2))
    position(shot, 0)

if job['mode'] in ('pose', 'validate'):
    shot = unreal.load_asset(destination)
    assert shot
    position(shot, int(job.get('frame', 0)))
    if job['mode'] == 'validate':
        camera_bindings = [b for b in shot.get_bindings() if str(b.get_display_name()).startswith('SH02')]
        assert len(camera_bindings) == 1
        camera_binding = camera_bindings[0]
        cuts = [sec for track in shot.get_tracks() if isinstance(track, unreal.MovieSceneCameraCutTrack)
                for sec in track.get_sections()]
        assert len(cuts) == 1 and cuts[0].get_start_frame() == 0 and cuts[0].get_end_frame() == 264
        assert unreal.MovieSceneSequenceExtensions.resolve_binding_id(
            shot, cuts[0].get_camera_binding_id()).get_id().to_string() == camera_binding.get_id().to_string()
        assert shot.get_playback_start() == 0 and shot.get_playback_end() == 264
        samples = []
        for frame in [0, 66, 132, 198, 263]:
            sequencer.set_current_time(frame)
            sequencer.force_update()
            objects = sequencer.get_bound_objects(shot.get_binding_id(camera_binding))
            assert len(objects) == 1 and isinstance(objects[0], unreal.CineCameraActor)
            a = objects[0]
            samples.append(xyz(a.get_actor_location()))
            cc = a.get_cine_camera_component()
            assert abs(cc.current_focal_length - 100) < 0.01
            assert abs(cc.filmback.sensor_width / cc.filmback.sensor_height - 16/9) < 0.001
        assert all(first[0] < second[0] for first, second in zip(samples, samples[1:])), samples
        (queue / 'validation.json').write_text(json.dumps({'samples': samples, 'status': 'passed'}, indent=2))
        sequencer.set_current_time(int(job.get('frame', 0)))
        levels.editor_invalidate_viewports()

if job['mode'] == 'grade':
    shot = unreal.load_asset(destination)
    assert shot
    camera = next(b for b in shot.get_bindings() if str(b.get_display_name()).startswith('SH02'))
    actor_template = camera.get_object_template()
    components = [c for c in unreal.ObjectIterator(unreal.CineCameraComponent)
                  if c.get_path_name().startswith(actor_template.get_path_name() + '.')]
    assert len(components) == 1
    component = components[0]
    settings = component.get_editor_property('post_process_settings')
    # Restrained camera-only grade: soften orange saturation and lift middle tones.
    for name, value in {
        'color_saturation': unreal.Vector4(1.0, 1.0, 1.0, 0.78),
        'color_gamma': unreal.Vector4(1.0, 1.03, 1.08, 1.05),
        'color_contrast': unreal.Vector4(1.0, 1.0, 1.0, 0.95),
    }.items():
        settings.set_editor_property('override_' + name, True)
        settings.set_editor_property(name, value)
    sequencer.close_level_sequence()
    component.modify()
    component.set_editor_property('post_process_settings', settings)
    component.set_editor_property('post_process_blend_weight', 1.0)
    assert unreal.EditorAssetLibrary.save_loaded_asset(shot, False)
    position(shot, int(job.get('frame', 0)))
    sequencer.force_update()
    bound = sequencer.get_bound_objects(shot.get_binding_id(camera))
    assert len(bound) == 1
    applied = bound[0].get_cine_camera_component().get_editor_property('post_process_settings')
    assert abs(applied.get_editor_property('color_saturation').w - 0.78) < 0.001

if job['mode'] == 'playcheck':
    import time
    shot = unreal.load_asset(destination)
    position(shot, 0)
    sequencer.play()
    started = time.monotonic()
    playback = {'max_frame': 0, 'handle': None}

    def check(_delta):
        frame = sequencer.get_current_time()
        playback['max_frame'] = max(frame, playback['max_frame'])
        if time.monotonic() - started > 14:
            sequencer.pause()
            unreal.unregister_slate_post_tick_callback(playback['handle'])
            (queue / 'playback.json').write_text(json.dumps({
                'max_frame': playback['max_frame'],
                'passed': playback['max_frame'] >= 260,
            }))
            sequencer.set_current_time(0)
            levels.editor_invalidate_viewports()

    playback['handle'] = unreal.register_slate_post_tick_callback(check)

if job['mode'] in ('doorway_detail', 'save_detail'):
    shot = unreal.load_asset(destination)
    camera = next(b for b in shot.get_bindings() if str(b.get_display_name()).startswith('SH02'))
    if job['mode'] == 'doorway_detail':
        middle = next(d for d in desks if d['label'].endswith('R1_C2'))
        door_x, door_y, _ = doors[0]['center']
        cx, cy, cz = middle['center']
        tabletop = cz + middle['extent'][2]
        motion = next(t for t in camera.get_tracks() if isinstance(t, unreal.MovieScene3DTransformTrack))
        channels = motion.get_sections()[0].get_all_channels()
        for index, (dx, dy, aim_y) in enumerate([(112, -89, -80), (172, -79, -77)]):
            point = unreal.Vector(door_x + dx, door_y + dy, tabletop + 7)
            aim = unreal.Vector(cx, cy + aim_y, tabletop - 4)
            rotation = unreal.MathLibrary.find_look_at_rotation(point, aim)
            for channel, value in zip(channels, xyz(point) + [0.0, rotation.pitch, rotation.yaw, 1.0, 1.0, 1.0]):
                key = channel.get_keys()[index]
                key.set_value(value)
        actor_template = camera.get_object_template()
        component = next(c for c in unreal.ObjectIterator(unreal.CineCameraComponent)
                         if c.get_path_name().startswith(actor_template.get_path_name() + '.'))
        sequencer.close_level_sequence()
        component.modify()
        component.current_focal_length = 100.0
        component.current_aperture = 4.0
        focus = component.focus_settings
        focus.focus_method = unreal.CameraFocusMethod.MANUAL
        focus.manual_focus_distance = 285.0
        component.focus_settings = focus
        camera.set_display_name('SH02 · Scroll and Desk Detail · 100mm')
    position(shot, int(job.get('frame', 0)))
    if job['mode'] == 'save_detail':
        assert unreal.EditorAssetLibrary.save_loaded_asset(shot, False)
