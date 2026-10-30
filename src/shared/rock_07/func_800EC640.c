#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 random_byte();

void func_800EC640(void* arg0) {
    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 7)) {
        func_80029478(6, (random_byte() & 3) | 4, 2);
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
