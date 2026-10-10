#include "common.h"
#define M2C_UNK s32

#define F(expr, type, offset) (*(type*)((u8*)(expr) + (offset)))
#define SPAD_4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
void func_800EB76C(void*, s32);
void func_800EB8B8(void*);

extern M2C_UNK D_800743DC;
extern u8 D_800970B4;
extern u8 D_800CCF38;
extern s32 D_800F669C;
extern s32 D_800F66A0;
extern s32 D_800F6728;

void func_800EA8A8(void* self) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 byte;

    F(self, u8, 0x60) = 4;
    F(self, u8, 0x5C) = 4;
    F(self, u8, 0x61) = 0;
    F(self, u8, 0x3) = 0;
    F(self, void*, 0x30) = &D_800F6728;
    byte = D_800970B4;
    F(self, u8, 0x16) = 7;
    d = F(self, s32, 0x8);
    c = F(self, s32, 0xC);
    F(self, u8, 0x67) = 0;
    F(self, void*, 0x58) = &D_800743DC;
    F(self, s32, 0x20) = 0;
    F(self, s32, 0x24) = 0;
    F(self, s32, 0x28) = 0;
    F(self, s32, 0x2C) = 0;
    F(self, u8, 0x15) = 0;
    F(self, u8, 0x14) = byte;
    F(self, s32, 0x18) = d;
    F(self, s32, 0x1C) = c;
    ((void (*)(void*, s32, s32, u8))func_800179A4)(self, 0, c, byte);
    F(self, u8, 0x3) = 0;
    F(self, s32, 0x68) = 0;
    F(self, void*, 0x50) = &D_800F669C;
    F(self, void*, 0x54) = &D_800F66A0;
    if (F(self, s8, 0x2) == 0) {
        func_800EB8B8(self);
        SPAD_4C[0x88] = 0;
        if (F(self, u8, 0x15) == 0) {
            F(self, s16, 0xA) += 0x20;
        } else {
            F(self, s16, 0xA) -= 0x20;
        }
        func_800EB76C(self, 0x10);
        func_800EB76C(self, 0x11);
        func_800EB76C(self, 0x12);
        func_800EB76C(self, 0x13);
        if (D_800CCF38 >= 2) {
            F(self, u8, 0x5) = 6;
        } else {
            F(self, u8, 0x5) = 2;
        }
    } else {
        F(self, u8, 0x5) = 3;
        a = func_8002A47C(F(self, s8, 0x1));
        b = func_8002A47C(F(self, s8, 0x1));
        F(self, s16, 0x42) =
            ((a * 4 + 0x21) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    }
    func_800EB8B8(self);
    F(self, u8, 0x4) = 1;
    F(self, u8, 0x6) = 0;
}

#undef SPAD_4C
#undef F
