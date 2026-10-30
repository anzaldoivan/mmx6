#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */

void func_800F9DE0(void* arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8*, 0x54) - 1;
    M2C_FIELD(arg0, u8*, 0x54) = temp_v0;
    if ((temp_v0 << 0x18) == 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0xB, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
