#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_800F82C0();

void func_800F7CFC(void* arg0) {
    s16 t;

    ((void (*)(void*))func_80017A04)(arg0);
    ((void (*)(void*))func_800F82C0)(arg0);
    t = M2C_FIELD(arg0, s16*, 0x7C)++;
    if (t >= 0x3C) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, u8*, 0x6)++;
        return;
    }
    if (SPAD4C[0x8A] != 0x11) {
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, u8*, 0x6) = 5;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
}
