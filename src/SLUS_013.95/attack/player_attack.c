// 0x8003F864 start_player_attack: jump table on the attack id (byte 0x96) to start_saber and nine other attack starters.
// basis: xref start_saber (docs/leads/derived.tsv:24)
// callers: func_8003E06C, try_shoot_in_air, try_shoot_on_ladder, try_start_attack, try_start_shot_attack
// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/3CE30", start_player_attack);
// clang-format on
