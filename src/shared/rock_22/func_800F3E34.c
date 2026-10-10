#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_800F3E34(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    func_80017A04();
}
