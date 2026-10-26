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
| XA music | - | - | - | xa_bgm | docs/leads/assets.tsv:9 |
| XA voice | - | - | - | xa_demo | docs/leads/assets.tsv:10 |
| disc padding file | - | - | - | znull | docs/leads/assets.tsv:11 |
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
