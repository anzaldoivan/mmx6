#include "common.h"

#define M2C_UNK s32

extern M2C_UNK D_800970A0;
extern void (*D_801F39E0[])(s8*);

void func_801F0664(s8* arg0) {
    u8* p;
    s32 f;

    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    p = (u8*)&D_800970A0;
    f = *(s8*)(p + 0xD3) != 0;
    if (*(s8*)(p + 0xD4) != 0) {
        f = 1;
    }
    if (*(s8*)(p + 0x93) != 3) {
        f = 1;
    }
    if (*(s8*)(p + 0x96) == 0xC) {
        f = 1;
    }
    if (f != 0) {
        arg0[4] = 3;
    }
    D_801F39E0[arg0[4]](arg0);
}
