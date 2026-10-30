#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_80017A04();                     /* extern */
M2C_UNK func_8002D230(void*);                /* extern */

void func_800F3A90(void* arg0) {
    ((void (*)(void*))func_80017A04)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x74, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 4);
        M2C_FIELD(arg0, s16*, 0x8C) = 0x14;
        M2C_FIELD(arg0, u8*, 0x7) = 0xA;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        return;
    }
    ((void (*)(void*))func_8002D230)(arg0);
}
