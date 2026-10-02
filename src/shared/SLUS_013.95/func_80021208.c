#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_80021208(void* arg0, void* arg1) {
    if ((M2C_FIELD(arg1, s8*, 0x9B) == 0) &&
        (M2C_FIELD(arg1, s8*, 0x9C) == 0)) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 0;
        return;
    }
    func_80017A04();
}
