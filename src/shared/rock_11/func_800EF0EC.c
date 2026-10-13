#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D2B0(void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
M2C_UNK func_800F4254(void*, M2C_UNK);
M2C_UNK func_800F4534(void*, M2C_UNK);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EF0EC(void* arg0) {
    s32 angle;
    s32 t;
    s32 d;
    s32 x;

    x = 0xA0;
    angle = func_80065B74(F(s16, 0xE) - 0x20, x - F(s16, 0xA));
    F(s32, 0x20) = func_80065A14(angle) << 5;
    F(s32, 0x24) = func_80065944(angle) << 5;
    func_8002D2B0(arg0);
    t = F(s16, 0xA);
    d = x - t;
    if (d >= 0) {
        if (d < 3) {
            goto L1;
        }
        return;
    }
    if (t - 0xA0 < 3) {
    L1:
        t = F(s16, 0xE);
        d = 0x20 - t;
        if (d >= 0) {
            if (d < 3) {
                goto L2;
            }
            return;
        }
        if (t - 0x20 < 3) {
        L2:
            func_800F4254(arg0, 0x20);
            func_800F4534(arg0, 0);
            {
                register s32 b asm("$4") = F(u8, 0x6);
                F(s16, 0xA) = 0xA0;
                F(s16, 0xE) = 0x20;
                F(s16, 0x8A) = 0x168;
                F(u8, 0x7) = 0;
                F(u8, 0x6) = b + 1;
            }
        }
    }
}
