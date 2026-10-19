#include "common.h"

#define M2C_UNK s32
#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8F(p, o) (*(s8*)((u8*)(p) + (o)))
#define S16F(p, o) (*(s16*)((u8*)(p) + (o)))
#define S32F(p, o) (*(s32*)((u8*)(p) + (o)))
#define SCRATCH_3C (*(s32**)0x1F80003C)

s32 func_8002CB50(struct X4_BaseObj*); /* extern */
extern s32 D_80097420;

void func_80048BD8(void* arg0) {
    s32* t;
    u8* g;
    s32 v;
    s32 x;

    S16F(arg0, 0x40) = 0x1E00;
    t = SCRATCH_3C;
    x = *t;
    S8F(arg0, 0x14) = -1;
    S16F(arg0, 0x42) = 0x7E11;
    S32F(arg0, 0x3C) = (s32)t + x;
    g = (u8*)&D_80097420;
    S16F(arg0, 0xE) = U8F(S32F(arg0, 0x50) + g[7] * 3, 2);
    v = g[7];
    U8F(arg0, 0x16) = 0;
    U8F(arg0, 4) = U8F(arg0, 4) + 1;
    U8F(arg0, 0x47) = 0x47;
    U8F(arg0, 0x54) = v;
    ((s32(*)())func_8002CB50)(arg0, v);
}
