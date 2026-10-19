#include "common.h"

extern u16 D_80097120;

void func_80046318(s8* arg0) {
    if (arg0[0x90] == 0 || --arg0[0x90] == 0) {
        if (D_80097120 & 0x10) {
            arg0[0x90] = 0x32;
            arg0[0x8F] = 1;
            if (++arg0[0x8E] >= 8) {
                arg0[0x8D] = 1;
                arg0[4] = 3;
            }
        }
    } else {
        arg0[0x8F] = 0;
    }
}
