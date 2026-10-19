#include "common.h"

extern u16 D_80077BD4[][2];
extern u8 D_800CCED3;

void func_80049050(u8* arg0) {
    s32 idx;

    idx = (s32)(arg0[2] << 0x18) >> 0x1C;
    arg0[0x47] = D_800CCED3;
    *(s16*)(arg0 + 0xA) = D_80077BD4[idx][0];
    *(s16*)(arg0 + 0xE) = D_80077BD4[idx][1];
}
