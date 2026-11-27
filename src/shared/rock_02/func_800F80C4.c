// rolefeed (3.1 T4): func_800F80C4 of src/rock_02/E9860.c

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_800F82C0();

void func_800F80C4(void* arg0) {
    u16 t;

    ((void (*)())animate_object)();
    ((void (*)())func_800F82C0)(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0x3C) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, 0x13);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
    if (SPAD[0x8A] != 0x11) {
        ((void (*)(void*, s32))set_animation)(arg0, 0x13);
        M2C_FIELD(arg0, u8*, 0x6) = 5;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
}
