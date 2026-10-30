#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);          /* extern */
extern M2C_UNK D_800F907C;

void func_800F4674(void* arg0) {
    if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 1);
        M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_800F907C;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
    func_8002D230(arg0);
}
