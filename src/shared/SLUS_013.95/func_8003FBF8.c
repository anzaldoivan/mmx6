#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BB94(void*, M2C_UNK, s8); /* extern */

void func_8003FBF8(void* arg0) {
    s32 var_v1;

    var_v1 = 1;
    M2C_FIELD(arg0, s8*, 0x8E) = 0;
    M2C_FIELD(arg0, s8*, 0x8F) = 0;
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        s32 temp = M2C_FIELD(arg0, u8*, 0x89) & 1;
        var_v1 = temp == 0;
    } else if (M2C_FIELD(arg0, u8*, 0x89) & 2) {
        var_v1 = 0;
    }
    M2C_FIELD(arg0, s8*, 5) = 0x2C;
    M2C_FIELD(arg0, s8*, 7) = 0;
    if (var_v1 != 0) {
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    ((void (*)(void*, M2C_UNK, s8))func_8003BB94)(arg0, 0x60, 2);
    M2C_FIELD(arg0, s8*, 6) = 2;
}
