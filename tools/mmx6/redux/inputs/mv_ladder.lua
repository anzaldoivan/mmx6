-- tools/mmx6/redux/inputs/mv_ladder.lua -- movement.lua schedule (T6.c1): intro_stage prefix (START taps 1700..2700 skip
-- the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then ladder attempt:
-- UP held with RIGHT along the mv_wall path (CROSS taps every 45 from 4300); the stage may have no ladder.
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'RIGHT', 1050}
steps[#steps + 1] = {4200, 'UP', 1050}
for _, s in ipairs(lib.mash('CROSS', 4300, 5250, 45, 20)) do steps[#steps + 1] = s end
return {name = 'mv_ladder', steps = steps, stop = 5250, focus = 4180}
