-- tools/mmx6/redux/inputs/mv_ladder2.lua -- movement.lua schedule (T6.c2): intro_stage prefix (START taps 1700..2700
-- skip the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then
-- ladder attempt 2: gate try_enter_ladder = UP held (input bit 4) over tile attribute 0x20 (func_8002FD3C), or DOWN
-- (bit 8) over 0x21 (func_80030068). Pad: the mv_ladder path (RIGHT + UP held, CROSS taps) run further, to 7000;
-- probes ladder_tile_up/down list every tile attribute met.
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'RIGHT', 2800}
steps[#steps + 1] = {4200, 'UP', 2800}
for _, s in ipairs(lib.mash('CROSS', 4300, 7000, 45, 20)) do steps[#steps + 1] = s end
return {name = 'mv_ladder2', steps = steps, stop = 7000, focus = 4180,
        probes = {'ladder_tile_up', 'ladder_tile_down', 'falcon_store_action'}}
