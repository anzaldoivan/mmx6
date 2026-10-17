#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

void func_800EB284();

void func_800EAF0C(void* arg0) {
    if (--M2C_FIELD(SPAD, s16*, 0x80) == 0) {
        func_800EB284();
        M2C_FIELD(SPAD, s16*, 0x80) = 0x1E;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}
