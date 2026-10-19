#include "common.h"

extern s8 D_800970A5;
extern void (*D_801F39B4[])(u8*);

void func_801EF944(u8* arg0) {
    D_801F39B4[((s8*)arg0)[5]](arg0);
    if (((s8*)arg0)[2] == 0 && D_800970A5 != 0x27) {
        if (--*(u16*)(arg0 + 0x8C) == 0) {
            arg0[4] = 3;
        }
    }
}
