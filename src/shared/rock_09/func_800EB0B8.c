#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

void func_800EB284();

void func_800EB0B8(void* arg0) {
    if (--M2C_FIELD(SPAD, s16*, 0x80) == 0) {
        func_800EB284();
        M2C_FIELD(SPAD, s16*, 0x80) = 0x1E;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_800EB284(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x3C000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x3C000;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
