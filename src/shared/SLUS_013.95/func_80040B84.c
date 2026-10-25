#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_80040B84(void* arg0) {
    s32 angle;
    s32 t;
    s32 u;
    s32 d;

    {
        s32 x = F(s16, 0x84);
        s32 y = F(s16, 0x86);
        angle = func_80065B74(F(s16, 0xE) - y, x - F(s16, 0xA));
    }
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    {
        s32 m = func_80065A14(angle) * 16;
        F(s32, 0x20) = (m * 2 + m) * 2;
    }
    angle = func_80065944(angle) * 16;
    F(s32, 0x24) = (angle * 2 + angle) * 2;
    u = F(s32, 0x20);
    if (u > 0) {
        F(u8, 0x15) = 0x40;
    } else {
        F(u8, 0x15) = 0;
    }
    move_object(arg0);
    u = F(s16, 0x84);
    t = F(s16, 0xA);
    d = u - t;
    if (d >= 0) {
        if (d < 7) {
            goto L1;
        }
        return;
    }
    if (t - u < 7) {
    L1:
        u = F(s16, 0x86);
        t = F(s16, 0xE);
        d = u - t;
        if (d >= 0) {
            if (d < 7) {
                goto L2;
            }
            return;
        }
        if (t - u < 7) {
        L2:
            F(s16, 0x7C) = 8;
            F(u8, 0x6)++;
        }
    }
}
