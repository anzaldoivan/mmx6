#include "common.h"

extern s32 D_80097420;
extern u16 D_800CCF3A;

void func_8001F9B0(u8* arg0) {
    s8* g = (s8*)&D_80097420;
    s32 v;

    if (g[4] == 0) {
        if (((u8*)g)[7] == 0) {
            arg0[0x1E] = 0;
            v = D_800CCF3A & 0x8000;
            if (v != 0) {
                v = 4;
            } else {
                v = 2;
            }
            arg0[0x39] = v;
            do {
            } while (0);
            arg0[0] = 9;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            return;
        }
        arg0[1] = 5;
    }
}
