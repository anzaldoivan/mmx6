#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define F(p, type, off) M2C_FIELD(p, type*, off)

extern s16 D_800F986A;

void func_800F65C4(void* arg0) {
    s16 v;
    s16 q;

    if (F(arg0, s16, 0x7E) == 0 || --F(arg0, s16, 0x7E) == 0) {
        // !FAKE: depin: dropping it breaks the match (43/50)
        register s32 b asm("$3") = F(arg0, u8, 0x6);
        F(arg0, s16, 0x7C) = 0x1E;
        F(arg0, s32, 0x50) = 0;
        F(arg0, s32, 0x54) = 0;
        F(arg0, u8, 0x7) = 1;
        F(arg0, u8, 0x6) = b + 1;
        return;
    }
    v = F(arg0, u16, 0x86);
    q = v / 3;
    if (v % 3 != 0) {
        q++;
    }
    if (v - D_800F986A >= q) {
        F(arg0, u8, 0x7) = 1;
        F(arg0, u8, 0x6) -= 2;
    }
}

#undef F
#undef M2C_FIELD
