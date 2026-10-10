#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_800F8714(void* arg0) {
    void* temp_a1;

    ((M2C_UNK(*)())func_80017A04)();
    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    if (((M2C_FIELD(temp_a1, s32*, 4) & 0xFFFF00) == 0xB0200) ||
        ((M2C_FIELD(temp_a1, s8*, 5) == 9) &&
         (M2C_FIELD(temp_a1, s8*, 6) >= 4))) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}
