#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F6684(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0xA) {
        func_80016C48(2, 0x1D, arg0);
        func_80012D9C(7);
    }
    if (M2C_FIELD(arg0, s16*, 0x7C)++ >= 0x3D) {
        func_800179A4(arg0, 8);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        {
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}
