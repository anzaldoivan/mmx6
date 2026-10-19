#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80013300(M2C_UNK, M2C_UNK*); /* extern */
extern s32 D_80097420;
extern s8 D_800C8861;
extern M2C_UNK func_80013530;

M2C_UNK func_800139A0(s8 arg0) {
    s8* p = (s8*)&D_80097420;

    if (p[4] == 0) {
        p[4] = 1;
        D_800C8861 = arg0;
        func_80013300(2, &func_80013530);
    }
}
