#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_80073D58;
extern M2C_UNK D_80073D5C;

void func_8003CD00(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD5) < 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x68) = NULL;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_80073D58;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_80073D5C;
}
