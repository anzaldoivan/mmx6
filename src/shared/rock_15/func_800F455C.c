#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_800F1DA8(void*, s32, s32);

void func_800F455C(void* arg0) {
    s8 st;

    ((void (*)())func_80017A04)();
    st = M2C_FIELD(arg0, s8*, 0x45);
    if (st == 1) {
        M2C_FIELD(arg0, u16*, 0xE) -= 0x10;
        func_800F1DA8(arg0, 3, 1);
        M2C_FIELD(arg0, u16*, 0xE) += 0x10;
    } else if (st == 2) {
        ((void (*)(void*, s32))set_animation)(arg0, 0xC);
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
        M2C_FIELD(arg0, u8*, 6) -= 1;
    }
}
