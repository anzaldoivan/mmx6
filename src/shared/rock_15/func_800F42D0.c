#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_800F1DA8(void*, s32, s32);

void func_800F42D0(void* arg0) {
    func_80017A04();
    {
        s8 v = SB(arg0, 0x45);
        if (v == 1) {
            func_800F1DA8(arg0, 3, 1);
        } else if (v == 2) {
            ((void (*)(void*, s32))set_animation)(arg0, 2);
            H(arg0, 0x8C) = 0;
            B(arg0, 0x6)--;
        }
    }
}
