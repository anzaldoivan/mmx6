#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80036C68(); /* extern */
M2C_UNK func_80036D4C(); /* extern */

void func_80036C28(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        func_80036C68();
        return;
    }
    func_80036D4C();
}
