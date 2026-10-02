#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EBE48(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 3) {
        ((M2C_UNK(*)())func_8002CA14)();
        return;
    }
    ((M2C_UNK(*)())func_8002CA54)();
}
