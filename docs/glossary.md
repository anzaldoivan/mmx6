# Glossary

This table ties a game term to the identifier stem our names use.
A stem is the snake_case part that names, globals and fields share.
The rules for names are in `docs/naming.md`, and the documentation standard is in `docs/semantic-c.md`.

## Columns

- English term: the term in English, as players and community notes use it.
- Japanese: the Japanese term, at most 64 bytes, or `-` when unknown (`docs/strings.md`).
  For `community.tsv` rows it is written back from that row's romaji, so it is a lead too.
- mmx4 name: the name sozud/mmx4 uses for the same thing, or `-`.
- X5 name: the Mega Man X5 counterpart, or `-`.
- Our stem: the identifier stem for X6 names.
- Source: the lead file and its line, where the term was met.

A row is a lead until a basis row in `config/symbols/basis.tsv` backs a name built from it.
The column headed `Japanese` is the only place in `docs/` where Japanese script is legal.
The check is `python3 tools/mmx6/gamestr.py check`.

## Terms

| English term | Japanese | mmx4 name | X5 name | Our stem | Source |
|---|---|---|---|---|---|
| Guard Shell | ガードシェル | - | Spike Ball | guard_shell | docs/leads/x5.tsv:2 |
| Arrow Ray | アローレイ | - | Wing Spiral | arrow_ray | docs/leads/x5.tsv:3 |
| text box | - | - | dialogue box | text_box | docs/leads/x5.tsv:4 |
| Ride Armor slot | - | - | Ride Armor | ride_armor | docs/leads/x5.tsv:7 |
| player palette | - | - | X palette | player_palette | docs/leads/x5.tsv:8 |
| rank | - | - | - | rank | docs/leads/tweaks-index.tsv:146 |
| Nightmare effect | - | - | - | nightmare_effect | docs/leads/tweaks-index.tsv:154 |
| boss HP | - | - | - | boss_hp | docs/leads/tweaks-index.tsv:174 |
| damage and defense | - | - | - | apply_damage | docs/leads/tweaks-index.tsv:204 |
| air dash | - | - | - | air_dash | docs/leads/tweaks-index.tsv:216 |
| capsule | - | - | - | capsule | docs/leads/tweaks-index.tsv:219 |
| checkpoint | - | - | - | checkpoint | docs/leads/tcrf-proto.md:11 |
| stage id | - | - | - | stage_id | docs/leads/tcrf-proto.md:10 |
| boss rush | - | - | - | boss_rush | docs/leads/tcrf-proto.md:16 |
| Nightmare Soul | ナイトメアソウル | - | - | nightmare_soul | docs/leads/tcrf-proto.md:24 |
| Nightmare Soul gate | - | - | - | NIGHTMARE_SOUL_GATE | src/shared/SLUS_013.95/func_8001E32C.c (proto 5000, retail 3000) |
| High Max | ハイマックス | - | - | high_max | docs/leads/tcrf-proto.md:28 |
| Commander Yammark | コマンダー・ヤンマーク | - | - | commander_yammark | docs/leads/community.tsv:6 |
| Ground Scaravich | グランド・スカラビッチ | - | - | ground_scaravich | docs/leads/community.tsv:8 |
| Blizzard Wolfang | ブリザード・ヴォルファング | - | - | blizzard_wolfang | docs/leads/community.tsv:11 |
| Gate | ゲイト | - | - | gate | docs/leads/community.tsv:14 |
| Sigma, unfinished form | シグマ（不完全体） | - | - | sigma | docs/leads/community.tsv:15 |
| Nightmare Zero | ゼロナイトメア | - | - | nightmare_zero | docs/leads/community.tsv:18 |
| Dynamo | ダイナモ | - | Dynamo | dynamo | docs/leads/community.tsv:19 |
| hurt state | - | player_hurt | - | hurt | config/symbols/basis.tsv:8 |
| save file name | - | - | - | save_file | docs/leads/strings.tsv (SLUS_013.95 0x80010098) |
| memory card device | - | - | - | memcard | docs/leads/strings.tsv (SLUS_013.95 0x800100AC) |
| Rainy Turtloid | レイニー・タートロイド | - | - | rainy_turtloid | docs/leads/community.tsv:3 |
| Shieldner Sheldon | シールドナー・シェルドン | - | - | shieldner_sheldon | docs/leads/community.tsv:4 |
| Infinity Mijinion | インフィニティー・ミジニオン | - | - | infinity_mijinion | docs/leads/community.tsv:5 |
| Metalshark Player | メタルシャーク・プレイヤー | - | - | metalshark_player | docs/leads/community.tsv:7 |
| Blaze Heatnix | ブレイズ・ヒートニックス | - | - | blaze_heatnix | docs/leads/community.tsv:9 |
| Giant Turtloid | - | - | - | giant_turtloid | docs/leads/community.tsv:10 |
| Isoc | アイゾック | - | - | isoc | docs/leads/community.tsv:13 |
| Hell Sigma | ヘル・シグマ | - | - | hell_sigma | docs/leads/community.tsv:16 |
| D-1000 (intro stage boss) | - | - | - | d1000 | developer 2026-10-26, docs/leads/community.tsv:17, docs/leads/objects.tsv:146 |
| Nightmare Mother | ナイトメア・マザー | - | - | nightmare_mother | docs/leads/community.tsv:20 |
| Nightmare Snake | - | - | - | nightmare_snake | docs/leads/community.tsv:21 |
| Nightmare Virus | - | - | - | nightmare_virus | docs/leads/community.tsv:22 |
| Nightmare Bugs | - | - | - | nightmare_bugs | docs/leads/community.tsv:23 |
| Nightmare Wind | - | - | - | nightmare_wind | docs/leads/community.tsv:24 |
| Nightmare Mirror | - | - | - | nightmare_mirror | docs/leads/community.tsv:25 |
| Nightmare Ice | - | - | - | nightmare_ice | docs/leads/community.tsv:26 |
| Nightmare Fire | - | - | - | nightmare_fire | docs/leads/community.tsv:27 |
| Nightmare Darkness | - | - | - | nightmare_darkness | docs/leads/community.tsv:28 |
| Nightmare Iron | - | - | - | nightmare_iron | docs/leads/community.tsv:29 |
| Nightmare Cube | - | - | - | nightmare_cube | docs/leads/community.tsv:30 |
| Amazon Area | アマゾンエリア | - | - | amazon_area | docs/leads/community.tsv:31 |
| Magma Area | マグマエリア | - | - | magma_area | docs/leads/community.tsv:32 |
| Recycle Lab | リサイクル研究所 | - | - | recycle_lab | docs/leads/community.tsv:33 |
| North Pole Area | 北極エリア | - | - | north_pole_area | docs/leads/community.tsv:34 |
| Central Museum | セントラルミュージアム | - | - | central_museum | docs/leads/community.tsv:35 |
| Inami Temple | イナミテンプル | - | - | inami_temple | docs/leads/community.tsv:36 |
| Laser Lab | レーザー研究所 | - | - | laser_lab | docs/leads/community.tsv:37 |
| Weapons Lab | 兵器研究所 | - | - | weapons_lab | docs/leads/community.tsv:38 |
| Secret Lab 1 | 秘密研究所1 | - | - | secret_lab_1 | docs/leads/community.tsv:39 |
| Secret Lab 2 | 秘密研究所2 | - | - | secret_lab_2 | docs/leads/community.tsv:40 |
| Secret Lab 3 | 秘密研究所3 | - | - | secret_lab_3 | docs/leads/community.tsv:41 |
| Intro Stage | - | - | - | intro_stage | docs/leads/community.tsv:42 |
| Gate stage | - | - | - | gate_stage | docs/leads/community.tsv:43 |
| Final Stage | - | - | - | final_stage | docs/leads/community.tsv:43 |
| Yammar Option | ヤンマーオプション | - | - | yammar_option | docs/leads/community.tsv:44 |
| Ice Burst | アイスバースト | - | - | ice_burst | docs/leads/community.tsv:45 |
| Magma Blade | マグマブレード | - | - | magma_blade | docs/leads/community.tsv:46 |
| Metal Anchor | メタルアンカー | - | - | metal_anchor | docs/leads/community.tsv:47 |
| Ground Dash | グランドダッシュ | - | - | ground_dash | docs/leads/community.tsv:48 |
| Meteor Rain | メテオレイン | - | - | meteor_rain | docs/leads/community.tsv:49 |
| Zero technique, ice wolf fang | 氷狼牙 | - | - | hyorouga | docs/leads/community.tsv:52 |
| Zero technique, rising flame | 昇炎斬 | - | - | shoenzan | docs/leads/community.tsv:53 |
| Zero technique, falling steel blade | 落鋼刃 | - | - | rakkoujin | docs/leads/community.tsv:54 |
| Zero technique, spinning drop slash | 旋墜斬 | - | - | sentsuizan | docs/leads/community.tsv:55 |
| Zero technique, water circle slash | 円水斬 | - | - | ensuizan | docs/leads/community.tsv:56 |
| Zero technique, light burst | 裂光覇 | - | - | rekkoha | docs/leads/community.tsv:57 |
| Falcon Armor | ファルコンアーマー | - | - | falcon_armor | docs/leads/community.tsv:58 |
| Blade Armor | ブレードアーマー | - | - | blade_armor | docs/leads/community.tsv:59 |
| Shadow Armor | シャドーアーマー | - | - | shadow_armor | docs/leads/community.tsv:60 |
| Ultimate Armor | アルティメットアーマー | - | - | ultimate_armor | docs/leads/community.tsv:61 |
| Raiden (ride armor) | ライデン | ride_armor_punch_init | Ride Armor | raiden | docs/leads/community.tsv:62 |
| D-Barrier | - | - | - | d_barrier | docs/leads/community.tsv:63 |
| Speed Move | スピードムーブ | - | - | speed_move | docs/leads/community.tsv:64 |
| High Jump | ハイジャンプ | - | - | high_jump | docs/leads/community.tsv:65 |
| Hyper Dash | ハイパーダッシュ | - | - | hyper_dash | docs/leads/community.tsv:66 |
| Energy Saver | エナジーセイバー | - | - | energy_saver | docs/leads/community.tsv:67 |
| Super Recover | スーパーリカバー | - | - | super_recover | docs/leads/community.tsv:68 |
| Buster Plus | バスタープラス | - | - | buster_plus | docs/leads/community.tsv:69 |
| Speed Shot | スピードショット | - | - | speed_shot | docs/leads/community.tsv:70 |
| Shock Absorber | ショックアブソーバー | - | - | shock_absorber | docs/leads/community.tsv:71 |
| Double Barrier | ダブルバリア | - | - | double_barrier | docs/leads/community.tsv:72 |
| Change Energy | チェンジエナジー | - | - | change_energy | docs/leads/community.tsv:73 |
| Rapid 5 | ラピッド5 | - | - | rapid_5 | docs/leads/community.tsv:74 |
| Ultimate Buster | アルティメットバスター | - | - | ultimate_buster | docs/leads/community.tsv:75 |
| Hyper Charge | ハイパーチャージ | - | - | hyper_charge | docs/leads/community.tsv:76 |
| Master Weapon | マスターウェポン | - | - | master_weapon | docs/leads/community.tsv:77 |
| Saber Plus | セイバープラス | - | - | saber_plus | docs/leads/community.tsv:78 |
| Saber Extend | セイバーエクステンド | - | - | saber_extend | docs/leads/community.tsv:79 |
| Shot Eraser | ショットイレイザー | - | - | shot_eraser | docs/leads/community.tsv:80 |
| Master Saber | マスターセイバー | - | - | master_saber | docs/leads/community.tsv:81 |
| Hyper Drive | ハイパードライブ | - | - | hyper_drive | docs/leads/community.tsv:82 |
| Power Drive | パワードライブ | - | - | power_drive | docs/leads/community.tsv:83 |
| Weapon Drive | ウェポンドライブ | - | - | weapon_drive | docs/leads/community.tsv:84 |
| Life Recover | ライフリカバー | - | - | life_recover | docs/leads/community.tsv:85 |
| Weapon Recover | ウェポンリカバー | - | - | weapon_recover | docs/leads/community.tsv:86 |
| Overdrive | オーバードライブ | - | - | overdrive | docs/leads/community.tsv:87 |
| Life Up | ライフアップ | - | - | life_up | docs/leads/community.tsv:88 |
| Energy Up | エナジーアップ | - | - | energy_up | docs/leads/community.tsv:89 |
| Reploid rescue | - | - | - | rescue_unit | docs/leads/community.tsv:91 |
| Heart Tank | - | - | - | heart_tank | docs/leads/community.tsv:91 |
| Sub Tank | - | - | - | sub_tank | docs/leads/community.tsv:91 |
| armor piece | - | - | - | armor_piece | docs/leads/community.tsv:91 |
| music track: Moon Light | - | - | - | bgm | docs/leads/community.tsv:92 |
| music track: The Answer | - | - | - | bgm | docs/leads/community.tsv:93 |
| music track: I.D.E.A. | - | - | - | bgm | docs/leads/community.tsv:94 |
| archive member (ARC file) | - | - | DAT archive member | dat_member | docs/leads/community.tsv:99 |
| butterfly (enemy) | - | - | - | butterfly | docs/leads/objects.tsv:16 |
| purple guard robot | - | - | - | purple_guard_robot | docs/leads/objects.tsv:34 |
| Nightmare press | - | - | - | nightmare_press | docs/leads/objects.tsv:59 |
| hidden area teleport | - | - | - | hidden_area_teleport | docs/leads/objects.tsv:102 |
| hidden area (Nightmare Zero, High Max and Dynamo rooms, stage index 0x1300-0x1601) | - | - | - | hidden_area | refs/leads/tweaks/BossHealth.tsv:2571,2761,2840, docs/leads/objects.tsv:160,165 |
| surface hopper | - | surface_hopper | - | surface_hopper | docs/leads/objects.tsv:120 |
| intro boss (D-1000) | - | - | - | d1000 | docs/leads/objects.tsv:146, developer 2026-10-26 |
| enemy slot | - | - | - | enemy_slot | docs/leads/objects.tsv:338 |
| misc object slot | - | find_free_misc_obj | - | misc_obj | docs/leads/objects.tsv:343 |
| disc archive seek | - | - | - | bin_seek | docs/leads/ram.tsv:2 |
| file load group | - | - | - | load_files | docs/leads/ram.tsv:18 |
| loading screen | - | - | - | loading_screen | docs/leads/ram.tsv:12 |
| screen fade | - | - | - | fade | docs/leads/ram.tsv:16 |
| sound effect | - | - | - | se | docs/leads/ram.tsv:20 |
| music track | - | stage_music_init | - | bgm | docs/leads/ram.tsv:22 |
| task | - | - | - | task | docs/leads/ram.tsv:28 |
| pad buttons | - | - | - | pad | docs/leads/ram.tsv:33 |
| frame counter | - | - | - | frame_count | docs/leads/ram.tsv:40 |
| save block | - | - | - | save | docs/leads/ram.tsv:42 |
| ordering table | - | - | - | ot | docs/leads/ram.tsv:44 |
| scratchpad | - | - | - | scratchpad | docs/leads/ram.tsv:61 |
| background layer | - | update_layer_objects | - | layer | docs/leads/ram.tsv:70 |
| stage layout | - | - | - | stage_layout | docs/leads/ram.tsv:71 |
| dialogue-seen flag | - | - | - | dialogue_flag | docs/leads/ram.tsv:76 |
| player object | - | g_Player | - | g_player | docs/leads/ram.tsv:82 |
| animation | - | set_animation | - | animation | docs/leads/ram.tsv:83 |
| display queue | - | - | - | queue_display | docs/leads/ram.tsv:85 |
| random number | - | get_random | - | rand | docs/leads/ram.tsv:86 |
| stages cleared | - | - | - | stages_cleared | docs/leads/ram.tsv:90 |
| life gauge | - | - | - | life_gauge | docs/leads/ram.tsv:91 |
| weapon gauge | - | - | - | weapon_gauge | docs/leads/ram.tsv:92 |
| current stage | - | - | - | stage | docs/leads/ram.tsv:95 |
| player character | - | - | - | player_char | docs/leads/ram.tsv:96 |
| lives | - | - | - | lives | docs/leads/ram.tsv:97 |
| selectable armor | - | - | - | armor_select | docs/leads/ram.tsv:99 |
| story progress | - | - | - | story_progress | docs/leads/ram.tsv:101 |
| difficulty | - | - | - | difficulty | docs/leads/ram.tsv:102 |
| equippable parts | - | - | - | parts | docs/leads/ram.tsv:107 |
| soul count | - | - | - | souls | docs/leads/ram.tsv:108 |
| screen handler | - | - | - | screen | docs/leads/ram.tsv:112 |
| end credits | - | - | - | credits | docs/leads/ram.tsv:113 |
| player death | - | player_spawn_death_orb | - | player_death | docs/leads/ram.tsv:120 |
| player state | - | player_common | - | player_state | docs/leads/ram.tsv:122 |
| life bar | - | - | - | life_bar | docs/leads/ram.tsv:125 |
| armor in use | - | - | - | armor | docs/leads/ram.tsv:127 |
| navigator | - | - | - | navigator | docs/leads/ram.tsv:129 |
| stage-select briefing | - | - | - | briefing | docs/leads/ram.tsv:130 |
| text speed | - | - | - | text_speed | docs/leads/ram.tsv:132 |
| text auto-advance | - | - | message box confirm wait | text_advance | docs/leads/ram.tsv:134 |
| logo | - | - | - | logo | docs/leads/ram.tsv:140 |
| opening video | - | - | - | opening_movie | docs/leads/ram.tsv:142 |
| attract demo | - | - | - | demo | docs/leads/ram.tsv:143 |
| stage exit | - | - | - | stage_exit | docs/leads/ram.tsv:144 |
| stage effect | - | effects | - | stage_effect | docs/leads/ram.tsv:146 |
| overlay | - | - | - | overlay | docs/leads/ram.tsv:149 |
| new game | - | - | - | new_game | docs/leads/ram.tsv:155 |
| boss life bar | - | - | - | boss_life_bar | docs/leads/ram.tsv:163 |
| music stream table | - | - | - | bgm_table | docs/leads/ram.tsv:165 |
| stage select | - | - | stage-select subscreens | stage_select | docs/leads/ram.tsv:169 |
| damage table | - | - | Ride Armor attacks | damage_table | docs/leads/ram.tsv:176 |
| hit detection | - | - | - | hit_check | docs/leads/ram.tsv:177 |
| disc file LBA | - | - | - | lba | docs/leads/tweaks-index.tsv:31 |
| screen resolution switch | - | - | - | res_switch | docs/leads/tweaks-index.tsv:36 |
| mugshot | - | - | X5 boss icon | mugshot | docs/leads/tweaks-index.tsv:43 |
| playthrough state | - | - | - | playthrough | docs/leads/tweaks-index.tsv:49 |
| in-game state | - | - | - | ingame | docs/leads/tweaks-index.tsv:103 |
| object type table | - | stage_objects | - | obj_type | docs/leads/tweaks-index.tsv:134 |
| object origin table | - | - | - | obj_origin | docs/leads/tweaks-index.tsv:138 |
| shared stats | - | - | - | shared_stats | docs/leads/tweaks-index.tsv:140 |
| unlockables | - | - | - | unlock | docs/leads/tweaks-index.tsv:149 |
| boss modifier | - | - | - | boss_mod | docs/leads/tweaks-index.tsv:161 |
| armor skill | - | player_special | - | armor_skill | docs/leads/tweaks-index.tsv:184 |
| Zero skill | - | ZeroObjectState | - | zero_skill | docs/leads/tweaks-index.tsv:221 |
| auto-crouch | - | - | - | crouch | docs/leads/tweaks-index.tsv:251 |
| saber animation | - | - | - | saber_anim | docs/leads/tweaks-index.tsv:272 |
| offense damage | - | - | - | damage | docs/leads/tweaks-index.tsv:275 |
| continue | - | - | - | continue | docs/leads/tweaks-index.tsv:282 |
| pause menu | - | - | - | pause_menu | docs/leads/tweaks-index.tsv:292 |
| menu alignment | - | - | - | menu_align | docs/leads/tweaks-index.tsv:301 |
| dialogue | - | - | dialogue box | dialogue | docs/leads/tweaks-index.tsv:304 |
| cutscene trigger | - | - | - | cutscene | docs/leads/tweaks-index.tsv:308 |
| voiced cutscene | - | - | - | voice | docs/leads/tweaks-index.tsv:316 |
| sound bank (VAB) | - | - | - | vab | docs/leads/tweaks-index.tsv:322 |
| mission report | - | - | - | mission_report | docs/leads/tweaks-index.tsv:334 |
| rescued Reploids | - | - | - | rescue | docs/leads/tweaks-index.tsv:348 |
| text colour | - | - | - | text_color | docs/leads/tweaks-index.tsv:354 |
| map edit | - | - | - | map | docs/leads/tweaks-index.tsv:388 |
| title menu | - | - | - | title_menu | docs/leads/tweaks-index.tsv:397 |
| sprite display table | - | - | - | sprite_table | docs/leads/tweaks-index.tsv:402 |
| Black Zero | - | - | - | black_zero | docs/leads/tcrf-proto.md:9 |
| alternate route (AR) stage | - | - | - | stage_ar | docs/leads/tcrf-proto.md:21 |
| Xtreme difficulty | - | - | - | xtreme | docs/leads/tcrf-proto.md:25 |
| boss weakness table | - | - | - | weakness | docs/leads/tcrf-proto.md:26 |
| Alia call | - | - | - | alia_call | docs/leads/tcrf-proto.md:32 |
| mirror hologram | - | - | - | mirror_hologram | docs/leads/tcrf-proto.md:33 |
| wall slide | - | player_enter_wall_cling | - | wall_slide | docs/leads/tcrf-proto.md:37 |
| Z-Saber | - | - | - | z_saber | docs/leads/tcrf-proto.md:37 |
| overlay archive | - | - | - | rock_bin | docs/leads/assets.tsv:3 |
| disc archive | - | - | DAT archive | rock_dat | docs/leads/assets.tsv:4 |
| Capcom logo video | - | - | - | caplogo | docs/leads/assets.tsv:6 |
| disc padding file | - | - | - | znull | docs/leads/assets.tsv:11 |
| BGM XA track (XA music) | - | - | - | bgm_xa | docs/leads/assets.tsv:9, docs/leads/assets.tsv:257 |
| demo XA track (XA voice) | - | - | - | demo_xa | docs/leads/assets.tsv:10, docs/leads/assets.tsv:258 |
| STR movie | - | - | - | str_movie | docs/leads/assets.tsv:256 |
| VAB sound bank record | - | - | - | vab_record | docs/leads/assets.tsv:261 |
| archive CD path table | - | - | - | rock_dat_cd_file_names | docs/leads/assets.tsv:6 |
| disc archive file table | - | - | - | rock_dat_file_table | docs/leads/assets.tsv:4 |
| overlay archive file table | - | - | - | rock_bin_file_table | docs/leads/assets.tsv:3 |
| PsyQ startup object (2MBYTE) | - | - | - | 2mbyte | config/psyq/names.tsv:2 |
| PsyQ kernel and BIOS call library (LIBAPI) | - | - | - | libapi | config/psyq/names.tsv:390 |
| PsyQ C runtime library (LIBC) | - | - | - | libc | config/psyq/names.tsv:382 |
| PsyQ memory card library (LIBCARD) | - | - | - | libcard | config/psyq/names.tsv:363 |
| PsyQ CD-ROM library (LIBCD) | - | - | - | libcd | config/psyq/names.tsv:208 |
| PsyQ data streaming library (LIBDS) | - | - | - | libds | config/psyq/names.tsv:257 |
| PsyQ system services library (LIBETC) | - | - | - | libetc | config/psyq/names.tsv:180 |
| PsyQ graphics processor library (LIBGPU) | - | - | - | libgpu | config/psyq/names.tsv:284 |
| PsyQ geometry engine library (LIBGTE) | - | - | - | libgte | config/psyq/names.tsv:275 |
| PsyQ controller library (LIBPAD) | - | - | - | libpad | config/psyq/names.tsv:444 |
| PsyQ image decompression library (LIBPRESS) | - | - | - | libpress | config/psyq/names.tsv:344 |
| PsyQ sound sequence library (LIBSND) | - | - | - | libsnd | config/psyq/names.tsv:29 |
| PsyQ sound processor library (LIBSPU) | - | - | - | libspu | config/psyq/names.tsv:6 |
| archive file table | - | - | - | file_table | docs/leads/strings.tsv:3 |
| memory card file list | - | - | - | memcard_list_files | docs/leads/strings.tsv:6 |
| memory card format | - | - | - | memcard_format | docs/leads/strings.tsv:6 |
| CD new media (directory read) | - | - | - | CD_newmedia | docs/leads/strings.tsv:26 |
| CD directory file cache | - | - | - | CD_cachefile | docs/leads/strings.tsv:33 |
| MDEC reset | - | - | - | MDEC_rest | docs/leads/strings.tsv:107 |
| MDEC input sync | - | - | - | MDEC_in_sync | docs/leads/strings.tsv:108 |
| MDEC output sync | - | - | - | MDEC_out_sync | docs/leads/strings.tsv:109 |
| reads a DAT file by index | - | - | - | read_dat_file | docs/leads/tweaks-index.tsv:33 |
| wide/normal display mode flag | - | - | - | g_wide_mode | docs/leads/tweaks-index.tsv:36 |
| current horizontal resolution | - | - | - | g_screen_width | docs/leads/tweaks-index.tsv:37 |
| switches screen resolution | - | - | - | set_resolution | docs/leads/tweaks-index.tsv:38 |
| loading screen per-call step | - | - | - | init_loading_screen | docs/leads/tweaks-index.tsv:40 |
| game progress struct, also the save image | - | - | - | g_playthrough_state | docs/leads/tweaks-index.tsv:49 |
| enemy/boss object array, stride 0x9C | - | - | - | g_enemies | docs/leads/tweaks-index.tsv:134 |
| projectile object array | - | - | - | g_projectiles | docs/leads/tweaks-index.tsv:136 |
| Yammark projectile setup, difficulty branch, speed | - | - | - | init_yammark_projectile | docs/leads/tweaks-index.tsv:162 |
| Wolfang ice spikes, level gate | - | - | - | init_wolfang_ice_spike | docs/leads/tweaks-index.tsv:168 |
| boss level by player rank, 8 entries | - | - | - | boss_level_by_rank | docs/leads/tweaks-index.tsv:172 |
| sets current boss level from rank | - | - | - | set_boss_level | docs/leads/tweaks-index.tsv:173 |
| Nightmare Pressure sub-boss start | - | - | - | init_nightmare_pressure | docs/leads/tweaks-index.tsv:182 |
| Illumina sub-boss start | - | - | - | init_illumina | docs/leads/tweaks-index.tsv:183 |
| dust animation start | - | - | - | spawn_dust | docs/leads/tweaks-index.tsv:186 |
| sliding-down state routine | - | - | - | handle_slide_down | docs/leads/tweaks-index.tsv:188 |
| dust animation control, stops on wall let-go/kick | - | - | - | update_dust | docs/leads/tweaks-index.tsv:190 |
| ceiling jump input (Shadow legs, Zero Hyoroga) | - | - | - | check_ceiling_jump | docs/leads/tweaks-index.tsv:192 |
| ceiling jump execution, duration per character | - | - | - | perform_ceiling_jump | docs/leads/tweaks-index.tsv:193 |
| Hyoroga attack from ceiling | - | - | - | attack_hyoroga_from_ceiling | docs/leads/tweaks-index.tsv:194 |
| end of ceiling dash | - | - | - | end_ceiling_dash | docs/leads/tweaks-index.tsv:195 |
| X saber start | - | - | - | start_saber | docs/leads/tweaks-index.tsv:197 |
| Shadow armor attack execution, sfx ids | - | - | - | update_shadow_armor_attack | docs/leads/tweaks-index.tsv:198 |
| giga attack input, armor checks, execution | - | - | - | check_giga_attack | docs/leads/tweaks-index.tsv:202 |
| pause menu display | - | - | - | setup_pause_menu | docs/leads/tweaks-index.tsv:203 |
| damage taken scaled by armor and difficulty | - | - | - | scale_damage | docs/leads/tweaks-index.tsv:204 |
| charging special weapons by armor | - | - | - | charge_special_weapon | docs/leads/tweaks-index.tsv:207 |
| energy cost by armor and parts | - | - | - | get_weapon_energy_cost | docs/leads/tweaks-index.tsv:208 |
| energy deduction on shot | - | - | - | use_weapon_energy | docs/leads/tweaks-index.tsv:209 |
| buster shot sfx by shot type | - | - | - | init_buster_shot_visual | docs/leads/tweaks-index.tsv:214 |
| Shadow armor shuriken buster | - | - | - | init_shuriken_buster | docs/leads/tweaks-index.tsv:215 |
| air dash picked by armor | - | - | - | select_air_dash | docs/leads/tweaks-index.tsv:216 |
| armor part given by each stage capsule | - | - | - | capsule_parts | docs/leads/tweaks-index.tsv:218 |
| capsule appearance checks parts | - | - | - | init_capsule | docs/leads/tweaks-index.tsv:219 |
| capsule applies part, mugshot, saber palette | - | - | - | apply_capsule_part | docs/leads/tweaks-index.tsv:220 |
| weapon menu-select input | - | - | - | switch_weapon | docs/leads/tweaks-index.tsv:221 |
| Yammar Option fireflies, ammo | - | - | - | init_yammar_option | docs/leads/tweaks-index.tsv:223 |
| Rekkoha input (Zero) | - | - | - | start_rekkoha | docs/leads/tweaks-index.tsv:226 |
| Guard Shell activation and ammo use | - | - | - | update_guard_shell | docs/leads/tweaks-index.tsv:228 |
| jump rising state | - | - | - | handle_jump_rise | docs/leads/tweaks-index.tsv:231 |
| dash input incl. double tap | - | - | - | check_dash_input | docs/leads/tweaks-index.tsv:243 |
| Blade hover boots execution | - | - | - | start_hover | docs/leads/tweaks-index.tsv:244 |
| Falcon dash start | - | - | - | start_falcon_dash | docs/leads/tweaks-index.tsv:246 |
| Mach Dash end | - | - | - | end_dash | docs/leads/tweaks-index.tsv:248 |
| ceiling movement step | - | - | - | move_ceiling | docs/leads/tweaks-index.tsv:253 |
| player/ceiling position compare | - | - | - | clamp_player_to_ceiling | docs/leads/tweaks-index.tsv:257 |
| general box collision check | - | - | - | check_box_collision | docs/leads/tweaks-index.tsv:258 |
| in-game input reading | - | - | - | read_player_input | docs/leads/tweaks-index.tsv:260 |
| default difficulty and speed | - | - | - | default_options | docs/leads/tweaks-index.tsv:265 |
| title screen demo timer | - | - | - | tick_title_demo_timer | docs/leads/tweaks-index.tsv:268 |
| item drop, off on Xtreme | - | - | - | drop_item | docs/leads/tweaks-index.tsv:271 |
| attack slots tested against enemies | - | - | - | check_enemy_hits | docs/leads/tweaks-index.tsv:275 |
| player attack hit detection | - | - | - | check_attack_hit | docs/leads/tweaks-index.tsv:277 |
| High Max intro-stage behaviour | - | - | - | init_high_max_intro | docs/leads/tweaks-index.tsv:279 |
| rescued reploid reward | - | - | - | rescue_reploid | docs/leads/tweaks-index.tsv:285 |
| options list display and toggles | - | - | - | init_options_menu | docs/leads/tweaks-index.tsv:292 |
| options menu values | - | - | - | option_values | docs/leads/tweaks-index.tsv:296 |
| options menu label tiles and positions | - | - | - | option_labels | docs/leads/tweaks-index.tsv:297 |
| options menu cursor/switch positions | - | - | - | option_cursors | docs/leads/tweaks-index.tsv:298 |
| temp options and level in menus | - | - | - | g_temp_options | docs/leads/tweaks-index.tsv:299 |
| new game status init | - | - | - | init_new_game | docs/leads/tweaks-index.tsv:302 |
| scene triggers after stage clear | - | - | - | exit_stage_by_clear | docs/leads/tweaks-index.tsv:308 |
| scene triggers on exit stage | - | - | - | exit_stage_from_menu | docs/leads/tweaks-index.tsv:310 |
| read input subroutine | - | - | - | map_buttons | docs/leads/tweaks-index.tsv:321 |
| VAB play #1 | - | - | - | play_sound | docs/leads/tweaks-index.tsv:324 |
| X charged shot sound | - | - | - | fire_charged_shot | docs/leads/tweaks-index.tsv:327 |
| low health voice site | - | - | - | check_low_health | docs/leads/tweaks-index.tsv:328 |
| boss intro sound step | - | - | - | tick_boss_intro | docs/leads/tweaks-index.tsv:329 |
| title screen voice | - | - | - | init_title_screen | docs/leads/tweaks-index.tsv:331 |
| end of Mission Report, Gate check | - | - | - | build_mission_report_list | docs/leads/tweaks-index.tsv:344 |
| enemy orb drop and value | - | - | - | init_orb | docs/leads/tweaks-index.tsv:349 |
| orb registered until Nightmare reset | - | - | - | register_orb | docs/leads/tweaks-index.tsv:351 |
| font colour index by speaker | - | - | - | speaker_colors | docs/leads/tweaks-index.tsv:355 |
| text box first page | - | - | - | open_text_box | docs/leads/tweaks-index.tsv:362 |
| text box following pages | - | - | - | update_text_box | docs/leads/tweaks-index.tsv:363 |
| generic reset at level start | - | - | - | reset_level | docs/leads/tweaks-index.tsv:371 |
| player mugshot selection | - | - | - | get_player_mugshot | docs/leads/tweaks-index.tsv:374 |
| player file selection on loading screen | - | - | - | load_player_files | docs/leads/tweaks-index.tsv:375 |
| free slot in displayed sprites table | - | - | - | alloc_sprite_slot | docs/leads/tweaks-index.tsv:379 |
| displayed sprites table, stride 0x60 | - | - | - | g_displayed_sprites | docs/leads/tweaks-index.tsv:380 |
| on-the-fly palette load | - | - | - | load_palette | docs/leads/tweaks-index.tsv:381 |
| free-slot allocator of object class N (3, 4, 6, 7), one pool per class | - | find_free_effect_obj (class 3) | - | alloc_class<N>_slot | docs/leads/objects.tsv:341-345 |
| D-1000 boss update | - | - | - | update_d1000 | refs/leads/tweaks/BossHealth.tsv:233 |
| High Max (Intro Stage) update | - | - | - | update_high_max_intro | refs/leads/tweaks/BossHealth.tsv:284 |
| Commander Yammark update | - | - | - | update_commander_yammark | refs/leads/tweaks/BossHealth.tsv:1346 |
| Blizzard Wolfang update | - | - | - | update_blizzard_wolfang | refs/leads/tweaks/BossHealth.tsv:1574 |
| Nightmare Snake update | - | - | - | update_nightmare_snake | refs/leads/tweaks/BossHealth.tsv:366 |
| Nightmare Pressure update | - | - | - | update_nightmare_pressure | refs/leads/tweaks/BossHealth.tsv:1294 |
| Ground Scaravich update | - | - | - | update_ground_scaravich | refs/leads/tweaks/BossHealth.tsv:1774 |
| Sigma, first form, update | - | - | - | update_sigma_1 | refs/leads/tweaks/BossHealth.tsv:2403 |
| High Max (Secret Lab 2-1) update | - | - | - | update_high_max_secret_lab2_1 | refs/leads/tweaks/BossHealth.tsv:2224 |
| Gate boss update | - | - | - | update_gate | refs/leads/tweaks/BossHealth.tsv:2303 |
| Commander Yammark (Boss Rush) update | - | - | - | update_commander_yammark_boss_rush | refs/leads/tweaks/BossHealth.tsv:2986 |
| Blizzard Wolfang (Boss Rush) update | - | - | - | update_blizzard_wolfang_boss_rush | refs/leads/tweaks/BossHealth.tsv:3214 |
| Ground Scaravich (Boss Rush) update | - | - | - | update_ground_scaravich_boss_rush | refs/leads/tweaks/BossHealth.tsv:3414 |
| Nightmare Zero (Hidden Area) update | - | - | - | update_nightmare_zero | refs/leads/tweaks/BossHealth.tsv:2571 |
| High Max (Hidden Areas) update | - | - | - | update_high_max_hidden_area | refs/leads/tweaks/BossHealth.tsv:2761 |
| create a task | - | - | - | create_task | docs/leads/ram.tsv:28 |
| task yield for frames | - | - | - | task_yield | docs/leads/ram.tsv:30 |
| end a task, second form | - | - | - | end_task_slot | docs/leads/ram.tsv:32 |
| gather and load files | - | - | - | pump_file_loads | docs/leads/ram.tsv:18 |
| silence sound | - | - | - | silence_sound | docs/leads/ram.tsv:21 |
| set an animation frame | - | - | - | set_animation_frame | docs/leads/ram.tsv:89 |
| pick music for the current stage | - | - | - | play_stage_bgm | docs/leads/ram.tsv:168 |
| stop music | - | - | - | stop_cd_audio | docs/leads/ram.tsv:15 |
| spawn setup | - | - | - | init_checkpoint_positions | docs/leads/ram.tsv:81 |
| object removal call target | - | - | - | clear_object_slot | docs/leads/ram.tsv:148 |
| random number | - | - | - | random_byte | docs/leads/ram.tsv:86 |
| write a rescue-unit status | - | - | - | set_reploid_status | docs/leads/ram.tsv:77 |
| read a rescue-unit status | - | - | - | get_reploid_status | docs/leads/ram.tsv:75 |
| test a dialogue-seen flag | - | - | - | is_text_box_seen | docs/leads/ram.tsv:76 |
| set a dialogue-seen flag | - | - | - | set_text_box_seen | docs/leads/ram.tsv:78 |
| per-stage music cue table | - | - | - | g_stage_bgm_tracks | docs/leads/ram.tsv:166 |
| screen handler table | - | - | - | g_playthrough_state_handlers | docs/leads/ram.tsv:112 |
| player top-level state jump table | - | - | - | g_player_state_handlers | docs/leads/ram.tsv:122 |
| stage layout size | - | - | - | g_tilemap_layer_stride | docs/leads/ram.tsv:73 |
| draw list pointer | - | - | - | g_cur_draw_info | docs/leads/ram.tsv:62 |
| rectangle list | - | - | - | g_bg_sprite_prims | docs/leads/ram.tsv:64 |
| pad 1 buttons down | - | - | - | g_pad1_buttons | docs/leads/ram.tsv:33 |
| drawing settings | - | - | - | g_draw_info_buffers | docs/leads/ram.tsv:63 |
| pad 2 buttons down | - | - | - | g_pad2_buttons | docs/leads/ram.tsv:36 |
| stage layout width | - | - | - | g_tilemap_width | docs/leads/ram.tsv:71 |
| stage layout height | - | - | - | g_tilemap_height | docs/leads/ram.tsv:72 |
