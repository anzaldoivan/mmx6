-- tools/mmx6/redux/inputs/mv_hover2.lua -- movement.lua schedule (T6.c2): intro_stage prefix (START taps 1700..2700 skip
-- the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then hover
-- attempt 2: gate start_hover = armor 4 + CROSS pressed in the air (air_action 0). Stimulus: the armor source
-- g_playthrough_state+0x5E (0x800CCF2E, read by player init func_8003D718) held at 4 from 2800 to 4170, so the game
-- sets the armor itself. Then mv_hover's pad: CROSS jump (12), CROSS held 60 while falling, RIGHT tail.
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'CROSS', 12}
steps[#steps + 1] = {4232, 'CROSS', 60}
steps[#steps + 1] = {4320, 'RIGHT', 130}
return {name = 'mv_hover2', steps = steps, stop = 4460, focus = 4180,
        probes = {'armor_init'}, pokes = {{2800, 0x800CCF2E, 4, 'armor source -> 4 (hover gate)', 4170}}}
