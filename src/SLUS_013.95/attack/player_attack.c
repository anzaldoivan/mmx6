// 0x8003F864 start_player_attack: jump table on the attack id (byte 0x96) to start_saber and nine other attack starters.
// basis: xref start_saber (docs/leads/derived.tsv:24)
// callers: func_8003E06C, func_8003E174, func_8003E260, func_8003F13C, func_8003F644
// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", start_player_attack);
// clang-format on
