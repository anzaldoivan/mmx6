#include "common.h"

extern u16 D_80077BD4[][2];
extern s16 D_800CCEDA;

void func_80049090(u8* arg0) {
    s32 idx;

    idx = (s32)(arg0[2] << 0x18) >> 0x1C;
    if (D_800CCEDA == 0) {
        *(s16*)(arg0 + 0xA) = 0x28;
    } else {
        *(s16*)(arg0 + 0xA) = 0x68;
    }
    *(s16*)(arg0 + 0xE) = D_80077BD4[idx][1] + 0x10;
}
