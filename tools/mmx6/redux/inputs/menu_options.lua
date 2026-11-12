-- tools/mmx6/redux/inputs/menu_options.lua -- pad schedule for boot.lua (T25.c1): boot → main menu → OPTION, each
-- options entry entered once, back to the main menu. Frames = Vsync count; evidence per step from boot.lua runs with
-- MMX6_EXPLORE=1 (bytes 0x800CD3F8+0..+0xF: state, +1 sub-mode, +2 main-menu cursor) and the options cursor u8
-- 0x80097427 (found by a RAM diff: 0..5 over 6 DOWN steps), screens read from dumps:
--   START 1700/1790/1880/1970: as boot_menu (state 6 at 2008). Main menu entries (screen): 0 GAME START,
--     1 CONTINUE (state 7, handler 0x800ED760), 2 OPTION.
--   DOWN 2100 → cursor +2 = 1 at 2102; DOWN 2160 → 2 at 2162 (OPTION highlighted).
--   START 2250 → sub-mode 2 at 2252, state 8 (OPTION, handler D_800710E8[8] = 0x800EA5C8, rock_18) at 2288,
--     options cursor 0. Options (screen): GAME LEVEL, GAME SPEED, BUTTON CONFIGURATION, SOUND MODE, SOUND TEST,
--     MODE SELECT SCREEN; "PRESS START BUTTON TO EXIT" (TRIANGLE also exits to state 6).
--   CROSS 2400 on GAME LEVEL (cursor 0; value unchanged on screen).
--   DOWN 2460 → cursor 1 at 2462; CROSS 2520 on GAME SPEED (NORMAL → SLOW on screen).
--   DOWN 2580 → cursor 2 at 2582; CROSS 2640 on BUTTON CONFIGURATION → sub-mode 2 at 2642, 4 at 2680 (its screen).
--   START 2760 → sub-mode 5 at 2762, back to the options list (sub-mode 1) at 2800 with cursor 0 (screen).
--   DOWN 2880/2940/3000 → cursor 1/2/3 at 2882/2942/3002; CROSS 3060 on SOUND MODE (STEREO ↔ MONAURAL on screen).
--   DOWN 3120 → cursor 4 at 3122; CROSS 3180 on SOUND TEST.
--   DOWN 3240 → cursor 5 at 3242; CROSS 3300 on MODE SELECT SCREEN → sub-mode 2 at 3302, state 6 at 3338.
--   stop 3460 (main menu back + ~120).
-- Control: require 0x800EA5C8 (the options handler). init_options_menu 0x8002A588 is never hit on this path
-- (0 hits over all six entries, T25.c1 exploration).
local lib = MMX6_LIB
local steps = lib.mash('START', 1700, 2008, 90, 6)
local function at(f, b) steps[#steps + 1] = {f, b, 6} end
at(2100, 'DOWN'); at(2160, 'DOWN'); at(2250, 'START')
at(2400, 'CROSS'); at(2460, 'DOWN'); at(2520, 'CROSS'); at(2580, 'DOWN'); at(2640, 'CROSS')
at(2760, 'START')
at(2880, 'DOWN'); at(2940, 'DOWN'); at(3000, 'DOWN'); at(3060, 'CROSS')
at(3120, 'DOWN'); at(3180, 'CROSS')
at(3240, 'DOWN'); at(3300, 'CROSS')
return {name = 'menu_options', asm = true, require = {0x800EA5C8}, steps = steps, stop = 3460}
