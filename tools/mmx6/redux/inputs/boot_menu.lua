-- tools/mmx6/redux/inputs/boot_menu.lua -- pad schedule for boot.lua (T19.c1): boot → title → front-end menu, then idle.
-- START taps as intro_stage (every 90 from 1700) up to the first frame the state byte 0x800CD3F8 reads the menu
-- state 6 (2008 in boot.lua runs on intro_stage: state 5 at 1972 after the 1970 tap, 6 at 2008), so taps at
-- 1700/1790/1880/1970; no input after; stop 1500 frames later.
local lib = MMX6_LIB
return {name = 'boot_menu', steps = lib.mash('START', 1700, 2008, 90, 6), stop = 2008 + 1500}
