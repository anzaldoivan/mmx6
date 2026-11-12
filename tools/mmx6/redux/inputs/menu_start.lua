-- tools/mmx6/redux/inputs/menu_start.lua -- pad schedule for boot.lua (T25.c1): boot → main menu → GAME START →
-- the opening stage, stopped at the first passing player dispatch (stop_on). Evidence (boot.lua MMX6_EXPLORE=1
-- runs, screens read from dumps):
--   START 1700/1790/1880/1970: as boot_menu (state 6 at 2008, main-menu cursor +2 = 0 = GAME START).
--   START 2100 → sub-mode +1 = 2 at 2102; loads member 46 → 0x800FA000 at 2138, 12 → 0x800E9860 at 2156; the
--     opening story runs from 2430 (rock_46/rock_12 range first hit; screen at 2460), dialog still up at 3200
--     without a skip.
--   START 2500 → story skipped: "Now Loading" screen at 2650; loads 0 → 0x801EA000 at 2763, 2 → 0x800E9860 at 2788;
--     READY screen at 3250; first passing player dispatch at 3261 (action 0) with no further input.
--   stop 4500: fallback only (stop_on ends the run first).
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2008, 90, 6)
steps[#steps + 1] = {2100, 'START', 6}
steps[#steps + 1] = {2500, 'START', 6}
return {name = 'menu_start', asm = true, stop_on = 'player_dispatch', steps = steps, stop = 4500}
