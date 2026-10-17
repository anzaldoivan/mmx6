#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D2B0(void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern s8 D_800FD51B;
extern s8 D_800FD51E;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EF304(void* arg0) {
    s32 angle;
    s32 t;
    s32 d;
    s32 x;

    x = 0xA0;
    angle = func_80065B74(F(s16, 0xE) - 0x48, x - F(s16, 0xA));
    F(s32, 0x20) = func_80065A14(angle) << 5;
    F(s32, 0x24) = func_80065944(angle) << 5;
    func_8002D2B0(arg0);
    t = F(s16, 0xA);
    d = x - t;
    if (d >= 0) {
        if (d < 3) {
            // !FAKE: goto: matched twin func_800EF0EC block order
            goto L1;
        }
        return;
    }
    if (t - 0xA0 < 3) {
    L1:
        t = F(s16, 0xE);
        d = 0x48 - t;
        if (d >= 0) {
            if (d < 3) {
                // !FAKE: goto: matched twin func_800EF0EC block order
                goto L2;
            }
            return;
        }
        if (t - 0x48 < 3) {
        L2:
            F(s16, 0xA) = 0xA0;
            F(s16, 0xE) = 0x48;
            D_800FD51E = 0;
            D_800FD51B = -3;
            F(u8, 0x4) = 3;
        }
    }
}
