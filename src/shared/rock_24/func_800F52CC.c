#include "common.h"
#define M2C_UNK s32

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F52CC(void* arg0) {
    s32 temp_v0;

    temp_v0 = F(arg0, u16*, 0x7C) + 1;
    F(arg0, u16*, 0x7C) = temp_v0;
    if ((s16)temp_v0 == 0x78) {
        F(arg0, u16*, 0x7C) = 0;
        F(arg0, u16*, 0x88) = F(arg0, u16*, 0xA);
        F(arg0, u8*, 0x5) = F(arg0, u8*, 0x5) + 1;
    }
    if (F(arg0, s16*, 0x7C) < 0x3C || (F(arg0, u16*, 0x7C) & 1)) {
        func_8002CCB0(arg0, 0x30, 0x40);
    }
}
