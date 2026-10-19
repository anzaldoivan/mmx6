#include "common.h"

extern s16 D_800F7E0E;

#define H(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F4B48(u8* arg0) {
    if (++H(arg0, 0x7C) == 2) {
        D_800F7E0E = 4;
        H(arg0, 0x8E) = 0;
        arg0[7] = 0;
        H(arg0, 0x7C) = 0;
        H(arg0, 0x7E) = 0;
        arg0[6]++;
    }
}
