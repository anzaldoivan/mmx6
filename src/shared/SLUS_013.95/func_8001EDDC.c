#include "common.h"

void func_8001EDDC(u8* arg0) {
    s32 i;
    u8* arr;
    u8* next;
    s32 t;

    i = 0;
    if (arg0[0x158] != (s8)arg0[0x1D]) {
        arr = arg0 + 0x158;
        do {
            i++;
        } while (i < 0x10 && arr[i] != (s8)arg0[0x1D]);
    }
    if (i == 0x10 ||
        (t = i + (s32)arg0, next = (u8*)t + 0x159, t = 0, *next == 0xFF)) {
        arg0[0] = 3;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
        arg0[0x158] = arg0[0x1D];
        return;
    }
    arg0[0] = 0x13;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[0x1D] = *next;
}
