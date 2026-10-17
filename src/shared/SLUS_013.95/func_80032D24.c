#include "common.h"

#define H(p, o) (*(s16*)((u8*)(p) + (o)))

void func_80032D24(void* arg0, void* arg1) {
    s32 d;
    s32 f;
    s16 r;
    s16 s;

    d = H(arg0, 0xA) - H(arg0, 0x1A);
    if (d != 0) {
        if (d > 0) {
            f = ((u8*)arg1)[0x70] & 1;
        } else {
            f = ((u8*)arg1)[0x70] & 2;
        }
        if (f == 0) {
            r = H(arg1, 0xA) - H(arg1, 0x1A);
            s = H(arg0, 0x1A) - H(arg1, 0x1A);
            H(arg1, 0xA) = r + (H(arg0, 0xA) - s);
        }
    }
    if (H(arg0, 0xE) - H(arg0, 0x1E) > 0) {
        r = H(arg1, 0xE) - H(arg1, 0x1E);
        s = H(arg0, 0x1E) - H(arg1, 0x1E);
        H(arg1, 0xE) = r + (H(arg0, 0xE) - s);
    }
}

#undef H
