#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F7624(void* arg0) {
    s32 t;

    ((M2C_UNK(*)())func_80017A04)();
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0xA) {
        play_sound(2, 0x1D, arg0);
        func_80012D9C(7);
    }
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, s16*, 0x7C) = t + 1;
    if ((s16)t >= 0x15) {
        set_animation(arg0, 8);
        t = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = t + 1;
    }
}
