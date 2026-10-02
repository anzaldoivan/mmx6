#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */

void func_800EC418(void* arg0) {
    if (func_800ECD7C(arg0 + 0x86, 0x38, 2) != 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
