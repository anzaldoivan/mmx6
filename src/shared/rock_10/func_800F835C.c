#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F5D58(); /* extern */

void func_800F835C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_800F5D58();
    }
}
