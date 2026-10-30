#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002D230();

void func_800F372C(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 5);
        M2C_FIELD(arg0, u8*, 6) += 1;
        return;
    }
    func_8002D230(arg0);
}
