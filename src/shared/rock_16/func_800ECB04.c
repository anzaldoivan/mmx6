#include "common.h"

extern s8 D_80097424;

void func_800ECB04(u8* arg0) {
    s32 t;

    if (D_80097424 == 0) {
        if (arg0[0x66] == 1) {
            arg0[1] = 9;
        } else {
            t = arg0[0x158];
            if (t < 8) {
                if (t >= 6) {
                    arg0[1] = 0xA;
                    arg0[2] = 0;
                    arg0[0x158] = 0xFF;
                    return;
                }
            }
            if (arg0[0x43B] != 0) {
                arg0[1] = 3;
            } else if (arg0[0x5F] & 0x10) {
                arg0[1] = 0xB;
            } else {
                arg0[1] = 3;
            }
        }
        arg0[2] = 0;
    }
}
