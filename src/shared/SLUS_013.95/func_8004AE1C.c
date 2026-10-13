#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002C9B0(); /* extern */
extern s8 D_800970A5;
extern u16 D_800CF856;

#define SCRATCH_3C (*(u8**)0x1F80003C)
#define F8(o) (*(s8*)(p + (o)))
#define F16(o) (*(s16*)(p + (o)))
#define FPTR(o) (*(u8**)(p + (o)))

void func_8004AE1C(u8* p, s32 arg1) {
    u8* t;
    s32 off;

    if (D_800970A5 != F8(5) || D_800CF856 != 0x1F) {
        func_8002C9B0(p, arg1);
        return;
    }
    if (F8(4) == 0) {
        F8(0x14) = -1;
        t = SCRATCH_3C;
        off = *(s32*)t;
        F16(0x40) = 0x1E00;
        F16(0x42) = 0x7E50;
        F8(0x16) = 0x37;
        F8(4)++;
        FPTR(0x3C) = t + off;
        return;
    }
    F8(3) = 1;
    switch (F8(2)) {
    case 0:
        F16(0xE) -= 8;
        if (F16(0xE) <= 0) {
            F16(0xE) = 0x140;
        }
        if (F16(0xE) >= 0x130) {
            F8(3) = 0;
        }
        break;
    case 1:
        F16(0xA) -= 8;
        if (F16(0xA) < -0x3F) {
            F16(0xA) = 0x140;
            F8(3) = 0;
        }
        break;
    case 2:
        F16(0xA) += 8;
        if (F16(0xA) >= 0x140) {
            F16(0xA) = -0x40;
            F8(3) = 0;
        }
        break;
    }
}
