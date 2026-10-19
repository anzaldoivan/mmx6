#include "common.h"
#define M2C_UNK s32

extern s16 D_80097206;

M2C_UNK func_800297F8(s16* arg0) {
    s32 f = (u16)arg0[0x21];
    arg0[7] = (D_80097206 >> 1) + f;
}
