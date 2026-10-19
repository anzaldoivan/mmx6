#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_8004E800 (*(s32**)0x1F800020)
#define F(type, off) M2C_FIELD(arg0, type*, off)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
void func_8002F288(struct X4_PlayerObj*);
M2C_UNK func_8004FE8C();
s32 func_8004FF4C(s32);
extern M2C_UNK D_800743DC;
extern s32 D_80078910;
extern s32 D_8007891C;
extern s32 D_80078BEC;
extern u32* D_80095098;
extern u8 D_800970B4;

void func_8004E800(void* arg0) {
    register s32 t asm("$5");

    if (F(u8, 2) != 0x80 && (u32)(func_8004FF4C(F(u8, 2)) - 2) < 3) {
        F(u8, 4) = 8;
        return;
    }
    if ((F(s8, 2) & 0xF0) == 0x10) {
        F(u8, 0x84) = 1;
    } else {
        F(u8, 0x84) = 0;
    }
    t = D_800970B4;
    F(u8, 0) = 0x41;
    F(void*, 0x58) = &D_800743DC;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x16) = 2;
    F(void*, 0x30) = &D_80078BEC;
    F(u8, 0x14) = t;
    F(u16, 0x40) = D_80095098[((s32(*)())func_8002A47C)(0x8D, t)] >> 7;
    F(u8*, 0x3C) = (u8*)SPAD20_8004E800 + SPAD20_8004E800[func_8002A47C(0x8D)];
    F(s16, 0x42) = ((func_8002A47C(0x8D) * 4 + 0x20) % 16) |
                   (((func_8002A47C(0x8D) + 8) / 4 + 0x1E0) << 6);
    F(u8, 0x15) = 0;
    F(s32, 0x18) = F(s32, 0x8);
    F(s32, 0x1C) = F(s32, 0xC);
    func_8004FE8C(arg0);
    if (F(u8, 0x84) == 0) {
        F(void*, 0x68) = &D_80078910;
        func_8002F288(arg0);
        if (F(u8, 0x70) & 8) {
            F(u8, 0x7E) = 0;
            if (F(u8, 0x82) == 0) {
                func_800179A4(arg0, 0);
            } else {
                func_800179A4(arg0, 0xB);
            }
        } else {
            F(u8, 0x7E) = 1;
            F(u16, 0x7C) = F(u16, 0xE);
            if (F(u8, 0x82) == 0) {
                func_800179A4(arg0, 5);
            } else {
                func_800179A4(arg0, 0xE);
            }
        }
    } else {
        F(void*, 0x68) = &D_8007891C;
        func_8002F288(arg0);
        if (F(u8, 0x82) == 0) {
            func_800179A4(arg0, 0x17);
        } else {
            func_800179A4(arg0, 0x1E);
        }
    }
    F(u8, 4) = 1;
    F(u8, 7) = 1;
    F(u8, 5) = 0;
    if (F(u8, 2) == 0x80) {
        F(u8, 7) = 0;
    }
}

#undef F
#undef SPAD20_8004E800
