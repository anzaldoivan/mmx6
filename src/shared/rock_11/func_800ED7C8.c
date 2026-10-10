#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800ED7C8 (*(s32**)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 func_8002D2D4();
extern s32 D_8007483C;
extern u32* D_80095098;
extern u8 D_800970B4;
extern s16 D_8009721C;
extern u8 D_800FB26C[];
extern s32 D_800FC84C;
extern void* D_800FD510;
extern s8 D_800FD514;
extern s16 D_800FD516;
extern s16 D_800FD518;
extern s8 D_800FD51A;
extern s8 D_800FD51B;
extern s8 D_800FD51D;
extern s8 D_800FD51F;
extern s8 D_800FD520;
extern s8 D_800FD521;
extern s16 D_800FD526;

#define F(type, off) M2C_FIELD(self, type*, off)

#define SETUP_GFX()                                                            \
    {                                                                          \
        s32 a;                                                                 \
        s32 b;                                                                 \
        F(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1)) + 1] >> 7;           \
        a = func_8002A47C(F(s8, 1));                                           \
        b = func_8002A47C(F(s8, 1)) + 1;                                       \
        a = (a + 1) * 4;                                                       \
        F(s16, 0x42) = ((a + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);       \
        F(u8*, 0x3C) = (u8*)SPAD20_800ED7C8 +                                  \
                       SPAD20_800ED7C8[func_8002A47C(F(s8, 1)) + 1];           \
    }

void func_800ED7C8(void* self) {
    s32 type;
    s32 sub;

    F(s16, 0x7C) = 0;
    F(s8, 0x60) = 0;
    F(s8, 0x5C) = 0;
    F(s8, 0x61) = 0;
    F(s8, 0x3) = 0;
    F(u8, 0x14) = D_800970B4;
    F(u8, 0x16) = 5;
    F(void*, 0x30) = &D_800FC84C;
    F(s32, 0x68) = 0;
    F(void*, 0x54) = 0;
    F(s32, 0x50) = 0;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x15) = 0;
    F(s8, 0x67) = 0;
    F(void*, 0x58) = &D_8007483C;
    type = F(s8, 2) & 0xF0;
    if (type != 0 && D_800FD51D != 0) {
        F(s8, 4) = 3;
        F(s8, 3) = 0;
        return;
    }
    if (type == 0) {
        D_800FD510 = self;
        D_800FD514 = 0;
        D_800FD516 = 0;
        D_800FD518 = 0;
        D_800FD51B = 0;
        D_800FD51D = 0;
        D_800FD51F = 0;
        D_800FD520 = 0;
        D_800FD521 = 0;
        D_800FD51A = 0;
        D_800FD526 = 0;
        F(s8, 0x87) = 0;
        F(s8, 0x85) = func_8002D2D4() & 0xF;
        F(s8, 0x84) = 0x78;
        F(s8, 0x86) = 0;
        F(s8, 0x89) = 0;
        F(s8, 0x5C) = 0;
        F(s8, 0x60) = 4;
        F(s8, 0x14) = -1;
        F(s8, 4) = 1;
        F(s8, 5) = 2;
        D_8009721C = 0x800;
    } else {
        if (type == 0x10) {
            F(s8, 0x14) = -1;
            F(s8, 3) = 1;
            F(s16, 0xA) = 0xA0;
            F(s16, 0xE) = 0x48;
            F(s8, 4) = 2;
            F(s16, 0x7E) = func_8002D2D4() * 16;
            F(void*, 0x54) = &D_800FB26C[0x1058];
            F(s8, 0x5C) = type;
            if (F(u8, 2) & 0xF) {
                F(u16, 0x40) += 0x400;
                SETUP_GFX();
            }
            sub = F(u8, 2) & 0xF;
            switch (sub) {
            case 0:
                F(u8, 0x16) = 0x30;
                func_800179A4(self, 0x50);
                F(s32, 0x50) = 0;
                F(void*, 0x54) = 0;
                F(s8, 0x5C) = 0x28;
                F(s8, 5) = 2;
                break;
            case 1:
                ((void (*)(void*, s32))func_800179A4)(self, 0x21);
                F(s8, 5) = 3;
                break;
            case 2:
                ((void (*)(void*, s32))func_800179A4)(self, 0x25);
                F(s8, 5) = 3;
                break;
            case 3:
                func_800179A4(self, 0x25);
                F(s8, 5) = sub;
                break;
            }
        } else if (type == 0x20) {
            F(u8, 0x16) = 2;
            F(s8, 0x14) = -1;
            F(s8, 3) = 0;
            F(s8, 4) = 2;
            F(u16, 0x40) += 0x400;
            SETUP_GFX();
            func_800179A4(self, 0x35);
            F(s8, 5) = 5;
        } else if (type == 0x30) {
            F(s8, 0x14) = 0;
            F(s8, 3) = 1;
            F(s8, 4) = 2;
            F(u16, 0x40) += 0x400;
            SETUP_GFX();
            ((void (*)(void*, s32))func_800179A4)(self, 0x37);
            if ((F(s8, 2) & 0xF) < 5) {
                F(u8, 0x15) = 0x40;
            } else {
                F(u8, 0x15) = 0;
            }
            F(s8, 0x5C) = 0x14;
            F(s8, 5) = 6;
        } else if (type == 0x40) {
            func_80016C48(2, 0x38, self);
            D_800FD520 = 1;
            F(s8, 0x14) = -1;
            F(s8, 4) = 2;
            F(s8, 0x5C) = 1;
            F(s8, 5) = 7;
        }
    }
    F(s8, 6) = 0;
    F(s32, 0x18) = F(s32, 8);
    F(s32, 0x1C) = F(s32, 0xC);
}

#undef F
#undef SETUP_GFX
