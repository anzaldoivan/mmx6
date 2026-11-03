-- tools/mmx6/redux/inputs/mv_dash.lua -- movement.lua schedule (T6.c1): intro_stage prefix (START taps 1700..2700 skip
-- the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then dash:
-- CIRCLE held 40 frames (button dash, right, stops at the obstacle near x 309), LEFT double tap (3 frames, gap 3,
-- held 30), CIRCLE + CROSS (dash jump, facing left). Control tail: RIGHT held from 4480 (camera reaches the first
-- enemy, move_object runs).
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'CIRCLE', 40}
steps[#steps + 1] = {4300, 'LEFT', 3}
steps[#steps + 1] = {4306, 'LEFT', 30}
steps[#steps + 1] = {4400, 'CIRCLE', 20}
steps[#steps + 1] = {4405, 'CROSS', 15}
steps[#steps + 1] = {4480, 'RIGHT', 130}
return {name = 'mv_dash', steps = steps, stop = 4630, focus = 4180}
