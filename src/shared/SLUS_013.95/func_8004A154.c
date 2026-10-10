#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8004A194(); /* extern */
M2C_UNK func_8004A250(); /* extern */

void func_8004A154(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        func_8004A194();
        return;
    }
    func_8004A250();
}
