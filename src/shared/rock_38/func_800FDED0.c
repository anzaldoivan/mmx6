#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800FE82C;

void func_800FDED0(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7E) >= 4) {
        M2C_FIELD(arg0, s8*, 6) = 6;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(&D_800FE82C, s16*, 0x688)) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, s8*, 6) = 4;
}
