#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

void func_800ECA28(void* arg0) {
    s8* p;

    p = M2C_FIELD(arg0, s8**, 0x80);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s8*, 0x60) = 0;
        p[7] = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}
