#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_8007573C[];
extern void* D_800F7800;
#define D_1F800020 (*(u8**)SP(0x20))

void func_800F407C(void* arg0) {
    s32 a;
    s32 b;
    u8* base;
    u8 st;
    s32 c;
    void* q;

    {
        void* p = D_800F7800;
        u8 sb;
        M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
        sb = M2C_FIELD(p, u8*, 0x14);
        M2C_FIELD(arg0, u8*, 0x16) = 2;
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, s32**, 0x58) = D_8007573C;
        M2C_FIELD(arg0, u8*, 0x14) = sb;
    }
    {
        void* p = D_800F7800;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, u16*, 0x40) = 0x140;
        a = func_8002A47C(M2C_FIELD(p, s8*, 1));
    }
    b = func_8002A47C(M2C_FIELD(D_800F7800, s8*, 1));
    c = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    q = D_800F7800;
    M2C_FIELD(arg0, u16*, 0x42) = c;
    b = func_8002A47C(M2C_FIELD(q, s8*, 1));
    base = D_1F800020;
    M2C_FIELD(arg0, u8**, 0x3C) = base + ((s32*)base)[b];
    func_800179A4(arg0, 5);
    st = M2C_FIELD(D_800F7800, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x15) = st;
    if (st == 0) {
        M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(D_800F7800, u16*, 0xA) - 0x28;
    } else {
        M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(D_800F7800, u16*, 0xA) + 0x28;
    }
    M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(D_800F7800, u16*, 0xE);
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, u8*, 0x60) = 8;
    func_80016C48(2, 0x8D, arg0);
    M2C_FIELD(arg0, s32*, 0x8C) = 0;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 4)++;
}
