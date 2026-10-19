#include "common.h"

extern s8 D_800970A2;

void func_800294B4(u8* arg0) {
    s16 v;

    *(u8*)(arg0 + 0x47) = 4;
    *(u8*)(arg0 + 0x48) = 8;
    *(s16*)(arg0 + 0x2C) = 0x60;
    *(s32*)(arg0 + 0x14) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0xC);
    *(s16*)(arg0 + 0x24) = *(s16*)(arg0 + 0x1C);
    *(s16*)(arg0 + 0x26) = *(s16*)(arg0 + 0x1E);
    *(s16*)(arg0 + 0x28) = *(s16*)(arg0 + 0x20);
    *(s16*)(arg0 + 0x2A) = *(s16*)(arg0 + 0x22);
    v = 0xAA;
    if (D_800970A2 == 0) {
        v = 0xAB;
    }
    *(s16*)(arg0 + 0x2E) = v;
    *(s16*)(arg0 + 0x30) = 0xA0;
    *(s16*)(arg0 + 0x32) = 0xA0;
    arg0[4]++;
}
