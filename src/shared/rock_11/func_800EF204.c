#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80065944(s32);
extern s8 D_800FD514;
extern s8 D_800FD51B;
extern s8 D_800FD51E;
extern u8 D_800FD522;
#define D_800FD522 (*(s8*)&D_800FD522)
extern s16 D_800FD526;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EF204(void* arg0) {
    s32 m;

    F(s16, 0xE) = ((-func_80065944(F(s16, 0x7E)) * 6) >> 12) + 0x20;
    F(s16, 0x7E) += 0x14;
    m = D_800FD514;
    if (m == 3 && (--F(s16, 0x8A) == 0 || (u16)D_800FD526 < 0xB)) {
        D_800FD51B = 0;
        D_800FD51E = 1;
        F(s8, 0x6) = m;
        return;
    }
    if (D_800FD522 == 0) {
        D_800FD51B = 0;
        D_800FD51E = 1;
        F(s8, 0x6) = 3;
        return;
    }
    if (D_800FD51B == -1) {
        F(s16, 0x7C) = 0x3C;
        F(u8, 0x6) += 1;
    }
}

#undef D_800FD522
