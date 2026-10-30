#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800EC574(void* arg0) {
    s32 temp_v0;

    ((void (*)())func_80017A04)();
    temp_v0 = M2C_FIELD(arg0, s32*, 0x80) - 1;
    M2C_FIELD(arg0, s32*, 0x80) = temp_v0;
    if (temp_v0 == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        M2C_FIELD(arg0, s8*, 0x5) = 4;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
    }
}
