#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EA860(void*);             /* extern */
s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */

void func_800EC0F0(void* arg0) {
    if (func_800ECD7C(arg0 + 0x86, -0x40, 2) != 0) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 0x91) = 0;
        M2C_FIELD(arg0, s8*, 0x8F) = 0;
        func_800EA860(arg0);
    }
}
