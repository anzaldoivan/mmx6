#include "common.h"

s32 func_800EA480(s8* arg0);
extern u8 D_800EA510[];
extern u8 D_800FA4F0[];

void func_800FA3A8(u8* arg0) {
    s32 i;

    if (func_800EA480((s8*)arg0) != 0) {
        i = 0;
        do {
            D_800EA510[i] = D_800FA4F0[i];
            i++;
        } while (i < 4);
        *(s16*)(arg0 + 8) = 0x209;
        *(s16*)(arg0 + 0xA) = 3;
        arg0[1]++;
    }
}
