#include "common.h"

s32 func_800EA480(s8* arg0);
extern u8 D_800EA510[];
extern u8 D_800FA4EC[];

void func_800FA334(u8* arg0) {
    s32 i;

    if (func_800EA480((s8*)arg0) != 0) {
        for (i = 0; i < 4; i++) {
            D_800EA510[i] = D_800FA4EC[i];
        }
        *(s16*)(arg0 + 8) = 0x202;
        *(s16*)(arg0 + 0xA) = 7;
        arg0[1]++;
    }
}
