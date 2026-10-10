#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F6E4C(); /* extern */

void func_800F8778(void* arg0) {
    M2C_FIELD(arg0, s8*, 7) = 0;
    func_800F6E4C();
}
