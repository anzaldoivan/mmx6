#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EBE84(); /* extern */
M2C_UNK func_800EBF34(); /* extern */

void func_800EBE44(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        func_800EBE84();
        return;
    }
    func_800EBF34();
}
