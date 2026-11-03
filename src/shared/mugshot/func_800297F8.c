#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK func_800297F8(s16* arg0) {
    s32 f = (u16)arg0[0x21];
    arg0[7] = (D_80097206 >> 1) + f;
}
