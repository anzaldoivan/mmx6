#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#define SPAD (*(u8**)0x1F80004C)

void func_800F6400(void* arg0) {
    u8 t;

    t = SPAD[0x8B];
    if (t != 0) {
        SPAD[0x8B] = t - 1;
        if (!(SPAD[0x8B] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (SPAD[0x8B] == 0) {
            SPAD[0x8B] = 0x78;
        }
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFC0000;
        M2C_FIELD(arg0, u8*, 6) += 1;
        SPAD[0x8B] = 0x78;
    }
}
