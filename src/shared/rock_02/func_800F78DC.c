#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F78DC(void* arg0) {
    ((void (*)(void*))func_80017A04)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x1E, arg0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (13/37)
            register s32 t asm("$3") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
        return;
    }
    if (SPAD4C[0x8A] != 0x11) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x3D, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, u8*, 6) = 5;
    }
}
