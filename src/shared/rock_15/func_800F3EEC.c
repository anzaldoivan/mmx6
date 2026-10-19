#include "common.h"
#define M2C_UNK s32

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();

void func_800F3EEC(void* arg0) {
    ((void (*)())func_80017A04)();
    if (F(arg0, s16*, 0x8C)++ >= 0x79) {
        F(arg0, u16*, 0x8C) = 0;
        F(arg0, u8*, 6) += 1;
    }
}
