#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800EE390(void* arg0) {
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x5A ||
        M2C_FIELD(arg0, u8*, 0x88) != 0) {
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        M2C_FIELD(arg0, s32*, 0x24) = 0x10000;
        M2C_FIELD(arg0, u8*, 6)++;
    } else if (M2C_FIELD(arg0, s16*, 0x7C) == 0x3C) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    } else if (M2C_FIELD(arg0, s16*, 0x7C) < 0x3C &&
               !(*(volatile s16*)((s8*)arg0 + 0x7C) & 1)) {
        M2C_FIELD(arg0, s32*, 0x24) = -M2C_FIELD(arg0, s32*, 0x24);
    }
}
