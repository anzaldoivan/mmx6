#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_800F5D58(); /* extern */
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F7F00(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 6);
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, u8*, 6) += 1;
        if (M2C_FIELD(arg0, s16*, 0x7E) >= 2) {
            func_800F5D58(arg0);
        }
    }
}
