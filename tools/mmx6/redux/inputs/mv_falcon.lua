-- tools/mmx6/redux/inputs/mv_falcon.lua -- movement.lua schedule (T6.c1): intro_stage prefix (START taps 1700..2700 skip
-- the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then Falcon armor air moves:
-- jump + second CROSS press mid-air (held 60), then jump + UP held with CIRCLE mid-air.
-- Control tail: RIGHT held from 4400 so the camera reaches the first enemy and move_object runs (no object
-- moves before that; control needs k >= 3).
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'CROSS', 15}
steps[#steps + 1] = {4222, 'CROSS', 60}
steps[#steps + 1] = {4330, 'CROSS', 15}
steps[#steps + 1] = {4338, 'UP', 30}
steps[#steps + 1] = {4340, 'CIRCLE', 20}
steps[#steps + 1] = {4400, 'RIGHT', 130}
return {name = 'mv_falcon', steps = steps, stop = 4540, focus = 4180}
