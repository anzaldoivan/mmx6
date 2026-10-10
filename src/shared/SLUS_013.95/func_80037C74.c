#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80037CB4(); /* extern */
M2C_UNK func_80037D68(); /* extern */

void func_80037C74(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        func_80037CB4();
        return;
    }
    func_80037D68();
}
