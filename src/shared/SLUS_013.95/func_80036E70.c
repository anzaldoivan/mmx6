#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK handle_slide_down(); /* extern */
M2C_UNK func_80036FBC();     /* extern */

void func_80036E70(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        handle_slide_down();
        return;
    }
    func_80036FBC();
}
