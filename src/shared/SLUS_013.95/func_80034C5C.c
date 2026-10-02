#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK); /* extern */
M2C_UNK func_80026028();        /* extern */

void func_80034C5C(void* arg0) {
    func_800139F4(0x20);
    func_80026028();
    M2C_FIELD(arg0, s8*, 5) = 1;
}
