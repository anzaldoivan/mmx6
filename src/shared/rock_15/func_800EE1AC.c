#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F637C;
extern M2C_UNK D_800F6380;

void func_800EE1AC(void* arg0) {
    switch (M2C_FIELD(arg0, s8*, 0x45)) {
    case 1:
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F637C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F6380;
        return;
    case 2:
        ((void (*)(void*, s32))set_animation)(arg0, 0xD);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 5) += 1;
        return;
    }
}
