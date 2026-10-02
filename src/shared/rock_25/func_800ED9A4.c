#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */

void func_800ED9A4(void* arg0) {
    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        func_800179A4(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
    }
}
