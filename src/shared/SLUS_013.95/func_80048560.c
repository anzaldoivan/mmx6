#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CB50(struct X4_BaseObj*); /* extern */

void func_80048560(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    ((s32 (*)())func_8002CB50)();
}
