#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004D598(void* arg0);
void func_8004D6D4(void* arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32*, 0x3C) - M2C_FIELD(arg0, s32*, 0x48);
    M2C_FIELD(arg0, s32*, 0x3C) = temp_v0;
    if (temp_v0 <= 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    ((M2C_UNK(*)())func_8004D598)();
}
