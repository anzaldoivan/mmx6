-- tools/mmx6/redux/inputs/mv_ceiling.lua -- movement.lua schedule (T6.c1): intro_stage prefix (START taps 1700..2700 skip
-- the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then ceiling attempt
-- (one try): stimulus poke g_Player.armor (+0xE7) 1 -> 3 at 4190 (assumed Shadow; unverified), then the mv_wall
-- path with UP held during the CROSS taps.
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'RIGHT', 1050}
for _, s in ipairs(lib.mash('CROSS', 4300, 5250, 45, 20)) do steps[#steps + 1] = s end
for _, s in ipairs(lib.mash('UP', 4300, 5250, 45, 20)) do steps[#steps + 1] = s end
return {name = 'mv_ceiling', steps = steps, stop = 5250, focus = 4180,
        pokes = {{4190, 'armor', 3, 'ceiling attempt: armor 1 -> 3'}}}
