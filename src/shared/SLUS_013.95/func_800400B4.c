#include "common.h"

extern s8 D_80074074[];
extern s8 D_800740B4[];

s8 func_800400B4(u8* arg0, s8 arg1) {
    s8 v = D_80074074[arg1];

    if (*(s32*)(arg0 + 0xEC) & 0x40000) {
        v = D_800740B4[arg1];
    }
    return v;
}
