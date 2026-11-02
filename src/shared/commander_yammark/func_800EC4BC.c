#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F73F0;
extern M2C_UNK D_800F73F8;
extern M2C_UNK D_800F7400;

void func_800EC4BC(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 2);
    M2C_FIELD(arg0, void**, 0x68) = &D_800F73F0;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F7400;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F73F8;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, u8*, 0x7) += 1;
}
