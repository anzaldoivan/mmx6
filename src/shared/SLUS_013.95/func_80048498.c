#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(); /* extern */

void func_80048498(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 3) != 0) {
        func_8002D230();
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 2;
    M2C_FIELD(arg0, s8*, 5) = 0;
}
