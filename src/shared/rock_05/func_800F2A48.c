#include "common.h"
#define M2C_UNK s32

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F2A48(void* arg0) {
    if (F(arg0, s8*, 0x45) < 0x10) {
        func_800179A4(arg0, 0);
    }
    F(arg0, s32*, 0x20) = 0;
    F(arg0, s32*, 0x24) = 0;
    F(arg0, s32*, 0x68) = 0;
    F(arg0, u8*, 6) += 1;
}
