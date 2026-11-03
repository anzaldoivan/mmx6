-- tools/mmx6/redux/inputs/mv_wall.lua -- movement.lua schedule (T6.c1): intro_stage prefix (START taps 1700..2700 skip
-- the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then wall:
-- RIGHT held from 4200 with CROSS taps (every 45, held 20) from 4300: X jumps the obstacles and enemies and reaches
-- the wall near x 1589 by ~5000, where the taps give cling, slide and wall jumps (found by the T6.c1 exploration run).
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'RIGHT', 1050}
for _, s in ipairs(lib.mash('CROSS', 4300, 5250, 45, 20)) do steps[#steps + 1] = s end
return {name = 'mv_wall', steps = steps, stop = 5250, focus = 4980}
