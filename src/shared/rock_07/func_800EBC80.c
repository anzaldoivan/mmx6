#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002D2D4();

void func_800EBC80(void* arg0) {
    s16 n;

    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 3)) {
        func_80029478(2, (func_8002D2D4() & 3) + 1, 2);
    }
    n = --M2C_FIELD(arg0, u16*, 0x7C);
    if (n == 0) {
        func_80016C48(2, 0x43, arg0);
        M2C_FIELD(arg0, u16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
