#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F8404(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        ((void (*)(void*, s32))set_animation)(arg0, 0x15);
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, u8*, 7) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
