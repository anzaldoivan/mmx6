#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */

void func_800F2E90(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x8E);
    M2C_FIELD(arg0, u16*, 0x8E) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x51) {
        play_sound(2, 0x14, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 5);
        M2C_FIELD(arg0, u16*, 0x8E) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
