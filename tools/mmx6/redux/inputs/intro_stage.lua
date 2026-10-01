-- tools/mmx6/redux/inputs/intro_stage.lua -- pad schedule for loads.lua (T5.c1): boot → title → Game Start →
-- the opening stage, playable. Frames = GPU::Vsync count from power-on (interpreter, no save state).
-- No input: BIOS + Capcom logo, then the intro story plays (title skipped). Found by screen dumps every 250 frames:
--   START taps 1700..2690 (every 90): skip intro → title "PRESS START" → menu → Game Start; stage loads ~2773.
--   READY ~3000, then Alia/X dialog: START does not advance it, CROSS does (taps every 30 from 3100).
--   RIGHT held from 5000: X walks into the stage (enemies, door) by ~6000; CROSS keeps jumping.
-- Loads seen (all three bases): 0x80013E7C → 0x800E9860 (members 18, 12, 2), 0x80013E40 → 0x800FA000
-- (member 46), 0x80013CDC → 0x801EA000 (member 0).
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2700, 90, 6)
for _, s in ipairs(lib.mash('CROSS', 3100, 6500, 30, 6)) do steps[#steps + 1] = s end
steps[#steps + 1] = {5000, 'RIGHT', 1500}
return {name = 'intro_stage', steps = steps, stop = 6500}
