-- tools/mmx6/redux/inputs/mv_hover.lua -- movement.lua schedule (T6.c1): intro_stage prefix (START taps 1700..2700 skip
-- the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then hover attempt:
-- CROSS jump (12), then while falling CROSS held 60. Control tail: RIGHT held from 4320.
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'CROSS', 12}
steps[#steps + 1] = {4232, 'CROSS', 60}
steps[#steps + 1] = {4320, 'RIGHT', 130}
return {name = 'mv_hover', steps = steps, stop = 4460, focus = 4180}
