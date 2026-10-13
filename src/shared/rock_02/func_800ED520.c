#include "common.h"

#define SPAD4C (*(s8**)0x1F80004C)

void func_800ED520(u8* arg0) {
    s8* p = SPAD4C;

    if (p[0x80] == 0) {
        ((u8*)p)[0x83]++;
        if (p[0x83] >= 2) {
            arg0[5] = 5;
            arg0[6] = 0;
            SPAD4C[0x83] = 0;
            return;
        }
        arg0[5] = 3;
        arg0[6] = 0;
        return;
    }
    p[0x80] = (u8)p[0x80] - 1;
}
