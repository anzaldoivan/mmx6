-- tools/mmx6/redux/inputs/mv_ceiling2.lua -- movement.lua schedule (T6.c2): intro_stage prefix (START taps 1700..2700
-- skip the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then
-- ceiling attempt 2: gate check_ceiling_jump = character 0 + armor 2 + UP held (input bit 4) + CROSS pressed. Stimulus:
-- the armor source g_playthrough_state+0x5E (0x800CCF2E, read by player init func_8003D718) held at 2 from 2800 to
-- 4170, so the game sets the armor itself. Pad: UP+CROSS from standstill at 4200, then the mv_wall path with UP+CROSS taps.
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'UP', 40}
steps[#steps + 1] = {4210, 'CROSS', 20}
steps[#steps + 1] = {4300, 'RIGHT', 950}
for _, s in ipairs(lib.mash('CROSS', 4350, 5250, 45, 20)) do steps[#steps + 1] = s end
for _, s in ipairs(lib.mash('UP', 4350, 5250, 45, 20)) do steps[#steps + 1] = s end
return {name = 'mv_ceiling2', steps = steps, stop = 5250, focus = 4180,
        probes = {'armor_init'}, pokes = {{2800, 0x800CCF2E, 2, 'armor source -> 2 (ceiling gate)', 4170}}}
