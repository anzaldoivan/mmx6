#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1DA8(void*, s32, s32);
extern M2C_UNK D_800F67C0;
extern M2C_UNK D_800F67C4;

void func_800F2910(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = temp_v0 + 1;
    if ((s16)temp_v0 >= 0xE) {
        M2C_FIELD(arg0, void**, 0x50) = &D_800F67C4;
    }
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, void**, 0x50) = &D_800F67C0;
        func_800F1DA8(arg0, 8, 2);
        M2C_FIELD(arg0, s8*, 7) = 1;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
