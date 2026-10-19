#include "common.h"

extern s8 D_80097424;
extern u8 D_8006D5F7;
extern u8 D_800CCF99;
extern u8 D_800964A0[];
extern u8 D_800E4188;

void func_8002AACC(u8* arg0) {
    u16 i;
    u16 j;
    u8* p;
    u8 v;

    v = 0;
    if (D_80097424 == 0) {
        arg0[6]++;
        D_800CCF99 = D_8006D5F7;
        for (i = 0; i < 32; i++) {
            p = &D_800964A0[i * 96];
            for (j = 95; j != 0xFFFF; j--) {
                *p++ = v;
            }
        }
        D_800E4188 = 0;
    }
}
