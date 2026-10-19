#include "common.h"

void func_800EB6B8(s8* arg0) {
    s8* p;

    p = *(s8**)(arg0 + 0x80);
    if (arg0[5] == 0) {
        arg0[3] = 0;
        *(s32*)(arg0 + 0x68) = 0;
        *(s32*)(arg0 + 0x50) = 0;
        *(s32*)(arg0 + 0x54) = 0;
        arg0[5]++;
    }
    if (p[4] != 1) {
        arg0[4] = 5;
        return;
    }
    if (p[7] == 0) {
        return;
    }
    switch (p[7]) {
    case 5:
        if (arg0[2] == 0x10) {
            p[7] = 0;
        }
        break;
    case 6:
        if (arg0[2] == 0x11) {
            p[7] = 0;
        }
        break;
    case 7:
        if (arg0[2] == 0x12) {
            p[7] = 0;
        }
        break;
    }
}
