#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern u8 D_800970B5;

void func_800FC3FC(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0xA);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
    M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
    M2C_FIELD(arg0, u8*, 0x61) = 0x19;
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x5) += 1;
    func_8003D308(0x14, D_800970B5);
    func_8002CCB0(arg0, 0x40, 0x40);
}
