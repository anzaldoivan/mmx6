#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_20 (*(s32**)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern u8 D_800970B4;
extern s32 D_80078DC8;
extern s32 D_80078DCC;

void func_8005011C(void* arg0) {
    s32 a;
    s32 b;
    u8 t;

    M2C_FIELD(arg0, u8*, 0x0) = 0x49;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, u16*, 0x40) = D_80095098[func_8002A47C(0x80)] >> 7;
    M2C_FIELD(arg0, s32*, 0x3C) =
        (s32)SCRATCH_20 + SCRATCH_20[func_8002A47C(0x80)];
    a = func_8002A47C(0x80);
    b = func_8002A47C(0x80);
    M2C_FIELD(arg0, s16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    {
        s32* p = &D_80078DCC;
        u8* q;
        register s32 one asm("$3");
        do {
        } while (0);
        q = &D_800970B4;
        M2C_FIELD(arg0, s32**, 0x30) = p;
        one = 1;
        t = *q;
        M2C_FIELD(arg0, u8*, 0x75) = one;
        M2C_FIELD(arg0, u8*, 0x4) = one;
    }
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, s32*, 0x7C) = 0;
    M2C_FIELD(arg0, s32*, 0x88) = 0;
    M2C_FIELD(arg0, s32**, 0x68) = &D_80078DC8;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = t;
    M2C_FIELD(arg0, u8*, 0x2) &= 0x3F;
    func_800179A4(arg0, 0);
}
