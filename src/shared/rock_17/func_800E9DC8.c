#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002B2F8(s32);
extern s8 D_800EAACC;

void func_800E9DC8(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 4) == 0) {
        func_8002B2F8(0);
        D_800EAACC = 1;
        M2C_FIELD(arg0, s16*, 4) = 0x1E;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
