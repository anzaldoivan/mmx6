#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EA218(); /* extern */
M2C_UNK func_800EA7D0(); /* extern */
M2C_UNK func_800EA810(); /* extern */

void func_800EA778(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 4);
    if (temp_v1 == 0) {
        func_800EA7D0();
        return;
    }
    if (temp_v1 == 1) {
        func_800EA218();
        return;
    }
    func_800EA810();
}
