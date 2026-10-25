#include "common.h"
#define M2C_UNK s32

s32 func_8002CB50(struct X4_BaseObj*); /* extern */
extern s32 D_80097420;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define SCRATCH_3C (*(u8**)0x1F80003C)

void func_800468DC(void* arg0) {
    s32 v;
    u8 raw;
    u8* p;

    v = F8(arg0, 2);
    raw = U8F(arg0, 2);
    if (v < 0) {
        F8(arg0, 0x14) = -1;
        F8(arg0, 0x16) = 0;
        F8(arg0, 0x15) = 0;
        if (v == -1) {
            u8* g;
            s32 t;
            u8* q;
            F16(arg0, 0x40) = 0x1E00;
            q = SCRATCH_3C;
            t = *(s32*)q;
            F16(arg0, 0x42) = 0x7E11;
            q += t;
            F32(arg0, 0x3C) = (s32)q;
            g = (u8*)&D_80097420;
            F16(arg0, 0xE) = *(u8*)(g[7] * 2 + *(u8**)((u8*)arg0 + 0x50));
            v = g[7];
            F8(arg0, 0x47) = 0x47;
            F8(arg0, 0x54) = v;
        } else {
            F16(arg0, 0x40) = 0x1F00;
            p = SCRATCH_3C;
            v = *(s32*)(p + 4);
            F16(arg0, 0x42) = 0x7C10;
            F16(arg0, 0xA) = 0xA0;
            F16(arg0, 0xE) = 0xD0;
            F8(arg0, 0x47) = 0x2B;
            p += v;
            F32(arg0, 0x3C) = (s32)p;
        }
        F8(arg0, 4) = 1;
    } else {
        s32 t;
        u8* q;
        F16(arg0, 0x40) = 0x1F00;
        q = SCRATCH_3C;
        t = *(s32*)(q + 4);
        F8(arg0, 0x14) = -1;
        F8(arg0, 0x15) = 0;
        F16(arg0, 0xA) = 0xA0;
        F8(arg0, 0x16) = 0;
        q += t;
        F32(arg0, 0x3C) = (s32)q;
        if (v == 0x20) {
            F16(arg0, 0x42) = 0x7C11;
            F8(arg0, 4) = 1;
        } else {
            F16(arg0, 0x42) = 0x7C10;
            if (v < 7) {
                F16(arg0, 0xA) = 0x20;
                F8(arg0, 4) = 3;
            } else if (v < 0x10) {
                F16(arg0, 0xA) = 0x110;
                F8(arg0, 2) = raw - 7;
                F8(arg0, 4) = 4;
            } else {
                F8(arg0, 4) = 2;
            }
        }
    }
    ((s32(*)())func_8002CB50)(arg0);
}
