#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
void func_800174D4(u8 arg0);
M2C_UNK func_80018060(M2C_UNK, M2C_UNK);
void func_800186A8();
extern u8 D_8006D5F8;
extern u8 D_8006D5F9;
extern u16 D_800C456C[];
extern s8 D_800CC869;
extern s8 D_800CD3F8[];
extern u8 func_800F08CC[];

#define ENG_B(o) ((u8)D_80097420[o])
#define ENG_SB(o) (D_80097420[o])
#define OPT_B(o) ((u8)D_800CD3F8[o])
#define OPT_SB(o) (D_800CD3F8[o])

void func_800E9A64(u8* arg0) {
    extern s8 D_80097420[];
    register u8* self asm("$17") = arg0;
    register s32 five asm("$18") = 5;
    u8 prev;
    u8 old;

    if (ENG_SB(4) != 0) {
        return;
    }
    if (D_800C456C[2] & 0x800) {
        if (ENG_B(7) == 4) {
            func_800186A8();
        }
        func_800139F4(8);
        D_80097420[7] = five;
        goto inc;
    }
    if ((D_800C456C[2] & 0x10) && ENG_B(7) != 4) {
        ((void (*)(s32))func_800139F4)(8);
        D_80097420[7] = five;
        goto inc;
    }
    if ((D_800C456C[2] & 0x40) && (ENG_B(7) == 2 || ENG_B(7) == 5)) {
        func_80016C48(0, 0x22, 0);
        func_800139F4(8);
    inc:
        self[1]++;
        return;
    }
    {
        register u8* eng asm("$16") = (u8*)D_80097420;
        prev = eng[7];
        if (D_800C456C[2] & 0x1000) {
            func_80016C48(0, 0xC, 0);
            if (eng[7] == 0) {
                eng[7] = five;
            } else {
                eng[7] = eng[7] - 1;
            }
        } else if (D_800C456C[2] & 0x4000) {
            func_80016C48(0, 0xC, 0);
            if (eng[7] == five) {
                eng[7] = 0;
            } else {
                eng[7] = eng[7] + 1;
            }
        }
    }
    if (D_800C456C[2] & 0xA040) {
        if (ENG_B(7) == 3) {
            func_80016C48(0, 0xC, 0);
            D_800CC869 ^= 1;
            func_800174D4(D_800CC869);
        }
        if ((D_800C456C[2] & 0xA040) && ENG_B(7) == 1) {
            func_80016C48(0, 0xC, 0);
            D_8006D5F9 ^= 1;
        }
    }
    if ((D_800C456C[2] & 0xA000) && ENG_B(7) == 0) {
        if (D_800C456C[2] & 0x8000) {
            func_80016C48(0, 0xC, 0);
            if (D_8006D5F8 != 0) {
                D_8006D5F8--;
            } else {
                D_8006D5F8 = 2;
            }
        } else if (D_800C456C[2] & 0x2000) {
            func_80016C48(0, 0xC, 0);
            if (D_8006D5F8 < 2) {
                D_8006D5F8++;
            } else {
                D_8006D5F8 = 0;
            }
        }
    }
    if (D_800C456C[2] & 0xA050) {
        if (ENG_B(7) != 4) {
            goto check;
        }
        old = OPT_B(3);
        if (D_800C456C[2] & 0x8000) {
            if (old != 0) {
                D_800CD3F8[3] = old - 1;
            }
        } else if ((D_800C456C[2] & 0x2000) && (s8)old < 0x17) {
            D_800CD3F8[3] = old + 1;
        }
        if (old != OPT_SB(3)) {
            func_80016C48(0, 0xC, 0);
        }
        if (D_800C456C[2] & 0x10) {
            func_800186A8();
        } else if (D_800C456C[2] & 0x40) {
            func_800186A8();
            {
                register s32 i asm("$2") = OPT_SB(3);
                func_80018060(func_800F08CC[i], 0x7F);
            }
        }
    }
    if (ENG_B(7) != 4) {
    check:
        if (prev == 4) {
            func_800186A8();
        }
    }
}
