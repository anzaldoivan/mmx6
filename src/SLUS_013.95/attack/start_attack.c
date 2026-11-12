// prog SLUS_013.95 | system attack | range 0x8003F13C-0x8003F1FC
#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
M2C_UNK player_set_animation(void*, M2C_UNK);
s32 check_giga_attack(void* self);
void try_fire_shot(void* arg0);
void start_player_attack(void* arg0, s32 arg1);

#define B(o) (*(s8*)((u8*)self + (o)))

s32 try_start_attack(void* self) {
    s8 t;

    if (B(0xD3) != 0) {
        return 0;
    }
    if (B(0x2) != 0) {
        return 0;
    }
    if (check_giga_attack(self) != 0) {
        return 1;
    }
    try_fire_shot(self);
    if (B(0x8F) == 0) {
        return 0;
    }
    t = B(0x96);
    if (D_80073E00[t] == 0) {
        return 0;
    }
    B(0x84) = 0;
    B(0x86) = 0;
    B(0x8C) = 0;
    if (t == 5 || t == 0xE) {
        player_set_animation(self, 0x58);
    }
    start_player_attack(self, 0);
    return 1;
}

#undef B
