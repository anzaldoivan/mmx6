#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EBA8C(); /* extern */
M2C_UNK func_800EC044(); /* extern */
M2C_UNK func_800EC084(); /* extern */

void func_800EBFEC(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 4);
    if (temp_v1 == 0) {
        func_800EC044();
        return;
    }
    if (temp_v1 == 1) {
        func_800EBA8C();
        return;
    }
    func_800EC084();
}
