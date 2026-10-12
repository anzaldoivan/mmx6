#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);
extern s16 D_800F4480;

void func_800F1F64(u8* arg0) {
    s32 x;
    s32 d;
    s32 a;
    s32 b;

    if (arg0[0x70] & 1) {
        x = *(s16*)(arg0 + 0xE) - 0x438;
        d = x - D_800F4480;
        if (d >= 0) {
            if (d >= 0x11) {
                goto call;
            }
        } else if (D_800F4480 - x >= 0x11) {
        call:
            func_800179A4(arg0, 3);
        }
        a = D_800F4480 + 0x438;
        b = *(s16*)(arg0 + 0xE);
        *(s32*)(arg0 + 0x20) = 0;
        if (a >= b) {
            *(s32*)(arg0 + 0x24) = 0xFFFB0000;
        } else {
            *(s32*)(arg0 + 0x24) = 0x50000;
        }
        arg0[6]++;
        return;
    }
    func_8002D2B0(arg0);
    func_80017A04(arg0);
}
