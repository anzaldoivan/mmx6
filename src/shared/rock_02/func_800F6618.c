#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
extern u8 D_800CCF5F;

void func_800F6618(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 7);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    if (D_800CCF5F == 0) {
        M2C_FIELD(arg0, s16*, 0x7E) = 1;
    } else if (D_800CCF5F == 1) {
        M2C_FIELD(arg0, s16*, 0x7E) = 2;
    } else if (D_800CCF5F == 2) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
    } else {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
    }
}
