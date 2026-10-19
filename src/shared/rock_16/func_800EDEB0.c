#include "common.h"

void func_800EC8CC(s32 arg0);

void func_800EDEB0(u8* arg0) {
    s32 t;

    if ((s8)++arg0[6] >= 4) {
        t = arg0[2];
        if (t & 0x20) {
            func_800EC8CC(t & 0xF);
        }
        arg0[3] = 0;
        arg0[4]++;
    }
}
