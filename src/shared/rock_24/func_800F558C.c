#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800F77EC;
extern s32 D_800F77F4;

void func_800F558C(void* arg0) {
    u32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u32*, 0x8C) + 1;
    M2C_FIELD(arg0, u32*, 0x8C) = temp_v1;
    if (temp_v1 < 0x14U) {
        if (temp_v1 & 1) {
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        }
    } else {
        D_800F77F4 = 0;
        D_800F77EC -= 1;
        ((void (*)())func_8002C9B0)(arg0);
    }
}
