#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D0D8(s32, s32);
void func_8002D380(void* arg0, void* arg1) {
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg0, s32*, 8);
    ((s32(*)())func_8002D0D8)(
        temp_a2 - M2C_FIELD(arg1, s32*, 8),
        M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg1, s32*, 0xC), temp_a2);
}
