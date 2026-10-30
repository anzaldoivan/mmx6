#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F188C(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
    if ((u32)(M2C_FIELD(arg0, u8*, 0x47) - 0xB) >= 4U) {
        set_animation(arg0, 2);
    }
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
