#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_800179A4(void*, s32);
s32 func_8002D2D4();

void func_800F3230(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 3) {
        M2C_FIELD(arg0, s8*, 7) = 0;
        func_800179A4(arg0, 3);
        if (!(func_8002D2D4() & 1)) {
            func_80016C48(2, 0x27, arg0);
        } else {
            func_80016C48(2, 0x28, arg0);
        }
        M2C_FIELD(arg0, s8*, 6) = 2;
    }
}
