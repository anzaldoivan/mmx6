#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCR_9C (*(s32**)0x1F80009C)
#define SCR_20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002C458();
void* func_800F77A0(void*, s32);
extern s16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)
extern s8 D_800CCEDC;

void func_800F71F4(void* arg0) {
    void* p;
    void* q;
    s16 e;
    u8 f;
    s16 x;

    p = func_8002C458();
    if (p != 0) {
        M2C_FIELD(p, u8*, 0) = 0x41;
        M2C_FIELD(p, u8*, 1) = 0x10;
        M2C_FIELD(p, u8*, 2) = 0x20;
        M2C_FIELD(p, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x10;
        } else {
            M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x10;
        }
        M2C_FIELD(p, s16*, 8) = 0;
        M2C_FIELD(p, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
        M2C_FIELD(p, s16*, 0x40) = 0x540;
        M2C_FIELD(p, s16*, 0xC) = 0;
        M2C_FIELD(p, void**, 0x7C) = arg0;
        if (D_800CCEDC == 0xC) {
            M2C_FIELD(p, s16*, 0x42) = 0x794C;
            M2C_FIELD(p, void**, 0x3C) = (u8*)SCR_9C + SCR_9C[1];
        } else {
            M2C_FIELD(p, s16*, 0x42) =
                (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1) * 4 + 0x20) %
                 16) |
                (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 9) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(p, void**, 0x3C) =
                (u8*)SCR_20 +
                SCR_20[func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1];
        }
    }
    f = (M2C_FIELD(arg0, u8*, 0x15) == 0) << 6;
    {
        s32 t;
        t = M2C_FIELD(p, u16*, 0xA) - D_80097202 - 0x140;
        x = D_80097202 - t;
    }
    e = M2C_FIELD(p, s16*, 0xE);
    q = func_800F77A0(p, 0);
    if (q != 0) {
        M2C_FIELD(q, u8*, 0) = 0x41;
        M2C_FIELD(q, u8*, 1) = 0x10;
        M2C_FIELD(q, u8*, 2) = 0x21;
        M2C_FIELD(q, u8*, 0x15) = f;
        M2C_FIELD(q, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(q, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(q, s16*, 0xA) = x;
        M2C_FIELD(q, s16*, 8) = 0;
        M2C_FIELD(q, s16*, 0xE) = e;
        M2C_FIELD(q, s16*, 0x40) = 0x540;
        M2C_FIELD(q, s16*, 0xC) = 0;
        M2C_FIELD(q, void**, 0x7C) = arg0;
        M2C_FIELD(q, void**, 0x8C) = p;
        if (D_800CCEDC == 0xC) {
            M2C_FIELD(q, s16*, 0x42) = 0x794C;
            M2C_FIELD(q, void**, 0x3C) = (u8*)SCR_9C + SCR_9C[1];
        } else {
            M2C_FIELD(q, s16*, 0x42) =
                (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1) * 4 + 0x20) %
                 16) |
                (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 9) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(q, void**, 0x3C) =
                (u8*)SCR_20 +
                SCR_20[func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1];
        }
    }
}
#undef D_80097202
#undef SCR_9C
#undef SCR_20
