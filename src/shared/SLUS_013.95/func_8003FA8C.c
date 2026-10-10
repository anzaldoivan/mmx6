#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();                                  /* extern */
M2C_UNK func_8003CFE0(void*, M2C_UNK);                /* extern */
M2C_UNK func_8003D510(M2C_UNK, M2C_UNK, s8, M2C_UNK); /* extern */

void func_8003FA8C(void* arg0) {
    s8 temp_v1;

    func_8003D510(0x21, 2, M2C_FIELD(arg0, s8*, 0x96), 0);
    temp_v1 = M2C_FIELD(arg0, s8*, 0x96);
    if (((temp_v1 == 0x12) || (temp_v1 == 0x14) || (temp_v1 == 0x13)) &&
        (func_8002D2D4() & 1)) {
        func_8003CFE0(arg0, 6);
    }
}
