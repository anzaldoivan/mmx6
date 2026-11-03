-- tools/mmx6/redux/inputs/mv_airdash.lua -- movement.lua schedule (T6.c1): intro_stage prefix (START taps 1700..2700 skip
-- the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then air dash:
-- CROSS held 20 (jump), CIRCLE tapped mid-air at +10 (held 20).
-- Control tail: RIGHT held from 4300 so the camera reaches the first enemy and move_object runs (no object
-- moves before that; control needs k >= 3).
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'CROSS', 20}
steps[#steps + 1] = {4210, 'CIRCLE', 20}
steps[#steps + 1] = {4300, 'RIGHT', 130}
return {name = 'mv_airdash', steps = steps, stop = 4440, focus = 4180}
