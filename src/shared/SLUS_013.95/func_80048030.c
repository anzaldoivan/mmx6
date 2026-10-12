#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
extern s32 D_80077B34[];
extern u8 D_80077B5C[];
extern u16 D_80077B64[];
extern u16 D_80077B70[];
extern u8 D_80077B7C[];
extern u8 D_800C4560;
extern s8 D_800CCF08;
extern u16 D_800E4450[];

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define SCRATCH_28 (*(u8**)0x1F800028)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

void func_80048030(u8* arg0) {
    s32 idx;
    u8 v;
    u16* dst;
    u16* src;
    u32 i;

    if (D_800CCF08 == 0) {
        FP(arg0, 0x3C) = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x24);
    } else {
        FP(arg0, 0x3C) = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x10);
    }
    F16(arg0, 0x40) = 0x1D00;
    FP(arg0, 0x30) = D_80077B34;
    idx = F8(arg0, 2);
    F8(arg0, 4) = 1;
    F8(arg0, 0x14) = -1;
    v = D_80077B5C[idx];
    F16(arg0, 0x42) = (v & 0xF) | (((v >> 4) + 0x1E0) << 6);
    F16(arg0, 0xA) = D_80077B64[idx];
    F16(arg0, 0xE) = D_80077B70[idx];
    F8(arg0, 0x16) = D_80077B7C[idx];
    F8(arg0, 0x15) = 0;
    F32(arg0, 0x20) = 0;
    F32(arg0, 0x28) = 0;
    F32(arg0, 0x24) = 0;
    F32(arg0, 0x2C) = 0;
    F16(arg0, 0x54) = 0;
    F16(arg0, 0x56) = 0;
    F16(arg0, 0x58) = 0;
    F16(arg0, 0x5A) = 0;
    F16(arg0, 0x5C) = 0;
    if (idx < 2) {
        if (idx != 0) {
            dst = D_800E4450;
            src = (u16*)(SCRATCH_28 + 0x200);
            for (i = 0; i < 0x10; i++) {
                *dst++ = *src;
                if (i != 0) {
                    *src = 0x8000;
                } else {
                    *src = 0;
                }
                src++;
            }
            D_800C4560 |= 1;
        }
        func_800179A4(arg0, 0);
    } else {
        func_800179A4(arg0, idx - 1);
    }
}
#undef func_800179A4
