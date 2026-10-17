#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_800179D0(void*, M2C_UNK, s8);
extern s8 D_800CCEF8;
extern s8 D_800CCF01;
extern u8 D_800F124C[];

#define E310_S8(o) (*(s8*)((s8*)arg0 + (o)))
#define E310_U8(o) (*(u8*)((s8*)arg0 + (o)))
#define E310_S16(o) (*(s16*)((s8*)arg0 + (o)))
#define E310_PTR(o) (*(void**)((s8*)arg0 + (o)))
#define E310_SCRATCH (*(u8**)0x1F800020)

void func_800EE310(void* arg0) {
    u8* p;
    s32 v;
    u8* q;

    E310_S16(0x40) = 0x1800;
    p = E310_SCRATCH;
    q = p + *(s32*)p;
    v = E310_S8(2);
    E310_PTR(0x30) = D_800F124C;
    E310_S16(0x42) = 0x780D;
    E310_U8(0x16) = 3;
    E310_PTR(0x3C) = q;
    if (v == 0) {
        E310_S16(0xA) = 0x5B0;
        E310_S16(0xE) = 0x6C;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        E310_U8(4) = 1;
    } else if (v == 1) {
        E310_S16(0xA) = 0x5B0;
        E310_S16(0xE) = 0x7C;
        ((void (*)(void*, s32, s8))func_800179D0)(arg0, 1, D_800CCF01);
        E310_U8(4) = 2;
    } else {
        E310_S16(0xA) = 0x5B0;
        E310_S16(0xE) = 0x7C;
        ((void (*)(void*, s32))func_800179A4)(arg0, D_800CCEF8 + 2);
        E310_U8(4) = 3;
    }
    E310_U8(3) = 1;
    E310_U8(0x14) = 1;
}
