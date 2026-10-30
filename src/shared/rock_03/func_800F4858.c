#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;

void func_800F4858(void* arg0) {
    if (D_800F7E0C == 0) {
        set_animation(arg0, 0);
        D_800F7E0E = 2;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
