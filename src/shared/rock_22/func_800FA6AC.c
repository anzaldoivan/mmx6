#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_800FA6AC(void* arg0) {
    ((void (*)())func_80017A04)();
    M2C_FIELD(arg0, u8*, 3) = 1;
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}
