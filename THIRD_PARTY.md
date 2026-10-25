# Third-party components

Code or data adapted from other projects, with its upstream, the commit it was taken from, its license and the paths
it occupies. Only sources whose license allows it may appear here (G102). Today that means
[sozud/mmx4](https://github.com/sozud/mmx4) (AGPL-3.0). That source may appear only for functions proven shared with
Mega Man X6 by a signature or byte comparison, each banked through the byte gate. Facts used without copying
(addresses, names as leads, formats) are credited in `README.md` and tracked in `docs/prior-art.md`, not here.

From 2026-10-14, [anzaldoivan/mmx5](https://github.com/anzaldoivan/mmx5) (AGPL-3.0) may appear too. It is the
developer's own Mega Man X5 decompilation. It may appear only for a function of `campaign/x4/x5-leads.tsv` drafted
from its card's `## X5 twin`. Each such file is banked through the byte gate and gets a row naming its mmx5 path.

Once their phase pins them, the toolchains that the build downloads at run time (and never commits) are listed. Each
is listed with the pinned version and the checksum that the build verifies.

<!-- x4port credits -->
| Component | Upstream | Commit / version | License | Paths here | Basis (proof it is shared) |
|---|---|---|---|---|---|
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `include/mmx6/x4.h` | types and macros of `include/common.h, include/func_tables.h, include/scratchpad.h, src/main/3D88.c` used by the rows below |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80013480.c` | exact signature `ea1f214c77bc`, `src/main/2824.c:func_800128EC` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800134A4.c` | exact signature `56ff4cada450`, `src/main/2824.c:func_80012910` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80014D50.c` | exact signature `630fc0e04ff1`, `src/main/3D88.c:func_800136B0` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80015DA0.c` | exact signature `587b9efb8c19`, `src/main/3D88.c:func_80014968` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001668C.c` | exact signature `6ba38c1ddd23`, `src/main/3D88.c:func_80014140` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800174D4.c` | exact signature `3313a3f0820f`, `src/main/55C4.c:func_800153D4` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80017A48.c` | exact signature `fd1585f50292`, `src/main/55C4.c:clear_vram_rect_ptrs` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80017A88.c` | exact signature `d1adcd118b38`, `src/main/55C4.c:load_vram_rect_ptrs` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80017E24.c` | exact signature `8cc804b315e5`, `src/main/55C4.c:func_800160AC` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800184F4.c` | exact signature `65b2d7edf418`, `src/main/55C4.c:func_800163EC` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80018B60.c` | exact signature `adc4ba01bdcd`, `src/main/55C4.c:func_80016E84` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001B428.c` | exact signature `f2a2862257fa`, `src/main/55C4.c:func_80019100` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001B5FC.c` | exact signature `9577b76e9365`, `src/main/55C4.c:func_800192F8` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001B6D0.c` | exact signature `fae0caed2311`, `src/main/55C4.c:func_80018AD0` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001B784.c` | exact signature `e997ebfce7dc`, `src/main/55C4.c:func_80018EEC` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001C6C0.c` | exact signature `e642975dc52e`, `src/main/memcard.c:func_8001CE84` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001C824.c` | exact signature `a1a1bb6682a3`, `src/main/memcard.c:func_8001CEDC` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001D218.c` | exact signature `6643b2ef34c8`, `src/main/game_info.c:func_8001D134` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001D760.c` | exact signature `57aab085cb3c`, `src/main/game_info.c:func_8001D57C` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001D8A0.c` | exact signature `370ee8910a36`, `src/main/game_info.c:func_8001D64C` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001D8EC.c` | exact signature `08f62733c4aa`, `src/main/game_info.c:func_8001D698` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001D930.c` | exact signature `07619b425e9d`, `src/main/game_info.c:func_8001D6DC` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001D9CC.c` | exact signature `ffde10626a32`, `src/main/11184.c:func_80020AC8` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001DF5C.c` | exact signature `0bffad427ba7`, `src/main/E47C.c:func_8001E638` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8001DFDC.c` | exact signature `3affa1eca32f`, `src/main/E47C.c:func_8001E6BC` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80020A08.c` | exact signature `cac1f7cae392`, `src/main/object_update.c:func_80021C14` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80020D18.c` | exact signature `95cf5435ad21`, `src/main/object_update.c:func_80021D20` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80020DC8.c` | exact signature `a99aed5959d6`, `src/main/object_update.c:func_80021CC8` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80021254.c` | exact signature `2a177c96c5fb`, `src/main/afterimage.c:func_800AEA58` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8002132C.c` | exact signature `fb1027ecedab`, `src/main/afterimage.c:func_800AE88C` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80021380.c` | exact signature `adb625a87261`, `src/main/125BC.c:func_80021DBC` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80022E44.c` | exact signature `ce7e7513ad74`, `src/main/14A60.c:func_80024260` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80025F34.c` | exact signature `6affe00825b4`, `src/main/144A4.c:func_80023CE0` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80026128.c` | exact signature `df4775baa321`, `src/main/144A4.c:func_800241E8` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8002935C.c` | exact signature `6ee72b467391`, `src/main/background.c:func_80027D40` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8002943C.c` | exact signature `43e71a929bf8`, `src/main/stage_objects.c:start_screen_shake_x` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80029478.c` | exact signature `503943cdb46f`, `src/main/stage_objects.c:start_screen_shake_y` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80029538.c` | exact signature `a09eb2b42e5f`, `src/main/background.c:func_80027974` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800295E8.c` | exact signature `3108906f66dd`, `src/main/background.c:func_80027AFC` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80029818.c` | exact signature `8a39aba72637`, `src/main/background.c:func_80027FA8` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80029A6C.c` | exact signature `53e7a3858f9c`, `src/main/background.c:update_screen_shake_x` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80029AFC.c` | exact signature `a0d9f0b7dd5c`, `src/main/background.c:update_screen_shake_y` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8002A3E8.c` | exact signature `a578409ab919`, `src/main/195B4.c:func_80028F58` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8002C2B8.c` | exact signature `7632243f87cd`, `src/main/objects.c:func_8002AB20` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8002CE18.c` | exact signature `824e92a3c988`, `src/main/objects.c:func_8002B468` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8002D454.c` | exact signature `5e8e8871519a`, `src/main/object_motion.c:func_8002B9F0` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8002D51C.c` | exact signature `b57657e8090d`, `src/main/object_motion.c:get_layout_screen` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8002F840.c` | exact signature `35842cc5ea2e`, `src/main/1CF60.c:func_8002CDD4` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800306F4.c` | exact signature `8fa4d2d2edd1`, `src/main/1CF60.c:func_8002CC98` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800309F8.c` | exact signature `42673ebd7e4e`, `src/main/1CF60.c:func_8002D32C` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80030B80.c` | exact signature `ca45eff14472`, `src/main/1CF60.c:func_8002D5E4` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80037F34.c` | exact signature `dff51a405822`, `src/main/player_special.c:player_zero_ryuenjin_rise` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8003B954.c` | exact signature `f6ae817e5d19`, `src/main/player_enter.c:player_enter_beam_out` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8003D2BC.c` | exact signature `8e04af3111c5`, `src/main/player_common.c:player_spawn_wall_slide_dust` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8003D850.c` | exact signature `6b996a39570c`, `src/main/player_common.c:player_entry_beam_in` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8003DAF4.c` | exact signature `76c0b9feb772`, `src/main/player_common.c:player_spawn_death_orb` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80042C18.c` | exact signature `3d82c3af21bb`, `src/main/mains/main_65_magma_dragoon.c:magma_dragoon_face_player` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8004672C.c` | exact signature `e7d22a6ee35c`, `src/main/weapons/weapon_61_ride_armor_punch.c:ride_armor_punch_main` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8004686C.c` | exact signature `ef5dce611697`, `src/main/weapons/weapon_61_ride_armor_punch.c:ride_armor_punch_init` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80046C64.c` | exact signature `38e1a722ce8e`, `src/main/mains/main_62_flame_jet.c:flame_jet_update` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800484D8.c` | exact signature `590ed0325c72`, `src/main/items/item_20_gravity_switch.c:gravity_switch_main` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80048DC8.c` | exact signature `092b78e20e4a`, `src/main/items/item_00_breakable_wall.c:breakable_wall_update` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800494DC.c` | exact signature `4a86628af3e4`, `src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_init` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80049670.c` | exact signature `246e79a6823b`, `src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_fade` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800496C0.c` | exact signature `3cea93403e4f`, `src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_attach` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80049950.c` | exact signature `eb3a6db008dc`, `src/main/visuals/visual_02_charge_muzzle_flash.c:charge_muzzle_flash_fade` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80049E50.c` | exact signature `260a65053a4e`, `src/main/mains/main_42_homing_orb.c:homing_orb_start_idle` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8004B4BC.c` | exact signature `350f949ca2ac`, `src/main/visuals/visual_22_missile_smoke.c:missile_smoke_init` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8004B50C.c` | exact signature `c82f771f5c19`, `src/main/visuals/visual_22_missile_smoke.c:missile_smoke_main` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8004BEC8.c` | exact signature `f3f6620a97d2`, `src/main/quads/quad_03_boss_warning_quad.c:boss_warning_quad_close` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8004C7B0.c` | exact signature `f8c67d3d4451`, `src/main/quads/quad_08_flash_band.c:flash_band_widen` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8004C844.c` | exact signature `5aa466ee5359`, `src/main/quads/quad_07_ready_line.c:ready_line_sweep` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8004CFA4.c` | exact signature `2100185f1445`, `src/main/quads/quad_07_ready_line.c:ready_line_init` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8004D074.c` | exact signature `067862c5794d`, `src/main/quads/quad_07_ready_line.c:ready_line_move` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8004E654.c` | exact signature `806a7421f0d6`, `src/main/items/item_01_stage_block.c:drop_item` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80050DFC.c` | exact signature `3841861bc21e`, `src/main/items/item_08_boss_door.c:boss_door_update` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80051104.c` | exact signature `37a985cf43c2`, `src/main/items/item_08_boss_door.c:boss_door_block_player` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800536D0.c` | exact signature `ec91c859e783`, `src/main/effects/effect_24_boss_warning.c:boss_warning_wait` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80053704.c` | exact signature `f64138f8e32d`, `src/main/effects/effect_24_boss_warning.c:boss_warning_wait_tiles` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_800537F0.c` | exact signature `7ccb25922a7c`, `src/main/effects/effect_24_boss_warning.c:boss_warning_finish` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/func_80053828.c` | exact signature `f335fb55e436`, `src/main/effects/effect_24_boss_warning.c:boss_warning_main` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/func_8005400C.c` | exact signature `6c6bde588dbe`, `src/main/effects/effect_27_teleport_intro.c:teleport_intro_spawn_quads` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/player_check_dash_jump_walk.c` | exact signature `67a670686326`, `src/main/player_check.c:player_check_dash_jump_walk` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/player_hurt.c` | exact signature `94a81587fc1f`, `src/main/player.c:player_hurt` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/player_ladder_climb_on_top.c` | exact signature `78487e2d128b`, `src/main/player.c:player_ladder_climb_on_top` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/player_ladder_let_go.c` | exact signature `97ce869b32ad`, `src/main/player.c:player_ladder_let_go` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/player_ladder_step_off_bottom.c` | exact signature `26cbae375ca4`, `src/main/player.c:player_ladder_step_off_bottom` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/SLUS_013.95/player_script_vanish.c` | exact signature `8c272e77d29e`, `src/main/player.c:player_script_vanish` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/player_set_animation_shooting.c` | exact signature `b7ee5de16676`, `src/main/player_weapon.c:player_set_animation_shooting` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/player_update_flash.c` | exact signature `e08fdf21be18`, `src/main/player_common.c:player_update_flash` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/set_velocity_from_angle.c` | exact signature `e92a2af1038e`, `src/main/object_motion.c:set_velocity_from_angle` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/spike_crawler_hit_flash.c` | exact signature `0f5c026ba0d7`, `src/main/enemy_reaction.c:spike_crawler_hit_flash` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/SLUS_013.95/update_layer_objects.c` | exact signature `00a3e13855ef`, `src/main/object_update.c:update_layer_objects` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_00/func_801EB968.c` | exact signature `404516d3d41d`, `src/main/mains/main_32_bomb_bat.c:bomb_bat_hover` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_00/func_801ECD24.c` | exact signature `9736cfd16dd5`, `src/main/weapons/weapon_01_lightning_web.c:lightning_web_release` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_00/func_801EE14C.c` | exact signature `ab318e028ab5`, `src/main/weapons/weapon_22_nova_strike_hitbox.c:nova_strike_hitbox_update` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_00/func_801EE458.c` | exact signature `e25d4c5c1482`, `src/main/weapons/weapon_00_lemon.c:lemon_main` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_00/func_801EE5D4.c` | exact signature `9c5292152b2a`, `src/main/weapons/weapon_00_lemon.c:lemon_deflected` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_00/func_801EEB7C.c` | exact signature `06aa2f0ae247`, `src/main/weapons/weapon_20_plasma_shot.c:buster_shot_follow_muzzle` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_00/func_801F0814.c` | exact signature `d5fdc58f219e`, `src/main/weapons/weapon_02_frost_tower.c:frost_tower_despawn` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_00/player_hover_back_stop.c` | exact signature `b28126054f46`, `src/main/player_special.c:player_hover_back_stop` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_00/player_hover_forward_stop.c` | exact signature `c351fcf586bf`, `src/main/player_special.c:player_hover_forward_stop` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_00/player_hover_set_direction.c` | exact signature `5022eaa90621`, `src/main/player_special.c:player_hover_set_direction` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_00/player_ladder_shoot.c` | exact signature `543816517dc7`, `src/main/player_special.c:player_ladder_shoot` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_02/func_800EA1D8.c` | exact signature `9f9117540cf8`, `src/main/layers/layer_02_train_tunnel.c:train_tunnel_update` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_02/func_800ED1F8.c` | exact signature `85e8100d5593`, `src/main/mains/main_48_sentry_drone.c:sentry_drone_drift_start` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_02/func_800ED25C.c` | exact signature `a6e79c949180`, `src/main/mains/main_48_sentry_drone.c:sentry_drone_drift_move` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_02/func_800ED2F4.c` | exact signature `327f58c0753a`, `src/main/mains/main_48_sentry_drone.c:sentry_drone_dash_start` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_02/func_800ED370.c` | exact signature `0de043eb0114`, `src/main/mains/main_48_sentry_drone.c:sentry_drone_dash_move` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_02/func_800ED3D4.c` | exact signature `d78453aaa177`, `src/main/mains/main_10_dragonfly.c:dragonfly_carry` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_02/func_800ED498.c` | exact signature `b51be65f31c0`, `src/main/mains/main_48_sentry_drone.c:sentry_drone_burst_repeat` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_02/func_800ED7B8.c` | exact signature `be9839e079dd`, `src/main/mains/main_48_sentry_drone.c:sentry_drone_spread_repeat` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_02/func_800ED880.c` | exact signature `0565770c6716`, `src/main/mains/main_48_sentry_drone.c:sentry_drone_drop_start` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_02/func_800EDCE0.c` | exact signature `7ce572c2f092`, `src/main/misc/misc_25_sentry_flash.c:sentry_flash_animate` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_03/func_800EA910.c` | exact signature `ab19d9ae77b7`, `src/main/mains/main_57_frost_walrus.c:frost_walrus_blizzard_finish` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_04/func_800F2FB0.c` | exact signature `f2023113f312`, `src/main/mains/main_57_frost_walrus.c:frost_walrus_death_explode` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_05/func_800E9E80.c` | exact signature `5870cc71888c`, `src/main/mains/main_56_jet_stingray.c:jet_stingray_vortex_finish` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_06/func_800EA5F8.c` | exact signature `6eac507027d5`, `src/main/visuals/visual_12_ride_dust.c:ride_dust_init` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_06/func_800F26E4.c` | exact signature `020323399ced`, `src/main/mech.c:func_8003F648` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_08/func_800E99AC.c` | exact signature `561f8a99cfb3`, `src/main/visuals/visual_13_ride_chaser_jet.c:ride_chaser_jet_init` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_08/func_800E99EC.c` | exact signature `ca898a8565aa`, `src/main/visuals/visual_13_ride_chaser_jet.c:ride_chaser_jet_main` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_08/func_800E9B0C.c` | exact signature `339a3fd19fc8`, `src/main/visuals/visual_15_ride_chaser_flash.c:ride_chaser_flash_init` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_08/func_800E9B48.c` | exact signature `d83d6ae99f8d`, `src/main/visuals/visual_15_ride_chaser_flash.c:ride_chaser_flash_main` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_08/func_800F1D54.c` | exact signature `df30c9a4d6e8`, `src/main/mains/main_54_slash_beast.c:slash_beast_death_blink` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_08/func_800F32A8.c` | exact signature `d7798d86256f`, `src/main/mains/main_13_heavy_mech.c:heavy_mech_face_player` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_09/func_800E9A60.c` | exact signature `b82c7ed308c9`, `src/main/visuals/visual_07_water_wake.c:water_wake_main` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_09/func_800E9D20.c` | exact signature `98768ef976bc`, `src/main/visuals/visual_07_water_wake.c:water_wake_player_moving` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_09/func_800EB284.c` | exact signature `3d82c3af21bb`, `src/main/mains/main_65_magma_dragoon.c:magma_dragoon_face_player` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_09/func_800EC380.c` | exact signature `c21d8b683171`, `src/main/mains/main_32_bomb_bat.c:bomb_bat_hover_start` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_09/func_800EC4C8.c` | exact signature `32f9f02b5c88`, `src/main/mains/main_32_bomb_bat.c:bomb_bat_drop_start` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_09/func_800EC518.c` | exact signature `b8c90aca8278`, `src/main/mains/main_32_bomb_bat.c:bomb_bat_drop_release` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_09/func_800EC8C0.c` | exact signature `551fe75c1ef0`, `src/main/mains/main_32_bomb_bat.c:bomb_bat_dive_fall` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_09/func_800ECA70.c` | exact signature `d7798d86256f`, `src/main/mains/main_13_heavy_mech.c:heavy_mech_face_player` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_09/func_800EE554.c` | exact signature `45fa9bb77d1e`, `src/main/mains/main_02_item_carrier.c:item_carrier_hover` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_09/general_dust_end.c` | exact signature `76d90a83ca68`, `src/main/shots/shot_55_general_shot.c:general_dust_end` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_10/func_800EA068.c` | exact signature `1d1542c14e9b`, `src/main/misc/misc_00_static_sprite.c:spawn_common_effect` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_10/func_800EA0DC.c` | exact signature `ed471c96b830`, `src/main/misc/misc_01_common_effect.c:common_effect_animate` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_10/func_800ECC10.c` | exact signature `8cebceb7e09c`, `src/main/mains/main_43_web_spider.c:web_spider_swing_wait` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_10/func_800F0434.c` | exact signature `7e98e0cffd71`, `src/main/mains/main_27_dash_gunner.c:dash_gunner_explode` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_15/func_800EC2B0.c` | exact signature `7c2510b02378`, `src/main/mains/main_51_fortress_cannon.c:fortress_cannon_volley_wait` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_15/func_800EC378.c` | exact signature `db765c44764d`, `src/main/mains/main_51_fortress_cannon.c:fortress_cannon_lower_end` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_15/func_800EC3C8.c` | exact signature `6c63f20ba27c`, `src/main/mains/main_06_bulldozer.c:bulldozer_fall` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_15/func_800EC428.c` | exact signature `838e32cf3933`, `src/main/mains/main_51_fortress_cannon.c:fortress_cannon_check_fall` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_15/func_800F3CE4.c` | exact signature `7d7e8abd4964`, `src/main/mains/main_49_train_soldier.c:train_soldier_jump_crouch` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_18/func_800ED330.c` | exact signature `b05a02ff1ea5`, `src/main/game_info.c:func_8001DAD0` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_20/func_800EF704.c` | exact signature `8d45f66608cd`, `src/main/engine.c:func_8001F9DC` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_20/func_800EFC74.c` | exact signature `e4a5fdbaa049`, `src/main/menu.c:func_8001C5A8` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_22/func_800F3B38.c` | exact signature `a46c53ea4229`, `src/main/mains/main_19_surface_hopper.c:surface_hopper_update` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_22/func_800F3BD0.c` | exact signature `279ef0018214`, `src/main/mains/main_19_surface_hopper.c:surface_hopper_appear` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_22/func_800F3C64.c` | exact signature `6c2ea09cdb15`, `src/main/mains/main_19_surface_hopper.c:surface_hopper_crawl` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_22/func_800F3CAC.c` | exact signature `c738d9c59df1`, `src/main/mains/main_19_surface_hopper.c:surface_hopper_crawl_turn` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_22/func_800F3D24.c` | exact signature `f1c046e43f2b`, `src/main/mains/main_19_surface_hopper.c:surface_hopper_crawl_turn_end` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_22/func_800F3EEC.c` | exact signature `f3e8264e3395`, `src/main/mains/main_19_surface_hopper.c:surface_hopper_leap_start` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_22/func_800F4094.c` | exact signature `bc88cc45895f`, `src/main/mains/main_19_surface_hopper.c:surface_hopper_probe_tile` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_22/func_800F40E0.c` | exact signature `636a950af3be`, `src/main/mains/main_19_surface_hopper.c:surface_hopper_set_launch` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_30/func_800EADCC.c` | exact signature `3d82c3af21bb`, `src/main/mains/main_65_magma_dragoon.c:magma_dragoon_face_player` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `29b62af` | AGPL-3.0 | `src/shared/rock_30/func_800EC5B8.c` | exact signature `d7798d86256f`, `src/main/mains/main_13_heavy_mech.c:heavy_mech_face_player` |
| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `src/shared/rock_45/func_800FBCF8.c` | exact signature `98a46ba8d11d`, `src/main/mains/main_65_magma_dragoon.c:magma_dragoon_breath` |
<!-- /x4port credits -->

## Build-image tools (not distributed)
Built inside the `mmx6-build` image only. No source or binary of theirs is committed, shipped, or occupies a path here.
- mkpsxiso (`dumpsxiso`): https://github.com/Lameguy64/mkpsxiso, commit `54fb1644ed8741223583e2dcda358b75a205e214`
  (tag v2.30), GPL-2.0. Used as the reference ISO extractor to cross-check `make extract` (T4).
- decomp-permuter: https://github.com/simonlindholm/decomp-permuter, commit `059609d4aec73eb0650726772954e1ad575825f8`,
  MIT. At `/opt/decomp-permuter`, never edited. It is run through `tools/mmx6/permute.py` with our masked scorer
  (phase 1.7 T7).
