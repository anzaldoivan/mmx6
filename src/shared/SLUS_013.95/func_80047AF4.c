#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80047B34(); /* extern */
M2C_UNK func_80047C30(); /* extern */

void func_80047AF4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        func_80047B34();
        return;
    }
    func_80047C30();
}
