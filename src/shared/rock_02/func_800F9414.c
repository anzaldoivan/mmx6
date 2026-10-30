#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void* alloc_sprite_slot();
extern u8 D_8008EAFC;

void func_800F9414(u8* arg0) {
    u8* temp_v0;

    if (D_8008EAFC == 0) {
        temp_v0 = alloc_sprite_slot();
        if (temp_v0 != 0) {
            temp_v0[0] = 0x41;
            temp_v0[1] = 8;
            temp_v0[2] = 1;
        }
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        arg0[6] = 0x14;
        arg0[5] = arg0[5] + 1;
    }
}
