#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8003D330();                        /* extern */
M2C_UNK func_800EA860(void*);

void func_800EBA04(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7E) == 0) {
        func_80016C48(0, 0xE, 0);
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
    }
    if (++M2C_FIELD(arg0, s8*, 0x5C) == 0x30) {
        func_8003D330();
        func_800EA860(arg0);
    }
}
