#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
extern s32 D_80097420;

void func_80038248(void* arg0) {
    if (D_80097420 & 1) {
        ((M2C_UNK(*)())func_80017A04)();
    }
    if ((M2C_FIELD(arg0, s8*, 7) == 0) || (--M2C_FIELD(arg0, s8*, 7) == 0)) {
        M2C_FIELD(arg0, s8*, 0x67) = -1;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 5) = 7;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x100);
    }
}
