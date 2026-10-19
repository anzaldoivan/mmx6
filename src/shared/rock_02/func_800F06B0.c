#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800F06B0(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0xE) < 0x131) {
        M2C_FIELD(arg0, s16*, 0xE) = 0x130;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 5) = 4;
        M2C_FIELD(arg0, u8*, 6) = 1;
    }
}
