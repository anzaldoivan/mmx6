#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F5AAC(); /* extern */
M2C_UNK func_800F5B5C(); /* extern */

void func_800F5A6C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        func_800F5AAC();
        return;
    }
    func_800F5B5C();
}
