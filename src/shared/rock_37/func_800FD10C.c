#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_animation(void*, M2C_UNK);

void func_800FD10C(void* arg0) {
    s8 n;

    set_animation(arg0, 1);
    n = M2C_FIELD(arg0, s8*, 0x9A);
    if (n < 2) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
    } else if (n < 3) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x28000;
    } else if (n < 4) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = 0x18000;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
    }
    M2C_FIELD(arg0, u8*, 6)++;
}
