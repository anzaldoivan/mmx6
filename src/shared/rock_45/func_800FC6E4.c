#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern u8 D_8008EAFC;

void func_800FC6E4(void* arg0) {
    if (D_8008EAFC == 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x40, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0xC);
        M2C_FIELD(arg0, u8*, 0x5) = (u8)(M2C_FIELD(arg0, u8*, 0x5) + 1);
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x40, 0x40);
}
