// prog SLUS_013.95 | system movement | range 0x8003A980-0x8003A9C0
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void player_clear_attack();           /* extern */
void clear_flash_palette(void* arg0); /* extern */

// 0x8003A980 cancel_player_attack: sets byte +0xCF, clears dash_momentum and afterimage, then calls two helpers.
// basis: code via=clear_flash_palette; derived.tsv:153
// callers: update_player_damage
void cancel_player_attack(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xCF) = 1;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s8*, 0x8C) = 0;
    player_clear_attack();
    clear_flash_palette(arg0);
}

void func_8003A9BC(void) {
}
