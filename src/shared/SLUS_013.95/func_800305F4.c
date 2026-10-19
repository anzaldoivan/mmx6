#include "common.h"
#define M2C_UNK s32

extern s16 D_800E41A2;
extern s16 D_800E41A4;

M2C_UNK func_800305F4(s32 arg0) {
    u16* p = (u16*)arg0;
    s32 a = (u16)D_800E41A2;
    s32 b = (u16)D_800E41A4;

    p[4] = 0;
    p[6] = 0;
    p[5] += a;
    p[7] += b;
}
