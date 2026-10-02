#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0(); /* extern */

void func_800ECEE8(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 0;
    func_8002C9B0();
}
