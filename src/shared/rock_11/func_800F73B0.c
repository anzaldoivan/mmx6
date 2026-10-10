#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
s32 func_800FA630(void*, s16, s16);
extern s16 D_800970AA;

#define F_U8(o) (*(u8*)((u8*)self + (o)))
#define F_S16(o) (*(s16*)((u8*)self + (o)))
#define F_S32(o) (*(s32*)((u8*)self + (o)))

void func_800F73B0(void* self) {
    s16 x;
    s32 d;
    s32 v;
    register s32 t asm("$2");

    if (F_U8(0x15) == 0) {
        if (func_800FA630(self, F_S16(0xA) - 0x10, F_S16(0xE)) != 0) {
            func_800179A4(self, 0xC);
            F_S32(0x50) = 0;
            F_U8(0x6) = 4;
            F_S16(0xA) -= 0x12;
            return;
        }
        if (!(F_U8(0x70) & 2)) {
            goto gen;
        }
        goto inc;
    } else if (F_U8(0x15) == 0x40) {
        if (func_800FA630(self, F_S16(0xA) + 0x10, F_S16(0xE)) != 0) {
            func_800179A4(self, 0xC);
            F_S32(0x50) = 0;
            F_U8(0x6) = 4;
            F_S16(0xA) += 0x12;
            return;
        }
        if (F_U8(0x70) & 1) {
            goto inc;
        }
    }
gen:
    x = F_S16(0xA);
    d = x - D_800970AA;
    if (d >= 0) {
        if (d < 9) {
            goto inc;
        }
    } else if (D_800970AA - x < 9) {
    inc:
        F_U8(0x6)++;
        return;
    }
    if (F_S32(0x84) == 1) {
        func_800179A4(self, 0xC);
        t = F_U8(0x15);
        if (t == 0) {
            v = (u16)F_S16(0xA) - 0x12;
        } else {
            v = (u16)F_S16(0xA) + 0x12;
        }
        F_S16(0xA) = v;
        F_S32(0x50) = 0;
        F_U8(0x6) = 4;
        return;
    }
    func_8002D2B0(self);
}
