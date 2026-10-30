#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F9E44(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        set_animation(arg0, 0);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
        M2C_FIELD(arg0, u8*, 0x5) = M2C_FIELD(arg0, u8*, 0x5) + 1;
    }
}
