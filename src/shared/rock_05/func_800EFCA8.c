#include "common.h"
#define M2C_UNK s32

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);
extern u8 D_800E9860[];
extern s8 D_800CCF5C;
extern s16 D_800F4480;

void func_800EFCA8(void* arg0) {
    s16 buf[3];
    s32 t;
    s16* src;

    src = (s16*)(D_800E9860 + 0x58);
    __builtin_memcpy(buf, src, 6);
    func_8002D2B0(arg0);
    func_80017A04(arg0);
    if (F32(arg0, 0x24) == 0x50000) {
        if (S16(arg0, 0xE) < buf[S16(arg0, 0x7C)] + D_800F4480) {
            S16(arg0, 0xE) = buf[S16(arg0, 0x7C)] + D_800F4480;
            S16(arg0, 0x7C) = 3;
        }
    } else {
        if (buf[S16(arg0, 0x7C)] + D_800F4480 < S16(arg0, 0xE)) {
            S16(arg0, 0xE) = buf[S16(arg0, 0x7C)] + D_800F4480;
            S16(arg0, 0x7C) = 3;
        }
    }
    t = S16(arg0, 0x7C);
    if (t == 3) {
        ((void (*)(void*, s32))func_800179A4)(
            arg0, 0); /* void fn-ptr cast at the unused result (C0103) */
        S16(arg0, 0x7C) = 0x32;
        if (S8(arg0, 0x5C) < D_800CCF5C / 8) {
            S16(arg0, 0x7E) = 5;
        } else if (S8(arg0, 0x5C) < D_800CCF5C / 4) {
            S16(arg0, 0x7E) = 4;
        } else {
            S16(arg0, 0x7E) = t;
        }
        F8(arg0, 6)++;
    }
}
