-- tools/mmx6/redux/inputs/mv_lowhp.lua -- movement.lua schedule (T6.c1): intro_stage prefix (START taps 1700..2700 skip
-- the intro and pick Game Start; CROSS taps 3100..4130 advance the Alia dialog; control from frame 4144), then low health:
-- stimulus: poke g_Player.hp (+0x5C) 32 -> 4 at 4250; RIGHT held with CROSS taps as mv_wall so an enemy hits X.
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 4130, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {4200, 'RIGHT', 400}
for _, s in ipairs(lib.mash('CROSS', 4300, 4600, 45, 20)) do steps[#steps + 1] = s end
return {name = 'mv_lowhp', steps = steps, stop = 4600, focus = 4180,
        pokes = {{4250, 'hp', 4, 'low health stimulus: hp 32 -> 4'}}}
